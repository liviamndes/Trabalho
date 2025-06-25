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
            cout << "\nMissao concluida: " << titulo << "\n";
            cout << "Habilidades desbloqueadas:\n";
            cout << "   -> " <<getHabilidadeAtaque()->getNome() << endl;
            cout << "   -> " <<getHabilidadeDefesa()->getNome() << endl;
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
            cout << "\nA fada foi curada! Com suas forcas restauradas, ela retorna para o Santuario em seguranca.\n";
            cout << "Voce a acompanha e sente que esta apenas no inicio de sua jornada...\n\n";
        }
};

// Clareira Corrompida
class PurificarTerra : public Missao {
    public:
        PurificarTerra() : Missao("Purificacao da Clareira", "Desbloqueie a magia para restaurar a terra corrompida.", new RugidoDaNatureza(), new GarrasDaTerra()) {}

        void concluir() override {
            Missao::concluir();
            cout << "Voce restaurou a clareira! A natureza agradece.\n";
        }
};

//Lago das lagrimas
class CurarLago : public Missao {
    public:
        CurarLago() : Missao("Cure o Lago das Lagrimas", "Afaste as almas perdidas para encontrar o cristal da água e curar o lago.", new ChuvaPurificadora(), new JorroEncantado()) {}

        void concluir() override {
            Missao::concluir();
            cout << "Voce curou o lago!As almas perdidas encontram paz no renascimento do lago, sendo libertas enfim da dor.\n";
        }
};


// Base industrial
class SabotarIndustria : public Missao {
    public:
        SabotarIndustria() : Missao("Contra a Exploração", "Infiltre-se e sabote máquinas destrutivas.", new AuraDaResistencia(), new RajadaEnergetica()) {}

        void concluir() override {
            Missao::concluir();
            cout << "Você sabotou os sistemas industriais e derrotou o general!\n";
        }
};

// vai precisar separar as declarações que envolvem jogador e fazer isso apenas em Personagem.cpp ou Personagem.h
// tipo o que eu fiz na funcao concluirMissao() -> criei
// concluir() -> agora nao tem mais parametros de jogador

// Coração da floresta
class MissaoFinal : public Missao {
        public:
        MissaoFinal() : Missao("O Destino da Floresta", "Ative os pedestais de energia pura para restaurar a floresta.", 
            new RenascimentoDaFloresta(), new ExplosaoCelestial()) {}

        void Dialogo() {
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

        void escolha(Jogador& jogador);
        void concluirSalvacao(Jogador& jogador);
        void concluirHumanidade(Jogador& jogador);
};


#endif