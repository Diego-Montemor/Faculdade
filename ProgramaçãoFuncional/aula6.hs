import Data.Char

{-
Como funciona:
list comprehension -> ['operação' | 'elementos' , 'condição']
-}

f1:: Int -> [Int] -> [Int]
f1 z l = [z*a | a <- l, a `mod` 2 == 0]

f2:: Bool -> [Int] -> [Int]
f2 b l 
    | b = [a*2|a <- l]
    | otherwise = [a + 5|a <- l]

f3:: [Int] -> [Int] -> [(Int,Int)]
f3 a b = [(x,y) |x <- a ,y <- b]

f3_count::[(Int,Int)]

f3_aux:: [(Int,Int)] -> ([Int],[Int])
f3_aux l = ([a|(a,b) <- l],[b|(a,b) <- l])