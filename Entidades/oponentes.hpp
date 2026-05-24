#ifndef INIMIGOS_HPP
#define INIMIGOS_HPP

#include <string>
#include <iostream>

class Inimigo {
protected:
    std::string nome;
    int vida;
    int vidaMaxima;
    float velocidade;

public:
    Inimigo(const std::string& nome, int vida, float velocidade)
        : nome(nome), vida(vida), vidaMaxima(vida), velocidade(velocidade) {}

    virtual ~Inimigo() = default;

    virtual bool receberDano(int dano);

    bool        estaVivo()       const { return vida > 0; }
    int         getVida()        const { return vida; }
    int         getVidaMaxima()  const { return vidaMaxima; }
    float       getVelocidade()  const { return velocidade; }
    std::string getNome()        const { return nome; }

    virtual void exibirStatus() const;
};
class RoboVoador : public Inimigo {
public:
    RoboVoador() : Inimigo("RoboVoador", 20, 3.5f) {}
};

class RoboBola : public Inimigo {
public:
    RoboBola() : Inimigo("RoboBola", 30, 2.5f) {}
};

class RoboZangao : public Inimigo {
public:
    RoboZangao() : Inimigo("RoboZangao", 30, 3.0f) {}
};

class RoboCobra : public Inimigo {
public:
    RoboCobra() : Inimigo("RoboCobra", 50, 2.0f) {}
};

class RoboDragao : public Inimigo {
private:
    bool modoFuria;

public:
    RoboDragao() : Inimigo("RoboDragao", 500, 1.5f), modoFuria(false) {}

    bool receberDano(int dano);

    bool getModoFuria() const { return modoFuria; }

    void exibirStatus() const override;
};

#endif