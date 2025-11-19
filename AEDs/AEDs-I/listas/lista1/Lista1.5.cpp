
#include <cstdlib>
#include <stdio.h>

using namespace std;


int main(int argc, char** argv) {

    float nota;
    
    printf("digite sua nota: ");
    scanf("%f", &nota);
    
    if (nota < 0){
        while (nota < 0 ){
            printf("digite a nota novamete: ");
            scanf("%f", &nota);
        }
    }
    
    if (10 >= nota and nota >= 9){
        printf("\nvocê tirou A");
    } else if(9 > nota and nota >= 7){
        printf("\nvocê tirou B");
    } else if(7 > nota and nota >= 5){
        printf("\nvocê tirou C");
    } else if(5 > nota and nota >= 3){
        printf("\nvocê tirou D");
    } else if(3 > nota and nota >= 0){
        printf("\nvocê tirou F");
    } else {
        printf("\nERRO!!!");
    }
    
    return 0;
}

