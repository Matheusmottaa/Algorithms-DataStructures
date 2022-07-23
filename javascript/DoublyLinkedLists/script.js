class Node{ 
  constructor(value){ 
    this.data = value; 
    this.next = null; 
    this.prev = null; 
  }
}

class DoublyLinkedList{ 
  constructor(){ 
    this.head = null; 
    this.tail = null; 
    this.length = 0; 
  }
  push(value){ 
    let newNode = new Node(value); 
    if(!this.head){ 
      this.head = newNode; 
      this.tail = newNode; 
    }else{ 
      this.tail.next = newNode; 
      newNode.prev = this.tail; 
      this.tail = newNode; 
    }
    this.length++; 
    return this; 
  }
  pop(){ 
    if(!this.head) return undefined; 
    let item = this.tail; 
    if(this.length===1){ 
      this.head = null; 
      this.tail = null; 
    }else{  
      this.tail = item.prev; 
      this.tail.next = null;
      item.prev = null; 
    }
    this.length--; 
    return item; 
  }
  shift(){ 
    if(!this.head) return undefined; 
    let item = this.head; 
    if(this.length === 1){ 
      this.head = null; 
      this.tail = null; 
    }else{ 
      this.head = item.next; 
      this.head.prev = null; 
      item.next = null; 
    }
    this.length--; 
    return item; 
  }
  unshift(value){ 
    let newNode = new Node(value); 
    if(!this.head){ 
      this.head = newNode; 
      this.tail = newNode; 
    }else{ 
      newNode.next = this.head; 
      this.head.prev = newNode; 
      this.head = newNode; 
    }
    this.length++; 
    return this; 
  }
  get(index){ 
    if(index<0||index>=this.length) return null; 
    let current; 
    if(index<=Math.floor(this.length/2.0)){ 
      current = this.head; 
      for(let i=0;i!==index;i++, current=current.next);
    }else{ 
      current = this.tail; 
      for(let i=this.length-1; i!==index; i--, current=current.prev); 
    }
    return current; 
  }
  set(index,value){ 
    let node = this.get(index); 
    if(node === null) return false; 
    node.data = value; 
    return true; 
  }
  insert(index,value){ 
    if(index<0||index>this.length) return false; 
    if(index === 0) return !!this.unshift(value); 
    if(index === this.length) return !!this.push(value); 
    let newNode = new Node(value); 
    let prevNode = this.get(index-1); 
    let temp = prevNode.next; 
    prevNode.next = newNode; 
    newNode.prev = prevNode; 
    newNode.next = temp; 
    temp.prev = newNode; 
    this.length++; 
    return true; 
  }
  remove(index){ 
    if(index<0||index>=this.length) return undefined;
    if(index===0) return this.shift(); 
    if(index===this.length-1) return this.pop(); 
    let item = this.get(index); 
    item.prev.next = item.next; 
    item.next.prev = item.prev; 
    item.prev=null; 
    item.next = null; 
    this.length--; 
    return item; 
  }
  reverse() {
    let current = this.head;
    this.head = this.tail;
    this.tail = current;
    while (current) {
      let next = current.next;
      let prev = current.prev;
      current.next = prev;
      current.prev = next;
      current = next;
    }
    return this;
  }
}

/* 
    BIG O of Doubly Linked Lists 
    
    Insertion -   O(1)

    Removal -   O(1)

    Searching -   O(N)

    Access -   O(N)

*/

let list = new DoublyLinkedList(); 

list.push("first"); 
list.push(20); 
list.push(false); 