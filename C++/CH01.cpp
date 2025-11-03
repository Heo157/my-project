#include <iostream>

//1-4
int main() {
    int i;
    for (i = 1; i < 5; i++) {
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << "\n";
    }

    return 0;
}


//1-3
int main() {
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;
    }

    std::cout << "1에서 10까지 더한 결과는 " << sum << "입니다.\n";

    return 0;
}


//1-2
int main() {
    std::cout << "컴퓨터공학과\n";
    std::cout << "21세\n";
    std::cout << "대통령\n";

    return 0;
}


//1-1
int main() {
    std::cout << "My name is Mike.\n";

    return 0;
}
