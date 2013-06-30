//Batov gr171
//SPBSU
open System

let mutable c = 2
let mutable l = 1
let mutable r = 0;
while c <  4000000 do
  if c % 2 = 0 then r <- r + c 
  let t = c
  c <- l + c
  l <- t
printfn "%A" r