#include  <iostream>
#include   <cassert>
using namespace std;
class Doubly_Linked_List
{
private:
    struct node
    {
        int   item;
        node* left;
        node*right;
    };
    int length;
    node* last;
    node*first;
public:
    Doubly_Linked_List()
    {
        length=    0;
        first = NULL;
        last  = NULL;
    }
    void push_front(int elm)
    {
        node*new_elm = new node;
        new_elm-> item =    elm;
        if(length == 0)
        {
            last = new_elm;
            first= new_elm;
            new_elm-> right = NULL;
            new_elm-> left  = NULL;
        }
        else
        {
            new_elm-> right=   first;
            first-> left   = new_elm;
            new_elm-> left =    NULL;
            first = new_elm;
        }
        length++;
    }
    void push_back(int elm)
    {
        node*new_elm = new node;
        new_elm-> item =    elm;
        if(length == 0)
        {
            last = new_elm;
            first= new_elm;
            new_elm-> right = NULL;
            new_elm-> left  = NULL;
        }
        else
        {
            last-> right   = new_elm;
            new_elm-> left =    last;
            new_elm-> right=    NULL;
            last = new_elm;
        }
        length++;
    }
    void insert(int idx, int elm)
    {
        assert(idx >= 0 && idx <= length);
        node*new_elm = new node;
        new_elm-> item =    elm;
        if(idx == 0)
            push_front(elm);

        else if(idx == length)
            push_back(elm);

        else
        {
            node*cur = first;
            for(int i = 1; i < idx; i++)
                cur = cur-> right;

            new_elm-> left =         cur;
            new_elm-> right= cur-> right;
            cur-> right-> left = new_elm;
            cur -> right =       new_elm;
            length++;
        }
    }
    void pop_front()
    {
        assert(length > 0);
        if (length == 1)
        {
            delete first;
            first = NULL;
            last  = NULL;
        }
        else
        {
            node*cur =      first;
            first = first-> right;
            first-> left =   NULL;
            delete cur;
        }
        length--;
    }
    void pop_back()
    {
        assert(length > 0);
        if(length == 1)
        {
            delete first;
            first = NULL;
            last  = NULL;
        }
        else
        {
            node*cur     = last;
            last = last->  left;
            last-> right = NULL;
            delete cur;
        }
        length--;
    }
    void pop_elm(int elm)
    {
        assert(length > 0);
        node*cur =   first;
        while (cur != NULL)
        {
            if(cur-> item == elm)
                break;
            cur = cur-> right;
        }
        if(cur == NULL)
            cout <<"this element does not exist.\n";
        
        else if(cur-> right == NULL)
            pop_back();

        else if (cur-> left == NULL)
            pop_front();
        
        else
        {
            cur-> left-> right = cur-> right;
            cur-> right-> left = cur->  left;
            delete cur;
            length--  ;
        }
    }
    int search(int elm)
    {
        node*cur =  first;
        int pos  =      0;
        while(cur != NULL)
        {
            if(cur-> item == elm)
                return pos;

            cur = cur-> right;
            pos++;
        }
        return -1;
    }
    void print_reverse()
    {
        node*cur   = last;
        while(cur != NULL)
        {
            cout << cur-> item << ' ';
            cur = cur-> left;
        }
        cout << '\n';
    }
    void print()
    {
        node*cur =  first;
        while(cur != NULL)
        {
            cout << cur-> item << ' ';
            cur = cur-> right;
        }
        cout << '\n';
    }
};
int main()
{
    Doubly_Linked_List a;
    a.push_back  (30);
    a.push_front (20);
    a.push_back  (40);
    a.insert  (0, 10);
    a.print        ();
    a.print_reverse();
    a.pop_elm    (30);
    a.pop_back     ();
    a.pop_front    ();
    a.print        ();
    return 0;
}
