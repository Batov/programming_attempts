//Batov gr171
//SPBSU
open System
let  num = 600851475143L
let mutable largest_Fact = 0L
let factors = Array.create 2 0L
let mutable i = 2L
while (i*i) < num do
  if (num % i = 0L) then
    factors.[0] <- i
    factors.[1] <- num / i
    let mutable k = 0
    while k < 2 do
      let mutable isPrime = true
      let mutable j = 2
      while Convert.ToInt64 (j*j) < factors.[k] && isPrime do
        if factors.[k] % Convert.ToInt64 j = 0L then
          isPrime <- false
        j <- j + 1
      if isPrime && factors.[k] > largest_Fact then
        largest_Fact <- factors.[k]
      k <- k + 1    
  i <- i + 1L     
 
printfn "%A" largest_Fact