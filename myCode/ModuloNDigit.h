/*
 * ModuloNDigit.h
 */

#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_
#include "ModuloNCounter.h"

/**
 * This class represents a ModuleNDigit which ask
 * user for number of digits to present counter value
 * in each counter increment. User can select one of
 * predefined base type for representation of current counter.
 */
class CModuloNDigit
{
private:
	/**
	 * @param m_nCounter receives a pointer from ModuleNCounter in order to
	 * set the number of digits and type of counter.
	 * @link aggregation
	 */
	CModuloNCounter *m_pNCounter;
	/**
	 * @param m_nCounter presents a 1D dynamic memory to
	 * store value of counter received from ModuleNCounter Class instance
	 */
	unsigned short *m_counterValue;
	/**
	 * @param m_Ndigits is a short unsigned integer variable to store the number of digits
	 * entered by user.
	 */
	unsigned short m_Ndigits = 1;
	/**
	 * @param m_counterType is a short unsigned integer variable to store type of counter
	 * entered by user.
	 */
	unsigned short m_counterType = 10;

public:
	/**
	 * Constructor receives a pointer from ModuleNCounter in order
	 * to set N counter type and number of digits for counter.
	 * It also allocates a 1D dynamic memory array to store current counter value
	 * for printing.
	 * @param *p is a pointer received from CModuleNCounter Class.
	 */
	CModuloNDigit(CModuloNCounter *p);
	/**
	 * Frees the memory allocated by this class.
	 */
	virtual ~CModuloNDigit();

	/**
	 * ++ operator overloading which is used for postfix increment operation.
	 */
	void operator ++(int);

	/**
	 * ++ operator overloading which is used for prefix increment operation.
	 */
	void operator ++();

	/**
	 * Prints current value of counter according to selected number of digits and type..
	 */
	void print();
};

#endif /* MODULONDIGIT_H_ */
