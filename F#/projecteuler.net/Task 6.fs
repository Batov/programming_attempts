//Batov gr171
//SPBSU
//open System
//
//let s = Seq.sum (seq { for x in [1..100] -> x*x})
//let s2 = (Seq.sum (seq { for x : float in [1.0..100.0] -> x }))**2.0
//printfn "%A" ((Convert.ToInt32 s2) - s  )

printfn "%A" ((System.Convert.ToInt32 ((Seq.sum (seq { for x : float in [1.0..100.0] -> x }))**2.0)) - (Seq.sum (seq { for x in [1..100] -> x*x}))  )
