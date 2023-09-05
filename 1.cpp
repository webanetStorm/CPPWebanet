#include <iostream>
#include <math.h>

using namespace std;


namespace WebanetA
{

	void FuncA()
	{
		float a, b;

		cout << "Введите 1-ое число: ";
		cin >> a;

		cout << "Введите 2-ое число: ";
		cin >> b;


		cout << "\nСумма: " << a + b << "\nРазность: " << a - b << "\nПроизведение: " << a * b << "\nЧастное: ";

		if ( b != 0 )
			cout << a / b << endl;
		else
			cout << "некорректный делитель\n";
	}

	void FuncB()
	{
		float b, c;

		cout << "Введите 1-ое число: ";
		cin >> b;

		cout << "Введите 2-ое число: ";
		cin >> c;

		if ( b == 0 )
		{
			if ( c == 0 )
				cout << "\nx - любое число\n";
			else
				cout << "\nНет решений\n";
		}
		else
			cout << "\nОтвет: " << -c / b << endl;
	}

	void FuncC()
	{
		float a, b, c;

		cout << "Введите 1-ое число: ";
		cin >> a;

		cout << "Введите 2-ое число: ";
		cin >> b;

		cout << "Введите 3-ое число: ";
		cin >> c;


		float d = pow( b, 2 ) - ( 4 * a * c );

		if ( d < 0 )
			cout << "\nНет корней\n";
		else if ( d == 0 )
			cout << "\nОтвет: " << -b / ( 2 * a ) << endl;
		else
			cout << "\nОтвет: " << ( sqrt( d ) - b ) / ( 2 * a ) << ", " << ( -b - sqrt(d) ) / ( 2 * a ) << endl;
	}

	void FuncD()
	{
		bool isDay = true;
		bool isOpen = false;
		bool lampOn = false;

		if ( lampOn or ( isDay and isOpen ) )
			cout << "Светло\n";
		else
			cout << "Темно\n";
	}

}
