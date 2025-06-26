#include "Armadilha.h"
#include <ctime>

void Armadilha::ativar(Jogador* jogador) {
    // método base vazio
}
void LagoArmadilha::ativar(Jogador *jogador) {
    srand(time(NULL));
    int efeito = rand() % 100;  // número aleatório entre 0 e 99
    if (efeito < 30) {  // 30% de chance de cura
        cout << "A Pocao Misterio teve um efeito positivo! Você recuperou 50 de vida.\n";
        jogador->sofrerDano(-50);  // Cura o jogador
    } else if (efeito < 60) {  // 30% de chance de aumento de dano
        cout << "A Pocao Misterio aumentou sua experiencia!" << endl;
        jogador->ganharExperiencia(20);
    } else {  // 40% de chance de dano
        cout << "A Pocao Misterio foi prejudicial! Você sofreu 10 de dano.\n";
        jogador->sofrerDano(10);  // Aplica dano ao jogador
    }
}