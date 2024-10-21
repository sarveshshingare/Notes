const express = require("express");
const path = require("path");
const fs = require("fs");
const cors = require("cors");
const app = express();

// Enable CORS for all routes
app.use(cors());
// Path to your songs directory
const musicDirectory = path.join(__dirname, "songs");

// Serve a list of songs in the directory
app.get("/songs", (req, res) => {
  fs.readdir(musicDirectory, (err, files) => {
    if (err) {
      return res.status(500).json({ message: "Unable to scan directory" });
    }
    // Return a list of song filenames as JSON
    res.json(files);
  });
});

// Endpoint to serve individual song files
app.get("/songs/:filename", (req, res) => {
  const filePath = path.join(musicDirectory, req.params.filename);
  res.sendFile(filePath);
});

// Start the server
app.listen(3000, () => {
  console.log("Server is running on http://localhost:3000");
});
