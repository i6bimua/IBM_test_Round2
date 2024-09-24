一个关于黑神话悟空的回合制

```c++
#include <string>
#include <iostream>

class Monkety {
private:
    std::string name;
    int health, magic, power, harm;
    friend class Wukong;

public:
    Monkety(const std::string& name, int health, int magic, int power, int harm)
            : name(name), health(health), magic(magic), power(power), harm(harm) {}

    std::string getName() const {
        return name;
    }

    int getHealth() const {
        return health;
    }

    void setHealth(int newHealth) {
        health = (newHealth > 0) ? newHealth : 0;
    }

    void attack(Monkety* target) {
        std::cout << target->name << " 受到了 " << harm << " 点伤害" << std::endl;
        target->setHealth(target->getHealth() - harm);
        std::cout << "当前生命为 " << target->getHealth() << std::endl;
    }
};

class Wukong :   public Monkety {
public:
    Wukong(const std::string& name, int health, int magic, int power,int harm)
            : Monkety(name, health, magic, power, magic * power * 2) {}

    void attack(Monkety* target)  {
        int calculated_harm = magic * power * 2;

        std::cout << this->getName() << " 使用了定身术" << std::endl;
        std::cout << target->name << " 受到了 " << calculated_harm << " 点伤害" << std::endl;
        target->setHealth(target->getHealth() - calculated_harm);
        std::cout << "当前生命为 " << target->getHealth() << std::endl;
    }
};

int main() {
    Monkety a("天命", 8000, 10, 10, 100);
    Wukong c("悟空", 18000, 20, 20,800);
    while(a.getHealth()>0&&c.getHealth()>0){
    std::cout << "初始状态：" << std::endl;
    std::cout << "悟空的生命值: " << c.getHealth() << std::endl;
    std::cout << "天命的生命值: " << a.getHealth() << std::endl;
    c.attack(&a);
    std::cout << "战斗后：" << std::endl;
    std::cout << "悟空的生命值: " << c.getHealth() << std::endl;
    std::cout << "天命的生命值: " << a.getHealth() << std::endl;}

    return 0;
}


```

![](24房立志\图片\屏幕截图 2024-09-16 081114.png")



![屏幕截图 2024-09-16 081114](E:\24房立志\屏幕截图 2024-09-16 081114.png)