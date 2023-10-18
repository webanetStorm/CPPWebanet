#include <iostream>

using namespace std;


namespace WebanetG
{

	void FuncA()
	{
		int a = 20, b = 10, c = 55;

		cout << ( ( c - a ) / b ) << endl;
	}

	void FuncB() // TODO: переделать
	{
        int m;

        cout << "Ввод: ";
        if ( !( cin >> m ) or m > 2000000000 )
        {
            cout << "\nНекорректный ввод\n";
            return;
        }

        if ( m < 3 or m == 5 )
        {
            cout << 0 << endl;
            cout << 0 << endl;
        }
        else
        {
            int num3 = m / 3;

            if ( m % 3 == 0 )
            {
                cout << num3 << endl;
                cout << 0 << endl;
            }
            else
            {
                if ( m % 3 == 1 )
                {
                    cout << num3 - 1 << endl;
                    cout << 1 << endl;
                }
                else
                {
                    cout << num3 - 2 << endl;
                    cout << 2 << endl;
                }
            }
        }
	}

	void FuncC()
	{

	}

	void FuncD()
	{

	}

	void FuncE()
	{

	}

}
