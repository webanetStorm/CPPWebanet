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

		cout << ( ( c - a ) / b ) << endl;
	}

    int* Distribute( int count )
    {
        int* result = new int[2] { 0, 0 };

        if ( count >= 3 and count != 5 )
        {
            result[0] = count / 3;

            if ( count % 3 == 1 )
            {
                result[0]--;
                result[1] = 1;
            }
            else if ( count % 3 == 2 )
            {
                result[0] -= 2;
                result[1] = 2;
            }
        }

        return result;
    }

	void FuncB()
	{
        int m;

        cout << "Ввод: ";
        if ( !( cin >> m ) or m > 2000000000 )
        {
            cout << "Некорректный ввод\n";
            return;
        }

        int* result = Distribute( m );
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
                result += n * m - j * n - i * m + i * j;

        cout << "Ответ: " << result << endl;
	}

	void FuncD()
	{
        unsigned int countFreeSeats, numFreeSeat, resultTemp = 0, result = 0;
        int x = 0, y = 55;
        vector<vector<int>> map;
        vector<int> mapFreeSeats;

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

            mapFreeSeats.push_back( numFreeSeat );
        }


        for ( int i = 0; i < 9; i++ )
        {
            map.push_back( { ++x, ++x, ++x, ++x, --y, --y } );

            bool flag = true;

            for ( int j = 0; j < map[i].size(); j++ )
            {
                if ( find( mapFreeSeats.begin(), mapFreeSeats.end(), map[i][j] ) == mapFreeSeats.end() )
                {
                    flag = false;
                    break;
                }
            }

            if ( flag )
            {
                resultTemp++;
                result = WebanetE::Max( result, resultTemp );
            }
            else
                resultTemp = 0;
        }


        cout << "\nОтвет: " << result << endl;
	}

	void FuncE()
	{
        
	}

}
