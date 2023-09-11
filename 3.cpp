#include <iostream>
#include <math.h>

using namespace std;


namespace WebanetC
{

	void FuncA()
	{
		float S = 50000, p = 13, n = 6;
		float r = p / 100;

		cout << ( S * r * pow( 1 + r, n ) ) / 12 * ( pow( 1 + r, n ) - 1 );
	}

	void FuncB()
	{

	}

}