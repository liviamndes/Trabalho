#include "Habilidade.h"
#include "Personagem.h"

//---------------Habilidades de Defesa

//Bosque das Fadas
void EscudoDeLuz :: ativar(Jogador* jogador, Inimigo* inimigo){
    if(jogador!= nullptr){
        cout << "Voce usou o Escudo de Luz! Dano reduzido em 25% neste turno." << endl;
        jogador->setModificadorDano(1.0);
    }
}

//Clareira Corrompida
void RugidoDaNatureza :: ativar(Jogador* jogador, Inimigo* inimigo){
    if(jogador != nullptr){
        cout << "Voce usou o Rugido da Natureza! Resistência aumentada contra ataques físicos e mágicos." << endl;   
        jogador->setModificadorDano(0.4);
    }
}

//Lago das Lagrimas
void ChuvaPurificadora :: ativar(Jogador* jogador, Inimigo* inimigo){
    if (jogador != nullptr) {
        int cura = jogador->getMaxVida() * 0.1;
        cout << "Voce usou a Chuva Purificadora! Efeitos negativos removidos e 10% da vida restaurada." << endl;
        jogador->recuperarVida(cura);
    }
}

//Base Industrial
void AuraDaResistencia :: ativar(Jogador* jogador, Inimigo* inimigo){
    if (jogador != nullptr) {
        cout << "Você usou a Aura da Resistencia! Defesa aumentada contra habilidades tecnológicas." << endl;
        jogador->setModificadorDano(0.7);
    }
}

//Coracao da Floresta
void RenascimentoDaFloresta :: ativar(Jogador* jogador, Inimigo* inimigo){
    if (jogador != nullptr) {
                int cura = jogador->getMaxVida() * 0.1;
                cout << "Voce usou o Renascimento da Floresta! 30% da vida regenerada ao longo de 3 turnos." << endl;
                jogador->iniciarEfeitoRegeneracao(cura, 3);
            }
}

//-----------------Habilidades de Ataque

//Bosque das Fadas
void DardoLuminoso :: ativar(Jogador* jogador, Inimigo* inimigo){
     if (inimigo != nullptr) {
        int dano = 25;
        cout << "Voce usou o Dardo Luminoso! Flechas de luz atingem o inimigo!" << endl;
        inimigo->sofrerDano(dano);
    }
}

//Clareira Corrompida
void GarrasDaTerra :: ativar(Jogador* jogador, Inimigo* inimigo){
    if (inimigo != nullptr) {
        int dano =30;
        cout << "Voce usou as Garras da Terra! Espinhos magicos causam dano >>"<< dano <<"<< no inimigo!" << endl;
        inimigo->sofrerDano(dano);
    }
}

//Lago das Lagrimas
void JorroEncantado :: ativar(Jogador* jogador, Inimigo* inimigo){
   if (inimigo != nullptr) {
        int dano = 45;
        cout << "Voce usou o Jorro Encantado! Um poderoso fluxo de agua purificada atinge o inimigo!" << endl;
        inimigo->sofrerDano(dano);
    } 
}

//Base Industrial
void RajadaEnergetica :: ativar(Jogador* jogador, Inimigo* inimigo){
    if (inimigo != nullptr) {
        int dano = 70;
        cout << "Voce usou a Rajada Energetica! Um feixe de energia concentrada atinge o inimigo!" << endl;
        inimigo->sofrerDano(dano);
    }    
}

//Coração da Floresta
void ExplosaoCelestial :: ativar(Jogador* jogador, Inimigo* inimigo){
   if (inimigo != nullptr) {
        int dano = 110;
        cout << "Voce usou a Explosao Celestial! Uma onda de luz divina causa grande dano no inimigo!" << endl;
        inimigo->sofrerDano(dano);
    } 
}
