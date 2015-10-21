#include <iostream>
using namespace std;

struct stack
{
	char symbol;
	stack* previous;
};

bool bracket_check(char symbol)
{
	if ((symbol == '(') || (symbol == ')') || (symbol == '{') || (symbol == '}') || (symbol == '[') || (symbol == ']'))
		return 1;
	else
		return 0;
}

stack* stack_add(char symbol, stack* stack_head)
{
	stack *new_stack_head = new stack;
	new_stack_head->previous = stack_head;
	new_stack_head->symbol = symbol;
	return new_stack_head;
}

bool checking_the_possibility_of_shortening_the_stack(stack* stack_head)
{
	if (((stack_head->symbol == ']')&&(stack_head->previous->symbol == '['))|| ((stack_head->symbol == ')') && (stack_head->previous->symbol == '('))|| ((stack_head->symbol == '}') && (stack_head->previous->symbol == '{')))
		return 1;
	else
		return 0;
}

bool checking(char* str)
{
	stack* stack_head=new stack;
	stack_head->symbol = '=';
	stack_head->previous = NULL;
	int i = 0;
	while (str[i] != '\0')
	{
		if (bracket_check(str[i]))
		{
			stack_head = stack_add(str[i], stack_head);
			if (checking_the_possibility_of_shortening_the_stack(stack_head))
				stack_head = stack_head->previous->previous;
		}
		i++;
	}
	if (stack_head->symbol == '=')
		return 1;
	else
		return 0;
}

void test (char test_string[], bool answer)
{
    if (checking(test_string) == answer)
    {
        cout <<"CORRECT\n";
    }
    else
    {
        cout << "INCORRECT\n";
    }
}

int main()
{
    test ("()", true);
    test ("[([{}])]", true);
    test ("", true);
    test ("{", false);
    test ("[[][][[[[[][][]][[[]]]]]][[[]][[]][]", false);
    test ("{([})", false);
	//Lesha();
	return 0;
}
