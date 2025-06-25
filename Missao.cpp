#include "Missao.h"
#include "Personagem.h"

void MissaoFinal::concluirSalvacao(Jogador &jogador)
{
    concluida = true;
    cout << "Você salvou a floresta e restaurou o equilíbrio do mundo! Missão concluída.\n";
    cout << "Habilidades desbloqueadas:\n";
    jogador.adicionarHabilidade(habilidadeDefesa);
    jogador.adicionarHabilidade(habilidadeAtaque);
}
void MissaoFinal::concluirHumanidade(Jogador &jogador)
{
    concluida = true;
    cout << "\nVoce escolheu abandonar sua missao...\n";
    cout << "A Rainha sorri. \"Muito bem... bem-vinda ao mundo real.\"\n";
    cout << "Voce agora sente sede, fome, ambição e medo pela primeira vez.\n";
    cout << "Mas agora é tarde. Voce faz parte da destruição.\n";
}
void MissaoFinal::escolha(Jogador &jogador)
{
    int escolha;

    cout << "\nESCOLHA SEU DESTINO:";
    cout << "\n1.Usar a semente Ancestral e salvar a floresta.";
    cout << "\n2.Aceitar a oferta da Rainha e se tornar humana.";

    cout << "Digite sua escolha (1 ou 2): ";
    cin >> escolha;

    if (escolha == 1)
    {
        concluirSalvacao(jogador);
    }
    else if (escolha == 2)
    {
        concluirHumanidade(jogador);
    }
    else
    {
        cout << "Escolha invalida! A Rainha aguarda sua resposta...\n";
    }
}