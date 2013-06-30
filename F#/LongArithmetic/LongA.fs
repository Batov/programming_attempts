open System
let CountofMaxDigitsinInt = 9
let MinusOver = 1000000000
//123|456789011|223344556|677889900 -> [|677889900; 223344556; 456789011; 123|] 

type BigNumber (InitWithSign: string) = 
  
  //interface System.IComparable with member this.CompareTo(that : BigNumber) = this.Compare(that) 
     
  let mutable sign = if InitWithSign.StartsWith("-") then true else false 
  let init = InitWithSign.Substring(0 + if sign then 1 else 0)                                                                                                    
  let mutable value = [|for i in [0..((init.Length / CountofMaxDigitsinInt) - (if init.Length % CountofMaxDigitsinInt <> 0 then 0  else 1) )] -> int (init.Substring((if  init.Length  - (i+1)*CountofMaxDigitsinInt > 0 then init.Length  - (i+1)*CountofMaxDigitsinInt else 0 ),if init.Length - (i)*CountofMaxDigitsinInt <= CountofMaxDigitsinInt then init.Length-(i)*CountofMaxDigitsinInt else CountofMaxDigitsinInt))|]
  member this.Sign 
    with get() = sign
    and set v = sign <- v
  member this.getValue = value
  member this.isZero = if this.getValue = [|0|]  then true else false
  override this.ToString() = (if sign && not (this.isZero) then "-" else "") + (this.ArrayToStr (value))
  member this.Abs = new BigNumber(if this.Sign then this.ToString().Substring(1) else this.ToString() )
  member  this.ArrayToStr(arr : int[]) =
    let mutable str = ""
    let mutable zeros = ""
    for i = arr.Length-1 downto 0 do
      if i < (arr.Length-1)
        then
          for j = 0 to (8 - ((string (arr.[i])).Length)) do
            zeros <- zeros + "0"
      str <- str + (zeros) + string (arr.[i])
      zeros <- ""
    str
  member left.AbsCompare (right:BigNumber) = 
    if left.getValue.Length > right.getValue.Length 
      then 1
      else if right.getValue.Length > left.getValue.Length 
             then -1
             else
                let mutable i = left.getValue.Length-1
                while left.getValue.[i] = right.getValue.[i] && i<>0 do
                  i <- i - 1
                if left.getValue.[i] = right.getValue.[i] then 0 
                else
                  if left.getValue.[i] > right.getValue.[i] then 1 else -1
  member left.Compare(right : BigNumber)=
    if not left.Sign && not right.Sign then left.AbsCompare(right) 
    else if left.Sign && right.Sign then if left.AbsCompare(right) = 0 then 0 else if left.AbsCompare(right) = 1 then -1 else 1  
    else if left.Sign then -1 else 1
  member left.Add (right : BigNumber) = 
    let mutable T = new BigNumber("0")
     
    if left.Sign && right.Sign // -a + -b
       then 
           T <- left.ForAdd(right)
           T.Sign <-true
           
    if left.Sign && not (right.Sign) //-a + b
       then  
           let positiveLeft = new BigNumber(left.ToString().Substring(1))
           T <- right.Sub(positiveLeft)
           
    if not (left.Sign) && right.Sign //a + -b
       then 
           let positiveRight = new BigNumber(right.ToString().Substring(1))
           T <- left.Sub(positiveRight)
           
    if not (left.Sign) && not (right.Sign) // a + b
       then 
           T <- left.ForAdd (right)
           T.Sign <-false
    T        
  member private left.ForAdd (right: BigNumber) = 
    let mutable Summ = [|0..(max  left.getValue.Length right.getValue.Length)-1|]
    let mutable Over = false
    for i = 0 to (max left.getValue.Length right.getValue.Length)-1 do
      if ((left.getValue.Length > i) && (right.getValue.Length > i)) 
        then
          Summ.[i] <- left.getValue.[i] + right.getValue.[i] + if Over then 1 else 0
          Over <- false 
          if (((string (Summ.[i])).Length) > CountofMaxDigitsinInt) 
            then 
              Over <- true
              Summ.[i] <- Summ.[i]- MinusOver
        else 
          if left.getValue.Length <= i 
            then
               Summ.[i] <- right.getValue.[i] + if Over then 1 else 0 
               Over <- false 
               if (((string (Summ.[i])).Length) > CountofMaxDigitsinInt) 
                 then 
                   Over <- true
                   Summ.[i] <- Summ.[i]- MinusOver
             else
               Summ.[i] <- left.getValue.[i] + if Over then 1 else 0 
               Over <- false 
               if (((string (Summ.[i])).Length) > CountofMaxDigitsinInt) 
                 then 
                   Over <- true
                   Summ.[i] <- Summ.[i]- MinusOver          
    if Over then Summ <- Array.concat [Summ ; [|1|]]
    new BigNumber (left.ArrayToStr Summ)
  //--------------------------------------------
  member left.Add(right:int)=
    left.Add(new BigNumber(string(right)))
     
  member left.Sub (right : BigNumber) = 
    let mutable T = new BigNumber("0")
    if not (left.Sign) && not (right.Sign) // a - b
       then 
         if left.AbsCompare(right) <> 0 
         then
          if left.AbsCompare(right) = 1 
           then T <- left.ForSub(right) 
           else 
                T <- right.ForSub(left)
                T.Sign <- true
    if (left.Sign) && (right.Sign) //-a - -b -> b-a 
       then
         let positiveLeft = new BigNumber(left.ToString().Substring(1))
         let positiveRight = new BigNumber(right.ToString().Substring(1))
         T <- positiveRight.Sub(positiveLeft)
    if not (left.Sign) && (right.Sign)// a - -b
       then
         let positiveRight = new BigNumber(right.ToString().Substring(1))
         T <- left.Add(positiveRight)
    if (left.Sign) && not (right.Sign) // -a - b -> -a + -b
       then
         let negativeRight = new BigNumber("-" + right.ToString())
         T <- left.Add(negativeRight)
    T                                                                                                                                                                                                                                                                                                                                                                                    
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                
  member private left.ForSub(right: BigNumber) = //left>=right
    let mutable Temp = [|0..(max  left.getValue.Length right.getValue.Length)-1|]
    let mutable Def = false
    for i = 0 to (max left.getValue.Length right.getValue.Length)-1 do
      if  (right.getValue.Length > i)
        then 
         Temp.[i] <- left.getValue.[i] - right.getValue.[i] - if Def 
                                                                then 
                                                                  Def <- false
                                                                  1
                                                                else 0
         if Temp.[i] < 0 
           then 
             Temp.[i] <- Temp.[i] + MinusOver
             Def <- true
       else Temp.[i] <- left.getValue.[i] - if Def 
                                              then 
                                                 Def <- false
                                                 1
                                              else 0
            if Temp.[i] < 0 
              then 
                Temp.[i] <- Temp.[i] + MinusOver
                Def <- true
    if Def then Temp <- Array.sub Temp 0 (Temp.Length - 1)
    new BigNumber (left.ArrayToStr Temp) 
    
  member left.Sub(right:int)=
    left.Sub(new BigNumber(string(right)))
    
    
  member private left.ForMul (right : BigNumber) =  //left>=right
    let mutable Res = new BigNumber("0")
    let mutable Temp = [|0..left.getValue.Length |]
    //let mutable TempS = [|0..(max  left.getValue.Length right.getValue.Length)|]
    let mutable LongTemp = 0L 
    let mutable Over = 0
    for j = 0 to  right.getValue.Length-1 do
     Over <- 0
     for i = 0 to left.getValue.Length-1 do
        LongTemp <- int64 (left.getValue.[i]) * int64 (right.getValue.[j])
        Temp.[i] <- int ( LongTemp % (int64 (MinusOver))) + Over
        if (((string (Temp.[i])).Length) > CountofMaxDigitsinInt) 
        then  
          Temp.[i] <- Temp.[i]- MinusOver                    
          Over <- int ( LongTemp / (int64 (MinusOver)))  + 1
        else
          Over <- int ( LongTemp / (int64 (MinusOver))) 
          
     if Over <> 0 then Temp.[left.getValue.Length] <- Over else Temp <- Array.sub Temp 0 (Temp.Length-1)
     for i = 1 to j do 
      Temp <- Array.append [|0|] Temp
     Res <- Res + BigNumber (left.ArrayToStr Temp) 
    Res
    
    
  member left.Mul(right :BigNumber) = 
    let mutable T = new BigNumber("0")
    if not (left.isZero || right.isZero) 
    then
      if left.AbsCompare(right) = 1 
      then 
        T <- left.ForMul(right)
      else
        T <- right.ForMul(left)
    if left.Sign = right.Sign
      then 
        T.Sign <- false
      else
        T.Sign <- true
    T
    
      
          
  //
  static member (+) (a : BigNumber, b : BigNumber) = a.Add(b)
  static member (+) (a : BigNumber, n) = a.Add(new BigNumber(n.ToString()))
  static member (+) (n, a : BigNumber) = a + (n.ToString())
  //
  static member (-) (a : BigNumber, b : BigNumber) = a.Sub(b)
  static member (-) (a : BigNumber, n) = a.Sub(new BigNumber(n.ToString()))
  static member (-) (n, a : BigNumber) = a - (n.ToString())
  //
  static member ( *) (a : BigNumber, b : BigNumber) = a.Mul(b)
  static member ( *) (a : BigNumber, n) = a.Mul(new BigNumber(n.ToString()))
  static member ( *) (n, a : BigNumber) = a * (n.ToString()) 
  //
            
