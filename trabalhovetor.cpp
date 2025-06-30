/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/*
 * Aluna: Gabriela Mazon Rabello de Souza
 * R.A.:2025.1.08.006
 * AED’s I – Prática
 * Professor: Paulo Alexandre Bressan
 * Objetivo: Realizar operações nos valores armazenados em um vetor
 * Descrição: criar um projeto que insira valores inteiros num vetor de
100 posições e apresente um menu de operações que podem ser realizadas no
vetor quantas vezes o usuário desejar.
 */
#include <iostream>
#include <cstdlib>
using namespace std;
const int TAM = 100;

int main() {
    int vetor[TAM];
    int valormin, valormax;
    int choice = 0;
    int valor, posivalor, contvalor;
    int intervalomenor, intervalomaior, contigual;
    int i, j;

    // Configuração inicial
    cout << "Digite o menor valor para o vetor: ";
    cin >> valormin;
    cout << "Digite o maior valor para o vetor: ";
    cin >> valormax;

    // Validação do intervalo
    while (valormin > valormax) {
        cout << "Valor mínimo maior que o máximo! Redigite:\n";
        cout << "Menor valor: ";
        cin >> valormin;
        cout << "Maior valor: ";
        cin >> valormax;
    }

    // Preenchimento inicial do vetor
    for (i = 0; i < TAM; i++) {
        vetor[i] = rand() % (valormax - valormin + 1) + valormin;
    }

    // Menu principal
    while (true) {
        cout << "\n=== MENU ===\n"
                << "1. Contar ocorrências de um valor\n"
                << "2. Contar valores em intervalo\n"
                << "3. Buscar primeira ocorrência\n"
                << "4. Excluir primeira ocorrência\n"
                << "5. Inserir valor em posição\n"
                << "6. Remover valores repetidos\n"
                << "0. Sair\n"
                << "Escolha: ";
        cin >> choice;

        switch (choice) {

                // Contar ocorrências  
            case 1:
                cout << "Digite o valor: ";
                cin >> valor;
                contvalor = 0;
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] == valor) contvalor++;
                }
                cout << "O valor aparece " << contvalor << " vezes\n";
                break;

                // Contar em intervalo
            case 2:
                cout << "Limite inferior: ";
                cin >> intervalomenor;
                cout << "Limite superior: ";
                cin >> intervalomaior;
                contigual = 0;
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] >= intervalomenor && vetor[i] <=
                            intervalomaior) contigual++;
                }
                cout << "Existem " << contigual << " valores no intervalo\n";
                break;

                // Buscar primeira ocorrência
            case 3:
                cout << "Digite o valor: ";
                cin >> valor;
                posivalor = -1;
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] == valor) {
                        posivalor = i;
                        break;
                    }
                }
                if (posivalor == -1) {
                    cout << "Valor não encontrado\n";
                } else {
                    cout << "Encontrado na posição " << posivalor + 1 <<
                            "\n";
                }
                break;

                // Excluir primeira ocorrência
            case 4:
                cout << "Digite o valor: ";
                cin >> valor;
                posivalor = -1;
                for (i = 0; i < TAM; i++) {
                    if (vetor[i] == valor) {
                        posivalor = i;
                        break;
                    }
                }
                if (posivalor != -1) {
                    for (j = posivalor; j < TAM - 1; j++) {
                        vetor[j] = vetor[j + 1];
                    }
                    vetor[TAM - 1] = rand() % (valormax - valormin + 1) +
                            valormin;
                    cout << "Valor removido\n";
                } else {
                    cout << "Valor não encontrado\n";
                }
                break;

                // Inserir valor
            case 5:
                cout << "Digite o valor: ";
                cin >> valor;
                cout << "Digite a posição (1-" << TAM << "): ";
                cin >> posivalor;
                posivalor--;

                if (posivalor >= 0 && posivalor < TAM) {
                    for (i = TAM - 1; i > posivalor; i--) {
                        vetor[i] = vetor[i - 1];
                    }
                    vetor[posivalor] = valor;
                    cout << "Valor inserido\n";
                } else {
                    cout << "Posição inválida\n";
                }
                break;

                // Remover repetidos
            case 6:
                for (i = 0; i < TAM; i++) {
                    for (j = i + 1; j < TAM; j++) {
                        if (vetor[i] == vetor[j]) {
                            vetor[j] = valormax + 1;
                        }
                    }
                }
                cout << "Repetidos marcados para remoção\n";
                break;


                // Sair     
            case 0:
                return 0;

            default:
                cout << "Opção inválida!\n";
        }
    }
    return 0;
}
