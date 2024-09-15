#ifndef ENTITY_H
#define ENTITY_H

// 我打算把这个程序编译为dll，链接到application程序中
// WK的意思是悟空

// #define WK_BUILD_DLL  如果要编译为dll，取消这行注释并且删掉最下面的main测试主函数


#ifdef WK_BUILD_DLL
    #define WK_API __declspec(dllexport)
#else
    #define WK_API
#endif
 
#include <bits/stdc++.h>

enum class EntityCategory
{
    Allay,
    Enemy,
    Neutral,
    sceneObj
};

enum class AbilityCategory
{
    Ability1,
    Ability2,
    Ability3,
    Ability4,
    Ultimate
};

struct Vector3
{
    float x, y, z;

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    void Print() const
    {
        std::cout << "Vector3(" << x << ", " << y << ", " << z << ")\n  ";
    }
};

class WK_API EntityInfo
{
public:
    virtual ~EntityInfo() = default;

    virtual EntityCategory GetEntityCategory() const = 0;
    virtual const std::string GetName() const = 0;
    virtual Vector3 GetPosition() const = 0;
    virtual std::string Tostring() const
    {
        return static_cast<std::string>(GetName());
    }
};

class WK_API Entity : public EntityInfo
{
private:
    std::string name;
    EntityCategory category;
    Vector3 position;

protected:
    Entity(const std::string &name, EntityCategory category, const Vector3 &position)
        : name(name), category(category), position(position) {}

public:
    virtual ~Entity() = default;

    EntityCategory GetEntityCategory() const override
    {
        return category;
    }

    const std::string GetName() const
    {
        return name.c_str();
    }

    Vector3 GetPosition() const
    {
        return position;
    }

    void SetPos(Vector3 vec3)
    {
        position = vec3;
    }
};

class WK_API Character : public Entity
{
private:
    int m_vitality;
    int m_attackPower;

public:
    Character(const std::string &name, const Vector3 &position, EntityCategory category, int vitality, int attackPower)
        : Entity(name, category, position), m_vitality(vitality), m_attackPower(attackPower) {}

    void PrintPlayerInfo() const
    {
        std::cout << "Player Name: " << GetName() << "\n";
        std::cout << "Position: ";
        GetPosition().Print();
    }

    int GetVitality() const
    {
        return m_vitality;
    }

    void SetVitality(int vitality)
    {
        m_vitality = vitality;
    }

    void move()
    {
        // 一些移动的函数
        // 因为是角色，所以可以移动
    }

    void hurt(int damage)
    {
        m_vitality -= damage;
        if (m_vitality < 0)
        {
            m_vitality = 0;
        }
    }

    void heal(int healing)
    {
        m_vitality += healing;
    }

    bool Alive()
    {
        return m_vitality > 0;
    }

    void use_ability(AbilityCategory abi)
    {
        // 写一些放技能的函数在这里
        std::cout << "ability used!" << std::endl;
    }
};

class WK_API Wukong : public Character
{
public:
    Wukong(const Vector3 &position)
        : Character("WuKong", position, EntityCategory::Allay, INT_MAX, INT_MAX) {} // 我大圣的血量就是INT_MAX，谁有意见

    void Kill_All()
    {
        // 杀死一切的函数
        std::cout << "大圣驾到统统闪开" << std::endl;
    }

    void revive()
    {
        SetVitality(INT_MAX);
    }
};

class WK_API Enemy : public Character
{
public:
    Enemy(const std::string &name, const Vector3 &position, int vitality, int attackPower)
        : Character(name, position, EntityCategory::Enemy, vitality, attackPower) {}

    void baojinbi()
    {
        // 怪死了爆金币的函数
        std::cout << "enemey killed, obtain xxx exp!" << std::endl;
    }
};

class WK_API NPC : public Character
{
public:
    NPC(const std::string &name, const Vector3 &position, int vitality)
        : Character(name, position, EntityCategory::Neutral, vitality, 0) {}

    void buy()
    {
        // 跟npc买东西的函数接口
        std::cout << "xxx brought!" << std::endl;
    }

    void sell()
    {
        // 跟npc卖东西的接口
        std::cout << "xxx sold!" << std::endl;
    }
};

class WK_API SceneObj : public Entity
{
private:
    // 物体的私有属性，什么树啊石头啊
public:
    SceneObj(const std::string &name, const Vector3 &position)
        : Entity(name, EntityCategory::sceneObj, position) {}

    void interact()
    {
        // 和物体交互的接口
    }
};
#endif

// 以下是测试程序
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
