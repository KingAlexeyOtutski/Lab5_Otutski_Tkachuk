#include <iostream>
#include <algorithm>
using namespace std;

struct stack
{
	int value;
	char operation;
	stack* previous;
};

stack* stack_add_first(int value, char operation, int& amount_of_stack_elements)
{
	stack *stack_last = new stack;
	stack_last->previous = NULL;
	if ((operation == '>') || (operation == '<'))
		stack_last->operation = operation;
	else
	{
		stack_last->value = value;
		stack_last->operation = '=';
	}
	amount_of_stack_elements++;
	return stack_last;
}

stack* stack_add(int value, char operation, stack* stack_head, int& amount_of_stack_elements)
{
	stack *new_stack_head = new stack;
	new_stack_head->previous = stack_head;
	if (operation != '=')
		new_stack_head->operation = operation;
	else
	{
		new_stack_head->value = value;
		new_stack_head->operation = '=';
	}
	amount_of_stack_elements++;
	return new_stack_head;
}

bool checking_the_possibility_of_shortening_the_stack(stack* stack_head, int amount_of_stack_elements)
{
	if (amount_of_stack_elements < 3)
		return 0;
	if ((stack_head->operation == '=') && (stack_head->previous->operation == '=') && ((stack_head->previous->previous->operation == '<') || (stack_head->previous->previous->operation == '>')))
		return 1;
	else
		return 0;
}

stack* stack_calculate(stack* stack_head, int& amount_of_stack_elements)
{
	if (stack_head->previous->previous->operation == '>')
	{
		stack_head->previous->previous->operation = '=';
		stack_head->previous->previous->value = max(stack_head->previous->value,stack_head->value);
		stack_head = stack_head->previous->previous;
	}
	else
	{
		stack_head->previous->previous->operation = '=';
		stack_head->previous->previous->value = min(stack_head->previous->value, stack_head->value);
		stack_head = stack_head->previous->previous;
	}
	amount_of_stack_elements = amount_of_stack_elements - 2;
	return stack_head;
}

int counting(char str[])
{
	int i = 0, amount_of_stack_elements = 0;
	stack* stack_head = new stack;
	while (str[i] != '\0')
	{
		if (isdigit(str[i]))
		{
			if (amount_of_stack_elements == 0)
				stack_head = stack_add_first((int)(str[i]) - 48, '=', amount_of_stack_elements);
			else
			{
				stack_head = stack_add((int)(str[i]) - 48, '=', stack_head, amount_of_stack_elements);
			}
			while (checking_the_possibility_of_shortening_the_stack(stack_head, amount_of_stack_elements))
			{
				stack_head = stack_calculate(stack_head, amount_of_stack_elements);
			}
			i++;
			continue;
		}
		else
		{
			if ((str[i] == ' ') || (str[i] == ',') || (str[i] == '(') || (str[i] == ')'))
			{
				i++;
				continue;
			}
			if (str[i] == 'm')
			{
				if (str[i + 1] == 'i')
				{
					if (amount_of_stack_elements == 0)
						stack_head = stack_add_first(0, '<', amount_of_stack_elements);
					else
						stack_head = stack_add(0, '<', stack_head, amount_of_stack_elements);
				}
				else
				{
					if (amount_of_stack_elements == 0)
						stack_head = stack_add_first(0, '>', amount_of_stack_elements);
					else
						stack_head = stack_add(0, '>', stack_head, amount_of_stack_elements);
				}
				i = i + 4;
				continue;
			}
		}
	}
	return stack_head->value;
}

/*void Lesha()
{
	char input_string[100];
	freopen("input.txt", "r", stdin);
	gets_s(input_string);
	fclose(stdin);
	int a = 10, b = 20;
	cout << "After calculating your input string " << endl << endl << input_string << endl << endl << "becomes " << endl << endl << counting(input_string) << endl << endl;
}*/

void test (char test_string[], int answer)
{
    if (counting(test_string) == answer)
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
    test ("8", 8);
    test ("max(2, 3)", 3);
    test ("max(1, max(2, max(3, max(4, max(5, 6)))))", 6);
    test ("max(1, min(1, max(1, min(1, max(1, 1)))))", 1);
    test ("min(max(1, 9), max(5, 6))", 6);
	//Lesha();
	return 0;
}
