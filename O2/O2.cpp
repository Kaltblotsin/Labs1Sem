﻿#include <iostream>
#include <cmath>

using namespace std;

void main()
{
    setlocale(LC_ALL, "Russian");//Поставили русский в консоле

    double A[] = { 0, -9, -4, 1.5 };
    double RES[2];
    A[0] = 0.5 * pow(10, -8);

    RES[0] = A[0] * A[1] + A[3] * sqrt(A[1] - 1);
    RES[1] = 0.5 * RES[0] / A[0] + exp(A[3]);
    cout << "\t\tЛаба №2(13 вариант)\n\tt == " << RES[0] << "\n\ty == " << RES[1] << endl;
    cout << "Ошибки в коде тут нету, просто компьютор, ну и лично я, не знаем как доставать корень отрицательных чисел => программа ломается.(\n";
    cout << "Но я как ответственный парень решил продолжить и исправить ошибку, так что c == 9. -.-\n";

    RES[0] = A[0] * A[1] + A[3] * sqrt((- A[1]) - 1);
    RES[1] = 0.5 * RES[0] / A[0] + exp(A[3]);
    cout << "\tt == " << RES[0] << "\n\ty == " << RES[1] << endl;

    cout << "А ещё решил сделать другие варианты.)\n";
    cout << "\t\t(1 вариант)\n";
    A[0] = 4;
    A[1] = 2 * pow(10, -4);
    A[2] = 8.1;
    RES[0] = 2 * A[0] / A[2] + log(2 + A[1]);
    RES[1] = sqrt(A[0] - 1) / (RES[0] + 1);
    cout << "\tt == " << RES[0] << "\n\tu == " << RES[1] << endl;

    cout << "\t\t(4 вариант)\n";
    A[0] = 6;
    A[1] = -1.2;
    A[2] = 0.4 * pow(10, 6);
    RES[0] = 2.6 * A[0] + cos(A[1] / (3 * A[2] + A[1]));
    RES[1] = (sin(A[0])) / (cos(A[0]));
    cout << "\tp == " << RES[0] << "\n\tq == " << RES[1] << endl;
}