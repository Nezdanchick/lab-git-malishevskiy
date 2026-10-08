#include <iostream>
#include <string>
#include <vector>
#include <memory>

using namespace std;

// Ключевые понятия (принципы) ООП:
// 1) Инкапсуляция (getter, setter)
// 2) Наследование
// 3) Полиморфизм
// 4) Абстракция

// public - публичный
// protected - защищенный
// private - приватный

enum Quality {
	Common,
	Uncommon,
	Rare,
	Epic,
	Legendary
};

class Entity;


class Weapon {
protected:
	string name;
	unsigned int damage{ 1 };
	Quality quality{ Common };
public:
	Weapon(string name = "weapon") {
		this->name = name;
	}
	virtual void GetInfo() {
		cout << "Оружие " << name << " качества " << quality << " с уроном " << damage << endl;
	}
	unsigned int GetDamage() {
		return damage;
	}
	void SetDamage(unsigned int damage) {
		this->damage = damage;
	}
	void Damage(Entity *from, Entity *target) {
		float damage = (this->damage + from->GetBaseDamage()) * target->GetDamageMultiplyer();;
		cout << "Оружие " << name << " наносит " << damage << " урона " << target->GetName() << endl;
		target->Damage(damage);
	}
	void Upgrade() {
		cout << "Снаряжение " << name << " улучшено! " << quality << " -> " << quality + 1 << endl;
		if (quality < Legendary) {
			quality = static_cast<Quality>(quality + 1);
		}
	}
	virtual ~Weapon() = default;
};

class Spell : public Weapon {
public:
	Spell(string name = "spell") : Weapon(name) {}
	void GetInfo() override {
		cout << "Заклинание " << name << " качества " << quality << " с уроном " << damage << endl;
	}
};

class Entity {
protected:
	string type{ "Entity" };
	string name{ "Entity" };
	float health{ 100 };
	float baseDamage{ 1 };
	float damageMultiplyer{ 1 };
	unsigned int level{ 1 };
	unsigned int armor{ 2 };

	Entity() = default;
public:
	Entity *SetName(string name) {
		this->name = name;
		return this;
	}
	Entity *SetNameConsole() {
		cout << "Введите имя: ";
		cin >> this->name;
		return this;
	}
	Entity *SetLevel(unsigned int level) {
		this->level = level;
		LevelRecalulate();
		return this;
	}

	virtual void GetInfo() {
		cout << "Тип: " << type << endl;
		cout << "Имя: " << name << endl;
		cout << "Уровень: " << level << endl;
		cout << "Здоровье: " << health << endl;
		cout << "Броня: " << armor << endl;
		cout << "Множитель урона: x" << damageMultiplyer << endl;
	}
	virtual void LevelUp() {
		cout << "Уровень " << name << " увеличен! " << level << " -> " << level + 1 << endl;
		level++;
		LevelRecalulate();
	}
	virtual void LevelRecalulate() {
		damageMultiplyer += 0.1;
		health += (1 + level * 0.1);
		armor += (1 + level * 0.1);
	}
	bool IsAlive() {
		return health > 0;
	}
	string GetName() {
		return name;
	}
	float GetBaseDamage() {
		return baseDamage;
	}
	float GetDamageMultiplyer() {
		return damageMultiplyer;
	}
	float GetArmor() {
		return armor;
	}
	float GetHealth() {
		return health;
	}
	void Damage(float damage) {
		float damageTaken = damage - armor;
		if (damageTaken < 0) {
			damageTaken = 0;
		}
		cout << name << " получил " << damageTaken << " урона" << endl;
		health -= damageTaken;
	}
	virtual ~Entity() = default;
};

class Paladin : public Entity {
private:
    Weapon weapon = Weapon("Освященный меч");
    Spell spell = Spell("Священный огонь");
    short strength{ 18 };
    short intellect{ 18 };
public:
    Paladin() {
        type = "Паладин";
		name = "Паладин";
        baseDamage = 8;
        health = 180;
        armor = 18;
    }
    void LevelRecalulate() override {
        damageMultiplyer += 0.1 + (strength * 0.01) + (intellect * 0.01);
        health += (1 + level * 0.1) + strength * 0.6;
        armor += (1 + level * 0.1) + strength * 0.4 + intellect * 0.05;
    }
    void GetInfo() override {
        Entity::GetInfo();
        cout << "Сила: " << strength << endl;
        cout << "Интеллект: " << intellect << endl;
        weapon.GetInfo();
        spell.GetInfo();
    }
    void LevelUp() override {
        Entity::LevelUp();
        health += 8;
        spell.Upgrade();
    }
    ~Paladin() override {
        cout << name << " завершил свой священный поход и вознесся к Свету" << endl;
    }
};

