#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>
#include "5.h"

using namespace std;


namespace WebanetF
{

	vector<vector<int>> Permutations( int count )
	{
		vector<vector<int>> result;
		vector<int> balls;


		for ( int i = 1; i <= count; i++ )
			balls.push_back( i );

		do 
			result.push_back( balls );
		while ( next_permutation( balls.begin(), balls.end() ) );


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

		vector<vector<int>> array = Permutations( count );
		
		for ( int i = 0; i < array.size(); i++ )
		{
			for ( int j = 0; j < array[i].size(); j++ )
			{
				if ( j + 1 == array[i][j] )
				{
					result++;
					break;
				}
			}
		}

		cout << "Ответ: " << result << endl;
	}

}
