#ifndef ARMADILHA_H
#define ARMADILHA_H

#include <iostream>
#include "Personagem.h"
using namespace std;

class Armadilha {
    protected:
        string nome;
        string descricao;
        int dano;
        bool ativada;
    public:
        Armadilha(string n, string de, int d) 
            : nome {n}, descricao{de}, dano{d}, ativada{false} { };
        virtual ~Armadilha() { };

        int getDano() { return dano; }
        string getNome() { return nome; }
        virtual void ativar(Jogador*);
};
class LagoArmadilha : public Armadilha {
    public:
        LagoArmadilha() : Armadilha("Lagrimas da Flora", "Esta armadilha é uma manifestação das energias malignas que corrompem o Lago das Lágrimas. " 
            "Formada por raízes de plantas venenosas que se estendem pela água, ela se ativa ao toque, lançando o jogador em um estado de paralisia "
            "enquanto inunda sua mente com visões de almas perdidas. "
            "As raízes, cobertas por uma substância pegajosa, drenam lentamente a energia vital do jogador, "
            "tornando-o mais vulnerável aos ataques dos inimigos.", 20) { };
        void ativar(Jogador*) override;
};
#endif