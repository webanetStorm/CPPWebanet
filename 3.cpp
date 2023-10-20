#include <iostream>
#include <fstream> // библа для работы с файловой системой
#include <string> // класс для работы со строками
#include <math.h>

using namespace std;


namespace WebanetC
{

	void FuncA()
	{
		float s = 1000000, p = 15, n = 20;
		float r = p / 100;

		cout << ( s * r * pow( 1 + r, n ) ) / ( 12 * ( pow( 1 + r, n ) - 1 ) ) << endl; // расчёт по формуле
	}

	void FuncB()
	{
		// mConst - месячный платеж, вычисленный в пред. задании. m - переменная для перебора значения месячного платежа
		float s = 1000000, n = 20, m = 0, mConst = 13313.5, r = 0.0001;
		int p;

		while ( m < mConst ) // Цикл для решения задачи путем перебора искомого значения r
		{
			m = s * r * pow( 1 + r, n ) / ( 12 * ( pow( 1 + r, n ) - 1 ) ); // расчет мес. платежа
			r += 0.0001; // чуть-чуть увеличиваем r
		}

		cout << "p = " << ( p = r * 100 ) << "%" << endl;
	}

	void FuncC() // 3-е и 4-е задания
	{
		/* Начало задания 3 */

		ofstream file( "file.txt" ); // открытие файла file.txt
		file << "CPPWebanetMIREA 1234567890"; // Запись в файл
		file.close(); // Закрытие файла


		string line; // переменная для построчного чтения файла
		ifstream in( "file.txt" ); // Открытие файла

		while ( getline( in, line ) ) // построчное чтение файла
			cout << "Копирование файла: " << line << endl << "Фильтр: "; // вывод каждой строки

		/* Конец задания 3 */


		/* Начало задания 4 */

		string numbers = "0123456789"; // строка, содержащая допустимые символы (в данном случае цифры)

		for ( int i = 0; i < line.size(); i++ ) // проход по символам строки, записанной в файл
			if ( numbers.find( line[i] ) != string::npos ) // если символ есть в numbers, то выводим
			    cout << line[i];

		cout << endl;

		in.close();
		remove( "file.txt" ); // удаление файла

		/* Конец задания 4 */
	}

	bool IsDigit( char c ) // Фцнкция, проверяющая, является ли символ числом
	{
		return isdigit( static_cast<unsigned char>( c ) );
	}

	void FuncD()
	{
		string str = "ЙЦУКЕНГШЩЗХЪФЫВАПРОЛДЖЭЯЧСМИТЬ180819";

		str.erase( remove_if( str.begin(), str.end(), IsDigit ), str.end() ); // Чистим цифры в str
		
		// два цикла для сравнения двух элементов строки
		for ( int i = 0; i < str.length() - 1; i++ )
			for ( int j = i; j < str.length() - 1; j++ )
				if ( str[i] > str[j + 1] ) // меняем местами буквы, если они стоят не по алфавиту
					swap( str[i], str[j + 1] );

		cout << str << endl;
	}

}
