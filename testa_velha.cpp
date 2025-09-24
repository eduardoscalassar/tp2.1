// Copyright [2025] <Eduardo Scalassara>

/**
 * \file testa_velha.cpp
 */

#include "velha.hpp"

#define CATCH_CONFIG_NO_POSIX_SIGNALS

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Testa velha", "[single-file]") {
  int teste1[3][3] = { { 2, 0, 1 },
                       { 2, 0, 1 },
                       { 0, 2, 1 }
                     };
  REQUIRE(VerificaVelha(teste1) == 1);
}

TEST_CASE("Testa numero de X", "[single-file]") {
  int teste1[3][3] = { { 2, 0, 1 },
                       { 2, 0, 1 },
                       { 0, 2, 1 }
                     };
  REQUIRE(NumerodeX(teste1) == 3);
}

TEST_CASE("Testa numero de O", "[single-file]") {
  int teste1[3][3] = { { 2, 0, 1 },
                       { 2, 0, 1 },
                       { 0, 2, 1 }
                     };
  REQUIRE(NumerodeO(teste1) == 3);
}

TEST_CASE("Testa se o jogo eh valido", "[single-file]") {
  int teste1[3][3] = { { 2, 0, 1 },
                       { 2, 0, 1 },
                       { 0, 2, 1 }
                     };
  REQUIRE(VerificaValido(teste1) == 1);
}

TEST_CASE("Testa se o jogo chegou ao fim. ", "[single-file]") {
  int teste1[3][3] = { { 2, 0, 1 },
					   { 2, 0, 1 },
					   { 0, 2, 1 }
					 };
  REQUIRE(VerificaFim(teste1) == 0);
}

TEST_CASE("Testa se o jogo retorna os valores corretos. ", "[single-file]") {
  int teste1[3][3] = { { 2, 0, 1 },
					   { 2, 0, 1 },
					   { 0, 2, 1 }
					 };
	// x ganha
  REQUIRE(SituacaoJogo(teste1) == 1);

  int teste2[3][3] = { { 1, 0, 1 },
					   { 0, 0, 1 },
					   { 2, 2, 2 }
					 };
	// O ganha
  REQUIRE(SituacaoJogo(teste2) == 2);

  int teste3[3][3] = { { 1, 0, 1 },
					   { 1, 0, 1 },
					   { 2, 0, 2 }
					 };

	// jogo invalido
  REQUIRE(SituacaoJogo(teste3) == -2);

  int teste4[3][3] = { { 1, 2, 1 },
					   { 2, 1, 1 },
					   { 2, 1, 2 }
					 };

	// empate
  REQUIRE(SituacaoJogo(teste4) == 0);

  int teste5[3][3] = { { 1, 2, 0 },
					   { 2, 1, 0 },
					   { 0, 0, 0 }
					 };	

	// jogo em andamento
  REQUIRE(SituacaoJogo(teste5) == -1);

}
  

