const http = require('http')
const fs = require('fs')

const server = http.createServer((req,res) => {
    fs.readFileSync('./img1.jpg', function(err,data) {
        res.statusCode = 200
        res.setHeader('Content-Type', 'image/jpg')
        res.end(data)
    })

})

server.listen(8005, function() {
    console.log('Server is on at localhost:8005')
})