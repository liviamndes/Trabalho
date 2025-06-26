#include"Item.h"
#include"Personagem.h"

void PocaoCura :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        cout << "\nVoce usou a " << getNome() << endl; 
        jogador->recuperarVida(30);  // Recupera 50 de vida no jogador
    } else {
        cout << "\nA " << getNome() << " ainda esta bloqueada!\n";
    }
}

void SementeAncestral :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        cout << "\nVoce usou a " << getNome() << endl; 
        jogador->recuperarVida(50);  // Recupera 50 de vida no jogador
    } else {
        cout << "\nA " << getNome() << " ainda esta bloqueada!\n";
    }
}

void CristalDaAgua :: usar(Jogador* jogador){
    if (estaDesbloqueado()) { 
        cout << "\nO Cristal da Agua purificou sua energia!\n";
        jogador->recuperarVida(70); // vida mais alta pq tem a opção de nao pegar

    } else {
        cout << "\nO Cristal da Agua ainda esta bloqueado!\n";
    }
}

void AmuletoDaEsperanca :: usar(Jogador* jogador){
     if (estaDesbloqueado()) {  
        cout << "\nO Amuleto da Esperanca fortaleceu sua resistecia magica!\n";
        jogador->recuperarVida(15);
    } else {
        cout << "\nO Amuleto da Esperanca ainda esta bloqueado!\n";
    }
}

void CristalDaVida :: usar(Jogador* jogador){
    if (estaDesbloqueado()) {
        cout << "\nO Cristal da Vida restaurou toda sua energia e fortaleceu sua magia!\n";
        jogador->recuperarVida(100); 
        jogador->ganharExperiencia(30); 
    } else {
        cout << "\nO Cristal da Vida ainda esta bloqueado!\n";
    }
}
