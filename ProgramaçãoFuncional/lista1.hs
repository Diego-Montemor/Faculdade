import GHC.Exts.Heap.Constants (tAG_MASK)
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
tamanhoInt:: Int -> Int -> Int
tamanhoInt x y
    | x > y = tamanhoInt x (y*10)
    | otherwise = y`div`10

inverte:: Int -> Int -> Int -> Int
inverte _ 0 _ = 0 
inverte x y z = (x `div` y)*z + inverte (x`mod`y) (y`div`10) z*10

inverteInt :: Int -> Int
inverteInt x = inverte x (tamanhoInt x 1) 1

-- Exercicio 5

square :: Int -> Int
square x = x * x

fourPower :: Int -> Int
fourPower x = square (square x)

-- Exercicio 6

somaDeRaiz :: Int -> Float
somaDeRaiz  1 = sqrt 6 
somaDeRaiz x = sqrt (6 + somaDeRaiz (x - 1))

-- Exercicio 7

arranjo :: Int -> Int -> Int
arranjo x y = fat x `div` fat (x - y)
-- OBS: para funcionar x >= y

-- Exercicio 8

mdc :: Int -> Int -> Int
mdc x y 
    | (x `mod` y) /= 0 = mdc x (x `mod` y)
    | otherwise = y
-- OBS: para funcionar x >= y

-- Exercicio 9

multiploEmIntervalo :: Int -> Int -> Int -> Int
multiploEmIntervalo x y z
    | x <= z = 1 + multiploEmIntervalo x y z
    |otherwise = 0