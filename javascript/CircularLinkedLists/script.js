class Node{ 
  constructor(value){ 
    this.val = value; 
    this.next = null; 
  }
}

class CLL { 
  constructor(){ 
    this.tail = null; 
    this.length = 0; 
  }
  //Time O(1)
  push(value){ 
    let newNode = new Node(value); 
    if(!this.tail){ 
      this.tail = newNode; 
      newNode.next = this.tail;
    }else{ 
      newNode.next = this.tail.next; 
      this.tail.next = newNode; 
      this.tail = newNode; 
    }
    this.length++; 
    return this; 
  }
  //Time complexity O(1)
  unshift(value){ 
    let newNode = new Node(value); 
    if(!this.tail){ 
      this.tail = newNode; 
      newNode.next = this.tail; 
    }else{ 
      newNode.next = this.tail.next; 
      this.tail.next = newNode; 
    }
    this.length++; 
    return this; 
  }
  // Time complexity O(1)
  shift(){ 
    if(!this.tail) return null; 
    let temp = this.tail.next; 
    this.tail.next = temp.next; 
    if(this.length===1){ 
      temp = this.tail; 
      this.tail = null; 
      this.length = 0;
      return temp; 
    }
    this.length--; 
    return temp 
  }
  // Time Complexity O(n)
  pop(){ 
    if(!this.tail) return null; 
    let current = this.tail;
    while(current.next!==this.tail){ 
      current = current.next; 
    }
    
    let removed = current.next; 
    current.next = removed.next; 
    this.tail = current; 
    this.length--; 
    return removed; 
  }

  clearList(){ 
    if(!this.tail) return
    this.tail = null; 
    this.length =0; 
    return true; 
  }

  get size(){ 
    return this.length; 
  }

  print(){ 
    if(!this.tail) return null; 
    let current = this.tail.next; 
    do{ 
      console.log(current.val); 
      current = current.next; 
    }while(current!==this.tail.next); 
  }
}

const list = new CLL(); 

list.unshift(20)
list.unshift(12); 
list.unshift(8) 