#include <iostream>
#include <random>
using namespace std;

//随机数生成器
random_device rd;
mt19937 gen(rd());
uniform_real_distribution<> dist(0.0, 1.0);

//基类：角色类
class character {
protected:
	int hp, atk, tkdmg=0;
	bool charge=false;//蓄力中
	int pauseturn = 0;
public:
	//构造函数
	character(int h, int a) :hp(h), atk(a) {};
	//攻击
	virtual void attack(character& wk, double multipower) {
		wk.takedamage(atk * multipower);
	}
	bool isalive() {
		return hp > 0;
	}
	void takedamage(int damage) {
		tkdmg+=damage;
	}
	void truedamage(double multipower) {
		hp -= tkdmg * multipower;
	}

	void addpauseturn(int a) {
		pauseturn += a;
	}
	//判定是否暂停回合
	bool ispauseturn() {
		return pauseturn;;
	}
	//判断是否受到伤害
	int isdamaged() {
		return tkdmg;
	}
	//纯虚函数：状态清除
	virtual void clearState() = 0;
};

//派生类：悟空
class Wukong : public character {
protected:
	int mp=0,gunshi=0;//法力值，棍势值
	int dr = 0;//剩余酒量
	char hl=0;//葫芦种类
	bool isdodge = false;//本回合是否已闪避
	double damageReduction = 0;//伤害减免
	bool tttb = false;//本回合是否使用铜头铁臂
	bool dss = false;//本回合是否使用定身术
	bool windSand = false;//Debuff:风沙
	bool attackback = false;//Debuff:本回合将被弹反
	bool tripleTaped = false;//本回合被三连击
public:
	//构造函数
	Wukong(int h,int a,int m) :character(h,a),mp(m) {}
	//选择葫芦
	void choosehl() {
		cout << "请选择葫芦：上清宝葫芦（s）or 乾坤彩葫芦（q)" << endl;
		cin >> hl;
		if (hl == 's') dr = 10;
		else if (hl == 'q') dr = 6;
		if (hl != 's' && hl != 'q') choosehl();
	}
	//普通攻击
	void attack(character&target, double multipower) {
		target.takedamage(atk * multipower);
		if (gunshi < 2) gunshi++;
	}
	//蓄力攻击
	void chargeattack(character&wk ,character &target) {
		if (gunshi != 2) {
			cout << "棍势不足3，请重新选择行动\n";
			wkturn(wk, target);
		}
		int choice;
		cout << "请选择架势1.劈棍2.立辊3.戳棍4.返回\n";
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			cout << "呔，妖怪！看我劈棍！\n";
			attack(target, 1.5);
			gunshi = 0;
			break;
		case 2:
			cout << "呔，妖怪！看我立辊！\n";
			attack(target, 1);
			damageReduction = 0.5;
			gunshi = 0;
			break;
		case 3:
			cout << "呔，妖怪！看我戳棍！\n";
			attack(target, 1);
			isdodge = true;
			gunshi = 0;
			break;
		case 4:
			wkturn(wk, target);
			break;
		default:
			cout << "请输入正确的数字\n";
			chargeattack(wk, target);
		}
	}
	//喝酒
	void drink() {
		cout << "仙露！琼浆！\n";
		dr--;
		hp += 35;
		if (hl == 'q') {
			atk += 3;
		}
		if (hp > 100) hp = 100;
	}
	//闪身
	void dodge() {
		cout << "闪！\n";
		isdodge = true;
	}
	//法术
	void magic(character &wk, character &target) {
		cout << "请选择法术1.铜头铁臂2.定身术3.返回\n";
		int choice;
		cin >> choice;
		cout << endl;
		switch (choice) {
		case 1:
			cout << "硬!"<<endl;
			tttb = true;
			mp -= 20;
			break;
		case 2:
			cout << "定！"<<endl;
			dss = true;
			mp -= 20;
			break;
		case 3:
			wkturn(wk, target);
			break;
		default:
			cout << "请输入正确的数字\n";
			magic(wk, target);
		}
		return;
	}
	//Debuff:风沙
	void windsand() {
		windSand = true;
	}
	bool iswindsand() {
		return windSand;
 	}
	//是否铜头铁臂
	bool istttb() {
		return tttb;
	}
	//是否定身术
	bool isdss() {
		return dss;
	}
	//是否闪避
	bool isDodge() {
		return isdodge;
	}
	//Defuff：本回合将被弹反
	void attackbacked() {
		attackback = true;
	}
	//被三连击
	void tripletaped() {
		tripleTaped = true;
	}
	bool istripletap() {
		return tripleTaped;
	}
	//是否被弹反
	bool isattackbacked() {
		return attackback;
	}
	//悟空回合
	void wkturn(character &wk,character &target) {
		cout <<endl<< "请选择行动1.攻击 2.蓄力攻击 3.闪避 4.法术 5.喝酒"<<endl;
		int act;
		cin >> act;
		cout << endl;
		switch (act) {
		case 1: 
			cout << "悟空 对 敌人 使用 普通攻击"<<endl;
			wk.attack(target, 1);
			break;
		case 2:
			if (gunshi < 2) {
				cout << "棍势不足，请重新选择\n";
				wkturn(wk, target);
				return;
			}
			chargeattack(wk, target);
			break;
		case 3:
			dodge();
			break;
		case 4:
			if (mp < 20) {
				cout << "法力不足，请重新选择\n";
				wkturn(wk, target);
				return;
			}
			magic(wk,target);
			break;
		case 5:
			if(dr>0) drink();
			else {
				cout << "葫芦已空\n";
				wkturn(wk, target);
			}
			break;
		default:
			cout << "请输入正确的数字\n";
			wkturn(wk, target);
		}
		return;
	}
	//最终伤害
	void truedamage(double multipower) {
		hp -= tkdmg * multipower * (1-damageReduction);
	}
	//清除状态
	void clearState() override {
		isdodge=false;
		damageReduction = false;
		tttb= false;
		dss= false;
		tkdmg = 0;
		attackback = false;
		tripleTaped = false;
	}
	//打印状态
	void printstate() {
		if (hp <= 0) cout << "悟空状态：死亡" << endl;
		else cout << "悟空状态：hp：" << hp << ",mp:" << mp << ",棍势:" << gunshi << ",酒量："<<dr<<endl;
	}
};

