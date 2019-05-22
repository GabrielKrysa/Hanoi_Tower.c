#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

int main(int argc, char const *argv[])
{
    Pilha A;
    Pilha B;
    Pilha C;
    int jogo = 0;
    int jogada1, jogada0;
    int metodo;
    int x;
asçldkaçsldkasçlkdaçsdkaçsdkas
asldkalçskd~çlaskda~çlkdasçdlkas
    inipilha(&A);
    inipilha(&B);
    inipilha(&C);
    printf("OBJETIVO: Transferir todos o discos do pino A para o pino C.\n\t  Eles devem estar na ordem 3 - 2 - 1\n");
    while(metodo != 1 && metodo != 2){
        printf("voce deseja jogar com 4 ou 3 discos?(1/2) ");
        scanf("%d", &metodo);
    }

    if(metodo == 1){
        push(&A, 4);
        push(&A, 3);
        push(&A, 2);
        push(&A, 1);
    }else if(metodo == 2){
        push(&A, 3);
        push(&A, 2);
        push(&A, 1);
    }   

    system("CLS");

    listarPilhas(&A, &B, &C);
    while (jogo == 0)
    {
        fflush(stdin);
        printf("\n\nENTRE COM A JOGADA\nPINO DE ORIGEM-> ");
        scanf("%d", &jogada1);
        printf("PINO DESTINO-> ");
        scanf("%d",&jogada0);
        system("cls");
        if (jogada1 == 1 && jogada0 == 2)
        {
            verificaPilha(&A,&B);
            listarPilhas(&A, &B, &C);
            x = verificaJogo(&C, metodo);
            if(x == 1){
                break;
            }
        }
        else if (jogada1 == 2 && jogada0 == 1)
        {
            verificaPilha(&B, &A);
            listarPilhas(&A, &B, &C);
            x = verificaJogo(&C, metodo);
            if (x == 1)
            {
                break;
            }
        }
        else if (jogada1 == 1 && jogada0 == 3)
        {
            verificaPilha(&A, &C);
            listarPilhas(&A, &B, &C);
            x = verificaJogo(&C, metodo);
            if (x == 1)
            {
                break;
            }
        }
        else if (jogada1 == 3 && jogada0 == 1)
        {
            verificaPilha(&C, &A);
            listarPilhas(&A, &B, &C);
            x = verificaJogo(&C, metodo);
            if (x == 1)
            {
                break;
            }
        }
        else if (jogada1 == 2 && jogada0 == 3)
        {
            verificaPilha(&B, &C);
            listarPilhas(&A, &B, &C);
            x = verificaJogo(&C, metodo);
            if (x == 1)
            {
                break;
            }
        }
        else if (jogada1 == 3 && jogada0 == 2)
        {
            verificaPilha(&C, &B);
            listarPilhas(&A, &B, &C);
            x = verificaJogo(&C, metodo);
            if (x == 1)
            {
                break;
            }
        }else{
            listarPilhas(&A, &B, &C);
            printf("JOGADA FORA DO INTERVALO, TENTE NOVAMENTE!\n");
        }
        
    }
    system("PAUSE");
    return 0;
}
