class Node { 
  constructor(value){ 
    this.value = value; 
    this.next = null; 
  }
}

/* 
  Big O of Stacks: 
  
  - insertion O(1).
  - Deletion O(1).
  - Searching O(n)
  - Access O(n).  
*/

class Stack{ 
  constructor(){ 
    this.first = null; 
    this.last = null; 
    this.size = 0; 
  }
  push(value){ 
    let newNode = new Node(value); 
    if(!this.first){ 
      this.first = newNode; 
      this.last = newNode; 
    }else{ 
      let temp = this.first; 
      this.first = newNode; 
      this.first.next = temp;
    }
    return ++this.size; 
  }
  pop(){ 
    if(!this.first) return null; 
    let item = this.first; 
    if(this.first === this.last){ 
      this.last = null; 
    }
    this.first = this.first.next; 
    --this.size; 
    return item.value; 
  }
}


