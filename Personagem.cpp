#include "Personagem.h"
#include "Personagem.h"
#include "Item.h"
#include "Habilidade.h"
#include "Missao.h"
#include "Cenario.h"
#include "QuebraCabeca.h"
#include "Armadilha.h"

bool Jogador::resolverQuebraCabecaAtual() {
    bool resolveu = quebraCabecaAtual->resolver();

    if(resolveu) {
        cout << "\n...........................................\n";
        cout << "      Quebra-cabeca resolvido com sucesso!   \n";
        cout << "...........................................\n";
        ganharExperiencia(25); 
    } 
}
void Jogador::setModificadorDano(float modificador) {
    modificadorDano = modificador;
}
void Jogador::resetarModificadorDano() {
    modificadorDano = 1.0;
}
void Jogador::sofrerDano(int perda) {
    perda = perda * modificadorDano;
    vida-= perda;
    if(vida <= 0)
        cout << "\nVoce foi derrotado.";
    else {
        cout << "\nVoce sofreu " << perda << " de dano!\n";
        cout << "Vida restante: " << vida << "\n";
    }
}
void Jogador:: atacar(Inimigo& inimigo){
    cout << "\n" << nome << " ataca " << inimigo.getNome() << " causando " << ataque << " de dano!";
    inimigo.sofrerDano(ataque);
}
void Jogador::ganharExperiencia(int xp) {
    experiencia += xp;
    cout << "Voce ganhou " << xp << " pontos de experiencia. Total: " << experiencia << "\n";
}
void Jogador::subirNivel() {
    nivel++;
    cout << "Parabens! Voce chegou ao nivel " << nivel << "!\n";
    ataque = ataque + (5*nivel);
    cout << "Seu ataque agora gera " << ataque << " de dano no inimigo.\n";

}
void Jogador:: recuperarVida(int quant){
    vida += quant;
    if (vida > vidaMaxima) vida = vidaMaxima;
    cout << "Voce recuperou " << quant << " de vida. Vida total: " << vida << "\n";
}
int Jogador::getMaxVida() const {
    return vidaMaxima;
}
void Jogador::iniciarEfeitoRegeneracao(int vidaPorTurno_, int duracaoTurnos) {
    vidaPorTurno = vidaPorTurno_;
    turnosRegenerando = duracaoTurnos;
    cout << "Voce comecra a recuperar " << vidaPorTurno << " de vida pelos proximos " << turnosRegenerando << " turnos.\n";
}
void Jogador::aplicarRegeneracaoPorTurno() {
    if (turnosRegenerando > 0) {
        cout << "Regeneracao ativa: + " << vidaPorTurno << " de vida!\n";
        recuperarVida(vidaPorTurno);
        turnosRegenerando--;
    }
}
void Inimigo::sofrerDano(int perda) {
    vida-= perda;
    if(vida <= 0)
        cout << "\nInimigo foi derrotado... Esta morto!\n";
    else {
        cout << "\n" << nome <<" sofreu " << perda << " de dano!\n";
        cout << "Vida restante: " << vida << "\n";
    }
}
void Inimigo:: atacar(Jogador& jogador){
    cout << "\n" << nome << " ataca " << jogador.getNome() << " causando " << ataque << " de dano!";
    jogador.sofrerDano(ataque);
}
void Jogador::concluirMissao(Missao* missao) {
    missao->concluir();
    adicionarHabilidade(missao->getHabilidadeDefesa());
    adicionarHabilidade(missao->getHabilidadeAtaque());
}