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
    double scaling;//scalling with stats
    stats scaling_stat;
    double accuracy;//between zero and one
    bool hostile; //if true is a damaging spell or attack
    bool is_spell;
}
{name, defense, bp, scalling, accuracy, hostility, is_spell}
