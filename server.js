var http = require('http'),
    url = require('url');
var dev = require('device');

var usb = new dev.Device();
    
var server = http.createServer().listen(8080, 'localhost');

console.log("Server started and listening on localhost:8080");

server.on('request', function(req, res) {

  var url_parts = url.parse(req.url, true);
  switch(url_parts.pathname) {
    case '/':
    case '/index.html':
      res.write('<html><body>' + usb.initDevice( 0x05ac, 0x0237 ) + '</body></html>');
      break;
    default:
      res.write('Unknown path: ' + JSON.stringify(url_parts));
  }
  res.end();
});
