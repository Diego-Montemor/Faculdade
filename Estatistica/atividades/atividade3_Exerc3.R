# Carregar os dados (36 observações)
tempos <- c(3.8, 8.5, 3.7, 4.1, 2.9, 3.9, 4.0, 7.9, 7.4,
            9.6, 10.6, 10.7, 11.9, 13.0, 14.0, 8.2, 9.2, 11.6,
            9.9, 12.6, 14.9, 4.7, 4.8, 4.9, 5.1, 5.5, 5.6,
            5.7, 5.9, 6.2, 6.3, 7.3, 6.3, 6.4, 6.8, 6.9)

# Definir os limites das classes (Amplitude de 1.2 começando do valor mínimo 2.9)
# A sequência vai até 14.9 (valor máximo)
limites <- seq(2.9, 14.9, by = 1.2)

# Categorizar os dados nas classes
# right = FALSE garante que o intervalo seja fechado à esquerda e aberto à direita: [a, b)
# include.lowest = TRUE garante que o último valor (14.9) seja incluído na última classe
classes <- cut(tempos, breaks = limites, right = FALSE, include.lowest = TRUE)

# Calcular as Frequências
fi <- table(classes)                           # Frequência Absoluta
fri <- prop.table(fi)                          # Frequência Relativa
Fi_acum <- cumsum(fi)                          # Freq. Absoluta Acumulada
Fri_acum <- cumsum(fri)                        # Freq. Relativa Acumulada

# Montar o Data Frame (Tabela Final)
tabela_frequencias <- data.frame(
  Intervalos = names(fi),
  Fi = as.integer(fi),
  Fri_Perc = sprintf("%.2f%%", fri * 100),
  Fi_Acumulada = as.integer(Fi_acum),
  Fri_Acum_Perc = sprintf("%.2f%%", Fri_acum * 100)
)

# Exibir a tabela no console
print(tabela_frequencias)

# Geração do Histograma e extração dos dados (sem plotar a linha ainda)
hist_dados <- hist(tempos, 
                   main = "Tempo de Convergência do Modelo", 
                   xlab = "Tempo (segundos)", 
                   ylab = "Frequência Absoluta", 
                   col = "lightblue", 
                   border = "black",
                   xlim = c(2, 16))

# Construção do Polígono de Frequência
# O polígono deve começar e terminar no eixo X (frequência 0)
x_poligono <- c(min(hist_dados$breaks), hist_dados$mids, max(hist_dados$breaks))
y_poligono <- c(0, hist_dados$counts, 0)

# Adiciona a linha e os pontos sobre o histograma
lines(x_poligono, y_poligono, col = "red", lwd = 2, type = "b", pch = 16)

# Cálculo de medidas de tendência central para verificar a assimetria
media <- mean(tempos)
mediana <- median(tempos)