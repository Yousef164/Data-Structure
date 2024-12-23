#include <algorithm>
#include  <iostream>
#include   <cassert>
#include     <queue>
using namespace std;
template<class type>
class AVL
{
private:
    struct node
    {
        type   item;
        node*  left;
        node* right;
        int  height;
        node(type val)
        {
            item   =  val;
            left   = NULL;
            right  = NULL;
            height =    1;
        }
        void update_height()
        {
            int l = (left  != NULL? left->  height : 0);
            int r = (right != NULL? right-> height : 0);
            height= 1 + max(l, r);
        }
        int bfactor()
        {
            int l = (left  != NULL? left->  height : 0);
            int r = (right != NULL? right-> height : 0);
            return l - r;
        }
    };
    node*root;
    node* helper_push(node*temp, type val)
    {
        if(temp == NULL)
        {
            return new node(val);
        }
        else if(val > temp-> item)
        {
            temp-> right = helper_push(temp-> right, val);
        }
        else
        {
            temp->  left = helper_push(temp->  left, val);
        }
        temp-> update_height();
        temp = balance  (temp);
        return temp;
    }
    node* right_rotation(node* a)
    {
        node* b   =a-> left;
        a-> left  =b->right;
        b-> right = a;
        a-> update_height();
        b-> update_height();
        return b;
    }
    node* left_rotation(node* a)
    {
        node* b  =a-> right;
        a-> right= b-> left;
        b-> left = a;
        a-> update_height();
        b-> update_height();
        return b;
    }
    node* balance(node*temp)
    {
        if(temp-> bfactor() == -2)
        {
            if(temp-> right-> bfactor() == 1)
            {
                temp-> right = right_rotation(temp-> right);
            }
            temp = left_rotation(temp);
        }
        else if(temp-> bfactor() == 2)
        {
            if(temp-> left-> bfactor() == -1)
            {
                temp->  left  = left_rotation(temp-> left);
            }
            temp = right_rotation(temp);
        }
        return temp;
    }
    type helper_max(node* temp)
    {
        while(temp-> right != NULL)
        {
            temp = temp-> right;
        }
        return temp-> item;
    }
    type helper_min(node* temp)
    {
        while(temp-> left != NULL)
        {
            temp = temp-> left;
        }
        return temp-> item;
    }
    node* helper_pop(node* temp, type val)
    {
        if(temp == NULL)
        {
            return temp;
        }
        else if(val > temp-> item)
        {
            temp-> right = helper_pop(temp-> right, val);
        }
        else if(val < temp-> item)
        {
            temp-> left  = helper_pop(temp->  left, val);
        }
        else
        {
            if(temp-> left == NULL)
            {
                node*cur = temp-> right;
                delete temp;
                return  cur;
            }
            else if(temp-> right == NULL)
            {
                node*cur = temp-> left;
                delete temp;
                return  cur;
            }
            else
            {
                type maxval = helper_max(temp-> left);
                temp-> item = maxval;
                temp-> left = helper_pop(temp-> left, maxval);
            }
        }
        temp-> update_height();
        return temp;
    }
    void helper_preorder(node* temp)
    {
        if(temp == NULL)
        {
            return;
        }
        cout << temp-> item << ' ';
        helper_preorder(temp->  left);
        helper_preorder(temp-> right);
    }
    void helper_inorder(node* temp)
    {
        if(temp == NULL)
        {
            return;
        }
        helper_inorder(temp->  left);
        cout << temp-> item << ' ';
        helper_inorder(temp-> right);
    }
    void helper_postorder(node* temp)
    {
        if(temp == NULL)
        {
            return;
        }
        helper_postorder(temp->  left);
        helper_postorder(temp-> right);
        cout << temp-> item << ' ';
    }
public:
    AVL(): root(NULL){}
    void push(type val)
    {
        if(root == NULL)
        {
            root = new node(val);
        }
        else
        {
            root = helper_push(root, val);
        }
    }
    void print_levels()
    {
        assert(root != NULL);
        queue <node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* cur = q.front();
            if(cur-> left != NULL)
            {
                q.push(cur-> left);
            }
            if(cur-> right != NULL)
            {
                q.push(cur-> right);
            }
            cout << cur-> item << ' ';
            q.pop();
        }
        cout << '\n';
    }
    void pop(type val)
    {
        assert(root != NULL);
        root = helper_pop(root, val);
    }
    void print_preorder()
    {
        assert(root !=  NULL);
        helper_preorder(root);
        cout << '\n';
    }
    void print_inorder()
    {
        assert(root != NULL);
        helper_inorder(root);
        cout << '\n';
    }
    void print_postorder()
    {
        assert(root  !=  NULL);
        helper_postorder(root);
        cout << '\n';
    }
    void get_max()
    {
        assert(root != NULL);
        cout << helper_max(root) << '\n';
    }
    void get_min()
    {
        assert(root != NULL);
        cout << helper_min(root) << '\n';
    }
};
int main()
{
    AVL <int> a;
    a.push (10);
    a.push (20);
    a.push (30);
    a.push (15);
    a.push (17);
    a.push (13);
    a.pop  (15);
    a.pop  (20);
    a.push (40);
    a.print_levels   ();
    a.print_preorder ();
    a.print_inorder  ();
    a.print_postorder();
    return 0;
}
