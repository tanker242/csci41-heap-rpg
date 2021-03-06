#pramga once
#include "battle_helper.h"
#include <assert.h>
#include <boost/regex.hpp>
#include <cmath>
#include <iostream>
#include <random>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <term.h>
#include <unistd.h>
#include <unordered_map>
#include <vector>
using namespace std;
// TODO: impliment dynamic events

void ClearScreen() {
  if (!cur_term) {
    int result;
    setupterm(NULL, STDOUT_FILENO, &result);
    if (result <= 0)
      return;
  }
  putp(tigetstr("clear"));
}

bool hit_check(const double &chance) {
  random_device rd; // Will be used to obtain a seed for the random number
                    // engine
  mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  uniform_real_distribution<> distr(0.0, 1.0);
  return (chance >= distr(gen));
}
int rand_int(const int &max) {
  random_device rd; // Will be used to obtain a seed for the random number
                    // engine
  mt19937 gen(rd()); // Standard mersenne_twister_engine seeded with rd()
  uniform_int_distribution<int> distr(0, max);
  return distr(gen);
}
void ext_parser(stak &);
void intern_parser(stak &, map<string, Entity>, map<string, Entity>);
void damage_calc(int damage, battle::damage_type type, Entity &targ);
void print_actors(map<string, Entity> &al, map<string, Entity> &foe);
void battle(map<string, Entity> &allies, map<string, Entity> &foes) {
  // unordered_map<string,Entity> party;
  // unordered_map<string,Entity> foes;

  string inputer;
  Heap<action> move_pile;
  stak act_stack;
  // User Move Selection
  bool fail = 0;
  for (auto iter = allies.begin(); iter != allies.end(); ++iter) {
    if (*allies.get_isDead())
      continue;

    while (true) {
      ClearScreen();
      print_actors(allies, foes);
      size_t input = 0;
      cout << "Turn for " << iter->second.get_name() << endl;
      iter->print_flav_txt();

      if (fail) {
        cout << "You did not pick a valid move\n";
        fail = false;
      }
      cout << "Input a move to use by its number\n";
      cin >> input;
      if (!cin || input >= iter->->second.moves.size()) {
        cin.clear();
        cin.ignore();
        fail = true;
        continue;
      }
      move& tatic = iter->second.moves.at(input);
      //Targeting
      vector<string> targs;
      array<bool,4> mark = tatic->get_targeting();
      if(!(mark[0]||mark[1]) targs.push_back(iter->get_name());
      else{ if(mark[0]){
          for(auto mit)
      }
    }
  }
  // for(Entity ent:allies) party.insert(ent.get_name, ent);
  // for(Entity ent:enemies_in) foes.insert(ent.get_name, ent);
  while (true) {
    // TODO: get user input, and run ai
    for () {
      /* code */
    }
    while (!move_pile.empty())
      act_stack.push(move_pile.pop());
    while (!act_stack.empty()) {
      if (act_stack.top().internal)
        intern_parser(act_stack);
      else
        ext_parser(act_stack);
    }
  }
}

void intern_parser(stak &stax, map<string, Entity> &party,
                   map<string, Entity> &foes) {
  using namespace battle;
  action move = stax.loot();
  stringstream datum(move.river.brook);
  move.river.target
      // brook format: int move_Type, bool hostility, double hitchance, int
      // damgage, int damage_type move_type formating: Attack==0,
      // Spell=1,Other=2; damage type formating: Pure: 0, Physical: 1, Magic: 2
      // parse the datum
          move_type cat; // catagory
  bool hostile;
  double hitchance;
  int damgage, temp;
  damage_type def_how; // what armor to use
  datum >> temp;
  cat = (move_type)temp;
  datum >> hostile;
  datum >> hitchance;

  if (!hit_check(hitchance)) {
    cout << move.river.target << " dodged" << end;
    return;
  }
  // TODO general hostile hit events
  datum >> damage;
  // damage type doesnt have to be in damage is 0
  if (damage) {
    datum >> temp;
    def_how = (damage_type)temp;
    // TODO on hit reaction events
    if (move.river.plyr_targ)
      damage_calc(
          damage, def_how,
          *(party.find(move.river.source))); // TODO likely bugs with
                                             // dereference, check if it works
    else
      damage_calc(damage, def_how, *(foes.find(move.river.source)));
  }
  // Check for after attack events
}

void damage_calc(int damage, battle::damage_type type, Entity &targ) {
  using namespace battle;
  if (targ.get_isDead()) {
    cout << "The word of THE DEVELOPERS says to respect the fallen.\n";
    return;
  }
  if (type == PHYSICAL) damage = damage*(1-((.05*targ.get_armor())/(1+0.5*targ.get_armor()));
    if(type==MAGIC) damage*(1-((.05*targ.get_armor())/(1+0.5*targ.get_armor()));
    damage = targ.damage(damage);
    if(damage>0){
      cout << targ.get_name() << " took " << damage << " damage.";
      if (targ.get_isDead())
        cout << targ.get_name()
             << " has been slain. They will be missed, for an infintestimal "
                "amount of time.\n";
    }
    else cout << targ.get_name() << " was healed for " << damage << " HP.";
}

void ext_parser(stak &stax) {
  // TODO remove debug code
  action act = stax.loot();
  string data = act.data;
  stringstream creek;
  vector<string> out_targets;
  string temp;
  string outsource;
  cout << act.message << endl;
  boost::smatch lighter;
  int num = 0;
  double odds = 0.0;
  boost::regex current(
      "(?<=Source: )[^$]+"); //"(?<=Source: <)([^>])+");//Everthing precede by
                             //"Source "" any followed by "
  if (boost::regex_search(data, lighter, current))
    outsource = lighter.str();
  else {
    cout << "Message: " << act.message << "\nThe data: $ " << data << endl;
    assert(false);
  }
  lighter = boost::smatch();
  boost::regbase::flag_type nocase = boost::regex::icase;
  boost::regex ignorant("(?<=Source:)[^\$]+",
                        boost::regex::icase); // to case that is
  current = "(?<=Type: )[^\$]+";              // Attack type
  if (boost::regex_search(data, lighter, current)) {
    temp = lighter.str();
    ignorant.assign("attack", nocase);
    if (boost::regex_search(data, ignorant)) {
      creek << "0 ";
      goto type_end;
    }
    ignorant.assign("spell", nocase);
    if (boost::regex_search(data, ignorant)) {
      creek << "1 ";
      goto type_end;
    }
    ignorant.assign("other", nocase);
    if (boost::regex_search(data, ignorant)) {
      creek << "2 ";
      goto type_end;
    }
    // throw range_error("In ext_parser lin");
    cout << "Message: " << act.message << "   Temp: " << temp
         << "\nThe data: $ " << data << endl;
    assert(false);
  } else {
    cout << "Message: " << act.message << "\nThe data: $ " << data << endl;
    assert(false);
  }
type_end:;
  lighter = boost::smatch();
  current = "(?<=Hostile: )(true|false)"; // Hostility
  temp = lighter.str();
  if (boost::regex_search(data, lighter, current)) {
    creek << temp << " ";
  } else {
    cout << "Message: " << act.message << "\nThe data: $ " << data << endl;
    assert(false);
  }
  lighter = boost::smatch();
  current = "(?<=Hitchance: )([.]|[0-9]{1})+"; // Hitchance
  if (boost::regex_search(data, lighter, current)) {
    temp = lighter.str();
    odds = stod(temp);
  } else
    odds = 1.0;
  creek << odds << " ";
  lighter = boost::smatch();
  current = "(?<=DMG: )[[:digit:]]+"; // The damage
  if (boost::regex_search(data, lighter, current)) {
    temp = lighter.str();
    num = stoi(temp);
  } else
    throw; // num = 0;
  lighter = boost::smatch();
  creek << num << " ";
  current = "(?<=Typing: )[^\$]+"; // Damage type
  if (num) {
    if (boost::regex_search(data, lighter, current)) {
      temp = lighter.str();
      ignorant.assign("pure", nocase);
      if (boost::regex_search(temp, ignorant)) {
        creek << "0 ";
        goto dmg_type_end;
      }
      ignorant.assign("phys", nocase);
      if (boost::regex_search(data, ignorant)) {
        creek << "1 ";
        goto dmg_type_end;
      }
      ignorant.assign("magic", nocase);
      if (boost::regex_search(data, ignorant)) {
        creek << "2 ";
        goto dmg_type_end;
      }
      cout << "Message: " << act.message << "   Temp: " << temp
           << "\nThe data: $ " << data << endl;
      assert(false);
    }
  }
dmg_type_end:;
  lighter = boost::smatch();
  current = "(?<=Targets: )[^\$]+"; // The targets
  if (boost::regex_search(data, lighter, current)) {
    temp = lighter.str();
    current = "(?<=\<)[^>]+";
    auto words_begin =
        boost::sregex_iterator(data.begin(), data.end(), current);
    auto words_end = boost::sregex_iterator();
    for (auto it = words_begin; it != words_end; ++it)
      out_targets.push_back(it->str());
  }
  data = creek.str();
  // cout << "Processed data: " << data << endl;
  // cout << "Targets: ";
  for (string s : out_targets) {
    cout << s << "  ";
    stax.push(action(battle_data(data, {}, outsource, s, true, false),
                     act.id)); // TODO set is_source_player and is_target_player
  }
}

void print_actors(map<string, Entity> &al, map<string, Entity> &foe) {
  cout << "Your party.\n";
  for (auto it = al.begin(); it != al.end; it++) {
    cout << it->get_name() << "   "
         << "HP: " << it->getHp() << "/" << it->get_stat(XHP)
         << " Mana: " << it->getMp << "/" << it->get_stat(XMP) << endl;
  }
  cout << "\nYour foes.\n";
  for (auto it = foe.begin(); it != feo.end; it++) {
    cout << it->get_name() << "   "
         << "HP: " << it->getHp() << "/" << it->get_stat(XHP)
         << " Mana: " << it->getMp << "/" << it->get_stat(XMP) << endl;
  }
}
