#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include "2.h" // ����� ��� ������������� �. Pi() �� �� #2

using namespace std;


namespace WebanetD
{

	void FuncA()
	{
		float inputNumber, result = 0;
		ofstream file( "D1.txt" );

		// ��������� � ����� � ���� �����
		for ( int i = 1; i <= 10; i++ )
		{
			cout << "����� #" << i << ": ";

			if ( cin >> inputNumber )
			{
				file << inputNumber << endl;
			}
			else
			{
				cout << "�������� �������� �� �������� ������";

				return;
			}
		}

		file.close();



		double digital = 0; // ��� �������� ����� �� �����
		int i = 0; // ������� �������� (����� 10 ����� � �����, �������������� 10 �������� �����)
		ifstream ifile( "D1.txt" );
		while ( i != 10 ) // ������� ����� �� ����� � �� ������������
		{
			ifile >> digital;
			result += digital;
			i += 1;
		}
		ifile.close();
		remove( "D1.txt" );

		cout << "���������: " << result << endl;
	}

	void Sign( float number ) // �., ������������ ���� �����
	{
		cout << "����: ";

		if ( number > 0 )
			cout << "+" << endl;
		else if ( number == 0 )
			cout << "0" << endl;
		else
			cout << "-" << endl;
	}

	void FuncB()
	{
		float number;
		cout << "�����: ";

		if ( cin >> number )
			Sign( number ); // ����� �. Sign()
		else
			cout << "������������ ����" << endl;
	}

	float RectangleArea( float a, float b ) // S ��������������
	{
		return a * b;
	}

	void FuncCA()
	{
		float rectangleA, rectangleB;

		cout << "������� A ��������������: ";
		if ( !( cin >> rectangleA ) or rectangleA <= 0 )
		{
			cout << "������������ ����" << endl;

			return;
		}

		cout << "������� B ��������������: ";
		if ( !( cin >> rectangleB ) or rectangleB <= 0 )
		{
			cout << "������������ ����" << endl;

			return;
		}

		cout << "������� ��������������: " << RectangleArea( rectangleA, rectangleB ) << endl;
	}

	float TriangleArea( float a, float h ) // S ������������ �� ��������� � ������
	{
		return a * h * 0.5;
	}

	void FuncCB()
	{
		float triangleA, triangleH;

		cout << "��������� ������������: ";
		if ( !( cin >> triangleA ) or triangleA <= 0 )
		{
			cout << "������������ ����" << endl;

			return;
		}

		cout << "������ ������������: ";
		if ( !( cin >> triangleH ) or triangleH <= 0 )
		{
			cout << "������������ ����" << endl;

			return;
		}

		cout << "������� ������������: " << TriangleArea( triangleA, triangleH ) << endl;
	}

	float CircleArea( float r ) // S �����
	{
		return WebanetB::Pi() * pow( r, 2 );
	}

	void FuncCC()
	{
		float circleR;

		cout << "������ �����: ";
		if ( !( cin >> circleR ) or circleR <= 0 )
		{
			cout << "������������ ����" << endl;

			return;
		}

		cout << "������� �����: " << CircleArea( circleR ) << endl;
	}

	void FuncD()
	{
		for ( int i = 1; i <= 13; i++ ) // ������
		{
			for ( int j = 1; j <= 35; j++ ) // ������
				// ������ ������ � �������� ������ �������� ����, � ��������� ������ - "-" �� �������� ������� � ������ �� ������
				i <= 6 and j <= 8 ? cout << "*" : i % 2 == 1 ? cout << "-" : cout << " ";

			cout << endl;
		}
	}

