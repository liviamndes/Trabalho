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
        "O solo ao redor das pedras esta corrompido e murcha a medida que o tempo passa, mas voce percebe que, "
        "se conseguir ativar as pedras na sequencia correta, pode purificar a terra e restaurar a clareira. "
        "As pedras estao dispostas em um circulo perfeito, e ha uma pedra central que brilha com uma luz intensa. "
        "Mas a chave para a purificacao esta em acertar a sequencia correta de pedras que devem ser ativadas.") { };
        bool resolver() override;
};

class QuebraIndustria : public QuebraCabeca {
    public:
        QuebraIndustria() : QuebraCabeca({"Circuito Vermelho", "Circuito Azul", "Circuito Verde", "Circuito Amarelo"},
        {"Circuito Azul", "Circuito Verde", "Circuito Amarelo", "Circuito Vermelho"},
        "O sistema de seguranca da base esta protegido por circuitos magicos e tecnologicos. "
        "Cada circuito precisa ser ativado na sequencia correta para desativar as defesas e permitir a infiltracao. "
        "Existem quatro circuitos com cores distintas dispostos em um painel eletronico. "
        "A chave para o sucesso esta em acertar a ordem correta de ativacao dos circuitos.") { };
        bool resolver() override;
};
#endif