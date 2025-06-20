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
            //case 3:
            // aqui tenho que descobrir como fazer isso de usar a habilidade na batalha
            case 3: //trocar 3 p 4, so ta assim p compilar se precisar.
                cout << "Você fugiu da batalha!\n";
                batalhaEmAndamento = false;
                break;
            default:
                cout << "Escolha inválida!\n";
            }
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