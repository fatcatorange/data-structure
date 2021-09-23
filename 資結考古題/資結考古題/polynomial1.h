#include "stdio.h"
#include <iostream>
using namespace std;

#define MAX_TERMS 10 /*size of terms array*/

class PolynomialTerm {
public:
	int coef;
	int expo;
};

class ArrayPolynomial {
public:
	PolynomialTerm terms[MAX_TERMS];

	void clear() /////
	{
		for (int i = 0; i < MAX_TERMS; i++) {
			terms[i].coef = 0;
			terms[i].expo = 0;
		}

		return;
	}

	void inputTerms(int coef, int expo)
	{
		// modify the following code and add your code here
		int i = 0;

		for (; terms[i].coef != 0 && i < MAX_TERMS; i++);

		terms[i].coef = coef;
		terms[i].expo = expo;

		return;
	}

	void printArrayBasedPoly()
	{
		if (terms[0].coef == 0)
			return;

		if (terms[0].expo == 0)
			cout << terms[0].coef;
		else
			cout << terms[0].coef << "X^" << terms[0].expo;

		for (int i = 1; i < MAX_TERMS; i++) {
			if (terms[i].coef == 0)
				return;

			if (terms[i].expo == 0)
				cout << " + " << terms[i].coef;
			else
				cout << " + " << terms[i].coef << "X^" << terms[i].expo;
		}

		return;
	}

	void showArrayBasedPolyMaxTerm()
	{
		PolynomialTerm term = findArrayBasedPolyMaxTerm(0);

		if (term.coef == 0)
			return;

		if (term.expo == 0)
			cout << term.coef;
		else
			cout << term.coef << "X^" << term.expo;
	}

	PolynomialTerm findArrayBasedPolyMaxTerm(int i)
	{
		if (terms[i].coef == 0)
			return terms[i];
		PolynomialTerm term;
		term = findArrayBasedPolyMaxTerm(i+1);
		if (terms[i].expo > term.expo)
			return terms[i];
		if (terms[i].expo < term.expo)
			return term;
		if (terms[i].coef > term.coef)
			return terms[i];
		return term;
		// add yor code here

		return term;
	}

	void ArrayBasedRotateTerms() {

		//printf("array\n");
		int a, b, c,last;
		PolynomialTerm first;
		first = terms[0];
		for (a = 0; a < MAX_TERMS; a++)
		{
			if (terms[a].coef == 0)
			{
				last = a;
				break;
			}
		}
		for (a = 0; a < MAX_TERMS - 1; a++)
		{
			terms[a] = terms[a + 1];
		}
		terms[last - 1] = first;
		terms[last].coef = 0;
		terms[last].expo = 0;
		// add yor code here


	}

	void compactCopy(ArrayPolynomial &poly)
	{
		int a, b, c;
		PolynomialTerm temp;
		for (a = 0; a < MAX_TERMS; a++)
		{
			terms[a] = poly.terms[a];
		}
		for (a = 0; a < MAX_TERMS; a++)
		{
			for (b = 0; b < MAX_TERMS; b++)
			{
				if (terms[b].expo < terms[b + 1].expo)
				{
					temp = terms[b];
					terms[b] = terms[b + 1];
					terms[b + 1] = temp;
				}
				if (terms[b].expo == terms[b + 1].expo)
				{
					terms[b].coef += terms[b + 1].coef;
					for (c = b + 1; c < MAX_TERMS - 1; c++)
						terms[c] = terms[c + 1];
				}
			}
		}
		for (a = 0; a < MAX_TERMS; a++)
		{
			if (terms[a].coef == 0)
			{
				for (b = a; b < MAX_TERMS - 1; b++)
				{
					terms[b] = terms[b + 1];
				}
			}
		}
		// add yor code here


	}
};

class LinkedPolynomialTerm {
public:
	int coef;
	int expo;
	LinkedPolynomialTerm *nextTermPtr;
};

class LinkedPolynomial {
public:
	LinkedPolynomialTerm *polynomialTermPtr = nullptr;

	void clear()
	{
		LinkedPolynomialTerm *tmpPtr;

		while (polynomialTermPtr != nullptr) {
			tmpPtr = polynomialTermPtr;
			polynomialTermPtr = polynomialTermPtr->nextTermPtr;
			delete tmpPtr;
		}

		return;
	}

	void inputTerms(int coef, int expo)
	{
		LinkedPolynomialTerm *tmpPtr;

		tmpPtr = new LinkedPolynomialTerm;
		tmpPtr->coef = coef;
		tmpPtr->expo = expo;
		tmpPtr->nextTermPtr = polynomialTermPtr;

		polynomialTermPtr = tmpPtr;

		// add your code here 


		return;
	}

