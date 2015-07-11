// stack_machine.cpp: определяет точку входа для консольного приложения.
//
#include "stdafx.h"
#include <iostream>
using namespace std;
void main () 
{
	StackMath a("55*2");
	cout << "Result is: "<<a.GetResult()<<'\n';
	system("pause");
}
