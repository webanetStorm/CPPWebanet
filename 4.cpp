#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include "2.h"

using namespace std;


namespace WebanetD
{

	void FuncA()
	{
		float inputNumber, result = 0;
		ofstream file( "D1.txt" );

		for ( int i = 1; i <= 10; i++ )
		{
			cout << "Число #" << i << ": ";

			if ( cin >> inputNumber )
			{
				file << inputNumber << endl;
			}
			else
			{
				cout << "Введённое значение не является числом";

				return;
			}
		}

		file.close();



		ifstream in( "D1.txt" );
		string line;

		while ( std::getline( in, line ) )
			result += std::stoi( line );

		in.close();

		cout << "Результат: " << result << endl;
	}

	void Sign( float number )
	{
		cout << "Знак: ";

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
		cout << "Число: ";

		if ( cin >> number )
			Sign( number );
		else
			cout << "Некорректынй ввод" << endl;
	}

	float RectangleArea( float a, float b )
	{
		return a * b;
	}

	void FuncCA()
	{
		float rectangleA, rectangleB;

		cout << "Сторона A прямоугольника: ";
		if ( !( cin >> rectangleA ) or rectangleA <= 0 )
		{
			cout << "Некорректный ввод" << endl;

			return;
		}

		cout << "Сторона B прямоугольника: ";
		if ( !( cin >> rectangleB ) or rectangleB <= 0 )
		{
			cout << "Некорректный ввод" << endl;

			return;
		}

		cout << "Площадь прямоугольника: " << RectangleArea( rectangleA, rectangleB ) << endl;
	}

	float TriangleArea( float a, float h )
	{
		return a * h * 0.5;
	}

	void FuncCB()
	{
		float triangleA, triangleH;

		cout << "Основание треугольника: ";
		if ( !( cin >> triangleA ) or triangleA <= 0 )
		{
			cout << "Некорректный ввод" << endl;

			return;
		}

		cout << "Высота треугольника: ";
		if ( !( cin >> triangleH ) or triangleH <= 0 )
		{
			cout << "Некорректный ввод" << endl;

			return;
		}

		cout << "Площадь треугольника: " << TriangleArea( triangleA, triangleH ) << endl;
	}

	float CircleArea( float r )
	{
		return WebanetB::Pi() * pow( r, 2 );
	}

	void FuncCC()
	{
		float circleR;

		cout << "Радиус круга: ";
		if ( !( cin >> circleR ) or circleR <= 0 )
		{
			cout << "Некорректный ввод" << endl;

			return;
		}

		cout << "Площадь круга: " << CircleArea( circleR ) << endl;
	}

	void FuncD()
	{
		for ( int i = 1; i <= 13; i++ )
		{
			for ( int j = 1; j <= 35; j++ )
				i <= 6 and j <= 8 ? cout << "*" : i % 2 == 1 ? cout << "-" : cout << " ";
			cout << endl;
		}
	}

	void FuncE() // TODO: переделать
	{
		int size = 100;
		int height = 21;

		vector<string> sinGraph( height, string( size, ' ' ) );
		sinGraph[height / 2] = string( size, '-' );

		for ( int i = 0; i < size; i++ )
			sinGraph[( round( 10 * sin( i / 4.5 ) + 10 ) )][i] = '*';

		for ( auto s : sinGraph )
			cout << s << endl;
	}

	int convert( char num )
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
		cout << "Ввод: ";
		cin >> input;

		int length = input.length();

		for ( int i = 0; i < length; i++ )
		{
			auto currentNumber = find( romanNumChars, romanNumChars + 7, input[i] );

			if ( currentNumber != end( romanNumChars ) )
			{
				int currentNumberWeight = convert( input[i] );

				if ( i == length - 2 )
				{
					int nextNumberWeight = convert( input[i + 1] );

					if ( currentNumberWeight < nextNumberWeight )
					{
						result += nextNumberWeight - currentNumberWeight;
						break;
					}
					else
						result += currentNumberWeight;
				}
				else
					result += currentNumberWeight;
			}
			else
			{
				cout << "Некорректный ввод\n";

				return;
			}

		}

		cout << input << " = " << result << endl;
	}

	int Random( int& s, int m, int b, int c )
	{
		return s = ( m * s + b ) % c;
	}

	void FuncG()
	{
		int s = 0;
		int m = 37;
		int b = 3;
		int c = 64;

		cout << "I вариант: " << endl;
		for ( int i = 0; i < 10; i++ )
			cout << Random( s, m, b, c ) << endl;


		s = 0;
		m = 25173;
		b = 13849;
		c = 65537;

		cout << endl << "II вариант: " << endl;
		for ( int i = 0; i < 10; i++ )
			cout << Random( s, m, b, c ) << endl;
	}

	void FuncH()
	{
		float result[4][4] =
		{
			{ 0, 0, 1.e10, 0 },
			{ 0, 0, 1.e10, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		};

		float A[3][4] =
		{
			{ 5, 2, 0, 10 },
			{ 3, 5, 2, 5 },
			{ 20, 0, 0, 0 }
		};
		float B[4][2] =
		{
			{ 1.20, 0.50 },
			{ 2.80, 0.40 },
			{ 5.00, 1.00 },
			{ 2.00, 1.50 }
		};
		float C[3][2] =
		{
			{ 0, 0 },
			{ 0, 0 },
			{ 0, 0 }
		};

		for ( int i = 0; i < 3; i++ )
			for ( int j = 0; j < 2; j++ )
				for ( int z = 0; z < 4; z++ )
					C[i][j] += A[i][z] * B[z][j];

		for ( int i = 0; i < 3; i++ )
		{
			for ( int j = 0; j < 2; j++ )
			{
				cout << C[i][j] << "  ";

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
				else
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

		cout << "\n1) Наибольшая выручка у " << result[0][1] << "-го продавца (" << result[0][0] << "), наименьшая - у " << result[0][3] << "-го (" << result[0][2] << ")";
		cout << "\n2) Наибольшие комиссионные у " << result[1][1] << "-го продавца (" << result[1][0] << "), наименьшие - у " << result[1][3] << "-го (" << result[1][2] << ")";
		cout << "\n3) Общая выручка всех продавцов: " << result[2][0];
		cout << "\n4) Полученные продавцами комиссионные: " << result[3][0];
		cout << "\n5) Сумма, прошедшая через руки продавцов: " << result[2][0] + result[3][0] << endl;
	}

}
