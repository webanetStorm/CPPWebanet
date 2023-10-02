#include <iostream>
#include <sstream>
#include <string>

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

	void FuncCA()
	{
		// ...
	}

	void FuncCB()
	{
		// ...
	}

}
