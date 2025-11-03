#include <iostream>
using namespace std;

//4-14
class Player{
	string name;
	int num[3];
public:
	Player() :Player("플레이어") {}
	Player(string name) { this->name = name; }
	string getName() { return name; }
	bool playGambling();
};

bool Player::playGambling() {
	srand((unsigned)time(0));
	for (int i = 0; i < 3; i++) {
		num[i] = rand() % 3;
		cout << "\t" << num[i];
	}
	for (int i = 0; i < 2; i++) {
		if (num[i] != num[i + 1]) {
			return false;
		}
	}
	return true;
}

class Game {
	Player player[2];
	bool isGameCompleted = false;
public:
	Game();
	void play();
};

Game::Game(){
	cout << "****** 갬블링 게임을 시작합니다. ******" << endl;
	string p_name;
	cout << "첫번째 선수 이름>> ";
	cin >> p_name;
	player[0] = Player(p_name);
	cout << "두번째 선수 이름>> ";
	cin >> p_name;
	player[1] = Player(p_name);
}

void Game::play() {
	int i = 0;
	while (!isGameCompleted) {
		cout << player[i % 2].getName() << ":<Enter>" << endl;
		getchar();
		if (player[i % 2].playGambling()) {
			isGameCompleted = true;
			cout << "\t" << player[i % 2].getName() << "님 승리!!" << endl;
		}
		else {
			cout << "\t아쉽군요!" << endl;
		}
		i++;
	}
}

int main() {
	Game g;
	g.play();

	return 0;
}


//4-13
#include <cstring>
class Histogram {
	string str;
	int alphabet[26] = { 0 };
public:
	Histogram(string str){ this->str = str; }
	void countAlphabet();
	int getAlphabetSize();
	void put(string new_str) { this->str.append(new_str); }
	void putc(char a) { this->str.append(&a); }
	void print();
};

void Histogram::print() {
	cout << str << endl << endl;
	cout << "총 알파벳 수 " << getAlphabetSize() << endl << endl;

	countAlphabet();
	char ch = 'a';
	while (ch <= 'z') {
		cout << ch << " (" << alphabet[(int)ch - 'a'] << ")\t: ";
		for (int i = 0; i < alphabet[(int)ch - 'a']; i++) {
			cout << "*";
		}
		cout << endl;
		ch++;
	}
}

int Histogram::getAlphabetSize() {
	int cnt = 0;
	for (int i = 0; i < str.length(); i++) {
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
			cnt++;
		}
	}
	return cnt;
}


void Histogram::countAlphabet() {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z') {
			int ind = str[i] - 'A';
			alphabet[ind]++;
		}
		if (str[i] >= 'a' && str[i] <= 'z') {
			int ind = str[i] - 'a';
			alphabet[ind]++;
		}
	}
}

int main() {
	Histogram elvisHisto("Wise men say, only folls rush in But I can't help, ");
	elvisHisto.put("falling in love with you");
	elvisHisto.putc('-');
	elvisHisto.put("Elvis Presley");
	elvisHisto.print();
}


//4-12
class Circle {
	int radius;
	string name;
public:
	void setCircle(string name, int radius) { this->name = name; this->radius = radius; }
	double getArea() { return 3.14 * radius * radius; }
	string getName() { return name; }
};

class CircleManager {
	Circle* p;
	int size;
	string name;
	double area;
public:
	CircleManager(int size) { p = new Circle[size]; this->size = size; }
	~CircleManager() { delete[] p; }
	Circle* getCircle() { return p; }
	void searchByName();
	void searchByArea();
};

void CircleManager::searchByArea() {
	int a;
	cout << "최소 면적을 정수로 입력하세요 >> ";
	cin >> a;
	cout << a << "보다 큰 원을 겁색합니다." << endl;
	for (int i = 0; i < size; i++) {
		if (a < p[i].getArea()) {
			cout << name << "의 면적은 " << p[i].getArea() << ", ";
		}
	}
}

void CircleManager::searchByName() {
	string find;
	cout << "검색하고자 하는 원의 이름 >> ";
	cin >> find;
	for (int i = 0; i < size; i++) {
		if (find == p[i].getName()) {
			cout << "도넛의 면적은 " << p[i].getArea() << endl;
		} 
	}
	
}

