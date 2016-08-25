var WebSocketServer = require('ws').Server
var wss = new WebSocketServer({ port: 8080 });

var express = require('express');
var app = express();

var sockets = [];

wss.on('connection', function connection(ws) {
  sockets.push(ws);

  ws.on('message', function incoming(message) {
    console.log(message);

    sockets.forEach(function(socket) {
      socket.send(message);
    });
  });

  ws.on('close', function() {
    sockets = sockets.filter(function(socket) {
      return ws !== socket;
    });
  });
});

app.use(express.static('public'));

app.get('/connections', function(req, res) {
  res.end('' + sockets.length);
});

app.listen(3000, function () {
  console.log('App listening on port 3000');
});
