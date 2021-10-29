(*Working set 1*)

(*1*)
let transpusa ((a11,a12) , (a21,a22)) = ((a11,a21) , (a12,a22));;
transpusa ((1,2),(3,4));;

(*2*)

let f x = match x with 
| k when k <= (-1) -> k-1
| k when k >= 1 -> k+1
| k -> -k;;

(*3*)
let rec fact x =
  if x <= 1 then 1 else x * fact (x - 1);;

(*4*)
let reverse x = 
  let rec internal x acc = 
    match x with
    |0 -> acc
    |k -> internal (k/10) (acc*10 + (k mod 10)) in
  internal x 0;;
reverse 1234;;

(* 5)  Write a function that finds the pair (minDigit, maxDigit) of an integer. ??????*)
let rec minim x acc = 
  match x with
  |0 -> acc
  |k when (k mod 10) < acc -> minim (x/10) (k mod 10)
  | _ -> minim (x/10) acc;;

let rec maxim x acc = 
  match x with
  |0 -> acc
  |k when (k mod 10) > acc -> maxim (x/10) (k mod 10)
  | _ -> maxim (x/10) acc;;

let min_max_N n (minDigit, maxDigit) = 
  match n with 
  |0 -> (0, 0)
  |k -> (minim n 10, maxim n (-1));;
min_max_N 3241 (0,0);;


(* ??? 6) Write a function that calculates the number of numbers in interval [a,b] containing the digit k. (a,b and k are arguments)*)
let k_numbers (a, b) k = 
  let rec find_k acc a = match a with
| p when p = b -> acc
| p when (p mod 10) = k -> find_k ( acc + 1 ) (p + 1)
| _ -> find_k acc (a + 1) in
find_k 0 a ;;

k_numbers (10, 20) 2;;

(* 7) Hofstadter sequence: Hofstadter Female and Male sequences (https://en.wikipedia.org/wiki/Hofstadter_sequence) 
=> Mutual recursion (let rec f and g) *)
let rec female n = 
  match n with
  |0 -> 1
  |k -> k - male( female (k - 1))
and male n = 
match n with
|0 -> 0
|k -> k - female( male (k - 1));;

female 12;;
male 12;;

(*??? 8)  Approximate the e^x function using its Maclaurin series with 100 steps. Afterwards, generalise your function to receive an arbitrary number of steps ???*)
let rec fact n = 
  if n = 0 then 1
  else n * fact (n - 1)

let rec maclaurin x n = 
  if n = 0 then 1.
  else let t = x ** (float_of_int n) /. float_of_int (fact n) in
  maclaurin x (n - 1) +. t;;

  maclaurin 1. 12;;

(*?????? 1.a - tema 3
let range inf sup =
  let rec interval acc inf = match inf with
  |p when p = sup -> acc 
  |
 ?????*)
  
(*3 - tema 3 *)
let rec double_list list = match list with
| [] -> [] 
| cap :: coada -> cap*2 :: double_list (coada);;

double_list [1;2;3;4];;  