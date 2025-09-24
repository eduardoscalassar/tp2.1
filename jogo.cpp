// Copyright [2025] <Eduardo Scalassara>
/**
 * \file jogo.cpp
 */

#include "jogo.hpp"

void ImprimeTabuleiro(int velha[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int pos = i * 3 + j + 1;
            if (velha[i][j] == 0) {
                printf(" %d ", pos);
            } else {
                char simbolo = (velha[i][j] == 1) ? 'X' : 'O';
                printf(" %c ", simbolo);
            }
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

void JogaNumero(int velha[3][3], int jogador) {
    char entrada[10];
    int posicao;
    int tentativas = 0;
    const int MAX_TENTATIVAS = 10;
    
    while (tentativas < MAX_TENTATIVAS) {
        printf("Jogador %c, escolha uma posição (1-9): ", 
               jogador == 1 ? 'X' : 'O');
        fflush(stdout);  // Força a exibição da mensagem
        
        // Usa fgets para ler linha completa, mais seguro que scanf
        if (fgets(entrada, sizeof(entrada), stdin) == NULL) {
            printf("Erro na leitura da entrada ou fim do arquivo.\n");
            // Em caso de erro de leitura, escolhe uma posição aleatória válida
            for (int i = 0; i < 9; i++) {
                int linha = i / 3;
                int coluna = i % 3;
                if (velha[linha][coluna] == 0) {
                    velha[linha][coluna] = jogador;
                    printf("Jogada automática na posição %d.\n", i + 1);
                    return;
                }
            }
            return;
        }
        
        // Converte string para inteiro
        if (sscanf(entrada, "%d", &posicao) != 1) {
            printf("Entrada inválida! Digite apenas números.\n");
            tentativas++;
            continue;
        }
        
        if (posicao < 1 || posicao > 9) {
            printf("Posição inválida! Digite um número de 1 a 9.\n");
            tentativas++;
            continue;
        }
        
        int linha = (posicao - 1) / 3;
        int coluna = (posicao - 1) % 3;
        
        if (velha[linha][coluna] != 0) {
            printf("Posição ocupada! Tente novamente.\n");
            tentativas++;
            continue;
        }
        
        // Se chegou aqui, a jogada é válida
        velha[linha][coluna] = jogador;
        return;
    }
    
    // Se excedeu o número de tentativas, faz jogada automática
    printf("Muitas tentativas inválidas. Fazendo jogada automática...\n");
    for (int i = 0; i < 9; i++) {
        int linha = i / 3;
        int coluna = i % 3;
        if (velha[linha][coluna] == 0) {
            velha[linha][coluna] = jogador;
            printf("Jogada automática na posição %d.\n", i + 1);
            return;
        }
    }
}