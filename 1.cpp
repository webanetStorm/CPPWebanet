#include <iostream>
#include <math.h>

using namespace std;


namespace WebanetA
{

	void FuncA()
	{
		float a, b;

		cout << "������� 1-�� �����: ";
		cin >> a;

		cout << "������� 2-�� �����: ";
		cin >> b;


		cout << "\n�����: " << a + b << "\n��������: " << a - b << "\n������������: " << a * b << "\n�������: ";

		if ( b != 0 )
			cout << a / b << endl;
		else
			cout << "������������ ��������\n";
	}

	void FuncB()
	{
		float b, c;

		cout << "������� 1-�� �����: ";
		cin >> b;

		cout << "������� 2-�� �����: ";
		cin >> c;

		if ( b == 0 )
		{
			if ( c == 0 )
				cout << "\nx - ����� �����\n";
			else
				cout << "\n��� �������\n";
		}
		else
			cout << "\n�����: " << -c / b << endl;
	}

	void FuncC()
	{
		float a, b, c;

		cout << "������� 1-�� �����: ";
		cin >> a;

		cout << "������� 2-�� �����: ";
		cin >> b;

		cout << "������� 3-�� �����: ";
		cin >> c;


		float d = pow( b, 2 ) - ( 4 * a * c );

		if ( d < 0 )
			cout << "\n��� ������\n";
		else if ( d == 0 )
			cout << "\n�����: " << -b / ( 2 * a ) << endl;
		else
			cout << "\n�����: " << ( sqrt( d ) - b ) / ( 2 * a ) << ", " << ( -b - sqrt(d) ) / ( 2 * a ) << endl;
	}

	void FuncD()
	{
		bool isDay = true;
		bool isOpen = false;
		bool lampOn = false;

		if ( lampOn or ( isDay and isOpen ) )
			cout << "������\n";
		else
			cout << "�����\n";
	}

}
