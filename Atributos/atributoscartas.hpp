#ifndef ATRIBUTOSCARTAS_HPP
#define ATRIBUTOSCARTAS_HPP

#include "jogador.hpp"


class Carta {
    private:
        int qtd;
    public:
        Carta() : qtd(0) {}
        virtual ~Carta() {};

        virtual int getQtd(){return qtd;}
        virtual void setQtd(int value){this->qtd = value;}
        
        virtual void aplicarBonus(Jogador& j) const = 0;
    };
    
class CartaDano : public Carta{
    private:
        int damage;
    
    public:
        CartaDano() : damage(0) {}

        int getQtd() override { return damage; }

        void setQtd(int value) override { this->damage = value; }

        void aplicarBonus(Jogador& j) const override;
    
    
};
    
class CartaCooldown : public Carta{
    private:
        int cooldown;
    
    public:
        CartaCooldown() : cooldown(0) {}
        int getQtd() override { return cooldown; }

        void setQtd(int value) override { this->cooldown = value; }

        void aplicarBonus(Jogador& j) const override;
};
    
class CartaSpeed : public Carta{
    private:
        int speed;
    
    public:
        CartaSpeed() : speed(0) {}
        int getQtd() override { return speed; }

        void setQtd(int value) override { this->speed = value; }

        void aplicarBonus(Jogador& j) const override;
    
    
};

class CartaHeal : public Carta{
    private:
        int heal;
    
    public:
        CartaHeal() : heal(0) {}
        int getQtd() override { return heal; }

        void setQtd(int value) override { this->heal = value; }

        void aplicarBonus(Jogador& j) const override;

};

class CartaMaxHealth : public Carta{
    private:
        int max_health;

    public:
        CartaMaxHealth() : max_health(0) {}
        int getQtd() override { return max_health; }

        void setQtd(int value) override { this->max_health = value; }

        void aplicarBonus(Jogador& j) const override;


};

#endif