int main() {
	int n;
	cout << "원의 개수 >> ";
	cin >> n;
	string name;
	int radi;
	CircleManager c(n);
	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 이름과 반지름 >> ";
		cin >> name >> radi;
		c.getCircle()[i].setCircle(name, radi);
	}
	c.searchByName();
	c.searchByArea();
	return 0;
}


//4-11
class Container {
	int size;
public:
	Container() { size = 10; }
	void fill() { size = 10; }
	void consume() { size -= 1; }
	int getSize() { return size; }
};

class CoffeeVendingMachine {
	Container tong[3];
	void fill();
	void selectEspresso();
	void selectAmericano();
	void selectSugarCoffee();
	void show();
public:
	void run();
};

void CoffeeVendingMachine::fill(){
	for (int i = 0; i < 3; i++) {
		tong[i].fill();
	}
	show();
}

void CoffeeVendingMachine::selectEspresso() {
	if (tong[0].getSize() > 0 && tong[1].getSize() > 0) {
		tong[0].consume();
		tong[1].consume();
		cout << "에스프레소 드세요" << endl;
	}
	else {
		cout << "원료가 부족합니다." << endl;
	}
}

void CoffeeVendingMachine::selectAmericano() {
	if (tong[0].getSize() > 0 && tong[1].getSize() > 0) {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		cout << "아메리카노 드세요" << endl;
	}
	else {
		cout << "원료가 부족합니다." << endl;
	}
}

void CoffeeVendingMachine::selectSugarCoffee() {
	if (tong[0].getSize() > 0 && tong[1].getSize() > 0 && tong[2].getSize() > 0) {
		tong[0].consume();
		tong[1].consume();
		tong[1].consume();
		tong[2].consume();
		cout << "설탕커피 드세요" << endl;
	}
	else {
		cout << "원료가 부족합니다." << endl;
	}
}

void CoffeeVendingMachine::show() {
	cout << "커피 " << tong[0].getSize() << ", 물 " << tong[1].getSize() << ", 설탕 " << tong[2].getSize() << endl;
}

void CoffeeVendingMachine::run() {
	int n;
	cout << "**** 커피자판기를 작동합니다. ****" << endl;
	while (true) {
		cout << "메뉴를 눌러주세요(1:에 2:아 3:설 4:잔 5:채)>>";
		cin >> n;
		if (n == 1) {
			selectEspresso();
		}
		else if (n == 2) {
			selectAmericano();
		}
		else if (n == 3) {
			selectSugarCoffee();
		}
		else if (n == 4) {
			show();
		}
		else {
			fill();
		}
	}
}

int main() {
	CoffeeVendingMachine a;
	a.run();
}


//4-10
#include <string>

class Person {
	string name;
public:
	Person(){}
	Person(string name) { this->name = name; }
	string getName() { return name; }
	void setName(string name) { this->name = name; }
};

class Family {
	Person* p;
	string familyName;
	int size;
public:
	Family(string name, int size);
	void show();
	void setName(int num, string personName);
	~Family();
};

Family::Family(string name, int size) {
	this->familyName = name;
	this->size = size;
	p = new Person[size];
}

Family::~Family() {
	delete[] p;
}

void Family::setName(int num, string personName) {
	p[num].setName(personName);
}

void Family::show() {
	cout << familyName << "가족은 다음과 같이 " << size << "명 입니다." << endl;
	for (int i = 0; i < size; i++) {
		cout << p[i].getName() << "	";
	}
}

int main() {
	Family* simpson = new Family("Simpson", 3);
	simpson->setName(0, "Mr. Simpson");
	simpson->setName(1, "Mr. Simpson");
	simpson->setName(2, "Mr. Simpson");
	simpson->show();
	delete simpson;

	return 0;
}


//4-9
class Person {
	string name;
	string tel;
public:
	Person();
	string getName() { return name; }
	string getTel() { return tel; }
	void set(string name, string tel);
};

Person::Person() {

}
void Person::set(string name, string tel) {
	this->name = name;
	this->tel = tel;
}

int main() {
	Person p[3];
	string person;
	string tel;

	cout << "이름과 전화 번호를 입력해주세요" << endl;
	for (int i = 0; i < 3; i++) {
		cout << "사람 " << i + 1 << ">> ";
		cin >> person >> tel;
		p[i].set(person, tel);
	}
	for (int i = 0; i < 3; i++) {
		cout << p[i].getName() << " ";
	}
	cout << "전화번호 검색합니다. 이름을 입력하세요 >> ";
	cin >> person;
	cout << "전화 번호는 ";
	for (int i = 0; i < 3; i++) {
		if (p[i].getName() == person) {
			cout << p[i].getTel();
		}
	}
	return 0;
}

