#include <iostream>
#include <math.h>

using namespace std;


namespace WebanetC
{

	void FuncA()
	{
		float s = 50000, p = -13, n = 6;
		float r = p / 100;

		cout << ( s * r * pow( 1 + r, n ) ) / ( 12 * ( pow( 1 + r, n ) - 1 ) ) << endl;
	}

	void FuncB()
	{
		// ...
	}

}