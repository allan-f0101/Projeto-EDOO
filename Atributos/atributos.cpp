#include "atributos.hpp"
#include <iostream>
#include <string>
#include <vector>

Atributos::Atributos()
    : vidaMaxima(100),
      vidaAtual(100),
      danoBase(10),
      cooldownTiro(500),
      velocidade(7),
      nivel(1),
      xpAtual(0),
      xpNecessario(20),
      semente(12345u)
{}

unsigned int Atributos::proximoAleatorio() const {
    semente = semente * 1664525u + 1013904223u;
    return semente;
}

void Atributos::setVidaAtual(int valor) {
    if      (valor < 0)          vidaAtual = 0;
    else if (valor > vidaMaxima) vidaAtual = vidaMaxima;
    else                         vidaAtual = valor;
}

bool Atributos::ganharXp(int quantidade) {
    xpAtual += quantidade;

    if (xpAtual >= xpNecessario) {
        xpAtual -= xpNecessario;
        xpNecessario = static_cast<int>(xpNecessario * 1.5f);
        nivel++;
        std::vector<TipoUpgrade> opcoes = sortearUpgrades();

        std::cout << "[Level Up] Nivel" << nivel << " atingido! Upgrades sorteados:\n";
        for (int i = 0; i < static_cast<int>(opcoes.size()); ++i) {
            std::cout << " [" << (i + 1) << "] "
                      << nomeUpgrade(opcoes[i])
                      << " -> " << descricaoUpgrade(opcoes[i]) << "\n";
        }

        aplicarUpgrade(opcoes[0]);
        std::cout << "[Auto] Upgrade aplicado: "
                  << nomeUpgrade(opcoes[0]) << "\n";
        return true;
    }

    return false;
}

std::vector<TipoUpgrade> Atributos::sortearUpgrades() const {
    TipoUpgrade catalogo[5] = {
        TipoUpgrade::FORCA_BRUTA,
        TipoUpgrade::METRALHADORA,
        TipoUpgrade::PE_DE_VENTO,
        TipoUpgrade::CURATIVO,
        TipoUpgrade::TANQUE
    };

    for (int i = 4; i > 0; --i) {
        int j = static_cast<int>(proximoAleatorio() % static_cast<unsigned int>(i + 1));
        TipoUpgrade tmp = catalogo[i];
        catalogo[i]     = catalogo[j];
        catalogo[j]     = tmp;
    }

    std::vector<TipoUpgrade> resultado;
    resultado.push_back(catalogo[0]);
    resultado.push_back(catalogo[1]);
    resultado.push_back(catalogo[2]);
    return resultado;
}

void Atributos::aplicarUpgrade(TipoUpgrade upgrade) {
    switch (upgrade) {
        case TipoUpgrade::FORCA_BRUTA:
            danoBase += 10;
            break;
        case TipoUpgrade::METRALHADORA:
            cooldownTiro = static_cast<int>(cooldownTiro * 0.9f);
            break;
        case TipoUpgrade::PE_DE_VENTO:
            velocidade += 1;
            break;
        case TipoUpgrade::CURATIVO:
            setVidaAtual(vidaAtual + 50);
            break;
        case TipoUpgrade::TANQUE:
            vidaMaxima += 20;
            vidaAtual  += 20;   
            break;
    }
}

std::string Atributos::nomeUpgrade(TipoUpgrade upgrade) const {
    switch (upgrade) {
        case TipoUpgrade::FORCA_BRUTA:  return "Forca Bruta";
        case TipoUpgrade::METRALHADORA: return "Metralhadora";
        case TipoUpgrade::PE_DE_VENTO:  return "Pe de Vento";
        case TipoUpgrade::CURATIVO:     return "Curativo";
        case TipoUpgrade::TANQUE:       return "Tanque";
    }
    return "Desconhecido";
}

std::string Atributos::descricaoUpgrade(TipoUpgrade upgrade)
const {
    auto intStr = [](int n) -> std::string {
        if (n == 0) return "0";
        std::string s;
        bool neg = (n < 0);
        if (neg) n = -n;
        while (n > 0) { s = static_cast<char>('0' + n % 10) + s; n /= 10;}
        return neg ? "-" + s : s;
    };

    switch (upgrade) {
        case TipoUpgrade::FORCA_BRUTA:
            return "Dano Base: " + intStr(danoBase) + " -> " + intStr(danoBase + 10);
        case TipoUpgrade::METRALHADORA:
            return "Cooldown: " + intStr(cooldownTiro) + "ms -> " + intStr(static_cast<int>(cooldownTiro * 0.9f)) + "ms";
        case TipoUpgrade::PE_DE_VENTO:
            return "Velocidade: " + intStr(velocidade) + " -> " + intStr(velocidade + 1);
        case TipoUpgrade::CURATIVO: {
            int apos = (vidaAtual + 50 > vidaMaxima) ? vidaMaxima : vidaAtual + 50;
            return "Vida: " + intStr(vidaAtual) + " -> " + intStr(apos)
                            + " (max " + intStr(vidaMaxima) + ")";
        }
        case TipoUpgrade::TANQUE:
            return "Vida Max: " + intStr(vidaMaxima) + " -> " + intStr(vidaMaxima + 20) + " | Vida: +" + intStr(20);
    }
    return "";
}

std::ostream& operator<<(std::ostream& os, const Atributos& a) {
    os << "=== ATRIBUTOS ===\n"
       << "  Nivel       : " << a.nivel
       << "  (XP: " << a.xpAtual << "/" << a.xpNecessario << ")\n"
       << "  Vida        : " << a.vidaAtual << "/" << a.vidaMaxima << "\n"
       << "  Dano Base   : " << a.danoBase  << "\n"
       << "  Cooldown    : " << a.cooldownTiro << "ms\n"
       << "  Velocidade  : " << a.velocidade  << "\n"
       << "=================\n";
    return os;
}