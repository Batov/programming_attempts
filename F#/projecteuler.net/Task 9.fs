//Batov 171gr
//SPBSU
for a= 1 to 999 do
  for b = a+1 to 999 do
    let c = 1000-b-a
    if a*a+b*b=c*c then printf "%A" <| (a*b*c)
      