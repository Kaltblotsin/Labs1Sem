﻿#include <iostream>
#include <conio.h>
#include <string>
#include <cmath>

using namespace std;

/*//НОРМАЛЬНО ОФОРМИТЬ КАК СВОЕ ЗАДАНИЕ!!!
void resize(int** resizeArray, int* resizeSize) {
    (*resizeSize)++;
    int* temp = new int[*resizeSize];
    for (int i = 0; i < (*resizeSize - 1); i++) {
        temp[i] = (*resizeArray)[i];
    }
    delete[] * resizeArray;
    *resizeArray = new int[*resizeSize];
    for (int i = 0; i < (*resizeSize - 1); i++) {
        (*resizeArray)[i] = temp[i];
    }
    delete[] temp;
}

void main() {
    int size = 1;
    int* arr;
    arr = new int[size];

    arr[0] = 1;
    resize(&arr, &size);
    arr[1] = 2;
    resize(&arr, &size);
    arr[2] = 3;

    cout << arr[0] << endl << arr[1] << endl << arr[2];
}
*/

void iAmLazy2() {
    system("cls");

    int size;
    int result[2] = { 0, 0 };

    cout << "Введите размер последовательности: ";
    cin >> size;

    int* arr = new int[size];

    for (int i = 0; i < size; i++) {
        cout << "Введите " << i << " элемент массива: ";
        cin >> arr[i];
    }

    for (int j = 0; j < size; j++) {
        if (arr[j] > 0) {
            if (result[0] < arr[j]) {
                result[0] = arr[j];
            }
        }
        if (arr[j] < 0) {
            if (result[1] > arr[j]) {
                result[1] = arr[j];
            }
        }
    }

    cout << "Ответ: максимальный положительный == " << result[0] << ", минимальный отрицательный == " << result[1] << endl;

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void iAmLazy() {
    system("cls");
    
    int size;
    int result[2] = { 0, 1 };
    
    cout << "Введите размер последовательности: ";
    cin >> size;

    int* arr = new int[size];
    
    for (int i = 0; i < size; i++) {
        cout << "Введите " << i << " элемент массива: ";
        cin >> arr[i];
    }

    for (int j = 0; j < size; j++) {
        if (arr[j] > 0) {
            result[0] += arr[j];
        }
        if (arr[j] < 0) {
            result[1] *= arr[j];
        }
    }
    
    cout << "Ответ: сумма положительных == " << result[0] << ", произведение отрицательных == " << result[1] << endl;

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void subsequence() {
    system("cls");
    
    class Subsequence {
    public:
        string numbers = "";
        int tempNumbers[4] = { 0, 0, 0, 0 };
        int arrSize = 1;
        const int zeroConst = 0;
        char symbol;
        int result = 0;
        //int* arr = new int[arrSize];

        bool outputOnAir() {
            cout << "Введите ваши элементы последовательности целых чисел через пробел(esc для выхода\\enter для подтверждения элемента): ";
            cout << numbers;
            return true;
        }

        void input() {
            while ((outputOnAir()) && ((symbol = _getch()) != 13)) {
                numbers += symbol;
                system("cls");
            }
        }

        /*void reArrSize()
        {
            int* reArrSize_arr = new int[arrSize + 1];
            for (int i = 0; i < arrSize; i++)
                reArrSize_arr[i] = arr[i];

            arrSize++;
            arr = reArrSize_arr;
            delete[] reArrSize_arr;
        }*/
    };

    Subsequence even;
    
    cout << "Найти  в  последовательности  n целых чисел и вывести значение суммы четных элементов.\n";

    even.input();

    for (int i = 0; i < even.numbers.length(); i++) {

        if ((even.numbers[i] == ' ') || (i == 0)) {
            if (i == 0) {
                even.tempNumbers[1] = 0;//Начало считывания
                even.tempNumbers[0] = 0;
            }
            else {
                even.tempNumbers[1] = i + 1;//Начало считывания
                even.tempNumbers[0] = i + 1;
            }

            while ((even.numbers[even.tempNumbers[0]] != ' ') && (!(even.tempNumbers[0] == even.numbers.length()))) {
                even.tempNumbers[0]++;
            }
            
            even.tempNumbers[2] = 0;
            even.tempNumbers[3] = even.tempNumbers[1];
            while (even.tempNumbers[1] < even.tempNumbers[0]) {
            even.tempNumbers[2] = even.tempNumbers[2] + ((even.numbers[even.tempNumbers[3]] - '0') * pow(10, (even.tempNumbers[0] - even.tempNumbers[1] - 1)));
            even.tempNumbers[0]--;
            even.tempNumbers[3]++;
            }

            if (!(even.tempNumbers[2] % 2)) {
                even.result += even.tempNumbers[2];
            }
        } 
    }
    //even.reArrSize();
    //even.arr[even.arrSize - 2] = even.tempNumbers[2];

    cout << "\nОтвет: " << even.result << endl;

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void lab7() {
    system("cls");
    double y[5] = { 3, -2, 0.9, 0.5, 1 };
    double p, q, result;
    
    p = 0;
    for (int i = 0; i < 5; i++) {
        if (y[i] < p) {
            p = y[i];
        }
    }

    result = 1;
    for (int j = 0; j < 5; j++) {
        result *= (y[j] - 5);
    }
    result += p;

    cout << "Ответ: " << result << endl;
    
    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void car() {
    system("cls");
    int arr[4];
    int number[2];
    int count;
    bool isAnswer;
    int sumOfArr = 0;

    cout << "Три приятеля были свидетелями нарушения правил дорожного движения. Номер автомобиля – четырехзначное число – никто полностью не запомнил. Из показаний следует, что номер делится на 2, на 7 и на 11, в записи номера участвуют только две цифры, сумма цифр номера равна 30.  Составить алгоритм и программу для определения номера автомашины.\n";

    for (int i = 1000; i < 10000; i++) {
        if (i == 1000) {
            cout << "Ответ:";
        }

        if ((!(i % 2)) && (!(i % 7)) && (!(i % 11))) {
            sumOfArr = 0;
            count = 0;
            isAnswer = false;
            for (int j = 10000; j >= 10; j /= 10) {
                arr[count] = (i % j) / (j / 10);
                count++;
            }
            
            number[0] = arr[0];
            number[1] = arr[1];
            for (int k = 2; k < 4; k++) {
                if (number[0] == number[1]) {
                    number[1] = arr[k];
                } else {
                    if ((number[0] == arr[k]) || (number[1] == arr[k])) {
                        isAnswer = true;
                    } else {
                        isAnswer = false;
                        break;
                    }
                }
                if ((k == 3) && (number[0] == number[1])) {
                    isAnswer = false;
                    break;
                }
            }
            
            for (int x = 0; x < 4; x++) {
                sumOfArr = sumOfArr + arr[x];
            }
            if (sumOfArr == 30) {
                isAnswer = true;
            } else {
                isAnswer = false;
            }
            
            if (isAnswer) {
                cout << " " << i;
            }
            /*for (int k = 0; k < 4; k++) {
                cout << arr[k];
            }
            cout << endl;
            count = 0;*/
        }
    }

    cout << endl;

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void vessel() {
    system("cls");
    class Vessel {
    public:
        const int maxCount = 12;
        int count = 1;
        double volume;
    };

    Vessel vessel[2];

    cout << "Имеются два  сосуда.  В первом сосуде находится C1 литров воды,  во втором –  C2 литров воды. Из первого сосуда переливают половину воды во второй  сосуд,  затем из второго переливают половину в первый сосуд,  и так далее. Сколько воды окажется в обоих сосудах после 12 переливаний?\n";
    cout << "C1 == ";
    cin >> vessel[0].volume;
    cout << "C2 == ";
    cin >> vessel[1].volume;

    while (vessel[0].count <= vessel[0].maxCount) {
        if (vessel[0].count % 2) {
            vessel[0].volume = vessel[0].volume + (vessel[1].volume / 2);
            vessel[1].volume /= 2;
        } else {
            vessel[1].volume = vessel[1].volume + (vessel[0].volume / 2);
            vessel[0].volume /= 2;
        }

        vessel[0].count++;
    }

    cout << "Ответ: C1 == " << vessel[0].volume << ", C2 == " << vessel[1].volume << ".\n";

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void magicNumber() {
    system("cls");

    class Task {
    public:
        int arr[3];
        int count = 0;
        bool answer = true;
        const int startNumber = 100;
        const int endNumber = 1000;
        const int rankOfEndNumber = 1000;

        void refresh() {
            count = 0;
            answer = true;
        }

        void end() {
            for (int i = startNumber; i < endNumber; i++) {
                if (i == ((int)sqrt(i) * (int)sqrt(i))) {
                    for (int j = rankOfEndNumber; j >= 10; j /= 10) {
                        arr[count] = (i % j) / (j / 10);
                        count++;
                    }
                    for (int k = 1; k < count; k++) {
                        if ((arr[(k - 1)] < arr[k]) && answer) {
                            answer = true;
                        }
                        else {
                            answer = false;
                        }
                    }
                    if (answer) {
                        cout << i << endl;
                    }
                    refresh();
                }
            }
        }
    };

    Task magic;

    magic.end();
    
    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void lab6() {
    /*
    class JustTest {
    public:
        double y;
        double x;

        void res() {
            cout << (x * y) << endl;
        }
    };
    JustTest test;
    test.x = 8;
    test.y = 9;
    test.res();
    system("pause");
    */

    system("cls");
    double a = 1.055;
    double x = 0.6;
    double y, z;
    int count;

    for (double n = 6; n <= 14; n += 2) {
        y = (pow(cos(pow(x, 2)), 2)) / (abs(x));
        if (y < (a * x * n)) {
            z = abs(y);
        } else {
            z = sqrt(1 + exp(-y));
        }

        cout << "y == " << y << endl << "z == " << z << endl;
    }

    cout << "Ошибок тут в принципе нету. А всё это происходит из-за не корректного условия задачи, т.е. переменная n не участвует в присвоении переменной y нового значения -> на z она тоже не влияет(только первый заход).\n";
    
    cout << "Вывести первые 6 натуральных чисел, делителями которых являются числа 3 и 5.\n";
    cout << "Введите число до которого надо проверить: ";
    cin >> count;

    for (int i = 1; i <= count; i++) {
        if (((i % 3) == 0) && ((i % 5) == 0)) {
            cout << i << endl;
        }
    }
    
    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void equipment() {
    system("cls");
    double p;
    double s[2000];
    int n;
    int tmp[2];
    double result = 0;

    cout << "Фирма ежегодно на протяжении n лет(до 1000) закупала оборудование стоимостью соответственно s1, s2, ..., sn pублей в год (эти числа вводятся и обрабатываются последовательно). Ежегодно в результате износа и морального старения (амортизации) все имеющееся оборудование уценивается на р% от первоначальной стоимости. Какова общая стоимость накопленного оборудования за n лет?\n";
    cout << "n == ";
    cin >> n;//Количество задействованных элементов массива s
    cout << "p(%) == ";
    cin >> p;
    p /= 100;
    
    tmp[0] = n;
    tmp[1] = 0;
    for (int i = 0; i < 2000; i++) {
        s[i] = NULL;
    }

    while (tmp[0] > 0) {
        cout << "s" << (tmp[1] + 1) << " == ";
        cin >> s[tmp[1]];
        tmp[0]--;
        tmp[1]++;
    }

    tmp[0] = n;
    tmp[1] = 0;
    while (tmp[1] < n) {
        result = result + (s[tmp[1]] * pow(p, tmp[0]));
        tmp[0]--;
        tmp[1]++;
    }

    cout << "Ответ: " << result << endl;

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void ticket() {
    system("cls");
    string ticketOne, ticketTwo;
    int number[2] = { 0, 0 };
    int tmp = 0;

    cout << "Шестизначный автобусный билет считается удачным, если сумма его цифр делится на 7. Могут ли два билета подряд быть удачными?\n";

    do {
        cout << "Введите номер первого билета: ";
        cin >> ticketOne;
    } while (ticketOne.length() != 6);

    do {
        cout << "Введите номер второго билета: ";
        cin >> ticketTwo;
    } while (ticketTwo.length() != 6);

    for (int i = 5; i >= 0; i--) {
        number[0] = number[0] + (ticketOne[i] - '0');//Крутая тема чтоб переводить char число в int, надо б запомнить)
        number[1] = number[1] + (ticketTwo[i] - '0');
        tmp++;
    }

    if (!(number[0] % 7) && !(number[1] % 7)) {
        cout << "Ответ: Да.\n";
    } else {
        cout << "Ответ: Нет.\n";
    }

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void firm() {
    system("cls");
    double p, q;
    int dayCount = 0;

    cout << "Торговая фирма в первый день работы реализовала товаров на P тыс. руб., а затем ежедневно увеличивала выручку на 3%. Какой будет выручка фирмы в тот день, когда она впервые превысит заданное значение Q? Сколько дней придется торговать фирме для достижения этого результата?\n";
    cout << "p == ";
    cin >> p;
    cout << "q == ";
    cin >> q;

    while (p <= q) {
        p *= 1.03;
        dayCount++;
    }

    cout << "Ответ: Выручка составит " << p << " и это займёт " << dayCount << " дней.\n";

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void lab5() {
    system("cls");
    double result[2];
    double a = 8;
    double m = 6;
    double b = 5 * pow(10, -3);
    double k[3] = { 1.6, 9.1, 8 };

    cout << "Цикл for:\n";
    for (int i = 0; i < 3; i++) {
        result[0] = sin(k[i] / a) / cos(m * b);
        result[1] = result[0] / (pow(result[0], 2) + 1) / (1 - exp(k[i]));
        cout << "d == " << result[0] << endl << "c == " << result[1] << endl;
    }

    cout << "Цикл while:\n";
    while (k[2] >= 3) {
        result[0] = sin(k[2] / a) / cos(m * b);
        result[1] = result[0] / (pow(result[0], 2) + 1) / (1 - exp(k[2]));
        cout << "d == " << result[0] << endl << "c == " << result[1] << endl;
        k[2] -= 0.5;
    }

    cout << "Двойной цикл:\n";
    k[0] = 1.7;
    k[1] = 5;
    k[2] = -2;
    a = 2;
    while (a <= 2.8) {
        for (int i = 0; i < 3; i++) {
            result[0] = sin(k[i] / a) / cos(m * b);
            result[1] = result[0] / (pow(result[0], 2) + 1) / (1 - exp(k[i]));
            cout << "d == " << result[0] << endl << "c == " << result[1] << endl;
        }

        a += 0.2;
    }

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void sphere() {
    system("cls");
    double data[3];
    double* temp = new double;

    cout << "Может ли шар радиуса r пройти через ромбообразное отверстие с диагоналями p и q?\nr == ";
    cin >> data[0];
    cout << "p == ";
    cin >> data[1];
    cout << "q == ";
    cin >> data[2];

    *temp = (data[1] * data[2]) / (sqrt((pow(data[1], 2)) + (pow(data[2], 2))));

    if (data[0] <= (*temp)) {
        cout << "Ответ: Да, может.\n";
    } else {
        cout << "Ответ: Нет, не может.\n";
    }

    delete temp;

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void chess() {
    system("cls");
    short int oX = 0;
    short int oY = 0;
    int iTest, jTest;
    short stage = 0;
    bool result = true;
    bool loopChess = true;
    bool err = false;
    short int chess[8][8] = { 1, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0 };
    /*
       _______________________________________________________
      |      |      |      |      |      |      |      |      |
      |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |
      |______|______|______|______|______|______|______|______|
      |      |      |      |      |      |      |      |      |
      |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |
      |______|______|______|______|______|______|______|______|
      |      |      |      |      |      |      |      |      |
      |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |
      |______|______|______|______|______|______|______|______|
      |      |      |      |      |      |      |      |      |
      |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |
      |______|______|______|______|______|______|______|______|
      |      |      |      |      |      |      |      |      |
      |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |
      |______|______|______|______|______|______|______|______|
      |      |      |      |      |      |      |      |      |
      |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |
      |______|______|______|______|______|______|______|______|
      |      |      |      |      |      |      |      |      |
      |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |
      |______|______|______|______|______|______|______|______|
      |      |      |      |      |      |      |      |      |
      |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |  K<- |
      |______|______|______|______|______|______|______|______|
      */
    while (loopChess) {
        system("cls");
        
        for (int i = 0; i < 8; i++) {
            //Отображение доски
            if (i == 0) {
                cout << " _______________________________________________________\n";
                cout << "|      |      |      |      |      |      |      |      |\n";
            }
            if (i > 0 && i < 8) {
                cout << "|______|______|______|______|______|______|______|______|\n";
                cout << "|      |      |      |      |      |      |      |      |\n";
            }

            for (int j = 0; j < 8; j++) {
                switch (chess[i][j]) {
                case 0:
                    cout << "|      ";
                    break;
                case 1:
                    cout << "|    < ";
                    break;
                case 2:
                    cout << "|  БК< ";
                    break;
                case 3:
                    cout << "|  БК  ";
                    break;
                case 4:
                    cout << "|  ЧС< ";
                    break;
                case 5:
                    cout << "|  ЧС  ";
                    break;
                }
            }
            cout << "|\n";

            if (i == 7) {
                cout << "|______|______|______|______|______|______|______|______|\n";
            }

            if (err && i == 7) {
                cout << "Вы не можете поставить черного слона на белого короля!\n";
                err = false;
            }
        }

        if (stage != 2) {
            switch (_getch()) {
            case 72:
                switch (chess[oY][oX]) {
                case 1:
                    chess[oY][oX] = 0;
                    break;
                case 2:
                    chess[oY][oX] = 3;
                    break;
                case 4:
                    chess[oY][oX] = 5;
                    break;
                }
                if (oY == 0) {
                    oY = 7;
                }
                else {
                    oY--;
                }
                switch (chess[oY][oX]) {
                case 0:
                    chess[oY][oX] = 1;
                    break;
                case 3:
                    chess[oY][oX] = 2;
                    break;
                case 5:
                    chess[oY][oX] = 4;
                    break;
                }
                break;
            case 80:
                switch (chess[oY][oX]) {
                case 1:
                    chess[oY][oX] = 0;
                    break;
                case 2:
                    chess[oY][oX] = 3;
                    break;
                case 4:
                    chess[oY][oX] = 5;
                    break;
                }
                if (oY == 7) {
                    oY = 0;
                }
                else {
                    oY++;
                }
                switch (chess[oY][oX]) {
                case 0:
                    chess[oY][oX] = 1;
                    break;
                case 3:
                    chess[oY][oX] = 2;
                    break;
                case 5:
                    chess[oY][oX] = 4;
                    break;
                }
                break;
            case 77:
                switch (chess[oY][oX]) {
                case 1:
                    chess[oY][oX] = 0;
                    break;
                case 2:
                    chess[oY][oX] = 3;
                    break;
                case 4:
                    chess[oY][oX] = 5;
                    break;
                }
                if (oX == 7) {
                    oX = 0;
                }
                else {
                    oX++;
                }
                switch (chess[oY][oX]) {
                case 0:
                    chess[oY][oX] = 1;
                    break;
                case 3:
                    chess[oY][oX] = 2;
                    break;
                case 5:
                    chess[oY][oX] = 4;
                    break;
                }
                break;
            case 75:
                switch (chess[oY][oX]) {
                case 1:
                    chess[oY][oX] = 0;
                    break;
                case 2:
                    chess[oY][oX] = 3;
                    break;
                case 4:
                    chess[oY][oX] = 5;
                    break;
                }
                if (oX == 0) {
                    oX = 7;
                }
                else {
                    oX--;
                }
                switch (chess[oY][oX]) {
                case 0:
                    chess[oY][oX] = 1;
                    break;
                case 3:
                    chess[oY][oX] = 2;
                    break;
                case 5:
                    chess[oY][oX] = 4;
                    break;
                }
                break;
            case 13:
                switch (stage) {
                case 0:
                    stage++;
                    chess[oY][oX] = 2;
                    break;
                case 1:
                    if (chess[oY][oX] == 2) {
                        err = true;
                    }
                    else {
                        stage++;
                        chess[oY][oX] = 4;
                    }
                    break;
                }
                break;
            case 27:
                loopChess = false;
                break;
            }
        } else {
            for (int iFill = 0; iFill < 8; iFill++) {
                for (int jFill = 0; jFill < 8; jFill++) {
                    if (chess[iFill][jFill] == 4 || chess[iFill][jFill] == 5 || chess[iFill][jFill] == 6) {
                        iTest = iFill;
                        jTest = jFill;
                        while (iTest >= 0 && jTest >= 0) {
                            chess[iTest][jTest] = 6;
                            iTest--;
                            jTest--;
                        }

                        iTest = iFill;
                        jTest = jFill;
                        while (iTest <= 7 && jTest <= 7) {
                            chess[iTest][jTest] = 6;
                            iTest++;
                            jTest++;
                        }

                        iTest = iFill;
                        jTest = jFill;
                        while (iTest >= 0 && jTest <= 7) {
                            chess[iTest][jTest] = 6;
                            iTest--;
                            jTest++;
                        }

                        iTest = iFill;
                        jTest = jFill;
                        while (iTest <= 7 && jTest >= 0) {
                            chess[iTest][jTest] = 6;
                            iTest++;
                            jTest--;
                        }
                    }
                }
            }

            for (int iCheck = 0; iCheck < 8; iCheck++) {
                for (int jCheck = 0; jCheck < 8; jCheck++) {
                    if (result) {
                        if (chess[iCheck][jCheck] == 2 || chess[iCheck][jCheck] == 3) {
                            result = false;
                        }
                    }
                }
            }

            if (result) {
                cout << "Ответ: Ууууу угрожаю, бойся меня!\n";
                loopChess = false;
            }
            else {
                cout << "Ответ: У нас с тобой нейтралитет, бро.)\n";
                loopChess = false;
            }
        }    
    }

    cout << "Для продолжения нажмите ENTER...";
    _getch();
}

void calculator() {
    system("cls");
    int result;
    int number[2] = { 0, 0 };
    string text;
    char textToChar[100];
    int temp[2] = { 0, 0 };

    cout << "Введите, то что вы хотите посчитать: ";
    getline(cin, text);//Получение из cin полной строки(с пробелами)

    strcpy_s(textToChar, text.c_str());//Безопасная копия строки text с переводом в char элемента и копия его значения в соответсвующий элемент массива textToChar
    for (int i = 0; i < 100; i++)
        if ((textToChar[i] == 'ю') || (textToChar[i] == ' '))
            textToChar[i] = NULL;

    for (int i = 0; i < 100; i++) {
        if (textToChar[i] == '+' || textToChar[i] == '-' || textToChar[i] == '*' || textToChar[i] == '/' || textToChar[i] == '%') {
            for (int j = i; j >= 0; j--) {
                if (textToChar[j] != NULL) {
                    switch (textToChar[j]) {
                    case '0':
                        number[0] = number[0] + 0 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '1':
                        number[0] = number[0] + 1 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '2':
                        number[0] = number[0] + 2 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '3':
                        number[0] = number[0] + 3 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '4':
                        number[0] = number[0] + 4 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '5':
                        number[0] = number[0] + 5 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '6':
                        number[0] = number[0] + 6 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '7':
                        number[0] = number[0] + 7 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '8':
                        number[0] = number[0] + 8 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    case '9':
                        number[0] = number[0] + 9 * pow(10, temp[0]);
                        temp[0]++;
                        break;
                    default:
                        break;
                    }
                }
            }

            for (int k = 99; k != i; k--) {
                if (textToChar[k] != NULL) {
                    switch (textToChar[k]) {
                    case '0':
                        number[1] = number[1] + 0 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '1':
                        number[1] = number[1] + 1 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '2':
                        number[1] = number[1] + 2 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '3':
                        number[1] = number[1] + 3 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '4':
                        number[1] = number[1] + 4 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '5':
                        number[1] = number[1] + 5 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '6':
                        number[1] = number[1] + 6 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '7':
                        number[1] = number[1] + 7 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '8':
                        number[1] = number[1] + 8 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    case '9':
                        number[1] = number[1] + 9 * pow(10, temp[1]);
                        temp[1]++;
                        break;
                    default:
                        break;
                    }
                }
            }

            switch (textToChar[i]) {
            case '+':
                result = number[0] + number[1];
                break;
            case '-':
                result = number[0] - number[1];
                break;
            case '*':
                result = number[0] * number[1];
                break;
            case '/':
                result = number[0] / number[1];
                break;
            case '%':
                result = number[0] % number[1];
                break;
            default:
                break;
            }
        }
    }

    cout << "Ответ: " << result << endl << "Для продолжения нажмите ENTER...";

    _getch();
}

void menu(int menuSelection) {
    if (menuSelection == 1){
        cout << "->";
    }
    cout << "1.Лабораторная работа №4. Дополнительное задание №1.\n";

    if (menuSelection == 2) {
        cout << "->";
    }
    cout << "2.Лабораторная работа №4. Дополнительное задание №2.\n";

    if (menuSelection == 3) {
        cout << "->";
    }
    cout << "3.Лабораторная работа №4. Дополнительное задание №5.\n";

    if (menuSelection == 4) {
        cout << "->";
    }
    cout << "4.Лабораторная работа №5.\n";

    if (menuSelection == 5) {
        cout << "->";
    }
    cout << "5.Лабораторная работа №5. Дополнительное задание №2.\n";

    if (menuSelection == 6) {
        cout << "->";
    }
    cout << "6.Лабораторная работа №5. Дополнительное задание №1.\n";

    if (menuSelection == 7) {
        cout << "->";
    }
    cout << "7.Лабораторная работа №5. Дополнительное задание №4.\n";

    if (menuSelection == 8) {
        cout << "->";
    }
    cout << "8.Лабораторная работа №6.\n";

    if (menuSelection == 9) {
        cout << "->";
    }
    cout << "9.Лабораторная работа №6. Дополнительное задание №1.\n";

    if (menuSelection == 10) {
        cout << "->";
    }
    cout << "10.Лабораторная работа №6. Дополнительное задание №3.\n";

    if (menuSelection == 11) {
        cout << "->";
    }
    cout << "11.Лабораторная работа №6. Дополнительное задание №4.\n";

    if (menuSelection == 12) {
        cout << "->";
    }
    cout << "12.Лабораторная работа №7.\n";

    if (menuSelection == 13) {
        cout << "->";
    }
    cout << "13.Лабораторная работа №7. Дополнительное задание №1.\n";

    if (menuSelection == 14) {
        cout << "->";
    }
    cout << "14.Лабораторная работа №7. Дополнительное задание №6.\n";

    if (menuSelection == 15) {
        cout << "->";
    }
    cout << "15.Лабораторная работа №7. Дополнительное задание №7.\n";
}

void input(int *inputSelection, bool *inputVerification, bool *inputBreak) {
    switch (_getch()) {
    case 72:
        if (*inputSelection == 1)
            *inputSelection = 15;
        else
            *inputSelection = *inputSelection - 1;
        break;
    case 80:
        if (*inputSelection == 15)
            *inputSelection = 1;
        else
            *inputSelection = *inputSelection + 1;
        break;
    case 13:
        *inputVerification = true;
        break;
    case 27:
        *inputBreak = true;
        break;
    }
}

bool check(int checkSelection, bool checkVerification) {
    if (checkVerification) {
        if (checkSelection == 1) {
            calculator();
        }
        if (checkSelection == 2) {
            chess();
        }
        if (checkSelection == 3) {
            sphere();
        }
        if (checkSelection == 4) {
            lab5();
        }
        if (checkSelection == 5) {
            firm();
        }
        if (checkSelection == 6) {
            ticket();
        }
        if (checkSelection == 7) {
            equipment();
        }
        if (checkSelection == 8) {
            lab6();
        }
        if (checkSelection == 9) {
            magicNumber();
        }
        if (checkSelection == 10) {
            vessel();
        }
        if (checkSelection == 11) {
            car();
        }
        if (checkSelection == 12) {
            lab7();
        }
        if (checkSelection == 13) {
            subsequence();
        }
        if (checkSelection == 14) {
            iAmLazy();
        }
        if (checkSelection == 15) {
            iAmLazy2();
        }
    }

    return false;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int selection = 1;
    bool verification = false;
    bool breaker = false;

    do {
        system("cls");

        menu(selection);
        
        input(&selection, &verification, &breaker);

        verification = check(selection, verification);
    } while (!(breaker));

    return 0;
}