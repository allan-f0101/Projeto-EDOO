#include <iostream>
#include "atributoscartas.hpp"
#include "coletaveis.hpp"
#include "jogador.hpp"
#include "oponentes.hpp"

using namespace std;

int main(){
    Jogador* player = new Jogador();

    cout << "----- INICIANDO O JOGO -----" << endl;
    
    player->exibirStatus();
    return 0;
}