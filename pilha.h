+#ifndef _PILHA_H

#define _PILHA_H
#define MAX 4
#define ERROPILHACHEIA -1
#define ERROPILHAVAZIA -2

#include <stdlib.h>

typedef struct
{
    int item[MAX];
    int topo;
} Pilha;

int jogadas = 0;

void inipilha(Pilha *p)
{
    p->topo = 0;
}

int vaziapilha(Pilha *p)
{
    if (p->topo == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int cheiapilha(Pilha *p)
{
    if (p->topo == MAX)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int push(Pilha *p, int x)
{
    if (cheiapilha(p) == 1)
    {
        return (ERROPILHACHEIA);
    }
    else
    {
        p->item[p->topo] = x;
        p->topo++;
        return (p->topo);
    }
}

int pop(Pilha *p)
{
    int aux;
    if (vaziapilha(p))
    {
        return (ERROPILHAVAZIA);
    }

    else
    {
        aux = p->item[p->topo - 1];
        p->topo--;
        return (aux);
    }
}

//----------------------------------------------------FUNÇOES HANOI-----------------------------------------------
//VERIFICA SE O JOGO TERMINOU
int verificaJogo(Pilha *p, int metodo)
{
    int a = p->topo;
    int soma = 0;

    if (metodo == 1)
    {
        if (jogadas < 30)
        {
            if (p->topo == 3)
            {
                if (p->item[a - 1] == 1)
                {
                    a--;
                    if (p->item[a - 1] == 2)
                    {
                        a--;
                        if (p->item[a - 1] == 3)
                        {
                            a--;
                            if (p->item[a - 1] == 4)
                            {
                                printf("VOCE GANHO COM %d JOGADAS!, VOCÊ TINHA 30 MOVIMENTO\n", jogadas);
                                return 1;
                            }
                            else
                            {
                                return 0;
                            }
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            printf("VOCE EXCEDEU O NUMERO MAXIMO DE JOGADA, QUE ERA 30\n");
            return 1;
        }
    }

    else if (metodo == 2)
    {
        if (jogadas < 14)
        {
            if (p->topo == 3)
            {

                if (p->item[a - 1] == 1)
                {
                    a--;
                    if (p->item[a - 1] == 2)
                    {
                        a--;
                        if (p->item[a - 1] == 3)
                        {
                            printf("VOCE GANHO COM %d JOGADAS!\n", jogadas);
                            return 1;
                        }
                        else
                        {
                            return 0;
                        }
                    }
                    else
                    {
                        return 0;
                    }
                }
                else
                {
                    return 0;
                }
            }
            else
            {
                return 0;
            }
        }
        else
        {
            printf("VOCE EXCEDEU O NUMERO MAXIMO DE JOGADA, QUE ERA 14\n");
            return 1;
        }
    }
}
//VERIFICA SE A JOGADA ESTA CORRETO DENTRO DAS NORMAS DO JOGO
void verificaPilha(Pilha *p, Pilha *q)
{
    if (vaziapilha(q) == 1 && vaziapilha(p) == 0)
    {
        int a = pop(p);
        push(q, a);
        jogadas++;
    }
    else if (vaziapilha(p) == 0)
    {
        if (p->item[p->topo - 1] > q->item[q->topo - 1])
        {
            printf("VOCE NAO PODE COLOCAR UM PECA MAIOR EM CIMA DE UMA MENOR\n");
        }
        else
        {
            int a = pop(p);
            push(q, a);
            jogadas++;
        }
    }
    else
    {
        printf("VOCE NAO PODE TIRAR UM ITEM DE UMA PILHA VAZIA\n");
    }
}

//REALIZA O PRINT DAS 3 PILHAS
void listarPilhas(Pilha *a, Pilha *b, Pilha *c)
{
    int a1 = a->topo;
    int b1 = b->topo;
    int c1 = c->topo;

    printf("\n1 -> ");
    for (int i = 0; i < a->topo; i++)
    {
        printf("%d ", a->item[i]);
    }
    printf("\n2 -> ");
    for (int i = 0; i < b->topo; i++)
    {
        printf("%d ", b->item[i]);
    }
    printf("\n3 -> ");
    for (int i = 0; i < c->topo; i++)
    {
        printf("%d ", c->item[i]);
    }
    printf("\n");
}

//--------------------------------------------------------------------------------------------------------------
#endif
