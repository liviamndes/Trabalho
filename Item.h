#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include<string>

using namespace std;

class Jogador; 

class Item {
    protected: 
        string nome;
        string descricao;
        bool desbloqueado;
    public:
        //Construtor e destrutor
        Item(string n, string d) : nome{n}, descricao{d}, desbloqueado{false} {}
        virtual ~Item() {}

        string getNome() const {return nome;}
        string getDescricao() const {return descricao;}
        bool estaDesbloqueado() const {return desbloqueado;}

        void desbloquear(){
            desbloqueado = true;
            cout << " -Item: " << nome << " desbloqueado!\n";
        }
        virtual void usar(Jogador* jogador) = 0;
};

//(Bosque das fadas)
class PocaoCura : public Item{
    public:
        PocaoCura() : Item("Pocao de Cura", "Recupera X HP e neutraliza venenos"){}
        void usar(Jogador* jogador) override;
};

//(Clareira corrompida)
class SementeAncestral : public Item {
    public:
        SementeAncestral() : Item("Semente Ancestral", "Fonte de energia pura, essencial para restaurar o mundo.") { }    
        void usar(Jogador* jogador)override;
};

//(Lago das Lágrimas)
class CristalDaAgua : public Item {
public:
    CristalDaAgua() : Item("Cristal da Água", "Um cristal que contem o poder de purificar a terra") { };
    void usar(Jogador* jogador) override;

};

//(Base Indústria Sombria)
class AmuletoDaEsperanca : public Item {
public:
    AmuletoDaEsperanca() : Item("Amuleto da Esperança", "Aumenta defesa mágica e resiste a interferências tecnológicas.") { }

     void usar(Jogador* jogador) override;
};

//(Coração da Floresta)
class CristalDaVida : public Item {
public:
    CristalDaVida() : Item("Cristal da Vida", "Potencializa magia e restaura energia máxima.") { }

    void usar(Jogador* jogador) override;
};

#endif