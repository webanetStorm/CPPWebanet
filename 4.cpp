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
		}

		return 0;
	}

	void FuncF()
	{
		char numChars[] = { 'I', 'V', 'X', 'L', 'C', 'D', 'M' };
		map<char, int> nums = {
			{ numChars[0], 1},
			{ numChars[1], 2 },
			{ numChars[2], 3 },
			{ numChars[3], 4 },
			{ numChars[4], 5 },
			{ numChars[5], 6 },
			{ numChars[6], 7 }
		};

		string inputNumber;
		cout << "Число: ";
		cin >> inputNumber;


	}

}
