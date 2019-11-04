//Class for the objects
function Rocket(dna){
  this.pos = createVector(width/2, height);
  this.vel = createVector();
  this.acc = createVector();
  this.completed = false;
  this.collide = false;
  this.whn = 0;

  if(dna){
    this.dna = dna;
  }else{
    this.dna = new DNA();
  }
  this.fitness = 0;
  
  this.applyForce = function(force){
    this.acc.add(force); 
  }
  
  this.update = function(){
    var d = dist(this.pos.x, this.pos.y, target.x,target.y)
    if(((this.pos.y < obj_pos.y + obj_height) && (this.pos.y > obj_pos.y)) && ((this.pos.x > obj_pos.x) && (this.pos.x < obj_pos.x + obj_width)) || this.pos.y > height){
      this.collide = true;
      this.whn = count;
    }
    
    if(!this.completed && !this.collide){ 
      if(d < 10){
        this.whn = count;
        this.completed = true;
        this.pos = target.copy();
        this.pos.x +=0.01;
      }
      this.applyForce(this.dna.genes[count]);
      this.vel.add(this.acc);
      this.pos.add(this.vel);
      this.acc.mult(0);
    }
  }
  
  this.calcFitness = function(){
    var d = dist(this.pos.x, this.pos.y, target.x, target.y);
    this.fitness = map(d, 0, width, width, 0); //instead of 1/d;
    
    if(this.completed){
      console.log(this.fitness)
      if(this.whn < menortempo){
        menortempo = this.whn;
        this.fitness += map(this.whn, 0, 400, 1, 0);
        console.log('melhor tempo:')
        console.log(this.whn)
        console.log('fitness')
        console.log(this.fitness)
      }
    }else if(this.collide){
      this.fitness = 0.00001;
    }
  }
  
  this.show = function(){
    push();
    translate(this.pos.x, this.pos.y);
    fill(255,150);
    rotate(this.vel.heading());
    rectMode(CENTER);
    rect(0,0,50,10);
    pop();
  }
}

//DNA what th fuck do you expect?
function DNA(genes){
  if(genes){
    this.genes = genes;
  }else{
    this.genes = [];
    for(var i = 0; i<lifespan;i++){
      this.genes[i] = p5.Vector.random2D();
      this.genes[i].setMag(0.2);
    }
  }

  this.crossover = function(partner){
    var newgenes = [];
    var mid = floor(random(this.genes.length));
      
    for(var i = 0; i<this.genes.length;i++){
      if(i>mid){
        newgenes[i]= this.genes[i];
      }else{
        newgenes[i]= partner.genes[i];
      }
    }

    return new DNA(newgenes);
  }

  this.mutation = function(){
    for(var i = 0; i < this.genes.length; i++){
      if(random() < 0.01){
        console.log('bhashdkajhkskjsdh')
        this.genes[i] = p5.Vector.random2D();
        this.genes[i].setMag(0.2);
      }
    }
  }

}