//派生类：小妖
class Xiaoyao : public character {
protected:
public:
	Xiaoyao(int h,int a): character(h,a){}
	//小妖回合
	void xyturn(Wukong&wk) {
		if (pauseturn > 0) {
			cout << "该回合小妖难以行动" << endl;
			return;
		}
		if (charge) {
			cout << "小妖 对 悟空 使用 蓄力攻击\n" ;
			attack(wk, 2);
			charge = false;
		}
		else {
			double randomNum = dist(gen);
			if (randomNum < 0.5) {
				cout << "小妖 对 悟空 使用 普通攻击\n";
				attack(wk, 1);
			}
			else {
				cout << "小妖重心下沉，气聚丹田\n";
				charge = true;
			}
		}
	}
	void printstate() {
		if (hp <= 0) cout << "小妖状态：死亡" << endl;
		else cout << "小妖状态：hp：" << hp<< endl;
	}
	void clearState() override {
		tkdmg = 0;
		if (pauseturn > 0) pauseturn--;
	}
};

//派生类：头目
class Toumu : public character {
protected:
public:
	//构造函数
	Toumu(int h, int a) : character(h, a) {}
	//头目回合
	void tmturn(Wukong& wk) {
		if (pauseturn > 0) {
			cout << "该回合头目难以行动" << endl;
			return;
		}
		if (charge) {
			cout << "头目 对 悟空 使用 蓄力攻击"<<endl;
			attack(wk, 2);
			charge = false;
		}
		else {
			double randomNum = dist(gen);
			if (randomNum < 0.4) {
				cout << "头目 对 悟空 使用 普通攻击\n";
				attack(wk, 1);
			}
			else if(randomNum<0.8){
				cout << "头目屏息凝气，眼神坚定\n";
				charge = true;
			}
			else {
				//弹反
				cout << "头目举起武器，摆好架势\n";
				wk.attackbacked();
			}
		} 
	}
	void printstate() {
		if (hp <= 0) cout << "头目状态：死亡" << endl;
		else cout << "头目状态：hp：" << hp << endl;
	}
	void clearState() override {
		tkdmg = 0;
		if (pauseturn > 0) pauseturn--;
	}
};

//派生类：妖王
class Yaowang : public character {
protected:
public:
	Yaowang(int h, int a) : character(h, a) {}
	void tripleTap(Wukong&wk) {
		double randomNum2 = dist(gen);
		wk.tripletaped();
		if (randomNum2 > 0.75) {
			cout << "那妖怪结结实实地朝悟空打了三下!悟空大意了，没闪开" << endl;
			attack(wk, 3);
		}
		else {
			double randomNum2 = dist(gen);
			if (randomNum2 > 0.67) {
				cout << "那妖怪朝悟空猛戳三下，悟空闪开第一下，却发现自己身上多出俩窟窿" << endl;
				attack(wk, 2);
			}
			else {
				double randomNum2 = dist(gen);
				if (randomNum2 > 0.5) {
					cout << "那妖怪的三叉戟朝悟空飞来，连扫三下，悟空后撤步躲开两下，最后一下却被撂倒在地！" << endl;
					attack(wk, 1);
				}
				else {
					cout << "那妖怪三下攻击没中，气急败坏喊道：“我来助你！”"<<endl;
				}
			}
		}
	}
	void ywturn(Wukong& wk) {
		if (pauseturn > 0) {
			cout << "该回合妖王难以行动" << endl;
			return;
		}
		if (charge) {
			cout << "妖王 对 悟空 狠狠砍了一刀\n";
			attack(wk, 2);
			charge = false;
		}
		else {
			double randomNum = dist(gen);
			if (randomNum < 0.3) {
				cout << "妖王 对 悟空 使用 普通攻击\n";
				attack(wk, 1);
			}
			else if (randomNum < 0.6) {
				cout << "那妖怪怒吼一声，向悟空冲过来!\n";
				charge = true;
			}
			else if(randomNum<0.9){
				if (wk.iswindsand()) {
					ywturn(wk);
					return;
				}
				cout << "只见那黄毛鼠精舞起风沙，将悟空蒙在漫天的黄沙之中\n";
				wk.windsand();
			}
			else {
				tripleTap(wk);
			}
		}
	}
	void printstate() {
		if (hp <= 0) cout << "妖王状态：死亡" << endl;
		else cout << "妖王状态：hp：" << hp << endl;
	}
	void clearState() override {
		tkdmg = 0;
		if (pauseturn > 0) pauseturn--;
	}
};

