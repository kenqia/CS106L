#include <string>
#include <iostream>

using std::string;
using std::cout; using std::endl;

class player{
    private:
        string name;
        int HP;
        size_t MP;
        size_t ATK;
        size_t DEF;
        bool living;
    
    bool check_living(const player& other) const {
        if(!other.living){
            cout << other.name << " was cooked." << endl;
            return false; 
        }
        return true;
    }

    public:
        player() : name("you"), HP(100), MP(100), ATK(20), DEF(10), living(true){

        }

        player(const string& name) : name(name), HP(100), MP(100), ATK(20), DEF(10), living(true){

        }

        player(const string& name, size_t HP, size_t MP, size_t ATK, size_t DEF) : name(name), HP(HP), MP(MP), ATK(ATK), DEF(DEF), living(true){

        }

        void attack(player& other){
            if(!check_living(other)) return;

            if(this->ATK <= other.DEF){
                cout << this->name << " can't even hit "<< other.name << "!" << endl;
            }else{
                size_t damage =(this->ATK - other.DEF);
                other.HP -= damage;
                cout << this->name << " hit "<< other.name << damage <<"!" << endl;
                if(other.HP <= 0){
                    other.living = false;
                    cout << other.name << " so dead!" << endl;
                }
            }
        }

        void heal(player& p, size_t HP){
            int hp_heal = p.HP + HP; 
            
            if(hp_heal > 100) hp_heal = 100;

            cout << p.name << " have healed " << HP <<endl;
            if(p.HP <= 0 && hp_heal > 0){
                cout << p.name << " get out of the bed!" << endl;
            }

            p.HP = hp_heal;
        }

        const string& get_name() const { return this->name; }
        size_t get_HP() const { return this->HP; }
        size_t get_MP() const { return this->MP; }
        
};