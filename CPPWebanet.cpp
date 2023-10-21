#include <windows.h>
#include <iostream>
#include "1.h"
#include "2.h"
#include "3.h"
#include "4.h"
#include "5.h"
#include "6.h"
#include "7.h"


int main()
{

	/* Адекватная работа на русском языке, в т.ч. для записи в файлы */
	setlocale( LC_ALL, "Russian" );
	SetConsoleCP( 1251 );
	SetConsoleOutputCP( 1251 );
	/* === */


	/* Каждое пространство имён вида WebanetX - отдельное ДЗ, каждая функция вида FuncX() - отдельное задание из ДЗ. A=1, B=2, C=3 и т.д. */

	/* Д/З #1 */
	// WebanetA::FuncZ(); // самое первое задание (вывод имени)
	// WebanetA::FuncA();
	// WebanetA::FuncB();
	// WebanetA::FuncC();
	// WebanetA::FuncD();

	/* Д/З #2 */
    // WebanetB::FuncA();
	// WebanetB::FuncB();
	// WebanetB::FuncC();
	// WebanetB::FuncD();
	// WebanetB::FuncE();

	/* Д/З #3 */
	// WebanetC::FuncA();
	// WebanetC::FuncB();
	// WebanetC::FuncC(); // 3 и 4 задания
	// WebanetC::FuncD();

	/* Д/З #4 */
	WebanetD::FuncA();
	// WebanetD::FuncB();
	// WebanetD::FuncCA();
	// WebanetD::FuncCB();
	// WebanetD::FuncCC();
	// WebanetD::FuncD();
    // WebanetD::FuncE();
	// WebanetD::FuncF();
	// WebanetD::FuncG();
	// WebanetD::FuncH();
	// WebanetD::FuncJ();

	/* Д/З #5 */
	// WebanetE::FuncA();
	// WebanetE::FuncB();
	// WebanetE::FuncCA();
	// WebanetE::FuncCB();
	// WebanetE::FuncDA();
	// WebanetE::FuncDB();
	// WebanetE::FuncE();

	/* Шарики */
	// WebanetF::Func(); // выполняется несколько секунд

	/* Спиннеры */
	// WebanetG::FuncA();
	// WebanetG::FuncB();
	// WebanetG::FuncC();
	// WebanetG::FuncD();
	// WebanetG::FuncE();


	return 0;

} // solders1@bk.ru
