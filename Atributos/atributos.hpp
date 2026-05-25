#ifndef INIMIGOS_HPP
#define INIMIGOS_HPP

#include "jogador.hpp"
#include <string>
#include <vector>
#include <iostream>

class Carta {
    private:
        TipoUpgrade tipo;
        std::string nome;
        std::string descricao;
    public:
        Carta(TipoUpgrade tipo, const std::string& nome, const std::string& descricao);

        TipoUpgrade getTipo()       const {return tipo;}
        std::string getNome()       const {return nome;}
        std::string getDescricao()  const {return descricao;}

        friend std::ostream& operator<<(std::ostream& os, const Carta& c);
};

std::ostream& operator<<(std::ostream& os, const Carta& c);

class Catalogo {
    private:
        mutable unsigned int semente;

        unsigned int proximoAleatorio() const;
        std::vector<Carta> todasAsCartas() const;
    
    public:
        Catalogo();
        std::vector<Carta> sortear3() const;
        Carta buscarCarta(TipoUpgrade tipo) const;
};

#endif