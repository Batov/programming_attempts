//Batov gr171
//SPBSU
printf "%A" (Seq.sum (seq{for i in [0..999] -> if i % 3 = 0 || i % 5 = 0  then i else 0}))
