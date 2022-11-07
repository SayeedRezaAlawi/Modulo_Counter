/*
 * ModuloNDigit.h
 *
 *      Author: Sayeed Reza Alawi
 */

#include "ModuloNDigit.h"
#include "ModuloNCounter.h"
#include <iostream>
#include <stdlib.h>
using namespace std;

CModuloNDigit::CModuloNDigit(CModuloNCounter *p)
{
	m_pNCounter = p;
	cout << "Please enter the parameters of your counter: " << endl;
	cout << "number of digits: ";
	cin >> m_Ndigits;
	cout << "type (2/8/10/16): ";
	cin >> m_counterType;
	m_counterValue = new unsigned short[m_Ndigits];
	for (int i = 0; i < m_Ndigits; i++)
	{
		m_counterValue[i] = 0;
	}
	m_pNCounter->setCounterDigits(m_Ndigits);
	m_pNCounter->setCounterType(m_counterType);
}

CModuloNDigit::~CModuloNDigit()
{
	delete[] m_counterValue;
}

void CModuloNDigit::print()
{
	m_counterValue = m_pNCounter->getCounterValue();
	if (m_counterType != 16)
	{
		for (int i = m_Ndigits - 1; i >= 0; i--)
		{
			cout << m_counterValue[i];
		}
		cout << endl;
	}
	else
	{
		for (int i = m_Ndigits - 1; i >= 0; i--)
		{
			switch (m_counterValue[i])
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
				cout << m_counterValue[i];
			}
		}
		cout << endl;
	}
}


void CModuloNDigit::operator ++(int)
{
	m_pNCounter->counter();
}

void CModuloNDigit::operator ++()
{
	m_pNCounter->operator ++();
}
