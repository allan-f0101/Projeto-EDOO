#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include "coletaveis.hpp"

class Jogador {
private:
    // --- Atributos de combate ---
    int   vidaMaxima;
    int   vidaAtual;
    int   danoBase;
    int   cooldownTiro; 
    int velocidade;

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

    // --- Ações de Combate ---
    bool receberDano(int dano); 
    
    void curar(int quantidade);
    bool estaVivo() const { return vidaAtual > 0; }

    // --- Métodos para as Cartas (Bônus) ---
    void aumentarDano(int bonus)        { danoBase += bonus; }
    void aumentarVelocidade(float b)    { velocidade += b; }
    void aumentarVidaMaxima(int bonus)  { 
        vidaMaxima += bonus; 
        vidaAtual += bonus;
    }

    // --- Progressão e Itens ---
    bool coletarItem(Coletaveis& item);
    bool ganharXP(int quantidade);

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

    void exibirStatus() const;
};

#endif