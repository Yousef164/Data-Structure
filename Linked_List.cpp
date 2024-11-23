#include  <iostream>
#include   <cassert>
using namespace std;
class Linked_List
{
private:
    struct node
    {
        int item;
        node*next;
    };
    node*first;
    node* last;
    int lenght;
public:
    Linked_List()
    {
        lenght =    0;
        first  = NULL;
        last   = NULL;
    }
    void push_front(int elm)
    {
        node*new_elm = new node;
        new_elm-> item  =   elm;
        if (lenght == 0)
        {
            new_elm-> next = NULL;
            first = new_elm;
            last =  new_elm;  
        }
        else
        {
            new_elm-> next = first;
            first = new_elm;
        }
        lenght++;
    }
    void push_back(int elm)
    {
        node*new_elm = new node;
        new_elm-> item =    elm;
        new_elm-> next =   NULL;
        if (lenght == 0)
        {
            first = new_elm;
            last  = new_elm;    
        }
        else
        {
            last-> next = new_elm;
            last = new_elm; 
        }
        lenght++;
    }
    void insert(int idx, int elm)
    {
        assert(idx >= 0 && idx <= lenght);
        if (idx == 0)
            push_front(elm);
        
        else if (idx == lenght)
            push_back(elm);
        
        else
        {
            node*new_elm = new node;
            new_elm-> item =    elm;
            node*cur = first;
            for(int i = 0; i < idx - 1; i++)
            {
                cur = cur-> next;
            }
            new_elm-> next = cur-> next;
            cur-> next =        new_elm;
            lenght++;
        }
    }
    void pop_front()
    {
        assert  (lenght > 0);
        node*cur =     first;
        first = first-> next;
        if (lenght == 1)
            last = first;
        delete cur;
        lenght  --;
    }
    void pop_back()
    {
        assert(lenght > 0);
        if(lenght == 1)
        {
            node*cur = first;
            first = NULL;
            last  = NULL;
            delete   cur;
            lenght--;
        }
        else
        {
            node*cur = first;
            while(cur-> next != last)
            cur = cur-> next;
            
            last = cur;
            cur  =  cur-> next;
            delete cur;
            last-> next = NULL;
            lenght--;
        }
    }
    void pop_elm(int elm)
    {
        assert(lenght > 0);
        if(first-> item == elm)
            pop_front();
        else
        {
            node*cur = first-> next;
            node*prv = first;
            while(cur != NULL)
            {
                if(cur-> item == elm)
                    break;
                prv = cur;
                cur = cur-> next;
            }
            if(cur == NULL)
                cout <<"this element does not exist.\n";

            else
            {
                prv-> next = cur-> next;
                delete cur;
                lenght  --;
            }
        }
    }
    void reverse()
    {
        assert  (lenght > 0);
        node*cur, *prv, *pos;
        prv   = first;
        cur   = first;
        pos   =  NULL;
        first =  last;
        last  =   cur;
        while(cur != NULL)
        {
            prv = prv-> next;
            cur-> next = pos;
            pos = cur;
            cur = prv;
        }
    }
    int search(int elm)
    {
        node*cur =  first;
        int pos = 0;
        while(cur != NULL)
        {
            if(cur-> item == elm)
                return pos;

            cur = cur-> next;
            pos++;
        }
        return -1;
    }
    void print()
    {
        node*cur = first;
        while(cur != NULL)
        {
            cout << cur-> item << ' ';
            cur = cur-> next;
        }
        cout << '\n';
    }
};
int main()
{
    Linked_List   a;
    a.push_back (30);
    a.push_front(40);
    a.push_back (20);
    a.insert (3, 10);
    a.print       ();
    a.reverse     ();
    a.print       ();
    a.pop_back    ();
    a.pop_front   ();
    a.pop_elm   (20);
    a.print       ();
    return 0;
}
