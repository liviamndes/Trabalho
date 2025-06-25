#ifndef QUEBRACABECA_H
#define QUEBRACABECA_H

#include <iostream>
#include <vector>
using namespace std;

class QuebraCabecaNaoResolvidoException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Erro: O quebra-cabeca nao foi resolvido corretamente.";
    }
};

class QuebraCabeca {
    protected:
        vector<string> itens;
        vector<string> sequencia;
        string descricao;
    public:
        QuebraCabeca(vector<string> i, vector<string> s, string d) 
            : itens{i}, sequencia{s}, descricao{d}{ };
        virtual ~QuebraCabeca() { };

        bool executarQuebraCabeca();
        string getDescricao() { return descricao; }
        static string normalizar(string);
        virtual bool resolver() = 0;
};

// Resolver as pedras místicas
class QuebraClareira : public QuebraCabeca {
    public:
        QuebraClareira() : QuebraCabeca({"Pedra Azul", "Pedra Verde", "Pedra Vermelha", "Pedra Amarela"},
        {"Pedra Amarela", "Pedra Vermelha", "Pedra Azul", "Pedra Verde"}, 
        "O solo ao redor das pedras esta corrompido e murcha a medida que o tempo passa, mas você percebe que, "
        "se conseguir ativar as pedras na sequência correta, pode purificar a terra e restaurar a clareira. "
        "As pedras estão dispostas em um círculo perfeito, e há uma pedra central que brilha com uma luz intensa. "
        "Mas a chave para a purificação está em acertar a sequência correta de pedras que devem ser ativadas.") { };
        bool resolver() override;
};

class QuebraIndustria : public QuebraCabeca {
    public:
        QuebraIndustria() : QuebraCabeca({"Circuito Vermelho", "Circuito Azul", "Circuito Verde", "Circuito Amarelo"},
        {"Circuito Azul", "Circuito Verde", "Circuito Amarelo", "Circuito Vermelho"},
        "O sistema de segurança da base esta protegido por circuitos mágicos e tecnológicos. "
        "Cada circuito precisa ser ativado na sequencia correta para desativar as defesas e permitir a infiltração. "
        "Existem quatro circuitos com cores distintas dispostos em um painel eletrônico. "
        "A chave para o sucesso está em acertar a ordem correta de ativação dos circuitos.") { };
        bool resolver() override;
};
#endif