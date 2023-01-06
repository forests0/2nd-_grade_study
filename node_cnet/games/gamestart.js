const express = require("express");
const path = require("path");
let app = express();
let http = require("http").Server(app);
let io = require("socket.io")(http);
const fs = require("fs");

let dataBuffer = fs.readFileSync("./question.json");
let dataJSON = dataBuffer.toString();
let data = JSON.parse(dataJSON);
let quiz = data.quizset + Math.floor(Math.random() * 10) + 1;
console.log(quiz);

/*
app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "/game.html"));
});
*/
