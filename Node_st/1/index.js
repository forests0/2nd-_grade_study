const http = require('http')

http.createServer((req,res) => {
    res.statusCode = 200;
    res.setHeader('Content-Type', 'text/html');
    res.write('<html>')
    res.write('<body>')
    res.write('<h1>Hello, World!</h1>')
    res.write('</html>')
    res.write('</body>')
    res.end()
}).listen(8080);