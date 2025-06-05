//Cada cenario é uma fase com uma missao e um vilão.
//Em cada uma dessas fases vamos ter armadilhas/quebra-cabecas para desbloquear o item.
//Esse item vai ser usado na batalha contra o vilao, que tb ocorrera nesse cenario.
//Ao final ocorre a progressao do personagem com duas novas habilidades(defesa e ataque)

#ifndef CENARIO_H
#define CENARIO_H
#include <iostream>
#include "Personagem.h"
#include"Missao.h"
#include "Inventario.h"
#include"Habilidade.h"

using namespace std;


class Cenario{
    protected:
        string nome;
        string descricao;
        vector<Inimigo*> inimigos;
        vector<Armadilha*> armadilhas;
        vector<Puzzle*> puzzles;
        Missao* missaoAtual;
        Item* item;
        vector<Cenario*> conexoes;

    public:
        // Construtor e destrutor
        Cenario(string n, string d, Missao* m, Item* i, Inimigo* v) : nome{n}, descricao{d}, missaoAtual{m}, item{i}, /*aq falta o vilao*/{}
        ~Cenario() { };

        void explorar(Jogador*) = 0;
        void adicionarInimigo(Inimigo *inimigo) { inimigos.push_back(inimigo); }
        void adicionarArmadilha(Armadilha *armadilha) { armadilha.push_back(armadilha); }
        void adicionarPuzzle(Puzzle *puzzle) { puzzles.push_back(puzzle); }
        void adicionarConexao(Cenario *cenario) {conexoes.push_back(cenario); }

        // getters
        string getNome() { return nome; }
        vector<Cenario*> getConexoes() {return conexoes; }

        //metados de missao
        void iniciarMissao(Jogador* jogador){
            cout << "Voce chegou ao " << nome << "\n";
            cout << descricao << "\n";
            missaoAtual->iniciar();
        } //vo esperar vc acabar os cenarios pra acabar de implementar.

};
class BosqueDasFadas : public Cenario {
    private:

    public:
        BosqueDasFadas() : Cenario("Bosque das fadas", "Voce entra em um lindo bosque que vivem centenas de fadas e diversas flores misticas. Ha uma fada ferida no chao") {};
        void explorar(Jogador*);
};
class ClareiraCorrompida : public Cenario {

};
class Ruinas : public Cenario {

};
class CaminhoSombrio : public Cenario {

};
class BaseIndustriaSobria : public Cenario {

};
class CoracaoDaFloresta : public Cenario {

};
#endif