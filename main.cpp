// Copyright [2025] <Eduardo Scalassara>
/**
 * \file main.cpp
 */

#include <cstdio>
#include "velha.hpp"
#include "jogo.hpp"

int main() {
    int velha[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    int jogadorAtual = 1;  
    int situacao;
    int jogadas = 0;
    const int MAX_JOGADAS = 9;  
    
    printf("=== JOGO DA VELHA ===\n");
    printf("X = Jogador 1, O = Jogador 2\n\n");
    
    do {
        ImprimeTabuleiro(velha);
        JogaNumero(velha, jogadorAtual);
        jogadas++;
        
        situacao = SituacaoJogo(velha);
        
       
        if (situacao == -1) {  
            jogadorAtual = (jogadorAtual == 1) ? 2 : 1;
        }
        
        
        if (jogadas >= MAX_JOGADAS && situacao == -1) {
            printf("Número máximo de jogadas atingido. Forçando empate.\n");
            situacao = 0;  
            break;
        }
        
    } while (situacao == -1);
    
    // Mostra resultado final
    ImprimeTabuleiro(velha);
    
    switch (situacao) {
        case 1:
            printf(" Jogador X venceu\n");
            break;
        case 2:
            printf("Jogador O venceu\n");
            break;
        case 0:
            printf("Empate!\n");
            break;
        case -2:
            printf("Jogo inválido\n");
            break;
    }
    
    return 0;
}