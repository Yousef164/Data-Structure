#include  <iostream>
using namespace std;
template <class t>
class stack
{
private:
    t*arr{nullptr};
    int    top;
    int length;

public:
    stack(int l) 
    {
        top =   -1;
        length = l;
        arr = new t[length]{};
    }
    bool isempty()
    {
        return length == 0;
    }
    void push(t val)
    {
        if(top >= length - 1)
            cout << "Stack full.\n";
        else
            arr[++top] = val;
    }
    void pop()
    {
        if(isempty())
            cout << "Stack is empty.\n";
        else
        {
            arr[top] = 0;
            top--;
        }
    }
    void get_top()
    {
        if(isempty())
            cout << "Stack is empty.\n";
        else
            cout << arr[top];
    }
    void print()
    {
        if(isempty())
            cout << "Stack is empty.";
        else
            for(int i = 0; i <= top; i++)
                cout << arr[i] << ' ';
        cout << '\n';
    }
};
int main()
{
    stack <char> s(10);
    s.push('a');
    s.push('b');
    s.push('c');
    s.push('d');
    s.print();
    s.get_top();
    return 0;
}
