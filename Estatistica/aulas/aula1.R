# -[ Exemplo 1 ]- #

N = 500
n = 20
sample(N,n)

# -[ Exemplo 2 ]- #

TE = c(300,200,100) 			# vetor para controle de quant de cada população (extratos)
N = 600			# tamanho total da população
n = 30			# tamanho da damostra
ni = n/N*TE; ni			# calcula o tamanho de cada grupo
ni2 = round(ni,0); ni2			# cria um novo vetor com base no vetor ni para arredondando para pegar só numeros inteiros

# amostragem simples em cada estagio

sample(TE[1],ni2[1])
sample(TE[2],ni2[2])
sample(TE[3],ni2[3])

# -[ Exemplo 3 ]- #

N = 1000				# tamanho da população
n = 50				# tamanho da amostra
r = round(N/n,0)				# salto de amostragem r
r

sort_elem1 = sample(r,1)				# sorteando o 1° elemento entre 1 e r
sort_elem1

posicao = seq(sort_elem1,N,r);		# Posição de todos os elementos da amostra
posicao












