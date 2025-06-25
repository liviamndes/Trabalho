//Descrição: Controla as batalhas em que jogadores e inimigos se alternam realizando ações (ataques, habilidades, defesas). Cada participante age em seu turno.
//Exemplos de classes: Batalha, Turno, Habilidade.

#ifndef BATALHAPORTURNOS_H
#define BATALHAPORTURNOS_H

#include"Habilidade.h"
#include<iostream>
#include"Personagem.h"

using namespace std;

class BatalhaPorTurnos{
    private:
        Jogador& jogador;
        Inimigo& inimigo;
        bool batalhaEmAndamento;
        bool jogadorFugiu = false;

    public:
        BatalhaPorTurnos(Jogador& j, Inimigo& i) : jogador(j), inimigo(i), batalhaEmAndamento(true){}
        bool fuga() { return jogadorFugiu; }
        void turnoJogador(){
            jogador.aplicarRegeneracaoPorTurno();

            cout << "\n\n---Sua vez!---\nVida do jogador:" << jogador.getVida() << "\n";
            cout << "Vida do " << inimigo.getNome() << ": " << inimigo.getVida() << "\n";
            
            cout << "\n\n\nEscolha sua acao: \n";
            cout << "1 - Atacar\n";
            cout << "2 - Usar Item\n";
            cout << "3 - Usar habilidade(defesa ou ataque)\n";
            cout << "4 - Fugir\n";
            int escolha;
            cin >> escolha;
            bool b = false;
            switch (escolha) {
            case 1:
                jogador.atacar(inimigo);
                break;
            case 2:
                b = jogador.listarItensDoInventario();
                
                if(b) {
                    cout << "Digite o nome do item para usar: ";
                    cin.ignore();
                    {
                        string nomeItem;
                        getline(cin, nomeItem);
                        jogador.usarItemDoInventario(nomeItem);
                    }
                    break;
                }
                
            case 3:
                if(jogador.getTemHabilidade()) {
                    jogador.listarHabilidades();
                    cout << "Escolha a habilidade para usar pelo indice: ";
                    int habilidadeEscolha;
                    cin >> habilidadeEscolha;
                    jogador.usarHabilidade(habilidadeEscolha, &jogador, &inimigo);
                }
                else {
                    cout << "Nenhuma habilidade desbloqueada.\n";
                }
                break;
            case 4: 
                cout << "Voce fugiu da batalha!\n";
                batalhaEmAndamento = false;
                jogadorFugiu = true;
                break;
            default:
                cout << "Escolha invalida!\n";
            }

            jogador.resetarModificadorDano();
        }

        void turnoInimigo() {
        if (batalhaEmAndamento && inimigo.getVida()>0) {
            cout << "\n\n--- Turno do " << inimigo.getNome() << " ---\n";
            inimigo.atacar(jogador);
        }
        }

        bool iniciar(){
            cout << "\n----Inicio da batalha: " << jogador.getNome() << " vs " << inimigo.getNome() << " ----\n";

            while(batalhaEmAndamento){
                turnoJogador();

                if(inimigo.getVida() <= 0){
                    cout<< "\nVoce derrotou o " << inimigo.getNome() << "!\n";
                    batalhaEmAndamento = false;
                    cout << "\n\n----Fim da Batalha---\n\n";

                    return true;
                }

                turnoInimigo();

                if (jogador.getVida() <= 0) {
                    cout << "pelo fungo!";
                    cout << "\n\n---- Fim da Batalha ----\n\n";
                    batalhaEmAndamento = false;
                    cout << "Recuperando forcas...\n";
                    jogador.recuperarVida(50); 
                    cout << "\nPressione Enter para tentar novamente...\n";
                    cin.get();
                    return false;
                }
            }

            return false;
        }
};

#endif