	void FuncE()
	{
		const int WIDTH = 60; // ����� �������
		const int HEIGHT = 15; // ������
		char graph[HEIGHT][WIDTH]; // ������ �������� HEIGHTxWIDTH

		for ( int x = 0; x < WIDTH; x++ )
		{
			int y = ( sin( x * 2 * WebanetB::Pi() / WIDTH ) + 1 ) / 2 * HEIGHT; // ����������� ���������� y

			if ( ( y >= 0 ) and ( y < HEIGHT ) ) // ���� y �� ������� �� ����� �������, �� ����� �� ��� ����� � ������� ������
				graph[y][x] = '*';
		}

		for ( int y = 0; y < HEIGHT; y++ )
		{
			// ����� ���� �������� �������
			for ( int x = 0; x < WIDTH; x++ )
				cout << graph[y][x];
			for ( int x = 0; x < WIDTH; x++ )
				cout << graph[y][x];
			cout << endl;
		}
	}

	int Convert( char num ) // ����������� ������� ����� � ���������� �������� ��������
	{
		switch ( num )
		{
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
			default: return 0;
		}
	}

	void FuncF()
	{
		int result = 0;

		char romanNumChars[7] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		map<char, int> nums = {
			{ romanNumChars[0], 1 },
			{ romanNumChars[1], 2 },
			{ romanNumChars[2], 3 },
			{ romanNumChars[3], 4 },
			{ romanNumChars[4], 5 },
			{ romanNumChars[5], 6 },
			{ romanNumChars[6], 7 }
		};

		string input;
		cout << "����: ";
		cin >> input;


		bool flag = false;

		for ( int i = 0; i < input.length(); i++ ) // ������� ���� ���� �������� �����
		{
			if ( flag ) // ���� ���������� �������*, ����� ���������� ��������� ������� ���� � ������� ����� (����., IX, IV, XIX). ���������� ��������, ���� �� ����������� ����� �����
			{
				flag = false;
				continue;
			}

			auto currentNumber = find( romanNumChars, romanNumChars + 7, input[i] );

			if ( currentNumber != end( romanNumChars ) ) // �������� �� ������������� ����� � ������ romanNumChars
			{
				int currentNumberWeight = Convert( input[i] ); // ������� �����
				int nextNumberWeight = Convert( input[i + 1] ); // ��������� �����

				if ( currentNumberWeight < nextNumberWeight ) // ���� ������ ����� ������ �����, �� ������������ ���������� ��� �������� ������� � ������ �����
				{
					result += nextNumberWeight - currentNumberWeight;
					flag = true; // *
				}
				else
					result += currentNumberWeight;
			}
			else
			{
				cout << "������������ ����\n";

				return;
			}

		}

		cout << input << " = " << result << endl;
	}

	int Random( int& s, int m, int b, int c ) // int& s - ������ �� s, ����� �������� s �������� � ������ ����� ������� �. Random()
	{
		return s = ( m * s + b ) % c;
	}

	void FuncG()
	{
		int s = 0;
		int m = 37;
		int b = 3;
		int c = 64;

		cout << "I �������: " << endl;
		for ( int i = 0; i < 10; i++ )
			cout << Random( s, m, b, c ) << endl; // ����� 10 ����� �� I ��������


		s = 0;
		m = 25173;
		b = 13849;
		c = 65537;

		cout << endl << "II �������: " << endl;
		for ( int i = 0; i < 10; i++ )
			cout << Random( s, m, b, c ) << endl; // ����� 10 ����� �� II ��������
	}

