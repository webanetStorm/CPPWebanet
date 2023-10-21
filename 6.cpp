#include <algorithm>
#include <iostream>
#include <numeric>
#include <vector>

using namespace std;


namespace WebanetF
{

	vector<vector<int>> Permutations( int count ) // ��������� ������������ ������� ����������� ������������ �����
	{
		vector<vector<int>> result; // ��� ���������� �����
		vector<int> balls; // ����� ������� �����


		for ( int i = 1; i <= count; i++ )
			balls.push_back( i ); // ������ ������ � �������� ����� ���� [ 1, 2, 3, ..., count ]

		do 
			result.push_back( balls ); // ��������� � result ��������� ���������� �����
		while ( next_permutation( balls.begin(), balls.end() ) ); // ������������ �����


		return result;
	}

	void Func()
	{
		int result = 0, count;

		cout << "������� ���-�� �����: ";
		if ( !( cin >> count ) )
		{
			cout << "\n������������ ����\n";
			return;
		}

		vector<vector<int>> array = Permutations( count ); // ������ � ������������ �����
		
		for ( int i = 0; i < array.size(); i++ )
		{
			for ( int j = 0; j < array[i].size(); j++ )
			{
				if ( j + 1 == array[i][j] ) // array[i][j] - ����� ����, j - ������� ������������ ����
				{
					result++;
					break;
				}
			}
		}

		cout << "�����: " << result << endl;
	}

}
