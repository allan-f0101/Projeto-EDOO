#include <iostream>
#include <vector>
#include "atributoscartas.hpp"
#include "coletaveis.hpp"
#include "Entidades/jogador.hpp"
#include "Entidades/oponentes.hpp"

using namespace std;

int main(){
    Jogador* player = new Jogador();

    vector<Inimigo*> horda;
    cout << "----- INICIANDO O JOGO -----" << endl;

    for(int i=0; i < 3; i++) horda.push_back(new RoboVoador());
    for(int i = 0; i < 1; i++) horda.push_back(new RoboBola());
    for(int i = 0; i < 1; i++) horda.push_back(new RoboZangao());
    for(int i = 0; i < 1; i++) horda.push_back(new RoboCobra());
    
    horda.push_back(new RoboDragao());

    cout << "----- INICIANDO O COMBATE -----" << endl;
    
    for (Inimigo* atual : horda){
        if(!player->estaVivo()) break;

        cout << "\n>>> Um novo oponente surge: " << atual->getNome() << " <<<" << endl;
        atual->exibirStatus();

        while (player->estaVivo() && atual->estaVivo()){
            cout << "[TURNO JOGADOR] ";
            atual->receberDano(player->getDano());
            
            cout << "-> " << atual->getNome() << " ficou com " << atual->getVida() << "/" << atual->getVidaMaxima() << " de HP!" << endl;

            if(atual->estaVivo()){
                cout << "[TURNO OPONENTE] ";
                player->receberDano(5 + (player->getNivel() * 2));

                cout << "-> Voce tem " << player->getVida() << " de HP restante." << endl;
            }
        }
        if (player->estaVivo()){
            std::cout << "\n[VITORIA] " << atual->getNome() << " foi destruido!" << std::endl;
            
            // 4. Progressão: Ganha XP e melhora um atributo
            player->ganharXP(60); 
            
            // Exibe como o jogador ficou após a luta
            player->exibirStatus();
        } else {
            std::cout << "\n[DERROTA] O jogador foi destruido por " << atual->getNome() << "..." << std::endl;
        }
    }

    // 5. Finalização
    if (player->estaVivo()) {
        std::cout << "\n=======================================" << std::endl;
        std::cout << "PARABENS! Voce derrotou toda a horda!" << std::endl;
        std::cout << "=======================================" << std::endl;
    }

    // Limpeza de memória
    for (Inimigo* e : horda) delete e;
    delete player;

    return 0;
}