	void FuncH()
	{
		float result[4][4] =
		{
			{ 0, 0, 1.e10, 0 },
			{ 0, 0, 1.e10, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		}; // ������, � ������ �������� ����� ������������ ���������� �������� (������ �� ������ �� ��������)

		float A[3][4] =
		{
			{ 5, 2, 0, 10 },
			{ 3, 5, 2, 5 },
			{ 20, 0, 0, 0 }
		}; // ������� A
		float B[4][2] =
		{
			{ 1.20, 0.50 },
			{ 2.80, 0.40 },
			{ 5.00, 1.00 },
			{ 2.00, 1.50 }
		}; // ������� B
		float C[3][2] =
		{
			{ 0, 0 },
			{ 0, 0 },
			{ 0, 0 }
		}; // ������� C

		for ( int i = 0; i < 3; i++ )
			for ( int j = 0; j < 2; j++ )
				for ( int z = 0; z < 4; z++ )
					C[i][j] += A[i][z] * B[z][j]; // ����������� ������� A � B, �������� C

		// ������� ������� C
		for ( int i = 0; i < 3; i++ )
		{
			for ( int j = 0; j < 2; j++ )
			{
				cout << C[i][j] << "  "; // ����� ��������� ������� C

				// ������� �������
				if ( j == 0 )
				{
					if ( C[i][j] > result[0][0] )
					{
						result[0][0] = C[i][j];
						result[0][1] = i + 1;
					}
					else if ( C[i][j] < result[0][2] )
					{
						result[0][2] = C[i][j];
						result[0][3] = i + 1;
					}

					result[2][0] += C[i][j];
				}
				else // ������� ������������
				{
					if ( C[i][j] > result[1][0] )
					{
						result[1][0] = C[i][j];
						result[1][1] = i + 1;
					}
					else if ( C[i][j] < result[1][2] )
					{
						result[1][2] = C[i][j];
						result[1][3] = i + 1;
					}

					result[3][0] += C[i][j];
				}
			}

			cout << endl;
		}

		cout << "\n1) ���������� ������� � " << result[0][1] << "-�� �������� (" << result[0][0] << "), ���������� - � " << result[0][3] << "-�� (" << result[0][2] << ")";
		cout << "\n2) ���������� ������������ � " << result[1][1] << "-�� �������� (" << result[1][0] << "), ���������� - � " << result[1][3] << "-�� (" << result[1][2] << ")";
		cout << "\n3) ����� ������� ���� ���������: " << result[2][0];
		cout << "\n4) ���������� ���������� ������������: " << result[3][0];
		cout << "\n5) �����, ��������� ����� ���� ���������: " << result[2][0] + result[3][0] << endl;
	}

	int ToInt( char num ) // ����������� � ���
	{
		switch ( num )
		{
			case '0': return 0;
			case '1': return 1;
			case '2': return 2;
			case '3': return 3;
			case '4': return 4;
			case '5': return 5;
			case '6': return 6;
			case '7': return 7;
			case '8': return 8;
			case '9': return 9;
			case 'A': return 10;
			case 'B': return 11;
			case 'C': return 12;
			case 'D': return 13;
			case 'E': return 14;
			case 'F': return 15;
			default: return -1;
		}
	}

	string ToChar( int num ) // ����������� �� ����
	{
		switch ( num )
		{
			case 0: return "0";
			case 1: return "1";
			case 2: return "2";
			case 3: return "3";
			case 4: return "4";
			case 5: return "5";
			case 6: return "6";
			case 7: return "7";
			case 8: return "8";
			case 9: return "9";
			case 10: return "A";
			case 11: return "B";
			case 12: return "C";
			case 13: return "D";
			case 14: return "E";
			case 15: return "F";
			default: return "";
		}
	}

	long double ToDecimal( string number, int base ) // ������� � ���������� ������� (long double - ����� ������� �� ������ ��������)
	{
		long double result = 0;

		for ( int i = 0; i < number.size(); i++ ) // ������ �� ������ ����� �����
			result += ToInt( number[i] ) * pow( base, number.size() - i - 1 ); // ������� � ����������

		return result;
	}

	string FromDecimal( int number, int base )
	{
		string result = ToChar( number % base );

		if ( number > 0 )
			return FromDecimal( number / base, base ) + result; // ���������� �������� �. � ����� ����� �� ��������� �.�., ���� ����� ������ ����

		return "";
	}

	void FuncJ()
	{
		string number; // �������� ����� � �����-�� ������� ���������
		int startNumberSystem, endNumberSystem; // ��������� � �������� �.�.

		cout << "������� �����: ";
		cin >> number;
		cout << "��������� �� ��������� �����: ";
		cin >> startNumberSystem;
		cout << "�������������� � �� � ����������: ";
		cin >> endNumberSystem;

		cout << "���������: " << FromDecimal( ToDecimal( number, startNumberSystem ), endNumberSystem ) << endl; // ������� � ����������, ����� � ���������
	}

}
