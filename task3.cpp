//---------------------------------------------------------------------------
#include <string>
#include <stack>
#include <iostream>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
//---------------------------------------------------------------------------
using namespace std;

//---------------------------------------------------------------------------
string sol = "", csN = ".0123456789", csF = "+-/*";
//---------------------------------------------------------------------------
float process(char sol[])
{
	stack <float> numbers;
	stack <char> functions;
	for (int i = 0; i < strlen(sol); i++)
	{
		if (i == 0 && sol[0] == '-')
		{
			numbers.push(-1);
			functions.push('*');
			i++;
		}
		if (!functions.empty() && functions.top() == '(' && sol[i] == '-')
		{
			numbers.push(-1);
			functions.push('*');
			i++;
		}
		if (csN.find(sol[i]) != -1) {
			char sub[300] = "";
			int j = i;
			while (csN.find(sol[i]) != -1)
			{
				sub[i - j] = sol[i];
				i++;
			}

			float n = atof(sub);
			numbers.push(n);
		}
		if (sol[i] == '(')
		{
			functions.push('(');
		}
		if (sol[i] == ')') {
			while (functions.top() != '(')
			{
				float a, b;
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				if (functions.top() == '*') {
					numbers.push(a*b);
				}
				if (functions.top() == '/') {
					numbers.push(b / a);
				}
				if (functions.top() == '+') {
					numbers.push(a + b);
				}
				if (functions.top() == '-') {
					numbers.push(b - a);
				}
				functions.pop();
			}
			functions.pop();
			continue;
		}
		if (csF.find(sol[i]) != -1) {
			while (!functions.empty())
			{
				if ((functions.top() == '+' || functions.top() == '-') && (sol[i] == '*' || sol[i] == '/') || functions.top() == '(') {
					break;
				}
				float a, b;
				a = numbers.top();
				numbers.pop();
				b = numbers.top();
				numbers.pop();
				if (functions.top() == '*') {
					numbers.push(a*b);
				}
				if (functions.top() == '/') {
					numbers.push(b / a);
				}
				if (functions.top() == '+') {
					numbers.push(a + b);
				}
				if (functions.top() == '-') {
					numbers.push(b - a);
				}
				functions.pop();

			}
			functions.push(sol[i]);
		}
	}
	while (!functions.empty())
	{
		float a, b;
		a = numbers.top();
		numbers.pop();
		b = numbers.top();
		numbers.pop();
		if (functions.top() == '+') {
			numbers.push(a + b);
		}
		if (functions.top() == '-') {
			numbers.push(b - a);
		}
		if (functions.top() == '*') {
			numbers.push(a*b);
		}
		if (functions.top() == '/') {
			numbers.push(b / a);
		}
		functions.pop();
	}
	float res = numbers.top();
	numbers.pop();
	return res;


}
//---------------------------------------------------------------------------

void testingitself(char* input_string, int expected_output, int& number_of_test)
{
	if (process(input_string) == expected_output)
		cout << "Test num." << ++number_of_test << " was passed.\n";
	else
		cout << "Test num." << ++number_of_test << " was failed.\n";
}

void testing()
{
	int i = 0;
	testingitself("2+3*(4-8/2+4/(2-1))", 14, i);
	testingitself("(2+2)*2", 8, i);
	testingitself("50*(80-10/5)-3", 3897, i);
	testingitself("2+2*2", 6, i);
	testingitself("(50/100+30/15)*40", 100, i);
	testingitself("(2001+2002+2003+2004+2005)/5", 2003, i);
	testingitself("2001+2002+2003+2004+2005/5", 8411, i);
	testingitself("1995+2400/(4+5*(6-2))", 2095, i);
	cout << "\nBecause Pasha is molodets ^_^.\n\n";
}

void work()
{
	char s[300];
	cin.getline(s, 256);
	cout << process(s);
}

void main()
{
//	work();
	testing();
}

