

function fib(x){ 
  if(x<=2) return 1; 
  return fib(x-1) + fib(x-2);  
}

console.log(fib(4)); 