class Warrior : public Entity {
private:
	Weapon weapon = Weapon("Кулаки");
	short strength{ 21 };
public:
	Warrior() {
		type = "Воин";
		name = "Воин";
		baseDamage = 10;
		health = 150;
		armor = 15;
	}
	void LevelRecalulate() override {
		damageMultiplyer += 0.1 + strength * 0.01;
		health += (1 + level * 0.1) + strength * 0.8;
		armor += (1 + level * 0.1) + strength * 0.3;
	}
	void GetInfo() override {
		Entity::GetInfo();
		cout << "Сила: " << strength << endl;
		weapon.GetInfo();
	}
	void LevelUp() override {
		Entity::LevelUp();
		health += 10;
	}
	~Warrior() override {
		cout << name << " пал смертью храбрых" << endl;
	}
};

class Mage : public Entity {
private:
	Spell spell = Spell("Вспышка");
	short intellect{ 29 };
public:
	Mage() {
		type = "Маг";
		name = "Маг";
		baseDamage = 0;
		health = 150;
		armor = 10;
	}
	void LevelRecalulate() override {
		damageMultiplyer += 0.1 + intellect * 0.02;
		health += (1 + level * 0.1) + intellect * 0.2;
		armor += (1 + level * 0.1) + intellect * 0.1;
	}
	void GetInfo() override {
		Entity::GetInfo();
		cout << "Интеллект: " << intellect << endl;
		spell.GetInfo();
	}
	void LevelUp() override {
		Entity::LevelUp();
		spell.Upgrade();
	}
	~Mage() override {
		cout << name << " испускает дух" << endl;
	}
};

class Evil : public Entity {
public:
	Evil() {
		type = "Злодей";
		name = "Злодей";
		health = 10;
		baseDamage = 2;
		damageMultiplyer = 1.0;
		armor = 3;
	}
	Evil(string name) : Evil() {
		this->name = name;
	}
	Evil(string name, float damageMultiplyer) : Evil(name) {
		this->damageMultiplyer = damageMultiplyer;
	}
	Evil(string name, float damageMultiplyer, float health) : Evil(name, damageMultiplyer) {
		this->health = health;
	}
	Evil(string name, float damageMultiplyer, float health, unsigned int armor) : Evil(name, damageMultiplyer, health) {
		this->armor = armor;
	}
	~Evil() override {
		cout << "Тьма рассеялась: злодей " << name << " превратился в горстку праха и оставил после себя лут!" << endl;
	}
};

int main() {
	setlocale(LC_ALL, "Rus");

	// Warrior *w1 = (Warrior*)(new Warrior())->SetNameConsole()->SetLevel(3);
	// w1->GetInfo();

	// Mage *m1 = (Mage*)(new Mage())->SetName("Ведьма");
	// m1->GetInfo();

	// w1->LevelUp();

	// Paladin *p1 = (Paladin*)(new Paladin())->SetName("Светлый рыцарь");
	// p1->GetInfo();

	// delete w1;
	// delete m1;
	// delete p1;	

	// vector<unique_ptr<Evil>> evils;
	// evils.push_back(make_unique<Evil>());
	// evils.push_back(make_unique<Evil>("Кабанчик"));
	// evils.push_back(make_unique<Evil>("Гнолл", 1.2f));
	// evils.push_back(make_unique<Evil>("Гнолл Дробитель", 1.5f, 20.0f));
	// evils.push_back(make_unique<Evil>("Дракон", 5.0f, 100.0f, 200));

	// for (const auto& evil : evils) {
	// 	evil->GetInfo();
	// }

	cout << "Присядь путник у костра и расскажи мне о себе, кто ты?" << endl;
	cout << "1) Воин" << endl;
	cout << "2) Маг" << endl;
	cout << "3) Паладин" << endl;
	int choice;
	cin >> choice;
	unique_ptr<Entity> player;
	switch (choice) {
	case 1:
		player = make_unique<Warrior>();
		break;
	case 2:
		player = make_unique<Mage>();	
		break;
	case 3:
		player = make_unique<Paladin>();
		break;
	}

	player->SetNameConsole();
	player->GetInfo();

	return 0;
}
