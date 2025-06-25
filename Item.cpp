#include"Item.h"
#include"Personagem.h"

void PocaoCura :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        cout << "Voce usou a " << getNome() << endl; 
        jogador->recuperarVida(50);  // Recupera 50 de vida no jogador
    } else {
        cout << "A " << getNome() << " ainda esta bloqueada!\n";
    }
}

void SementeAncestral :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        cout << "Voce usou a " << getNome() << endl; 
        jogador->recuperarVida(50);  // Recupera 50 de vida no jogador
    } else {
        cout << "A " << getNome() << " ainda esta bloqueada!\n";
    }
}

void CristalDaAgua :: usar(Jogador* jogador){
    if (estaDesbloqueado()) { 
        cout << "O Cristal da Agua purificou sua energia!\n";

    } else {
        cout << "O Cristal da Agua ainda esta bloqueado!\n";
    }
}

void AmuletoDaEsperanca :: usar(Jogador* jogador){
     if (estaDesbloqueado()) {  
        cout << "O Amuleto da Esperanca fortaleceu sua resistecia magica!\n";
        jogador->recuperarVida(15);
    } else {
        cout << "O Amuleto da Esperanca ainda esta bloqueado!\n";
    }
}

void CristalDaVida :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        cout << "O Cristal da Vida restaurou toda sua energia e fortaleceu sua magia!\n";
        jogador->recuperarVida(100); 
        jogador->ganharExperiencia(30); 
    } else {
        cout << "O Cristal da Vida ainda esta bloqueado!\n";
    }
}
