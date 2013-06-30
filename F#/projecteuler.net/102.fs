//Batov 171gr 
//SPBSU

open System
let x = 0
let y = 1
let mutable result = 0

let input = (System.IO.File.ReadAllLines("/home/batov/triangles.txt"));

let Check (a:int[]) (b:int[]) (c:int[]) = 
  Math.Abs((a.[x]-c.[x])*(b.[y]-a.[y])-(a.[x]-b.[x])*(c.[y]-a.[y])); 
  
for line in input do
  let (parts:string[]) = line.Split(',');
  let A = [|Convert.ToInt32(parts.[0]);Convert.ToInt32(parts.[1])|];
  let B = [|Convert.ToInt32(parts.[2]);Convert.ToInt32(parts.[3])|];
  let C = [|Convert.ToInt32(parts.[4]);Convert.ToInt32(parts.[5])|];
  let Zero = [|0;0|];   
  if (Check A  B  C) = (Check A B Zero) + (Check A Zero C) + (Check Zero B C) 
    then 
      result <- result + 1
    
printfn "%A" result;
     
        
           
              
                 
                    
                                    
                                   
                                      
                                         
                                            
                                               
                                                  
                                                     
                                                        
                                                           
                                                              
                                                                 
                                                                    
                                                                       
                                                                          
                                                                             
                                                                                
                                                                                   
                                                                                       
 