#include "jogador.hpp"
#include <iostream>

Jogador::Jogador() {
    vidaMaxima = 100;
    vidaAtual = 100;
    danoBase = 10;
    cooldownTiro = 1;
    velocidade = 1.0f;
    
    nivel = 1;
    xpAtual = 0;
    xpNecessario = 50;
    moedas = 0;
}

bool Jogador::receberDano(int dano) {
    vidaAtual -= dano;
    std::cout << "[COMBATE] Jogador recebeu " << dano << " de dano! (HP: " << vidaAtual << ")\n";

    if (vidaAtual <= 0) {
        vidaAtual = 0;
        return true;
    }
    return false;
}

void Jogador::curar(int quantidade) {
    vidaAtual += quantidade;
    if (vidaAtual > vidaMaxima) {
        vidaAtual = vidaMaxima;
    }
    std::cout << "[ITEM] Jogador curou " << quantidade << " de vida!\n";
}

bool Jogador::ganharXP(int quantidade) {
    xpAtual += quantidade;
    std::cout << "[XP] +" << quantidade << " pontos de experiencia.\n";

    if (xpAtual >= xpNecessario) {
        nivel++;
        xpAtual -= xpNecessario;
        xpNecessario += 50;
        
        vidaMaxima += 20;
        vidaAtual = vidaMaxima;
        danoBase += 5;
        
        std::cout << "\n>>> LEVEL UP! Agora voce esta no nivel " << nivel << " <<<\n";
        std::cout << ">>> Vida e Dano aumentados! <<<\n\n";
        return true;
    }
    return false;
}

bool Jogador::coletarItem(Coletaveis& item) {
    int valor = item.getQtd();
    
    return ganharXP(valor);
}

void Jogador::ganharMoeda(int quantidade) {
    moedas += quantidade;
    std::cout << "[MOEDA] +" << quantidade << " moedas de ouro!\n";
}

// Exibe a ficha do personagem no terminal
void Jogador::exibirStatus() const {
    std::cout << "==============================\n";
    std::cout << " STATUS DO JOGADOR (Nvl: " << nivel << ")\n";
    std::cout << " HP: " << vidaAtual << "/" << vidaMaxima << "\n";
    std::cout << " Dano: " << danoBase << " | Vel: " << velocidade << "\n";
    std::cout << " XP: " << xpAtual << "/" << xpNecessario << "\n";
    std::cout << " Moedas: " << moedas << "\n";
    std::cout << "==============================\n";
}