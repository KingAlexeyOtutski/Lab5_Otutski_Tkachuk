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
 string sol ="", csN = ".0123456789", csF="+-/*";
//---------------------------------------------------------------------------
float process (char sol[])
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
			char sub[300]="";
			int j = i;
			while (csN.find(sol[i]) != -1)
			{
			   sub[i-j] = sol[i];
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
						numbers.push(b/a);
					}
					if (functions.top() == '+') {
						numbers.push(a+b);
					}
					if (functions.top() == '-') {
						numbers.push(b-a);
					}
					functions.pop();
				}
           functions.pop();
			continue;
		}
		if (csF.find(sol[i]) != -1) {
			while (!functions.empty())
			{
				if ((functions.top() == '+' || functions.top() == '-') && (sol[i] == '*' || sol[i] =='/') || functions.top() == '(') {
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
					numbers.push(b/a);
				}
				if (functions.top() == '+') {
					numbers.push(a+b);
				}
				if (functions.top() == '-') {
					numbers.push(b-a);
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
			numbers.push(a+b);
		}
		if (functions.top() == '-') {
			numbers.push(b-a);
		}
		if (functions.top() == '*') {
			numbers.push(a*b);
		}
		if (functions.top() == '/') {
			numbers.push(b/a);
		}
		functions.pop();
	}
	float res = numbers.top();
	numbers.pop();
	return res;


}
//---------------------------------------------------------------------------

int main ()
{
    char s[300];
    cin.getline(s, 256);
    cout << process(s);
}

