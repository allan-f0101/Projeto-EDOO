#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "coletaveis.hpp"

// Espelha as cartas de upgrade do jogo original
enum class TipoUpgrade {
    DANO,       // +10 dano base
    COOLDOWN,   // -10% tempo entre tiros
    VELOCIDADE, // +1 velocidade
    CURA,       // recupera 50 HP
    VIDA_MAX    // +20 HP máximo
};

class Jogador {
private:
    // --- Atributos de combate ---
    int   vidaMaxima;
    int   vidaAtual;
    int   danoBase;
    int   cooldownTiro; 
    float velocidade;

    // --- Invencibilidade pós-dano ---
    bool invencivel;
    int  timerInvencivel;

    // --- Progressão ---
    int nivel;
    int xpAtual;
    int xpNecessario;
    int moedas;

    // --- Helpers internos ---
    void curar(int quantidade);
    void ganharMoeda(int quantidade);

public:
    Jogador();

    // --- Combate ---
    bool receberDano(int dano);

    void atualizarInvencibilidade();

    bool estaVivo() const { return vidaAtual > 0; }

    // --- Coleta de itens ---
    // Retorna true se o XP coletado causou level up.
    bool coletarItem(Coletaveis& item);

    // --- XP e level up ---
    // Retorna true se subiu de nível
    bool ganharXP(int quantidade);

    // --- Upgrades (cartas de level up) 
    void aplicarUpgrade(TipoUpgrade tipo);

    // --- Getters ---
    int   getVida()         const { return vidaAtual;     }
    int   getVidaMaxima()   const { return vidaMaxima;    }
    int   getNivel()        const { return nivel;         }
    int   getXP()           const { return xpAtual;       }
    int   getXPNecessario() const { return xpNecessario;  }
    int   getMoedas()       const { return moedas;        }
    int   getDano()         const { return danoBase;      }
    int   getCooldown()     const { return cooldownTiro;  }
    float getVelocidade()   const { return velocidade;    }
    bool  isInvencivel()    const { return invencivel;    }

    // --- Debug / terminal ---
    void exibirStatus() const;
};

#endif