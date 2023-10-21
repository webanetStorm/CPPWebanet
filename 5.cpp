#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;


namespace WebanetE
{	

	float Max( float a, float b ) // выбор наибольшего числа из двух
	{
		return a > b ? a : b;
	}

	float Min( float a, float b ) // выбор наименьшего числа из двух
	{
		return a < b ? a : b;
	}

	float DivEuclid( float a, float b ) // поиск НОД делением
	{
		float rem, min;

		if ( ( rem = fmod( Max( a, b ), ( min = Min( a, b ) ) ) ) == 0 )
			return min;

		return DivEuclid( abs( min ), abs( rem ) );
	}

	float SubEuclid( float a, float b ) // поиск НОД вычитанием
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

	bool IsPrime( int value ) // ф., проверяющая, является число простым
	{
		for ( int d = 2; d <= sqrt( value ); d++ ) // перебор от двух до корня
			if ( value % d == 0 ) // если найден хоть один делитель, то сразу ретурн фолс
				return false;

		return true;
	}

	void FuncB()
	{
		unsigned int value; // неотрицательный инт
		
		cout << "Ввод: ";
		if ( !( cin >> value ) or value > 9999 or value < 2 )
		{
			cout << "Некорректное значение\n";
			return;
		}

		cout << "Простые числа: ";

		for ( int i = 2; i <= value; i++ ) // вывод простых чисел от 2 до заданного
			if ( IsPrime( i ) )
				cout << i << " ";
	}

	string StrReplace( string search, string replace, string subject ) // ф., заменяющая подстроку в строке на другую подстроку
	{
		// start - точка отсчета, end - поиск ближайшей заменяемой подстроки, length - длина заменяемой подстроки
		size_t start = 0, end = subject.find( search ), length = search.length();

		while ( end != string::npos ) // пока в строке находится заменяемая подстрока
		{
			subject.replace( end, length, replace ); // меняем search на replace
			start = end + length; // перемещаем точку отсчета на length символов вправо от только что найденной search
			end = subject.find( search, start ); // ищем следующую подстроку для замены
		}

		return subject;
	}

	string Trim( string subject ) // обрезает пробелы по краяем
	{
		while ( subject[0] == ' ' ) // пока в начале есть пробелы
			subject.erase( 0, 1 ); // обрезаем с начала один символ

		while ( subject[subject.length() - 1] == ' ' ) // пока в конце есть пробелы
			subject.erase( subject.length() - 1, 1 ); // обрезаем один символ с конца

		return subject;
	}

	string RemoveExtraSpaces( string subject ) // удаление дублирующихся пробелов
	{
		subject = Trim( subject ); // обрезаем пробелы по краям
		
		while ( subject.find( "  " ) != string::npos ) // пока в строке найдено два идущих подряд пробела
			subject = StrReplace( "  ", " ", subject ); // заменяем два пробела на один

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
		const int SIZE = 5; // порядок матрицы
		float result = 0; // результирующая сумма
		float matrix[SIZE][SIZE] = {
			{ 1, 2, 3, 1, 1 },
			{ 4, 1, 2, 1, 4 },
			{ 1, 1, 1, 5, 2 },
			{ 8, 1, 0, 1, 7 },
			{ 1, 5, 2, 1, 1 }
		}; // матрица

		for ( int i = 0; i < SIZE; i++ )
			result += matrix[i][i]; // сумма элементов на главной диагонали

		for ( int i = 0; i < SIZE; i++ )
			if ( SIZE % 2 == 0 or ( SIZE % 2 == 1 and i != SIZE - i - 1 ) ) // если порядок матрицы нечетный, то исключаем двойное суммирование центрального элемента
				result += matrix[i][SIZE - i - 1]; // сумма элементов на побочной диагонали

		cout << "Сумма диагональных элементов: " << result << endl;
	}

