let quan = 500;
let vel = 50;
let fred = [quan];
function setup(){
    createCanvas(500, 500);
    for (i = 0; i<quan; i++){
        fred[i] = new lei();
        fred[i].novo();
    }
}
function draw(){
    background(255);
    for(i = 0; i<quan; i++)
    {
        fred[i].vai();
        fred[i].adi(vel);
        fred[i].veri();
    }
}
function lei(){
    this.novo = function(){
        this.cor = random(0,255);
        this.cog = random(0,255);
        this.cob = random(0,255);
        this.tamanho = random(50, 100);
        this.lugar = random(this.tamanho/2, width-this.tamanho/2)
        this.alt = this.tamanho/2
    }
    this.vai = function(){
        fill(this.cor, this.cog,this.cob)
        ellipse(this.lugar, this.alt, this.tamanho)
    }
    this.adi = function(val){
        this.alt += val;
    }
    this.veri = function(){
        if (this.alt-this.tamanho/2 > height){
            this.novo();
        }
    }
}