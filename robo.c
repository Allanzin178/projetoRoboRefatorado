#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "robo.h"

#define INICIAL_X 0
#define INICIAL_Y 0

#define POSITIVO 0
#define NEGATIVO 1

// Struct Ponto armazena cada ponto onde o robô girou 90 graus no sentido anti horario
// Struct Caminho (lista encadeada) armazena cada ponto onde o robô teve que realizar esse movimento

void andarRobo(Caminho *C);
void calcularSinal(int *eixo, int *alternaSinal, int *disMovimento);

Caminho *iniciarCaminho(int N)
{
    Caminho *caminho = (Caminho *)malloc(sizeof(Caminho));
    if (caminho == NULL)
    {
        printf("Erro ao alocar memória para a lista.\n");
        exit(1);
    }

    caminho->Origem = (Ponto *)malloc(sizeof(Ponto));
    if (caminho->Origem == NULL)
    {
        printf("Erro ao alocar memória para o ponto de origem.\n");
        free(caminho);
        exit(1);
    }


    caminho->N = N;
    caminho->Distancia = 0;
    caminho->Origem->X = INICIAL_X;
    caminho->Origem->Y = INICIAL_Y;

    return caminho;
}

void andarRobo(Caminho *C) {
    int ciclos, alternaSinal = POSITIVO, eixo = 0, disMovimento = 1;
    Ponto *anterior = C->Origem;

    for (ciclos = 1; ciclos <= C->N; ciclos++) {
        Ponto *atual = (Ponto *)malloc(sizeof(Ponto));

        // Inicializando ponteiro atual
        atual->X = anterior->X;
        atual->Y = anterior->Y;
        atual->Proximo = NULL;

        // Atualiza o ponteiro Proximo do ponto anterior para apontar para o novo ponto
        anterior->Proximo = atual;

        // Lógica de movimento: alterna entre movimentos no eixo X e Y
        if (ciclos % 2 != 0) {
            if (alternaSinal == POSITIVO) {
                atual->X = atual->X + disMovimento;
            } else {
                atual->X = atual->X - disMovimento;
            }
        } else {
            if (alternaSinal == POSITIVO) {
                atual->Y = atual->Y + disMovimento;
            } else {
                atual->Y = atual->Y - disMovimento;
            }
        }

        // Função para calcular o sinal
        calcularSinal(&eixo, &alternaSinal, &disMovimento);

        anterior = atual;
    }
}

// Função para calcular o ponto final após o robô ter andado
Ponto Final(Caminho *C) {

    // Restrições
    Ponto Nulo = {INICIAL_X, INICIAL_Y, NULL};
    if (C->N == 0)
    {
        return Nulo;
    }

    if (C->N < 0)
    {
        return Nulo;
    }

    // Função para andar
    andarRobo(C);

    // Após a execução da função andarRobo, o ponto final será o último ponto da lista
    Ponto *anterior = C->Origem;
    while (anterior->Proximo != NULL) {
        anterior = anterior->Proximo;
    }

    // Retorna o último ponto
    return *anterior;  
}

int Distancia(Caminho *C)
{
    int distancia = 0;
    int j = 1;

    // Restrições: 
    if (C->N <= 0)
    {
        return 0;
    }

    // Calculo da distancia:
    for (int i = 1; i <= C->N; i++)
    {
        distancia += j;
        if (i % 2 == 0)
        {
            j++;
        }
    }
    return distancia;
}

void calcularSinal(int *eixo, int *alternaSinal, int *disMovimento){
    *eixo = *eixo + 1;
    if (*eixo == 2) {
        *alternaSinal = NEGATIVO;
        *disMovimento = *disMovimento + 1;
    }
    if (*eixo == 4) {
        *alternaSinal = POSITIVO;
        *disMovimento = *disMovimento + 1;
        *eixo = 0;
    }
}