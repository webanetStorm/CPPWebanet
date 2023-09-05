#include <iostream>
#include <math.h>

using namespace std;


void FuncA()
{
	int a, b;
	cin >> a >> b;

	cout << a + b << endl;
	cout << a - b << endl;
	cout << a * b << endl;

	if ( a % b == 0 )
		cout << a / b;
	else
		cout << "Не делится нацело";
}

void FuncB()
{
	int b, c;
	cin >> b >> c;

	if ( c % b == 0 and b != 0 )
		cout << -c / b;
	else
		cout << "Нет решений";
}

void FuncC()
{
	float a, b, c;
	cin >> a >> b >> c;

	float d;
	d = pow( b, 2 ) - ( 4 * a * c );

	if ( d < 0 )
		cout << "Нет корней";
	else if ( d == 0 )
		cout << -b / ( 2 * a );
	else
		cout << ( sqrt( d ) - b ) / ( 2 * a ) << endl << ( -b - sqrt( d ) ) / ( 2 * a );
}

void FuncD()
{
	bool isDay = false;
	bool isOpen = true;
	bool lampOn = false;

	if ( lampOn or ( isDay and isOpen ) )
		cout << "Светло";
	else
		cout << "Темно";

}

void FuncE()
{
	int R = 5;
	int r = 3;
	int h = 8;
	int l = 4;
	float v = 0.33333 * 3.14 * h * ( pow( R, 2 ) + R * r + pow( r, 2 ) );
	float s = 3.14 * ( pow( R, 2 ) + ( R + r ) * l + pow( r, 2 ) );

	cout << v << endl << s;
}

void FuncF()
{
	// хз хз
}

void FuncG()
{
	int x = 3;
	int y = 5;
	int b = 11;

	if ( b > x and b - y > 0 )
		cout << log( b - y ) * sqrt( b - x );
	else
		cout << ":(";
}

void FuncH()
{
	int n = 0;

	if ( n >= 1 )
	{
		for ( int i = n; i < n + 10; i++ )
			cout << i << endl;
	}
	else
		cout << "N должно быть натуральным числом";
}

void FuncJ()
{
	for ( float x = -4; x <= 4; x += 0.5 )
	{
		if ( x == 1 )
			continue;

		cout << ( pow( x, 2 ) - 2 * x + 2 ) / ( x - 1 ) << endl;
	}
}

int main()
{

	setlocale( LC_ALL, "Russian" );

	FuncA();
	// FuncB();
	// FuncC();
	// FuncD();
	// FuncE();
	// FuncF();
	// FuncG();
	// FuncH();
	// FuncJ();

	return 0;

}
