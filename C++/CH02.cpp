#include <iostream>
using namespace std;
/*
//2-16
#include<ctype.h>
#include <cstring>
int main() {
	char buf[10000];
	char buf1[10000];
	int sum = 0;

	cout << "영문 텍스트를 입력하세요. 히스토그램을 그립니다." << endl;
	cout << "텍스트의 끝은 ; 입니다. 1000-개까지 가능합니다." << endl;

	cin.getline(buf, 10000, ';');
	for (int i = 0; i < strlen(buf); i++) {
		cout << tolower(buf);
		sum += isalpha(buf1[i]);
	}
	cout << "총 알파벳 수 " << sum << endl;

}


//2-15
int main() {
	int a, b;
	char x;
	while (1) {
		cout << "?  ";
		cin >> a >> x >> b;

		switch (x) {
		case '+':
			cout << a << " " << x << " " << b << " = " << a + b << endl;
			break;
		case '-':
			cout << a << " " << x << " " << b << " = " << a - b << endl;
			break;
		case '*':
			cout << a << " " << x << " " << b << " = " << a * b << endl;
			break;
		case '/':
			cout << a << " " << x << " " << b << " = " << a / b << endl;
			break;
		case '%':
			cout << a << " " << x << " " << b << " = " << a % b << endl;
			break;
 		}
	}
	return 0;
}


//2-14
#include <cstring>
int main() {
	char coffe[100];
	int num;
	int m = 0;
	
	while (1) {
		cout << "에스프레소 2000원, 아메리카노 2300원, 카푸치노 2500원입니다." << endl;
		cout << "주문>>";
		cin >> coffe >> num;
		if (strcmp(coffe, "에스프레소") == 0) {
			m += num * 2000;
			cout << num * 2000 << "입니다. 맛있게 드세요" << endl;
		}
		else if (strcmp(coffe, "아메리카노") == 0) {
			m += num * 2300;
			cout << num * 2300 << "입니다. 맛있게 드세요" << endl;
		}
		else if (strcmp(coffe, "카푸치노") == 0) {
			m += num * 2500;
			cout << num * 2500 << "입니다. 맛있게 드세요" << endl;
		}
		if (m >= 20000) {
			cout << "오늘 " << m << "원을 판매하여 카페를 닫습니다. 내일 봐요~" << endl;
			break;
		}
	}
	return 0;
}


//2-13
int main() {
	int menu, p;

	cout << "***** 승리장에 오신 것을 환영합니다. *****" << endl;

	while(1){
		cout << "짬뽕:1, 짜장:2, 군만두:3, 종료:4>>";
		cin >> menu;
		if (menu == 1) {
			cout << "몇인분?";
			cin >> p;
			cout << "짬뽕 " << p << "인분 나왔습니다." << endl;
		}
		else if (menu == 2) {
			cout << "몇인분?";
			cin >> p;
			cout << "짜장 " << p << "인분 나왔습니다." << endl;
		}
		else if (menu == 3) {
			cout << "몇인분?";
			cin >> p;
			cout << "군만두 " << p << "인분 나왔습니다." << endl;
		}
		else if (menu == 4) {
			cout << "오늘 영업은 끝났습니다." << endl;
			break;
		}
		else {
			cout << "다시 주문하세요!!" << endl;
		}
	}
	return 0;
}


//2-12
int sum(int a, int b);

int main() {
	int k, n = 0;
	cout << "끝 수를 입력하세요>>";
	cin >> n;
	cout << "1에서 " << n << " 까지의 합은 " << sum(1, n) << " 입니다." << endl;
	return 0;
}
int sum(int a, int b) {
	int k, res = 0;
	for (k = a; k <= b; k++) {
		res += k;
	}
	return res;
}


//2-11
int main() {
	int k, n = 0;
	int sum = 0;
	cout << "끝 수를 입력하세요>>";
	cin >> n;
	for (k = 1; k <= n; k++) {
		sum += k;
	}

	cout << "1에서 " << n << " 까지의 합은 " << sum << " 입니다." << endl;
	return 0;
}


//2-10
#include <cstring>
int main() {
	char n[100];

	cout << "문자열 입력>>";
	cin >> n;

	for (int i = 0; i < strlen(n); i++) {
		for (int j = 0; j <= i; j++) {
			cout << n[j];
		}
		cout << endl;
	}

	return 0;
}


//2-9
int main() {
	char name[10];
	char addr[100];
	int age;

	cout << "이름은?";
	cin.getline(name, 10);

	cout << "주소는?";
	cin.getline(addr,100);
	
	cout << "나이는?";
	cin >> age;
	
	cout << name << ", " << addr << ", " << age << endl;

	return 0;
}


//2-8(안됨)
#include <string.h>
int main() {
	char name[100];
	int max = 0;
	char max_name[100];

	cout << "5명의 이름을 ';'으로 구분하여 입력하세요." << endl;
	cout << ">>";
	
	for (int i = 0; i < 5; i++) {
		cin.getline(name, 100, ';');
		cout << i + 1 << " : " << name << endl;
		if (max < strlen(name)) {
			strcpy(max_name, name);
			max = strlen(name);
		}
	}
	cout << "가장 긴 이름은 " << max_name << endl;
	return 0;
}

//2-7
#include <cstring>
int main() {
	char x[100];

	while (true) {
		cout << "종료하고싶으면 yes를 입력하세요 >> ";
		cin.getline(x, 100);

		if (strcmp(x, "yes") == 0)
			break;
	}
	return 0;
}

 
//2-6
#include <cstring>
int main() {
	char ps[100];
	char psc[100];

	cout << "새 암호를 입력하세요>> ";
	cin >> ps;
	cout << "새 암호를 다시 한 번 입력하세요>> ";
	cin >> psc;

	if (!strcmp(ps, psc))
		cout << "같습니다.\n";
	else
		cout << "다릅니다.\n";

	return 0;
}


//2-5
int main() {
	char a[100];
	int cnt = 0, i = 0;

	cout << "문자들을 입력하라(100개 미만).";
	cin.getline(a, 100, '\n');
	while (a[i]!=EOF) {
		if (a[i] == 'x')
			cnt++;
		i++;
	}
	cout << "x의 개수는 " << cnt;

	return 0;
}


//2-4
int main() {
	double a[5];
	double max = 0;
	cout << "5개의 실수를 입력하라 >> ";
	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 5; i++) {
		if (max < a[i]) {
			max = a[i];
		}
	}
	cout << "제일 큰 수 = " << max << endl;

	return 0;
}

//2-3
int main() {
	int a, b;

	cout << "두 수를 입력하라>>";
	cin >> a >> b;
	if (a > b)
		cout << "큰 수 = " << a;
	else
		cout << "큰 수 = " << b;
	
	return 0;
}


//2-2
int main() {
	for (int i = 1; i < 10; i++) {
		for (int j = 1; j < 10; j++) {
			cout << j << " * " << i << " = " << i * j << " ";
		}
		cout << "\n";
	}
	return 0;
}


//2-1
int main() {
	int cnt = 0;
	for (int i = 1; i <= 100; i++) {
		cout << i << " ";
		cnt++;
		if (cnt == 10) {
			cnt = 0;
			cout << "\n";
		}
	}
}
*/