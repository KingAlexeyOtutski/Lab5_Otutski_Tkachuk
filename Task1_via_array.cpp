#include <iostream>
#include <cstring>

using namespace std;

bool check(char st[])
{
	/* 1 - "()"  2 - "[]"  3 - "{}"  */
	int stack1[256];
	int top = 0;
	for (int i = 0; i < strlen(st); i++)
	{
		if (st[i] == '(')
		{
			stack1[top] = 1;
			top++;
		}
		if (st[i] == '[')
		{
			stack1[top] = 2;
			top++;
		}
		if (st[i] == '{')
		{
			stack1[top] = 3;
			top++;
		}

		if (st[i] == ')')
		{

			if (top > 0 && stack1[top - 1] == 1)
			{
				top--;
			}
			else
			{
				return false;
			}
		}
		if (st[i] == ']')
		{

			if (top > 0 && stack1[top - 1] == 2)
			{
				top--;
			}
			else
			{
				return false;
			}
		}
		if (st[i] == '}')
		{

			if (top > 0 && stack1[top - 1] == 3)
			{
				top--;
			}
			else
			{
				return false;
			}
		}
	}
	if (top == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

void Pasha()
{
	char st[256];
	cin.getline(st, 256);
	if (check(st))
	{
		cout << "CORRECT" << endl;
	}
	else
	{
		cout << "INCORRECT" << endl;
	}
}

void testingitself(char* input_string, int expected_result, int& i)
{
	if (check(input_string) == expected_result)
		cout << "Test n." << i << " was passed." << endl;
	else
		cout << "Test n." << i << " was failed." << endl;
	i++;
}

void testing()
{
	int i = 1;
	testingitself("[aaz([a{z()}]f2)5]", 1, i);
	testingitself("adg(tw[f{{s}}])[{]}dq", 0, i);
	testingitself("([af{()(())}]{[y]})", 1, i);
	testingitself("([{{}{}{}(da)(ne)}][(ye)r][]t2[][[fv]21{1}])", 1, i);
	testingitself("{{()}[()((()))bs{(dv0))ey[[ar]]}]}", 0, i);
}

void main()
{
	//Pasha();
	testing();
}