#include <iostream>
#include <fstream>
#include <string>

using namespace std;


namespace WebanetD
{

	int FuncA()
	{
		float inputNumber, result = 0;
		ofstream file( "D1.txt" );

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

				return 0;
			}
		}

		file.close();



		ifstream in( "D1.txt" );
		string line;

		while ( std::getline( in, line ) )
			result += std::stoi( line );

		in.close();

		cout << "���������: " << result << endl;


		return 0;
	}

}
