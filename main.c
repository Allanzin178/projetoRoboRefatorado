#include <stdio.h>
#include <stdlib.h>
#include "robo.h"

int main(){
    Caminho *c1 = iniciarCaminho(16);
    Ponto final = Final(c1);
    printf("Posição final: X = %d, Y = %d\n", final.X, final.Y);
    printf("Primeira posição: X = %d, Y = %d\n", c1->Origem->Proximo->X, c1->Origem->Proximo->Y);
    printf("Segunda posição: X = %d, Y = %d\n", c1->Origem->Proximo->Proximo->X, c1->Origem->Proximo->Proximo->Y);
    printf("Distância: %d\n\n", Distancia(c1));

    Caminho *c2 = iniciarCaminho(6);
    final = Final(c2);
    printf("Posição final: X = %d, Y = %d\n", final.X, final.Y);
    printf("Distância: %d\n\n", Distancia(c2));
    
    Caminho *c3 = iniciarCaminho(7);
    final = Final(c3);
    printf("Posição final: X = %d, Y = %d\n", final.X, final.Y);
    printf("Distância: %d\n\n", Distancia(c3));
    
    
    // Liberar memória
    free(c1->Origem);
    free(c1);
    free(c2->Origem);
    free(c2);
    free(c3->Origem);
    free(c3);

    return 0;
}