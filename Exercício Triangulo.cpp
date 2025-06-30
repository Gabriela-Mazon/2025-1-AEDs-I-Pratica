/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/main.cc to edit this template
 */

/* 
 * File:   main.cpp
 * Author: 2025.1.08.006
 *
 * Created on 21 de março de 2025, 08:06
 */

#include <cstdlib>
#include <stdio.h>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    // entrada de dados//
    float lado1, lado2, lado3, hip, cat1, cat2;

    printf("\n\t DIgite o primeiro valor:");
    scanf("%f", &lado1);

    printf("\n\t DIgite o segundo valor:");
    scanf("%f", &lado2);

    printf("\n\t DIgite o terceiro valor:");
    scanf("%f", &lado3);


    //Processamento de dados e saída de resultado//

    if (lado1 + lado2 < lado3 || lado1 + lado3 < lado2 || lado2 + lado3 < lado1) {
        printf("\n\tOs valores não formam um triângulo.");
    } else {
        if (lado1 <= 0 || lado2 <= 0 || lado3 <= 0) {
            printf("\n\tOs valores não formam um triângulo.");
        } else {
            
        if (lado1 == lado2 && lado3 == lado1 && lado2 == lado3) {
            printf("\n\tOs valores formam um triângulo equilátero.");
        } else {
            if (lado1 != lado2 && lado1 != lado3 && lado2 != lado3) {
                printf("\n\tOs valores formam um triângulo escaleno.");
            } else {
                printf("\n\tOs valores formam um triângulo isósceles.");
            }

        }
    }
}


return 0;
}

