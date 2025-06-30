#include <stdio.h>
int main(int argc, char** argv) {
     /* Local: Alfenas
     Data: 22/03/2025
     Autor: Gabriela Mazon Rabello de Souza
     Número de matrícula: 2025.1.08.006
     Disciplina: AEDs I Prática
     Objetivo: Criar um programa que avalie a possibilidade de empréstimo.
     Trabalho 01 - Sistema de Aprovação de Empréstimo
     Professor: Paulo Alexandre Bressan
     */
   
     // Declaração das variáveis//
       
        float renda;
        int idade,historico,atraso_atual, atraso2;
   
        // entrada de dados//
   
        printf ("\n\t Sistema de Aprovação de empréstimo.");
       
        printf("\n\t Digite a sua idade:");
        scanf("%d", &idade);
   
        printf("\n\t Digite sua renda mensal:");
        scanf("%f", &renda);
   
        printf("\n\t Digite o histórico de crédito (caso o nome esteja negativado digite 1, caso contrário digite 0):");
        scanf("%d", &historico);


        printf("\n\t Digite o numero de parcelas em atraso atualmente:");
        scanf("%d", &atraso_atual);


        printf("\n\t Digite o numero de parcelas em atraso nos ultimos dois anos:");
        scanf("%d", &atraso2);
   
        //Validação de entradas//
   if (idade <0 || (historico != 0 && historico != 1) || atraso_atual < 0 || atraso2 < 0 || renda < 0){
    printf("\nValores inválidos inseridos!");
    //Código para informar qual entrada é inválido//
    if(idade<0){
printf("\nO valor %d para idade do solicitante é inválido",idade);
    }
    if(renda<0){
        printf("\nO valor %.2f para renda do solicitante é inválido",renda);
    }
    if(historico !=0 && historico !=1){
        printf("\nO valor %d para a opção de histórico de crédito do solicitante é inválido.\nDigite 0 para 'Não' e 1 para 'Sim'",historico);
    }
    if(atraso_atual < 0){
        printf("\nO valor %d para a quantidade de parcelas em atraso atualmente é inválido",atraso_atual);
    }
    if(atraso2 < 0){
        printf("\nO valor %d para a quantidade de parcelas em atraso nos últimos 2 anos é inválido",atraso2);
    }
} else {
    // Processamento e saída de dados quando forem válidos//
   
   
    if (renda<2000 || historico ==1|| idade<18|| idade>70) {
    printf ("\n\t Seu empréstimo foi negado!");
        } else {
            if (renda>=2000 && renda<=4999.99 && atraso_atual<=2) {
        printf ("\n\t Empréstimo de baixo valor (até R$5000.00).");
    } else {
        if (renda>=5000 && renda<=9999.99 && atraso2<=4 && atraso_atual == 0){
            printf ("\n\t Empréstimo de Médio valor (até R$20000.00).");
        } else {
            if (renda>=10000 && atraso2==0 && atraso_atual==0) {
            printf ("\n\t Empréstimo de Alto valor (acima de R$20000.00).");
        } else {
            printf ("\n\t Seu empréstimo foi negado!\n");
        }
    }
}
}
}
      return 0;
}
