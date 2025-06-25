#include "Personagem.h"
#include "Cenario.h"
#include "Missao.h"
#include "Armadilha.h"
#include "BatalhaPorTurnos.h"
#include "Habilidade.h"
#include "Inventario.h"
#include "Item.h"
#include "QuebraCabeca.h"
#include <iostream>
#include<vector>

using namespace std;

int main() {
    //Aprensentação do Jogo
    cout << "\n=============================================\n";
    cout << "          RPG: Guardia da Floresta           \n";
    cout << "=============================================\n\n";
    cout << "Bem vindo(a) ao mundo magico da Floresta Encantada.\n";
    cout << "Sua missao: restaurar o equilibrio natural, combater a corrupcao e proteger os seres misticos.\n\n";
    cout << "Prepare se para a jornada que ira se iniciar...\n\n";;

    // 1. Criação do jogador
    cout<< "Digite o nome da sua personagem: ";
    string nomeJogador;
    cin >> nomeJogador;
    Jogador jogador{nomeJogador, 100};
    cout << "Bem-vindo(a), " << jogador.getNome() << "!\n";
    cout << "\nPressione Enter para continuar.\n";
    cin.ignore();
    cin.get();

    // 2. Definir Cenário Bosque das Fadas (FASE 1)
    cout << "\n=============================================\n";
    cout << "            Fase 1: Bosque das Fadas          \n";
    cout << "=============================================\n\n";

    Missao* missaoBosque = new ResgatarFada();
    Item* pocao = new PocaoCura();
    Inimigo* morcego = new Morcego();

    BosqueDasFadas bosque{missaoBosque, pocao, morcego};
    jogador.setCenario(&bosque);
    bosque.explorar(&jogador);

    //Limpeza fase 1
    delete missaoBosque;
    delete morcego;
    
    //3.Definir Cenário Clareira Corrompida(FASE 2)
    cout << "\n=============================================\n";
    cout << "            Fase 2: Clareira Corrompida          \n";
    cout << "=============================================\n\n";
    Missao* missaoClareira = new PurificarTerra();
    Item* semente = new SementeAncestral();
    Inimigo* fungo = new Fungo();
    QuebraCabeca *quebra = new QuebraClareira();

    ClareiraCorrompida clareira{missaoClareira, semente, fungo, quebra};
    jogador.setCenario(&clareira);
    clareira.explorar(&jogador);

    // Limpeza da Fase 2
    delete missaoClareira;
    delete fungo;

    
    //4.Definir cenario Lago das Lagrimas(FASE 3)
    cout << "\n=============================================\n";
    cout << "             Fase 3: Lago das Lagrimas           \n";
    cout << "=============================================\n\n";
    Missao* missaoLago = new CurarLago();
    Item* cristalAgua = new CristalDaAgua();
    Inimigo* almas = new AlmasPerdidas();
    Armadilha* lagoarmadilha = new LagoArmadilha();

    LagodasLagrimas lago{missaoLago, cristalAgua, almas, lagoarmadilha};
    jogador.setCenario(&lago);
    lago.explorar(&jogador);

    //Limpeza fase 3
    delete missaoLago;
    delete almas;

    //5.Definir Cenario Base Industrial(FASE 4)
    cout << "\n=============================================\n";
    cout << "             Fase 4: Base da Industria          ";
    cout << "=============================================\n\n";
    Missao* missaoIndustria = new SabotarIndustria();
    Item* amuleto = new AmuletoDaEsperanca();
    Inimigo* general = new General();

    BaseIndustria base{missaoIndustria, amuleto, general};
    jogador.setCenario(&base);
    base.explorar(&jogador);

    //Limpeza fase 4
    delete missaoIndustria;
    delete general;

    //Definir Cenario Coração da Floresta (FASE 5 - final)
    cout << "\n=============================================\n";
    cout << "             Fase 5: Coracao da Floresta         ";
    cout << "=============================================\n\n";
    Missao* missaoFinal = new MissaoFinal();
    Item* cristalVida = new CristalDaVida();
    Inimigo* rainha = new RainhaDasCinzas();

    CoracaoDaFloresta coracao{missaoFinal, cristalVida, rainha};
    jogador.setCenario(&coracao);
    coracao.explorar(&jogador);

    //Limpeza fase final
    delete missaoFinal;
    delete rainha;

    //Fim do Jogo
    cout << "\n=== FIM DE JOGO ===\n";
    cout << "Obrigado por jogar, " << jogador.getNome() << "!\n";

    return 0;
}