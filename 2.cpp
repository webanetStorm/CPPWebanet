#include <iostream>
#include <math.h>

using namespace std;


namespace WebanetB
{

	float Pi() // ���⮬��� �㭪��, ��������� �᫮ ��
	{
		return 3.1415926535;
	}

	void FuncA()
	{
		float r1, r2, h;

		cout << "������ �᭮����� �����: ";
		cin >> r1;

		cout << "������ ���� �����: ";
		cin >> r2;

		cout << "����� �����: ";
		cin >> h;


		float l = sqrt( pow( h, 2 ) + pow( r1 - r2, 2 ) );

		cout << "����: " << 1.0 / 3.0 * Pi() * h * ( pow( r1, 2 ) + r1 * r2 + pow( r2, 2 ) ); // pow() - �㭪. ���������� � �⥯���
		cout << "\n���頤� �����孮��: " << Pi() * ( pow( r1, 2 ) + ( r1 + r2 ) * l + pow( r2, 2 ) ) << endl;
	}

	void FuncB()
	{
		float a, x;

		cout << "��᫮ A: ";
		cin >> a;

		cout << "��᫮ X: ";
		cin >> x;

		cout << endl;


		abs( x ) < 1 // abs() - ����� �᫠
			? x != 0 ? cout << "w = " << a * log( x ) << endl : cout << "�����४⭮� ���祭�� ��� X\n" // log() - ����ࠫ�� ������
			: a - pow( x, 2 ) >= 0 ? cout << "w = " << sqrt( a - pow( x, 2 ) ) << endl : cout << "�����४�� ���祭�� ��६�����\n";
	}

	void FuncC()
	{
		float x, y, b;

		cout << "��᫮ X: ";
		cin >> x;

		cout << "��᫮ Y: ";
		cin >> y;

		cout << "��᫮ B: ";
		cin >> b;

		cout << endl;


	    b >= x and b - y > 0 ? cout << log( b - y ) * sqrt( b - x ) << endl : cout << "�����४�� ���祭��\n";
	}

	void FuncD()
	{
		int n; // ��६����� ⨯� int 

		cout << "��᫮ N: ";
		cin >> n;

		if ( n >= 1 )
			for ( int i = n; i < n + 10; i++ ) // 横� � ������� ���-��� ���権
				cout << i << endl;
		else
			cout << "N ������ ���� ����ࠫ�� �᫮�\n";
	}

	void FuncE()
	{
		for ( float x = -4; x <= 4; x += 0.5 )
		{
			if ( x == 1 ) // �ய�� x=1 �� ��������� ������� �� 0
			{
				cout << "�訡��\n";
				continue; // ���室 �� ᫥������ ����� 横��
			}

			cout << ( pow( x, 2 ) - 2 * x + 2 ) / ( x - 1 ) << endl;
		}
	}

}
