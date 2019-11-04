let population;
let lifespan =600;
let lifeP;
let gerP;
let ger = 0;
let count = 0;
let target;
let muut = 0.01
let obj_width = 400;
let obj_height = 25;
let obj_pos;
let menortempo = 10000;
function setup() {
  createCanvas(1350,600);
  //rocket = new Rocket();
  population = new Population();
  lifeP = createP();
  gerP = createP();
  gerP.position(100, 600);
  target = createVector(width/2, 100);
  obj_pos = createVector(450, 200);
}
function draw() {
  background(0);
  population.run();
  count++;
  lifeP.html(count);
  gerP.html(ger);
  fill(255,255,0);
  rect(obj_pos.x, obj_pos.y, obj_width, obj_height);
  if(count == lifespan){
    //population = new Population();
    //console.log(population.rockets);
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
  this.popsize = 20;
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

    //console.log('///////////////////////////////////////////////////////')
    for(var i = 0;i<this.popsize;i++){
      //console.log(this.rockets[i].fitness);
      this.rockets[i].fitness /= maxfit;
    }
    
    for(var i = 0;i<this.popsize;i++){
      //console.log(this.rockets[i].fitness);
      var n = this.rockets[i].fitness * 100;
      //console.log(n);
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
