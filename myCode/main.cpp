// Standard (system) header files
#include <iostream>
#include <stdlib.h>
using namespace std;
#include "ModuloNCounter.h"
#include "ModuloNDigit.h"
// Add more standard header files as required
// #include <string>

int main(void)
{
	cout << "Exercise 2.1 Modulo Counter started." << endl << endl;
	/**
	 * Creation of Module N Counter instance, and setting starting value and maximum number of counting.
	 */
	CModuloNCounter counter(0, 10);
	/**
	 * Creation of Module N Digit instance.
	 * @param &counter address of N Counter instance as constructor parameter.
	 */
	CModuloNDigit MdigitCounter(&counter);

//	counter++;
//	++counter;
	MdigitCounter++;
//	++MdigitCounter;


	return 0;
}
