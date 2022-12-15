const express = require("express");
const path = require("path");
let app = express();
let http = require("http").Server(app);
let io = require("socket.io")(http);

app.get("/", (req, res) => {
  res.sendFile(path.join(__dirname, "index.html"));
});

let count = 0;

io.on("connection", (socket) => {
  let name = "user" + count++;
  io.to(socket.id).emit("change name", name);

  socket.on("disconnect", () => {
    console.log("user disconnected : ", socket.id);
  });

  socket.on("send message", (name, txt) => {
    let msg = name + " : " + txt;
    console.log(msg);
    io.emit("receive msg : ", msg);
  });
});

http.listen(8080, () => {
  console.log("http://localhost:8080");
});

/*
const app = require("express")();
const server = require("http").createServer(app);
const io = require("socket.io")(server);

app.get("/", (req, res) => {
  res.sendFile(__dirname + "/index-room.html");
});

const chat = io.of("/chat").on("connection", (socket) => {
  socket.on("chat message", (data) => {
    console.log("message from client: ", data);

    const name = (socket.name = data.name);
    const room = (socket.room = data.room);

    socket.join(room);
    chat.to(room).emit("chat message", data.msg);
  });
});

server.listen(3000, () => {
  console.log("Socket IO server listening on port 3000");
});

*/
