#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

using namespace std;


namespace WebanetC
{

	void FuncA()
	{
		float s = 1000000, p = 15, n = 20;
		float r = p / 100;

		cout << ( s * r * pow( 1 + r, n ) ) / ( 12 * ( pow( 1 + r, n ) - 1 ) ) << endl;
	}

	void FuncB()
	{
		float s = 1000000;
		float n = 20;
		float m = 0;
		float mConst = 13313.5;
		float r = 0.000001; 
		int p;


		if ( n == 0 or s <= 0 )
			cout << "Íåêîððåêòíûå çíà÷åíèÿ\n";

		while ( m < mConst )
		{
			m = s * r * pow( 1 + r, n ) / ( 12 * ( pow( 1 + r, n ) - 1 ) );
			r += 0.000001;
		}

		p = r * 100;

		cout << "p = " << p << "%" << endl;
	}

	void FuncC()
	{
		ofstream file( "file.txt" );
		file << "CPPWebanetMIREA 1234567890";
		file.close();


		string line;
		ifstream in( "file.txt" );

		while ( std::getline( in, line ) )
			cout << "Êîïèðîâàíèå ôàéëà: " << line << endl << "Ôèëüòð: ";


		string numbers = "0123456789";

		for ( int i = 0; i < line.size(); i++ )
			if ( numbers.find( line[i] ) != string::npos )
			    cout << line[i];

		cout << endl;

		in.close();

	}

	void FuncD()
	{
		string str = "ÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏÐÎËÄÆÝß×ÑÌÈÒÜ";
		
		for ( int i = 0; i < str.length() - 1; i++ )
			for ( int j = i; j < str.length() - 1; j++ )
				if ( str[i] > str[j + 1] )
					swap( str[i], str[j + 1] );

		cout << str << endl;
	}

}
