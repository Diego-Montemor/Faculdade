#include <cstdlib>
#include <iostream>

using namespace std;
// objetivo: Excluir a primeira ocorrência de um valor em um vetor
int main(int argc, char** argv) {
    int quant = 0, dif = 0;
    // VetorRep: vetor original com possíveis repetições
    // VetorSemRep: vetor para armazenar valores sem repetição
    int VetorRep[20] = {4, 9, 1, 7, 0, 6, 10, 3, 2, 8, 5, 0, 9, 4, 1, 6, 7, 3, 2, 10}, VetorSemRep[quant];
    
    // Exibe o vetor original
    for(int i = 0; i< 20 ; i++){
        cout << VetorRep[i] << " ";
    }
    cout << endl;
    
    // Percorre o vetor original para eliminar repetições
    for(int i = 0 ; i < 20 ; i++){
        for(int j = 0 ; j < 20; j++ ){
            // Verifica se o elemento já está no vetor sem repetição
            if(VetorRep[i] != VetorSemRep[j]){
                quant++;
                dif = 1;                
            }
        }
        // Se não encontrou repetição, adiciona ao vetor sem repetição
        if(dif == 1){
            VetorSemRep[quant] = VetorRep[i];
            dif = 0;
        }
    }
    
    // Exibe o vetor sem repetições
    for(int i = 0; i< quant ; i++){
        cout << VetorSemRep[i] << " ";
    }
    
    
    return 0;
}