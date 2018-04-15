struct action{
    bool internal = false;
    string message, data;
}

enum damage_type{PHYS,MAGIC,PURE};
enum stats{STR,AGI,INT,LVL};
struct move{
    string name;
    damage_type defense;
    int bp;//basepower
    int mana_cost;
    double scaling;//scalling with stats
    stats scaling_stat;
    double accuracy;//between zero and one
    bool hostile; //if true is a damaging spell or attack
    bool is_spell;
}
//{name, defense, bp, mana_cost, scalling, accuracy, hostility, is_spell}
/*Examples
{"Blizzard", MAGIC, 80, 200, 0, INT, .95, true, true}
{"Heal Ally", PURE, -40, 150, 0, INT, 1.0, false, true}
*/