	void FuncDB() // Дана строка S из n символов. Подсчитать максимальное число подряд идущих пробелов | #35
	{
		string text = " Дана    строка  S из   n символов.    Подсчитать      максимальное   число  подряд         идущих  пробелов   ";
		int result = 0, resultTemp = 0; // результ и временнный результ
		
		for ( int i = 0; i <= text.length(); i++ ) // перебор символов строки
		{
			text[i] == ' ' ? resultTemp++ : resultTemp = 0; // считаем длину текущего пробела
			result = Max( result, resultTemp ); // обновляем макс. значение result
		}

		cout << "Максимальное число подряд идущих пробелов: " << result << endl;
	}

	vector<string> Explode( string separator, string text ) // преобразование строки в массив через разделитель
	{
		vector<string> result;
		size_t start = 0, end = text.find( separator ); // start - т. отсчета, end - ближайший разделитель

		while ( end != string::npos ) // пока находится разделитель
		{
			result.push_back( Trim( text.substr( start, end - start ) ) ); // добавляем в result вырезанный элемент строки от start до след. разделителя
			start = end + separator.length(); // передвигаем точку отсчета
			end = text.find( separator, start ); // ищем след. разделитель
		}

		result.push_back( Trim( text.substr( start ) ) ); // добавляем в result последний элемент (стоящий после последнего найденного разделителя)


		return result;
	}

	string Implode( string separator, vector<string> array ) // преобразование массива в строку через разделитель
	{
		string result; // итоговая строка
		size_t size = array.size(); // кол-во элементов в массиве

		for ( int i = 0; i < size; i++ )
			result += i == size - 1 ? array[i] : array[i] + separator; // конкатенируем элементы массива через разделитель (последний элемент конкатенируется без него)

		return result;
	}

	/* | #2
	 * Создать файл, содержащий сведения в библиотеке о книгах: ФИО автора, название, год издания. 
	 * Данные вводить с клавиатуры. В этом файле: найти название книги, автор и год издания которой вводятся вручную; 
	 * определить имеется ли книга, в названии которой есть слово «С++». Если «да», то сообщить автора и год издания:
	 */
	void FuncE()
	{
		const string SEPARATOR = "{_}"; // разделитель, через который будут вписываться в файл название книги, автор и год издания
		int type;

		cout << "Чтобы найти книгу в библиотеке - нажмите 1, чтобы добавить новую - нажмите 2: ";
		cin >> type;


		if ( type == 2 )
		{
			char isInput = '+';

			ofstream out( "E5.txt", ios::app ); // ios::app - чтобы файл не сбрасывался каждый раз, а накапливал книги

			while ( isInput == '+' )
			{
				string name, author;
				unsigned int date;

				cout << "[Добавление новой книги]\nВведите название: ";
				getline( cin >> ws, name ); // Ввод текста через пробел
				cout << "Введите автора: ";
				getline( cin >> ws, author );
				cout << "Введите год издания: ";

				if ( !( cin >> date ) or ( name + author ).find( SEPARATOR ) != string::npos )
				{
					cout << "Введены некорректные данные, заполните форму заново.\n";

					return;
				}

				out << Implode( SEPARATOR, { name, author, to_string( date ) } ) << endl; // Конвертация {название_книги, автор, гдо_издания} в строку через разделитель "{_}"

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
			bool found = false; // найдена ли книга про C++

			cout << "\n[Поиск книги]\nВведите автора: ";
			getline( cin >> ws, author );
			cout << "Введите год издания: ";
			cin >> date;

			while ( getline( in, line ) ) // перебор всех книг из файла
			{
				vector<string> data = Explode( SEPARATOR, line ); // конвератция строки вида "название_книги{_}автор{_}год" в массив

				if ( data[1] == author and data[2] == date ) // если совпал автор и год
					result.push_back( data[0] ); // то добавляем название книги в result

				if ( !found and data[0].find( "C++" ) != string::npos ) // если в название есть подстрока "C++"
					found = true; // то ставим флаг в true
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

	void FuncED() // зачистка библиотеки
	{
		remove( "E5.txt" );
	}

}