	void printLinkBasedPoly()
	{
		LinkedPolynomialTerm *termPtr = polynomialTermPtr;

		if (termPtr == nullptr)
			return;

		if (termPtr->expo == 0)
			cout << termPtr->coef;
		else
			cout << termPtr->coef << "X^" << termPtr->expo;

		termPtr = termPtr->nextTermPtr;

		while (termPtr != nullptr) {
			if (termPtr->coef == 0)
				return;

			if (termPtr->expo == 0)
				cout << " + " << termPtr->coef;
			else
				cout << " + " << termPtr->coef << "X^" << termPtr->expo;

			termPtr = termPtr->nextTermPtr;
		}

		return;
	}

	void showLinkBasedPolyMaxTerm()
	{
		LinkedPolynomialTerm *termPtr = findLinkBasedPolyMaxTerm(polynomialTermPtr);

		if (termPtr == nullptr)
			return;

		if (termPtr->expo == 0)
			cout << termPtr->coef;
		else
			cout << termPtr->coef << "X^" << termPtr->expo;
	}

	LinkedPolynomialTerm* findLinkBasedPolyMaxTerm(LinkedPolynomialTerm *currPtr)
	{
		LinkedPolynomialTerm *temp;
		if (currPtr->nextTermPtr == nullptr)
			return currPtr;
		temp = findLinkBasedPolyMaxTerm(currPtr->nextTermPtr);
		if (temp->expo > currPtr->expo)
			return temp;
		if (temp->expo < currPtr->expo)
			return currPtr;
		if (temp->coef > currPtr->coef)
			return temp;
		return currPtr;

		// add yor code here


		return nullptr;
	}

	void LinkBasedRotateTerms() {
		//printf("\nlink");
		LinkedPolynomialTerm* first;
		first = polynomialTermPtr;
		if (first != nullptr)
		{
			polynomialTermPtr = first->nextTermPtr;
		}
		LinkedPolynomialTerm* find;
		find = polynomialTermPtr;
		for (int a=0;;a++)
		{
			if (find == nullptr&&a==0)
			{
				polynomialTermPtr = first;
				break;
			}
			if (find->nextTermPtr == nullptr)
			{
				find->nextTermPtr = first;
				first->nextTermPtr = nullptr;
				break;
			}
			find = find->nextTermPtr;
		}

		// add yor code here


	}

	void compactCopy(LinkedPolynomial &poly)
	{
		int a, b, c;
		LinkedPolynomialTerm* old;
		LinkedPolynomialTerm* next;
		LinkedPolynomialTerm* find;
		old = poly.polynomialTermPtr;
		polynomialTermPtr = nullptr;
		for (a=0;;a++)
		{
			find = polynomialTermPtr;
			if (old == nullptr)
				break;
			next = new LinkedPolynomialTerm;
			if (polynomialTermPtr==nullptr)
			{
				polynomialTermPtr = next;
				next->coef = old->coef;
				next->expo = old->expo;
				next->nextTermPtr = nullptr;
				old = old->nextTermPtr;
				continue;
			}
			if (old->expo > polynomialTermPtr->expo)
			{
				next->nextTermPtr =  polynomialTermPtr;
				next->coef = old->coef;
				next->expo = old->expo;
				polynomialTermPtr = next;
				old = old->nextTermPtr;
				continue;
			}
			if (old->expo == polynomialTermPtr->expo)
			{
				//printf("\n hi %d %d \n");
				polynomialTermPtr->coef += old->coef;
				if (polynomialTermPtr->coef == 0)
				{
					polynomialTermPtr = polynomialTermPtr->nextTermPtr;
				}
				old = old->nextTermPtr;
				continue;
			}
			for (;;)
			{
				if (find->nextTermPtr == nullptr || find->nextTermPtr->expo < old->expo)
				{
					next->nextTermPtr = find->nextTermPtr;
					next->coef = old->coef;
					next->expo = old->expo;
					find->nextTermPtr = next;
					break;
				}
				if (find->nextTermPtr->expo == old->expo)
				{
					//printf("\nyo\n");
					find->nextTermPtr->coef += old->coef;
					if (find->nextTermPtr->coef == 0)
					{
						find->nextTermPtr = find->nextTermPtr->nextTermPtr;
					}
					break;
				}
				find = find->nextTermPtr;
			}
			old = old->nextTermPtr;
		}
		for (int a = 0; a < MAX_TERMS; a++)
		{
			if (polynomialTermPtr == nullptr)
				break;
			if (polynomialTermPtr->coef == 0)
				polynomialTermPtr = polynomialTermPtr->nextTermPtr;
		}
		

		// add yor code here


	}
};
