const fs = require("fs");

console.log("starting");
fs.writeFile("sarvesh.txt", "Sarvesh is a good boy", () => {
  console.log("done");
  fs.readFile("sarvesh.txt", (e, d) => {
    console.log(d.toString());
  });
});

fs.appendFile("sarvesh.txt", "euuuu sutti not aaaa!", (e, d) => {
  console.log(d);
});

console.log("ending");
