#include "Personagem.h"

bool Jogador::resolverQuebraCabecaAtual() {
    if (!quebraCabecaAtual) {
        cout << "Nenhum quebra-cabeça atribuído ao jogador.\n";
        return;
    }

    bool resolveu = quebraCabecaAtual->resolver();

    if(resolveu) {
        cout << "Voce resolveu o quebra-cabeça com sucesso!\n";
        ganharExperiencia(25); 

        if (missaoAtual) {
            missaoAtual->concluir();
            cout << "Missão concluída!\n";
            return true;
        }
        
    } else {
        cout << "Você falhou em resolver o quebra-cabeça.\n";
        return false;
    }
}
void Jogador::sofrerDano(int perda) {
    vida-= perda;
    if(vida <= 0)
        cout << "Você foi derrotado... Esta morto!\n";
    else {
        cout << "Você sofreu " << perda << " de dano!\n";
        cout << "Vida restante: " << vida << "\n";
    }
}
void Jogador:: atacar(Inimigo& inimigo){
    cout << nome << "ataca" << inimigo.getNome() << "causando" << ataque << "de dano!";
    inimigo.sofrerDano(ataque);
}
void Jogador::ganharExperiencia(int xp) {
    experiencia += xp;
    cout << "Você ganhou " << xp << " pontos de experiência. Total: " << experiencia << "\n";

    while (experiencia >= nivel * 100) {
        experiencia -= nivel * 100;
        subirNivel();
    }
}
void Jogador::subirNivel() {
    nivel++;
    cout << "Parabéns! Você chegou ao nivel " << nivel << "!\n";
}
void Jogador:: recuperarVida(int quant){
    vida += quant;
    cout << "Voce recuperou" << quant << " de vida. Vida total: " << vida << "\n";
}
void Inimigo::sofrerDano(int perda) {
    vida-= perda;
    if(vida <= 0)
        cout << "Inimigo foi derrotado... Esta morto!\n";
    else {
        cout << nome <<" sofreu " << perda << " de dano!\n";
        cout << "Vida restante: " << vida << "\n";
    }
}
void Inimigo:: atacar(Jogador& jogador){
    cout << nome << "ataca" << jogador.getNome() << "causando" << ataque << "de dano!";
    jogador.sofrerDano(ataque);
}