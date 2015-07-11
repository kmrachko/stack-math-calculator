#include <stack>
#include "stdlib.h"
#include "ctype.h"
#include <cstring>
class StackMath {
private:
	std::stack <int> digits;
	std::stack <char> operators;
	char* ex;
	int write_digit (int);
	void last_op (void);
	void check_operator (char);
	void pop_operator (void);
	int check_priority (char);
	int get_priority (char);
public:
	StackMath(char*);
	~StackMath();
	int GetResult(void);
};