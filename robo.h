#ifndef ROBO_H
#define ROBO_H

typedef struct Ponto {

    int X;
    int Y;
    struct Ponto *Proximo;

} Ponto;

typedef struct Caminho {

    Ponto *Origem;
    int N;  // Número de pontos percorridos
    int Distancia; // Distância total percorrida

} Caminho;

Caminho *iniciarCaminho(int N);
Ponto Final (Caminho *C);
int Distancia (Caminho *C);


#endif