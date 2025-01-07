#include  <iostream>
#include   <cassert>
#include   <cstring>
using namespace std;
const int ch =   26;
class Letter_Tree
{
private:
    struct Node
    {
        Node* let[ch];
        int    prifex;
        int       end;
        Node()
        {
            prifex = end = 0;
            memset(let, 0, sizeof let);
        }
    };
    Node*root;
public:
    Letter_Tree(): root(new Node()){}
    void insert(string s)
    {
        Node* cur = root;
        for(auto it : s)
        {
            int idx = it - 'a';
            if(cur-> let[idx] == 0)
            {
                cur-> let[idx] = new Node();
            }
            cur = cur-> let[idx];
            cur-> prifex++;
        }
        cur-> end++;
    }
    void word_exist(string s)
    {
        Node* cur = root;
        for(auto it : s)
        {
            int idx = it - 'a';
            if(cur-> let[idx] == 0)
            {
                cout << "This word is not exist.\n";
                return;
            }
            cur = cur-> let[idx];
        }
        cout << "This word is exist.\n";
    }
};
int main()
{
    Letter_Tree a;
    a.insert("youssef");
    a.insert("mohamed");
    a.word_exist("youssef");
    a.word_exist("sagfj");
    return 0;
}
