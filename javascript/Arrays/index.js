class MyArray{ 
  constructor(){
    this.length = 0; 
    this.data = {}; 
  }

  get(index){ 
    return this.data[index]; 
  }

  push(value){ 
    this.data[this.length] = value; 
    this.length++; 
    return this.length; 
  }

  pop(){ 
    const deleted = this.data[this.length-1]; 
    this.length--; 
    return deleted; 
  }

  delete(index){ 
    if(index<0||index>this.length) return null; 
    const removed = this.data[index]; 
    this.shifting(index); 
    this.length--; 
    return removed; 
  }

  shifting(index){ 
    for(let i=index;i<this.length-1;i++){ 
      this.data[i] = this.data[i+1]; 
    }
    delete this.data[this.length-1]; 
  }

}

const arr = new MyArray(); 
 
arr.push("Goku");
arr.push("Vegeta"); 
arr.push("Naruto"); 
arr.push("Gohan"); 
arr.push("Mydoria"); 


arr.delete(2); 

console.log(arr); 

