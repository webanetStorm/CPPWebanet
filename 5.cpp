#include <algorithm>
#include <iostream>
#include <fstream>
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

		return DivEuclid( abs( min ), abs( rem ) );
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

	string StrReplace( string search, string replace, string subject )
	{
		size_t start = 0, end = subject.find( search ), length = search.length();

		while ( end != string::npos )
		{
			subject.replace( end, length, replace );
			start = end + length;
			end = subject.find( search, start );
		}

		return subject;
	}

	string Trim( string subject )
	{
		while ( subject[0] == ' ' )
			subject.erase( 0, 1 );

		while ( subject[subject.length() - 1] == ' ' )
			subject.erase( subject.length() - 1, 1 );

		return subject;
	}

	string RemoveExtraSpaces( string subject )
	{
		subject = Trim( subject );
		
		while ( subject.find( "  " ) != string::npos )
			subject = StrReplace( "  ", " ", subject );

		return subject;
	}

	void FuncCA() // �������������� ������������: ������ �������� �� ������(������������) �������. | #1
	{
		cout << StrReplace( " ", "_", "�����-�� ����� � ���������    ....    <>   !  qwerty  " ) << endl;
	}

	void FuncCB() // ��������� ������ �� ������: ������� ������������ ����� ������� | #11
	{
		cout << StrReplace( " ", "|", RemoveExtraSpaces( " ���������    ������ �� ������: �������       ������������ �����   �������       " ) ) << endl;
	}

	void FuncDA() // �������� ���������, ������� ��������� ����� ������������ ��������� ���������� �������. | #47
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

	void FuncDB() // ���� ������ S �� n ��������. ���������� ������������ ����� ������ ������ �������� | #35
	{
		string text = " ����    ������  S ��   n ��������.    ����������      ������������   �����  ������         ������  ��������   ";
		int result = 0, resultTemp = 0;
		
		for ( int i = 0; i <= text.length(); i++ )
		{
			text[i] == ' ' ? resultTemp++ : resultTemp = 0;
			result = Max( result, resultTemp );
		}

		cout << "������������ ����� ������ ������ ��������: " << result << endl;
	}

	void FuncDC() // �������� ���������, ������� ���������� ��� ������������� �� ����������� ������� � ����, ����� ������������� �� �����������, ������. | #43
	{
		vector<int> generalArray = { 1, 4, 5, 9, 16 }, sideArray = { -3, 7, 10, 22 };

		generalArray.insert( generalArray.end(), sideArray.begin(), sideArray.end() );
		sort( generalArray.begin(), generalArray.end() );

		for ( int elem : generalArray )
			cout << elem << ' ';
	}

	vector<string> Explode( string separator, string text )
	{
		vector<string> result;
		size_t start = 0, end = text.find( separator );

		while ( end != string::npos )
		{
			result.push_back( Trim( text.substr( start, end - start ) ) );
			start = end + separator.length();
			end = text.find( separator, start );
		}

		result.push_back( Trim( text.substr( start ) ) );


		return result;
	}

	string Implode( string separator, vector<string> array )
	{
		string result;
		size_t size = array.size();

		for ( int i = 0; i < size; i++ )
			result += i == size - 1 ? array[i] : array[i] + separator;

		return result;
	}

	/* | #2
	 * ������� ����, ���������� �������� � ���������� � ������: ��� ������, ��������, ��� �������. 
	 * ������ ������� � ����������. � ���� �����: ����� �������� �����, ����� � ��� ������� ������� �������� �������; 
	 * ���������� ������� �� �����, � �������� ������� ���� ����� ��++�. ���� ���, �� �������� ������ � ��� �������:
	 */
	void FuncE()
	{
		const string SEPARATOR = "{_}";
		int type;

		cout << "����� ����� ����� � ���������� - ������� 1, ����� �������� ����� - ������� 2: ";
		cin >> type;


		if ( type == 2 )
		{
			char isInput = '+';

			ofstream out( "E5.txt", ios::app );

			while ( isInput == '+' )
			{
				string name, author;
				unsigned int date;

				cout << "[���������� ����� �����]\n������� ��������: ";
				getline( cin >> ws, name );
				cout << "������� ������: ";
				getline( cin >> ws, author );
				cout << "������� ��� �������: ";

				if ( !( cin >> date ) or ( name + author ).find( SEPARATOR ) != string::npos )
				{
					cout << "������� ������������ ������, ��������� ����� ������.\n";

					return;
				}

				out << Implode( SEPARATOR, { name, author, to_string( date ) } ) << endl;

				cout << "�������� ��� ����� (+/-)?: ";
				cin >> isInput;
			}

			out.close();
		}
		else if ( type == 1 )
		{
			ifstream in( "E5.txt" );
			vector<string> result;
			string author, date, line;
			bool found = false;

			cout << "\n[����� �����]\n������� ������: ";
			getline( cin >> ws, author );
			cout << "������� ��� �������: ";
			cin >> date;

			while ( getline( in, line ) )
			{
				vector<string> data = Explode( SEPARATOR, line );

				if ( data[1] == author and data[2] == date )
					result.push_back( data[0] );

				if ( !found and data[0].find( "C++" ) != string::npos )
					found = true;
			}

			cout << "\n���������� ������:\n";
			result.size() == 0 ? cout << "������ �� �������\n" : cout << Implode( ", ", result ) << endl;

			if ( found )
				cout << "\n*� ���������� ���� ����� ��� C++\n";

			in.close();
		}
		else
			cout << "����������� �������\n";
	}

	void FuncED()
	{
		remove( "E5.txt" );
	}

}
