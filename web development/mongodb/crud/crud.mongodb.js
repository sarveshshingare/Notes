use("crudDB");

console.log(db);

db.createCollection("courses");

db.courses.insertOne({ name: "full stack courses", price: 0, projects: 45 });
db.courses.insertMany([
  {
    name: "sarvesh",
    lastname: "shinagre",
  },
  {
    name: "aram",
    lastname: "se",
  },
  {
    name: "khuch",
    lastname: "bhi",
  },
  {
    name: "murkha",
    lastname: "nsjan",
  },
  {
    name: "kasa",
    lastname: "ahes",
  },
]);
