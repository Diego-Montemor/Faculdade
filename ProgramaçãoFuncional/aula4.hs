{- objetivo: trabalhar tipos distintos entre listas e tuplas -}

import Data.Char

------------------------------------------------------
{- 01 função que separa [(Int,Char)] em ([Int],[Char]) -}
myUnzip :: [(Int,Char)]->([Int],[Char])
myUnzip [] = ([],[])
myUnzip((a,b):xs) = (a:fst(myUnzip xs),  b:snd(myUnzip xs))


{- 02 versão em uma única função -}
--myUnzipU :: [(Int,Char)]->([Int],[Char])

------------------------------------------------------------
{- 03 função que junta duas listas em lista de duplas -}
myZip::[Bool]->[Char] ->[(Bool,Char)]  
myZip [] [] = []
myZip (x:xs) (y:ys) = (x,y): myZip xs ys


{- 04 função que recebe [Char] e retorna [(Bool,Char)] 
   True se Char for alfanumérico e False, caso contrário  48-90  97-122  -}
setAlfa::String -> [(Bool,Char)] 
setAlfa [] = []
setAlfa (x:xs) = [(ord x >= 48 && ord x <= 90 || ord x >= 97 && ord x <= 122, x)] ++ setAlfa xs

   
{- 05 função que recebe [(Bool, Char)] e filtra alfanuméricos -}
filtraAlfa:: [(Bool,Char)] -> String
filtraAlfa [] = []
filtraAlfa ((a,b):xs)
   | a = b : filtraAlfa xs
   | otherwise = filtraAlfa xs

{- 06 função transforma String de alfa em Int -}
alfaToInt::String -> [Int]
alfaToInt [] = []
alfaToInt (x:xs) 
   | isNumber x = (ord x - ord '0') : alfaToInt xs
   | otherwise = alfaToInt xs

tamLista :: [a] -> Int
tamLista [x] = 1
tamLista (x:xs) = 10 * tamLista xs 

listParaInt:: [Int] -> Int -> Int   
listParaInt [] _ = 0
listParaInt (x:xs) y = x*y + listParaInt xs (y`div`10)

final:: [Int] -> Int
final x = listParaInt x (tamLista x) 

{-- 07 função que gera tabela ascii -}
geraASCII:: Int->[(Int,Char)]
geraASCII 0 = [(0, chr 0)]
geraASCII x = geraASCII (x-1) ++ [(x,chr x)]


{-  
f:: String -> Int
f [] = 0
f (a:b) = (Valor de a) + (f b)*10
-}