//Start class prototypes- will actually be in an implementation file later today
//Message me in discord if you have more to add or have suggestions

class Entity {

public:
  //Variables
int hp = 0;
int mp = 0;
int xp = 0;
int lvl = 1;
int speed = 0; // might end up being an int depending on heap
int str = 0; // stat will increase HP and warrior melee
int intel = 0; // stat increases MP and spell damage
int agi = 0; // stat increases speed and agile attack damage
bool isDead = 0;
bool isAlly = 0;
int row = 0 //Front row = 0 and back row = 1

  //Methods
void setHP ();
int getHP ();
void setMP ();
int getMP ();
void setLvl ();
int getLvl ();
void setSpeed ();
int getSpeed ();
void setStr ();
int getStr ();
void setIntel ();
int getIntel ();
void setAgi ();
int getAgi ();
void set_isDead ();
bool get_isDead ();
void set_isAlly ();
bool get_isAlly ();
void setRow ();
bool getRow ();

};

//Start player classes

class Warrior : public Entity :{

protected:

public:

};

class Rogue : public Entity {

protected:

public:

};

class Mage : public Entity {

protected:

public:

};

class Cleric : public character :{

protected:

public:

};

//Start NPC classes

// Mimic, centaur ???
