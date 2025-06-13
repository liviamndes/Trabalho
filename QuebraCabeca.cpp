#include <iostream>
#include <algorithm>
#include <cctype>
#include <vector>
#include <string>
#include "QuebraCabeca.h"

using namespace std;
string QuebraCabeca::normalizar(string str) {
    // Remove espaços do início e do fim
    while (!str.empty() && isspace(str.front())) str.erase(str.begin());
    while (!str.empty() && isspace(str.back())) str.pop_back();

    // Converte para minúsculas
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    return str;
}
bool QuebraCabeca::resolver() {
    cout << getDescricao() << "\n\n";
    cout << "Sequencia Inicial:\n";
    for(const auto& item : itens) {
        cout << "- " << item << "\n";
    }

    int tentativaAtual = 0;
    while(true) {
        cout << "\nTentativa " << tentativaAtual + 1 << "\n";

        vector<string> resposta;
        string entrada;

        cout << "Digite a sequencia correta (quatro nomes separados por ENTER):\n";

        for(int i = 0; i < 4; i++) {
            getline(cin, entrada);
            resposta.push_back(entrada);
        }

        bool correta = true;
        for(int i = 0; i < 4; i++) {
            if(QuebraCabeca::normalizar(resposta[i]) == QuebraCabeca::normalizar(sequencia[i])) {
                cout << "Posicao " << (i + 1) << ": " << resposta[i] << " esta correta!\n";
            }
            else {
                cout << "Posicao " << (i + 1) << ": " << resposta[i] << " esta incorreta!\n";
                correta = false;
            }
        }

        if(correta) {
            return true;
        } else {
            cout << "Tente novamente.\n";
            tentativaAtual++;
        }
    }
}
