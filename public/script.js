var socket = new WebSocket(
  'ws://localhost:8080'
);

socket.onopen = function() {
  document.body.innerHTML += '<div id="num-connections"></div>';

  var wrapWithHighlightSpan = function(string) {
    return '<span class="highlight">' + string + '</span>';
  };

  (function loop() {
    var numConnectionsElement = document.getElementById('num-connections');
    var pingElement = document.getElementById('ping');

    var xmlhttp = new XMLHttpRequest();
    var url = "/connections";

    xmlhttp.onreadystatechange = function() {
      if (xmlhttp.readyState == 4 && xmlhttp.status == 200) {
        var numConnections = xmlhttp.responseText;
        var numESP8266Connecitons = numConnections - 1;
        numConnectionsElement.innerHTML = wrapWithHighlightSpan(numConnections) + ' active connection' + (numConnections == 1 ? '' : 's');
        numConnectionsElement.innerHTML += '<br /> ' + wrapWithHighlightSpan(numESP8266Connecitons) +
          ' active ESP8266 connection' + (numESP8266Connecitons == 1 ? '' : 's');

        setTimeout(loop, 1000);
        pingElement.className = 'active';
        setTimeout(function() {
          pingElement.className = 'animating';
        }, 500);

      }
    };
    xmlhttp.open("GET", url, true);
    xmlhttp.send();
  })();

  document.body.innerHTML += (function() {
    var toReturn = '';
    for (var id in animations) {
      var name = animations[id];
      toReturn += '<div id="animation-' + id + '" class="animation-trigger">' + name + '</div>';
    }
    return toReturn;
  })();

  Array.prototype.slice.call(document.getElementsByClassName('animation-trigger')).forEach(function(element) {
    var animationId = element.id.match(/-(.+)/)[1];
    element.onclick = function() {
      console.log(animationId);
      socket.send(animationId);
    };
  });

};
