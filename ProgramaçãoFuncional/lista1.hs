import Data.Char -- começa a usar no exercicio 17
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
    | y <= z = 1 + multiploEmIntervalo x (y+x) z
    |otherwise = 0

-- Exercicio 10

lastDigit:: Int -> Int
lastDigit x = x `mod` 10

-- Exercicio 11

anyDigit:: Int -> Int -> Int
anyDigit x y 
    | 10^x > y = -1
    |otherwise = lastDigit (inverteInt y `div` 10^x)

-- Exercicio 12

-- (a) não compara se m é diferente de p

-- (b)
allDiferents:: Int -> Int -> Int -> Bool
allDiferents a b c = a/=b && a/=c && b/=c

-- Exercicio 13
howManyEqual:: Int -> Int -> Int -> Int 
howManyEqual x y z 
    | allDiferents x y z = 0
    | (x == y) && (y == z) = 3
    |otherwise = 2

-- Exercicio 14

vendas:: Int -> Int
vendas 1 = 10
vendas 2 = 0
vendas 3 = 30
vendas 4 = 0
vendas 5 = 50
vendas 6 = 0
vendas 7 = 70
vendas _ = 0

-- (a)
howManyLess:: Int -> Int -> Int -> Int
howManyLess x a b
    | a <= b && vendas a < x = 1+ howManyLess (a+1) b x 
    | a <= b = howManyLess (a+1) b x 
    |otherwise = 0

-- (b)
noZeroInPeriod:: Int -> Bool
noZeroInPeriod 0 = True
noZeroInPeriod x = (vendas x > 0) && noZeroInPeriod (x-1)

-- (c)
period::Int -> [Int]
period 0  = []
period x 
    | vendas x == 0 = period (x-1) ++ [x]
    |otherwise = period (x-1)

zeroInPeriod:: [Int]
zeroInPeriod = period 7 

-- (d)
periodL:: Int -> Int -> [Int]
periodL _ 0 = []
periodL x y 
    | vendas y < x = periodL x (y-1) ++ [y]
    |otherwise = periodL x (y-1) 

periodLess:: Int -> [Int]
periodLess x = periodL x 7

-- Exercicio 15 

fib:: Int -> Int
fib 0 = 0
fib 1 = 1
fib x = fib (x-2) + fib (x-1) 

percorreFib:: Int -> Int -> Int
percorreFib x y 
    | x > fib y = percorreFib x (y+1)
    | x == fib y = y
    |otherwise = -1

antFib:: Int -> Int
antFib x = percorreFib x 2

-- Exercicio 16

funny:: Int -> Int -> Int -> Bool
funny x y z = x > z && x < y 

-- Exercicio 17

myToUpper:: Char -> Char
myToUpper x 
    | 'A' <= x && x <= 'Z' = x 
    | 'a' <= x && x <= 'z' = chr (ord (x) - 32)

-- Exercicio 18

charToNumber:: Char -> Int
charToNumber x = ord (x) - 48

-- Exercicio 19 

duplicate:: String -> Int -> String
duplicate _ 0 = "."
duplicate x y = x ++ duplicate x (y-1)

-- Exercicio 20

tam:: [a] -> Int
tam [] = 0
tam (x:xs) = 1 + tam xs

pushRight:: String -> Int -> String
pushRight x y 
    | tam x < y = '>':pushRight x (y-1)
    | otherwise = x

-- Exercicio 21

(&-):: Int -> Int -> Int
x &- y = x - 2*y
--para 10 &- 3 &- 2
-- infixl 6 &- = 0  maior precedencia a equerda
-- infixr 6 &- = 12 maior precedencia a direita
-- infix  6 &- = 0  maior precedencia padrão (esquerda)

--para 10 &- 3 * 2
-- infix 6 &- = -2 a operação * tem maior precedencia
-- infix 8 &- = 8 a operação &- tem maior precedencia

-- Exercicio 22

inverteLista:: [a] -> [a]
inverteLista [] = []
inverteLista (x:xs) = inverteLista xs ++ [x]

-- Exercicio 23

separaImparPar:: [Int] -> ([Int],[Int])
separaImparPar [] = ([],[])
separaImparPar (x:xs)
    | x `mod` 2 == 0 = (fst(separaImparPar xs), x:snd(separaImparPar xs))
    | x `mod` 2 == 1 = (x:fst(separaImparPar xs), snd(separaImparPar xs))

-- Exercicio 24    

converte:: [Int] -> String
converte [] = ""
converte (x:xs) = chr(x + 64):converte xs

-- Exercicio 25
{-
a) ['a'..'g'] = ['a','b','c','d','e','f','g']
b) [0.1..0.9] = [0.1,1.1]
c) [0.1,0.3..0.9] = [0.1,0.3,0.5,0.7,0.8999]
d) [0.4,0.2..0.8] = []
e) [1,4..15] = [1,4,7,10,13]    
-}
-- Exercicio 26

