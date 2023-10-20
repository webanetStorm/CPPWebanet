#include <iostream>
#include <fstream> // ����� ��� ������ � �������� ��������
#include <string> // ����� ��� ������ �� ��������
#include <math.h>

using namespace std;


namespace WebanetC
{

	void FuncA()
	{
		float s = 1000000, p = 15, n = 20;
		float r = p / 100;

		cout << ( s * r * pow( 1 + r, n ) ) / ( 12 * ( pow( 1 + r, n ) - 1 ) ) << endl; // ������ �� �������
	}

	void FuncB()
	{
		// mConst - �������� ������, ����������� � ����. �������. m - ���������� ��� �������� �������� ��������� �������
		float s = 1000000, n = 20, m = 0, mConst = 13313.5, r = 0.0001;
		int p;

		while ( m < mConst ) // ���� ��� ������� ������ ����� �������� �������� �������� r
		{
			m = s * r * pow( 1 + r, n ) / ( 12 * ( pow( 1 + r, n ) - 1 ) ); // ������ ���. �������
			r += 0.0001; // ����-���� ����������� r
		}

		cout << "p = " << ( p = r * 100 ) << "%" << endl;
	}

	void FuncC() // 3-� � 4-� �������
	{
		/* ������ ������� 3 */

		ofstream file( "file.txt" ); // �������� ����� file.txt
		file << "CPPWebanetMIREA 1234567890"; // ������ � ����
		file.close(); // �������� �����


		string line; // ���������� ��� ����������� ������ �����
		ifstream in( "file.txt" ); // �������� �����

		while ( getline( in, line ) ) // ���������� ������ �����
			cout << "����������� �����: " << line << endl << "������: "; // ����� ������ ������

		/* ����� ������� 3 */


		/* ������ ������� 4 */

		string numbers = "0123456789"; // ������, ���������� ���������� ������� (� ������ ������ �����)

		for ( int i = 0; i < line.size(); i++ ) // ������ �� �������� ������, ���������� � ����
			if ( numbers.find( line[i] ) != string::npos ) // ���� ������ ���� � numbers, �� �������
			    cout << line[i];

		cout << endl;

		in.close();
		remove( "file.txt" ); // �������� �����

		/* ����� ������� 4 */
	}

	bool IsDigit( char c ) // �������, �����������, �������� �� ������ ������
	{
		return isdigit( static_cast<unsigned char>( c ) );
	}

	void FuncD()
	{
		string str = "������������������������������180819";

		str.erase( remove_if( str.begin(), str.end(), IsDigit ), str.end() ); // ������ ����� � str
		
		// ��� ����� ��� ��������� ���� ��������� ������
		for ( int i = 0; i < str.length() - 1; i++ )
			for ( int j = i; j < str.length() - 1; j++ )
				if ( str[i] > str[j + 1] ) // ������ ������� �����, ���� ��� ����� �� �� ��������
					swap( str[i], str[j + 1] );

		cout << str << endl;
	}

}
