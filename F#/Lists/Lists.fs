//#indent "off"
//Batov gr171
//SPBSU

let addtoend (l:list<_>) (x:_) = l @ [x] // Две разные реализации, как надо?

let rec pushth x =  //push through a list
  function
  | [] -> [x]
  | head::tail -> head::(pushth x tail)

let test_for_addtoend= 
  printfn "Добавление элемента в конец списка  addtoend+pushth"
  if addtoend [] 3 = [3] then printfn "Тест пройден   addtoend [] 3 = [3]" else printfn "Тест провален"
  if addtoend [2;43] 1000 = [2;43;1000] then printfn "Тест пройден   addtoend [2;43] 1000 = [2;43;1000]" else printfn "Тест провален"
  if addtoend [1;1;1;1;1;1;1] 8 = [1;1;1;1;1;1;1;8] then printfn "Тест пройден   addtoend 1;1;1;1;1;1;1] 8 = [1;1;1;1;1;1;1;8]" else printfn "Тест провален"
  if addtoend [0] 0 = [0;0] then printfn "Тест пройден   addtoend [0] 0 = [0;0]" else printfn "Тест провален"
  if pushth 300 [2] = [2;300] then printfn "Тест пройден   pushth [2] 300 = [2;300]" else printfn "Тест провален"
  if pushth 80 [32;4] = [32;4;80] then printfn "Тест пройден   pushth [32;4] 80 = [32;4;80]" else printfn "Тест провален"
  if pushth 0 []  = [0] then printfn "Тест пройден   pushth [] 0 = [0]" else printfn "Тест провален"
  if pushth 77 [7;7] = [7;7;77] then printfn "Тест пройден   pushth [7;7] 77 = [7;7;77]" else printfn "Тест провален"

printfn "---" 

//-----------------------------------------------------------------------------
//let conc2 l l2 = l @ l2

let rec conc list1 list2=
  match list1 with
  | [] -> list2
  | head::tail -> head::(conc tail list2)  

let test_for_conc= 
  printfn "Слияние списков  conc"
  if conc [] [] = [] then printfn "Тест пройден   conc [] [] = []" else printfn "Тест провален"
  if conc [2;43] [1000;12] = [2;43;1000;12] then printfn "Тест пройден   conc [2;43] [1000;12]" else printfn "Тест провален"
  if conc [1;1;1;1;1;1;1] [] = [1;1;1;1;1;1;1] then printfn "Тест пройден   conc [1;1;1;1;1;1;1] [] = [1;1;1;1;1;1;1]" else printfn "Тест провален"
  if conc [1..9] [10..20]  = [1..20] then printfn "Тест пройден   conc [1..9] [10..20]  = [1..20]" else printfn "Тест провален"

printfn "---"  

//-----------------------------------------------------------------------------
let rec reverse = 
  function
  | [] -> []
  | head::tail -> pushth head (reverse tail)

let test_for_reverse= 
  printfn "Обратный порядок reverse"
  if reverse [] = [] then printfn "Тест пройден    reverse [] = []" else printfn "Тест провален"
  if reverse [1;2;3;4] = [4;3;2;1] then printfn "Тест пройден    reverse [1;2;3;4] = [4;3;2;1]" else printfn "Тест провален"
  if reverse [1.;10.] = [10.;1.] then printfn "Тест пройден    reverse [1.;10.] = [10.;1.]" else printfn "Тест провален"
  if reverse [0;0;0;1] = [1;0;0;0] then printfn "Тест пройден    reverse [0;0;0;1] = [1;0;0;0]" else printfn "Тест провален"

printfn "---"  

//-----------------------------------------------------------------------------
let rec map f = 
  function
  | [] -> []
  | head::tail -> (f head)::(map f tail)
    
let test_for_map= 
  printfn "Применение функции к каждому элементу списка map"
  if map (fun x -> x+1) [1;2] = [2;3] then printfn "Тест пройден    map (fun x -> x+1) [1;2] = [2;3]" else printfn "Тест провален"
  if map (fun x -> x*10) [10;100] = [100;1000] then printfn "Тест пройден    map (fun x -> x*2) [10;100] = [100;1000]" else printfn "Тест провален"
  if map ((+) 8) [0] = [8] then printfn "Тест пройден    map ((+) 8) [0] = [8]" else printfn "Тест провален"
  if map (fun x -> x/0) [] = [] then printfn "Тест пройден    map (fun x -> x/0) [] = []" else printfn "Тест провален"

printfn "---" 

//-----------------------------------------------------------------------------
let rec find key =
    function
    | [] -> None
    | head::tail -> if key head then Some head else find key tail

let test_for_find= 
  printfn "Поиск по ключу find"
  if find ((=)3) [1..2] = None then printfn "Тест пройден    find ((=)3) [1..2] = None" else printfn "Тест провален"
  if find ((=)90) [1..200] = Some 90 then printfn "Тест пройден    find ((=)90) [1..200] = Some 90" else printfn "Тест провален"
  if find ((=)0) [0] = Some 0 then printfn "Тест пройден    find ((=)0) [0] = Some 0 " else printfn "Тест провален"
  if find ((=)0) [] = None  then printfn "Тест пройден    find ((=)0) [] = None" else printfn "Тест провален"