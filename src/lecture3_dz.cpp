#include <iostream> 
#include <vector>
#include <memory>
using namespace std; 

//ключевые понятия (принципы) ООП:
//1) наследование
//2) полиморфизм
//3) абстракция
//4) инкапсуляция

class NPC
{
protected:
	string name{ "npc" };
	unsigned int damage{ 2 };
	unsigned int health{ 5 };
	short lvl = 1;
	unsigned int armor = 2;
public:
	virtual void GetInfo()
	{
		cout << "имя: " << name << endl;
		cout << "здоровье: " << health << endl;
		cout << "урон: " << damage << endl;
		cout << "уровень: " << lvl << endl;
		cout << "броня: " << armor << endl;
	};
	void Create(){	};
	void LvlUp()
	{
		cout << name << " получил новый уровень" << endl;
		lvl++;
		Relaculate();
	}
	virtual void Relaculate() //кастомизировать для война и волшебника зависимости от инт/силы
	{
		damage += (1 + lvl * 0.1);
		health += (1 + lvl * 0.1);
		armor += (1 + lvl * 0.1);
	}
	virtual ~NPC() = default;
};

struct Weapon
{
	string name{ "weapon" };
	unsigned int damage{ 1 };
};

class Warrior : public NPC
{
private:
	short strength{ 21 };
	vector<Weapon> weapons;
public:
	//конструктор по умолчанию
	Warrior()
	{
		//cout << "конструктор война" << endl;
		damage = 20;
		health = 30;
		armor = 15;
		Create();
	}
	//кастомный конструктор
	Warrior(string name, unsigned int lvl)
	{
		damage = 20;
		health = 30;
		armor = 15;
		this->name = name; //такой способ задания поля уместен только для сеттер
		for (size_t i = 0; i < lvl; i++)
		{
			LvlUp();
		}
		//this->lvl = lvl; //this - указывает на конкретный экземпляр класса
	}
	void Relaculate() override
	{
		damage += (1 + lvl * 0.1) + strength * 0.5;
		health += (1 + lvl * 0.1) + strength * 0.8;
		armor += (1 + lvl * 0.1) + strength * 0.3;
	}
	void Create()
	{
		cout << "Вы создали война\nЗадайте имя игрока\n";
		cin >> name;

		GetInfo();
		GetWeapon();
	};
	void GetInfo() override
	{
		NPC::GetInfo();
		cout << "сила: " << strength << endl;
	};
	void GetWeapon()
	{
		Weapon weapon;
		weapon.damage = 1;
		weapon.name = "кулаки";
		weapons.push_back(weapon);

		cout << name << " взял в руки оружие " << weapons[0].name << endl;
		cout << " добавка к урону = " << weapons[0].damage << endl;
	};
	~Warrior() //деструктор (вызывается сам в момент высвобождения памяти экземпляра)
	{
		cout << name << " пал смертью храбрых" << endl;
	}
};

struct Spell
{
	string name{ "spell" };
	unsigned int damage{ 1 };
};

class Wizard : public NPC
{
private:
	short intellect{ 29 };
	vector<Spell> spells;
public:
	Wizard()//конструктор вызывается в момент создания экземпляра
	{
		//cout << "конструктор волшебник" << endl;
		damage = 27;
		health = 21;
		armor = 10;
		Create();
	} 
	void Relaculate() override
	{
		damage += (1 + lvl * 0.1) + intellect * 0.9;
		health += (1 + lvl * 0.1) + intellect * 0.2;
		armor += (1 + lvl * 0.1) + intellect * 0.1;
	}
	void Create()
	{
		cout << "Вы создали волшебник\nЗадайте имя игрока\n";
		cin >> name;

		GetInfo();
		LearnSpell();
	};
	void GetInfo() override
	{
		NPC::GetInfo();
		cout << "интеллект: " << intellect << endl;
	};
	void LearnSpell()
	{
		Spell spell;
		spell.damage = 2;
		spell.name = "вспышка";
		spells.push_back(spell);

		cout << name << " изучил заклинание " << spells[0].name << endl;
		cout << " добавка к урону = " << spells[0].damage << endl;
	};
	~Wizard()
	{
		cout << name << " испускает дух" << endl;
	}
};

class Evil : public NPC
{
public:
	Evil()
	{
		name = "Злодей";
		health = 10;
		damage = 5;
		armor = 3;
	}
	Evil(string name) : Evil() //делегирование конструктора (то есть вызовется вначале базовый)
	{
		this->name = name;
	}
	Evil(string name, unsigned int damage) : Evil(name)
	{
		this->damage = damage;
	}
	Evil(string name, unsigned int damage, unsigned int health) : Evil(name, damage)
	{
		this->health = health;
	}
	Evil(string name, unsigned int damage, unsigned int health, unsigned int armor) : Evil(name, damage, health)
	{
		this->armor = armor;
	}
//придумать интересный деструктор для злодеев
	~Evil()
	{
		cout << "Тьма рассеялась: злодей " << name << " превратился в горстку праха и оставил после себя лут!" << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");

	Warrior* warrior = new Warrior("друг война", 5); //как только создал новый экземпляр, для него вызвался конструктор
	warrior->GetInfo(); //стрелка работает с указателями
	delete warrior;
	warrior = nullptr;

	Wizard wizard;

	// превратить злодеев в вектор (указателей, умных)
	vector<unique_ptr<Evil>> evils;
	evils.push_back(make_unique<Evil>());
	evils.push_back(make_unique<Evil>("Кабанчик"));
	evils.push_back(make_unique<Evil>("Гнолл", 12));
	evils.push_back(make_unique<Evil>("Гнолл Дробитель", 15, 20));
	evils.push_back(make_unique<Evil>("Дракон", 50, 100, 200));

	for (const auto& evil : evils)
	{
		evil->GetInfo();
	}

	return 0; 
}
