#pragma once
class Caracteristic
{
public:
	Caracteristic();
	~Caracteristic();

	void initValues(int hp, int mp, int ct, int atk,int def,int mvt);

	inline int getHp() {
		return this->hp;
	}
	inline int getHpMax() {
		return this->hpMax;
	}
	inline int getMp() {
		return this->mp;
	}
	inline int getMpMax() {
		return this->mpMax;
	}
	inline int getCt() {
		return this->ct;
	}
	inline int getCtMax() {
		return this->ctMax;
	}

	inline int getAtk() {
		return this->atk;
	}
	inline int getDef() {
		return this->def;
	}
	inline int getMvt() {
		return this->mvt;
	}

private:
	int hp;
	int hpMax;
	int mp;
	int mpMax;
	int ct;
	int ctMax;

	int atk;
	int def; 
	int mvt;
};

