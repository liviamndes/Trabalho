#include <iostream>
#include "Personagem.h"
#include "Cenario.h"
#include "Missao.h"
#include "BatalhaPorTurnos.h"
#include "QuebraCabeca.h"
#include "Armadilha.h"
#include "Inventario.h"
#include <string>
#include <algorithm>
using namespace std;

void Cenario::iniciarMissao(Jogador *jogador)
{
    cout << "Voce chegou ao " << nome << "\n";
    cout << descricao << "\n";
    missaoAtual->iniciar();
}

ResultadoBatalha Cenario ::iniciarBatalha(Jogador &jogador, Inimigo &inimigo)
{
    BatalhaPorTurnos batalha(jogador, inimigo);
    bool venceu = batalha.iniciar();

    ResultadoBatalha resultado;
    resultado.venceu = venceu;
    resultado.fugiu = batalha.fuga();
    if (venceu)
    {
        Habilidade *novaHabilidadeDefesa = nullptr;
        Habilidade *novaHabilidadeAtaque = nullptr;

        if (nome == "Bosque das Fadas")
        {
            novaHabilidadeDefesa = new EscudoDeLuz();
            novaHabilidadeAtaque = new DardoLuminoso();
        }
        else if (nome == "Clareira Corrompida")
        {
            novaHabilidadeDefesa = new RugidoDaNatureza();
            novaHabilidadeAtaque = new GarrasDaTerra();
        }
        else if (nome == "Lago das Lagrimas")
        {
            novaHabilidadeDefesa = new ChuvaPurificadora();
            novaHabilidadeAtaque = new JorroEncantado();
        }
        else if (nome == "Base da Industria")
        {
            novaHabilidadeDefesa = new AuraDaResistencia();
            novaHabilidadeAtaque = new RajadaEnergetica();
        }
        else if (nome == "Coracao da Floresta")
        {
            novaHabilidadeDefesa = new RenascimentoDaFloresta();
            novaHabilidadeAtaque = new ExplosaoCelestial();
        }

        if (novaHabilidadeDefesa != nullptr && novaHabilidadeAtaque != nullptr)
        {
            novaHabilidadeDefesa->desbloquear();
            novaHabilidadeAtaque->desbloquear();
        }
    }

    return resultado;
}

void BosqueDasFadas::explorar(Jogador *jogador)
{
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr)
    {
        // Caso a missão ainda nao tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
    }
    cout << "\nVoce avanca pelo Bosque das Fadas.\n";
    cout << "Entre as arvores magicas, voce encontra uma pequena fada ferida.\n";
    cout << "As asas dela estao danificadas e ela precisa de sua ajuda.\n";
    cout << "Para curar a fada, voce precisara preparar uma Pocao de Cura.\n";

    cout << "\n\nPressione Enter para continuar...\n\n";
    cin.get();

    char resposta = 'N';

    // Loop para garantir a coleta de ingredientes
    while (resposta != 'S' && resposta != 's')
    {
        cout << "\nDeseja coletar ingredientes para a Pocao de Cura? (S/N): ";
        cin >> resposta;

        if (resposta == 'S' || resposta == 's')
        {
            cout << "\nVoce percorre o bosque em busca de folhas e flores encantadas...\n";
            cout << "Voce coletou os ingredientes necessarios para preparar a Pocao de Cura.\n";
            item->desbloquear();
            jogador->adicionarItemAoInventario(item);
            break;
        }
        else
        {
            cout << "\nSem a pocao, voce nao conseguira ajudar a fada.\n";
            cout << "Tente novamente apos refletir sobre sua decisao.\n";
        }
    }
    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.ignore();
    cin.get();

    // Ajudar a fada ferida
    bool fadaCurada = false;
    while (!fadaCurada)
    {
        cout << "\nDeseja curar a fada ferida? (S/N): ";
        cin >> resposta;

        if (resposta == 'S' || resposta == 's')
        {
            cout << "A pocao brilha suavemente. A luz da cura envolve a fada. Ela sorri, aliviada.\n";
            jogador->ganharExperiencia(50);
            fadaCurada = true;
        }
        else
        {
            cout << "Voce ainda precisa usar a Pocao de Cura para ajudar a fada!\n";
        }
    }

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.ignore();
    cin.get();

    // Enfrentando inimigo: morcego
    cout << "\n----------------------------------------------------------------------\n";
    cout << "De repente, um Morcego emerge das copas das arvores e avanca sobre voce!\n";
    cout << "As suas asas batem com furia enquanto ele tenta te atacar.\n";
    cout << "Prepare se para a batalha!\n";
    cout << "------------------------------------------------------------------------\n\n";

    ResultadoBatalha resultado;

    do
    {
        resultado = iniciarBatalha(*jogador, *inimigo);
        if (resultado.fugiu)
        {
            break; // Sai do loop se fugiu
        }
    } while (!resultado.venceu);

    jogador->subirNivel();
    jogador->concluirMissao(missaoAtual);

    cout << "\n\nPressione ENTER para avancar...\n\n";
    cin.ignore();
    cin.get();
    cout << "\n\n";
}

