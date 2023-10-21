#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


namespace WebanetF
{

	vector<vector<int>> Permutations( int count ) // генерация всевозмодных вариков очередности вытаскивания шаров
	{
		vector<vector<int>> result; // все комбинации шаров
		vector<int> balls; // набор номеров шаров


		for ( int i = 1; i <= count; i++ )
			balls.push_back( i ); // создаём массив с номерами шаров вида [ 1, 2, 3, ..., count ]

		do 
			result.push_back( balls ); // вставляем в result следующую комбинацию шаров
		while ( next_permutation( balls.begin(), balls.end() ) ); // перестановка шаров


		return result;
	}

	void Func()
	{
		int result = 0, count;

		cout << "Укажите кол-во шаров: ";
		if ( !( cin >> count ) )
		{
			cout << "\nНекорректный ввод\n";
			return;
		}

		vector<vector<int>> array = Permutations( count ); // массив с комбинациями шаров
		
		for ( int i = 0; i < array.size(); i++ )
		{
			for ( int j = 0; j < array[i].size(); j++ )
			{
				if ( j + 1 == array[i][j] ) // array[i][j] - номер шара, j - порядок вытаскивания шара
				{
					result++;
					break;
				}
			}
		}

		cout << "Ответ: " << result << endl;
	}

}
