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
		float s = 1000000, n = 20, m = 0, mConst = 13313.5, r = 0.0001;
		int p;

		while ( m < mConst )
		{
			m = s * r * pow( 1 + r, n ) / ( 12 * ( pow( 1 + r, n ) - 1 ) );
			r += 0.0001;
		}

		cout << "p = " << ( p = r * 100 ) << "%" << endl;
	}

	void FuncC()
	{
		ofstream file( "file.txt" );
		file << "CPPWebanetMIREA 1234567890";
		file.close();


		string line;
		ifstream in( "file.txt" );

		while ( std::getline( in, line ) )
			cout << "Êîïèğîâàíèå ôàéëà: " << line << endl << "Ôèëüòğ: ";


		string numbers = "0123456789";

		for ( int i = 0; i < line.size(); i++ )
			if ( numbers.find( line[i] ) != string::npos )
			    cout << line[i];

		cout << endl;

		in.close();
		remove( "file.txt" );
	}

	bool IsDigit( char c )
	{
		return isdigit( static_cast<unsigned char>( c ) );
	}

	void FuncD()
	{
		string str = "ÉÖÓÊÅÍÃØÙÇÕÚÔÛÂÀÏĞÎËÄÆİß×ÑÌÈÒÜ180819";

		str.erase( remove_if( str.begin(), str.end(), IsDigit ), str.end() );
		
		for ( int i = 0; i < str.length() - 1; i++ )
			for ( int j = i; j < str.length() - 1; j++ )
				if ( str[i] > str[j + 1] )
					swap( str[i], str[j + 1] );

		cout << str << endl;
	}

}
