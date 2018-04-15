struct action{
    bool internal = false;
    string message, data;
}

enum damage_type{PHYS,MAGIC,PURE};
enum stats{STR,AGI,INT,LVL};
struct move{
    string name;
    int priority;
    damage_type defense;
    int bp;//basepower
    int mana_cost;
    double scaling;//scalling with stats
    stats scaling_stat;
    double accuracy;//between zero and one
    bool hostile; //if true is a damaging spell or attack
    bool is_spell;
}
//{name, priority, defense, bp, mana_cost, scaling, scaling stat, accuracy, hostility, is_spell}
/*Examples
{"Blizzard", 0, MAGIC, 80, 200, 0, INT, .95, true, true}
{"Heal Ally", 0, PURE, -40, 150, 0, INT, 1.0, false, true}
*/
