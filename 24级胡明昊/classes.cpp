#include<iostream>
#include<vector>
//To simplize the code
#define map_vector std::vector<std::vector<char>>

struct Point {
    int column, row;
};
//To build the basic system to receive inputs from the user
class System {


};
//To build the sub-system dealing with the map 
class System_Map : System {
public:
    int* capture_map_size();
};
class System_Obstrucal :System {
public:
    Point* capture_obstrucal_summon_point();
};
class System_Entity {
public:
    int* capture_entity_hp();
    int* capture_entity_mp();
    Point* capture_entity_spawn_point();
};
class Map;
class Entity;
class Obstrucal {
public:
    void obstrucal_summon_point_set(Point* point_set);
    Point obstrcal_summon_point_output(Obstrucal obstrucal);
    void obstrucal_summon_try(map_vector& game_map, Obstrucal obstrucal, Map& map);
private:
    Point summon_point;
};
//To build a rectangle-sized map 
class Map {
public:
    void map_size_receive(int* mape_size_input); //To set the size of the map
    int* map_size_output(); //To return the size of the map
    map_vector map_generate_blank(const int* map_size); //To generate a blank map
    void map_set_boundary(map_vector& game_map);
    void map_print(map_vector game_map);
    bool map_is_obstruct_settle(Obstrucal obstrucal, map_vector game_map);
    bool map_is_entity_settle(Entity entity, map_vector game_map);
private:
    int map_size[2];
};
//To displace obstrucals

class Entity{//To summon entities;
public:
    void entity_set_hp(int* hp_input);
    void entity_set_hp(int hp_input);
    void entity_set_mp(int* mp_input);
    void entity_set_spawn_point(Point* spawn_point);
    int entity_hp_output();
    int entity_mp_output();
    Point entity_spawn_point_output();
    void entity_summon_try(map_vector& game_map, Entity entity, Map& map);
private:
    int hp, mp;
    Point position_entity;
};
class Enemy:public Entity{
public:
};//Enemy
class Player:public Entity{//Player
public:
    void player_move(Player player, map_vector game_map, Map map);
    void player_recover();
};
class Debug {//Debug
public:
    //To debug System_Map's function:capture_map_size()
    void Debug_System_Map_capture_map_size(const System_Map system_map);
    void Debug_printmap(const map_vector game_map);
    void Debug_Map_check_map_size(const Map map);
    void Debug_Obstrucal_check_summon_point(Obstrucal Obstrucal);
};


//Defines
int* System_Map::capture_map_size() {
    int* map_size_input = new int[2];
    printf("输入地图长（总列数）：");
    std::cin >> map_size_input[0];
    printf("输入地图宽（总行数）：");
    std::cin >> map_size_input[1];
    return map_size_input;
}
void Debug::Debug_System_Map_capture_map_size(System_Map system_map) {
    printf("这是对类System_Map成员函数capture_map_size的debug\n ");
    int* map_size = system_map.capture_map_size();
    printf("%d,%d\n", map_size[0], map_size[1]);
    printf("capture_map_size的Debug结束");
    delete[] map_size;
}

