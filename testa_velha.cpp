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