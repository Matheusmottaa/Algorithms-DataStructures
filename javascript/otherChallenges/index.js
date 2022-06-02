/* 
  Given two strings, write a function to determine if the second string is 
  an anagram of the first.
*/

"use strict"; 

// Time complexity O(n)
function validAnagram(str1, str2){ 
  if(str1.length !== str2.length){ 
    return false; 
  }
  const frequencyCounter1 = {}; 
  const frequencyCounter2 = {}; 
  for(let val of str1){ 
    frequencyCounter1[val] = (frequencyCounter1[val] || 0) + 1; 
  }
  for(let val of str2){ 
    frequencyCounter2[val] = (frequencyCounter2[val] || 0) + 1; 
  }
  for(let key in frequencyCounter1){ 
    if(!(key in frequencyCounter2)){ 
      return false; 
    }
    if(frequencyCounter1[key] !== frequencyCounter2[key]){ 
      return false; 
    }
  }
  return true; 
}

console.log(validAnagram('anagram', 'nagaram')); 