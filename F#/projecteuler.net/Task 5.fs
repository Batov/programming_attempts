//Batov gr171
//SPBSU
open System

let div = seq { for x in [1..20] -> x}
let mutable n = 0
let f = ref 0

while !f <> 1 do
  f := 1
  n <- n + 2520
  Seq.iter (fun elem -> if n % elem <> 0 then f := 0 ) div
  printfn "%A" n
printf "========%A" n