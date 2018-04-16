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
    //brook used for string stream
    string brook, source, target;
    vector<string> effects;
    battle_data() : brook(), effects(), source(), target() {}
    //battle_data(const battle_data &pain)
    //: brook(pain.brook.str()), effects(pain.effects), source(pain.source), target(pain.target) {}
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


void ext_parser(action act/*,stak &stax*/){
    string data = act.data;
    stringstream creek;
    vector<string> out_targets;
    string temp;
    string outsource;
    cout << data << endl;
    boost::smatch lighter;
    int num = 0;
    double odds = 0.0;
    boost::regex current("(?<=Source: )[^$]+");//"(?<=Source: <)([^>])+");//Everthing precede by "Source "" any followed by "
    if(boost::regex_search(data, lighter, current)) outsource = lighter.str();
    else{
        cout << "Message: " << act.message << "\nThe data: $ " << data << endl;
        assert(false);
    }
    lighter = boost::smatch();
    boost::regbase::flag_type nocase = boost::regex::icase;
    boost::regex ignorant("(?<=Source:)[^\$]+", boost::regex::icase);//to case that is
    current = "(?<=Type: )[^\$]+";
    if(boost::regex_search(data, lighter, current)){
        temp = lighter.str();
        ignorant.assign("attack", nocase);
        if(boost::regex_search(data, ignorant)) {creek << "0 "; goto type_end;}
        ignorant.assign("spell", nocase);
        if(boost::regex_search(data, ignorant)) {creek << "1 "; goto type_end;}
        ignorant.assign("other",nocase);
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
    lighter = boost::smatch();
    //ignorant.assign("(?<=Hostility: )(true|false)(?=\$)", nocase);
    current = "(?<=Hostile: )(true|false)";
    if(boost::regex_search(data, lighter, current)){
        temp = lighter.str();
        //cout << "host: " << temp << endl;
        creek << temp << " ";
    }
    else{
        cout << "Message: " << act.message << "\nThe data: $ " << data << endl;
        assert(false);
    }
    lighter = boost::smatch();
    current = "(?<=Hitchance: )[[:digit:].]+(?=\$)";
    if(boost::regex_search(data, lighter, current)){
        temp = lighter.str();
        odds = stod(temp);
    }
    else odds = 1.0;
    lighter = boost::smatch();
    current = "(?<=DMG: )[[:digit:]]+";
    if(boost::regex_search(data, lighter, current)){
        temp = lighter.str();
        cout << temp << endl;
        num = stoi(temp);
    }
    else throw;//num = 0;
    lighter = boost::smatch();
    creek << num << " ";
    current = "(?<=Typing: )[^\$]+";
    if(num){
        if(boost::regex_search(data, lighter, current)){
            temp = lighter.str();
            ignorant.assign("pure", nocase);
            if(boost::regex_search(temp, ignorant)) {creek << "0 "; goto dmg_type_end;}
            ignorant.assign("phys", nocase);
            if(boost::regex_search(data, ignorant)) {creek << "1 "; goto dmg_type_end;}
            ignorant.assign("magic", nocase);
            if(boost::regex_search(data, ignorant)) {creek << "2 "; goto dmg_type_end;}
            cout << "Message: " << act.message << "   Temp: " << temp << "\nThe data: $ " << data << endl;
            assert(false);
        }
    }
    dmg_type_end:;
    lighter = boost::smatch();
    current = "(?<=Targets: )[^\$]+";
    if(boost::regex_search(data, lighter,current)){
        temp = lighter.str();
        cout << "Targ: " << temp << endl; 
        current ="(?<=\<)[^>]+";
        auto words_begin = boost::sregex_iterator(data.begin(), data.end(), current);
        auto words_end = boost::sregex_iterator();
        for (auto it = words_begin; it != words_end; ++it)
            out_targets.push_back(it->str());
    }
    data = creek.str();
    cout << "Processed data: " << data << endl;
    cout << "Targets: ";
    for(string s:out_targets){
        cout << s << "  ";
        //stax.push(action(battle_data(data,{}, outsource, s), act.id));
    }
    cout << endl;
}




int main(){
    string frank;
    getline(cin,frank);
    action move(0, 0, 0, "", frank);
    ext_parser(move);
}
