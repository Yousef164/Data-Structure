#include  <iostream>
using namespace std;
template<class tybe>
class   Linked_Stack
{
private:
    struct node
    {
        tybe item;
        node*next;
    };
    node*top;
public:
    Linked_Stack(): top(NULL){}
    void push(int val)
    {
        node*new_elm = new node;
        new_elm-> item =    val;
        new_elm-> next =    top;
        top = new_elm;
    }
    void pop()
    {
        if(top == NULL)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            node*cur =   top;
            top = top-> next;
            cur = cur-> next = NULL;
            delete cur;
        }
    }
    void get_top()
    {
        if(top == NULL)
            cout << "Stack is empty.\n";
            
        else
            cout << top-> item << '\n';
    }
    void print()
    {
        if(top == NULL)
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            node*cur = top;
            while(cur != NULL)
            {
                cout << cur-> item << ' ';
                cur = cur-> next;
            }
            cout << '\n';
        }
    }
};
int main()
{
    Linked_Stack <int>a;
    a.push (10);
    a.push (20);
    a.push (30);
    a.push (40);
    a.pop    ();
    a.get_top();
    a.print  ();
    return 0;
}
