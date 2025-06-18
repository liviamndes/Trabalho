void LagoArmadilha::ativar(Jogador *jogador) {
    int efeito = rand() % 100;  // número aleatório entre 0 e 99
    if (efeito < 30) {  // 30% de chance de cura
        cout << "A Poção Misterio teve um efeito positivo! Você recuperou 50 de vida.\n";
        jogador->sofrerDano(-50);  // Cura o jogador
    } else if (efeito < 60) {  // 30% de chance de aumento de dano
        cout << "A Poção Mistério aumentou sua experiencia!" << endl;
        jogador->ganharExperiencia(20);
    } else {  // 40% de chance de dano
        cout << "A Poção Misterio foi prejudicial! Você sofreu " << dano << " de dano.\n";
        jogador->sofrerDano(dano);  // Aplica dano ao jogador
    }
}