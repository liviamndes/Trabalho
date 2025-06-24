#ifndef MISSAO_H
#define MISSAO_H

#include <iostream>
#include <string>
#include "Habilidade.h"
#include "Personagem.h"

using namespace std;

class Missao{
    protected:
        string titulo;
        string descricao;
        bool concluida;
        Habilidade* habilidadeDefesa;
        Habilidade* habilidadeAtaque;
    public:
        Missao(string t, string d, Habilidade* def, Habilidade* atk) 
            : titulo{t}, descricao{d}, habilidadeDefesa{def}, habilidadeAtaque{atk}, concluida{false} {}
        virtual ~Missao() { }

        void iniciar() {
            cout << "Missao iniciada: " << titulo << "\n";
            cout << "Objetivo: " << descricao << "\n";
        }

        virtual void concluir(Jogador& jogador) { 
            concluida = true; 
            cout << "\nMissão concluída: " << titulo << "\n";
            cout << "Habilidades desbloqueadas:\n";
            jogador.adicionarHabilidade(habilidadeDefesa);
            jogador.adicionarHabilidade(habilidadeAtaque);
        }

        Habilidade* getHabilidadeDefesa() { return habilidadeDefesa; }
        Habilidade* getHabilidadeAtaque() { return habilidadeAtaque; }
        string getTitulo() { return titulo; }
        bool estaConcluida() const { return concluida; }
};

// Missões especificas para cada cenario

// Bosque das Fadas
class ResgatarFada : public Missao{
    public:
        ResgatarFada() : Missao("Retorno ao Santuario", "Ajude a fada ferida a voltar para o santuario.", 
            new EscudoDeLuz(), new DardoLuminoso()) {}
        
        void concluir(Jogador& jogador) override {
            Missao::concluir(jogador);
            cout << "Voce resgatou a fada ferida e garantiu sua segurança!";
        }
};

// Clareira Corrompida
class PurificarTerra : public Missao {
    public:
        PurificarTerra() : Missao("Purificação da Clareira", "Desbloqueie a magia para restaurar a terra corrompida.", new RugidoDaNatureza(), new GarrasDaTerra()) {}

        void concluir(Jogador& jogador) override {
            Missao::concluir(jogador);
            cout << "Você restaurou a clareira! A natureza agradece.\n";
        }
};

//Lago das lagrimas
class CurarLago : public Missao {
    public:
        CurarLago() : Missao("Cure o Lago das Lagrimas", "Afaste as almas perdidas para encontrar o cristal da água e curar o lago.", new ChuvaPurificadora(), new JorroEncantado()) {}

        void concluir(Jogador& jogador) override {
            Missao::concluir(jogador);
            cout << "Você curou o lago!As almas perdidas encontram paz no renascimento do lago, sendo libertas enfim da dor.\n";
        }
};


// Base industrial
class SabotarIndustria : public Missao {
    public:
        SabotarIndustria() : Missao("Contra a Exploração", "Infiltre-se e sabote máquinas destrutivas.", new AuraDaResistencia(), new RajadaEnergetica()) {}

        void concluir(Jogador& jogador) override {
            Missao::concluir(jogador);
            cout << "Você sabotou os sistemas industriais e derrotou o general!\n";
        }
};


// Coração da floresta
class MissaoFinal : public Missao {
        public:
        MissaoFinal() : Missao("O Destino da Floresta", "Ative os pedestais de energia pura para restaurar a floresta.", 
            new RenascimentoDaFloresta(), new ExplosaoCelestial()) {}

        void Dialogo(Jogador& jogador) {
            cout << "\n A Rainha das Cinzas está bem diante de você..\n\n";
            cout << "\nVocê lutou tanto pequena fada.. mas por quê?";
            cout << "\nSerá que não vê eles iram destruir a floresta novamente. Tudo será em vão";
            cout << "\nE os humanos? Ah, os humanos... eles não carregam fardos como você. Eles vivem... livres.";
            cout << "\nOlhe para si mesma... ferida, cansada, sempre lutando por um mundo que nunca te deu escolha.";
            cout << "\nVocê realmente quer ser escrava dessa floresta para sempre?";

            cout<<"\n\nA rainha se aproxima, sua voz é calma mas afiada. Sua olhar expressa conforto.\n\n";

            cout<<"\nJá imaginou sentir o calor do sol semprecisar protegê-lo? Comer sem precisar buscar sustento para todos?";
            cout<<"\nVocê realmente quer ser escrava dessa floresta para sempre?";
            cout<<"\nE se eu te dissesse que há outro caminho? Um onde você não precisa carregar esse fardo";
            cout <<"\nVenha comigo. Seja como eles.Você nunca teve escolha antes... mas agora tem.";
        }

        void escolha(Jogador& jogador){
            int escolha;

            cout << "\nESCOLHA SEU DESTINO:";
            cout << "\n1.Usar a semente Ancestral e salvar a floresta.";
            cout <<"\n2.Aceitar a oferta da Rainha e se tornar humana.";
            
            cout << "Digite sua escolha (1 ou 2): ";
            cin >> escolha;

            if (escolha == 1) {
                concluirSalvacao(jogador);
            } else if (escolha == 2) {
                concluirHumanidade(jogador);
            } else {
                cout << "Escolha inválida! A Rainha aguarda sua resposta...\n";
            }
        }

        void concluirSalvacao(Jogador& jogador){
            concluida = true;
            cout << "Você salvou a floresta e restaurou o equilíbrio do mundo! Missão concluída.\n";
            cout << "Habilidades desbloqueadas:\n";
            jogador.adicionarHabilidade(habilidadeDefesa);
            jogador.adicionarHabilidade(habilidadeAtaque);
        }

        void concluirHumanidade(Jogador& jogador){
            concluida = true;
            cout << "\nVocê escolheu abandonar sua missão...\n";
            cout << "A Rainha sorri. \"Muito bem... bem-vinda ao mundo real.\"\n";
            cout << "Você agora sente sede, fome, ambição e medo pela primeira vez.\n";
            cout << "Mas agora é tarde. Você faz parte da destruição.\n";  
        }

};


#endif