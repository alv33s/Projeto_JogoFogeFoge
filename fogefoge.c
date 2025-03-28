#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fogefoge.h"
#include "mapa.h"

MAPA m;
POSICAO heroi;
POSICAO inimigos[4]; // Agora temos 4 inimigos

// Verifica se o jogo terminou (jogo acaba quando herói fica ao lado, em cima ou embaixo de um inimigo)
int acabou() {
    for (int i = 0; i < 4; i++) {
        if ((heroi.x == inimigos[i].x && (heroi.y == inimigos[i].y - 1 || heroi.y == inimigos[i].y + 1)) || 
            (heroi.y == inimigos[i].y && (heroi.x == inimigos[i].x - 1 || heroi.x == inimigos[i].x + 1))) {
            return 1; // O jogo acaba se o herói está ao lado de algum inimigo
        }
    }
    return 0; // O jogo continua
}

// Função para verificar se uma posição é válida (não sai dos limites e não entra em paredes)
int podeMover(int x, int y) {
    return (x >= 0 && x < m.linhas && y >= 0 && y < m.colunas && m.matriz[x][y] == '.');
}

// Movimenta o jogador, impedindo atravessar obstáculos
void move(char direcao) {
    int novoX = heroi.x;
    int novoY = heroi.y;

    switch (direcao) {
        case 'a': novoY--; break;
        case 'w': novoX--; break;
        case 's': novoX++; break;
        case 'd': novoY++; break;
    }

    if (podeMover(novoX, novoY)) {
        m.matriz[heroi.x][heroi.y] = '.';
        m.matriz[novoX][novoY] = '@';
        heroi.x = novoX;
        heroi.y = novoY;
    }
}

// Movimenta os inimigos aleatoriamente (evitando sair dos limites e atravessar paredes)
void moveInimigos() {
    int direcoes[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} }; // Cima, Baixo, Esquerda, Direita
    for (int i = 0; i < 4; i++) {
        int direcaoEscolhida = rand() % 4;
        int novoX = inimigos[i].x + direcoes[direcaoEscolhida][0];
        int novoY = inimigos[i].y + direcoes[direcaoEscolhida][1];

        if (podeMover(novoX, novoY)) {
            m.matriz[inimigos[i].x][inimigos[i].y] = '.';
            m.matriz[novoX][novoY] = 'E';
            inimigos[i].x = novoX;
            inimigos[i].y = novoY;
        }
    }
}

int main() {
    srand(time(0)); // Inicializa a semente do gerador de números aleatórios

    lemapa(&m);
    encontramapa(&m, &heroi, '@'); // Encontra o jogador
    
    // Aqui, verificamos se cada inimigo tem um local diferente no mapa
    for (int i = 0; i < 4; i++) {
        char inimigoChar = 'E'; // Identificador de inimigo
        int x, y;
        
        do {
            x = rand() % m.linhas;
            y = rand() % m.colunas;
        } while (m.matriz[x][y] != '.' || (x == heroi.x && y == heroi.y)); // Certifique-se de que o inimigo não apareça onde o herói está
        
        inimigos[i].x = x;
        inimigos[i].y = y;
        m.matriz[x][y] = inimigoChar; // Coloca o inimigo no mapa
    }

    do {
        imprimemapa(&m);

        char comando;
        scanf(" %c", &comando);

        move(comando);
        moveInimigos(); // Faz os inimigos se moverem ao mesmo tempo após o jogador

    } while (!acabou()); // O jogo termina se o herói ficar ao lado, em cima ou embaixo de um inimigo

    printf("GAME OVER! O herói foi pego por um inimigo.\n");

    liberamapa(&m);
}
