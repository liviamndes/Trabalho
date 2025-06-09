#include <iostream>
#include "Personagem.h"
#include "Cenario.h"
#include "Missao.h"
#include "BatalhaPorTurnos.h"
#include "QuebraCabeca.h"

using namespace std;

void Cenario::iniciarMissao(Jogador *jogador) {
    cout << "Voce chegou ao " << nome << "\n";
    cout << descricao << "\n";
    missaoAtual->iniciar();
}
void BosqueDasFadas::explorar(Jogador* jogador) {
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) {
        // Caso a missão ainda não tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
        cout << "Missao iniciada!\n";
    }

    // Enfrentando inimigo: morcego
    cout << "De repente, um Morcego aparece e começa a te ataca!\n";
    Morcego *morcego = new Morcego();
    batalha(jogador, morcego); // ! ! Implementei aqui o de batalha, mas se precisar alterar pode mexer ! !
    delete morcego;

    // Coletar ingredientes da poção de cura
    cout << "Deseja coletar ingredientes para a Poção de Cura? (S/N)" << endl;
    char resposta;
    cin >> resposta;
    if(resposta == 'S' || resposta == 's') {
        cout << "Voce coletou as folhas e flores necessarias para a Poção de Cura.\n";
        // Receber item Pocao Cura
                // . . .

        cout << "A Poção de Cura esta agora no seu inventario!" << "\n";

        cout << "Deseja curar a fada ferida?\n";
        cin >> resposta;

        if(resposta == 'S' || resposta == 's') {
            missaoAtual->concluir();
            jogador->ganharExperiencia(50);
            jogador->subirNivel();
        }
        else {
            cout << "Você ainda precisa da Poção de Cura para ajudar a fada!\n";
        }
    }
    else {
        cout << "Voce precisa coletar ingredientes para concluir a missao!\n";
    }
}

void ClareiraCorrompida::explorar(Jogador *jogador) {
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) {
        // Caso a missão ainda não tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
        cout << "Missao iniciada!\n";
    }

    // Enfrentando inimigo: Lobo
    cout << "Voce comeca a sentir uma presenca...\n";
    cout << "Um lobo vindo da escuridao aparece e voce precisa se defender!\n";
    Lobo *lobo = new Lobo();
    batalha(jogador, lobo);
    delete lobo;

    // Quebra cabeça
    QuebraClareira *clareira = new QuebraClareira();
    jogador->definirQuebraCabeca(clareira);
    bool resolveu = jogador->resolverQuebraCabecaAtual();
    delete clareira;

    // Receber item de recompensa
    if(resolveu) {
    
    }
}
void Ruinas::explorar(Jogador *jogador) {
     // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) {
        // Caso a missão ainda não tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
        cout << "Missao iniciada!\n";
    }

    // Enfrentando inimigo: Fungo
    cout << "Você adentra as ruínas antigas e sente um ar pesado e sombrio...\n";
    cout << "De repente, uma criatura sinistra emerge das sombras: um Fungo Ancestral!\n";
    Fungo *fungo = new Fungo();
    batalha(jogador, fungo); 
    delete fungo;

}