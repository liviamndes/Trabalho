#include"Item.h"
#include"Personagem.h"

void PocaoCura :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        jogador->recuperarVida(50);  // Recupera 50 de vida no jogador
        cout << "Voce usou a " << getNome() << endl; 
    } else {
        cout << "A " << getNome() << " ainda está bloqueada!\n";
    }
}

void SementeAncestral :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        jogador->recuperarVida(50);  // Recupera 50 de vida no jogador
        cout << "Voce usou a " << getNome() << endl; 
    } else {
        cout << "A " << getNome() << " ainda está bloqueada!\n";
    }
}

void CristalDaAgua :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        jogador->recuperarVida(20); 
        cout << "O Cristal da Água purificou sua energia!\n";
    } else {
        cout << "O Cristal da Água ainda está bloqueado!\n";
    }
}

void AmuletoDaEsperanca :: usar(Jogador* jogador){
     if (estaDesbloqueado()) {
        jogador->recuperarVida(15);  
        cout << "O Amuleto da Esperança fortaleceu sua resistência mágica!\n";
    } else {
        cout << "O Amuleto da Esperança ainda está bloqueado!\n";
    }
}

void CristalDaVida :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        jogador->recuperarVida(100); 
        jogador->ganharExperiencia(30); 
        cout << "O Cristal da Vida restaurou toda sua energia e fortaleceu sua magia!\n";
    } else {
        cout << "O Cristal da Vida ainda está bloqueado!\n";
    }
}
