import Data.Char

type Dia = Int
type Venda = Int

maxi::Int -> Int -> Int
maxi x y 
    | x >= y = x 
    | otherwise = y


f:: Dia -> Venda
f 1 = 9
f 2 = 7
f 3 = 15
f 4 = 14
f 5 = 8
f 6 = 0
f 7 = 3
f x = 0

periodo:: Dia
periodo = 7

total:: Dia -> Venda
total 0 = 0
total x = total (x - 1) + f x

totalVendas:: Venda
totalVendas = total periodo

maiorVenda:: Dia -> Venda -> Venda
maiorVenda 0 v = v 
maiorVenda x v = maxi (maiorVenda(x - 1) (f x)) v

maiorVenda1:: Dia -> Venda 
maiorVenda1 0 = f 0
maiorVenda1 x = maxi (maiorVenda1 (x-1)) (f x)

diaMaiorVenda:: Dia -> Dia -> Venda
diaMaiorVenda 0 d = d
diaMaiorVenda x d 
    | f d >= f x = diaMaiorVenda (x - 1) d
    |otherwise = diaMaiorVenda (x - 1) x

vendaPeriodo:: Dia -> Dia -> Venda
vendaPeriodo x y
    | x > y = 0
    |otherwise = vendaPeriodo (x + 1) y + f x   