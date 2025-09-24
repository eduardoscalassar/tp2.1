# Jogo da Velha

  Este projeto é um jogo da velha que você pode jogar pelo terminal. Ele foi desenvolvido seguindo o padrão de TDD (Test Driven Development). Com isso, a cada função
de verificação das regras do jogo da velha, seguiu-se uma sequência de Vermelho-Verde-Fatoração, que vai ser explicado adiante.

  No arquivo velha.hpp, podemos ver as funções definidas:

```cpp
int VerificaVelha(int velha[3][3]);

int NumerodeX(int velha[3][3]);

int NumerodeO(int velha[3][3]);

int VerificaValido(int velha[3][3]);

int VerificaFim(int velha[3][3]);

int SituacaoJogo(int velha[3][3]);
```

  Para cada uma dessas funções o teste foi elaborado antes (Vermelho), depois foi implementado o mínimo para a que a função passasse no teste (Verde), e depois houve a refatoração
de acordo com o cpplint (Refatoração).

  Para cada uma dessas fases houve um commit chamado "test_results" seguido da data e horarário do commit, de forma que eles ficaram em ordem cronológica. Neles pode-se
observar que a implementação das funções seguiu o padrão do TDD, em que primeiro o teste não passava, depois tentava-se passar no teste, e depois refatorava-se.

  Para testar o jogo, vá no diretório do arquivo e digite na linha de comando "./jogo".