void ClareiraCorrompida::explorar(Jogador *jogador)
{
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr)
    {
        // Caso a missão ainda nao tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
    }

    cout << "Voce adentra uma clareira onde tudo parece estar morrendo...\n";
    cout << "As arvores estao retorcidas, o chao coberto de neblina negra.\n";
    cout << "Uma energia estranha pulsa a cada passo.\n";
    cout << "No centro, um enigma bloqueia sua passagem.\n";

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.get();

    // Quebra cabeça
    jogador->definirQuebraCabeca(quebra);
    bool resolveu = false;
    
    cout << "\n\nteste1";

    while (resolveu == false)
    {
        try
        {
            cout << "\n\ntest2";
            resolveu = jogador->resolverQuebraCabecaAtual();
        }
        catch (QuebraCabecaNaoResolvidoException &e)
        {
            cout << "\n\nteste3";
            cout << e.what() << "\n";
            cout << "Aperte ENTER para tentar novamente.\n";
            cin.get();
        }
    }

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.get();

    // Receber item de recompensa
    if (resolveu)
    {
        item->desbloquear();
        jogador->adicionarItemAoInventario(item);

        string resposta;
        bool clareiraRestaurada = false;
        while (!clareiraRestaurada)
        {
            cout << "\nA terra ao redor comeca a reagir a presenca da " << item->getNome() << ".\n\n";
            cout << "Combinar " << item->getNome() << " com seus conhecimentos para purificar a clareira? (S/N): ";
            cin >> resposta;
            if (resposta == "S" || resposta == "s")
            {
                cout << "\nUma onda de energia pura se espalha pela clareira...\n";
                cout << "A corrupcao da terra finalmente comeca a recuar!\n";
                clareiraRestaurada = true;
            }
            else
            {
                cout << "\nSem o aproveitamento da" << item->getNome() << ", a clareira continua corrompida...\n";
                cout << "Voce sente que ainda ha algo a ser feito.\n";
            }
        }
    }

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.ignore();
    cin.get();

    // Enfrentando inimigo: Fungo
    cout << "\n-----------------------------------------------------------------------------\n";
    cout << "                  Voce comeca a sentir uma presenca...\n";
    cout << " Do solo corrompido, um Fungo gigantesco emerge, coberto por esporos venenosos!\n";
    cout << "                 Prepare-se para lutar pela sua vida!\n";
    cout << "\n-----------------------------------------------------------------------------\n\n";

    ResultadoBatalha resultado;
    do
    {
        resultado = iniciarBatalha(*jogador, *inimigo);
        if (resultado.fugiu)
        {
            cout << "\nVoce escapou por pouco... mas o perigo ainda esta a solta.\n";
            break; // Sai do loop se fugiu
        }
    } while (!resultado.venceu);

    jogador->subirNivel();
    jogador->concluirMissao(missaoAtual);
    cout << "\nPressione ENTER para avancar...\n";
    cin.ignore();
    cin.get();
    cout << "\n\n\n\n";
}
void LagodasLagrimas::explorar(Jogador *jogador)
{
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr)
    {
        // Caso a missão ainda nao tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
    }
    cout << "\nAs margens do lago exalam tristeza...\n";
    cout << "As aguas estao turvas e geladas, e uma nevoa cobre tudo ao redor.\n";
    cout << "De repente, uma presenca gelada o envolve...\n";

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.ignore();
    cin.get();

    // Enfrentando inimigo: Almas perdias
    cout << "\n-----------------------------------------------------------------------------\n";
    cout << "             As Almas Perdidas surgem e comecam a cerca-lo!\n";
    cout << "                     Prepare-se para a batalha!\n";
    cout << "-----------------------------------------------------------------------------\n\n";

    ResultadoBatalha resultado;
    do
    {
        resultado = iniciarBatalha(*jogador, *inimigo);
        if (resultado.fugiu)
        {
            cout << "\nVoce escapou por pouco... mas o perigo ainda esta a solta.\n";
            break; // Sai do loop se fugiu
        }
    } while (!resultado.venceu);

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.ignore();
    cin.get();

    // Jogador recebe recompensa
    string resposta, purificar;

    cout << "Voce encontra um brilho na agua...\n";
    cout << "Voce se aproxima e encontra o " << item->getNome() << "\n";
    cout << item->getDescricao() << "\n";
    item->desbloquear();
    cout << "Voce deseja colocar o item no seu inventario? (S/N): ";

    cin >> resposta;
    while (resposta != "S" && resposta != "s" && resposta != "N" && resposta != "n")
    {
        cout << "Insira uma resposta valida. Deseja pegar o item? (S/N):";
        cin >> resposta;
    }
    if (resposta == "S" || resposta == "s")
    {
        cout << "Voce agora possui o Cristal da Agua!\n";
        jogador->adicionarItemAoInventario(item);
        cout << "\nDigite 'PURIFICAR' para salvar o lago: ";
        cin >> purificar;
        while (purificar != "PURIFICAR")
        {
            cout << "Algo esta errado, tente novamente para concluir a missao!\n";
            cin >> purificar;
        }
        cout << "\nUma luz azulada invade o lago...\n";
        cout << "As aguas se purificam e a nevoa desaparece.\n";
        cout << "O Lago das Lagrimas brilha novamente!\n";
    }else{
        cout << "Tem certeza?Esse item pode ser essencial para salvar o lago.\n";
        cout << "Deseja recosiderar e pegar o item ? (S/N)\n";
        cin >> resposta;
        if (resposta == "S" || resposta == "s"){
            cout << "Saiba que voce tomou a decisão certa.";
            jogador->adicionarItemAoInventario(item);
            cout << "\nDigite 'PURIFICAR' para salvar o lago: ";
            cin >> purificar;
            while (purificar != "PURIFICAR")
            {
                cout << "Algo esta errado, tente novamente para concluir a missao!\n";
                cin >> purificar;
            }
            cout << "\nUma luz azulada invade o lago...\n";
            cout << "As aguas se purificam e a nevoa desaparece.\n";
            cout << "O Lago das Lagrimas brilha novamente!\n";
        }else{
            cout << "Entendido. Voce decidiu seguir sem o Cristal da Agua.\n";
        }

    }

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.ignore();
    cin.get();

    // Armadilha final
    cout << "\nAntes de sair do lago, voce encontra uma 'Pocao Misterio' flutuando na margem...\n";
    cout << "\nAs cores mudam: ora azul profunda, ora vermelha intensa, como se escondesse segredos.";
    cout << "Talvez ela te fortaleca... ou nao.\n";
    cout << "Sem saber se eh presente ou armadilha do destino voce bebe a 'Pocao Misterio'\n";
    armadilha->ativar(jogador);

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.get();

    // Concluir missão
    jogador->ganharExperiencia(30);
    jogador->subirNivel();
    jogador->concluirMissao(missaoAtual);
}
void BaseIndustria::explorar(Jogador *jogador)
{
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr)
    {
        // Caso a missão ainda nao tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
    }

    // Infiltração e hackeamento dos sistemas de segurança mágicos
    cout << "Voce se aproxima do centro de controle da base...\n";
    cout << "Para acessar a sala do General, voce precisa desarmar os dispositivos de seguranca para infiltrar se com sucesso.\n";

    // O jogador precisa resolver quebra-cabeças para hackear e desarmar dispositivos
    cout << "Desarmando os feiticos magicos e hackeando os sistemas de seguranca...\n";

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.ignore();
    cin.get();

    jogador->definirQuebraCabeca(quebra);
    bool resolveu = false;
    cout << "teste\n\n";

    while (resolveu == false)
    {
        try
        {
            cout << "teste\n\n";
            resolveu = jogador->resolverQuebraCabecaAtual();
        }
        catch (QuebraCabecaNaoResolvidoException &e)
        {
            cout << e.what() << "\n";
            cout << "Aperte ENTER para tentar novamente.\n";
            cin.get();
        }
    }

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.get();

    item->desbloquear();
    jogador->adicionarItemAoInventario(item);

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.get();

    // Inimigo: general
    cout << "Voce conseguiu hackear os sistemas e desativar os feiticos magicos! O caminho agora esta livre para a infiltracao.\n";
    cout << "Mas, ao chegar mais perto do centro de controle, você percebe que algo esta errado...\n";
    cout << "O General da Base Industria Sombria estava esperando por voce o tempo todo. Ele e o comandante das forcas de seguranca da base e possui grande poder, tanto tecnologico quanto magico.\n";
    cout << "Com sua presenca imponente e sua tecnologia avancada, ele ira lutar ate o fim para proteger os segredos da base.\n";
    cout << "Voce precisa se preparar para uma batalha intensa contra ele, que usa feiticarias e tecnologias para aumentar sua forca. Prepare se!\n";

    cout << "O General usa sua magia para invocar um escudo impenetravel ao redor de si, e sistemas automaticos começam a atacar de todas as direcoes!\n";
    cout << "Voce sente o peso da batalha, mas com a forca adquirida nas missoes anteriores, voce esta pronto para enfrenta lo.\n";
    cout << "A luta sera dificil, mas se voce usar todas as suas habilidades e itens, pode conseguir derrota lo e destruir a ameaca da Base Industria Sombria.\n";

    ResultadoBatalha resultado;
    do
    {
        resultado = iniciarBatalha(*jogador, *inimigo);
        if (resultado.fugiu)
        {
            cout << "\nVoce escapou por pouco... mas o perigo ainda esta a solta.\n";
            break; // Sai do loop se fugiu
        }
    } while (!resultado.venceu);

    cout << "\n\nPressione ENTER para continuar...\n\n";
    cin.get();
    // Concluir missão
    jogador->concluirMissao(missaoAtual);
    jogador->ganharExperiencia(50);
    jogador->subirNivel();
}
void CoracaoDaFloresta::explorar(Jogador *jogador)
{
    // Inicia a fase
    if (jogador->getMissaoAtual() == nullptr)
    {
        // Caso a missão ainda nao tenha sido iniciada, vamos iniciar a missão
        jogador->iniciarMissao(missaoAtual);
    }

    cout << "Voce chega ao Coração da Floresta. O ar esta pesado, e a energia da natureza esta se esvaindo.\n";
    cout << "A Rainha das Cinzas corrompeu a floresta e controla a terra com sua magia negra.\n";
    cout << "Para restaurar a floresta, voce precisa ativar os pedestais magicos espalhados pela regiao.\n";
    cout << "Cada pedestal exige que voce use as habilidades adquiridas nas fases anteriores.\n";

    ResultadoBatalha resultado;
    do
    {
        resultado = iniciarBatalha(*jogador, *inimigo);
        if (resultado.fugiu)
        {
            cout << "\nVoce escapou por pouco... mas o perigo ainda esta a solta.\n";
            break; // Sai do loop se fugiu
        }
    } while (!resultado.venceu);

    cout << "\nAgora, com a Rainha das Cinzas derrotada, você enfrenta uma escolha dificil...\n";
    cout << "A Rainha das Cinzas, antes de morrer, sussurra: 'Deixe para tras sua missao. Os humanos nao carregam fardos... Seja como eles.'\n";
    cout << "Voce pode escolher: \n";
    cout << "1. **Salvar a floresta** - Usar a **Semente Ancestral** e **todas as habilidades adquiridas** para restaurar o equilíbrio e renascer como guardia definitiva da natureza.\n";
    cout << "2. **Se corromper e se tornar humana** - Deixar para trás a missao e seguir a Rainha das Cinzas, tornando se humana e abandonando seu papel como guardia da natureza.\n";

    // Receber a escolha do jogador
    string escolha;
    cout << "Escolha 1 ou 2: ";
    cin >> escolha;

    if (escolha == "1")
    {
        cout << "\nVoce decide salvar a floresta. Usando a **Semente Ancestral** e todas as habilidades adquiridas, voce restaura o equilibrio da natureza.\n";
        cout << "Como guardia definitiva da natureza, voce ve a floresta florescer completamente, e a paz retorna ao mundo.\n";
        cout << "A energia da floresta flui através de voce, tornando-se um ser imortal, um simbolo da restauracao e da força da natureza.\n";
        cout << "A missao 'Renascer ou Cair' foi completada com sucesso. A floresta esta salva e sua jornada como guardia continua.\n";
    }
    else if (escolha == "2")
    {
        cout << "\nVoce decide seguir o caminho da Rainha das Cinzas, se tornando humana e abandonando sua missao como guardia da natureza.\n";
        cout << "Agora, voce sente **sede, fome, ambicao, medo** pela primeira vez, e o peso da humanidade se instala em seu coracao.\n";
        cout << "Mas, ao perceber tarde demais que se tornou parte da destruicao, você entende que **não ha como voltar atras**.\n";
        cout << "Voce se torna parte da escuridao que corrompeu o mundo, e a natureza paga o preco pela sua escolha.\n";
        cout << "A missao 'Renascer ou Cair' termina em tragedia. A floresta morreu, e você eh agora parte do mal que ela produziu.\n";
    }
    else
    {
        cout << "\nEscolha invalida. A missao falhou. A floresta permanece em ruinas.\n";
    }

    // Conclusão da missão
    jogador->concluirMissao(missaoAtual);
    jogador->ganharExperiencia(100);
    jogador->subirNivel();
}