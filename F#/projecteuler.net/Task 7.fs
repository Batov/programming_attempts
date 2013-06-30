//Batov 171gr
//SPBSU
open System
let isPrime (x:int) =
  let mutable ret = true
  if x % 2 = 0 then ret <- false 
  let mutable i = 3
  //let sqrt = System.Convert.ToInt32(Math.Sqrt(System.Convert.ToDouble(x)))
  while ((i) < x/2) && ret  do
    if x % i = 0 then ret <- false
    i <- i + 2
  ret

let mutable num = 3 
let mutable i = 2    
while i < 10001 do
  printfn "%A" i
  num <- num + 2
  if isPrime num then
    i <- i + 1
printfn "%A" <| num 