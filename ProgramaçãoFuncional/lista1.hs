-- Exercicio 1
f1 :: Int -> Int
f1 x 
    | x >= 0 = (x+4)`div`(x+2)
    | x < 0  = 2`div`x

f2 :: Int -> Int -> Int
f2 x y 
    | x >= y = x + y
    | x < y  = x - y

f3 :: Int -> Int -> Int -> Int
f3 x y z
    | (x + y) > z  = x + y + z
    | (x + y) < z  = x - y - z
    | (x + y) == z = 0  

-- Exercicio 2
fat :: Int -> Int
fat 0 = 1
fat x = x * fat(x-1)

-- Exercicio 3

soma :: Int -> Int -> Int
soma x y = x + y

multi :: Int -> Int -> Int
multi _ 0 = 0
multi x y = soma x (multi x (y-1))   

-- Exercicio 4

inverteInt :: Int -> Int
inverteInt x
    | x > 1000 = (x`div`1000) + inverteInt x
    | x > 100 = (x`div`100)*10 + inverteInt x
    | x > 10 = (x`div`10)*100 + inverteInt x
    | x > 1 =  (x`div`1)*1000 + inverteInt x
    |otherwise = 0

-- Exercicio 5

square :: Int -> Int
square x = x * x

fourPower :: Int -> Int
fourPower x = square (square x)

-- Exercicio 6

somaDeRaiz :: Int -> Int
somaDeRaiz x 
