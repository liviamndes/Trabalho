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
    public:
        BatalhaPorTurnos(Jogador& j, Inimigo& i) : jogador(j), inimigo(i), batalhaEmAndamento(true){}

        void turnoJogador(){
            jogador.aplicarRegeneracaoPorTurno();

            cout << "Sua vez!\nVida do jogador:" << jogador.getVida() << "\n";
            cout << "Vida do" << inimigo.getNome() << ":" << inimigo.getVida() << "\n";
            
            cout << "Escolha sua acao: \n";
            cout << "1 - Atacar\n";
            cout << "2 - Usar Item\n";
            cout << "3 - Usar habilidade(defesa ou ataque)\n";
            cout << "4 - Fugir\n";
            int escolha;
            cin >> escolha;

            switch (escolha) {
            case 1:
                jogador.atacar(inimigo);
                break;
            case 2:
                jogador.listarItensDoInventario();
                cout << "Digite o nome do item para usar: ";
                cin.ignore();
                {
                    string nomeItem;
                    getline(cin, nomeItem);
                    jogador.usarItemDoInventario(nomeItem);
                }
                break;
            case 3:
                jogador.listarHabilidades();
                cout << "Escolha a habilidade para usar: ";
                int habilidadeEscolha;
                cin >> habilidadeEscolha;
                jogador.usarHabilidade(habilidadeEscolha, &jogador, &inimigo);
                break;
            case 4: 
                cout << "Você fugiu da batalha!\n";
                batalhaEmAndamento = false;
                break;
            default:
                cout << "Escolha inválida!\n";
            }

            jogador.resetarModificadorDano();
        }

        void turnoInimigo() {
        if (batalhaEmAndamento && inimigo.getVida()>0) {
            cout << "\n--- Turno do " << inimigo.getNome() << " ---\n";
            inimigo.atacar(jogador);
        }
        }

        void iniciar(){
            cout << "\n----Início da batalha:" << jogador.getNome() << "vs" << inimigo.getNome() << "----\n";

            while(batalhaEmAndamento){
                turnoJogador();

                if(inimigo.getVida() <= 0){
                    cout<< "\nVocê derrotou o " << inimigo.getNome() << "!\n";
                    batalhaEmAndamento = false;
                    break;
                }

                turnoInimigo();

                if (jogador.getVida() <= 0) {
                cout << "\nVocê foi derrotado pelo " << inimigo.getNome() << "!\n";
                batalhaEmAndamento = false;
                break;
            }
            }

            cout << "\n----Fim da Batalha---\n";
        }
};

#endif