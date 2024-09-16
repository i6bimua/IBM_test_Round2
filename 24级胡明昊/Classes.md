众所周知，黑神话和这个的唯一相似点就是大家都是闯关游戏（
#### 系统
系统主要负责接受玩家输入和管理菜单（但菜单做不出来）
目前地图，障碍物，实体均有对应的继承：System_(类名)，其中只含有capture_函数来接受输入
其继承间共有属性目前找不太到所以System类本身是空的（
#### 地图
地图属性有两项：长与宽
提供的方法有：
- map_size_receive：以数组形式接收传入的长与宽；
- map_size_output：返回这一地图的长与宽
- map_is_obstruct_settle判断某物体是否可以被放在某处

**地图显示方面**：将一个二维vector定义为map_vector并以此进行显示
提供的方法有：
- map_generate_blank：创建一个指定长与宽的矩形地图
- map_set_boundary：进行地图边界的设置。目前会直接将地图最外围整体设置为
边境
- map_print在终端打印当前的地图

#### 障碍物
障碍物会阻碍玩家前进。
其目前成员属性仅坐标summon_point；
提供的方法有：
- obstrucal_summon_point_set 设置一个障碍物的坐标
- obstrcal_summon_point_output 输出一个障碍物的坐标
- obstrucal_summon_try 尝试在地图中该障碍物坐标处放置该障碍物

#### 实体
实体包含玩家与敌人
其共有成员属性有hp，mp
提供的方法有
- entity_set_hp 设置hp
- entity_set_mp 设置mp
- entity_hp_output 获取hp
- entity_mp_output 获取mp
- entity_set_spawn_point 设置出生点
- entity_summon_try 尝试在地图中该实体坐标处放置该实体

#### 玩家
玩家是实体的一个继承，其独有的方法有：
- player_move 尝试移动（敌人理应也会移动，但寻路做不出来只好原地坐牢了）
- player_recover 回复一定量的hp
（战斗系统做不了一点，前面的区域以后再来探索吧）
#### Debug
Debug类提供了一系列函数，辅助检查（但在这里似乎没什么用）
其命名规律：
Debug_(类名)\_(类成员函数名)；
Debug_(类名)\_check\_(成员变量名);
Debug_(行为)
提供的成员函数有：
Debug_System_Map_capture_map_size
Debug_printmap















***
**下面是旧版，做不出来，因为我太菜了**
***


# これはタイトルですよ～
This is the subtitle.
-

***
- ~~这~~**里*****只***是
想试试各种效果
***

## 关于对象：
### 大概结构
  一个淳朴的2d战斗游戏，随机生成一片地图，随机生成玩家与敌人位置，玩家一回合移动一次，与敌人接触时发生战斗，通关要求是等级达到要求且活着到达出口。

**则涉及的对象有：系统，地图，实体**

## 大概内容

#### 系统
有：
    循环：每次循环时监听玩家输入；
    更新：更新地图状态（如果有），更新实体状态；
    菜单：应当能调出菜单，战斗时有战斗菜单，脱战时有道具菜单，随时可调出系统设置菜单；
    刷新屏幕；

#### 地图
地图尺寸：一定范围内随机大小；
地图形状：随机生成，但不能有死路，过于离谱的路

#### 实体
共有实体属性：名称，HP,MP,位置
再分类：敌人，玩家

##### 敌人
随机初始化属性；
寻路策略

##### 玩家 
等级，移动方式，
独有的调用hp，mp的方法（道具）

## 游戏流程
启动
生成地图
生成实体
（进入循环）
检测输入（初次时有开始游戏）
是否调用\{系统菜单，道具菜单，行动菜单\}
敌人寻路
检测是否触发战斗
（结束循环）


## 具体实现（完全做不到）
### 地图
private:
int map_struct[][];
public:
void map_size(int length,int width);//传参为随机生成
void map_generate();//生成地图具体结构
bool if_movable();//检测实体存在于某处是否可行

void map_generate(){
    /*
    （边界强调的是“地图”数组的边界）
    逻辑是：选取边界一点开始走过非对角线连续过程，直到再次抵达某一边界，期间不发生该线自交或相交；这一过程进行至少一次。
    选取被线分成的某区域。其他区域填充为不可到达区。
    其内边界处一点作为出生点，该区域内生成合理数目的敌人。
    （优化：寻找被线划分区域中边界相距最远的一块）
    */
    void enemy_generate(int num)//生成敌人（应当是合理范围内的随机数个，但是不会）
    void player_generate();
}

### 实体
private:
int hp,mp;
int position_x,position_y;
int name;
public:
void set_name();
int get_name();
void move();


### 敌人
public:
void fight_happen();
void destory();

### 玩家
public:
