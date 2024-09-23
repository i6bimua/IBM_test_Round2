#include <iostream>
#include <string>

using namespace std;

// 基类 Monkey
class Monkey
{
public:
    Monkey(const string &name, const string &appearance)
        : name(name), appearance(appearance) {}

    void introduce() const
    {
        cout << "我是" << name << "，我的外貌是" << appearance << "。\n";
    }

protected:
    string name;
    string appearance;
};

// 派生类 SunWukong
class SunWukong : public Monkey
{
public:
    SunWukong(const string &name, const string &appearance, const string &special_powers)
        : Monkey(name, appearance), special_powers(special_powers) {}

    void transform() const
    {
        cout << name << "可以使用" << special_powers << "进行变化。\n";
    }

private:
    string special_powers;
};

int main()
{
    // 创建一个普通的猴子对象
    Monkey monkey("普通猴子", "毛茸茸的身体");
    monkey.introduce();

    // 创建一个孙悟空对象
    SunWukong sun_wukong("孙悟空", "金箍棒", "七十二变");
    sun_wukong.introduce();
    sun_wukong.transform();

    return 0;
}