//Batov 171gr 
//SPBSU
open System
let input = (System.IO.File.ReadAllLines("/home/batov/roman.txt"));

let mutable full_size = 0
let mutable short_size = 0
for line in input do
  full_size <- line.Length + full_size
 // printfn "Full=%A" full_size
  let mutable str = ""
  str <- line.Replace("DCCCC", "CM") 
  str <- str.Replace("LXXXX", "XC")
  str <- str.Replace("VIIII" , "IX")
  str <- str.Replace("IIII" , "IV")
  str <- str.Replace("XXXX", "XL")
  str <- str.Replace("CCCC" , "CD")
  short_size <- str.Length + short_size
//  printfn "Short=%A" short_size

printf "%A" (full_size - short_size)
