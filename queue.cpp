#include  <iostream>
#include   <cassert>
using namespace std;
template<class type>
class queue
{
private:
    int    first;
    int     last;
    int   length;
    int capacity;
    type*arr{nullptr};
public:
    queue(int l)
    {
        if(l < 1) l = 100;
        first    = 0;
        last     =-1;
        length   = 0;
        capacity = l;
        arr = new type[capacity] {};
    }
    bool isEmpty()
    {
        return length == 0;
    }
    void push(type val)
    {
        if(length == capacity)
        {
            cout << "array is full....";
            print();
        }
        else
        {
            last = (last + 1) % capacity;
            arr[last] = val;
            length++;
        }
    }
    void pop()
    {
        if(isEmpty())
        {
            cout << "array is empty.\n";
        }
        else
        {
            arr[first] = 0;
            first = (first + 1) % capacity;
            length--;
        }
    }
    void getfront()
    {
        if(isEmpty())
        {
            cout << "array is empty.\n";
        }
        else
            cout << arr[first] << '\n';
    }
    void getback()
    {
        if(isEmpty())
        {
            cout << "array is empty.\n";
        }
        else
            cout << arr[last] << '\n';
    }
    void print()
    {
        if(isEmpty())
        {
            cout << "array is empty.\n";
        }
        else
        {
            for(int i = first; i != last; i = (i + 1)% capacity)
            {
                cout << arr[i] << ' ';
            }
            cout << arr[last] << '\n';
        }
    }
};
int main()
{
    queue <int> a(5);
    a.push(10);
    a.push(20);
    a.push(30);
    a.push(40);
    a.push(50);
    a.print ();
    return   0;
}
