let audioPlayer = new Audio();

fetch("http://localhost:3000/songs")
  .then((response) => response.json())
  .then((data) => {
    const songUL = document
      .querySelector(".songList")
      .getElementsByTagName("ul")[0];

    // Create a list of songs
    data.forEach((song) => {
      const songName = song.replace(/\.mp3$/, "");
      const listItem = document.createElement("li");
      listItem.innerHTML = `
                <div class="songInfo">
                  <img src="/images/music.svg" alt="music" />
                  <div class="info">
                    <div class="songName">${songName}</div>
                    <div class="songArtist">Sachin-Jigar, Madhubanti Bagchi</div>
                  </div>
                </div>
                <div class="playnow">
                  <span>Playnow</span>
                  <img
                    src="/images/play-button.svg"
                    alt=""
                    height="28px"
                    width="28px"
                  />
                </div>
              `;

      // Add click event to play the song when clicked
      listItem.addEventListener("click", () => {
        playSong(song);
      });

      songUL.appendChild(listItem);
    });
  })
  .catch((error) => console.error("Error fetching songs:", error));

// Function to play a selected song
function playSong(songFileName) {
  // var audioPlayer = new Audio(`http://localhost:3000/songs/${songFileName}`);
  audioPlayer.src = `http://localhost:3000/songs/${songFileName}`;

  // Get elements

  const seekBar = document.getElementById("seekBar");
  const currentTimeEl = document.getElementById("currentTime");
  const durationEl = document.getElementById("duration");

  // Update the seek bar as the audio plays
  audioPlayer.addEventListener("timeupdate", () => {
    // Update seek bar value
    seekBar.value = (audioPlayer.currentTime / audioPlayer.duration) * 100;

    // Update current time display
    currentTimeEl.textContent = formatTime(audioPlayer.currentTime);
  });

  // Set the duration when the metadata is loaded
  audioPlayer.addEventListener("loadedmetadata", () => {
    // Set the max value of the seek bar to the duration of the audio
    seekBar.max = 100;

    // Update the duration display
    durationEl.textContent = formatTime(audioPlayer.duration);
  });

  // Seek when the user drags the seek bar
  seekBar.addEventListener("input", () => {
    const seekTo = (seekBar.value / 100) * audioPlayer.duration;
    audioPlayer.currentTime = seekTo;
  });

  // Format time in minutes and seconds
  function formatTime(time) {
    const minutes = Math.floor(time / 60);
    const seconds = Math.floor(time % 60);
    return `${minutes}:${seconds < 10 ? "0" : ""}${seconds}`;
  }
  audioPlayer.play();
  playimg.src = "/images/pause.svg";
  const songName = songFileName.replace(/\.mp3$/, "");

  document.querySelector(".songDetails").innerHTML = songName;

  playimg.addEventListener("click", () => {
    if (audioPlayer.paused) {
      audioPlayer.play();
      playimg.src = "/images/pause.svg";
    } else {
      audioPlayer.pause();
      playimg.src = "/images/play.svg";
    }
  });
}
