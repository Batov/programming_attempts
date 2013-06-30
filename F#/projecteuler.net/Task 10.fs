open System
let isPrime (x:int) =
  let mutable ret = true
  if x % 2 = 0 && x <> 2 then ret <- false 
  let mutable i = 3
  while ((i) < x/2) && ret  do
    if x % i = 0 then ret <- false
    i <- i + 2
  ret
 
let prs = List.filter isPrime [2..2 * 1000000]
printfn "%A" <| List.fold (fun a (x:int) -> a + (int64 x)) 0L prs
