#include "class.h"

using std::string;
using std::cout; using std::endl;

bool Player::check_living() const {
    if(!this->living && this->HP <= 0){
        cout << this->name << " was cooked." << endl;
        return false; 
    }
    return true;
}

void Player::attack(Player& other){
    if(!check_living()) return;

    int damage =(this->ATK - other.DEF);
    if(damage <= 0){
        cout << this->name << " can't even hit "<< other.name << "!" << endl;
    }else{
        other.HP -= damage;
        cout << this->name << " hit "<< other.name << damage <<"!" << endl;
        if(other.HP <= 0){
            other.living = false;
            cout << other.name << " so dead!" << endl;
        }
    }
}

void Player::magic_attack(Player& other){
    if(!check_living()) return;
    
    int damage =(2 * this->ATK - other.DEF);

    if(damage <= 0){
        cout << this->name << " can't even hit "<< other.name << "!" << endl;
    }else{
        other.HP -= damage;
        cout << this->name << " 'magic' hit "<< other.name << damage <<"!" << endl;
        if(other.HP <= 0){
            other.living = false;
            cout << other.name << " so dead!" << endl;
        }
    }
}

void Player::heal(Player& p, int HP){
    if(!check_living()) return;

    int hp_heal = p.HP + HP; 
    
    if(hp_heal > p.MAXHP) hp_heal = p.MAXHP;
     cout << p.name << " have healed " << (hp_heal - p.HP) <<endl;

    if(p.HP <= 0 && hp_heal > 0){
        cout << p.name << " get out of the bed!" << endl;
    }

    p.HP = hp_heal;
}

void Player::heal(int HP){
    heal(*this, HP);
}