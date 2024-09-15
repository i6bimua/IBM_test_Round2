# Entity 系统

本文档描述了一个简单的游戏实体系统，包括 `Entity`、`Character` 及其派生类如 `Wukong`、`Enemy`、`NPC` 和 `SceneObj`。

## 枚举

### `EntityCategory`

用于定义实体的分类：

- `Allay`: 同盟
- `Enemy`: 敌人
- `Neutral`: 中立
- `sceneObj`: 场景对象

### `AbilityCategory`

用于定义角色的能力类型：

- `Ability1`
- `Ability2`
- `Ability3`
- `Ability4`
- `Ultimate`

## 结构体

### `Vector3`

表示三维空间中的位置或方向：

- `x`: x 坐标
- `y`: y 坐标
- `z`: z 坐标

## 类

### `EntityInfo`

这是一个抽象基类，定义了所有实体必须实现的接口：

- `GetEntityCategory() const`: 返回实体的分类。
- `GetName() const`: 返回实体的名称。
- `GetPosition() const`: 返回实体的位置。
- `Tostring() const`: 返回实体的名称字符串。

### `Entity`

继承自 `EntityInfo`，用于表示具体的游戏实体：

- **私有成员**:
  - `name`: 实体的名称
  - `category`: 实体的分类
  - `position`: 实体的位置
- **保护构造函数**:
  - `Entity(const std::string &name, EntityCategory category, const Vector3 &position)`: 初始化实体。
- **公有方法**:
  - `GetEntityCategory() const`: 返回实体的分类。
  - `GetName() const`: 返回实体的名称。
  - `GetPosition() const`: 返回实体的位置。
  - `SetPos(Vector3 vec3)`: 设置实体的位置。

### `Character`

继承自 `Entity`，表示具有生命值和攻击力的角色：

- **私有成员**:
  - `m_vitality`: 生命值
  - `m_attackPower`: 攻击力
- **构造函数**:
  - `Character(const std::string &name, const Vector3 &position, EntityCategory category, int vitality, int attackPower)`: 初始化角色。
- **公有方法**:
  - `PrintPlayerInfo() const`: 打印角色信息。
  - `GetVitality() const`: 返回生命值。
  - `SetVitality(int vitality)`: 设置生命值。
  - `move()`: 移动角色。
  - `hurt(int damage)`: 角色受伤。
  - `heal(int healing)`: 角色恢复。
  - `Alive()`: 判断角色是否存活。
  - `use_ability(AbilityCategory abi)`: 使用技能。

### `Wukong`

继承自 `Character`，表示一个特殊的角色（悟空）：

- **构造函数**:
  - `Wukong(const Vector3 &position)`: 初始化悟空角色，设置血量为最大值。
- **公有方法**:
  - `Kill_All()`: 杀死一切。
  - `revive()`: 复活并恢复生命值。

### `Enemy`

继承自 `Character`，表示敌人：

- **构造函数**:
  - `Enemy(const std::string &name, const Vector3 &position, int vitality, int attackPower)`: 初始化敌人。
- **公有方法**:
  - `baojinbi()`: 敌人死亡后爆出金币。

### `NPC`

继承自 `Character`，表示中立 NPC：

- **构造函数**:
  - `NPC(const std::string &name, const Vector3 &position, int vitality)`: 初始化 NPC。
- **公有方法**:
  - `buy()`: 购买物品。
  - `sell()`: 卖出物品。

### `SceneObj`

继承自 `Entity`，表示场景中的对象：

- **构造函数**:
  - `SceneObj(const std::string &name, const Vector3 &position)`: 初始化场景对象。
- **公有方法**:
  - `interact()`: 与场景对象交互。

## 示例程序

```cpp
int main()
{
    Wukong wukong(Vector3(1.0f, 2.0f, 3.0f));
    wukong.PrintPlayerInfo();
    wukong.Kill_All();
    wukong.revive();

    Enemy enemy("black_bear_guai", Vector3(5.0f, 6.0f, 7.0f), 100, 10);
    enemy.PrintPlayerInfo();
    enemy.baojinbi();

    NPC npc("shenhou", Vector3(8.0f, 9.0f, 10.0f), 50);
    npc.PrintPlayerInfo();
    npc.buy();
    npc.sell();

    SceneObj tree("Tree", Vector3(11.0f, 12.0f, 13.0f));
    tree.interact();

    std::cin.get();

    return 0;
}
