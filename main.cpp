#include "Personagem.h"
#include "Cenario.h"
#include "Missao.h"
#include "Armadilha.h"
#include "BatalhaPorTurnos.h"
#include "Habilidade.h"
#include "Inventario.h"
#include "QuebraCabeca.h"
#include <iostream>
using namespace std;

int main() {
    // 1. Criação do jogador
    Jogador jogador{"FadaGuardiana", 100};

    // 2. Definir Cenário Bosque das Fadas (FASE 1)
    Missao* missaoBosque = new ResgatarFada();
    Item* pocao = new PocaoCura();
    Inimigo* morcego = new Morcego();

    BosqueDasFadas bosque{missaoBosque, pocao, morcego};
    jogador.setCenario(&bosque);
    bosque.explorar(&jogador);

    delete missaoBosque;
    delete pocao;
    delete morcego;
    
    return 0;
}