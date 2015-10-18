#include <iostream>
#include <cstring>

using namespace std;

bool check (char st[])
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

int main()
{
    char st[256];
    cin.getline(st, 256);
    if (check(st))
    {
        cout << "CORRECT"<<endl;
    }
    else
    {
        cout <<"INCORRECT"<<endl;
    }
    return 0;
}
