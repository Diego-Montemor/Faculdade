import Data.Char
-- Exercicio 1
somaLista:: Int
somaLista = sum [x^2 | x <- [1..100]]

-- Exercicio 2
replica:: Int -> a -> [a]
replica 0 _ = []
replica x b = b: replica (x-1) b

-- Exercicio 3
pyths:: Int -> [(Int, Int, Int)]
pyths x = [(a,b,c)|a <- [1..x], b <- [1..x], c <- [1..x], a^2 + b^2 == c^2]

-- Exercicio 4
perfeito:: Int -> [Int]
perfeito x = [b | b <- [1..x] ,b == sum [a | a <-[1..(b-1)], b `mod` a == 0]]

-- Exercicio 5
listaConcat:: [(Int,Int)]
listaConcat = concat [[(x,y)| y <- [4,5,6]] | x <- [1,2,3]]

-- Exercicio 6
find :: Eq a1 => a1 -> [(a1, a2)] -> [a2]
find x y = [snd t | t <- y, x == fst t]

positions :: Eq a => a -> [a] -> [Int]
positions x xs = find x (zip xs [0..n])
    where n = length xs - 1

-- Exercicio 7
scalarproduct :: [Int] -> [Int] -> Int
scalarproduct x y = sum [fst a * snd a | a <- zip x y]

-- Exercicio 9
altaOrdem x = map (+7) (filter odd x)

-- Exercicio 10 
dec2int :: [Int] -> Int
dec2int x = sum [(fst a)*10^(snd a) | a <- zip (reverse x) [0,1..]]

-- Exercicio 14

howManyMultiples:: Int -> Int -> Int -> Int
howManyMultiples x a b = length [y | y <- [a..b] , (y `mod` x) == 0]

-- Exercicio 15 
duplicate:: String -> Int -> String
duplicate x y = [a | b <- [1..y], a <- x]

-- Exercicio 16
pushRight::String->Int->String
pushRight x y = ['>'| a <- [1..(y - length x)]] ++ x

-- Exercicio 17
inverte:: [a] -> [a]
inverte x = [a | a <- reverse x]

-- Exercicio 18
separa:: [Int] -> ([Int],[Int])
separa x = ([a|a<-x,even a],[a|a<-x,odd a])

-- Exercicio 19
converte:: [Int] -> String
converte x = [chr (a+64)| a<-x]

-- Exercicio 20
conta:: String -> Char -> Int
conta x y = length [a| a <- x , y == a]

-- Exercicio 21
prolifera:: Int -> [Int]
prolifera x = [x| a<- [1..x]]

proliferaInt:: [Int] -> [Int]
proliferaInt x = concat [prolifera a | a <- x]

-- Exercicio 22
proliferaC:: Char -> [Char]
proliferaC x = [x| a<- [1..(ord x - 64)]]

proliferaChar:: [Char] -> [Char]
proliferaChar x = concat [proliferaC a | a <- x]

-- Exercicio 23

