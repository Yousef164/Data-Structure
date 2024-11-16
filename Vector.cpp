#include  <iostream>
#include   <cassert>
using namespace std;
class vector
{
private:
    int *arr{nullptr};
    int size      {0};
    int capacity   {};
public:
    vector (int cap) : capacity(cap)
    {
        if (capacity <= 0) 
            capacity = 1;
        arr = new int[capacity] {};
    }
    void double_vector()
    {
        capacity *= 2;
        int *arr1 = new int[capacity];
        for (int i = 0; i < size; i++)
            arr1[i] = arr[i];
        swap(arr, arr1);
        delete[]   arr1;
    }
    void push_back(int value)
    {
        if(size == capacity - 1)
            double_vector();
        arr[size++] = value;
    }
    void insert (int index, int value)
    {
        assert(index >= 0 && index < size);
        if(size == capacity - 1)
            double_vector();
        for (int i = size - 1; i >= index; i--)
            arr[i + 1] = arr[i];
        arr[index] = value;
        size++;
    }
    void pop_back()
    {
        arr[--size] = INT_MIN;
    }
    int getval (int index)
    {
        return arr[index];
    }
};
int main()
{
    int n = 3;
    vector x(n);
    x.push_back(10);
    x.push_back(11);
    x.push_back(13);
    x.pop_back   ();
    x.push_back (9);
    x.insert (0, 5);
    x.insert (2, 6);
    x.pop_back();

    for (int i = 0; i < 10; i++)
        cout << x.getval(i) << ' ';
}
