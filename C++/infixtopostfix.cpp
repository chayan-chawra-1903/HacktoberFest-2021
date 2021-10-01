#include<iostream>
#include<stack>

using namespace std;

bool isOperand(char ch)
{
    if ((ch>='0' && ch<='9') || (ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
    {
        return true;
    }
    return false;
}

bool isOperator(char ch)
{
    if (ch=='+'|| ch=='-'|| ch=='*'|| ch=='/')
    {
        return true;
    }
    return false;
}

int setPrecedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    
    default:
        return 0;
    }
}

bool hasHigherPrecedence(int op1,int op2)
{
    int op1pref = setPrecedence(op1);
    int op2pref = setPrecedence(op2);
    return op1pref>op2pref;
}

int main()
{
    string infix,postfix="";
    getline(cin,infix);
    stack<char> s;

    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i]==' ' || infix[i]==',')
        {
            continue;
        }
        else if (isOperand(infix[i]))
        {
            postfix+=infix[i];
        }
        else if (infix[i]=='(')
        {
            s.push(infix[i]);
        }
        else if (infix[i]==')')
        {
            while (!s.empty() && s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }
            s.pop();
        }
        else if (isOperator(infix[i]))
        {
            while (!s.empty() && hasHigherPrecedence(s.top(),infix[i]))
            {
                postfix+=s.top();
                s.pop();
            }
            s.push(infix[i]);
        }
        
    }
    while (!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    cout<<postfix<<endl;
    
}