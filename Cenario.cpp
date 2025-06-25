#include <iostream>
#include "Personagem.h"
#include "Cenario.h"
#include "Missao.h"
#include "BatalhaPorTurnos.h"
#include "QuebraCabeca.h"
#include "Armadilha.h"
#include "Inventario.h"

using namespace std;

void Cenario::iniciarMissao(Jogador *jogador) {
    cout << "Voce chegou ao " << nome << "\n";
    cout << descricao << "\n";
    missaoAtual->iniciar();
}

ResultadoBatalha Cenario :: iniciarBatalha(Jogador& jogador, Inimigo& inimigo){
    BatalhaPorTurnos batalha(jogador, inimigo);
    bool venceu = batalha.iniciar();

    ResultadoBatalha resultado;
    resultado.venceu = venceu;
    resultado.fugiu = batalha.fuga();
    if (venceu) {
        Habilidade* novaHabilidadeDefesa = nullptr;
        Habilidade* novaHabilidadeAtaque = nullptr;

        if (nome == "Bosque das Fadas") {
            novaHabilidadeDefesa = new EscudoDeLuz();
            novaHabilidadeAtaque = new DardoLuminoso();
        }
        else if (nome == "Clareira Corrompida") {
            novaHabilidadeDefesa = new RugidoDaNatureza();
            novaHabilidadeAtaque = new GarrasDaTerra();
        }
        else if (nome == "Lago das Lagrimas") {
            novaHabilidadeDefesa = new ChuvaPurificadora();
            novaHabilidadeAtaque = new JorroEncantado();
        }
        else if (nome == "Base da Industria") {
            novaHabilidadeDefesa = new AuraDaResistencia();
            novaHabilidadeAtaque = new RajadaEnergetica();
        }
        else if (nome == "Coracao da Floresta") {
            novaHabilidadeDefesa = new RenascimentoDaFloresta();
            novaHabilidadeAtaque = new ExplosaoCelestial();
        }

        if (novaHabilidadeDefesa != nullptr && novaHabilidadeAtaque != nullptr ) {
            novaHabilidadeDefesa->desbloquear();
            novaHabilidadeAtaque->desbloquear();

            cout << "\nParabens! Voce desbloqueou a habilidade de defesa: " << novaHabilidadeDefesa->getNome() << "!\n";
            cout << "Parabens! Voce desbloqueou a habilidade de ataque: " << novaHabilidadeAtaque->getNome() << "!\n";
            jogador.adicionarHabilidade(novaHabilidadeDefesa);
            jogador.adicionarHabilidade(novaHabilidadeAtaque);
        }
    }

    return resultado;
}

void BosqueDasFadas::explorar(Jogador* jogador) {
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) {
        // Caso a missão ainda nao tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
    }
    cout << "\nVoce avanca pelo Bosque das Fadas.\n";
    cout << "Entre as arvores magicas, voce encontra uma pequena fada ferida.\n";
    cout << "As asas dela estao danificadas e ela precisa de sua ajuda.\n";
    cout << "Para curar a fada, voce precisara preparar uma Pocao de Cura.\n";

    cout << "\nPressione Enter para continuar...\n";
    cin.get();

    char resposta = 'N';

    // Loop para garantir a coleta de ingredientes
    while (resposta != 'S' && resposta != 's') {
        cout << "\nDeseja coletar ingredientes para a Pocao de Cura? (S/N)" << endl;
        cin >> resposta;

        if(resposta == 'S' || resposta == 's') {
            cout << "\nVoce percorre o bosque em busca de folhas e flores encantadas...\n";
            cout << "Voce coletou os ingredientes necessarios para preparar a Pocao de Cura.\n";
            item->desbloquear();
            jogador->adicionarItemAoInventario(item);
            break;
        }
        else {
            cout << "\nSem a pocao, voce nao conseguira ajudar a fada.\n";
            cout << "Tente novamente apos refletir sobre sua decisao.\n";
        }
    } 
    cout << "\nPressione Enter para continuar...\n";
    cin.ignore();
    cin.get();

    // Ajudar a fada ferida
    bool fadaCurada = false;
    while(!fadaCurada) {
        cout << "\nDeseja curar a fada ferida? (S/N)\n";
        cin >> resposta;

        if(resposta == 'S' || resposta == 's') {
            jogador->usarItemDoInventario("Pocao de Cura");
            jogador->concluirMissao(missaoAtual);
            jogador->ganharExperiencia(50);
            jogador->subirNivel();
            fadaCurada = true;
        }
        else {
            cout << "Voce ainda precisa usar a Pocao de Cura para ajudar a fada!\n";
        }
    }

    cout << "\nPressione Enter para continuar...\n";
    cin.ignore();
    cin.get();

    // Enfrentando inimigo: morcego
    cout << "\n----------------------------------------------------------------------\n";
    cout << "De repente, um Morcego emerge das copas das arvores e avanca sobre voce!\n";
    cout << "As suas asas batem com furia enquanto ele tenta te atacar.\n";
    cout << "Prepare se para a batalha!\n";
    cout << "------------------------------------------------------------------------\n\n";
    
    ResultadoBatalha resultado;

    do {
        resultado = iniciarBatalha(*jogador, *inimigo);
        if (resultado.fugiu) {
            break;  // Sai do loop se fugiu
        }
    } while (!resultado.venceu);
}

