class Node{ 
  constructor(value){ 
    this.value = value; 
    this.next = null; 
  }
}

/* 
  Big O of Queues:

  - Insertion O(1).
  - Deletion  O(1). 
  - Search    O(n). 
  - Access    O(n). 

*/

class Queue{ 
  constructor(){ 
    this.first = null; 
    this.last = null; 
    this.size = 0; 
  }
  enQueue(value){ 
    let newNode = new Node(value); 
    if(!this.first){ 
      this.first = newNode; 
      this.last = newNode; 
    }else { 
      this.last.next = newNode; 
      this.last = newNode; 
    }
    return ++this.size;
  }
  deQueue(){ 
    if(!this.first) return null; 
    let removed = this.first; 
 
    if(this.size === 1){ 
      this.first = null; 
      this.last = null; 
    }else{ 
      this.first = removed.next; 
    } 
    --this.size; 
    return removed; 
  }
}