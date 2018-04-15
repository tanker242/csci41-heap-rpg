//Start class prototypes- will actually be in an implementation file later today
//Message me in discord if you have more to add or have suggestions

class character {

static NPC = 0;
static player = 0;

protected:
int hp = 0;
int mp = 0;
int xp = 0;
int level = 1;
double speed = 0; // might end up being an int depending on heap
int str = 0; // stat will increase HP and warrior melee
int mind = 0; // stat increases MP and spell damage
int agi = 0; // stat increases speed and agile attack damage
bool isDead = 0;
bool isAlly
int row = 0 //Front row = 0 and back row = 1


public:

void setHP ();
int getHP ();
void setMP ();
int getMP ();
int getLevel ();
void setSpeed ();
double getSpeed ();
void setStr ();
int getStr ();
void setMind ();
int getMind ();
void setAgi ();
int getAgi ();
void set_isDead ();
bool get_isDead ();
void set_isAlly ();
bool get_isAlly ();
void setRow ();
int getRow ();

};

//Start player classes

class warrior:character :{

protected:

public:

};

class rogue:character {

protected:

public:

};

class mage:character {

protected:

public:

};

class cleric:character :{

protected:

public:

};

//Start NPC classes

// Mimic, centaur ???
