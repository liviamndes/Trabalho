// Todos os itens podem ser desbloqueados ao resolver o sistema de armadilhas e quebra cabeca da fase.
// Eles devem ser usados para derrotar o vilao da fase na batalha por turnos.
// Ao final de cada batalha eh desbloqueada duas novas habilidades, para defesa e ataque(progredindo o personagem),
// e uma nova missao para o próximo cenário.


//falta a interação com o inventario: Descrição: Gerencia os objetos coletados pelo jogador durante a aventura. Permite adicionar, remover e visualizar objetos, como armas, armaduras, itens, poções e outros objetos.


#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <iostream>
#include <vector>
#include "Personagem.h"

using namespace std;

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
                cout << "Item:" << nome << " desbloqueado!\n";
            }

            void usar(){
                if(desbloqueado){
                    cout << "Usou" << nome << "\n";
                }else{
                    cout << "Ainda não pode ser usado. Resolva o desafio da fase para acessar.\n";
                }
            }

};

class Inventario{
    private: 
        vector<Item*> itens;   //"construtor":inicializa o vetor de itens, automaticamente ao criar um objeto da classe
    public:
        // destrutor
        ~Inventario () {
            for (size_t i = 0; i < itens.size(); i++) {
                delete itens[i];
            }
        }

        void addItem(Item* item){
            if (!item->estaDesbloqueado()) {
                cout << "Item " << item->getNome() << " ainda está bloqueado!\n";
                return;
            }
            
            itens.push_back(item); //insere o item no vetor, função da biblioteca padrao vector
            cout << "Item "<< item->getNome() << " adicionado ao inventário!\n";
        }

        void listarItens(){
            if(itens.empty()){
                cout << "Inventario vazio!" << "\n";
                return;
            }
            cout << "Itens no inventário:\n";
            for(auto item : itens)
                cout << item->getNome() << "-" << item->getDescricao() <<"\n";
        }

        void usarItem(string nomeItem){
            for(auto item : itens){
                if(item->getNome() == nomeItem){
                    item->usar();
                    return;
                }
            }
            cout << "Item nao encontrado!\n"; 
        }
};  

//(Bosque das fadas)
class PocaoCura : public Item{
    public:
        PocaoCura() : Item("Poção de Cura", "Recupera X HP e neutraliza venenos"){}

        void usar(Jogador& jogador) {
        if (estaDesbloqueado()) {
            jogador.recuperarVida(50);  //aqui ainda tenho que implementar a função.
            cout << "Você usou a Poção de Cura e recuperou X HP!\n";
        } else {
            cout << "A Poção de Cura ainda está bloqueada!\n";
        }
    }
};

//(Clareira Corrompida)
class RaizAncestral : public Item {
public:
    RaizAncestral() : Item("Raiz Ancestral", "Fortalece resistência contra venenos e ataques físicos.") { }
    
    void usar(Jogador& jogador) {
        if (estaDesbloqueado()) {
            jogador.aumentarDefesa(10); // Ex: aumenta defesa em 10 pontos //aqui ainda tenho que implementar a função. -- e o obj, defesa magica
            cout << "A Raiz Ancestral fortaleceu sua resistência!\n";
        } else {
            cout << "A Raiz Ancestral ainda está bloqueada!\n";
        }
    }

};


//(Lago das Lágrimas)
class CristalDaAgua : public Item {
public:
    CristalDaAgua() : Item("Cristal da Água", "Purifica a terra e remove efeitos negativos.") { }

    void usar(Jogador& jogador) {
        if (estaDesbloqueado()) {
            jogador.removerDanos(); //aqui ainda tenho que implementar a função. 
            cout << "O Cristal da Água purificou sua energia!\n";
        } else {
            cout << "O Cristal da Água ainda está bloqueado!\n";
        }
    }

};

//(Ruínas)
class SementeAncestral : public Item {
public:
    SementeAncestral() : Item("Semente Ancestral", "Fonte de energia pura, essencial para restaurar o mundo.") { }

    void usar(Jogador& jogador) {
        if (estaDesbloqueado()) {
            cout << "A Semente Ancestral brilha com energia pura...\n"; // ai salva o mundo kkkk 
        } else {
            cout << "A Semente Ancestral ainda está bloqueada!\n";
        }
    }

};

//(Caminho de Cinzas)
class CoracaoDeMadeira : public Item {
public:
    CoracaoDeMadeira() : Item("Coração de Madeira", "Protege contra chamas e ambientes hostis.") { }

    void usar(Jogador& jogador) {
        if (estaDesbloqueado()) {
            jogador.reduzirDanoPorFogo(50); //aqui ainda tenho que implementar a função. -- escudo
            cout << "O Coração de Madeira protegeu você contra queimaduras!\n";
        } else {
            cout << "O Coração de Madeira ainda está bloqueado!\n";
        }
    }

};

//(Base Indústria Sombria)
class AmuletoDaEsperanca : public Item {
public:
    AmuletoDaEsperanca() : Item("Amuleto da Esperança", "Aumenta defesa mágica e resiste a interferências tecnológicas.") { }

     void usar(Jogador& jogador) {
        if (estaDesbloqueado()) {
            jogador.aumentarDefesaMagica(15); //aqui ainda tenho que implementar a função. 
            cout << "O Amuleto da Esperança fortaleceu sua resistência mágica!\n";
        } else {
            cout << "O Amuleto da Esperança ainda está bloqueado!\n";
        }
    }

};

//(Coração da Floresta)
class CristalDaVida : public Item {
public:
    CristalDaVida() : Item("Cristal da Vida", "Potencializa magia e restaura energia máxima.") { }

    void usar(Jogador& jogador) {
        if (estaDesbloqueado()) {
            jogador.recuperarVidaTotal(); //aqui ainda tenho que implementar a função.
            jogador.aumentarExperiencia(30); //aqui ainda tenho que implementar a função
            cout << "O Cristal da Vida restaurou toda sua energia e fortaleceu sua magia!\n";
        } else {
            cout << "O Cristal da Vida ainda está bloqueado!\n";
        }
    }

};


#endif