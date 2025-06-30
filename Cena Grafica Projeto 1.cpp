/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
Matéria: AED's I - Prática
 * Professor: Paulo Bressan 
 * Programa 1: Gerador de Cena Gráfica
 * Objetivo: Permitir ao usuário descrever figuras geométricas e salvar em arquivo.
 * Autor: Gabriela Mazon Rabello de Souza
 * R.A:2025.1.08.006
 * Data: 22/04/2025
 * Local: Alfenas
 * 
 */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream arquivoSaida("cenagrafica.txt");
    string objeto;
    int continuar = 1; // 1 para verdadeiro, 0 para falso

    if (!arquivoSaida.is_open()) {
        cout << "Erro ao criar o arquivo!" << endl;
        return 1;
    }

    cout << "Digite as figuras da cena gráfica (digite 'fim' para encerrar):" << endl;

    while (continuar) {
        cout << "Tipo de objeto (quadrado, retangulo, triangulo, cubo, esfera, etc.): ";
        cin >> objeto;

        if (objeto == "fim") {
            arquivoSaida << "fim" << endl;
            continuar = 0;
        } else {
            arquivoSaida << objeto << " ";

            if (objeto == "quadrado") {
                float lado;
                cout << "Lado do quadrado: ";
                cin >> lado;
                arquivoSaida << lado;
            } else if (objeto == "retangulo") {
                float base, altura;
                cout << "Base e altura do retângulo: ";
                cin >> base >> altura;
                arquivoSaida << base << " " << altura;
            } else if (objeto == "triangulo") {
                float base, altura;
                cout << "Base e altura do triângulo: ";
                cin >> base >> altura;
                arquivoSaida << base << " " << altura;
            } else if (objeto == "circulo") {
                float raio;
                cout << "Raio do círculo: ";
                cin >> raio;
                arquivoSaida << raio;
            } else if (objeto == "cubo") {
                float lado;
                cout << "Lado do cubo: ";
                cin >> lado;
                arquivoSaida << lado;
            } else if (objeto == "paralelepipedo") {
                float lado1, lado2, altura;
                cout << "Lado1, lado2 e altura do paralelepípedo: ";
                cin >> lado1 >> lado2 >> altura;
                arquivoSaida << lado1 << " " << lado2 << " " << altura;
            } else if (objeto == "esfera") {
                float raio;
                cout << "Raio da esfera: ";
                cin >> raio;
                arquivoSaida << raio;
            } else if (objeto == "cilindro") {
                float raio, altura;
                cout << "Raio e altura do cilindro: ";
                cin >> raio >> altura;
                arquivoSaida << raio << " " << altura;
            } else if (objeto == "cone") {
                float raio, altura;
                cout << "Raio e altura do cone: ";
                cin >> raio >> altura;
                arquivoSaida << raio << " " << altura;
            } else {
                cout << "Objeto não reconhecido!" << endl;
                continue;
            }

            arquivoSaida << endl;
        }
    }

    arquivoSaida.close();
    cout << "Cena gráfica salva em 'cenagrafica.txt'" << endl;

    return 0;
}
