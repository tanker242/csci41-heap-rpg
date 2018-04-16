#include <stack>
#include <vector>
#include <string>
struct battle_data{
    //brook format: int move_Type, bool hostility, double hitchance, int damgage, int damage_type
    //move_type formating: Attack==0, Spell=1,Other=2; damage type formating: Pure: 0, Physical: 1, Magic: 2
    std::string brook;
    std::vector<string> effects;
    std::string source, target;
    bool plyr_src, plyr_targ;
    battle_data() : brook(), effects(), source(), target(), plyr_src(true), plyr_targ(true) {}
    //battle_data(const battle_data &pain)
    //: brook(pain.brook.str()), effects(pain.effects), source(pain.source), target(pain.target) {}
    battle_data(string trout, vector<string> fx, string origin, string down, bool scr, bool targ)
    : brook(trout), effects(fx), source(origin), target(down), plyr_src(scr), plyr_targ(targ) {}
};

struct action{
    bool internal;
    std::string message, data;
    int speed;
    int priority;
    int id;
    //for internal only
    battle_data river;
    action(int spd, int prior, int idn, std::string msg, std::string info)
    : internal(false), speed(spd), priority(prior), id(idn), message(msg), data(info), river() {}
    action(const battle_data &plan, int idn) : river(plan), id(idn), internal(true), speed(0), priority(0), message(), {}
};
class stak : public std::stack<action>{
public:
    action loot(){
        action temp = this->top();
        this->pop();
        return temp;
    }
};
