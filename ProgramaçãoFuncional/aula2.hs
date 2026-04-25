{-Assunto: Litas
  Os conceitos introdutórios sobre listas foram apresentados em sala.
  Agora, considerando os casos mais simples, com apenas listas de inteiros,
  implemente as funções abaixo, considerando os operadores ++ e :
    ++ (concatena listas)
     : (insere um elemento na lista)
-}
     
{- 01 função que soma os elementos de uma lista -}
sumList::[Int]->Int
sumList [] = 0
sumList (x:xs) = x + sumList(xs)

{- 02-localiza elemento em lista -}
searchList::Int->[Int]->Bool
searchList _ [] = False
searchList x (a:b)
    | x == a = True
    | otherwise = searchList x b

{-03 remove todas ocorrências de y em uma lista -}
deleteList::Int->[Int]->[Int]
deleteList _ [] = []
deleteList x (a:as)
    | x == a = deleteList x as
    |otherwise = a : deleteList x as

{-04 informa o tamanho de uma lista -}
lenghtList::[a]->Int
lenghtList [] = 0
lenghtList (_:as) = lenghtList as + 1

{-05 conta a ocorrência de um Int em [Int] -}
contList::Int->[Int]->Int
contList _ [] = 0
contList x (a:as)
    | x == a = contList x as + 1
    | otherwise = contList x as

{- 06 inverte a lista -}
reverseList:: [a]->[a]
reverseList [] = []
reverseList (a:as) = reverseList as ++ [a]

{- 07 inverte elementos das listas internas -} 
inverteListaInterna:: [[a]] -> [[a]]
inverteListaInterna [] = []
inverteListaInterna (x:xs) = reverseList x : inverteListaInterna xs

{- 08 função que exclui a penúltima ocorrência de um número na lista-}

excluiPenultimo:: [Int] -> Int -> [Int]
excluiPenultimo [] _ = []
excluiPenultimo (x:xs) y
    | x == y && contList y xs == 1  = xs
    | otherwise = x:excluiPenultimo xs y

{- 09 função que exclui o penultimo elemento da lista-}
ePenultimo:: [a] -> [a]
ePenultimo [] = []
ePenultimo [x] = [x]
ePenultimo (x:y:z)
    | length z == 0 = [y]
    |otherwise = x:ePenultimo (y:z)


-------------------------------------------------------------
{- Exercícios
     Implementar as funções: 
       myHead que recebe uma lista x e retorna a cabeça de x
       myTail que recebe uma lista x e retorna a lista x sem a cabeça
       myLast que recebe uma lista x e retorna o último elemento de x
       myInit que recebe uma lista x e retorna a lista x sem o último elemento
-}  

-- Exc 1
myHead:: [a] -> a
myHead (x:xs) = x

--Exc 2
myTail:: [a] -> [a]
myTail (x:xs) = xs

--Exc 3
myLast:: [a] -> a
myLast [x] = x
myLast (_:xs) = myLast xs

--Exc 4
myInit:: [a] -> [a]
myInit [a] = []
myInit (x:xs) = x:myInit xs
 
{- função que gera uma lista de booleanos relativa à comparação entre os elementos e um parâmetro z -} 
gBool :: [Int]->Int-> [Bool]
gBool [] _ = []
gBool (a:x) z = (a>z):gBool x z

{- função que reverte uma lista -}
reverte :: [a] -> [a]
reverte   []  = []
reverte (b:x) = reverte x ++ [b]
     










