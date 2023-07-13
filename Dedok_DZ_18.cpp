#include <iostream>
#include <string>
#include <cmath>
using namespace std;
//к заданию 1
double calculatePower(double base, int exponent) {
    double result = 1.0;

    // Обработка случая, когда показатель степени отрицателен
    if (exponent < 0) {
        base = 1.0 / base;
        exponent = -exponent;
    }

    // Вычисление степени числа
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }

    return result;
}
//к заданию 2
int sumInRange(int num1, int num2) {
    int sum = 0;

    int start = min(num1, num2);
    int end = max(num1, num2);

    for (int i = start; i <= end; i++) {
        sum += i;
    }

    return sum;
}
//к заданию 3
bool isPerfectNumber(int number) {
    int sum = 0;
    for (int i = 1; i < number; i++) {
        if (number % i == 0) {
            sum += i;
        }
    }
    if (sum == number) {
        return true;
    }
    else {
        return false;
    }
}
void findPerfectNumbers(int start, int end) {
    cout << "Совершенные числа в интервале [" << start << ", " << end << "]: ";

    for (int number = start; number <= end; number++) {
        if (isPerfectNumber(number)) {
            cout << number << " ";
        }
    }

    cout << "\n";
}
//к заданию 5
bool isHappyNumber(int number) {
    if (number < 100000 || number > 999999) {
        return false;
    }
    int digit1 = number / 100000;
    int digit2 = (number / 10000) % 10;
    int digit3 = (number / 1000) % 10;
    int digit4 = (number / 100) % 10;
    int digit5 = (number / 10) % 10;
    int digit6 = number % 10;

    if (digit1 + digit2 + digit3 == digit4 + digit5 + digit6) {
        return true;
    }
    else {
        return false;
    }
}
//к заданию 8
int binaryToDecimal(const string & binaryNumber) {
    int decimalNumber = 0;
    int power = 0;

    for (int i = binaryNumber.length() - 1; i >= 0; --i) {
        if (binaryNumber[i] == '1') {
            decimalNumber += std::pow(2, power);
        }
        power++;
    }

    return decimalNumber;
}
int main()
{
    setlocale(LC_ALL, "RUS");
    //Task_1

    double base;
    int exponent;

    cout << "Введите основание степени: ";
    cin >> base;

    cout << "Введите показатель степени: ";
    cin >> exponent;

    double result = calculatePower(base, exponent);

    cout << "Результат: " << result << "\n";
    cout << "\n"; 

    //Task_2
    int num1, num2;

    cout << "Введите первое число: ";
    cin >> num1;
    cout << "Введите второе число: ";
    cin >> num2;

    int result_1 = sumInRange(num1, num2);
    cout << "Сумма чисел в диапазоне: " << result_1 << "\n";
    cout << "\n";

    //Task_3
    int start, end;

    cout << "Введите начало интервала: ";
    cin >> start;

    cout << "Введите конец интервала: ";
    cin >> end;
    findPerfectNumbers(start, end);
    cout << "\n";

    //Task_5
    int number;
    cout << "Введите шестизначное число: ";
    cin >> number;

    if (isHappyNumber(number)) {
        cout << "Число является счастливым!" << "\n";
    }
    else {
        cout << "Число не является счастливым." << "\n";
    }
    cout << "\n";

    //Task_8
    string binaryNumber;
    cout << "Введите двоичное число: ";
    cin >> binaryNumber;

    int decimalNumber = binaryToDecimal(binaryNumber);
    cout << "Десятичное представление: " << decimalNumber << "\n";
}
