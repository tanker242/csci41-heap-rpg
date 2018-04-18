#include <string>
#include <array>
#include <alogrithm>
enum stat_type {STR=0,INT=1,AGI=2,SPD=3,ARM=4,MR=5,XHP=6,XMP=7};
enum postion {FRONT,BACK};
class Entity{
    string name;
    int hp;
    int mp;
    int xp;
    int level;
    array<int,8> stats;
    array<int,8> stat_gain;
    array<int,8> delta_stat;
    bool Still_Alive;
    bool faction;//true for player, false for enemy
    postion row;
    void death_checker(){
        if(hp<1) Still_Alive = false;
    }
public:
  //Method
  //Use the enum
  int get_stat(stat_type in){return stats[in];}
  void change_stat(stat_type stat, int change){
      if((stat!=XHP)&&(stat!=XMP)){
          stats[stat] += change;
          delta_stat[stat] += change;
          return;
      }
      //now checks for hp stuff
      if(stat==XHP){
          int temp = stats[XHP];
          stats[XHP] -= change;
          if(stats[XHP]<1) stat[XHP] = 1;
          delta_stat[XHP] += (stats[XHP]-temp);
          if(hp>stats[XHP]) hp = stats[XHP];
      }
      else{
          int temp = stats[XMP];
          stats[XMP] -= change;
          if(stats[XMP]<1) stat[XMP] = 1;
          delta_stat[XMP] += (stats[XMP]-temp);
          if(mp>stats[XMP]) mp = stats[XMP];
      }
  }
  void end_battle(){
      for(size_t k = 0; k<8; k++) stats[k] -= delta_stat[k];
      delta_stat.fill(0);
  }
  void get_name(){return name;}
  void lvl_up(){
      for(size_t k = 0; k<8; k++) stats[k] += stat_gain[k];
      level++;
  }
  int get_level(){return level;}//There is nosetter for level on purpose
  int getHp(){return hp;}
  int damage(int in){
      int temp = hp;
      hp -= in;
      clamp(hp, 0, stats[XHP]);
      return (temp-hp);
  }
  void subMp (int in){
      int temp = mp;
      mp -= in;
      clamp(hp, 0, stats[XHP]);
  }
  int getMp (){return mp}
  void set_life_status (bool in){Still_Alive = in;}
  bool is_alive(){return Still_Alive;}
  position get_row(){return row;}
  bool get_faction{return faction;}
  void changeRow(){
      if(row==FRONT) row==BACK;
      else row==FRONT;
  }

//Constructor
Entity() {}
//You can enter the arrays like this
//{STR,INT,AGI,SPD,ARM,MR,XHP,XMP}
Entity(array<int,8> base, array<int,8> per_lvl, int lvl, bool side, string named)
: stats(base), stat_gain(per_lvl), level(level), faction(side), Still_Alive(true), row(front), xp(0), name(named){
    delta_stat.file(0);
    hp = stats[XHP];
    mp = stats[XMP];
}
};
