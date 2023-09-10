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
		float R = 5, r = 3, h = 8, l = 4;

		cout << "Объём: " << 1.0 / 3.0 * Pi() * h * ( pow( R, 2 ) + R * r + pow( r, 2 ) );
		cout << "\nПлощадь поверхности: " << Pi() * ( pow( R, 2 ) + ( R + r ) * l + pow( r, 2 ) ) << endl;
	}

	void FuncB()
	{
		float a = 3, x = 0.3;
		abs( x ) < 1 ? cout << "w1 = " << a * log(x) << endl : cout << "Некорректное значение\n";
		
		a = 5, x = 2;
		abs( x ) >= 1 and a - pow( x, 2 ) >= 0 ? cout << "w2 = " << sqrt(a - pow(x, 2)) << endl : cout << "Некорректные значения\n";
	}

	void FuncC()
	{
		float x = 3, y = 5, b = 11;

	    b >= x and b - y > 0 ? cout << log( b - y ) * sqrt( b - x ) : cout << ":(";
	}

	void FuncD()
	{
		int n = 2;

		if ( n >= 1 )
		{
			for ( int i = n; i < n + 10; i++ )
				cout << i << endl;
		}
		else
			cout << "N должно быть натуральным числом";
	}

	void FuncE()
	{
		for ( float x = -4; x <= 4; x += 0.5 )
		{
			if ( x == 1 )
				continue;

			cout << ( pow( x, 2 ) - 2 * x + 2 ) / ( x - 1 ) << endl;
		}
	}

}