//4-8
class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea();
};

void Circle::setRadius(int radius) {
	this->radius = radius;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	int n;
	cout << "원의 개수 >> ";
	cin >> n;
	Circle* c = new Circle[n];
	int r;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		c[i].setRadius(r);
	}
	for (int i = 0; i < n; i++) {
		if (c[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다.";
	return 0;
}


//4-7
class Circle {
	int radius;
public:
	void setRadius(int radius);
	double getArea();
};

void Circle::setRadius(int radius) {
	this -> radius = radius;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle c[3];
	int r;
	int cnt = 0;
	for (int i = 0; i < 3; i++) {
		cout << "원 " << i + 1 << "의 반지름 >> ";
		cin >> r;
		c[i].setRadius(r);
	}
	for (int i = 0; i < 3; i++) {
		if (c[i].getArea() > 100) {
			cnt++;
		}
	}
	cout << "면적이 100보다 큰 원은 " << cnt << "개 입니다.";
	return 0;
}

//4-6
#include <string>
int main() {
	string str;
	cout << "아래에 한 줄을 입력하세여.(exit을 입력하면 종료합니다)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, str);
		if (str == "exit") break;

		for (int i = str.length(); i >= 0; i--) {
			cout << str[i];
		}
		cout << endl;
	}
	return 0;
}


//4-5
#include <string>
#include <cstdlib>
#include <ctime>
int main() {
	string str;
	cout << "아래에 한 줄을 입력하세여.(exit을 입력하면 종료합니다)" << endl;
	while (true) {
		cout << ">>";
		getline(cin, str);
		if (str == "exit") break;

		srand((unsigned)time(0));
		int n = rand() % str.length();

		srand((unsigned)time(0));
		char a = 'a' + rand() % 26;

		str[n] = a;

		cout << str << endl;
	}
	return 0;
}


//4-4
class Sample {
	int* p;
	int size;
public:
	Sample(int n) {
		size = n; p = new int[n];
	}
	void read();
	void write();
	int big();
	~Sample();
};

void Sample::read() {
	for (int i = 0; i < size; i++) {
		cin >> p[i];
	}
}

void Sample::write() {
	for (int i = 0; i < size; i++) {
		cout << p[i] << " ";
	}
	cout << endl;
}

int Sample::big() {
	int max = 0;
	for (int i = 0; i < size; i++) {
		if (max < p[i]) {
			max = p[i];
		}
	}
	return max;
}

Sample::~Sample() {

}

int main() {
	Sample s(10);
	s.read();
	s.write();
	cout << "가장 큰 수는 " << s.big() << endl;
	return 0;
}


//4-3-2
#include <string>
int main() {
	string str;
	int index = 0, cnt = 0;

	cout << "문자열 입력>>";
	getline(cin, str);
	
	while (true) {
		index = str.find('a', index+1);
		if (index == -1) break;
		else cnt++;
	}
	cout << "문자 a는 " << cnt << "개 있습니다.";
	return 0;
}


//4-3-1
#include <string>
int main() {
	string str;
	int cnt = 0;

	cout << "문자열 입력>>";
	getline(cin, str);
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == 'a') cnt++;
	}

	cout << "문자 a는 " << cnt << "개 있습니다.";
	return 0;
}


//4-2
int main() {
	int* num = new int[5];
	int sum = 0;


	cout << "정수 5개 입력>>";
	for (int i = 0; i < 5; i++) {
		cin >> num[i];
		sum += num[i];
	}

	double avg = sum / 5.f;
	cout << "평균" << avg;
	return 0;
}


//4-1
class Color {
	int red, green, blue;
public:
	Color() { red = green = blue = 0; }
	Color(int r, int g, int b) { red = r; green = g; blue = b; }
	void setColor(int r, int g, int b) { red = r; green = g; blue = b; }
	void show() { cout << red << ' ' << green << ' ' << blue << endl; }
};

int main() {
	Color screenColor(255, 0, 0);
	Color* p;

	p = &screenColor;
	p->show();

	Color colors[3];
	p = colors;

	p[0].setColor(255, 0, 0);
	(p + 1)->setColor(0, 255, 0);
	(p + 2)->setColor(0, 0, 255);

	for (int i = 0; i < 3; i++) {
		p[i].show();
	}
}