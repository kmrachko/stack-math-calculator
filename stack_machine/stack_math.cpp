#include "stdafx.h"
StackMath::StackMath(char* ex_) {
	ex=ex_;
}
StackMath::~StackMath() {

}
int StackMath::write_digit (int i) {
	std::string temp_ex(ex);									  //writes number to digit stack and returns position of the end of number in ex
	int start=i;
	int count=1;
	while (ex[++i]!='\0' && isdigit(ex[i])) count++;
	char * temp=new char[999];
	int length = temp_ex.copy(temp,count,start);
	temp[length]='\0';
	(ex[start-1]=='-' && ex[start-2]=='(')?digits.push(-atoi(temp)):digits.push(atoi(temp));
	return start+count-1;
}
void StackMath::last_op (void) {
	std::stack <char> temp_op;

	while (!operators.empty())
	{
		temp_op.push(operators.top());
		operators.pop();
	}

	operators.push('(');

	while (!temp_op.empty())
	{
		operators.push(temp_op.top());
		temp_op.pop();
	}
	check_operator (')');
}
void StackMath::check_operator (char s) {
	if (check_priority (s)==1)
	{	
		if (s==')') 
		{	
			while (operators.top()!='(')
			{
				pop_operator ();
			}
			operators.pop();
			return;
		}
		pop_operator ();
	}
	operators.push(s);
}
void StackMath::pop_operator (void) {
		int A = digits.top();
		digits.pop();
		int B = digits.top();
		digits.pop();

		switch (operators.top()) 
		{
			case '+': digits.push(A+B); break;
			case '-': digits.push(B-A); break;
			case '*': digits.push(A*B); break;
			case '/': digits.push(B/A); break;
		}
		operators.pop();
}
int StackMath::check_priority (char s) {
	if (operators.empty()) return 0;
	if (get_priority(s)>=get_priority(operators.top()) && get_priority(s)>0 && get_priority(operators.top())>0) return 1;
	else return 0;
}
int StackMath::get_priority (char s) {
	if (s=='+'||s=='-') return 2;
	if (s=='*'||s=='/') return 1;
	if (s=='(') return -1;
	if (s==')') return 999;
}
int StackMath::GetResult(void) {
	for (int i=0;i<strlen(ex);i++)
		{	
			if (isdigit(ex[i])) 
			{	
				i = write_digit(i);
			}
			else 
			{
				if (ex[i]=='(' && ex[i+1]=='-') 
				{
					i+=2;
					i = write_digit(i);
					i+=2;
				}
				check_operator(ex[i]);
			}
		}
	last_op();
	return digits.top();
}