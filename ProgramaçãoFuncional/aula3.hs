maxi::Int -> Int -> Int
maxi x y 
    | x >= y = x 
    | otherwise = y

f:: Int -> Int
f 1 = 9
f 2 = 7
f 3 = 15
f 4 = 14
f 5 = 8
f 6 = 0
f 7 = 3
f x = 0

--Listas
listaDeVendas:: Int -> [Int]
listaDeVendas 0 = [0]
listaDeVendas x = f x : listaDeVendas (x-1)

listaDeVendasCDias:: Int -> [[Int]]
listaDeVendasCDias 0 = []
listaDeVendasCDias x = listaDeVendasCDias (x-1) ++ [[x,f x]]


totalVendasLista:: [[Int]] -> Int
totalVendasLista [] = 0
totalVendasLista ((x:y:xs):ys) = y + totalVendasLista ys

--Tuplas
tuplasDeVendasCDias:: Int -> [(Int,Int)]
tuplasDeVendasCDias 0 = []
tuplasDeVendasCDias x = tuplasDeVendasCDias (x-1) ++ [(x , f x)]

totalVendasTupla:: [(Int,Int)] -> Int
totalVendasTupla [] = 0
totalVendasTupla ((a,b):xs) = b + totalVendasTupla xs



temMenor:: Int -> [Int] -> Bool
temMenor x (y:ys)
    | x > y = True
    |otherwise = temMenor x ys

ordena:: [Int] -> [Int]
ordena [] = []
ordena (x:y:xs)
    | y > x = y : ordena (x:xs)
    |otherwise = x:ordena (y:xs)