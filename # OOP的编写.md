# OOP试写说明

## 阐述

在这个例子中，我们先创建了 `海龟(Turtle)`这个基类，这里海龟是基础模板，它自然是有 `高度(Height)`和 `体重(Weight)`。这些属性封装在了Turtle类，体现了模块化，也就是：

```c++
class Turtle
{
protected:
    float Height;
    float Weight;

public:
    Turtle(float h, float w) :Height(h), Weight(w) {}
};
```

其次，在宝可梦里，`杰尼龟（Squirtle）`显然是 `海龟（Turtle）`，自然地就有 `海龟（身高与体重）`的属性。
所以杰尼龟继承了海龟的类：

```c++
class Squirtle : public Turtle
{
public:
    Squirtle(float h, float w)
        :Turtle(h, w) {}
}
```

`杰尼龟`是游戏内的角色，所以又有额外的属性，比如血条 `HP`，攻击 `Attack`以及防御 `Defense`，这是现实生活中没有或者难以衡量的，但在游戏中有其明确的属性，我们认为这是杰尼龟特有的类，于是：

```c++
class Squirtle : public Turtle
{
private:
    int HP;
    int Attack;
    int Defense;

public:
    Squirtle(float h, float w, int hp, int atk, int def)
        :Turtle(h, w), HP(hp), Attack(atk), Defense(def) {}
}
```

这样杰尼龟这个类就包装完了，既继承了海龟的属性，又有自己的属性。符合了代码重用，利于维护原则。
此外，在 `Turtle`类中，我们加入了 `Info()`函数，可以看到 `"Turtle information"`
在 `Squirtle`类中，我们在 `Info()`函数内部加入 `Turtle::Info()`继承了海龟Turtle的消息,再添加新内容表示自己独有的属性，构成了新的 `Info()`函数。
所以可分为 `Turtle::Info()`和 `Squirtle::Info()`两个函数

```c++
class Turtle
{   
    //... 
    void Info()
    {
        std::cout << "Turtle information" << std::endl;
        std::cout << "Height:" << Height << std::endl;
        std::cout << "Weight:" << Weight << std::endl;
    }
};

class Squirtle : public Turtle
{
    //...
    void Info()
    {
        Turtle::Info();
        std::cout << "Squirtle information" << std::endl;
        std::cout << "HP:" << HP << std::endl;
        std::cout << "Attack:" << Attack << std::endl;
        std::cout << "Defense:" << Defense << std::endl;
    }

};
```

在 `main`函数：

```c++
int main()
{
    Turtle turtle(1.0, 17.0);
    Squirtle squirtle(0.5, 9.0, 44, 48, 65); //Height,Weight,HP,Attack,Defense
    turtle.Info();
    squirtle.Info();
    return 0;
}
```

输出结果是：

```txt
Turtle information
Height:1
Weight:17
Turtle information
Height:0.5
Weight:9
Squirtle information
HP:44
Attack:48
Defense:65
```

* 解释：
  首先我们定义了turtle，利用 `turtle.Info()`列出了海龟的消息
  其次再定义squirtle，利用 `squirtle.Info()`列出了杰尼龟的消息
  上述结果可看出Height和Weight属性是不相同的，体现了封装，以此验证了事件逻辑的完整性。

## 源代码

```c++
#include<iostream>

class Turtle
{
protected:
    float Height;
    float Weight;

public:
    Turtle(float h, float w) :Height(h), Weight(w) {}

    void Info()
    {
        std::cout << "Turtle information" << std::endl;
        std::cout << "Height:" << Height << std::endl;
        std::cout << "Weight:" << Weight << std::endl;
    }
};

class Squirtle : public Turtle
{
private:
    int HP;
    int Attack;
    int Defense;

public:
    Squirtle(float h, float w, int hp, int atk, int def)
        :Turtle(h, w), HP(hp), Attack(atk), Defense(def) {}

    void Info()
    {
        Turtle::Info();
        std::cout << "Squirtle information" << std::endl;
        std::cout << "HP:" << HP << std::endl;
        std::cout << "Attack:" << Attack << std::endl;
        std::cout << "Defense:" << Defense << std::endl;
    }

};

int main()
{
    Turtle turtle(1.0, 17.0);
    Squirtle squirtle(0.5, 9.0, 44, 48, 65); //Height,Weight,HP,Attack,Defense
    turtle.Info();
    squirtle.Info();
    return 0;
}
```
