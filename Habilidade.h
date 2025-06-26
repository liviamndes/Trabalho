#ifndef HABILIDADE_H 
#define HABILIDADE_H

#include<iostream>
#include<string>

using namespace std;

class Jogador;
class Inimigo;

class Habilidade{
    protected:
        string nome;
        string descricao;
        bool desbloqueado;
    public:
        Habilidade(string n, string d) : nome{n}, descricao{d} {}
        void desbloquear() { 
            desbloqueado = true;
            cout << "Habilidade desbloqueada: " << nome << "!\n";
        }
        
        bool estaDesbloqueada() const { return desbloqueado; }
        virtual ~Habilidade() {}

        virtual string getNome() const {return nome;}
        virtual string getDescricao() const {return descricao;}

        virtual void ativar(Jogador* jogador, Inimigo* inimigo) = 0;
        
};


//Habilidades de Defesa

//Bosque das fadas
class EscudoDeLuz : public Habilidade{
    public:
        EscudoDeLuz() : Habilidade("Escudo de Luz", "Cria uma barreira magica que reduz 25% do dano recebido por um turno."){}
        void ativar(Jogador* jogador, Inimigo* inimigo) override;
};

//Clareira Corrompida
class RugidoDaNatureza : public Habilidade {
    public:
        RugidoDaNatureza() : Habilidade("Rugido da Natureza", "Garante resistencia contra ataques fisicos e magicos por um turno.") {}
        void ativar(Jogador* jogador, Inimigo* inimigo) override;
};

//Lago das larimas
class ChuvaPurificadora : public Habilidade {
    public:
        ChuvaPurificadora() : Habilidade("Chuva Purificadora", "Remove efeitos negativos e restaura 10% da vida.") {}
        void ativar(Jogador* jogador, Inimigo* inimigo) override;
};


//Base Industrial
class AuraDaResistencia : public Habilidade {
    public:
        AuraDaResistencia() : Habilidade("Aura da Resistencia", "Aumenta defesa contra habilidades tecnologicas.") {}
        void ativar(Jogador* jogador, Inimigo* inimigo) override ;
};

//Coracao da floresta
class RenascimentoDaFloresta : public Habilidade {
    public:
        RenascimentoDaFloresta() : Habilidade("Renascimento da Floresta", "Regenera 30% da vida ao longo de tres turnos.") {}
        void ativar(Jogador* jogador, Inimigo* inimigo) override;
};

//Habilidades de Ataque

//Bosque das fadas
class DardoLuminoso : public Habilidade {
public:
    DardoLuminoso() : Habilidade("Dardo Luminoso", "Dispara flechas de luz contra inimigos sombrios.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override;
};

//Clareira Corrompida
class GarrasDaTerra : public Habilidade {
public:
    GarrasDaTerra() : Habilidade("Garras da Terra", "Ataca o inimigo com espinhos magicos que causam dano terrestre.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override;
};

//Lago das Lagrimas
class JorroEncantado : public Habilidade {
public:
    JorroEncantado() : Habilidade("Jorro Encantado", "Desencadeia um poderoso fluxo de agua purificada.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override;
};

//Base Industrial
class RajadaEnergetica : public Habilidade {
public:
    RajadaEnergetica() : Habilidade("Rajada Energetica", "Dispara um feixe de energia concentrada.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override;
};

//Coracao da floresta
class ExplosaoCelestial : public Habilidade {
public:
    ExplosaoCelestial() : Habilidade("Explosao Celestial", "Libera uma onda de luz divina que causa grande dano em inimigos.") {}
    void ativar(Jogador* jogador, Inimigo* inimigo) override;
};

#endif