#include  <iostream>
#include   <cassert>
#include   <cstring>
using namespace std;
const int bf =   10;
class Hashing
{
private:
    struct Node
    {
        Node*next;
        int  item;
        Node(int val)
        {
            item =  val;
            next = NULL;
        }
    };
    Node*root[bf];
public:
    Hashing()
    {
        memset(root, 0, sizeof root);
    }
    void push(int val)
    {
        int idx = val % bf;
        if(root[idx] == 0)
        {
            root[idx] = new Node(val);
        }
        else
        {
            Node*cur = root[idx];
            while(cur-> next != NULL)
            {
                cur = cur-> next;
            }
            cur-> next = new Node(val);
        }
    }
    void pop(int val)
    {
        int idx = val % bf;
        assert(root[idx] != 0);
        if(root[idx]-> item == val)
        {
            Node*cur = root[idx];
            root[idx] = cur-> next;
            delete cur;
        }
        else
        {
            Node*cur =  root[idx];
            Node*temp= cur-> next;
            while(temp != NULL)
            {
                if(temp-> item == val)
                {
                    break;
                }
                cur = temp;
                temp = temp-> next;
            }
            if(temp == NULL)
            {
                cout << "This val is not exist.\n";
            }
            else
            {
                cur-> next = temp-> next;
                delete temp;
            }
        }
    }
    void search(int val)
    {
        int idx = val % bf;
        Node*cur = root[idx];
        while(cur != NULL)
        {
            if(cur-> item == val)
            {
                cout << "This val is exist.\n";
                break;
            }
            cur = cur-> next;
        }
        if(cur == NULL)
        {
            cout << "This val is not exist.\n";
        }
    }
};
int main()
{
    Hashing a;
    a.push(10);
    a.push(3);
    a.push(13);
    a.push(23);
    a.push(6);
    a.pop(6);
    a.search(6);
    a.search(23);
    return 0;
}
