#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <iostream>
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
        Cenario* cenarioAtual;  // -> composição
        // vector<Missao*> missoesAtivas;
        // vector<Habilidade*> habilidadesAprendidas;
    public:
        // construtor e destrutor
        Jogador(int vida) : Personagem{"Jogador", vida, 10, 5}, nivel{1}, experiencia{0}, cenarioAtual{nullptr} { };
        virtual ~Jogador() { };

        // métodos para se mover por cenários
                // ...
        // métodos para verificar missões
                // ...

        void ganharExperiencia(int xp);
        void subirNivel();
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
class MonstroChefe : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        MonstroChefe(string t = "Monstro Chefe") : Inimigo{100, 50, 5}, tipo{t} { nome = tipo;}
        ~MonstroChefe() { };
};

#endif