//判定阶段
void judge(Wukong& wk, character& enemy) {
	int multipower2=1;
	//
	if (wk.istripletap()) {

	}
	//头目弹反
	if (wk.isattackbacked() && enemy.isdamaged()) {
		cout << "悟空攻击不成反被对方借势所伤！\n";
		wk.takedamage(enemy.isdamaged());
		wk.truedamage(1);
		return;
	}
	//风沙
	if (wk.iswindsand()) {

	    double windSandRandomNum = dist(gen);
		if (windSandRandomNum > 0.5) {
			multipower2 = 0;
			cout << "悟空被风沙迷了眼！"<<endl;
		}
		else multipower2 = 1;
	}
	//法术
	if (wk.istttb()) {
		if (wk.isdamaged() && !wk.istripletap()) {
			cout << "Duang~" << endl;
			enemy.addpauseturn(2);
		}
		else {
			wk.truedamage(1);
			cout << "白用法术了" << endl;
		}
		return;
	}
	if (wk.isdss()) {
		enemy.addpauseturn(3);
		return;
	}
	//暂停回合
	if (enemy.ispauseturn() ){
		enemy.truedamage(multipower2);
		return;
	}
	//闪身
	if (wk.isDodge()) {
		double randomNum = dist(gen);
		if (randomNum < 0.8) {
			cout << "闪身成功" << endl;
			enemy.truedamage(multipower2);
		}
		else {
			cout << "闪身失败" << endl;
			wk.truedamage(1);
			enemy.truedamage(multipower2);
		}
		return;
	}
	wk.truedamage(1);
	enemy.truedamage(multipower2);
	return;
}

//第一关
void Stage1(Wukong&wk) {
	cout << "悟空遇见一个小妖\n";
	Xiaoyao xy(100,10);
	while (xy.isalive() && wk.isalive()) {
		wk.wkturn(wk,xy);
		xy.xyturn(wk);
		judge(wk,xy);
		wk.printstate();
		xy.printstate();
		wk.clearState();
		xy.clearState();
	}
	return;
}

//第二关
void Stage2(Wukong&wk) {
	cout << "悟空遇见一头目，二话不说上来就开打\n";
	Toumu tm(200,15);
	while (tm.isalive() && wk.isalive()) {
		wk.wkturn(wk,tm);
		tm.tmturn(wk);
		judge(wk,tm);
		wk.printstate();
		tm.printstate();
		wk.clearState();
		tm.clearState();
	}
	return;
}

//第三关
void Stage3(Wukong&wk) {
	cout << "悟空见到了一直拿着三叉戟的黄鼠狼，毫不犹豫冲了上去\n";
	Yaowang yw(300,20);
	while(yw.isalive() && wk.isalive()) {
		wk.wkturn(wk,yw);
		yw.ywturn(wk);
		judge(wk,yw);
		wk.printstate();
		yw.printstate();
		wk.clearState();
		yw.clearState();
	}
	return;
}

void youwin() {
	cout << endl << "得    胜" << endl<<endl;
}

//主函数
int main() {
	Wukong wk(100,20,100);
	wk.choosehl();
	cout << "游戏开始" << endl << endl<<"~黄风岭~八百里~曾是关外富饶地~" << endl<<endl;

	Stage1(wk);
	if (!wk.isalive()) {
		cout << "YOU DEAD\n";
		return 0;
	}
	youwin();

	Stage2(wk);
	if (!wk.isalive()) {
		cout << "YOU DEAD\n";
		return 0;
	}
	youwin();

	Stage3(wk);
	if (!wk.isalive()) {
		cout << "YOU DEAD\n";
		return 0;
	}
	youwin();

	cout << "已通关本章节";
	return 0;
}