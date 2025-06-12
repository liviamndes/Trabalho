#include <iostream>
#include "Personagem.h"
#include "Cenario.h"
#include "Missao.h"
#include "BatalhaPorTurnos.h"
#include "QuebraCabeca.h"
#include "Armadilha.h"

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
    cout << "Um fungo infectado começou a te consumir e voce precisa se defender!\n";
    Fungo *fungo = new Fungo();
    batalha(jogador, fungo);
    delete fungo;

    // Quebra cabeça
    QuebraClareira *clareira = new QuebraClareira();
    jogador->definirQuebraCabeca(clareira);
    bool resolveu = jogador->resolverQuebraCabecaAtual();
    delete clareira;

    // Receber item de recompensa
    if(resolveu) {
    
    }
}
void LagodasLagrimas::explorar(Jogador *jogador) {
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) {
        // Caso a missão ainda não tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
        cout << "Missao iniciada!\n";
    }

    // Enfrentando inimigo: Almas perdias
    cout << "Você começa a sentir uma presença sombria...\n";
    cout << "As Almas Perdidas surgem e começam a cercá-lo. Prepare-se para a batalha!\n";
    AlmasPerdidas *almas = new AlmasPerdidas();
    batalha(jogador, almas);
    delete almas;

    // Jogador recebe recompensa
    string resposta, purificar;
    Item* cristal = new Item("Cristal da Agua", 
        "Um cristal que contem o poder de purificar a terra");

    cout << "Apos derrotar o inimigo, voce encontra um brilho na agua...\n";
    cout << "Você se aproxima e encontra o" << cristal->getNome() << "\n";
    cout << cristal->getDescricao() << "\n";
    cout << "Voce deseja colocar o item no seu inventario (S/N)?\n";

    cin >> resposta;
    while(resposta != "S" && resposta != "N") {
        cout << "Insira uma resposta valida (S/N)\n";
        cin >> resposta;
    }
    if(resposta == "S") {
        cout << "Voce agora possui o Cristal da Agua!\n";
        jogador->adicionarItemAoInventario(cristal);
        cout << "Digite 'PURIFICAR' para salvar o solo!";
        cin >> purificar;
        while(purificar != "PURIFICAR") {
            cout << "Algo esta errado, tente novamente para concluir a missao!\n";
            cin >> purificar;
        }
        jogador->usarItemDoInventario(cristal->getNome());
        cout << "Voce acabou de restaurar o solo e o lago das lagrimas brilha novamente!\n";
    }

    // Armadilha
    cout << "Antes de sair do lago, voce precisa tomar a 'Pocao Misterio' para se fortalecer para o que vier, ou nao...\n";
 
    LagoArmadilha *lagoArmadilha = new LagoArmadilha();
    lagoArmadilha->ativar(jogador);
    delete lagoArmadilha;

    // Concluir missão
    missaoAtual->concluir();
    jogador->ganharExperiencia(50);
    jogador->subirNivel();
}