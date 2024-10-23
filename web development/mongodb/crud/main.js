import mongoose from "mongoose";
import express from "express";
import { Todo } from "./models/Todo.js";

let conn = await mongoose.connect("mongodb://localhost:27017/todo");

const app = express();
const port = 3000;

app.get("/", (req, res) => {
  res.send("Hello World!");
  const todo = new Todo({
    title: "using mongoose with express",
    desc: "will be wrtiting some code eto use mongoose wiht express",
    isDone: false,
  });
  todo.save();
});

app.listen(port, () => {
  console.log(`Example app listening on port ${port}`);
});
