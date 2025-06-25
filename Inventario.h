// Todos os itens podem ser desbloqueados ao resolver o sistema de armadilhas e quebra cabeca da fase.
// Eles devem ser usados para derrotar o vilao da fase na batalha por turnos.
// Ao final de cada batalha eh desbloqueada duas novas habilidades, para defesa e ataque(progredindo o personagem),
// e uma nova missao para o próximo cenário.

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include <string>
#include <iostream>
#include <vector>
#include "Item.h"

using namespace std;

class Jogador;

//fiquei em duvida de em qual arquivo vai essa classe
class ItemBloqueadoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro: O item esta bloqueado e não pode ser adicionado ao inventario. Resolva o desafio da fase para acessar";
    }
};

template <typename T>
class Inventario{
    private: 
        vector<T*> itens;   //"construtor":inicializa o vetor de itens, automaticamente ao criar um objeto da classe
    public:
        // destrutor
        ~Inventario () {
            for (size_t i = 0; i < itens.size(); i++) {
                delete itens[i];
            }
        }
        vector<T*> getItens() const { return itens; }
        void addItem(T* item){
            if (!item->estaDesbloqueado()) {
                 if (!item->estaDesbloqueado()) {
                    throw ItemBloqueadoException(); 
                }
            }
            
            itens.push_back(item); //insere o item no vetor, função da biblioteca padrao vector
            cout << " -Item: "<< item->getNome() << " adicionado ao inventario!\n";
        }

        bool listarItens(){
            if(itens.empty()){
                cout << "Inventario vazio!" << "\n";
                return false;
            }
            cout << "Itens no inventario:\n";
            for(auto item : itens)
                cout << item->getNome() << " - " << item->getDescricao() <<"\n";
            return true;
        }

        void usarItem(string &nomeItem, Jogador* jogador){
            for(auto it = itens.begin(); it != itens.end(); ++it){
                if((*it)->getNome() == nomeItem){
                    (*it)->usar(jogador);
                    delete *it;
                    itens.erase(it);

                    cout << "O item foi consumido e removido do inventario.\n";
                    return;
                }
            }
            cout << "Item nao encontrado!\n"; 
        } 
};  

#endif