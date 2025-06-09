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
        string descrição;
        bool concluida;
        Habilidade* habilidadeDefesa;
        Habilidade* habilidadeAtaque;
    public:
        Missao(string t, string d, Habilidade* def, Habilidade* atk) 
            : titulo{t}, descrição{d}, habilidadeDefesa{def}, habilidadeAtaque{atk}, concluida{false} {}
        virtual ~Missao() { }

        void iniciar() {
            cout << "Missao iniciada: " << titulo << "\n";
            cout << "Objetivo: " << descrição << "\n";
        }
        virtual void concluir() { concluida = true; }
        Habilidade* getHabilidadeDefesa() { return habilidadeDefesa; }
        Habilidade* getHabilidadeAtaque() { return habilidadeAtaque; }

        bool estaConcluida() const { return concluida; }
};

// Missões especificas para cada cenario

// Bosque das Fadas
class ResgatarFada : public Missao{
    public:
        ResgatarFada() : Missao("Retorno ao Santuario", "Ajude a fada ferida a voltar para o santuario.", 
            new EscudoDeLuz(), new DardoLuminoso()) {}
        
        void concluir() override {
            concluida = true;
            cout << "voce resgatou a fada ferida e garantiu sua segurança! Missao concluoda.\n";
            cout << "Habilidades desbloqueadas:\n";
            habilidadeDefesa->ativar();
            habilidadeAtaque->ativar();
        }
};

// Clareira Corrompida
class PurificarTerra : public Missao {
    public:
        PurificarTerra() : Missao("Purificação da Clareira", "Desbloqueie a magia para restaurar a terra corrompida.", new RugidoDaNatureza(), new GarrasDaTerra()) {}

        void concluir(){
            concluida = true;
            cout << "Você restaurou a clareira! A natureza agradece. Missão concluída.\n";
            cout << "Habilidades desbloqueadas:\n";
            habilidadeDefesa->ativar();
            habilidadeAtaque->ativar();
        }
};

// Ruinas
class CriarBarreiras : public Missao {
    public:
        CriarBarreiras() : Missao("Defesa Contra as Chamas", "Fortaleça a floresta contra o avanço do fogo.", new AuraDaResistencia(), new ChicoteDeCipos()) {}

        void concluir(){
            concluida = true;
            cout << "Novas barreiras naturais contra incêndios! Missão concluída.\n";
            cout << "Habilidades desbloqueadas:\n";
            habilidadeDefesa->ativar();
            habilidadeAtaque->ativar();
        }
};


// Base industrial
class MissaoSabotarIndustria : public Missao {
    public:
        MissaoSabotarIndustria() : Missao("Contra a Exploração", "Infiltre-se e sabote máquinas destrutivas.", new AuraDaResistencia(), new RajadaEnergetica()) {}

        void concluir(){
            concluida = true;
            cout << "Você sabotou os sistemas industriais! Missão concluída.\n";
            cout << "Habilidades desbloqueadas:\n";
            habilidadeDefesa->ativar();
            habilidadeAtaque->ativar();
        }
};


// Coração da floresta
class MissaoFinal : public Missao {
        public:
        MissaoFinal() : Missao("O Destino da Floresta", "Ative os pedestais de energia pura para restaurar a floresta.", new RenascimentoDaFloresta(), new ExplosaoCelestial()) {}

        void Dialogo(Jogador& jogador){
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
            habilidadeDefesa->ativar();
            habilidadeAtaque->ativar();
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