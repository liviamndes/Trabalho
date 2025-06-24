#ifndef HABILIDADE_H 
#define HABILIDADE_H

#include "Personagem.h"
#include<iostream>
#include<string>

using namespace std;

class Habilidade{
    protected:
        string nome;
        string descricao;
    public:
        Habilidade(string n, string d) : nome{n}, descricao{d} {}
        virtual ~Habilidade() {}

        virtual string getNome() const {return nome;}
        virtual string getDescricao() const {return descricao;}

        virtual void ativar(Jogador* jogador, Inimigo* inimigo) = 0;
};


//Habilidades de Defesa

//Bosque das fadas
class EscudoDeLuz : public Habilidade{
    public:
        EscudoDeLuz() : Habilidade("Escudo de Luz", "Cria uma barreira mágica que reduz 25% do dano recebido por um turno."){}
       
        void ativar(Jogador* jogador, Inimigo* inimigo) override {
            if(jogador!= nullptr){
            cout << "Voce usou o Escudo de Luz! Dano reduzido em 25% neste turno." << endl;
            jogador->setModificadorDano(0.75);
            }
        }

};

//Clareira Corrompida
class RugidoDaNatureza : public Habilidade {
    public:
        RugidoDaNatureza() : Habilidade("Rugido da Natureza", "Garante resistência contra ataques fisicos e magicos por um turno.") {}
        void ativar(Jogador* jogador, Inimigo* inimigo) override {
            if(jogador != nullptr){
                cout << "Você usou o Rugido da Natureza! Resistência aumentada contra ataques físicos e mágicos." << endl;   
                jogador->setModificadorDano(0.3);
            }
        }
};

//Lago das larimas
class ChuvaPurificadora : public Habilidade {
    public:
        ChuvaPurificadora() : Habilidade("Chuva Purificadora", "Remove efeitos negativos e restaura 10% da vida.") {}
        void ativar(Jogador* jogador, Inimigo* inimigo) override {
            if (jogador != nullptr) {
                int cura = jogador->getMaxVida() * 0.1;
                cout << "Voce usou a Chuva Purificadora! Efeitos negativos removidos e 10% da vida restaurada." << endl;
                jogador->recuperarVida(cura);
            }
        }   
};


//Base Industrial
class AuraDaResistencia : public Habilidade {
    public:
        AuraDaResistencia() : Habilidade("Aura da Resistência", "Aumenta defesa contra habilidades tecnológicas.") {}
        void ativar(Jogador* jogador, Inimigo* inimigo) override {
             if (jogador != nullptr) {
            cout << "Você usou a Aura da Resistencia! Defesa aumentada contra habilidades tecnológicas." << endl;
            jogador->setModificadorDano(0.7);
            }
        }
};

//Coracao da floresta
class RenascimentoDaFloresta : public Habilidade {
    public:
        RenascimentoDaFloresta() : Habilidade("Renascimento da Floresta", "Regenera 30% da vida ao longo de três turnos.") {}
        void ativar(Jogador* jogador, Inimigo* inimigo) override {
            if (jogador != nullptr) {
                int cura = jogador->getMaxVida() * 0.1;
                cout << "Voce usou o Renascimento da Floresta! 30% da vida regenerada ao longo de 3 turnos." << endl;
                jogador->iniciarEfeitoRegeneracao(cura, 3);
            }
        }
};

//Habilidades de Ataque

//Bosque das fadas
class DardoLuminoso : public Habilidade {
public:
    DardoLuminoso() : Habilidade("Dardo Luminoso", "Dispara flechas de luz contra inimigos sombrios.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override {
        if (inimigo != nullptr) {
            int dano = 30;
            cout << "Voce usou o Dardo Luminoso! Flechas de luz atingem o inimigo!" << endl;
            inimigo->sofrerDano(dano);
        }
    }
};

//Clareira Corrompida
class GarrasDaTerra : public Habilidade {
public:
    GarrasDaTerra() : Habilidade("Garras da Terra", "Ataca o inimigo com espinhos mágicos que causam dano terrestre.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override {
        if (inimigo != nullptr) {
            int dano = 25;
            cout << "Voce usou as Garras da Terra! Espinhos mágicos causam dano >>"<< dano <<"<< no inimigo!" << endl;
            inimigo->sofrerDano(dano);
        }
    }
};

//Lago das Lagrimas
class JorroEncantado : public Habilidade {
public:
    JorroEncantado() : Habilidade("Jorro Encantado", "Desencadeia um poderoso fluxo de água purificada.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override {
        if (inimigo != nullptr) {
            int dano = 35;
            cout << "Voce usou o Jorro Encantado! Um poderoso fluxo de água purificada atinge o inimigo!" << endl;
            inimigo->sofrerDano(dano);
        }
    }
};

//Base Industrial
class RajadaEnergetica : public Habilidade {
public:
    RajadaEnergetica() : Habilidade("Rajada Energética", "Dispara um feixe de energia concentrada.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override {
        if (inimigo != nullptr) {
            int dano = 40;
            cout << "Voce usou a Rajada Energética! Um feixe de energia concentrada atinge o inimigo!" << endl;
            inimigo->sofrerDano(dano);
        }
    }
};

//Coracao da floresta
class ExplosaoCelestial : public Habilidade {
public:
    ExplosaoCelestial() : Habilidade("Explosao Celestial", "Libera uma onda de luz divina que causa grande dano em inimigos.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override {
        if (inimigo != nullptr) {
            int dano = 50;
            cout << "Você usou a Explosão Celestial! Uma onda de luz divina causa grande dano no inimigo!" << endl;
            inimigo->sofrerDano(dano);
        }
    }

};


#endif