//testing
let test = 
  printfn "Start Testing BigNumber"
  printfn ""
  printfn "Task 1 : Add"
  let mutable a = new BigNumber ("99999999999999999999999999999999")
  let mutable b = new BigNumber ("9999999999") 
  let mutable c = a + b
  printfn <| (if c.ToString() = "100000000000000000000009999999998" then "OK" else "FAIL")
  a <- new BigNumber ("-36412736782093")
  b <- new BigNumber ("738472396476983249238432098")
  c <- a + b
  printfn <| (if c.ToString() = "738472396476946836501650005" then "OK" else "FAIL")
  a <- new BigNumber ("1364762387463264923749732894903284092304832894798364787382479707489372478326423874983290482390792298237")
  b <- new BigNumber ("-7748923748932")
  c <- a + b
  printfn <| (if c.ToString() = "1364762387463264923749732894903284092304832894798364787382479707489372478326423874983290474641868549305" then "OK" else "FAIL")
  a <- new BigNumber ("-999999999")
  b <- new BigNumber ("-1")
  c <- a + b
  printfn <| (if c.ToString() = "-1000000000" then "OK" else "FAIL")
  printfn ""
  
  printfn "Task 2 : Sub"
  a <- new BigNumber ("-999999999")
  b <- new BigNumber ("1")
  c <- a - b
  printfn <| (if c.ToString() = "-1000000000" then "OK" else "FAIL")
  a <- new BigNumber ("7482937498732999999999")
  b <- new BigNumber ("-17348274983")
  c <- a - b
  printfn <| (if c.ToString() = "7482937498750348274982" then "OK" else "FAIL")
  a <- new BigNumber ("-123123123")
  b <- new BigNumber ("-123123123")
  c <- a - b
  printfn <| (if c.ToString() = "0" then "OK" else "FAIL")
  a <- new BigNumber ("0")
  b <- new BigNumber ("0")
  c <- a - b
  printfn <| (if c.ToString() = "0" then "OK" else "FAIL")
  printfn ""
  
  
  printfn "Task 3 : Mul"
  a <- new BigNumber ("7777777777")
  b <- new BigNumber ("-22222222222222222222222")
  c <- a * b
  printfn <| (if c.ToString() = "-172839506155555555555553827160494" then "OK" else "FAIL")
  a <- new BigNumber ("9999999999999999999999999999")
  b <- new BigNumber ("8312093111")
  c <- a * b
  printfn <| (if c.ToString() = "83120931109999999999999999991687906889" then "OK" else "FAIL")
  a <- new BigNumber ("-999999999")
  b <- new BigNumber ("1")
  c <- a * b
  printfn <| (if c.ToString() = "-999999999" then "OK" else "FAIL")
  a <- new BigNumber ("7482937498732999999999")
  b <- new BigNumber ("0")
  c <- a * b
  printfn <| (if c.ToString() = "0" then "OK" else "FAIL")
 

