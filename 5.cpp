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

		cout << "1-е число: ";
		if ( !( cin >> a ) )
		{
			cout << "Некорректный ввод числа";
			return;
		}
		cout << "2-е число: ";
		if ( !( cin >> b ) )
		{
			cout << "Некорректный ввод числа";
			return;
		}

		cout << "\nНОД (делением): " << DivEuclid( abs( a ), abs( b ) ) << endl;
		cout << "НОД (вычитанием): " << SubEuclid( abs( a ), abs( b ) ) << endl;
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
		
		cout << "Ввод: ";
		if ( !( cin >> value ) or value > 9999 or value < 2 )
		{
			cout << "Некорректное значение\n";
			return;
		}

		cout << "Простые числа: ";

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

	void FuncCA() // Преобразование разделителей: замена пробелов на другие(определенные) символы. | #1
	{
		cout << StrReplace( " ", "_", "Какой-то текст с пробелами    ....    <>   !  qwerty  " ) << endl;
	}

	void FuncCB() // Обработка текста по словам: вставка разделителей между словами | #11
	{
		cout << StrReplace( " ", "|", RemoveExtraSpaces( " Обработка    текста по словам: вставка       разделителей между   словами       " ) ) << endl;
	}

	void FuncDA() // Написать программу, которая вычисляет сумму диагональных элементов квадратной матрицы. | #47
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

		cout << "Сумма диагональных элементов: " << result << endl;
	}

	void FuncDB() // Дана строка S из n символов. Подсчитать максимальное число подряд идущих пробелов | #35
	{
		string text = " Дана    строка  S из   n символов.    Подсчитать      максимальное   число  подряд         идущих  пробелов   ";
		int result = 0, resultTemp = 0;
		
		for ( int i = 0; i <= text.length(); i++ )
		{
			text[i] == ' ' ? resultTemp++ : resultTemp = 0;
			result = Max( result, resultTemp );
		}

		cout << "Максимальное число подряд идущих пробелов: " << result << endl;
	}

	void FuncDC() // Написать программу, которая объединяет два упорядоченных по возрастанию массива в один, также упорядоченный по возрастанию, массив. | #43
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
	 * Создать файл, содержащий сведения в библиотеке о книгах: ФИО автора, название, год издания. 
	 * Данные вводить с клавиатуры. В этом файле: найти название книги, автор и год издания которой вводятся вручную; 
	 * определить имеется ли книга, в названии которой есть слово «С++». Если «да», то сообщить автора и год издания:
	 */
	void FuncE()
	{
		const string SEPARATOR = "{_}";
		int type;

		cout << "Чтобы найти книгу в библиотеке - нажмите 1, чтобы добавить новую - нажмите 2: ";
		cin >> type;


		if ( type == 2 )
		{
			char isInput = '+';

			ofstream out( "E5.txt", ios::app );

			while ( isInput == '+' )
			{
				string name, author;
				unsigned int date;

				cout << "[Добавление новой книги]\nВведите название: ";
				getline( cin >> ws, name );
				cout << "Введите автора: ";
				getline( cin >> ws, author );
				cout << "Введите год издания: ";

				if ( !( cin >> date ) or ( name + author ).find( SEPARATOR ) != string::npos )
				{
					cout << "Введены некорректные данные, заполните форму заново.\n";

					return;
				}

				out << Implode( SEPARATOR, { name, author, to_string( date ) } ) << endl;

				cout << "Добавить ещё книгу (+/-)?: ";
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

			cout << "\n[Поиск книги]\nВведите автора: ";
			getline( cin >> ws, author );
			cout << "Введите год издания: ";
			cin >> date;

			while ( getline( in, line ) )
			{
				vector<string> data = Explode( SEPARATOR, line );

				if ( data[1] == author and data[2] == date )
					result.push_back( data[0] );

				if ( !found and data[0].find( "C++" ) != string::npos )
					found = true;
			}

			cout << "\nРезультаты поиска:\n";
			result.size() == 0 ? cout << "Ничего не найдено\n" : cout << Implode( ", ", result ) << endl;

			if ( found )
				cout << "\n*В библиотеке есть книга про C++\n";

			in.close();
		}
		else
			cout << "Неизвестная команда\n";
	}

	void FuncED()
	{
		remove( "E5.txt" );
	}

}
