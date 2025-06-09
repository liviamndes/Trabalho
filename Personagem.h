#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
#include <vector>
#include "Cenario.h"
#include "Inventario.h" 
#include "Habilidade.h"
#include "QuebraCabeca.h"

using namespace std;

class Personagem {
    protected:
        string nome;
        int vida, ataque, dano;
    public:
        // construtor e destrutor 
        Personagem(string n, int v, int a, int d) : nome{n}, vida{v}, ataque{a}, dano{d} { };
        virtual ~Personagem() { };

        // métodos de ataque e defesa, virtuais
                // ...
        // getters
        string getNome() const { return nome; }
        int getVida() const { return vida; }
        int getAtaque() const { return ataque; }
        int getDefesa() const { return dano; }
};
class Jogador : public Personagem {
    protected:
        int nivel, experiencia;
        Cenario *cenarioAtual; 
        Item *itemAtual;
        Missao *missaoAtual;
        QuebraCabeca *quebraCabecaAtual;
        Inventario inv;  // cada jogador tem inventario própio 
        vector<Habilidade*> habilidadesAprendidas;
    public:
        // construtor e destrutor
        Jogador(int vida) : Personagem{"Jogador", vida, 10, 5}, nivel{1}, experiencia{0}, cenarioAtual{nullptr} { };
        virtual ~Jogador() { };

        // métodos para se mover por cenários
                // ...
        // métodos para verificar missões
                // ...

        // métodos do inventario
        void adicionarItemAoInventario(Item *item) { inv.addItem(item); }
        void listarItensDoInventario() { inv.listarItens(); }
        void usarItemDoInventario(string nomeItem) { inv.usarItem(nomeItem); }

        // método de missao
        void iniciarMissao(Missao *missao) { missaoAtual = missao; missao->iniciar(); }
       
        // método de quebra cabeça
        void definirQuebraCabeca(QuebraCabeca *qc) { quebraCabecaAtual = qc; }
        bool resolverQuebraCabecaAtual();

        void ganharExperiencia(int);
        void subirNivel();

        // getters
        Missao* getMissaoAtual() { return missaoAtual; }
};
class Fada : public Jogador {
    public:
        // construtor e destrutor
        Fada() : Jogador{120} { };
        ~Fada() { };

        // polimorfismo das funções de ataque e defesa
                // ...
};
class Inimigo : public Personagem {
    public: 
        // construtor e destrutor
        Inimigo(int v, int a, int d) : Personagem{"Inimigo", v, a, d} { };
        ~Inimigo() { };

        // polimorfismo das funções de ataque e defesa
                // ...
};
class Morcego : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        Morcego(string t = "Morcego") : Inimigo{25, 10, 1}, tipo{t} { nome = tipo;}
        ~Morcego() { };
};
class Lobo : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        Lobo(string t = "Lobo") : Inimigo{50, 20, 5}, tipo{t} { nome = tipo;}
        ~Lobo() { };
};
class Fungo : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        Fungo(string t = "Fungo") : Inimigo{100, 40, 15}, tipo{t} { nome = tipo;}
        ~Fungo() { };
};
class FlorCarnivora : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        FlorCarnivora(string t = "Flor Carnivora") : Inimigo{75, 30, 10}, tipo{t} { nome = tipo;}
        ~FlorCarnivora() { };
};
class MaquinaIndustrial : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        MaquinaIndustrial(string t = "Maquina Industrial") : Inimigo{125, 50, 20}, tipo{t} { nome = tipo;}
        ~MaquinaIndustrial() { };
};
class General : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        General(string t = "General") : Inimigo{150, 60, 25}, tipo{t} { nome = tipo;}
        ~General() { };
};
class RainhaDasCinzas : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        RainhaDasCinzas(string t = "Rainha Das Cinzas") : Inimigo{200, 100, 30}, tipo{t} { nome = tipo;}
        ~RainhaDasCinzas() { };  
};

#endif