# Dicionário de funções em R
# Arquivo apenas para consulta e anotações, não para execução.

# Resumo rápido:
# c() = vetor
# table() = frequência
# prop.table() = proporção
# mean() = média
# median() = mediana
# barplot() = gráfico de barras
# hist() = histograma
# boxplot() = boxplot
# cut() = classes de intervalo

c()
# o que faz: Cria um vetor com valores informados
# Exemplo: c(1, 2, 3, 4)
# Saída: [1] 1 2 3 4

seq()
# o que faz: Cria uma sequência numérica com intervalo definido
# Exemplo: seq(0, 10, by = 2)
# Saída: [1] 0 2 4 6 8 10

data.frame()
# o que faz: Cria uma tabela com colunas e linhas
# Exemplo: data.frame(Aluno = c("A", "B"), Nota = c(8, 9))
# Saída: uma tabela com duas colunas: Aluno e Nota

names()
# o que faz: Obtém ou define os nomes dos elementos de um objeto
# Exemplo: names(vetor) <- c("x", "y", "z")
# Saída: nomes atribuídos ao vetor, como x, y, z

as.vector()
# o que faz: Converte um objeto para vetor
# Exemplo: as.vector(table(dados))
# Saída: vetor com os valores contados pela tabela

as.integer()
# o que faz: Converte valores para inteiros
# Exemplo: as.integer(c(1.2, 3.7, 4.9))
# Saída: [1] 1 3 4

paste0()
# o que faz: Junta textos e valores sem separador
# Exemplo: paste0(50, "%")
# Saída: [1] "50%"

sprintf()
# o que faz: Formata valores com precisão específica
# Exemplo: sprintf("%.2f%%", 12.345)
# Saída: [1] "12.35%"

table()
# o que faz: Conta a frequência de cada valor ou categoria
# Exemplo: table(dados)
# Saída: uma tabela com contagem dos valores, por exemplo: 1 2 3

prop.table()
# o que faz: Calcula a proporção de cada frequência
# Exemplo: prop.table(table(dados))
# Saída: valores em porcentagem/ proporção, por exemplo: 0.25 0.50 0.25

sum()
# o que faz: Soma todos os valores de um vetor ou coluna
# Exemplo: sum(dados, na.rm = TRUE)
# Saída: valor numérico total, por exemplo: 30
# Extras: na.rm = TRUE/FALSE -> ignora ou não valores ausentes (NA)

cumsum()
# o que faz: Calcula a soma acumulada dos valores
# Exemplo: cumsum(c(2, 4, 6))
# Saída: [1] 2 6 12
# Extras: nenhum parâmetro extra obrigatório; normalmente recebe vetores numéricos

cut()
# o que faz: Divide dados em intervalos ou classes
# Exemplo: cut(dados, breaks = seq(0, 10, by = 2))
# Saída: fatores representando intervalos, como [0,2), [2,4)
# Extras: breaks = seq(...), labels = TRUE/FALSE, include.lowest = TRUE/FALSE, right = TRUE/FALSE
# labels = FALSE mostra apenas os intervalos; include.lowest = TRUE inclui o menor valor do intervalo

mean()
# o que faz: Calcula a média aritmética
# Exemplo: mean(dados, na.rm = TRUE)
# Saída: valor numérico, por exemplo: 5.8
# Extras: na.rm = TRUE/FALSE -> ignora valores ausentes antes de calcular

median()
# o que faz: Calcula a mediana dos dados
# Exemplo: median(dados, na.rm = TRUE)
# Saída: valor central, por exemplo: 6
# Extras: na.rm = TRUE/FALSE -> ignora NA no cálculo

max()
# o que faz: Retorna o maior valor do vetor
# Exemplo: max(dados, na.rm = TRUE)
# Saída: maior número do vetor
# Extras: na.rm = TRUE/FALSE -> ignora valores ausentes

min()
# o que faz: Retorna o menor valor do vetor
# Exemplo: min(dados, na.rm = TRUE)
# Saída: menor número do vetor
# Extras: na.rm = TRUE/FALSE -> ignora valores ausentes

barplot()
# o que faz: Cria um gráfico de barras
# Exemplo: barplot(table(dados), col = "steelblue", main = "Frequência", xlab = "Categorias", ylab = "Quantidade")
# Gera: um gráfico de barras mostrando a frequência de cada categoria
# Extras: col = "cor", main = "título", xlab = "texto", ylab = "texto", names.arg = c("A", "B"), beside = TRUE/FALSE
# beside = FALSE empilha as barras; TRUE coloca barras lado a lado

text()
# o que faz: Adiciona textos em um gráfico
# Exemplo: text(x, y, labels = valor, col = "black", cex = 1.2)
# Saída: texto visível no gráfico, como rótulos sobre barras
# Extras: labels = valor, col = "cor", cex = tamanho, pos = 1,2,3,4 para posição do texto

hist()
# o que faz: Cria um histograma para visualizar a distribuição dos dados
# Exemplo: hist(dados, breaks = 10, col = "lightblue", border = "white")
# Gera: um histograma com barras de frequência por intervalo
# Extras: breaks = número ou vetor, col = "cor", border = "cor", main = "título", xlab = "eixo x", ylab = "eixo y", freq = TRUE/FALSE
# freq = FALSE mostra densidade em vez de frequência

lines()
# o que faz: Desenha linhas em um gráfico já existente
# Exemplo: lines(x, y, col = "red", lwd = 2)
# Gera: uma linha sobre o gráfico, como um polígono ou curva
# Extras: col = "cor", lwd = espessura, lty = tipo da linha, pch = tipo do ponto

boxplot()
# o que faz: Cria um boxplot para mostrar mediana, quartis e outliers
# Exemplo: boxplot(dados, col = "lightblue", outline = TRUE, main = "Boxplot", ylab = "Valores")
# Gera: um diagrama de caixa com mediana e possíveis valores extremos
# Extras: col = "cor", border = "cor", horizontal = TRUE/FALSE, outline = TRUE/FALSE, main = "título", xlab = "texto", ylab = "texto"
# outline = FALSE oculta os outliers; outline = TRUE mostra os outliers no gráfico

print()
# o que faz: Exibe um objeto ou mensagem no console
# Exemplo: print("Tabela de frequência")
# Saída: "Tabela de frequência"

round()
# o que faz: Arredonda um número para uma quantidade de casas decimais
# Exemplo: round(3.14159, 2)
# Saída: [1] 3.14
# Extras: digits = número de casas decimais; muda a precisão do resultado


