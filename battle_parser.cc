#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <map>
#include <stack>
#include <cmath>
#include <boost/regex.hpp>
#include <assert.h>
#include <random>
using namespace std;
//using namespace boost;

struct battle_data{
    //brook format: int move_Type, bool hostility, double hitchance, int damgage, int damage_type
    //move_type formating: Attack==0, Spell=1,Other=2; damage type formating: Pure: 0, Physical: 1, Magic: 2
    stringstream brook;
    vector<string> effects;
    string source, target;
    battle_data() : brook(), effects(), source(), target() {}
    battle_data(const battle_data &pain)
    : brook(pain.brook.str()), effects(pain.effects), source(pain.source), target(pain.target) {}
    battle_data(string trout, vector<string> fx, string origin, string down)
    : brook(trout), effects(fx), source(origin), target(down) {}
};

struct action{
    bool internal;
    string message, data;
    int speed;
    int priority;
    int id;
    //for internal only
    battle_data river;
    action(int spd, int prior, int idn, string msg, string info)
    : internal(false), speed(spd), priority(prior), id(idn), message(msg), data(info) {}
    action(const battle_data &plan, int idn) : river(plan), id(idn) {}
};
class stak : public std::stack<action>{
public:
    action loot(){
        action temp = this->top();
        this->pop();
        return temp;
    }
};
//TODO:Move above to own header
/*bool hit_check(const &chance){
    random_device rd;  //Will be used to obtain a seed for the random number engine
    mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    uniform_real_distribution<> distr(0.0, 1.0);
    return (chance>=distr(gen));
}*/


void ext_parser(action act,stak &stax){
    string data = act.data;
    stringstream creek;
    vector<string> out_targets;
    string temp;
    string outsource;
    boost::smatch lighter;
    int num = 0;
    double odds = 0.0;
    boost::regex current("(?<=Source: )[^<]([^>])+");//Everthing precede by "Source "" any followed by "
    if(boost::regex_search(data, lighter, current)) outsource = lighter.str();
    else{
        cout << "Message: " << act.message << "\nThe data: $ " << data << endl;
        assert(false);
    }
    boost::regex ignorant("(?<=Source:)[^\$]+", boost::regex::icase);//to case that is
    current = "(?<=Type: )[[:alpha:]]+(?=\$)";
    if(boost::regex_search(data, lighter, current)){
        temp = lighter.str();
        ignorant = "attack";
        if(boost::regex_search(data, ignorant)) {creek << "0 "; goto type_end;}
        ignorant = "spell";
        if(boost::regex_search(data, ignorant)) {creek << "1 "; goto type_end;}
        ignorant = "other";
        if(boost::regex_search(data, ignorant)) {creek << "2 "; goto type_end;}
        //throw range_error("In ext_parser lin");
        cout << "Message: " << act.message << "   Temp: " << temp << "\nThe data: $ " << data << endl;
        assert(false);
    }
    else{
        cout << "Message: " << act.message << "\nThe data: $ " << data << endl;
        assert(false);
    }
    type_end:;
    current = "(?<=Hostility: )(true|false)(?=\$)";
    if(boost::regex_search(data, lighter, current)){
        temp = lighter.str();
        creek << temp << " ";
    }
    else{
        cout << "Message: " << act.message << "\nThe data: $ " << data << endl;
        assert(false);
    }
    current = "(?<=Hitchance: )[[:digit:].]+(?=\$)";
    if(boost::regex_search(data, lighter, current)){
        temp = lighter.str();
        odds = stod(temp);
    }
    else odds = 1.0;

    current = "(?<=DMG: )[[:digit:]]+(?=\$)";
    if(boost::regex_search(data, lighter, current)){
        temp = lighter.str();
        num = stoi(temp);
    }
    else num = 0;
    creek << num << " ";
    current = "(?<=Typing: )[^\$]+";
    if(num){
        if(boost::regex_search(data, lighter, current)){
            temp = lighter.str();
            ignorant = "pure";
            if(boost::regex_search(temp, ignorant)) {creek << "0 "; goto dmg_type_end;}
            ignorant = "phys";
            if(boost::regex_search(data, ignorant)) {creek << "1 "; goto dmg_type_end;}
            ignorant = "magic";
            if(boost::regex_search(data, ignorant)) {creek << "2 "; goto dmg_type_end;}
            cout << "Message: " << act.message << "   Temp: " << temp << "\nThe data: $ " << data << endl;
            assert(false);
        }
    }
    dmg_type_end:;
    current = "(?<=Targets: )[^\$]+";
    if(boost::regex_search(data, lighter,current)){
        temp = lighter.str();
        current ="(?<=\<)[^>]+";
        auto words_begin = boost::sregex_iterator(data.begin(), data.end(), current);
        auto words_end = boost::sregex_iterator();
        for (auto it = words_begin; it != words_end; ++it)
            out_targets.push_back(it->str());
    }
    data = creek.str();
    for(string s:out_targets){
        stax.push(action(battle_data(data,{}, outsource, s), act.id));
    }
}




int main(){

}
