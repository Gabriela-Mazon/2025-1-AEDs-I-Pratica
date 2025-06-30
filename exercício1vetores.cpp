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
 * 1. Crie um vetor com 20 números inteiros e coloque em um outro vetor os números sem repetição
 * 2. Crie um outro vetor e coloque os valres do vetor sem repetição de forma ordenada
 */
int main(int argc, char** argv) {

    int vet[20],unico[20],ordenado[20],tam=0,n,i,j;
    
    cout<<"Quantos valores você quer digitar?(Máximo de 20 valores)\n";
    cin>>n;
    
    if (n>20){
        cout<<"Erro, não são aceitos mais de 20 números.\n";
        return 1;
    }
    cout<<"Digite 20 números inteiros(podem ser repetidos):\n";
 
        for(int i=0;i<n;i++){
        cin>>vet[i];
    }

    //remove os valores repetidos
    for (int i=0;i<n;i++){
        int repetido=0;
        for(j=0;j<tam;j++){
            if(vet[i]==unico[j]){
                repetido=1;
                break;
                        
            }
        }
        if(repetido==0){
            unico[tam]=vet[i];
                    tam++;
        }
    }

    //copia dos valores unicos para o vetor ordenado
    for(i=0;i<tam;i++){
        ordenado[i]=unico[i];
    }

    //Ordena o vetor ordenado (bubble sort)
    for(i=0;i<tam-1;i++){
        for(j=i+1;j<tam;j++){
            if(ordenado[i]>ordenado[j]){
                int temp=ordenado[i];
                ordenado[i]=ordenado[j];
                ordenado[j]=temp;
            }
        }
    }
    cout<<"Valores únicos:";
    for(i=0;i<tam;i++){
        cout<<unico[i]<<" ";
    }
    cout<<"\n Valores únicos ordenados: ";
    for(i=0;i<tam;i++){
        cout<<ordenado[i]<<" ";
    }
    return 0;
}

