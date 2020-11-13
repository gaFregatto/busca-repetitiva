# busca-repetitiva
Trabalho segundo semestre de IA.

## Como entregar

Enviar código através do Google Classroom. Os arquivos enviados ao Classroom serão os mesmos utilizados na avaliação do trabalho, portanto apenas confirme o envio quando tiver certeza que não está faltando nada.

## Descrição
Este trabalho é em duplas.
O objetivo é criar um simples Jogo da Velha, onde um jogador humano enfrentará uma IA desenvolvida pela dupla. Esta IA deverá ser treinada através do algoritmo Minimax ou Poda Alpha-Beta.
Antes de iniciar o jogo é preciso ter uma opção de escolha para quem será o primeiro jogador: Humano ou IA. Se escolhido o Humano, então a IA sempre atuará nas camadas pares da árvore gerada, senão, a IA atuará nas camadas ímpares.
A árvore de jogadas deve ser completamente calculada pelo algoritmo escolhido antes de se iniciar o jogo.
Desta forma, a resposta da IA ser ́a instantânea para qualquer movimentação do jogador humano.
Para calcular a pontuação de cada estado no Algoritmo Minimax ou Poda Alpha-Beta utilize os seguintes valores nos estados folha:
- Se jogador Humano (MAX) ganhou, então pontuação = 1/camada(estado);
- Se jogador IA (MIN) ganhou, então pontuação = −1/camada(estado);
- Caso de empate, pontuação = 0.
A função camada(), neste caso, irá retornar um valor inteiro no intervalo [1, 9], referente a camada da ́arvore onde o estado se encontra. Note que a pontuação diminui a medida que se avançam as jogadas (ou camadas). Isso faz com que soluções mais distantes nãoo tenham o mesmo peso das soluções mais próximas,fazendo com que a IA tente ganhar o jogo o mais rápido possível. Note também os valores somam 0, logo,
com esta solução a IA sempre selecionará a melhor jogada possível em cada situação.

## Dicas de Implementaçãoo
A complexidade de construçãoo desta árvore é 9!, logo, recomenda-se que seja utilizado uma linguagem focada em performance, como o C ou C++. O usu de outras linguagens como Python ou JavaScript fará com que o cálculo da árvore seja excessivamente demorado.