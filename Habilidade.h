#ifndef HABILIDADE_H 
#define HABILIDADE_H

#include<iostream>
#include<string>

using namespace std;

class Habilidade{
    protected:
        string nome;
        string descricao;
    public:
        Habilidade(string n, string d) : nome{n}, descricao{d} {}
        virtual ~Habilidade() {}

        string getNome() const {return nome;}
        string getDescricao() const {return descricao;}

        void ativar(){
            cout << "Habilidade ativada:" << nome << "-" << descricao << "\n";
        }
};


//Habilidades de Defesa

//Bosque das fadas
class EscudoDeLuz : public Habilidade{
    public:
        EscudoDeLuz() : Habilidade("Escudo de Luz", "Cria uma barreira mágica que reduz 25% do dano recebido por um turno."){}

};

//Clareira Corrompida
class RugidoDaNatureza : public Habilidade {
    public:
        RugidoDaNatureza() : Habilidade("Rugido da Natureza", "Garante resistência contra ataques físicos e mágicos por um turno.") {}
};

//Lago das larimas
class ChuvaPurificadora : public Habilidade {
    public:
        ChuvaPurificadora() : Habilidade("Chuva Purificadora", "Remove efeitos negativos e restaura 10% da vida.") {}
};

//Ruinas
class VisaoDoPassado : public Habilidade{
    public:
        VisaoDoPassado() : Habilidade("Visão do Passado", "Revela armadilhas ocultas e elementos estratégicos em níveis futuros.") {}
};

// Caminho de Cinzas 
class RaizesVivas : public Habilidade {
    public:
     RaizesVivas() : Habilidade("Raízes Vivas", "Enraíza o jogador no chão, reduzindo o impacto de golpes pesados.") {}
};

//Base Industrial
class AuraDaResistencia : public Habilidade {
    public:
        AuraDaResistencia() : Habilidade("Aura da Resistência", "Aumenta defesa contra habilidades tecnológicas.") {}
};

//Coracao da floresta
class RenascimentoDaFloresta : public Habilidade {
    public:
        RenascimentoDaFloresta() : Habilidade("Renascimento da Floresta", "Regenera 30% da vida ao longo de três turnos.") {}
};

//Habilidades de Ataque

//Bosque das fadas
class DardoLuminoso : public Habilidade {
public:
    DardoLuminoso() : Habilidade("Dardo Luminoso", "Dispara flechas de luz contra inimigos sombrios.") {}
};

//Clareira Corrompida
class GarrasDaTerra : public Habilidade {
public:
    GarrasDaTerra() : Habilidade("Garras da Terra", "Ataca o inimigo com espinhos mágicos que causam dano terrestre.") {}
};

//Lago das Lagrimas
class JorroEncantado : public Habilidade {
public:
    JorroEncantado() : Habilidade("Jorro Encantado", "Desencadeia um poderoso fluxo de água purificada.") {}
};

//Ruinas
class EsporosExplosivos : public Habilidade {
public:
    EsporosExplosivos() : Habilidade("Esporos Explosivos", "Lança esporos venenosos que enfraquecem o inimigo por dois turnos.") {}
};


//Caminho das Cinzas
class ChicoteDeCipos : public Habilidade {
public:
    ChicoteDeCipos() : Habilidade("Chicote de Cipós", "Golpeia o inimigo rapidamente com cipós encantados.") {}
};

//Base Industrial
class RajadaEnergetica : public Habilidade {
public:
    RajadaEnergetica() : Habilidade("Rajada Energética", "Dispara um feixe de energia concentrada.") {}
};

//Coracao da floresta
class ExplosaoCelestial : public Habilidade {
public:
    ExplosaoCelestial() : Habilidade("Explosão Celestial", "Libera uma onda de luz divina que causa grande dano em inimigos.") {}
};


#endif