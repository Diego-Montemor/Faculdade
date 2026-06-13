{-
1. (20 pt) Faça, em Haskell, uma solução que receba um Int a e uma [Int] b. Como saída,
teremos um Bool que informa se a ∈ b.
-}
f1::Int->[Int]->Bool
f1 _ [] = False
f1 x (y:ys) = x == y || f1 x ys

{-
2. (20 pt) Considerando f1, faça, em Haskell, uma solução que receba um Int x e uma [[Int]] l.
Como saída, teremos uma [(Bool, [Int])] s que informa, para cada sublista li de l, se o elemento
x pertence ou não à lista
-}
f2::Int->[[Int]]->[(Bool,[Int])]
f2 _ [] = []
f2 x (y:ys) = (f1 x y, y):f2 x ys 

{-
3. (20 pt) Considerando f2, faça, em Haskell, uma solução que receba um Int x e uma [[Int]] l.
Como saída, teremos uma (Int, [(Bool, [Int])]) s que informa o Int x e, para cada sublista li
de l, se o elemento x pertence ou não à lista
-}
f3::Int->[[Int]]->(Int,[(Bool,[Int])])
f3 x y = (x, f2 x y)

{-
4. (20 pt) Faça, em Haskell, uma solução que receba uma (Int,[(Bool,[Int])]) e gere uma [[Int]]
com apenas as listas [Int] cujo Bool da dupla é False.
-}
f4::(Int,[(Bool,[Int])])->[[Int]]
f4 (_,[]) = []
f4 (a,((y,x):xs))
    | not y  = x: f4 (a,xs)
    | otherwise = f4 (a,xs)

{-
5. (15 pt) Faça, em Haskell, uma solução que receba duas strings S e R, cuja menor tem tamanho
n. Sua solução deverá retornar uma lista de Bool B de tamanho n, de modo que cada Bi será
a informação se Si é igual ou diferente de Ri, para 0 ≤ i < n.
-}    
f5::String->String->[Bool]
f5 _ [] = []
f5 [] _ = []
f5 (x:xs) (y:ys) = (x == y) : f5 xs ys

{-
1- checar sempre os parenteses (principalmente quando envolve tuplas e lista uma dentro da outra)
2- checar sempre o caso base
3- ficar esperto com Bool
-}

f6:: [Int] -> Int
f6 [x] = x
f6 (y:x:xs)
    | y > x = f6 (y:xs)
    | x >= y = f6 (x:xs)