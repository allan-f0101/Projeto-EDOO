#include "oponentes.hpp"
#include <iostream>

bool Inimigo::receberDano(int dano){
    vida -= dano;
    if (vida <= 0){
        vida = 0;
        return true;
    }
    return false;
}

void Inimigo::exibirStatus() const{
    std::cout << nome
                  << " | HP: " << vida << "/" << vidaMaxima
                  << " | Vel: " << velocidade
                  << " | " << (estaVivo() ? "VIVO" : "MORTO")
                  << "\n";
}

bool RoboDragao::receberDano(int dano){
    bool morreu = Inimigo::receberDano(dano);

    if (!modoFuria && vida > 0 && vida < vidaMaxima / 4){
        modoFuria = true;
        velocidade = 3.0f;
    }

    return morreu;
}

void RoboDragao::exibirStatus() const{
    Inimigo::exibirStatus();
    std::cout << "  -> Modo furia: " << (modoFuria ? "ATIVO" : "inativo") << "\n";
}