contaChar:: [Char] -> Char -> Int
contaChar [] _ = 0
contaChar (x:xs) y 
    | x == y = contaChar xs y + 1
    | otherwise = contaChar xs y

-- Exercicio 27
estaPresente:: Int ->[Int] -> Bool
estaPresente _ [] = False
estaPresente y (x:xs) = x == y || estaPresente y xs

purifica:: [Int] -> [Int]
purifica [] = []
purifica (x:xs)
    | estaPresente x xs = purifica xs
    | otherwise = x:purifica xs

-- Exercicio 28
addNaLista:: a -> Int -> [a]
addNaLista _ 0  = []
addNaLista x y = x: addNaLista x (y-1)

proliferaInt:: [Int] -> [Int]
proliferaInt [] = []
proliferaInt (x:xs) = addNaLista x x ++ proliferaInt xs

-- Exercicio 29

proliferaChar:: [Char] -> [Char]
proliferaChar [] = []
proliferaChar (x:xs)
    | 'A' <= x && x <= 'Z' = addNaLista x (ord x - 64) ++ proliferaChar xs 
    | 'a' <= x && x <= 'z' = addNaLista x (ord x - 96) ++ proliferaChar xs

-- Exercicio 30

myToLower:: Char -> Char
myToLower x 
    | 'A' <= x && x <= 'Z' = chr (ord (x) + 32) 
    | 'a' <= x && x <= 'z' = x

converteChar:: Char -> (Char,Char,Int)
converteChar x = (myToLower x, myToUpper x, ord x)
-- myToUpper veio do Exercicio 17

-- Exercicio 31
rg :: Int -> (String, Int, Char)
rg n 
    | n == 1 = ("Diego Montemor", 20, 'm')
    | n == 2 = ("Mariana Montemor", 17, 'f')
    | n == 3 = ("Carlos Silva", 25, 'm')
    | n == 4 = ("Ana Souza", 30, 'f')
    | n == 5 = ("Lucas Oliveira", 22, 'm')
    | n == 6 = ("Beatriz Costa", 28, 'f')
    | n == 7 = ("João Pedro Santos", 35, 'm')
    | n == 8 = ("Gabriela Lima", 24, 'f')
    | n == 9 = ("Rafael Rodrigues", 40, 'm')
    | n == 10 = ("Fernanda Alves", 27, 'f')
    | n == 11 = ("Marcos Ferreira", 31, 'm')
    | n == 12 = ("Camila Pereira", 29, 'f')
    | n == 13 = ("Thiago Gomes", 26, 'm')
    | n == 14 = ("Leticia Ribeiro", 21, 'f')
    | n == 15 = ("Bruno Martins", 33, 'm')
    | n == 16 = ("Amanda Carvalho", 23, 'f')
    | n == 17 = ("Rodrigo Mendes", 38, 'm')
    | n == 18 = ("Larissa Rocha", 19, 'f')
    | n == 19 = ("Marcelo Dias", 45, 'm')
    | n == 20 = ("Natalia Barbosa", 32, 'f')
    | otherwise = ("Ninguem com esse registro!", 9999, 'x')

myFst:: (a,b,c) -> a
myFst (x,_,_) = x 

mySnd:: (a,b,c) -> b
mySnd (_,x,_) = x

myTrd:: (a,b,c) -> c 
myTrd (_,_,x) = x    

--(a)

buscaIdade:: Int -> Int -> Int -> (String,Int,Char)
buscaIdade x y z
    | mySnd (rg x) < mySnd (rg y) = buscaIdade x (y+1) z
    | y > z = rg x
    | otherwise = buscaIdade y (y+1) z

nomeMenorIdade:: Int -> String
nomeMenorIdade x = myFst (buscaIdade 1 1 x)

--(b)
calculaMedia:: Int -> Int -> Int -> Int 
calculaMedia x y z 
    | y <= z = x + mySnd(rg y)
    | otherwise = x `div` y 

mediaIdade:: Int -> Int 
mediaIdade x = calculaMedia 0 1 x

-- Exercicio 32

ordenaTupla:: (Int,Int,Int,Int) -> (Int,Int,Int,Int)
ordenaTupla (a,b,c,d)
    | a > b = ordenaTupla (b,a,c,d)
    | b > c = ordenaTupla (a,c,b,d)
    | c > d = ordenaTupla (a,b,d,c)
    | otherwise = (a,b,c,d) 

ordenaT:: Int -> Int -> Int -> Int -> (Int,Int,Int,Int)
ordenaT a b c d = ordenaTupla (a,b,c,d) 

-- Exercicio 33

diferencaDeDatas:: (Int,Int,Int) -> (Int,Int,Int) -> Int
diferencaDeDatas (a,b,c) (x,y,z) = (x + y*30 + z*365) - (a + b*30 + c*365)

