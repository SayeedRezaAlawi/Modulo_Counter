/*
 * ModuloNCounter.h
 *
 *      Author: Sayeed Reza Alawi
 */

#include "ModuloNCounter.h"
#include "ModuloNDigit.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

CModuloNCounter::CModuloNCounter(unsigned short curcount,
		unsigned short maxcount)
{
	m_currentValue = curcount;
	m_maxCounterValue = maxcount;
	m_nDigitConunter = new unsigned short[m_Ndigits];
	for (int i = 0; i < m_Ndigits; i++)
	{
		m_nDigitConunter[i] = 0;
	}
	m_startingCounterValue = m_currentValue;
	counterType = decimal;
}

CModuloNCounter::CModuloNCounter(const CModuloNCounter &orig)
{
	m_currentValue = orig.m_currentValue;
	m_maxCounterValue = orig.m_maxCounterValue;
	m_nDigitConunter = new unsigned short[m_Ndigits];
	for (int i = 0; i < m_Ndigits; i++)
	{
		m_nDigitConunter[i] = orig.m_nDigitConunter[i];
	}
	m_startingCounterValue = m_currentValue;
	counterType = decimal;
}

CModuloNCounter::~CModuloNCounter()
{
	delete[] m_nDigitConunter;
}

void CModuloNCounter::counter()
{
	int total = pow(m_maxCounterValue, m_Ndigits);
	int j = 0;
	switch (counterType)
	{
	case 2:
		cout << m_Ndigits << " digit binary counter" << endl;
		break;
	case 8:
		cout << m_Ndigits << " digit octal counter" << endl;
		break;
	case 10:
		cout << m_Ndigits << " digit decimal counter" << endl;
		break;
	case 16:
		cout << m_Ndigits << " digit hexadecimal counter" << endl;
		break;
	}
	do
	{
		switch (counterType)
		{
		case 2:
			binaryCounter();
			print();
			if (j < m_maxCounterValue - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				cout << endl;
			}
			break;
		case 8:
			octalCounter();
			print();
			if (j < m_maxCounterValue - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				cout << endl;
			}
			break;
		case 10:
			decimalCounter();
			print();
			if (j < m_maxCounterValue - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				cout << endl;
			}
			break;
		case 16:
			hexaCounter();
			print();
			if (j < m_maxCounterValue - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				cout << endl;
			}
			break;
		}
		m_currentValue++;
	} while (m_currentValue < total);
}

void CModuloNCounter::operator ++()
{
	int total = pow(m_maxCounterValue, m_Ndigits);
	int j = 0;
	switch (counterType)
	{
	case 2:
		cout << m_Ndigits << " digit binary counter" << endl;
		break;
	case 8:
		cout << m_Ndigits << " digit octal counter" << endl;
		break;
	case 10:
		cout << m_Ndigits << " digit decimal counter" << endl;
		break;
	case 16:
		cout << m_Ndigits << " digit hexadecimal counter" << endl;
		break;
	}

	do
	{
		m_currentValue++;
		switch (counterType)
		{
		case 2:
			binaryCounter();
			print();
			if (j < m_maxCounterValue - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				cout << endl;
			}
			break;
		case 8:
			octalCounter();
			print();
			if (j < m_maxCounterValue - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				cout << endl;
			}
			break;
		case 10:
			decimalCounter();
			print();
			if (j < m_maxCounterValue - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				cout << endl;
			}
			break;
		case 16:
			hexaCounter();
			print();
			if (j < m_maxCounterValue - 1)
			{
				j++;
			}
			else
			{
				j = 0;
				cout << endl;
			}
			break;
		}
	} while (m_currentValue < total);
}

void CModuloNCounter::print()
{
	if (counterType != hexadecimal)
	{
		for (int i = m_Ndigits - 1; i >= 0; i--)
		{
			cout << m_nDigitConunter[i];
		}
		cout << " ";
	}
	else
	{
		for (int i = m_Ndigits - 1; i >= 0; i--)
		{
			switch (m_nDigitConunter[i])
			{
			case 10:
				cout << "A";
				break;
			case 11:
				cout << "B";
				break;
			case 12:
				cout << "C";
				break;
			case 13:
				cout << "D";
				break;
			case 14:
				cout << "E";
				break;
			case 15:
				cout << "F";
				break;
			default:
				cout << m_nDigitConunter[i];
			}
		}
		cout << " ";
	}
}

void CModuloNCounter::setCounterType(unsigned short type)
{
	m_maxCounterValue = type;
	switch (type)
	{
	case 2:
		counterType = binary;
		break;
	case 8:
		counterType = octal;
		break;
	case 10:
		counterType = decimal;
		break;
	case 16:
		counterType = hexadecimal;
		break;
	}
}

void CModuloNCounter::setCounterDigits(unsigned short digits)
{
	m_Ndigits = digits;
}

unsigned short* CModuloNCounter::getCounterValue()
{
	return m_nDigitConunter;
}

void operator ++(CModuloNCounter &v, int)
{
	v.counter();
}

void CModuloNCounter::binaryCounter()
{
	int digits[m_Ndigits] =
	{ 0 };
	int CounterValue = m_currentValue;
	for (int i = 0; i < m_Ndigits; i++)
	{

		if (CounterValue > 2)
		{
			digits[i] = CounterValue % 2;
			CounterValue = CounterValue / 2;
		}
		else
		{
			digits[i] = CounterValue % 2;
			CounterValue = CounterValue / 2;
		}
	}
	for (int i = m_Ndigits; i >= 0; i--)
	{
		m_nDigitConunter[i] = digits[i];
	}
}

void CModuloNCounter::octalCounter()
{
	int digits[m_Ndigits] =
	{ 0 };
	int CounterValue = m_currentValue;
	for (int i = 0; i < m_Ndigits; i++)
	{

		if (CounterValue > 8)
		{
			digits[i] = CounterValue % 8;
			CounterValue = CounterValue / 8;
		}
		else
		{
			digits[i] = CounterValue % 8;
			CounterValue = CounterValue / 8;
		}
	}
	for (int i = m_Ndigits; i >= 0; i--)
	{
		m_nDigitConunter[i] = digits[i];
	}

}

void CModuloNCounter::decimalCounter()
{
	int digits[m_Ndigits] =
	{ 0 };
	int CounterValue = m_currentValue;
	for (int i = 0; i < m_Ndigits; i++)
	{

		if (CounterValue > 10)
		{
			digits[i] = CounterValue % 10;
			CounterValue = CounterValue / 10;
		}
		else
		{
			digits[i] = CounterValue % 10;
			CounterValue = CounterValue / 10;
		}
	}
	for (int i = m_Ndigits; i >= 0; i--)
	{
		m_nDigitConunter[i] = digits[i];
	}

}

void CModuloNCounter::hexaCounter()
{
	int digits[m_Ndigits] =
	{ 0 };
	int CounterValue = m_currentValue;
	for (int i = 0; i < m_Ndigits; i++)
	{

		if (CounterValue > 16)
		{
			digits[i] = CounterValue % 16;
			CounterValue = CounterValue / 16;
		}
		else
		{
			digits[i] = CounterValue % 16;
			CounterValue = CounterValue / 16;
		}
	}
	for (int i = m_Ndigits; i >= 0; i--)
	{
		m_nDigitConunter[i] = digits[i];
	}
}

