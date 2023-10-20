#include <algorithm>
#include <iostream>
#include <vector>
#include "5.h"

using namespace std;


namespace WebanetG
{

	void FuncA()
	{
		int a = 20, b = 10, c = 55;

		cout << ( ( c - a ) / b ) << endl; // из макс. стоимости вычитаем стоимость основани€, а оставшуюс€ сумму делим на стоиомсть 1 лопасти
	}

    int* Distribute( int count ) // распределение спиннеров, возвращает в виде массива
    {
        int* result = new int[2] { 0, 0 }; // result[0] - 3-лопастные, result[1] - 4-лопастные

        if ( count >= 3 and count != 5 )
        {
            result[0] = count / 3; // распредел€ем лопасти на 3-лопастные спиннеры

            if ( count % 3 == 1 ) // если осталась одна лопасть
            {
                result[0]--; // то за счет одного 3-лопастного спиннера
                result[1] = 1; // делаем один 4-лопастной
            }
            else if ( count % 3 == 2 ) // если их осталось две
            {
                result[0] -= 2; // то за счет двух 3-лопастных
                result[1] = 2; // делаем два 4-лопастных
            }
        }

        return result;
    }

	void FuncB()
	{
        int m; // кол-во лопастей

        cout << "¬вод: ";
        if ( !( cin >> m ) or m > 2000000000 )
        {
            cout << "Ќекорректный ввод\n";
            return;
        }

        int* result = Distribute( m ); // распределение лопастей по спиннерам
        cout << "3-лопастыне: " << result[0] << endl << "4-лопастные: " << result[1] << endl;
	}

	void FuncC()
	{
        int n, m, result = 0;

        cout << "N: ";
        if ( !( cin >> n ) or n > 75000 )
        {
            cout << "Ќекорректный ввод\n";
            return;
        }

        cout << "M: ";
        if ( !( cin >> m ) or m > 75000 )
        {
            cout << "Ќекорректный ввод\n";
            return;
        }


        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < m; j++ )
                result += n * m - j * n - i * m + i * j; // считаем кол-во вариантов, исключа€ повтор€ющиес€ пр€моугольники

        cout << "ќтвет: " << result << endl;
	}

	void FuncD()
	{
        unsigned int countFreeSeats, numFreeSeat, resultTemp = 0, result = 0; // countFreeSeats - кол-во свободных мест, numFreeSeat - номер свободных мест
        int x = 0, y = 55; // номера мест дл€ формировани€ карты вагона
        vector<vector<int>> map; // карта вагона
        vector<int> mapFreeSeats; // карта свободных мест

        cout << " ол-во свободных мест: ";
        if ( !( cin >> countFreeSeats ) or countFreeSeats > 54 )
        {
            cout << "Ќекорректный ввод\n";
            return;
        }

        cout << "Ќомера свободных мест:" << endl;
        for ( int i = 0; i < countFreeSeats; i++ )
        {
            if ( !( cin >> numFreeSeat ) or numFreeSeat > 54 or numFreeSeat == 0 )
            {
                cout << "Ќекорректный ввод\n";
                return;
            }

            mapFreeSeats.push_back( numFreeSeat ); // добавл€ем в массив mapFreeSeats номер свободного места
        }


        for ( int i = 0; i < 9; i++ ) // проход по всем дев€ти р€дам вагона
        {
            map.push_back( { ++x, ++x, ++x, ++x, --y, --y } ); // формирование карты вагона (первые 4 числа - места-купе, последние два - места сбоку)

            bool flag = true; // true, если р€д полностью свободен

            for ( int j = 0; j < map[i].size(); j++ ) // перебор мест в р€ду
            {
                if ( find( mapFreeSeats.begin(), mapFreeSeats.end(), map[i][j] ) == mapFreeSeats.end() ) // поиск номера места в массиве свободных мест
                {
                    flag = false;
                    break;
                }
            }

            if ( flag )
            {
                resultTemp++; // увеличиваем текущее кол-во подр€д идущих свободных купе
                result = WebanetE::Max( result, resultTemp ); // записываем макс. число подр€д идущих свободных купе
            }
            else
                resultTemp = 0; // если р€д не свободен, то обнул€ем текущее кол-во подр€д идущих свободных купе
        }


        cout << "\nќтвет: " << result << endl;
	}

	void FuncE()
	{
        
	}

}
