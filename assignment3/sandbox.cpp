/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */

#include "class.h"

void sandbox() {
  Player kenqia("kenqia");
  Player god("god", 1000, 1000, 1000, 1000, 50, 50);

  kenqia.attack(god);
  kenqia.attack(god);
  god.attack(kenqia);
  god.attack(kenqia);
  god.magic_attack(kenqia);
  god.magic_attack(kenqia);
  god.magic_attack(kenqia);
  kenqia.heal(50);
  god.heal(kenqia, 1000);
}