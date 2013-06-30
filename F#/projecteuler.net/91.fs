//Batov 171gr 
//SPBSU
open System

let rec gcd x y =
    if y = 0 then x
    else gcd y (x % y)
    
let size = 50
let mutable res = size*size*3

for x = 1 to size do
  for y = 1 to size do
    res  <- res + Math.Min(y * gcd x y / x ,(size - x)*gcd x y /y) * 2
    
printf "%A" res