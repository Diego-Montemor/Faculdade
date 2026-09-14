# Entrada dos dados do problema
vldl <- c(5.25, 4.56, 6.66, 5.73, 4.00, 6.26, 
          9.57, 9.55, 9.80, 9.65, 9.54, 9.77, 
          7.59, 7.39, 8.46, 7.44, 6.86, 8.12, 
          13.85, 13.60, 15.99, 14.69, 13.23, 14.71, 
          11.06, 10.76, 12.79, 11.59, 10.53, 12.00, 
          17.26, 16.61, 22.00, 18.75, 16.22, 19.40)

# Definição do título
titulo_principal <- "Diego Vianna Leite Montemor"

# Criação do Boxplot
boxplot(vldl, 
        main = titulo_principal,
        ylab = "Fração de VLDL (mg/dL)",
        col = "lightblue",
        border = "darkblue",
        outline = TRUE) # Outline = TRUE permite visualizar os outliers

