/* 
  Given a sorted array of integers, write a function called search, that 
  accepts a value and returns the index where the value passed to the function 
  is located. If the value is not found, return -1
*/ 

// Time Complexity O(Log n)
function search(array, number){ 
  let begin = 0; 
  let end = array.length - 1; 
  while(begin<end){ 
    let mid = Math.floor((begin + end)/2); 
    let guess = array[mid]
    if(guess < number){ 
      begin = mid + 1; 
    } else if(guess > number){ 
      end = mid - 1;
    }else { 
      return mid
    }
  }
  return null; 
}
