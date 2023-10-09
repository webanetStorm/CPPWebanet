#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


namespace WebanetE
{	

	float Max( float a, float b )
	{
		return a > b ? a : b;
	}

	float Min( float a, float b )
	{
		return a < b ? a : b;
	}

	float DivEuclid( float a, float b )
	{
		float rem, min;

		if ( ( rem = fmod( Max( a, b ), ( min = Min( a, b ) ) ) ) == 0 )
			return min;

		return DivEuclid( abs( min ), abs ( rem ) );
	}

	float SubEuclid( float a, float b )
	{
		float rem, min;

		if ( ( rem = Max( a, b ) - ( min = Min( a, b ) ) ) == 0 )
			return min;

		return SubEuclid( abs( min ), abs( rem ) );
	}

	void FuncA()
	{
		float a, b;

		cout << "1-� �����: ";
		if ( !( cin >> a ) )
		{
			cout << "������������ ���� �����";
			return;
		}
		cout << "2-� �����: ";
		if ( !( cin >> b ) )
		{
			cout << "������������ ���� �����";
			return;
		}

		cout << "\n��� (��������): " << DivEuclid( abs( a ), abs( b ) ) << endl;
		cout << "��� (����������): " << SubEuclid( abs( a ), abs( b ) ) << endl;
	}

	bool IsPrime( int value )
	{
		for ( int d = 2; d <= sqrt( value ); d++ )
			if ( value % d == 0 )
				return false;

		return true;
	}

	void FuncB()
	{
		unsigned int value;
		
		cout << "����: ";
		if ( !( cin >> value ) or value > 9999 or value < 2 )
		{
			cout << "������������ ��������\n";
			return;
		}

		cout << "������� �����: ";

		for ( int i = 2; i <= value; i++ )
			if ( IsPrime( i ) )
				cout << i << " ";
	}

	void FuncCA() // �������������� ������������: ������ �������� �� ������(������������) �������.
	{
		string text = "�����-�� ����� � ���������";
		
		for ( int i = 0; text[i]; i++ )
			if ( text[i] == ' ' )
				text[i] = '_';

		cout << text << endl;
	}

	void FuncCB() // ��������� ������ �� ������: ������� ������������ ����� �������
	{
		string text = "��������� ������ �� ������: ������� ������������ ����� �������";

		for ( int i = 0; i < text.length(); i++ )
			if ( text[i] == ' ' )
				text.replace( i, 1, "|" );
		
		cout << text << endl;
	}

	void FuncDA() // �������� ���������, ������� ��������� ����� ������������ ��������� ���������� �������.
	{
		const int SIZE = 5;
		float result = 0;
		float matrix[SIZE][SIZE] = {
			{ 1, 2, 3, 1, 1 },
			{ 4, 1, 2, 1, 4 },
			{ 1, 1, 1, 5, 2 },
			{ 8, 1, 0, 1, 7 },
			{ 1, 5, 2, 1, 1 }
		};

		for ( int i = 0; i < SIZE; i++ )
			result += matrix[i][i];

		for ( int i = 0; i < SIZE; i++ )
			if ( SIZE % 2 == 0 or ( SIZE % 2 == 1 and i != SIZE - i - 1 ) )
				result += matrix[i][SIZE - i - 1];

		cout << "����� ������������ ���������: " << result << endl;
	}

	void FuncDB() // ���� ������ S �� n ��������. ���������� ������������ ����� ������ ������ ��������
	{
		// ...
	}

}
