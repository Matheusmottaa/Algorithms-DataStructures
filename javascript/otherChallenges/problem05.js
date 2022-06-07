/* 
Write a function called maxSubarraySum which accepts an array of integers and 
a number called n. The function should calculate the maximum sum of 
n consecutive elements in the array.
*/

// Time Complexity O(n)
function maxSubarraySum(array, n){ 
  if(n > array.length) return null; 
  let maxSum = 0; 
  let tempSum = 0; 
  for(let i =0; i<n; i++){ 
    maxSum += array[i]; 
  }
  tempSum = maxSum; 
  for(let i=n; i<array.length; i++){ 
    tempSum = tempSum - array[i - n] + array[i];  
    maxSum = Math.max(maxSum, tempSum); 
  }
  return maxSum; 
}

console.log(maxSubarraySum([1,2,5,2,8,1,5],2)); // 10
console.log(maxSubarraySum([1,2,5,2,8,1,5],4)); // 17
console.log(maxSubarraySum([], 4)); // Null


/* 
=========================
    Other Solution
=========================

// Time Complexity O(n²)
function maxSubarraySum(array, n){ 
  if(n>array.length) return null; 
  let max = -Infinity; 
  for(let i=0; i<array.length - n + 1; i++){ 
    let temp = 0; 
    for(let j=0; j<n;j++){ 
      temp += array[i+j]; 
    }
    if(temp > max){ 
      max = temp; 
    }
  }
  return max; 
}

console.log(maxSubarraySum([1,2,5,2,8,1,5],4)); 


*/