void ClareiraCorrompida::explorar(Jogador *jogador) {
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) { //eu tenho que implementar isso ou ta em algm lugar q eu n achei?
        // Caso a missão ainda não tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
        cout << "Missao iniciada!\n";
    }

    // Quebra cabeça
    jogador->definirQuebraCabeca(quebra);
    bool resolveu = false;

    try {
        resolveu = jogador->resolverQuebraCabecaAtual();
    } catch (QuebraCabecaNaoResolvidoException& e) {
        cout << e.what() << "\n";
        cout << "Tente novamente.\n";
    }
    // tem que ver quando que ele vai usar esses itens 
    // Receber item de recompensa
    if(resolveu) {
        item->desbloquear();
        jogador->adicionarItemAoInventario(item);
    }

    // Enfrentando inimigo: Fungo
    cout << "Voce comeca a sentir uma presenca...\n";
    cout << "Um fungo infectado começou a te consumir e voce precisa se defender!\n";
    iniciarBatalha(*jogador, *inimigo);
    jogador->concluirMissao(missaoAtual);
}
void LagodasLagrimas::explorar(Jogador *jogador) {
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) {
        // Caso a missão ainda não tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
        cout << "Missao iniciada!\n";
    }

    // Enfrentando inimigo: Almas perdias
    cout << "Voce começa a sentir uma presença sombria...\n";
    cout << "As Almas Perdidas surgem e começam a cercá-lo. Prepare-se para a batalha!\n";
    iniciarBatalha(*jogador, *inimigo);

    // Jogador recebe recompensa
    string resposta, purificar;
    item->desbloquear();        

    cout << "Apos derrotar o inimigo, voce encontra um brilho na agua...\n";
    cout << "Você se aproxima e encontra o" << item->getNome() << "\n";
    cout << item->getDescricao() << "\n";
    cout << "Voce deseja colocar o item no seu inventario (S/N)?\n";

    cin >> resposta;
    while(resposta != "S" && resposta != "N") {
        cout << "Insira uma resposta valida (S/N)\n";
        cin >> resposta;
    }
    if(resposta == "S") {
        cout << "Voce agora possui o Cristal da Agua!\n";
        jogador->adicionarItemAoInventario(item);
        cout << "Digite 'PURIFICAR' para salvar o lago!";
        cin >> purificar;
        while(purificar != "PURIFICAR") {
            cout << "Algo esta errado, tente novamente para concluir a missao!\n";
            cin >> purificar;
        }
        jogador->usarItemDoInventario(item->getNome());
        cout << "Voce acabou de restaurar o solo e o lago das lagrimas brilha novamente!\n";
    }
    cout << "Antes de sair do lago, voce precisa tomar a 'Pocao Misterio' para se fortalecer para o que vier, ou nao...\n";
    armadilha->ativar(jogador);

    // Concluir missão
    jogador->concluirMissao(missaoAtual);
    jogador->ganharExperiencia(50);
    jogador->subirNivel();
}
void BaseIndustria::explorar(Jogador *jogador) {
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) {
        // Caso a missão ainda não tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
        cout << "Missao iniciada!\n";
    }

    // Infiltração e hackeamento dos sistemas de segurança mágicos
    cout << "Voce se aproxima do centro de controle da base...\n";
    cout << "Para acessar a sala do General, você precisa desarmar os dispositivos de segurança para infiltrar-se com sucesso.\n";
    
    // O jogador precisa resolver quebra-cabeças para hackear e desarmar dispositivos
    cout << "Desarmando os feitiços magicos e hackeando os sistemas de segurança...\n";
    QuebraIndustria *industia = new QuebraIndustria();
    jogador->definirQuebraCabeca(industia);
    bool resolveu = jogador->resolverQuebraCabecaAtual();
    delete industia;

    if (resolveu) {
        item->desbloquear();
        jogador->adicionarItemAoInventario(item);

        // Inimigo: general
        cout << "Voce conseguiu hackear os sistemas e desativar os feitiços magicos! O caminho agora esta livre para a infiltracao.\n";
        cout << "Mas, ao chegar mais perto do centro de controle, você percebe que algo está errado...\n";
        cout << "O General da Base Indústria Sombria estava esperando por voce o tempo todo. Ele e o comandante das forças de segurança da base e possui grande poder, tanto tecnológico quanto magico.\n";
        cout << "Com sua presenca imponente e sua tecnologia avancada, ele ira lutar até o fim para proteger os segredos da base.\n";
        cout << "Voce precisa se preparar para uma batalha intensa contra ele, que usa feitiçarias e tecnologias para aumentar sua forca. Prepare-se!\n";
    
        cout << "O General usa sua magia para invocar um escudo impenetrável ao redor de si, e sistemas automaticos começam a atacar de todas as direções!\n";
        cout << "Voce sente o peso da batalha, mas com a forca adquirida nas missoes anteriores, voce esta pronto para enfrenta-lo.\n";
        cout << "A luta sera difícil, mas se voce usar todas as suas habilidades e itens, pode conseguir derrota-lo e destruir a ameaça da Base Industria Sombria.\n";
        
        // Aqui é onde o jogador deve usar o Amuleto da Esperança para restaurar a força
            //...
        iniciarBatalha(*jogador, *inimigo);

        // Concluir missão
        jogador->concluirMissao(missaoAtual);
        jogador->ganharExperiencia(50);
        jogador->subirNivel();
        
    }
    else {
        cout << "Tente novamente\n";
    }
}
void CoracaoDaFloresta::explorar(Jogador *jogador) {
      // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr) {
        // Caso a missão ainda não tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
        cout << "Missao 'Renascer ou Cair' iniciada!\n";
    }

    cout << "Você chega ao Coração da Floresta. O ar está pesado, e a energia da natureza está se esvaindo.\n";
    cout << "A Rainha das Cinzas corrompeu a floresta e controla a terra com sua magia negra.\n";
    cout << "Para restaurar a floresta, você precisa ativar os pedestais mágicos espalhados pela região.\n";
    cout << "Cada pedestal exige que você use as habilidades adquiridas nas fases anteriores.\n";

    // pensei em fazer aqui uma batalha mais complexa
    iniciarBatalha(*jogador, *inimigo);

    cout << "\nAgora, com a Rainha das Cinzas derrotada, você enfrenta uma escolha dificil...\n";
    cout << "A Rainha das Cinzas, antes de morrer, sussurra: 'Deixe para tras sua missão. Os humanos não carregam fardos... Seja como eles.'\n";
    cout << "Você pode escolher: \n";
    cout << "1. **Salvar a floresta** - Usar a **Semente Ancestral** e **todas as habilidades adquiridas** para restaurar o equilíbrio e renascer como guardiã definitiva da natureza.\n";
    cout << "2. **Se corromper e se tornar humana** - Deixar para trás a missão e seguir a Rainha das Cinzas, tornando-se humana e abandonando seu papel como guardiã da natureza.\n";
    
    // Receber a escolha do jogador
    string escolha;
    cout << "Escolha 1 ou 2: ";
    cin >> escolha;

    if (escolha == "1") {
        cout << "\nVoce decide salvar a floresta. Usando a **Semente Ancestral** e todas as habilidades adquiridas, você restaura o equilíbrio da natureza.\n";
        cout << "Como guardia definitiva da natureza, você vê a floresta florescer completamente, e a paz retorna ao mundo.\n";
        cout << "A energia da floresta flui através de você, tornando-se um ser imortal, um símbolo da restauração e da força da natureza.\n";
        cout << "A missao 'Renascer ou Cair' foi completada com sucesso. A floresta está salva e sua jornada como guardiã continua.\n";
    } else if (escolha == "2") {
        cout << "\nVocê decide seguir o caminho da Rainha das Cinzas, se tornando humana e abandonando sua missão como guardiã da natureza.\n";
        cout << "Agora, você sente **sede, fome, ambição, medo** pela primeira vez, e o peso da humanidade se instala em seu coração.\n";
        cout << "Mas, ao perceber tarde demais que se tornou parte da destruição, você entende que **não há como voltar atrás**.\n";
        cout << "Você se torna parte da escuridão que corrompeu o mundo, e a natureza paga o preço pela sua escolha.\n";
        cout << "A missao 'Renascer ou Cair' termina em tragedia. A floresta morreu, e você é agora parte do mal que ela produziu.\n";
    } else {
        cout << "\nEscolha invalida. A missao falhou. A floresta permanece em ruínas.\n";
    }

    // Conclusão da missão
    jogador->concluirMissao(missaoAtual);
    jogador->ganharExperiencia(100);
    jogador->subirNivel();
}