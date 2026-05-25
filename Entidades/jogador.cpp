#include "jogador.hpp"
#include <iostream>
#include <algorithm> 
Jogador::Jogador()
    : vidaMaxima(100),
      vidaAtual(100),
      danoBase(10),
      cooldownTiro(30),    
      velocidade(7.0f),
      invencivel(false),
      timerInvencivel(0),
      nivel(1),
      xpAtual(0),
      xpNecessario(100),
      moedas(0)
{}

// ──────────────────────────────────────────────
//  Combate
// ──────────────────────────────────────────────
bool Jogador::receberDano(int dano) {
    if (invencivel) return false;       

    vidaAtual -= dano;
    if (vidaAtual < 0) vidaAtual = 0;

    invencivel       = true;
    timerInvencivel  = 30;

    return true;
}

void Jogador::atualizarInvencibilidade() {
    if (!invencivel) return;

    --timerInvencivel;
    if (timerInvencivel <= 0) {
        invencivel      = false;
        timerInvencivel = 0;
    }
}

//  Helpers privados
void Jogador::curar(int quantidade) {
    vidaAtual = std::min(vidaAtual + quantidade, vidaMaxima);
}

void Jogador::ganharMoeda(int quantidade) {
    moedas += quantidade;
}

//  Coleta de itens
bool Jogador::coletarItem(Coletaveis& item) {
    
    if (XP* xp = dynamic_cast<XP*>(&item)) {
        return ganharXP(xp->getQtd());
    }
    if (Moeda* moeda = dynamic_cast<Moeda*>(&item)) {
        ganharMoeda(moeda->getQtd());
        return false;
    }
    if (Vida* vida = dynamic_cast<Vida*>(&item)) {
        curar(vida->getQtd());
        return false;
    }
    return false;
}

//  XP e level up
bool Jogador::ganharXP(int quantidade) {
    xpAtual += quantidade;

    if (xpAtual >= xpNecessario) {
        xpAtual      -= xpNecessario;
        xpNecessario  = static_cast<int>(xpNecessario * 1.5f); 
        ++nivel;
        return true;   
    }
    return false;
}

//  Upgrades (cartas de level up)
void Jogador::aplicarUpgrade(TipoUpgrade tipo) {
    switch (tipo) {
        case TipoUpgrade::DANO:
            danoBase += 10;
            break;

        case TipoUpgrade::COOLDOWN:
            cooldownTiro = std::max(5, static_cast<int>(cooldownTiro * 0.9f));
            break;

        case TipoUpgrade::VELOCIDADE:
            velocidade += 1.0f;
            break;

        case TipoUpgrade::CURA:
            curar(50);
            break;

        case TipoUpgrade::VIDA_MAX:
            vidaMaxima += 20;
            vidaAtual  += 20;   
            break;
    }
}

//  Exibição no terminal
void Jogador::exibirStatus() const {
    std::cout << "=== STATUS DO JOGADOR ===\n"
              << "  Nivel:      " << nivel << "\n"
              << "  HP:         " << vidaAtual << "/" << vidaMaxima << "\n"
              << "  XP:         " << xpAtual   << "/" << xpNecessario << "\n"
              << "  Dano:       " << danoBase  << "\n"
              << "  Cooldown:   " << cooldownTiro << " frames\n"
              << "  Velocidade: " << velocidade   << "\n"
              << "  Moedas:     " << moedas        << "\n"
              << "  Status:     " << (estaVivo() ? "VIVO" : "MORTO")
                                  << (invencivel  ? " [INVENCIVEL]" : "")
              << "\n=========================\n";
}