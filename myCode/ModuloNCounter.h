/*
 * ModuloNCounter.h
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

/**
 * This class is a Module N Counter which starts counting from predefined
 * starting point and N define the maximum number of counting entered by user
 */

class CModuloNCounter
{
private:
	/**
	 * @param nDigitConunter is a pointer which shows a 1D dynamic memory allocated to
	 * store current value of N Digits Counter.
	 */
	unsigned short *m_nDigitConunter;
	/**
	 * @param m_MaxCounterValue store maximum number of counting by N counter.
	 * The predefined value of m_MaxCounterValue is set to 10,
	 * means it starts from starting point and counts 10 times.
	 */
	unsigned short m_maxCounterValue = 10;
	/**
	 * @param m_Ndigits receive number of digits from ModuleNDigit.
	 * It is predefined value is 1, means one digit counter.
	 */
	unsigned short m_Ndigits = 1;
	/**
	 * @param m_currentValue keeps current value of counter.
	 */
	unsigned short m_currentValue = 0;
	/**
	 * @param m_startingCounterValue can be entered by user to define the start number of counting.
	 */
	unsigned short m_startingCounterValue = 0;
	/**
	 * In order to distinguish the type of counter, enumeration type is defined here.
	 * @param m_counterType is enumeration for different types of
	 * counter (binary, octal, decimal, hexadecimal) selected by user.
	 *
	 */
	enum m_counterType
	{
		binary = 2, octal = 8, decimal = 10, hexadecimal = 16,
	};
	typedef enum m_counterType m_counterType_t;
	/**
	 * @param counterType is enum type variable to store
	 * type of counter which set from ModuleNDigit class.
	 */
	m_counterType_t counterType;
	/**
	 * binaryCounter is a private method which only used by counter and operation methods.
	 * It receives the current value of N Counters and converts it
	 * to binary form with number of digits which entered by user.
	 */
	void binaryCounter();
	/**
	 * octalCounter is a private method which only used by counter and operation methods.
	 * It receives the current value of N Counter and converts it
	 * to octal form with number of digits which entered by user.
	 */
	void octalCounter();
	/**
	 * decimalCounter is a private method which only used by counter and operation methods.
	 * It receives the current value of N Counter and converts it
	 * to decimal form with number of digits which entered by user.
	 */
	void decimalCounter();
	/**
	 * hexaCounter is a private method which only used by counter and operation methods.
	 * It receives the current value of N Counter and converts it
	 * to hexadecimal form with number of digits which entered by user.
	 */
	void hexaCounter();
public:
	/**
	 * Constructor of CModuleNCounter which allocate a 1D memory array
	 * to store current value of counter
	 * @param curcount starting number for counter which can be set by user.
	 * @param maxcount maximum number of counting which can be defined by user.
	 */
	CModuloNCounter(unsigned short curcount, unsigned short maxcount);
	/**
	 * Copy constructor.
	 * @param orig the object to copy from
	 */
	CModuloNCounter(const CModuloNCounter &orig);
	/**
	 * Frees the memory allocated by this class.
	 */
	virtual ~CModuloNCounter();
	/**
	 * Increase the current value and if the number of counting becomes more
	 * than maximum number of counting, the current counter value will reset
	 * to stating value.
	 */
	void counter();
	/**
	 * ++ operator overloading which is used for prefix increment operation.
	 */
	void operator ++();
	/**
	 * Prints the current value of counter according type, number of digits.
	 */
	void print();
	/**
	 * ModuleNDigit uses this method to pass the type of counter.
	 */
	void setCounterType(unsigned short type);
	/**
	 * ModuleNDigit uses this method to pass the number of digits for N Counter.
	 */
	void setCounterDigits(unsigned short digits);
	/**
	 * Returns a pointer to current value on dynamic memory to ModuleNDigits class to print.
	 */
	unsigned short* getCounterValue();
	/**
	 * Makes postfix increment operator function as a friend for ModuleNCounter class.
	 */

	friend void operator ++(CModuloNCounter &v, int);
};

/**
 * Friend function for ++ operator overloading which is used for postfix increment operation.
 */

void operator ++(CModuloNCounter &v, int);

#endif /* MODULONCOUNTER_H_ */
