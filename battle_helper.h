#include <stack>
#include <vector>
#include <array>
#include <string>
#include <sstream>
#include <tuple>
using namespace std;

namespace battle{
    enum damage_type{PURE=0,PHYSICAL=1,MAGIC=2};
    enum move_type{ATTACK=0,SPELL=1,OTHER=2};
    //enum targets{FOE, ALLY, ALL, NONE};//
}

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
//{name, priority, defense, bp, mana_cost, scaling, scaling stat, accuracy, hostility, is_spell}
class move{
    string name, message, source, flavor_txt; //message is goint be liked used, cast, or summoned, or taclked
    int prioity, bp, mana_cost;
    array<bool, 4> targeting; //Enemy, Ally, Self, Hits all or one
    array<int,8> stat_scaling;
    double accuracy;
    bool hostility;
    battle::move_type kind;
    battle::damage_type dmg;
    int dmg_calc(const array<int,8> &in){
        int out = bp;
        for (size_t k = 0; k < 8; k++) out += stat_scaling[k]*in[k];
        return;
    }

public:
    move(string nam, string msg, battle::move_type mvtyp, battle::damage_type dmgt, int base, int pri = 0, array<bool,4> targ, const array<int,8> &scaling = {0,0,0,0,0,0,0,0}, int mpcost, double accu = 1.0, bool hos = 1, string flvr = "")
    : prioity(pri), source(""), name(name), bp(base), message(msg), stat_scaling(scaling), dmg(dmgt), accuracy(accu), kind(),
     hostility(hos), flavor_txt(flvr),  mana_cost(mp_cost), targeting(targ) {}
    set_source(const string &in){source = in};
    void set_flavor_text(const string &in, const array<int,8> &stats){flavor_txt = in}
    string get_flavor_text(const array<int,8> &stats){
        array<string,3> mtypes = {"Attack", "Spell", "Other"};
        array<string,3> dtypes = {"Pure", "Physical", "Magic"};
        stringstring out;
        out << "Name: " <<  name << " ";
        out << flavor_txt << endl;
        out << "Mana Cost: " << mana_cost;
        out << " Hostile: " << boolalpha << hostility;
        out << " Kind of Move: " << mtypes[kind];
        out << " Damage Type: " << dtypes[dmg];
        int out_dmg = dmg_calc(stats);
        if(dmg>0) out << "Damage: " << out_dmg;
        else if(dmg<0) out << " Heal: " << (-1*out_dmg);
        return out.str;
    }
    array<bool, 4> get_targeting(){return targeting};
    string get_data(const vector<string> &targets, const array<int,8> &stats){
        array<string,3> mtypes = {"Attack", "Spell", "Other"};
        array<string,3> dtypes = {"Pure", "Physical", "Magic"};
        stringstream dat;
        dat << "Type: " << mtypes[kind] << "$ ";
        dat << "DMG: " << dmg_calc(stats) << "$ ";
        dat << " Hitchance: " << accuracy << "$ ";
        dat << " Typing: " << dtypes[dmg] << "$ ";
        dat << " Hostile: " << boolalpha << hostility << "$ ";
        dat << " Source: " << source << "$ ";
        dat << " Target: ";
        for(string s:targets) data << " <" << s >> ">";
        dat << "$";
        return dat.str();
    }
    int get_Priority(){return prioity;}
    string get_message(){return source+" "+message};
};
class stak : public std::stack<action>{
public:
    action loot(){
        action temp = this->top();
        this->pop();
        return temp;
    }
};
