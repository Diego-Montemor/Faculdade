
Dataset <- readXL("C:/Users/monte/Downloads/Dados_caso_implanta_Empresa_TI.xlsx", rownames=FALSE, header=TRUE, 
  na="", sheet="Plan1", stringsAsFactors=TRUE)
library(abind, pos=16)
library(e1071, pos=17)
numSummary(Dataset[,"vvpa", drop=FALSE], statistics=c("mean", "sd", "se(mean)", "var", "IQR", "quantiles", "cv"), quantiles=c(0,.25,.5,.75,1))
binnedCounts(Dataset[,"vvpa", drop=FALSE])

Boxplot( ~ vvpa, data=Dataset, id=list(method="y"))
