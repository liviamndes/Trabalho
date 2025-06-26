#ifndef MISSAO_H
#define MISSAO_H

#include <iostream>
#include <string>
#include "Habilidade.h"

using namespace std;
class Jogador;

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
            cout << "........................................................\n";
        }

        virtual void concluir() { 
            concluida = true;
            cout << "\n====================================================\n";
            cout << "          Missao concluida: " << titulo << "          \n";
            cout << "====================================================\n";
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
        
        void concluir() override {
            Missao::concluir();
            cout << "\nVoce derrotou o inimigo e a fada foi curada!\n Com suas forcas restauradas, ela retorna para o Santuario em seguranca.\n";
            cout << "Voce a acompanha e sente que esta apenas no inicio de sua jornada...\n\n";
        }
};

// Clareira Corrompida
class PurificarTerra : public Missao {
    public:
        PurificarTerra() : Missao("Purificacao da Clareira", "Desbloqueie a magia para restaurar a terra corrompida.", new RugidoDaNatureza(), new GarrasDaTerra()) {}

        void concluir() override {
            Missao::concluir();
            cout << "Voce restaurou a clareira! A natureza agradece.\n\n";
        }
};

//Lago das lagrimas
class CurarLago : public Missao {
    public:
        CurarLago() : Missao("Cure o Lago das Lagrimas", "Afaste as almas perdidas para encontrar o cristal da agua e curar o lago.", new ChuvaPurificadora(), new JorroEncantado()) {}

        void concluir() override {
            Missao::concluir();
            cout << "Voce curou o lago!As almas perdidas encontram paz no renascimento do lago, sendo libertas enfim da dor.\n\n";
        }
};


// Base industrial
class SabotarIndustria : public Missao {
    public:
        SabotarIndustria() : Missao("Contra a Exploracao", "Infiltre-se e sabote maquinas destrutivas.", new AuraDaResistencia(), new RajadaEnergetica()) {}

        void concluir() override {
            Missao::concluir();
            cout << "Voce sabotou os sistemas industriaisl!\n\n";
        }
};

// Coração da floresta
class MissaoFinal : public Missao {
        public:
        MissaoFinal() : Missao("O Destino da Floresta", "Ative os pedestais de energia pura para restaurar a floresta.", 
            new RenascimentoDaFloresta(), new ExplosaoCelestial()) {}

        void Dialogo() {
            cout << "\n A Rainha das Cinzas esta bem diante de voce..\n\n";
            cout << "\nVoce lutou tanto pequena fada.. mas por quê?";
            cout << "\nSera que não ve eles iram destruir a floresta novamente. Tudo sera em vao";
            cout << "\nE os humanos? Ah, os humanos... eles nao carregam fardos como você. Eles vivem... livres.";
            cout << "\nOlhe para si mesma... ferida, cansada, sempre lutando por um mundo que nunca te deu escolha.";
            cout << "\nVoce realmente quer ser escrava dessa floresta para sempre?";

            cout<<"\n\nA rainha se aproxima, sua voz eh calma mas afiada. Sua olhar expressa conforto.\n\n";

            cout<<"\nJa imaginou sentir o calor do sol semprecisar protege-lo? Comer sem precisar buscar sustento para todos?";
            cout<<"\nVoce realmente quer ser escrava dessa floresta para sempre?";
            cout<<"\nE se eu te dissesse que há outro caminho? Um onde voce nao precisa carregar esse fardo";
            cout <<"\nVenha comigo. Seja como eles.Voce nunca teve escolha antes... mas agora tem.";
        }

        void escolha(Jogador& jogador);
        void concluirSalvacao(Jogador& jogador);
        void concluirHumanidade(Jogador& jogador);
};


#endif