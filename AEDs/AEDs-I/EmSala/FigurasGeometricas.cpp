#include <cstdlib>
#include <fstream>
#include <iostream>

using namespace std;

/*Objetivo: calcular o volume de um arquivo .txt de uma "cenagrafica" no seguinte formato:

FiguraValida respectivaDimensao
...
Fim

Exemplo:
    Cubo 3
    Esfera 4
    Cilindro 5 10
    Paralelepipedo 2 3 4
    Triangulo 3 4 5
    Fim

*/


int main(int argc, char** argv) {
    string figura;
    float areatotal = 0, volumepiramide = 0, volumeparalelepipedo = 0, volumecilindro = 0, volumeesfera = 0, volumecubo = 0;

    ifstream valores("CenaGrafica.txt");
    if (not valores.is_open()){
        cout << "\n\tERRO: O arquivo não foi aberto\n";
        return 1;
    }
    
    valores >> figura;
    // lê o arquivo lendo cada figura e suas dimensões até encontrar "Fim" e calcula o volume de cada figura
    while (figura != "Fim"){
        if (figura == "Cubo"){
            int lado;
            valores >> lado;
            volumecubo = volumecubo + (lado*lado*lado);
        }else if(figura == "Triangulo"){
            int lado1,lado2,lado3;           
            valores >> lado1;
            valores >> lado2;
            valores >> lado3;
            volumepiramide = volumepiramide + ((lado1*lado2/2)*lado3/3);
        }else if(figura == "Paralelepipedo"){
            int lado1,lado2,lado3;
            valores >> lado1;
            valores >> lado2;
            valores >> lado3;
            volumeparalelepipedo = volumeparalelepipedo + (lado1*lado2*lado3);
        }else if(figura == "Cilindro"){
            int raio, altura;        
            valores >> raio;
            valores >> altura;
            volumecilindro = volumecilindro + ((raio*raio*3.14)*altura);
        }else if(figura == "Esfera"){
            int raio;    
            valores >> raio;
            volumeesfera = volumeesfera + (4/3*3.14*raio*raio*raio);
        }
        valores >> figura;
    }
    valores.close();
    // calcula o volume total somando os volumes de cada figura e exibe o resultado
    areatotal = (volumecubo + volumepiramide + volumeparalelepipedo + volumecilindro + volumeesfera);
    cout << "O volume total é de " << areatotal << "m³" << endl;    
    
    return 0;
}

