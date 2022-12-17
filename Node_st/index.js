const express = require('express')
const app = express()
const req = require('express/lib/request')
const res = require('express/lib/response')

app.set('views', __dirname, '/views')
app.set('view engine', 'ejs')

app.get('/', (req,res) => {
    res.sendFile(__dirname +  "/index.html")
})

app.get('/data', (req,res) => {
    let context = [
        {'a' : 'Hello', 'b' : 'Hello'},
        {'a' : 'javascript', 'a' : 'is...'},
        {'a' : 'web', 'a' : 'is....'}
    ]
    res.render('data.ejs', {'data' : context}, (err,html) => {
        if(err) console.log('Err')
        res.end(html)
    })
})

app.get('/contact', (req,res) => {
    res.render('contact.ejs',
    {'name' : 'hey!', 'mail' : 'forestser00@gmail.com'},
    (err,html) => {
        if(err) console.log(err)
        res.end(html)
    }
    )
})

app.listen(8080, () => {
    console.log('listening in http://localhost:8080')
})
