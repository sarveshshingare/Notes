let track = new Audio();
let lastTrackPlayed = new Audio();
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

async function addSongsInLibrary(data) {
  playSong(data[0], (pause = true));
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

    // play song if clicked from library
    listItem.addEventListener("click", () => {
      playSong(song);
    });
  });
}

function playSong(songFileName, pause = false) {
  track.src = `http://localhost:3000/songs/${songFileName}`;
  seekBar(track);
  if (!pause) {
    track.play();
    playimg.src = "/images/pause.svg";
  } else {
    playimg.src = "/images/play.svg";
  }
  const songName = songFileName.replace(/\.mp3/, "");
  updateSeekBarDetails(songName);
}

function seekBar(track) {
  const seekBar = document.getElementById("seekBar");
  const currentTimeEl = document.getElementById("currentTime");
  const durationEl = document.getElementById("duration");
  //   // Update the seek bar as the audio plays
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
    console.log(seekBar.value);
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

function updateSeekBarDetails(songName) {
  document.querySelector(".songDetails").innerHTML = `<div class="songInfo">
                  <img src="/images/music.svg" alt="music" />
                  <div class="info">
                    <div class="seekBarSongName">${songName}</div>
                    <div class="seekBarsongArtist">Sachin-Jigar, Madhubanti Bagchi</div>
                  </div>
                </div>`;

  // Add a new event listener
  playimg.addEventListener("click", () => {
    if (track.paused) {
      track.play();
      playimg.src = "/images/pause.svg";
    } else {
      track.pause();
      playimg.src = "/images/play.svg";
    }
  });
}
async function main() {
  // fetch songs data from API
  let data = await fetchData();
  addSongsInLibrary(data);
}

main();
