#include<iostream>
#include<stack>
using namespace std;

int excecuteOperation(char op,int op1,int op2)
{
    switch (op)
    {
    case '+':
        return op1+op2;
    case '-':
        return op1-op2;   
    case '*':
        return op1*op2;
    case '/':
        return op1/op2;
    default:
        return 0;
    }
}

bool isNumeric(char ch)
{
    if (ch>='0' && ch<='9')
    {
        return true;
    }
    return false;    
}

int main()
{
    string prefix;
    // cin>>prefix;
    getline(cin,prefix);

    stack<int> s;
    for (int i = 0; i < prefix.length(); i++)
    {
        if (prefix[i]==' ' || prefix[i]==',')
        {
            continue;
        }
        
        else if (prefix[i]=='+' || prefix[i]=='-' || prefix[i]=='*' || prefix[i]=='/')
        {
            int op2=s.top();
            s.pop();
            int op1=s.top();
            s.pop();
            int res=excecuteOperation(prefix[i],op1,op2);
            s.push(res);
        }
        else
        {
            int operand=0;
            while (i<prefix.length() && isNumeric(prefix[i]))
            {
                operand = operand*10 + (prefix[i]-'0');
                i++;
            }
            i--;
            s.push(operand);
        }
       
    }
    cout<<"The ans is:"<<s.top()<<endl;
    
}