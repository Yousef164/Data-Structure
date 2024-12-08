#include  <iostream>
#include   <cassert>
using namespace std;
template<class tybe>
class linked_queue
{
private:
    struct node
    {
        tybe item;
        node*next;
    };
    node*first;
    node* last;
    int length;
public:
    linked_queue()
    {
        last = NULL;
        first= NULL;
        length =  0;
    }
    void push(tybe val)
    {
        node*new_elm = new node;
        new_elm-> item = val;
        if(length == 0)
        {
            last = new_elm;
            first= new_elm;
            new_elm-> next = NULL;
        }
        else
        {
            last-> next = new_elm;
            last = new_elm;
            last-> next =    NULL;
        }
        length++;
    }
    void pop()
    {
        if(length == 0)
            cout << "queue is empty.\n";
        
        else
        {
            node*cur = first;
            first = first-> next;
            delete cur;
            length--;
        }
    }
    void front()
    {
        if(length == 0)
            cout << "queue is empty.";

        else 
            cout << first-> item;

        cout << '\n';
    }
    void back()
    {
        if(length == 0)
            cout << "queue is empty.";
        
        else
            cout << last-> item;
        
        cout << '\n';
    }
    void print()
    {
        if(length == 0)
            cout << "queue is empty.";
        else
        {
            node*cur = first;
            while(cur != NULL)
            {
                cout << cur-> item << ' ';
                cur = cur-> next;
            }
        }
        cout << '\n';
    }
};
int main()
{
    linked_queue <int> a;
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.front ();
    a.back  ();
    a.print ();   
    return   0;
}
