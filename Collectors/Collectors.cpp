#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

string Declination(int a, string text1, string text2, string text3) {                   // Метод для правильного склонения единиц измерения
    string text;
    if (a % 10 == 0 || a % 10 >= 5 || (a / 10) % 10 == 1) {                             // Условиями присваиваем переменной text необхоимое склонение слова "рубль"
        text = text1;
    }
    else {
        if (a % 10 == 1) {
            text = text2;
        }
        else {
            text = text3;
        }
    }

    return text;
}

int main()
{
    // Изменение кодировки терминала:
    system("chcp 1251 > nul");
    // Установка цвета фона терминала и цвета текста
    system("color 80");

    cout << endl;

    int duty;                                                                                        // Переменная для записи долга
    string name;                                                                                     // Переменная для записи Ф.И.О. должника
    string text1 = " рублей!";
    string text2 = " рубль!";
    string text3 = " рубля!";


    cout << " Введите Ф.И.О. должника: ";                                                            // Запрос Ф.И.О. должника
    getline(cin, name);                                                                              // Запись в переменную name Ф.И.О. должника
    cout << " Введите сумму долга: ";                                                                // Запрос суммы долга
    cin >> duty;                                                                                     // Запись в переменную duty суммы долга

    while (duty > 0) {                                                                               // Цикл для запроса суммы списания и вычисления остатка по кредиту
        string text = Declination(duty, text1, text2, text3);                                        // Локальная переменная для записи правильного склонения
                                                                                                     // вызываемым методом Declination
        int summ = 0;
                                  
        cout << " " << name << " Ваш долг перед банком составляет: " << duty << text << endl;
        cout << " Введите сумму погашения долга:";
        cin >> summ;
        if (summ <= 0) {                                                                             // Проверка на корректность ввода суммы списания
            cout << " Нулевое или отрицательное погашение долга не допустимы! Попробуйте ещё раз!" << endl;
        }
        else
        {
            duty -= summ;
        }
    }

    if (duty <= 0) {                                                                                 // Вывод сообщения о погашении кредита с отрицательным балансом кредита
        string text = Declination(duty * (-1), text1, text2, text3);                                 // Локальная переменная для записи правильного склонения
                                                                                                     // вызываемым методом Declination
        cout << " Долг погашен, долг за банком составляет: " << duty * (-1) << text << endl;
    }


    // Задержка окна консоли:
    system("pause > nul");

    return 0;
}