/* 
Write a function called sumZero which accepts a sorted array of integers. 
The function should find the first pair where the sum is 0. Return an array 
that includes both values that sum to zero or undefined if a pair does not exist
*/ 

// Time Complexity O(n)
// Space Complexity O(1)
function sumZero(array){ 
  let left = 0; 
  let right = array.length - 1; 
  while(left<right){ 
    let sum = array[left] + array[right]; 
    if(sum === 0){ 
      return [array[left], array[right]]; 
    }else if(sum>0){ 
      right--; 
    }else { 
      left++; 
    }
  }
}

console.log(sumZero([-3,-2,-1,0,1,2,3]));
console.log(sumZero([-2,0,1,3])); 

/* 

==================
  Other solution
==================

// Time Complexity O(N²)
// Space Complexity O(1)
function sumZero(array){ 
  for(let i=0;i<array.length; i++){
     for(let j=i+1; array.length; j++){ 
        if(array[i] + array[j] === 0){ 
          return [array[i], array[j]]; 
        }
     }
  }
}

*/ 