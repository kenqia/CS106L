#include <string>
#include <iostream>

class Player{
    private:
        std::string name;
        int MAXHP;
        int HP;
        int MP;
        int MAXMP;
        int ATK;
        int DEF;
        bool living;
    
    bool check_living() const;

    public:
        Player() : name("you"), MAXHP(100), HP(100), MP(100), MAXMP(100), ATK(20), DEF(10), living(true) {}

        Player(const std::string& name) : name(name), MAXHP(100), HP(100), MP(100), MAXMP(100), ATK(20), DEF(10), living(true){}

        Player(const std::string& name, int MAXHP, int HP, int MP, int MAXMP, int ATK, int DEF) : name(name), MAXHP(MAXHP), HP(HP), MP(MP), MAXMP(MAXMP), ATK(ATK), DEF(DEF), living(true){}

        void attack(Player& other);
        void magic_attack(Player& other);
        void heal(int HP);
        void heal(Player& p, int HP);

        const std::string& get_name() const { return this->name; }
        int get_HP() const { return this->HP; }
        int get_MP() const { return this->MP; }
        int get_ATK() const { return this->ATK; }
        int get_DEF() const { return this->DEF; }
        bool get_living() const { return this->living; }

};