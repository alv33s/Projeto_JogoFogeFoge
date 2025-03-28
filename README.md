# Jogo de Fuga (Fogefoge)
## 📌 Sobre o Projeto
Fogefoge é um jogo simples desenvolvido em C, onde o objetivo é controlar um herói que deve se mover pelo mapa enquanto evita inimigos que se movem aleatoriamente. O jogador deve usar os controles para explorar o ambiente e escapar dos inimigos, enquanto o jogo termina quando o herói fica ao lado de um inimigo.

### Características principais:
 - Movimentação do herói.

 - Movimentação aleatória de inimigos.

 - Mapa carregado dinamicamente com posições aleatórias para o herói e inimigos.

 - O jogo termina quando o herói fica ao lado ou em cima de um inimigo.

## 🎮 Como Jogar
O herói é representado pelo caractere @.

O inimigo é representado pelo caractere E.

O objetivo do jogo é escapar dos inimigos e explorar o mapa.

### Controles:

W - Mover para cima

S - Mover para baixo

A - Mover para a esquerda

D - Mover para a direita

### Condição de fim de jogo:
O jogo termina quando o herói se posiciona em uma célula adjacente (acima, abaixo, esquerda ou direita) de um inimigo.

## 🛠️ Como Compilar e Executar
### Pré-requisitos:
 - GCC (GNU Compiler Collection) instalado no seu sistema.

 - Um terminal ou o VS Code configurado para compilar e rodar programas em C.

### Compilação Manual via Terminal:
 - No terminal ou no VS Code, use o seguinte comando para compilar os arquivos .c:

        gcc -o fogefoge fogefoge.c mapa.c -Wall
   
### Executar o jogo:
 - Depois de compilar, execute o programa gerado com o seguinte comando:

 - No Linux/macOS:

        ./fogefoge

 - No Windows:


        fogefoge.exe

## 📂 Estrutura do Projeto
 - A estrutura de arquivos do projeto é a seguinte:

### 📦 Projeto_Fogefoge

 - ┣ 📜 fogefoge.c       # Código principal do jogo
 - ┣ 📜 mapa.c           # Funções para manipulação do mapa
 - ┣ 📜 mapa.h           # Header do mapa
 - ┣ 📜 fogefoge.h       # Header do jogo
 - ┣ 📜 mapa.txt         # Arquivo contendo o mapa inicial
 - ┣ 📜 README.md        # Documentação do projeto
 
## Descrição dos arquivos:

 - fogefoge.c: Contém o código principal do jogo, onde o herói se move, inimigos se movem aleatoriamente e a lógica de fim de jogo é tratada.

 - mapa.c: Contém funções para carregar, imprimir e liberar o mapa do jogo.

 - mapa.h: Arquivo de cabeçalho com definições e declarações usadas por mapa.c.

 - fogefoge.h: Arquivo de cabeçalho com as definições de variáveis e funções utilizadas por fogefoge.c.

## ✨ Contribuições
 - Contribuições são bem-vindas! Para contribuir:

 - Faça um fork do repositório.

 - Crie uma nova branch (git checkout -b minha-feature).

 - Faça commit das suas mudanças (git commit -m 'Adicionando nova funcionalidade').

 - Envie o push para a branch (git push origin minha-feature).

 - Abra um Pull Request.

## Autor
Felipe Alves Muniz
