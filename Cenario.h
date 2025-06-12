//Cada cenario é uma fase com uma missao e um vilão.
//Em cada uma dessas fases vamos ter armadilhas/quebra-cabecas para desbloquear o item.
//Esse item vai ser usado na batalha contra o vilao, que tb ocorrera nesse cenario.
//Ao final ocorre a progressao do personagem com duas novas habilidades(defesa e ataque)

#ifndef CENARIO_H
#define CENARIO_H
#include <iostream>
#include "Personagem.h"
#include "Missao.h"
#include "Inventario.h"
#include "Habilidade.h"

using namespace std;


class Cenario{
    protected:
        string nome;
        string descricao;
        vector<Inimigo*> inimigos;
        vector<Armadilha*> armadilhas;
        vector<Puzzle*> puzzles;
        Missao *missaoAtual;
        Item *item;
        Inimigo *vilao;
        vector<Cenario*> conexoes;

    public:
        // Construtor e destrutor
        Cenario(string n, string d, Missao* m, Item* i, Inimigo* v) 
            : nome{n}, descricao{d}, missaoAtual{m}, item{i}, vilao{v}, conexoes{} {};  
        virtual ~Cenario() { };

        virtual void explorar(Jogador*) = 0;
        
        // Getters
        string getNome() const { return nome; }
        string getDescricao() const { return descricao; }
        vector<Cenario*> getConexoes() {return conexoes; }

        // Método de missao
        void iniciarMissao(Jogador*);
};
class BosqueDasFadas : public Cenario {
    private:

    public:
        BosqueDasFadas(Missao *m, Item *i, Inimigo *v) : Cenario("Bosque das Fadas",
            "Você entra em um bosque iluminado por fadas e flores místicas. "
            "As árvores altas formam um teto natural que filtra a luz, criando uma atmosfera etérea. "
            "No centro do bosque, uma fada ferida repousa, suas asas estao danificadas. "
            "O ar ao redor é fresco e a fragrancia das flores torna o ambiente tranquilo, mas voce sente que ha algo urgente a ser feito. "
            "A estrada até o Santuário das Fadas está bloqueada por um campo de plantas venenosas, que ameaça qualquer um que tente atravessar. " 
            "Voce deve reunir ingredientes para a Poção de Cura antes que seja tarde demais.",
            m, i, v) { };
            void explorar(Jogador*);
};
class ClareiraCorrompida : public Cenario {
    public:
        ClareiraCorrompida(Missao *m, Item *i, Inimigo *v) : Cenario("Clareira Corrompida", 
            "Voce entra em uma clareira sombria onde a vegetação parece murchar. "
            "O chao esta coberto por uma neblina negra e as arvores tem uma aparencia retorcida. "
            "O ar esta pesado, e o ambiente parece pulsar com uma energia malignamente distorcida. "
            "A corrupção da terra pode ser sentida a cada passo. ",
            m, i, v) { };
            void explorar(Jogador*);
};
class LagodasLagrimas : public Cenario {
    public: 
        LagodasLagrimas(Missao *m, Item *i, Inimigo *v) : Cenario("Lago das Lagrimas", 
            "O Lago das Lágrimas, normalmente uma fonte de beleza serena, agora está secando e sua água parece desaparecer lentamente. "
            "A água do lago, que costumava brilhar com um tom azul etéreo, agora está turva e opaca. " 
            "A natureza ao redor também sofre, com as plantas murchando e os animais fugindo. "
            "Você sente que há algo errado com o coração do lago. "
            "Seguindo rastros de energia, você encontra um Cristal da Agua, que pode ser a chave para restaurar o lago. "
            "Mas o inimigo, uma flor carnivora, bloqueia o caminho, absorvendo a energia vital da terra e tornando-se mais forte.",
            m, i, v) { };
            void explorar(Jogador*);
};
class BaseIndustria : public Cenario {
    public:
        BaseIndustria(Missao *m, Item *i, Inimigo *v) : Cenario("Base da Industria", 
        "Você entra em uma imensa base industrial, onde máquinas gigantescas e tecnologia arcana estão em pleno funcionamento. "
        "O som de engrenagens e tubos de vapor ecoa por toda a instalação, criando uma atmosfera de total mecanização. "
        "O General da Exploração controla a área e está atrás de manipular a magia e a tecnologia para seus próprios fins. "
        "Para impedir seus planos, você precisa hackear sistemas de segurança mágicos, desarmar dispositivos e sabotar a máquina central. "
        "Mas a interferência do General torna o ambiente ainda mais perigoso. "
        "A única esperança é o Amuleto da Esperança, que pode reverter os danos causados por essa interferência.",
        m, i, v) { };
        void explorar(Jogador*);
};
class CoracaoDaFloresta : public Cenario {
    public:
        CoracaoDaFloresta(Missao *m, Item *i, Inimigo *v) : Cenario("Coracao da Floresta",
            "Você chega ao centro da floresta, onde a natureza é mais vibrante e poderosa. "
            "O ar aqui parece mais fresco, e a luz solar brilha diretamente através das copas das árvores, criando um campo de luz dourada. "
            "No entanto, algo está prestes a mudar. "
            "O Coração da Floresta está em perigo, ameaçado por uma força sombria e corrompida que se originou da Rainha das Cinzas. "
            "Para salvar a floresta, você deve ativar os pedestais de energia pura, usando todas as habilidades adquiridas nas fases anteriores. "
            "Ao enfrentar a Rainha, você deve usar todo o poder acumulado para resistir à sua força destrutiva e restaurar o equilíbrio natural.",
            m, i, v) { };
        void explorar(Jogador*);
};
#endif