#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include "2.h" // нужно для использования ф. Pi() из ДЗ #2

using namespace std;


namespace WebanetD
{

	void FuncA()
	{
		float inputNumber, result = 0;
		ofstream file( "D1.txt" );

		// Считываем и пишем в файл числа
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



		double digital = 0; // для хранения числа из файла
		int i = 0; // Счетчик итераций (всего 10 чисел в файле, соотвественноЮ 10 итераций вайла)
		ifstream ifile( "D1.txt" );
		while ( i != 10 ) // Перебор чисел из файла и их суммирование
		{
			ifile >> digital;
			result += digital;
			i += 1;
		}
		ifile.close();
		remove( "D1.txt" );

		cout << "Результат: " << result << endl;
	}

	void Sign( float number ) // Ф., определяющая знак числа
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
			Sign( number ); // Вызов ф. Sign()
		else
			cout << "Некорректынй ввод" << endl;
	}

	float RectangleArea( float a, float b ) // S прямоугольника
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

	float TriangleArea( float a, float h ) // S треугольника по основанию и высоте
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

	float CircleArea( float r ) // S круга
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
		for ( int i = 1; i <= 13; i++ ) // строки
		{
			for ( int j = 1; j <= 35; j++ ) // стобцы
				// рисуем звезды в пределах левого верхнего угла, в остальных местах - "-" на нечетных строках и пробел на четных
				i <= 6 and j <= 8 ? cout << "*" : i % 2 == 1 ? cout << "-" : cout << " ";

			cout << endl;
		}
	}

	void FuncE()
	{
		const int WIDTH = 60; // длина графика
		const int HEIGHT = 15; // высота
		char graph[HEIGHT][WIDTH]; // массив размером HEIGHTxWIDTH

		for ( int x = 0; x < WIDTH; x++ )
		{
			int y = ( sin( x * 2 * WebanetB::Pi() / WIDTH ) + 1 ) / 2 * HEIGHT; // высчитываем координату y

			if ( ( y >= 0 ) and ( y < HEIGHT ) ) // если y не выходит за рамки массива, то кладём на это место в массиве звезду
				graph[y][x] = '*';
		}

		for ( int y = 0; y < HEIGHT; y++ )
		{
			// вывод двух периодов графика
			for ( int x = 0; x < WIDTH; x++ )
				cout << graph[y][x];
			for ( int x = 0; x < WIDTH; x++ )
				cout << graph[y][x];
			cout << endl;
		}
	}

	int Convert( char num ) // Концертация римской цифры в нормальное числовое значение
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


		bool flag = false;

		for ( int i = 0; i < input.length(); i++ ) // Перебор всех цифр римского числа
		{
			if ( flag ) // флаг становится трушным*, когда нарушается убывающий порядок цифр в римском числе (напр., IX, IV, XIX). Пропускаем итерацию, дабы не суммировать левую цифру
			{
				flag = false;
				continue;
			}

			auto currentNumber = find( romanNumChars, romanNumChars + 7, input[i] );

			if ( currentNumber != end( romanNumChars ) ) // Проверка на существование цифры в наборе romanNumChars
			{
				int currentNumberWeight = Convert( input[i] ); // Текущая цифра
				int nextNumberWeight = Convert( input[i + 1] ); // Следующая цифра

				if ( currentNumberWeight < nextNumberWeight ) // Если правая цифра больше левой, то суммирование происходит как разность правого и левого чисел
				{
					result += nextNumberWeight - currentNumberWeight;
					flag = true; // *
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

	int Random( int& s, int m, int b, int c ) // int& s - ссылка на s, чтобы значение s менялось с каждым новым вызовом ф. Random()
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
			cout << Random( s, m, b, c ) << endl; // Вывод 10 чисел по I варианту


		s = 0;
		m = 25173;
		b = 13849;
		c = 65537;

		cout << endl << "II вариант: " << endl;
		for ( int i = 0; i < 10; i++ )
			cout << Random( s, m, b, c ) << endl; // Вывод 10 чисел по II варианту
	}

	void FuncH()
	{
		float result[4][4] =
		{
			{ 0, 0, 1.e10, 0 },
			{ 0, 0, 1.e10, 0 },
			{ 0, 0, 0, 0 },
			{ 0, 0, 0, 0 }
		}; // массив, в ячейки которого будут записываться полученные значения (ответы на каждый из вопросов)

		float A[3][4] =
		{
			{ 5, 2, 0, 10 },
			{ 3, 5, 2, 5 },
			{ 20, 0, 0, 0 }
		}; // матрица A
		float B[4][2] =
		{
			{ 1.20, 0.50 },
			{ 2.80, 0.40 },
			{ 5.00, 1.00 },
			{ 2.00, 1.50 }
		}; // матрица B
		float C[3][2] =
		{
			{ 0, 0 },
			{ 0, 0 },
			{ 0, 0 }
		}; // матрица C

		for ( int i = 0; i < 3; i++ )
			for ( int j = 0; j < 2; j++ )
				for ( int z = 0; z < 4; z++ )
					C[i][j] += A[i][z] * B[z][j]; // Перемножаем матрицы A и B, получаем C

		// Перебор матрицы C
		for ( int i = 0; i < 3; i++ )
		{
			for ( int j = 0; j < 2; j++ )
			{
				cout << C[i][j] << "  "; // Вывод элементов матрицы C

				// подсчет выручки
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
				else // подсчет комиссионных
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

	int ToInt( char num ) // Конвертация в инт
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

	string ToChar( int num ) // концертация из инта
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

	long double ToDecimal( string number, int base ) // перевод в десятичную систему (long double - чтобы хватало на больше значения)
	{
		long double result = 0;

		for ( int i = 0; i < number.size(); i++ ) // проход по каждой цифре числа
			result += ToInt( number[i] ) * pow( base, number.size() - i - 1 ); // перевод в десятичную

		return result;
	}

	string FromDecimal( int number, int base )
	{
		string result = ToChar( number % base );

		if ( number > 0 )
			return FromDecimal( number / base, base ) + result; // рекурсивно вызываем ф. и делим число на основание с.с., пока число больше нуля

		return "";
	}

	void FuncJ()
	{
		string number; // вводимое число в какой-то системе счисления
		int startNumberSystem, endNumberSystem; // начальная и конечная с.с.

		cout << "Введите число: ";
		cin >> number;
		cout << "Основание СС введённого числа: ";
		cin >> startNumberSystem;
		cout << "Конвертировать в СС с основанием: ";
		cin >> endNumberSystem;

		cout << "Результат: " << FromDecimal( ToDecimal( number, startNumberSystem ), endNumberSystem ) << endl; // перевод в десятичную, потом в требуемую
	}

}
