// Copyright [2025] <Eduardo Scalassara>
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

int VerificaVelha(int velha[3][3]) {
  // verificando se x completou alguma linha
  if ((velha[0][0] == 1) && (velha[0][1] == 1) && (velha[0][2] == 1)) return 1;
  if ((velha[1][0] == 1) && (velha[1][1] == 1) && (velha[1][2] == 1)) return 1;
  if ((velha[2][0] == 1) && (velha[2][1] == 1) && (velha[2][2] == 1)) return 1;

  // verificando se O completou alguma linha
  if ((velha[0][0] == 2) && (velha[0][1] == 2) && (velha[0][2] == 2)) return 2;
  if ((velha[1][0] == 2) && (velha[1][1] == 2) && (velha[1][2] == 2)) return 2;
  if ((velha[2][0] == 2) && (velha[2][1] == 2) && (velha[2][2] == 2)) return 2;

  // verificando se x completou alguma coluna
  if ((velha[0][0] == 1) && (velha[1][0] == 1) && (velha[2][0] == 1)) return 1;
  if ((velha[0][1] == 1) && (velha[1][1] == 1) && (velha[2][1] == 1)) return 1;
  if ((velha[0][2] == 1) && (velha[1][2] == 1) && (velha[2][2] == 1)) return 1;

  // verificando se O completou alguma coluna
  if ((velha[0][0] == 2) && (velha[1][0] == 2) && (velha[2][0] == 2)) return 2;
  if ((velha[0][1] == 2) && (velha[1][1] == 2) && (velha[2][1] == 2)) return 2;
  if ((velha[0][2] == 2) && (velha[1][2] == 2) && (velha[2][2] == 2)) return 2;

  // verificando se x completou alguma diagonal
  if ((velha[0][0] == 1) && (velha[1][1] == 1) && (velha[2][2] == 1)) return 1;
  if ((velha[0][2] == 1) && (velha[1][1] == 1) && (velha[2][0] == 1)) return 1;

  // verificando se O completou alguma diagonal
  if ((velha[0][0] == 2) && (velha[1][1] == 2) && (velha[2][2] == 2)) return 2;
  if ((velha[0][2] == 2) && (velha[1][1] == 2) && (velha[2][0] == 2)) return 2;

  return 0;
}

int NumerodeX(int velha[3][3]) {
  int contador = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (velha[i][j] == 1) {
        contador++;
      }
    }
  }
  return contador;
}

int NumerodeO(int velha[3][3]) {
  int contador = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (velha[i][j] == 2) {
        contador++;
      }
    }
  }
  return contador;
}


int VerificaValido(int velha[3][3]) {
  int numX = NumerodeX(velha);
  int numO = NumerodeO(velha);
  int diff = numX - numO;
  if (diff >= 0 && diff <= 1) {
    return 1;  // Jogo valido
  } else {
    return 0;  // Jogo invalido
  }
}

int VerificaFim(int velha[3][3]){
	int z = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (velha[i][j] == 0) {
				z++;
			}
		}
	}
	if (z == 0) {
		return 1; // Jogo terminou
	} else {
		return 0; // Jogo nao terminou
	}
}

