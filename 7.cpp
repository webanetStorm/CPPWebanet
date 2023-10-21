#include <algorithm> // библиотека алгоритмических функций (понадобится только sort())
#include <iostream>
#include <vector>
#include "5.h" // для использования ф. Max()

using namespace std;


namespace WebanetG
{

	void FuncA()
	{
		int a = 20, b = 10, c = 55;

		cout << ( ( c - a ) / b ) << endl; // из макс. стоимости вычитаем стоимость основания, а оставшуюся сумму делим на стоиомсть 1 лопасти
	}

    int* Distribute( int count ) // распределение спиннеров, возвращает в виде массива
    {
        int* result = new int[2] { 0, 0 }; // result[0] - 3-лопастные, result[1] - 4-лопастные

        if ( count >= 3 and count != 5 )
        {
            result[0] = count / 3; // распределяем лопасти на 3-лопастные спиннеры

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

        cout << "Ввод: ";
        if ( !( cin >> m ) or m > 2000000000 )
        {
            cout << "Некорректный ввод\n";
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
            cout << "Некорректный ввод\n";
            return;
        }

        cout << "M: ";
        if ( !( cin >> m ) or m > 75000 )
        {
            cout << "Некорректный ввод\n";
            return;
        }


        for ( int i = 0; i < n; i++ )
            for ( int j = 0; j < m; j++ )
                result += n * m - j * n - i * m + i * j; // считаем кол-во вариантов, исключая повторяющиеся прямоугольники

        cout << "Ответ: " << result << endl;
	}

	void FuncD()
	{
        unsigned int countFreeSeats, numFreeSeat, resultTemp = 0, result = 0; // countFreeSeats - кол-во свободных мест, numFreeSeat - номер свободных мест
        int x = 0, y = 55; // номера мест для формирования карты вагона
        vector<vector<int>> map; // карта вагона
        vector<int> mapFreeSeats; // карта свободных мест

        cout << "Кол-во свободных мест: ";
        if ( !( cin >> countFreeSeats ) or countFreeSeats > 54 )
        {
            cout << "Некорректный ввод\n";
            return;
        }

        cout << "Номера свободных мест:" << endl;
        for ( int i = 0; i < countFreeSeats; i++ )
        {
            if ( !( cin >> numFreeSeat ) or numFreeSeat > 54 or numFreeSeat == 0 )
            {
                cout << "Некорректный ввод\n";
                return;
            }

            mapFreeSeats.push_back( numFreeSeat ); // добавляем в массив mapFreeSeats номер свободного места
        }


        for ( int i = 0; i < 9; i++ ) // проход по всем девяти рядам вагона
        {
            map.push_back( { ++x, ++x, ++x, ++x, --y, --y } ); // формирование карты вагона (первые 4 числа - места-купе, последние два - места сбоку)

            bool flag = true; // true, если ряд полностью свободен

            for ( int j = 0; j < map[i].size(); j++ ) // перебор мест в ряду
            {
                if ( find( mapFreeSeats.begin(), mapFreeSeats.end(), map[i][j] ) == mapFreeSeats.end() ) // проверка на свободность места
                {
                    flag = false;
                    break;
                }
            }

            if ( flag )
            {
                resultTemp++; // увеличиваем текущее кол-во подряд идущих свободных купе
                result = WebanetE::Max( result, resultTemp ); // записываем макс. число подряд идущих свободных купе
            }
            else
                resultTemp = 0; // если ряд не свободен, то обнуляем текущее кол-во подряд идущих свободных купе
        }


        cout << "\nОтвет: " << result << endl;
	}

	void FuncE()
	{
        // result - массив с искомыми значениями, free и freeTemp: первый элемент - точка отсчета свободных мест на отрезке, второй - кол-во свободных мест на отрезке
        int n, k, result[2] = { 0, 0 }, free[2] = { 0, 0 }, freeTemp[2] = { 0, 0 };
        vector<char> row = { '+' }; // ряд в зале (плюсы - занятые места, минусы - свободные)

        cout << "N: ";
        if ( !( cin >> n ) )
        {
            cout << "Некорректный ввод\n";
            return;
        }
        cout << "K: ";
        if ( !( cin >> k ) or k > n )
        {
            cout << "Некорректный ввод\n";
            return;
        }

        for ( int i = 0; i < n; i++ )
            row.push_back( '-' ); // в начале все места свободны (-)
        row.push_back( '+' ); // по краям места заняты персоналом (+)

        for ( int i = 0; i < k; i++ ) // Перебор всех школьников
        {
            for ( int j = 0; j < row.size(); j++ ) // перебор мест в ряду
            {
                if ( row[j] == '-' ) // если место свободно
                {
                    freeTemp[1]++; // то начинаем подсчет кол-ва свободных мест на текущем отрезке
                    if ( row[j - 1] == '+' ) // если предыдущее место занято, то точкой отсчета отрезка будет текущий индекс j
                        freeTemp[0] = j;

                    if ( freeTemp[1] > free[1] )
                        free[0] = freeTemp[0], free[1] = freeTemp[1]; // перекладываем значения из временнного массива в основной, если текущий отрезок свободных мест больше предыдущего
                }
                else
                    freeTemp[0] = 0, freeTemp[1] = 0; // обнуление временного массива свободных мест
            }

            row[free[1] / 2 + free[0]] = '+'; // располагаем школьника в середину отрезка свободных мест
            free[1] % 2 == 0 ? result[0] = free[1] / 2 - 1, result[1] = free[1] / 2 : result[0] = free[1] / 2, result[1] = free[1] / 2; // подсчет свободных мест справа и слева от севшего
            free[0] = 0, free[1] = 0; // обнулеение основого массива свобобдных мест
        }

        cout << result[0] << " " << result[1] << endl;
	}

}
