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

        // métodos de ataque e defesa
                // ...
        // getters
        string getNome() const;
        int getVida() const;
        int getAtaque() const;
        int getDefesa() const;
};

class Jogador : Personagem {
    protected:
        int nivel, experiencia;
        Cenario* cenarioAtual;  // -> composição
        // vector<Missao*> missoesAtivas;
        // vector<Habilidade*> habilidadesAprendidas;
    public:
        // construtor e destrutor
        Jogador() : Personagem{"Jogador", 100, 0, 0}, nivel{1}, experiencia{0}, cenarioAtual{nullptr} { };
        ~Jogador() { };

        // métodos para se mover por cenários
                // ...
        // métodos para verificar missões
                // ...

        void ganharExperiencia(int xp);
        void subirNivel();
};
#endif