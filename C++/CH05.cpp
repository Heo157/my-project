#include <iostream>
using namespace std;

//5-8


/*
//5-7
class MyIntStack {
	int p[10];
	int tos = 0;
public:
	MyIntStack() {}
	bool push(int n);
	bool pop(int& n);
};

bool MyIntStack::push(int n) {
	if (tos == 10 ) {
		return false;
	}
	else {
		p[tos] = n;
		tos++;
		return true;
	}
}

bool MyIntStack::pop(int& n) {
	tos--;
	if (tos < 0) {
		return false;
	}
	else {
		n = p[tos];
		return true;
	}
}

int main() {
	MyIntStack a;
	for (int i = 0; i < 11; i++) {
		if (a.push(i)) cout << i << ' ';
		else cout << endl << i + 1 << "번째  stack full" << endl;
	}
	int n;
	for (int i = 0; i < 11; i++) {
		if (a.pop(n)) cout << n << ' ';
		else cout << endl << i + 1 << " 번째 stack empty";
	}
	cout << endl;
}


//5-6
#include <cstring>
char& find(char a[], char c, bool& success) {
	int size = sizeof(a);
	for (int i = 0; i < size; i++) {
		if (a[i] == c) {
			success = true;
			return a[i];
		}
	} 
}

int main() {
	char s[] = "Mike";
	bool b = false;
	char& loc = find(s, 'M', b);
	if (b == false) {
		cout << "M을 발견할 수 없다." << endl;
		return 0;
	}
	loc = 'm';
	cout << s << endl;
}


//5-5
class Circle {
	int radius;
public:
	Circle(int r) { radius = r; }
	int getRadius() { return radius; }
	void setRadius(int r) { radius = r; }
	void show() { cout << "반지름이 " << radius << "인 원" << endl; }
};

void increaseBy(Circle &a, Circle &b) {
	int r = a.getRadius() + b.getRadius();
	a.setRadius(r);
}

int main() {
	Circle x(10), y(5);
	increaseBy(x, y);
	x.show();
}


//5-4
bool bigger(int a, int b, int& big) {
	if (a > b) {
		big = a;
		return false;
	}
	else if (b > a) {
		big = b;
		return false;
	}
	else {
		return true;
	}
}

int main() {
	int a, b, big=0;

	cin >> a >> b;

	
	cout << big << " " << bigger(a, b, big);
}


//5-3
string combine(string &txt1, string& txt2, string& txt3) {
	txt3 = txt1 + " " + txt2;
	return txt3;
}

int main() {
	string text1("I love you"), text2("very much");
	string text3;

	combine(text1, text2, text3);
	cout << text3;
}


//5-2
double half(double& num) {
	return num /= 2;
}

int main() {
	double n = 20;
	half(n);
	cout << n;
}


//5-1
class Circle {
	int radius;
public:
	Circle();
	Circle(int radius) { this->radius = radius; }
	void swap(Circle &a, Circle &b);
	int getRadius() { return radius; }
	void setRadius(int radius) { this->radius = radius; }
};

void Circle::swap(Circle& a, Circle &b) {
	int swap = a.getRadius();
	a.setRadius(b.getRadius());
	b.setRadius(swap);

}

int main() {
	Circle a(20);
	Circle b(30);
	swap(a,b);
	cout << a.getRadius() << endl;
	cout << b.getRadius() << endl;
}
*/