#include <iostream>
using namespace std;

//3-8



/*
//3-7
#include <cstdlib>
#include <ctime>
class Random {
public:
	int nextOdd();
	int nextEven();
	int nextOddInRange(int a, int b);
	int nextEvenInRange(int a, int b);
};

int Random::nextOdd() {
	int n;
	do {
		n = rand();
	} while (n % 2 == 1);
	return n;
}
int Random::nextEven() {
	int n;
	do {
		n = rand();
	} while (n % 2 == 0);
	return n;
}
int Random::nextOddInRange(int a, int b) {
	int n;
	do {
		n = rand() % (b - a + 1) + a;
	} while (n % 2 == 1);
	return n;
}
int Random::nextEvenInRange(int a, int b) {
	int n;
	do {
		n = rand() % (b - a + 1) + a;
	} while (n % 2 == 0);
	return n;
}

int main() {
	Random r;
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextOdd();
		cout << n << ' ';
	}
	cout << endl << endl << "--2에서 " << "10까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextEvenInRange(2, 9);
		cout << n << ' ';
	}
	cout << endl;
}


//3-6
#include <cstdlib>
#include <ctime>
class Random {
public:
	int next();
	int nextInRange(int a, int b);
};

int Random::next() {
	int n;
	do {
		n = rand();
	} while (n % 2 == 1);
	return n;
}

int Random::nextInRange(int a, int b) {
	int n;
	do {
		n = rand() % (b - a + 1) + a;
	} while (n % 2 == 1);
	return n;
}

int main() {
	Random r;
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "--2에서 " << "10까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 10);
		cout << n << ' ';
	}
	cout << endl;
}


//3-5
#include <cstdlib>
#include <ctime>
class Random {
public:
	int next();
	int nextInRange(int a, int b);
	
};

int Random::next() {
	int n = rand();
	return n;
}

int Random::nextInRange(int a, int b) {	
	int n = rand() % (b - a + 1) + a;
	return n;
}

int main() {
	Random r;
	cout << "--0에서 " << RAND_MAX << "까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.next();
		cout << n << ' ';
	}
	cout << endl << endl << "--2에서 " << "4까지의 랜덤 정수 10개--" << endl;
	for (int i = 0; i < 10; i++) {
		int n = r.nextInRange(2, 4);
		cout << n << ' ';
	}
	cout << endl;
}


//3-4
class CoffeeMachine {
public:
	int water;
	int coffee;
	int sugar;
	CoffeeMachine(int c, int w, int s);
	void drinkEspresso();
	void drinkAmericano();
	void drinkSugarCoffee();
	void show();
	void fill();
};
CoffeeMachine::CoffeeMachine(int c, int w, int s) {
	coffee = c;
	water = w;
	sugar = s;
}
void CoffeeMachine::show() {
	cout << "커피 머신 상태, 커피: " << coffee << " 물: " << water << "	설탕: " << sugar << endl;
}


void CoffeeMachine::drinkEspresso() {
	coffee -= 1;
	water -= 1;
}

void CoffeeMachine::drinkAmericano() {
	coffee -= 1;
	water -= 2;
}

void CoffeeMachine::drinkSugarCoffee() {
	coffee -= 1;
	water -= 2;
	sugar = 1;
}

void CoffeeMachine::fill() {
	coffee = 10;
	water = 10;
	sugar = 10;
}


int main() {
	CoffeeMachine java(5, 10, 3);
	java.drinkEspresso();
	java.show();
	java.drinkAmericano();
	java.show();
	java.drinkSugarCoffee();
	java.show();
	java.fill();
	java.show();
}


//3-3
class Account {
	string name;
	int id;
	int money;
public:
	Account(string N, int num, int mon);
	void deposit(int m);
	string getOwner();
	int inquiry();
	int withdraw(int n);
};

Account::Account(string N, int num, int mon) {
	name = N;
	id = num;
	money = mon;
}

void Account::deposit(int m) {
	money += m;
}

int Account::withdraw(int n) {
	money -= n;
	return money;
}

int Account::inquiry() {
	return money; 
}

string Account::getOwner() {
	return name;
}

int main() {
	Account a("kitae", 1, 5000);
	a.deposit(50000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
	int money = a.withdraw(20000);
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl;
}


//3-2
#include <string>
class Date {
	int year;
	int month;
	int day;
public:
	Date(int y, int m, int d);
	Date(string D);
	void show();
	int getYear();
	int getMonth();
	int getDay();
};
Date::Date(string D) {
	int ind;

	year = stoi(D);
	ind = D.find('/');
	month = stoi(D.substr(ind + 1));

	ind = D.find('/', ind + 1);
	day = stoi(D.substr(ind + 1));
}
void Date::show() {
	cout << year << "년" << month << "월" << day << "일" << endl;
}

Date::Date(int y, int m, int d) {
	year = y;
	month = m;
	day = d;
}
int Date::getYear() {
	return year;
}
int Date::getMonth() {
	return month;
}
int Date::getDay() {
	return day;
}
int main() {
	Date birth(2014, 3, 20);
	Date independenceDay("1945/8/15");
	independenceDay.show();
	cout << birth.getYear() << "," << birth.getMonth() << "," << birth.getDay() << endl;
}


//3-1
class Tower {
public:
	int height;
	Tower();
	Tower(int m);
	int getHeight();
};
Tower::Tower() {
	height = 1;
}

Tower::Tower(int m) {
	height = m;
}

int Tower::getHeight() {
	return height;
}

int main() {
	Tower myTower;
	Tower seoulTower(100);
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;
	return 0;
}
*/