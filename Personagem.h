#ifndef PERSONAGEM_H
#define PERSONAGEM_H
#include <iostream>
#include <vector>

using namespace std;

#include "Inventario.h" 
#include "Habilidade.h"
#include "Missao.h"
using namespace std;

class Item;
class Cenario;
class Inimigo;
class QuebraCabeca;
template <typename T> class Inventario;

class Personagem {
    protected:
        string nome;
        int vida, ataque, dano;
    public:
        // construtor e destrutor 
        Personagem(string n, int v, int a, int d) : nome{n}, vida{v}, ataque{a}, dano{d} { };
        virtual ~Personagem() { };

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
        Inventario<Item> inv;  // cada jogador tem inventario própio 
        vector<Habilidade*> habilidades;
        int vidaMaxima;
        float modificadorDano = 1.0;
        int turnosRegenerando = 0;
        int vidaPorTurno = 0;
        bool temHabilidade = false;
    public:
        // construtor e destrutor
        Jogador(string nome, int vida) : Personagem{nome, vida, 10, 5}, nivel{1}, experiencia{0}, cenarioAtual{nullptr}, missaoAtual{nullptr} { 
            vidaMaxima = vida;
        }
        virtual ~Jogador() { };

        // métodos do inventario
        void adicionarItemAoInventario(Item *item) { inv.addItem(item); }
        bool listarItensDoInventario() { inv.listarItens(); }
        void usarItemDoInventario(string nomeItem) { inv.usarItem(nomeItem, this); }

        //metado de habilidade
        void adicionarHabilidade(Habilidade* habilidade) {
            habilidades.push_back(habilidade);
            cout << "Habilidade " << habilidade->getNome() << " adicionada ao jogador!\n";
        }
        bool getTemHabilidade() { 
            for (auto* h : habilidades)
                if (h->estaDesbloqueada()) return true;
            return false; 
        }
        
        void listarHabilidades() {
            
            cout << "\nHabilidades disponiveis:\n";
            for (size_t i = 0; i < habilidades.size(); i++) {
                if(habilidades[i]->estaDesbloqueada()) {
                    cout << i+1 << " - " << habilidades[i]->getNome() << ": " << habilidades[i]->getDescricao() << endl;
                    temHabilidade = true;
                } 
            }
        }
        void usarHabilidade(int escolha, Jogador* jogador, Inimigo* inimigo) {
            
            if (escolha >= 1 && escolha <= habilidades.size()) {
                cout << "\nUsando habilidade: " << habilidades[escolha-1]->getNome() << endl;
                habilidades[escolha-1]->ativar(jogador, inimigo);
            } else {
                cout << "Escolha invalida.\n";
            }
        }

        // método de missao
        void iniciarMissao(Missao *missao) { missaoAtual = missao; missao->iniciar(); }
        Missao* getMissaoAtual() {return missaoAtual;}
        void concluirMissao(Missao* missao);

        // método de quebra cabeça
        void definirQuebraCabeca(QuebraCabeca *qc) { quebraCabecaAtual = qc; }
        bool resolverQuebraCabecaAtual();

        // método cenário
        void setCenario(Cenario* cenario) { cenarioAtual = cenario; }
        Cenario* getCenario() { return cenarioAtual; }

        //metado batalha
        void atacar(Inimigo& inimigo);
        void sofrerDano(int);
        void ganharExperiencia(int);
        void subirNivel();
        void recuperarVida(int);
        int getMaxVida() const;
        void setModificadorDano(float modificador);
        void resetarModificadorDano();
        void iniciarEfeitoRegeneracao(int vidaPorTurno_, int duracaoTurnos);
        void aplicarRegeneracaoPorTurno();
};
class Fada : public Jogador {
    public:
        // construtor e destrutor
        Fada() : Jogador{"FadaGuardiana", 120} { };
        ~Fada() { };
};
class Inimigo : public Personagem {  
    public: 
        // construtor e destrutor
        Inimigo(int v, int a, int d) : Personagem{"Inimigo", v, a, d} { };
        ~Inimigo() { };

        void sofrerDano(int);
        void atacar(Jogador& jogador);
};
class Morcego : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        Morcego(string t = "Morcego") : Inimigo{25, 20, 1}, tipo{t} { nome = tipo;}
        ~Morcego() { };
};
class Fungo : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        Fungo(string t = "Fungo") : Inimigo{40, 40, 15}, tipo{t} { nome = tipo;}
        ~Fungo() { };
};
class AlmasPerdidas : public Inimigo {
    protected:
        string tipo;
    public: 
        // construtor e destrutor
        AlmasPerdidas(string t = "Almas Perdidas") : Inimigo{75, 30, 10}, tipo{t} { nome = tipo;}
        ~AlmasPerdidas() { };
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