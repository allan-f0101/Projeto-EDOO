#ifndef COLETAVEIS_H
#define COLETAVEIS_H

class Coletaveis{
    protected:
        int qtd;
    public:
        Coletaveis(int v) : qtd(v) {}

        virtual ~Coletaveis(){}

        int getQtd() const {return qtd;}
        virtual void setQtd(int value){this->qtd = value;}

};

class XP : public Coletaveis{
    private:
        int xp;
    public:
        XP(int v) : Coletaveis(v), xp(v) {}

        void setQtd(int value) override{
            this->xp = value;
        }
};

class Moeda : public Coletaveis{
    private:
        int moeda;
    
    public:
        Moeda(int v) : Coletaveis(v), moeda(v) {}

        void setQtd(int value) override{
            this->moeda = value;
        }
};

class Vida : public Coletaveis{
    private:
        int vida;
    
    public:
        Vida(int v) : Coletaveis(v), vida(v) {}

        void setQtd(int value) override{
            this->vida = value;
        }
};

#endif