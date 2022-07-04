class Node{ 
  constructor(value){ 
    this.value = value; 
    this.next = null; 
  }
}

class SinglyLinkedList{ 
  constructor(){ 
    this.length = 0; 
    this.head = null; 
    this.tail = null; 
  }
  push(value){ 
    let newNode = new Node(value); 
    if(!this.head){ 
      this.head = newNode; 
      this.tail = newNode; 
    }else {
       this.tail.next = newNode; 
       this.tail = newNode; 
    }
    this.length++; 
    return this; 
  }
  pop(){ 
    if(!this.head) return undefined; 
    let current = this.head; 
    let newTail = current; 
    while(current.next){ 
      newTail = current; 
      current = current.next; 
    }
    this.tail = newTail; 
    this.tail.next = null; 
    this.length--;
    if(this.length===0){ 
      this.head = null; 
      this.tail = null; 
    } 
    return current; 
  }
  shift(){ 
    if(!this.head) return undefined; 
    let currentHead = this.head; 
    this.head = currentHead.next; 
    this.length--; 
    if(this.length === 0){ 
      this.tail = null; 
    }
    return currentHead; 
  }
  unshift(value){ 
    let newNode = new Node(value); 
    if(!this.head){ 
      this.head = newNode; 
      this.tail = newNode; 
    }else { 
      newNode.next = this.head;
      this.head = newNode;    
    }
    this.length++; 
    return this; 
  }
  get(index){ 
    if(index<0||index>=this.length) return null; 
    let count = 0; 
    let current = this.head; 
    while(count!==index){ 
      current = current.next; 
      count++; 
    }
    return current; 
  }
  set(index, value){ 
    let node= this.get(index); 
    if(!node) return false; 
    node.value = value; 
    return true; 
  }
  insert(index,value){ 
    if(index<0||index>this.length) return false; ; 
    if(index === this.length){
      return !!this.push(value); 
    } 
    else if(index === 0){ 
      return !!this.unshift(value)
    }
    let newNode = new Node(value); 
    let previous = this.get(index-1); 
    let temp = previous.next; 
    previous.next = newNode; 
    newNode.next=temp; 
    this.length++; 
    return true; 
  }
}
