/* 
 * File:   LeituraDaCenaGrafica.cpp
 * Author: Diego Vianna Leite Montemor
 * RA:2025.1.08.023
 * Created on 22 de abril de 2025, 09:09
 * 
 * Disciplina AEDs 1 (Pratica)
 * Objetivo: Ler o arquivo "CenaGrafica.txt" criada pelo outro codigo
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
    
    float AreaSuperficial, VolumeTotal;
    string Figura;
    
    ifstream CenaGrafica("CenaGrafica.txt");
    if (not CenaGrafica.is_open()) {
        cout << "O arquivo não foi aberto";
        return 1;
    }
    // Define a area e o volume como 0 para evitar o lixo de memoria no calculo
    AreaSuperficial = 0;
    VolumeTotal = 0;
    
    CenaGrafica >> Figura;
    
    // Verifica e calcula cada objeto presente na Cena Grafica
    while (Figura != "Fim"){
        if (Figura == "Cubo"){
            int Lado;
            CenaGrafica >> Lado;
            AreaSuperficial = AreaSuperficial + ((Lado*Lado)*6);
            VolumeTotal = VolumeTotal + (Lado*Lado*Lado);
        }else if(Figura == "Piramide"){
            float LBase, Altura;
            CenaGrafica >> LBase;
            CenaGrafica >> Altura;
            AreaSuperficial = AreaSuperficial +((LBase*LBase)+ (sqrt((LBase/2*LBase/2)+(Altura*Altura))));
            VolumeTotal = VolumeTotal + ((LBase*LBase*Altura)/3);
        }else if(Figura == "Paralelepipedo"){
            float LBase,HBase, Altura;
            CenaGrafica >> LBase;
            CenaGrafica >> HBase;
            CenaGrafica >> Altura;
            AreaSuperficial = AreaSuperficial + ((LBase*HBase*4)+(HBase*Altura*2));
            VolumeTotal = VolumeTotal + (LBase*HBase*Altura);
        }else if(Figura == "Esfera"){
            float Raio;
            CenaGrafica >> Raio;
            AreaSuperficial = AreaSuperficial + (4*3.14*Raio*Raio);
            VolumeTotal = VolumeTotal + (4/3*3.14*Raio*Raio*Raio);
        }else if(Figura == "Cilindro"){
            float Raio, Altura;
            CenaGrafica >> Raio;
            CenaGrafica >> Altura;
            VolumeTotal = VolumeTotal + (Raio*Raio*3.14*Altura);
            AreaSuperficial = AreaSuperficial + ((2*Raio*3.14*Altura)+(2*Raio*Raio*3.14));
        }else if(Figura == "Prisma"){
            float LBase, HBase, Altura;
            CenaGrafica >> LBase;
            CenaGrafica >> HBase;
            CenaGrafica >> Altura;
            VolumeTotal = VolumeTotal + (LBase*HBase/2*Altura);
            AreaSuperficial = AreaSuperficial + ((2*LBase*HBase/2)+(LBase*Altura*3));
        }else if(Figura == "Quadrado"){
            float Lado;
            CenaGrafica >> Lado;
            AreaSuperficial = AreaSuperficial + (Lado*Lado);
        }else if(Figura == "Triangulo"){
            float LBase, Altura;
            CenaGrafica >> LBase;
            CenaGrafica >> Altura;
            AreaSuperficial = AreaSuperficial + (LBase*Altura/2);
        }else if(Figura == "Circulo"){
            float Raio;
            CenaGrafica >> Raio;
            AreaSuperficial = AreaSuperficial + (Raio*Raio*3.14);
        }else if(Figura == "Retangulo"){
            float Largura, Altura;
            CenaGrafica >> Largura;
            CenaGrafica >> Altura;
            AreaSuperficial = AreaSuperficial + (Largura*Altura);
        }else if(Figura == "Pentagono"){
            float Lado;
            CenaGrafica >> Lado;
            AreaSuperficial = AreaSuperficial + (1.72*Lado*Lado); // 1.72 é a aproximação da formula para calcular a area do Pentagono
        }else if(Figura == "Hexagono"){
            float Lado;
            CenaGrafica >> Lado;
            AreaSuperficial = AreaSuperficial + (2.598*Lado*Lado); //2.598 é a aproximação da formula para calcular a area do Hexagono
        }
        CenaGrafica >> Figura;
    }
    
    // Mostra para o usuario o resultado do volume e da area da Cena Grafica
    cout << "O valor da Area de superficie total foi de " << AreaSuperficial << "m²" << endl;
    cout << "O valor do volume total foi de " << VolumeTotal << "m³" << endl;
    
    return 0;
}

