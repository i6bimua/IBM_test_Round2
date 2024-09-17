import random

class Monkey():
    ears = 2
    eyes = 2
    #此处使用类属性
        

class Immortal():
    def __init__(self) -> None:
        self.skill = "72 changes"
        #此处使用实例属性

class NormalMonkey(Monkey):
    def __init__(self) -> None:
        # 无需super().__init__()
        self.skill = "I don't have any speical skill"
        self.name = "normalmonkey"

class SixEarMacaque(Monkey,Immortal):
    def __init__(self) -> None:
        super().__init__()
        self.ears = 6
        self.name = "sixearmacaque"

class MonkeyKing(Monkey,Immortal):
    def __init__(self) -> None:
        super().__init__()
        self.name = "monkeyking"

def guess():
    a1 = input("Who is a:")
    b1 = input("Who is b:")
    c1 = input("Who is c:")
    if a1 == a.name and b1 == b.name and c1 == c.name:
        print("You are right,you WON!")
    else:
        print("You are wrong,you FAILED!")

monkeys = []
monkeys.append(NormalMonkey())
monkeys.append(SixEarMacaque())
monkeys.append(MonkeyKing())

random.shuffle(monkeys)

a = monkeys[0]
b = monkeys[1]
c = monkeys[2]

print("1. Please play the game with Python IDLE.\n2. There are 3 Monkeys,including normalmonkey,monkeyking and sixearmacaque.a, b and c are used as their pronouns.\n3. You can use .eyes/.ears/.skill attributes to distinguish them.\n4. When you know the answer,please tap in \"guess\".")
