#ifndef INIMIGOS_HPP
#define INIMIGOS_HPP

#include <string>
#include <vector>
#include <iostream>

enum class TipoUpgrade {
    FORCA_BRUTA,   // +10 Dano Base
    METRALHADORA,  // Cooldown * 0.9
    PE_DE_VENTO,   // +1 Velocidade
    CURATIVO,      // +50 Vida Atual (limitado à Vida Máxima)
    TANQUE         // +20 Vida Máxima e +20 Vida Atual
};

class Atributos {
    private:
        int vidaMaxima;
        int vidaAtual;
        int danoBase;
        int cooldownTiro;
        int velocidade;

        int nivel;
        int xpAtual;
        int xpNecessario;

        mutable unsigned int semente;

        unsigned int                proximoAleatorio() const;
        std::vector<TipoUpgrade>    sortearUpgrades() const;
        void                        aplicarUpgrade(TipoUpgrade upgrade);
        std::string                 nomeUpgrade(TipoUpgrade upgrade) const;
        std::string                 descricaoUpgrade(TipoUpgrade upgrade) const;

    public:
        Atributos();
        int getVidaMaxima()   const { return vidaMaxima;   }
        int getVidaAtual()    const { return vidaAtual;    }
        int getDanoBase()     const { return danoBase;     }
        int getCooldownTiro() const { return cooldownTiro; }
        int getVelocidade()   const { return velocidade;   }
        int getNivel()        const { return nivel;        }
        int getXpAtual()      const { return xpAtual;      }
        int getXpNecessario() const { return xpNecessario; }

        void setVidaAtual(int valor);

        bool ganharXp(int quantidade);

        friend std::ostream& operator<<(std::ostream& os, const Atributos& a);
};

std::ostream& operator<<(std::ostream& os, const Atributos& a);

#endif