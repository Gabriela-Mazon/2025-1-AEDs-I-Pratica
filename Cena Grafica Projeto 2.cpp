/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
  * Matéria: AED's I - Prática
 * Professor: Paulo Bressan 
 * Projeto 2: Calculo de area e volume a partir dos dados do projeto 1.
 * Objetivo: Calcular a área e o volume da cena criada a partir do projeto 1.
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

float PI = 3.14159265358979323846f;


    
    float raizquadrada(float numero) {
    if(numero <= 0) return 0;
    
    // Aproximação inicial (pode ser qualquer valor positivo)
    float resultado = numero / 2;
    
    // Só faz 5 tentativas (suficiente para exercício)
    for(int i = 0; i < 5; i++) {
        resultado = (resultado + numero/resultado) / 2;
    }
    
    return resultado;
}

int main() {
    //leitura do arquivo da cena grafica
    ifstream arquivoEntrada("/home/gabrielamazon/Cena Grafica - Projeto 1/cenagrafica.txt");
    string objeto;
    float areaTotal = 0.0f, volumeTotal = 0.0f;

    if (!arquivoEntrada.is_open()) {
        cout << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
//calculo dos volumes e a
    while (arquivoEntrada >> objeto && objeto != "fim") {
        if (objeto == "quadrado") {
            float lado;
            arquivoEntrada >> lado;
            areaTotal += lado * lado;
        } else if (objeto == "retangulo") {
            float base, altura;
            arquivoEntrada >> base >> altura;
            areaTotal += base * altura;
        } else if (objeto == "triangulo") {
            float base, altura;
            arquivoEntrada >> base >> altura;
            areaTotal += (base * altura) / 2;
        } else if (objeto == "circulo") {
            float raio;
            arquivoEntrada >> raio;
            areaTotal += PI * raio * raio;
        } else if (objeto == "cubo") {
            float lado;
            arquivoEntrada >> lado;
            areaTotal += 6 * lado * lado;
            volumeTotal += lado * lado * lado;
        } else if (objeto == "paralelepipedo") {
            float lado1, lado2, altura;
            arquivoEntrada >> lado1 >> lado2 >> altura;
            areaTotal += 2 * (lado1*lado2 + lado1*altura + lado2*altura);
            volumeTotal += lado1 * lado2 * altura;
        } else if (objeto == "esfera") {
            float raio;
            arquivoEntrada >> raio;
            areaTotal += 4 * PI * raio * raio;
            volumeTotal += (4.0f/3.0f) * PI * raio * raio * raio;
        } else if (objeto == "cilindro") {
            float raio, altura;
            arquivoEntrada >> raio >> altura;
            areaTotal += 2 * PI * raio * (raio + altura);
            volumeTotal += PI * raio * raio * altura;
        } else if (objeto == "cone") {
            float raio, altura;
            arquivoEntrada >> raio >> altura;
            float geratriz = raizquadrada(raio*raio + altura*altura);
            areaTotal += PI * raio * (raio + geratriz);
            volumeTotal += (PI * raio * raio * altura) / 3;
        }
    }

    arquivoEntrada.close();
//saida do resultado da area e do volume
    cout << "Área total da cena: " << areaTotal << endl;
    cout << "Volume total da cena: " << volumeTotal << endl;

    return 0;
}