map_vector Map::map_generate_blank(const int* map_size){
    map_vector game_map(map_size[1], std::vector<char>(map_size[0]));
    for (int i = 0; i < map_size[1];i++){
        for (int j = 0; j < map_size[0]; j++) {
            game_map[i][j] = '*';
        }
    }
    return game_map;
}
void Debug::Debug_printmap(const map_vector game_map){
    printf("下面是对类Map成员函数map_generate_blank的Debug\n");
    for (int i = 0; i < game_map.size(); i++) {
        for (int j = 0; j < game_map[i].size(); j++) {
            printf("%c ", game_map[i][j]);
        }
        std::cout << std::endl;
    }
    printf("map_generate_blank的Debug结束");
    std::cout << std::endl;
}
void Map::map_size_receive(int* map_size_input) {
    map_size[0] = map_size_input[0];
    map_size[1] = map_size_input[1];
}
int* Map::map_size_output() {
    return map_size;
}
void Map::map_set_boundary(map_vector& game_map) {
    //理论上是随机寻找出入口的，因此没有自定义出入口的接口，但随机功能摸了（)，所以直接取中间值了,见谅
    int length = (int)game_map.size();
    int width = (int)game_map[0].size();
    for (int i = 0; i < length; i++){
        game_map[i][0] = game_map[i][width - 1] = '#';
    }
    for (int j = 0; j < width; j++) {
        game_map[0][j] = game_map[length - 1][j] = '#';
    }
    game_map[length / 2][0] = game_map[length-1][width/2] = 'o';
}
void Map::map_print(map_vector game_map) {
    for (int i = 0; i < game_map.size(); i++) {
        for (int j = 0; j < game_map[i].size(); j++) {
            printf("%c ", game_map[i][j]);
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void Debug::Debug_Map_check_map_size(Map map) {
    int* temp_map_size = map.map_size_output();
    printf("地图的长为：%d宽为：%d\n",temp_map_size[0],temp_map_size[1]);
}
Point* System_Obstrucal::capture_obstrucal_summon_point(){
    Point *point_input = new Point;
    printf("输入物体横坐标（列数）：");
    std::cin >> point_input->column;
    printf("输入物体横坐标（行数）：");
    std::cin >> point_input->row;
    return point_input;
}
void Obstrucal::obstrucal_summon_point_set(Point* point_set) {
    summon_point.column = point_set->column;
    summon_point.row = point_set->row;
}
Point Obstrucal::obstrcal_summon_point_output(Obstrucal obstrucal) {
    return summon_point;
}
void Debug::Debug_Obstrucal_check_summon_point(Obstrucal obstrucal) {
    int x = obstrucal.obstrcal_summon_point_output(obstrucal).column;
    int y = obstrucal.obstrcal_summon_point_output(obstrucal).row;
    printf("该物体横坐标（所在列数）为：%d，纵坐标（所在行数）为：%d\n", x, y);
}
bool Map::map_is_obstruct_settle(Obstrucal obstrucal,map_vector game_map) {
    int column = obstrucal.obstrcal_summon_point_output(obstrucal).column;
    int row =  obstrucal.obstrcal_summon_point_output(obstrucal).row;
    if (game_map[column-1][row-1] ==  '*') {
        return true;
    }
    else{
        return false;
    }
}
Point Entity::entity_spawn_point_output() {
    return position_entity;
}
bool Map::map_is_entity_settle(Entity entity, map_vector game_map) {
    int column = entity.entity_spawn_point_output().column;
    int row = entity.entity_spawn_point_output().row;
    if (game_map[column - 1][row - 1] == '*') {
        return true;
    }
    else {
        return false;
    }
}
void Obstrucal::obstrucal_summon_try(map_vector& game_map, Obstrucal obstrucal,Map& map) {
    if (map.map_is_obstruct_settle(obstrucal, game_map)) {
        int column = obstrucal.obstrcal_summon_point_output(obstrucal).column;
        int row = obstrucal.obstrcal_summon_point_output(obstrucal).row;
        game_map[column-1][row-1] = '@';
    }
    else {
        printf("防止失败：已被占位");
    }
}
Point* System_Entity::capture_entity_spawn_point() {
    Point* point_input = new Point;
    printf("输入实体横坐标（列数）：");
    std::cin >> point_input->column;
    printf("输入实体横坐标（行数）：");
    std::cin >> point_input->row;
    return point_input;
}
int* System_Entity::capture_entity_mp() {
    int* ptr_mp = new int;
    printf("输入实体mp：");
    std::cin >> *ptr_mp;
    std::cout << std::endl;
    return ptr_mp;
}
int* System_Entity::capture_entity_hp() {
    int* ptr_hp = new int;
    printf("输入实体hp：");
    std::cin >> *ptr_hp;
    std::cout << std::endl;
    return ptr_hp;
}
void Entity::entity_set_hp(int* hp_input) {
    hp = *hp_input;
}
void Entity::entity_set_hp(int hp_input) {
    hp = hp_input;
}
void Entity::entity_set_mp(int* mp_input) {
    mp = *mp_input;
}
void Entity::entity_set_spawn_point(Point* spawn_point) {
    position_entity.column = spawn_point->column;
    position_entity.row = spawn_point->row;
}
int  Entity::entity_hp_output() {
    return hp;
}
int  Entity::entity_mp_output() {
    return mp;
}
void Entity::entity_summon_try(map_vector& game_map, Entity entity, Map& map) {
    if (map.map_is_entity_settle(entity, game_map)) {
        int column = entity.entity_spawn_point_output().column;
        int row = entity.entity_spawn_point_output().row;
        game_map[column - 1][row - 1] = 'A';
    }
    else {
        printf("防止失败：已被占位\n");
    }
}
void Player::player_recover() {
    this->entity_set_hp(this->entity_hp_output() + 5);
    std::cout << "成功回复" << std::endl;
}
void Player::player_move(Player player,map_vector game_map,Map map) {
    Point* point_input = new Point;
    printf("输入玩家横坐标（列数）移动数：");
    std::cin >> point_input->column;
    printf("输入玩家横坐标（行数）移动数：");
    std::cin >> point_input->row;
    Point move_if;
    move_if.column = player.entity_spawn_point_output().column + point_input->column;
    move_if.row = player.entity_spawn_point_output().row + point_input->row;
    if (game_map[move_if.column][move_if.row] == '*') {
        player.entity_set_spawn_point(&move_if);
        player.entity_summon_try(game_map, player, map);
    }
    else std::cout << "占位，移动失败！" << std::endl;
}

//Main
int main() {
    System_Map system_map;
    System_Obstrucal system_obstrucal;
    System_Entity system_entity;
    Map map;
    Obstrucal obstrucal1;
    Debug debug;
    Enemy enemy1;
    Player player;


    map.map_size_receive(system_map.capture_map_size()) ;
    map_vector game_map = map.map_generate_blank(map.map_size_output());
    map.map_set_boundary(game_map);
    map.map_print(game_map);

    obstrucal1.obstrucal_summon_point_set(system_obstrucal.capture_obstrucal_summon_point());
    debug.Debug_Obstrucal_check_summon_point(obstrucal1);
    obstrucal1.obstrucal_summon_try(game_map, obstrucal1,map);
    map.map_print(game_map);

    enemy1.entity_set_hp(system_entity.capture_entity_hp());
    enemy1.entity_set_mp(system_entity.capture_entity_mp());
    enemy1.entity_set_spawn_point(system_entity.capture_entity_spawn_point());
    enemy1.entity_summon_try(game_map, enemy1, map);
    map.map_print(game_map);

    player.entity_set_hp(system_entity.capture_entity_hp());
    player.entity_set_mp(system_entity.capture_entity_mp());
    player.entity_set_spawn_point(system_entity.capture_entity_spawn_point());
    player.entity_summon_try(game_map, player, map);
    map.map_print(game_map);

    player.player_recover();
    player.player_move(player,game_map,map);
    map.map_print(game_map);
    
    return 0;
}