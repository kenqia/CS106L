#include "user.h"

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string& name)
  : _name(name)
  , _friends(nullptr)
  , _size(0)
  , _capacity(0)
{
}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void
User::add_friend(const std::string& name)
{
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string* newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string
User::get_name() const
{
  return _name;
}

/**
 * Returns the number of friends this User has.
 */
size_t
User::size() const
{
  return _size;
}

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string& name)
{
  _friends[index] = name;
}

std::ostream& operator<<(std::ostream& os, const User& obj){
  os << "User(name=" << obj._name << ", friends=[";
  
  for(size_t i = 0 ; i < obj._size ; ++i){
    if(i == 0){
      os << obj._friends[i];
    }
    else{
      os << ", " << obj._friends[i];
    }
  }
  os << "])";
  return os;
}

User::~User(){
  delete[] _friends;
}

User::User(const User& user): _name(user._name), _size(user._size), _capacity(user._capacity)
{
  if(_capacity != 0){
    _friends = new std::string[_capacity];
    for(size_t i = 0 ; i < _size ; i++){
      _friends[i] = user._friends[i];
    }
  }else{
    _friends = nullptr;
  }
}

User& User::operator=(const User& user){
  if(this != &user){
    delete[] _friends;
    _name = user._name;
    _size = user._size;
    _capacity = user._capacity;
    _friends = new std::string[_capacity];
    for(size_t i = 0 ; i < _size ; i++){
      _friends[i] = user._friends[i];
    }
  }
  return *this;
}

User& User::operator+=(User& other){
  if(this != &other){
    this->add_friend(other._name);
    other.add_friend(this->_name);
  }
  return *this;
}

bool User::operator<(const User& other) const{
  return this->_name < other._name;
}