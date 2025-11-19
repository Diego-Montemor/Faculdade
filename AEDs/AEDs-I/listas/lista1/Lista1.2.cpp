/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: monte
 *
 * Created on 20 de março de 2025, 08:41
 */

#include <cstdlib>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
    
    int idade;
    
    printf("Digite sua idade: ");
    scanf("%d", &idade);
    
    if (idade >= 18){
        printf("você é adulto");
    } else if(18 > idade >= 13){
        printf("você é adolescente");
    } else{
        printf("você é criança");
    }
    
    return 0;
}

