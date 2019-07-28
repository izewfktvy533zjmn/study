#!/usr/env/bin node
const http = require('http');
const url  = require('url');
const port = 3000;
const server = http.createServer(requestHandler);

server.listen(port);


function requestHandler(req, res) {
    var url_parts = url.parse(req.url, true);

    try {
        str = url_parts.search;
        str = str.split('?')[1];
        ans = String(eval(str)) + '\n';

        res.writeHead(200, {'Content-type': 'text/html'});
        res.end(ans);
    } catch(err) {
        res.writeHead(200, {'Content-type': 'text/html'});
        res.end("ERROR\n");
    }
}

