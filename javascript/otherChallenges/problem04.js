/* 
Implement a function called countUniqueValues, which accepts a sorted array, 
and counts the unique values in the array. There can be negative numbers in the 
array, but it will always be sorted.
*/

// Time Complexity O(n)
function countUniqueValues(array){ 
  if(array.length === 0) return 0;
  let i =0;
  for(let j=1; j<array.length; j++){ 
    if(array[i] !== array[j]){ 
      i +=1; 
      array[i] = array[j]; 
    }
  }
  return i + 1; 
}

console.log(countUniqueValues([1,2,3,4,4,4,7,7,12,12,13])); 