🇧🇷 Português · 🇺🇸 [English summary](#english-summary)

# Guardiã da Floresta — RPG de console em C++

Projeto da disciplina de **Programação Orientada a Objetos** (ECOP13A, UNIFEI), ministrada pelo
Prof. João Paulo Reus Rodrigues Leite. RPG de console em que o jogador, uma fada, atravessa uma
floresta encantada para restaurar o equilíbrio da natureza. Aplica conceitos de POO em C++, como
modelagem de classes, herança, polimorfismo e templates.

## Estrutura

```
CODE/                          # código-fonte em C++
├── main.cpp                   # fluxo do jogo (5 fases)
├── Personagem.h / .cpp        # Personagem, Jogador, Inimigo e os inimigos de cada fase
├── Cenario.h / .cpp           # Cenario e os cenários de cada fase
├── Missao.h / .cpp            # Missao e as missões de cada fase
├── Item.h / .cpp              # Item e os itens mágicos
├── Inventario.h / .cpp        # inventário do jogador (template)
├── Habilidade.h / .cpp        # habilidades de ataque e defesa
├── BatalhaPorTurnos.h / .cpp  # combate por turnos
├── QuebraCabeca.h / .cpp      # quebra-cabeças
├── Armadilha.h / .cpp         # armadilhas e eventos aleatórios
├── jogo.exe                   # executável (Windows)
DOCS/
├── Relatorio_Guardia_Floresta.pdf   # relatório da atividade
└── mapamental.txt                   # planejamento inicial
```

## O jogo

O jogador cria sua personagem e passa por cinco fases. Em cada uma ele cumpre uma missão,
resolve um quebra-cabeça ou enfrenta armadilhas, desbloqueia um item mágico e derrota um inimigo
em batalha por turnos. Cada missão concluída libera uma habilidade de defesa e uma de ataque.
Na última fase, a Rainha das Cinzas oferece um novo caminho, e a escolha do jogador define o
final: salvar a floresta ou abandonar a missão e se tornar humana.

| Fase | Cenário | Missão | Inimigo | Item |
|---|---|---|---|---|
| 1 | Bosque das Fadas | Retorno ao Santuário | Morcego | Poção de Cura |
| 2 | Clareira Corrompida | Purificação da Clareira | Fungo | Semente Ancestral |
| 3 | Lago das Lágrimas | Cure o Lago das Lágrimas | Almas Perdidas | Cristal da Água |
| 4 | Base da Indústria | Contra a Exploração | General | Amuleto da Esperança |
| 5 | Coração da Floresta | O Destino da Floresta | Rainha das Cinzas | Cristal da Vida |

O planejamento inicial está em DOCS/mapamental.txt, com mais fases do que a versão final. As respostas
dos quebra-cabeças e o detalhamento das classes estão no relatório em `DOCS/`.

## Conceitos de POO aplicados

- **Herança:** `Jogador` e `Inimigo` derivam de `Personagem` (e cada inimigo, de `Inimigo`).
  Cenários, missões, itens e habilidades também têm uma classe base e uma subclasse por fase.
- **Polimorfismo:** classes abstratas com métodos virtuais puros (`Cenario::explorar`,
  `Item::usar`) e métodos sobrescritos (`Missao::concluir`). No `main.cpp`, `Missao*`, `Item*`,
  `Inimigo*`, `QuebraCabeca*` e `Armadilha*` recebem a subclasse de cada fase.
- **Templates:** o `Inventario` é uma classe genérica (`Inventario<Item>`).
- **Composição:** o `Jogador` possui seu inventário, suas habilidades, a missão e o cenário
  atuais, e o `Cenario` agrega missão, item, inimigo, armadilha e quebra-cabeça.

## Como executar

No Windows, execute `CODE/jogo.exe`. Para compilar, a partir da pasta `CODE/`:

```
g++ *.cpp -o jogo
./jogo
```

## Créditos

Disciplina ECOP13A — Programação Orientada a Objetos, UNIFEI (2025.1), ministrada pelo
Prof. João Paulo Reus Rodrigues Leite.

## Autoras

Mel Cabral Fiore Brito ([@melfioree](https://github.com/melfioree)) — Engenharia de Computação, UNIFEI<br>
Lívia Mendes Borges ([@liviamndes](https://github.com/liviamndes)) — Engenharia de Computação, UNIFEI

---

<a name="english-summary"></a>

## English summary

Developed as part of the Object-Oriented Programming course (ECOP13A, UNIFEI), taught by Prof.
João Paulo Reus Rodrigues Leite, this console-based RPG places the player in an enchanted forest
to restore balance to nature. It applies key OOP principles in C++, including class design,
inheritance, polymorphism and templates.

Five levels (Fairy Grove, Corrupted Glade, Lake of Tears, Industrial Base, Heart of the Forest),
each with a mission, a puzzle or traps, a magic item and a turn-based boss fight. The final
choice leads to one of two endings. Source code in `CODE/`, project report in `DOCS/`.
