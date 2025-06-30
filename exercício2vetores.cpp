/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.006
 *
 * Created on 22 de maio de 2025, 08:20
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/* exercícios 22/05
 * 3. Crie um outro vetor de números não repetidos para as operações abaixo
 * 4. Crie um vetor com o resultado da operação de união dos vetores sem repetição
 * 5. Idem para a operação de intersecção
 */

int main() {
    int vet1[20], vet2[20];
    int unicos1[20], unicos2[20];
    int n1, n2, t1 = 0, t2 = 0;
    int uniao[40], intersec[20];
    int tu = 0, ti = 0;
    int i, j, temp;

    // Leitura vetor 1
    cout << "Quantos números no vetor 1? (máx 20): ";
    cin >> n1;
     cout << endl;
    if (n1 > 20) {
        cout << "Erro: máximo 20 números!\n";
        return 1;
    }
    cout << "Digite os " << n1 << " números do vetor 1:\n";
    for (i = 0; i < n1; i++) cin >> vet1[i];
     cout << endl;

    // Leitura vetor 2
    cout << "Quantos números no vetor 2? (máx 20): ";
    cin >> n2;
     cout << endl;
    if (n2 > 20) {
        cout << "Erro: máximo 20 números!\n";
        return 1;
    }
    cout << "Digite os " << n2 << " números do vetor 2:\n";
    for (i = 0; i < n2; i++) cin >> vet2[i];
 cout << endl;
 
    // Ordenar vet1
    for (i = 0; i < n1 - 1; i++)
        for (j = i + 1; j < n1; j++)
            if (vet1[i] > vet1[j]) {
                temp = vet1[i];
                vet1[i] = vet1[j];
                vet1[j] = temp;
            }

    // Ordenar vet2
    for (i = 0; i < n2 - 1; i++)
        for (j = i + 1; j < n2; j++)
            if (vet2[i] > vet2[j]) {
                temp = vet2[i];
                vet2[i] = vet2[j];
                vet2[j] = temp;
            }

    // Remover repetidos vet1
    for (i = 0; i < n1; i++) {
        int rep = 0;
        for (j = 0; j < t1; j++)
            if (vet1[i] == unicos1[j]) rep = 1;
        if (!rep) unicos1[t1++] = vet1[i];
    }

    // Remover repetidos vet2
    for (i = 0; i < n2; i++) {
        int rep = 0;
        for (j = 0; j < t2; j++)
            if (vet2[i] == unicos2[j]) rep = 1;
        if (!rep) unicos2[t2++] = vet2[i];
    }

    // União
    for (i = 0; i < t1; i++) uniao[tu++] = unicos1[i];
    for (i = 0; i < t2; i++) {
        int rep = 0;
        for (j = 0; j < tu; j++)
            if (unicos2[i] == uniao[j]) rep = 1;
        if (!rep) uniao[tu++] = unicos2[i];
    }

    // Intersecção
    for (i = 0; i < t1; i++) {
        for (j = 0; j < t2; j++) {
            if (unicos1[i] == unicos2[j]) {
                int rep = 0;
                for (int k = 0; k < ti; k++)
                    if (intersec[k] == unicos1[i]) rep = 1;
                if (!rep) intersec[ti++] = unicos1[i];
            }
        }
    }

    // Mostrar vetores
    cout << "\nVetor 1 (sem repetidos): ";
    for (i = 0; i < t1; i++) cout << unicos1[i] << " ";
    cout<<endl;

    cout << "\nVetor 2 (sem repetidos): ";
    for (i = 0; i < t2; i++) cout << unicos2[i] << " ";
    cout<<endl;

    cout << "\n\nUnião dos vetores: ";
    for (i = 0; i < tu; i++) cout << uniao[i] << " ";
     cout<<endl;


    cout << "\nIntersecção dos vetores: ";
    for (i = 0; i < ti; i++) cout << intersec[i] << " ";
    cout << endl;
     cout << endl;
    return 0;
}

