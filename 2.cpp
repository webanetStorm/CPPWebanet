#include <iostream>
#include <math.h>

using namespace std;


namespace WebanetB
{

	float Pi()
	{
		return 3.1415926535;
	}

	void FuncA()
	{
		float r1, r2, h;

		cout << "Радиус основания конуса: ";
		cin >> r1;

		cout << "Радиус крыши конуса: ";
		cin >> r2;

		cout << "Ввысота конуса: ";
		cin >> h;


		float l = sqrt( pow( h, 2 ) + pow( r1 - r2, 2 ) );

		cout << "Объём: " << 1.0 / 3.0 * Pi() * h * ( pow( r1, 2 ) + r1 * r2 + pow( r2, 2 ) );
		cout << "\nПлощадь поверхности: " << Pi() * ( pow( r1, 2 ) + ( r1 + r2 ) * l + pow( r2, 2 ) ) << endl;
	}

	void FuncB()
	{
		float a, x;

		cout << "Число A: ";
		cin >> a;

		cout << "Число X: ";
		cin >> x;

		cout << endl;


		abs( x ) < 1
			? x != 0 ? cout << "w = " << a * log( x ) << endl : cout << "Некорректное значение для X\n"
			: a - pow( x, 2 ) >= 0 ? cout << "w = " << sqrt( a - pow( x, 2 ) ) << endl : cout << "Некорректные значения переменных\n";
	}

	void FuncC()
	{
		float x, y, b;

		cout << "Число X: ";
		cin >> x;

		cout << "Число Y: ";
		cin >> y;

		cout << "Число B: ";
		cin >> b;

		cout << endl;


	    b >= x and b - y > 0 ? cout << log( b - y ) * sqrt( b - x ) << endl : cout << "Некорректные значения\n";
	}

	void FuncD()
	{
		int n;

		cout << "Число N: ";
		cin >> n;

		if ( n >= 1 )
		{
			for ( int i = n; i < n + 10; i++ )
				cout << i << endl;
		}
		else
			cout << "N должно быть натуральным числом\n";
	}

	void FuncE()
	{
		for ( float x = -4; x <= 4; x += 0.5 )
		{
			if ( x == 1 )
			{
				cout << "Ошибка\n";
				continue;
			}

			cout << ( pow( x, 2 ) - 2 * x + 2 ) / ( x - 1 ) << endl;
		}
	}

}
