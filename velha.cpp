/**
 * \file  velha.cpp
 */

 
#include "velha.hpp"

/** 
 * @brief verifica situacao do jogo da velha  
 * @author Programador 
 * @param  velha descreve o parametro
 * 
 *  Descrever o que a funcao faz
 */ 

int VerificaVelha( int velha[3][3] )
{
	// Verifica linhas
	for (int i = 0; i < 3; i++) {
		if (velha[i][0] != 0 && velha[i][0] == velha[i][1] && velha[i][1] == velha[i][2]) {
			return velha[i][0];
		}
	}
	
	// Verifica colunas
	for (int j = 0; j < 3; j++) {
		if (velha[0][j] != 0 && velha[0][j] == velha[1][j] && velha[1][j] == velha[2][j]) {
			return velha[0][j];
		}
	}
	
	// Verifica diagonal principal
	if (velha[0][0] != 0 && velha[0][0] == velha[1][1] && velha[1][1] == velha[2][2]) {
		return velha[0][0];
	}
	
	// Verifica diagonal secundária
	if (velha[0][2] != 0 && velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0]) {
		return velha[0][2];
	}
	
	return 0; /*!< retorna zero se não há vencedor */
}


