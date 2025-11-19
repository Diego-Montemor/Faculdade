#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {

    int altura,i,homens,mulheres,PG,ihomens,imulheres;
    string sexo;
    imulheres = 0;
    ihomens = 0;
    PG = 0;
    ifstream valores("Lista2.10.txt");
    if (not valores.is_open()){
        return 1;
    }
    
    valores >> sexo;
    valores >> altura;
    while (sexo != "0"){
        i = i + 1;        
        if(sexo == "F"){
            if(altura < 170){
              mulheres = mulheres +1;   
            }
           imulheres = imulheres + 1;            
        }
        if(sexo == "M"){
            homens = homens + altura;
            ihomens = ihomens + 1;
        }
        
        if(altura > 180){
            PG = PG +1;
        }
        
        valores >> sexo;
        valores >> altura;
    }
    
    cout << "A porcentagem de pessoas com a altura maior que 1.8m foi de " << (float)PG/i*100 << "%" << endl;
    cout << "A média das alturas de homens foi de " << (float)homens/ihomens/100 << "m" << endl;
    cout << "A porcentagem de mulheres abaixo de 1.7m foi de " << (float)mulheres/imulheres*100 << "%" << endl;
    
    return 0;
}

