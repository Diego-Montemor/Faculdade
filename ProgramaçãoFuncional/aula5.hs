-- 01 Operador que define o menor numero
infix 7 &<&
(&<&) :: Int -> Int -> Int
x &<& y 
    | x < y = x
    |otherwise = y

menorL:: [Int] -> Int   
menorL [x] = x
menorL (x:xs) = x &<& menorL xs

menorD:: [Int] -> (Int,[Int])
menorD x = (menorL x, x)

filtraL:: (Int,[Int]) -> [Int]
filtraL (_,[]) = []
filtraL (x,(y:ys))
    | x == y = ys
    |otherwise = y:filtraL (x,ys)

ordenaL:: (Int,[Int]) -> [Int]
ordenaL (_,[]) = []
ordenaL (x, y) = x:ordenaL(menorD (filtraL (x,y)))

ordena:: [Int] -> [Int]
ordena [] = []
ordena x = ordenaL (menorL x, x)

ordenaBB:: [Int] -> [Int]
ordenaBB [] = []
ordenaBB (x:y:xs)
    | y > x = y : ordenaBB (x:xs)
    |otherwise = x:ordenaBB (y:xs)