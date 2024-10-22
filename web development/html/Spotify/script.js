let track = new Audio();
const playimg = document.getElementById("playimg"); // Assuming this is the play/pause button element

// Function to fetch songs data
async function fetchData() {
  try {
    let response = await fetch("http://localhost:3000/songs");
    let data = await response.json();
    console.log(data);
    return data;
  } catch (error) {
    console.error("Fetch error:", error);
    return [];
  }
}

// Function to add songs to the library UI
async function addSongsInLibrary(data) {
  let lastSong = localStorage.getItem("lastSong"); // Check if a last song was saved
  if (lastSong) {
    playSong(lastSong, true); // Play the last song but in paused state
  } else {
    playSong(data[0], true); // Pause by default if no song found
  }

  let songUl = document.querySelector(".songList ul");
  data.forEach((song) => {
    const songName = song.replace(/\.mp3/, "");
    const listItem = document.createElement("li");
    try {
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
      songUl.appendChild(listItem);
    } catch (error) {
      console.log("error adding songs in library", error);
    }

    // Play song if clicked from library
    listItem.addEventListener("click", () => {
      playSong(song);
    });
  });
}

// Function to play the selected song and store it in localStorage
function playSong(songFileName, pause = false) {
  if (track.src !== `http://localhost:3000/songs/${songFileName}`) {
    track.src = `http://localhost:3000/songs/${songFileName}`;
    seekBar(track);
  }
  if (!pause) {
    track.play();
    playimg.src = "/images/pause.svg";
  } else {
    track.pause();
    playimg.src = "/images/play.svg";
  }
  const songName = songFileName.replace(/\.mp3/, "");
  updateSeekBarDetails(songName);

  // Save the current song to localStorage
  localStorage.setItem("lastSong", songFileName);
}

// Function to manage the seek bar
function seekBar(track) {
  const seekBar = document.getElementById("seekBar");
  const currentTimeEl = document.getElementById("currentTime");
  const durationEl = document.getElementById("duration");

  // Update the seek bar as the audio plays
  track.addEventListener("timeupdate", () => {
    seekBar.value = (track.currentTime / track.duration) * 100;
    currentTimeEl.textContent = formatTime(track.currentTime);
  });

  // Set the duration when the metadata is loaded
  track.addEventListener("loadedmetadata", () => {
    seekBar.max = 100;
    durationEl.textContent = formatTime(track.duration);
  });

  // Seek when the user drags the seek bar
  seekBar.addEventListener("input", () => {
    
    const seekTo = (seekBar.value / 100) * track.duration;
    track.currentTime = seekTo;
  });

  // Format time in minutes and seconds
  function formatTime(time) {
    const minutes = Math.floor(time / 60);
    const seconds = Math.floor(time % 60);

    return `${minutes}:${seconds < 10 ? "0" : ""}${seconds}`;
  }



  
}

// Function to update the song details in the seek bar area
function updateSeekBarDetails(songName) {
  document.querySelector(".songDetails").innerHTML = `<div class="songInfo">
                  <img src="/images/music.svg" alt="music" />
                  <div class="info">
                    <div class="seekBarSongName">${songName}</div>
                    <div class="seekBarsongArtist">Sachin-Jigar, Madhubanti Bagchi</div>
                  </div>
                </div>`;
}

// Play/pause event listener
playimg.addEventListener("click", () => {
  if (track.paused) {
    track.play();
    playimg.src = "/images/pause.svg";
  } else {
    track.pause();
    playimg.src = "/images/play.svg";
  }
});

// Main function to initialize the page
async function main() {
  // Fetch songs data from API
  let data = await fetchData();
  addSongsInLibrary(data);
}

main();
