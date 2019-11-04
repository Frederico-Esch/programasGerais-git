const express = require('express');
const app = express();
const porta = 8081
let nome = []
let quant = 0;
app.get('/', function(req, res){
    res.sendFile(__dirname + '/html/teste.html')
})
app.get('/sair/:nome', function(req, res){
    if(nome[quant-1] != req.params.nome){
        nome[quant] = req.params.nome;
        quant++;
    }
    res.send('<head><meta http-equiv="refresh" content="30"/></head>' + nome)
})
app.get('/frai', function(req, res){
    if(req.query.idade == 10){
        res.sendFile(__dirname + '/html/index.html')
    }else{
        res.send( req.query.idade)
    }
})
app.get('/:nome', function(req, res){
    
    res.sendFile(__dirname + '/html/index.html')
})
app.listen(porta, function(){
    console.log(`foi, localhost:${porta}`)
})
