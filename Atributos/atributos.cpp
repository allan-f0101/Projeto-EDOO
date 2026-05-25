#include "atributos.hpp"
#include <iostream>
#include <string>
#include <vector>

Carta::Carta(TipoUpgrade tipo, const std::string& nome, const std::string& descricao)
    : tipo(tipo), nome(nome), descricao(descricao)
{}

std::ostream& operator<<(std::ostream& os, const Carta& c) {
    os << "[" << c.nome << "] " << c.descricao;
    return os;
}

Catalogo::Catalogo()
    : semente(12345u)
{}

unsigned int Catalogo::proximoAleatorio() const {
    semente = semente * 1664525u + 1013904223u;
    return semente;
}

std::vector<Carta> Catalogo::todasAsCartas() const {
    std::vector<Carta> cartas;
    cartas.push_back(Carta(TipoUpgrade::DANO,       "Forca Bruta", "+10 de Dano Base"));
    cartas.push_back(Carta(TipoUpgrade::COOLDOWN,   "Metralhadora", "-10% "));
    cartas.push_back(Carta(TipoUpgrade::VELOCIDADE, "Pe de Vento", "+1 de Velocidade"));
    cartas.push_back(Carta(TipoUpgrade::CURA, "Curativo", "+50 de Vida Atual"));
    cartas.push_back(Carta(TipoUpgrade::VIDA_MAX, "Tanque", "+20 de Vida Maxima e +20 de Vida Atual"));
    return cartas;
}

std::vector<Carta> Catalogo::sortear3() const {
    std::vector<Carta> cartas = todasAsCartas();

    for (int i = static_cast<int>(cartas.size()) - 1; i > 0; --i) {
        int j = static_cast<int>(proximoAleatorio() % static_cast<unsigned int>(i + 1));
        Carta tmp = cartas[i];
        cartas[i] = cartas[j];
        cartas[j] = tmp;
    }
    return std::vector<Carta>(cartas.begin(), cartas.begin() + 3);
}

Carta Catalogo::buscarCarta(TipoUpgrade tipo) const {
    std::vector<Carta> todas = todasAsCartas();
    for (int i = 0; i < static_cast<int>(todas.size()); ++i) {
        if (todas[i].getTipo() == tipo)
            return todas[i];
    }
    return todas[0];
}