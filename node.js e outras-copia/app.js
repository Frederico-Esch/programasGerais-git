const express = require('express')
const app = express();
const porta = 8081


app.get('/', function(req, res){
    res.sendFile(__dirname+'/html/unv.html')
})
app.get('/inicio', function(req, res){
    res.sendFile(__dirname+'/html/index.html')
})
app.get('/veri', function(req, res){
    res.sendFile(__dirname+'/html/ver.html')
})
app.get('/post', function(req, res){
    res.sendFile(__dirname+'/html/post.html')
})


function resp(){
    console.log('rodando...')
}
app.listen(porta, resp())