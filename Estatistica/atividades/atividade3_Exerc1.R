# Entrada dos dados do problema
criancas <- c(5,1,5,3,1,2,2,1,1,0,
              4,2,0,4,4,4,4,3,3,2,
              1,1,3,2,3,1,2,3,4,3,
              4,0,2,0,5,2,3,4,3,4,
              0,0,4,3,2,2,4,3,4,3)

# Construção da Tabela de Frequência
fi <- table(criancas)               # Frequência Absoluta
fri <- prop.table(fi)               # Frequência Relativa
Fi_acumulada <- cumsum(fi)          # Frequência Absoluta Acumulada
Fri_acumulada <- cumsum(fri)        # Frequência Relativa Acumulada

# Estruturando os dados em um Data Frame organizado
tabela_freq <- data.frame(
  Numero_Criancas = names(fi),
  Freq_Absoluta = as.vector(fi),
  Freq_Rel_Perc = paste0(round(as.vector(fri) * 100, 2), "%"),
  Freq_Abs_Acumulada = as.vector(Fi_acumulada),
  Freq_Rel_Acum_Perc = paste0(round(as.vector(Fri_acumulada) * 100, 2), "%")
)

# Visualizar a tabela no console R
print("Tabela de Distribuição de Frequências:")
print(tabela_freq)

titulo_grafico <- "Distribuição do Número de Crianças por Família\nAluno: Diego Vianna Leite Montemor"

# Construindo o gráfico de barras (ideal para variável quantitativa discreta)
grafico <- barplot(fi,
                   main = titulo_grafico,
                   xlab = "Número de Crianças",
                   ylab = "Frequência Absoluta (Nº de Famílias)",
                   col = "steelblue",
                   ylim = c(0, max(fi) + 2))

# Adicionando os rótulos com os valores exatos em cima de cada barra
text(x = grafico, y = fi + 0.3, labels = fi, font = 2)