#include  <iostream>
#include   <cassert>
using namespace std;
class heap
{
private:
    void heapify(int arr[], int s, int i)
    {
        int l = i * 2 + 1;
        int r = i * 2 + 2;
        int min = i;
        if(l < s && arr[l] > arr[min])
            min = l;
        if(r < s && arr[r] > arr[min])
            min = r;
        if(min != i)
        {
            swap(arr[min], arr[i]);
            heapify (arr, s, min);
        }
    }
public:
    void buildheap(int arr[], int s)
    {
        for(int i = s / 2 - 1; i >= 0; i--)
            heapify(arr, s, i);
    }
    void sortheap(int arr[], int s)
    {
        buildheap(arr, s);
        for(int i = s - 1; i >= 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }
};
int main()
{
    int size = 6;
    int arr[size] = {10, 60, 30, 50, 40, 20};
    heap a;
    a.sortheap(arr, size);
    for(int i = 0; i < size; i++)
        cout << arr[i] << ' ';
    
    return 0;
}
