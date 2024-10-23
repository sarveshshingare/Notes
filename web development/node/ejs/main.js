const express = require("express");
const app = express();
const port = 3000;
app.set("view engine", "ejs");

app.get("/", (req, res) => {
  res.sendFile("templates/index.html", { root: __dirname });
});

// app.get("/blog/:slug", (req, res) => {
//   let blogTitle = "why development";
//   let blogContent = "development is very good and everyone should learn";
//   res.render("templates/index.html", {
//     blogTitle: blogTitle,
//     blogContent: blogContent,
//   });
// });

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});
