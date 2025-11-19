/* 
 * File:   CriaçãoDeUmaCenaGrafica.cpp
 * Author: Diego Vianna Leite Montemor
 * RA: 2025.1.08.023
 * Created on 22 de abril de 2025, 09:03
 * 
 * Disciplina: AEDs 1 (Pratica)
 * Objetivo: Criar de um arquivo .txt contendo objetos 2D e 3D de uma cena grafica
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {

    ofstream CenaGrafica("CenaGrafica.txt");
    if (not CenaGrafica.is_open()) {
        return 1;
    }
    int opcao;
    opcao = 0;
    cout << "Digite o valor referente a geometria que deseja usar na sua cena?" << endl; // Criação do menu de escolha
    cout << "Obijetos 3D\n(1).Cubo\t(2).Piramide\t(3).Paralelepipedo\n(4).Esfera\t(5).Cilindro\t(6).Prisma\nObjetos 2D\n(7).Quadrado\t(8).Triangulo\t(9).circulo\n(10).retangulo\t(11).pentagono\t(12).hexagono\n(0).Fim" << endl;
    cin >> opcao;

    string Figura;
    
    //(pesquisei por conta propria) verifica se a entrada do usuario é uma opção valida e evita a quebrar o codigo pelo usuario digitar uma letra ao inves de um numero.
   while (cin.fail() or (0 > opcao or opcao > 12)) {
        cin.clear(); // limpa o cin em caso de erro
        cin.ignore(1000, '\n'); // descarta a entrada inválida
        cout << "Valor inválido!" << endl;
        cout << "Digite um numero de uma opção valida: ";
        cin >> opcao; // pede para o usuario entrar com um valor valido
    }
   
    
    // verifica a entrada o usuario e assimila com um objeto
    if (opcao == 1) {
        Figura = "Cubo";
    } else if (opcao == 2) {
        Figura = "Piramide";
    } else if (opcao == 3) {
        Figura = "Paralelepipedo";
    } else if (opcao == 4) {
        Figura = "Esfera";
    } else if (opcao == 5) {
        Figura = "Cilindro";
    } else if (opcao == 6) {
        Figura = "Prisma";
    } else if (opcao == 7) {
        Figura = "Quadrado";
    } else if (opcao == 8) {
        Figura = "Triangulo";
    } else if (opcao == 9) {
        Figura = "Circulo";
    } else if (opcao == 10) {
        Figura = "Retangulo";
    } else if (opcao == 11) {
        Figura = "Pentagono";
    } else if (opcao == 12) {
        Figura = "Hexagono";
    } else if (opcao == 0) {
        Figura = "Fim";
    }
    
    // Verifica qual a figura escolhida e pede suas dimensões
    while (Figura != "Fim") {
        // quebrei em 2 essa verificação para poupar processamento e separar as figuras 2D e 3D
        if (opcao <= 6) { // Pega as informações das figuras 3D
            if (Figura == "Cubo") {
                float lado; // usei o float para permitir a entrada de numeros com virgula
                cout << "Digite o valor dos lados do cubo: ";
                cin >> lado;
                CenaGrafica << Figura << "\t\t" << lado << endl;
            } else if (Figura == "Piramide") {
                float LBase, Altura;
                cout << "Digite o valor para os lados da base: ";
                cin >> LBase;
                cout << "Digite o valor da altura da piramide: ";
                cin >> Altura;
                CenaGrafica << Figura << "\t" << LBase << "\t" << Altura << endl;
            } else if (Figura == "Paralelepipedo") {
                float lado1, lado2, Altura;
                cout << "Digite o valor para o largura da base: ";
                cin >> lado1;
                cout << "Digite o valor para o altura da base: ";
                cin >> lado2;
                cout << "digite o valor da altura do paralelepípedo: ";
                cin >> Altura;
                CenaGrafica << Figura << "\t" << lado1 << "\t" << lado2 << "\t" << Altura << endl;
            } else if (Figura == "Esfera") {
                float raio;
                cout << "Digite o valor para o raio da esfera: ";
                cin >> raio;
                CenaGrafica << Figura << "\t\t" << raio << endl;
            } else if (Figura == "Cilindro") {
                float raio, Altura;
                cout << "Digite o valor do raio da base: ";
                cin >> raio;
                cout << "Digite o valor da altura do cilindro: ";
                cin >> Altura;
                CenaGrafica << Figura << "\t" << raio << "\t" << Altura << endl;
            } else if (Figura == "Prisma") {
                float Largura, HBase, Altura;
                cout << "Digite o valor da largura da base: ";
                cin >> Largura;
                cout << "Digite o valor da altura do triângulo da base: ";
                cin >> HBase;
                cout << "Digite o valor para a altura do prisma: ";
                cin >> Altura;
                CenaGrafica << Figura << "\t\t" << Largura << "\t" << HBase << "\t" << Altura << endl;
            }
        } else { // pega as informações das figuras 2D
            if (Figura == "Quadrado") {
                float Lado;
                cout << "Digite o tamanho dos lados do quadrado: ";
                cin >> Lado;
                CenaGrafica << Figura << "\t" << Lado << endl;
            } else if (Figura == "Triangulo") {
                float Largura, Altura;
                cout << "Digite o tamanho da largura da base do triângulo: ";
                cin >> Largura;
                cout << "Digite o tamanho da altura do triângulo: ";
                cin >> Altura;
                CenaGrafica << Figura << "\t" << Largura << "\t" << Altura << endl;
            } else if (Figura == "Circulo") {
                float Raio;
                cout << "Digite o valor do raio do circulo: ";
                cin >> Raio;
                CenaGrafica << Figura << "\t\t" << Raio << endl;
            } else if (Figura == "Retangulo") {
                float Largura, Altura;
                cout << "Digite o tamanho da largura do retângulo: ";
                cin >> Largura;
                cout << "Digite o tamanho da altura do retângulo: ";
                cin >> Altura;
                CenaGrafica << Figura << "\t" << Largura << "\t" << Altura << endl;
            } else if (Figura == "Pentagono") {
                float Lado;
                cout << "Digite o tamanho dos lados do pentágono: ";
                cin >> Lado;
                CenaGrafica << Figura << "\t" << Lado << endl;
            } else if (Figura == "Hexagono") {
                float Lado;
                cout << "Digite o tamanho dos lados do hexágono: ";
                cin >> Lado;
                CenaGrafica << Figura << "\t" << Lado << endl;
            }
        }
        
        // Pergunta ao usuario oq deseja novamente 
        cout << "Digite o valor referente a geometria que deseja usar na sua cena." << endl;
        cout << "Obijetos 3D\n(1).Cubo\t(2).Piramide\t(3).Paralelepipedo\n(4).Esfera\t(5).Cilindro\t(6).Prisma\nObjetos 2D\n(7).Quadrado\t(8).Trriangulo\t(9).circulo\n(10).retangulo\t(11).pentagono\t(12).hexagono\n(0).Fim" << endl;
        cin >> opcao;

        while (cin.fail() or (0 > opcao or opcao > 12)) {
            cin.clear(); // limpa o estado de erro
            cin.ignore(1000, '\n'); // descarta a entrada inválida
            cout << "Entrada inválida!" << endl;
            cout << "Digite um numero de uma opção valida: ";
            cin >> opcao;
        }
        if (opcao == 1) {
            Figura = "Cubo";
        } else if (opcao == 2) {
            Figura = "Piramide";
        } else if (opcao == 3) {
            Figura = "Paralelepipedo";
        } else if (opcao == 4) {
            Figura = "Esfera";
        } else if (opcao == 5) {
            Figura = "Cilindro";
        } else if (opcao == 6) {
            Figura = "Prisma";
        } else if (opcao == 7) {
            Figura = "Quadrado";
        } else if (opcao == 8) {
            Figura = "Triangulo";
        } else if (opcao == 9) {
            Figura = "Circulo";
        } else if (opcao == 10) {
            Figura = "Retangulo";
        } else if (opcao == 11) {
            Figura = "Pentagono";
        } else if (opcao == 12) {
            Figura = "Hexagono";
        } else if (opcao == 0) {
            Figura = "Fim";
        }
    }
        
    CenaGrafica << Figura; // Coloca o "Fim" no final do arquivo
    CenaGrafica.close(); // Fecha o arquivo
    cout << "\nLista feita com sucesso";
    return 0;
}
