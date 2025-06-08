#ifndef QUEBRACABECA_H
#define QUEBRACABECA_H

#include <iostream>
#include <vector>
using namespace std;

class QuebraCabeca {
    protected:
        vector<string> itens;
        vector<string> sequencia;
        string descricao;
    public:
        QuebraCabeca(vector<string> i, vector<string> s, string d) 
            : itens{i}, sequencia{s}, descricao{d}{ };
        virtual ~QuebraCabeca() { };

        static string normalizar(string);
        virtual bool resolver() = 0;
};

// Resolver as pedras místicas
class QuebraClareira : public QuebraCabeca {
    public:
        QuebraClareira() : QuebraCabeca({"Pedra Azul", "Pedra Verde", "Pedra Vermelha", "Pedra Amarela"},
        {"Pedra Amarela", "Pedra Vermelha", "Pedra Azul", "Pedra Verde"}, 
        "O solo ao redor das pedras está corrompido e murcha à medida que o tempo passa, mas você percebe que, "
        "se conseguir ativar as pedras na sequência correta, pode purificar a terra e restaurar a clareira. "
        "As pedras estão dispostas em um círculo perfeito, e há uma pedra central que brilha com uma luz intensa. "
        "Mas a chave para a purificação está em acertar a sequência correta de pedras que devem ser ativadas.") { };
        
        bool resolver() override;
};      
#endif