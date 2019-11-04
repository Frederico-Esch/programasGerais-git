let population;
let lifespan =300;
let lifeP;
let gerP;
let ger = 0;
let count = 0;
let target;
let muut = 0.01
let menortempo = 10000;
function setup() {
  createCanvas(1350,600);
  //rocket = new Rocket();
  population = new Population();
  lifeP = createP();
  gerP = createP();
  gerP.position(100, 600);
  target = createVector(width/2, 100);
}
function draw() {
  background(0);
  population.run();
  count++;
  lifeP.html(count);
  gerP.html(ger)
  if(count == lifespan){
    //population = new Population();
    population.evaluate();
    population.selection();
    count=0;
    ger++;
  }
  fill(255,0,0);
  ellipse(target.x, target.y, 10,10);
}
function Population(){
  this.rockets = [];
  this.popsize = 100;
  this.matingpool = [];
  
  for(var i=0;i<this.popsize;i++){
    this.rockets[i] = new Rocket();
  }
  
  this.evaluate = function(){
    var maxfit = 0;
    for(var i=0;i<this.popsize;i++){
      this.rockets[i].calcFitness();
      if(this.rockets[i].fitness>maxfit){
        maxfit = this.rockets[i].fitness;
      }
    }
    //createP(maxfit)

    
    this.matingpool = [];
    
    for(var i = 0;i<this.popsize;i++){
      this.rockets[i].fitness /= maxfit;
    }
    
    for(var i = 0;i<this.popsize;i++){
      var n = this.rockets[i].fitness * 100;
      for(var j = 0; j<n;j++){
        this.matingpool.push(this.rockets[i]);
      }
    }
  }

  this.selection = function(){
    var newRockets = [];

    for(var i = 0; i<this.rockets.length; i++){
      var parentA = random(this.matingpool).dna;
      var parentB = random(this.matingpool).dna;
      var child = parentA.crossover(parentB);
      child.mutation();
      newRockets[i] = new Rocket(child);
    }

    this.rockets = newRockets;

  }
  
  this.run = function(){
    for(var i=0;i<this.popsize;i++){
      this.rockets[i].update();
      this.rockets[i].show();
    }
  }
}
