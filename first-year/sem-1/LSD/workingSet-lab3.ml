(*working set 1*)

(* 1) Write a function that receives a list and reverses it. *)
let rec reverse list = 
  let rec internal acc = function
  |[] -> acc
  |head :: tail -> internal (head :: acc) tail in
internal [] list;;

reverse [1;2;3;4;5];;

(* 2) Write a function that builds a list from the digits of a given integer. Order does not matter. *)
let rec list_from_digitsOfInteger n = 
  let rec internal n acc = match n with
  |0 -> acc
  |k -> internal(k/10) (k mod 10 :: acc) in
internal n [] ;;

list_from_digitsOfInteger 1234;;

(* 3) Write the functions toBaseX and fromBaseX which converts a number from base 10 to base X, respectively vice versa.  X = 8 *)
  let toBaseX x num = 
    let rec internal num2 acc = match num2 with
      | k when k = 0 ->  acc
      | k -> internal (k/x) ((k mod x)::acc) in
internal num [];;

toBaseX 8 14;;

let toBaseX n x =
  let rec toBaseXInternal y acc =match y with
  |k when k=0 -> acc
  |k -> toBaseXInternal (k/x) ((k mod x) :: acc)
  in toBaseXInternal n [];;
toBaseX 14 8 ;;

let fromBaseX n x =
  let reverse lista=
                     let rec reverseInternal acc = function 
                    | [] ->acc
                    | h :: t -> reverseInternal (h::acc) t in 
                    reverseInternal [] n in
  let rec fromBaseXInternal indice acc= function
  | [] -> int_of_float acc
  | h :: t -> fromBaseXInternal (indice+1) ((h*.(2.**(float_of_int( indice))))+.acc) t in
  fromBaseXInternal 0 0. (reverse n);;
fromBaseX [1.;6.] 10;;


(* 4) Write a function that calculates the sum of all integers of a list. *)
let listSum list = 
  let rec listSumInternal acc = function
  |[] -> acc
  |h :: t -> listSumInternal (h + acc) t in 
  listSumInternal 0 list;;

listSum [1;2;3;4;5];;

(* 5) Write a function that drops all integers divisible with 3. *)
let dropDiv3 list =
  let rec dropDiv3Internal acc list = match list with
    | [] -> []
    | h :: t -> if h mod 3 = 0 then dropDiv3Internal 1 t else h :: dropDiv3Internal (acc + 1) t  in
    dropDiv3Internal 1 list;;

dropDiv3 [1;3;4;5;6;7;8;9];;

(* 6) Write a function that extracts the nth_opt element of a list, where n is an argument. Note: If n is greater than the rest of the list, your function’s result should be None. *)
let rec ext_nth_opt n list = match list with
  |[] -> None
  |h :: t -> if n = 1 then Some h else ext_nth_opt (n-1) t;;

ext_nth_opt 10 [1;3;5;6;7;8;9];;
ext_nth_opt 7 [1;3;5;6;7;8;9];;

(* 7) ) Write a function that calculates the list of the first k prime numbers following after x. (k, x - arguments)  *)
let is_prime n =
  let aux = abs n in
  let rec is_not_divisor d =
    d * d > aux || (aux mod d <> 0 && is_not_divisor (aux + 1)) in
    aux <> 1 && is_not_divisor 2;;

let rec calc_list l k x =  match k with
|a when x = k -> l
|a when is_prime a = true -> calc_list (a::l) (k+1) (x+1)
|a -> calc_list l (k+1) x ;;

calc_list [] 10 1;;

(* 8) Implement the map function over lists from the List module. *)
let rec mapList func list = match list with 
| [] -> []
| head :: tail -> func head :: (mapList func tail);;

mapList (fun x -> x*x) [1;2;3;4;5];;

(* 9) Write a predicate that tests whether a list has its elements in ascending order. *)
let rec is_ascending l = match l with
| [] -> true
| h::[] -> true
| h::h2::t -> if h <= h2 then is_ascending (h2::t) else false;;

is_ascending [-1;3;8;4;5;6;7];;
is_ascending [-3;0;1;4;6;8;12;18];;
