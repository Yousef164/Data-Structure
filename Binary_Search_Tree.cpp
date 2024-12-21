#include  <iostream>
#include   <cassert>
#include     <queue>
using namespace std;
template<class type>
class binary_search_tree
{
private:
    struct node
    {
        type  item;
        node* left;
        node*right;
        node(type val)
        {
            item =  val;
            left = NULL;
            right= NULL;
        }
    };
    node*root;
    void helper_push(node*temp, type val)
    {
        if(val > temp-> item)
        {
            if(temp-> right == NULL)
            {
                temp-> right = new node  (val);
            }
            else
            {
                helper_push(temp-> right, val);
            }
        }
        else
        {
            if(temp-> left == NULL)
            {
                temp-> left = new node  (val);
            }

            else
            {
                helper_push(temp-> left, val);
            }
        }
    }
    type helper_max(node*temp)
    {
        while(temp-> right != NULL)
        {
            temp = temp-> right;
        }
        return temp-> item;
    }
    type helper_min(node*temp)
    {
        while(temp-> left != NULL)
        {
            temp = temp-> left;
        }
        return temp-> item;
    }
    int helper_height(node*temp)
    {
        if(temp == NULL)
            return -1;
        int l = helper_height (temp-> left);
        int r = helper_height(temp-> right);
        return 1 + max(l, r);
    }
    void helper_preorder(node*temp)
    {
        if(temp == NULL)
            return;
        cout << temp-> item <<    ' ';
        helper_preorder(temp->  left);
        helper_preorder(temp-> right);
    }
    void helper_inorder(node*temp)
    {
        if(temp == NULL)
            return;
        helper_inorder(temp->   left);
        cout << temp-> item <<    ' ';
        helper_inorder(temp->  right);
    }
    void helper_postorder(node*temp)
    {
        if(temp == NULL)
            return;
        helper_postorder(temp->  left);
        helper_postorder(temp-> right);
        cout << temp-> item <<    ' ';
    }
    node* helper_pop(node*temp, type val)
    {
        if(val < temp-> item)
        {
            temp->left = helper_pop(temp-> left,  val);
        }
        else if(val > temp-> item)
        {
            temp->right= helper_pop(temp-> right, val);
        }
        else
        {
            if(temp-> left == NULL)
            {
                node*cur = temp-> right;
                delete temp;
                return cur;
            }
            else if(temp-> right == NULL)
            {
                node*cur = temp-> left;
                delete temp;
                return cur;
            }
            else
            {
                type maxval = helper_max  (temp-> left);
                temp-> item = maxval;
                temp-> left = helper_pop(temp-> left, maxval);
            }
        }
        return temp;
    }
public:
    binary_search_tree() : root(NULL){}
    void push(type val)
    {
        if(root == NULL)
        {
            root = new node  (val);
        }
        else
        {
            helper_push(root, val);
        }
    }
    type get_max()
    {
        assert    (root != NULL);
        return  helper_max(root);
    }
    type get_min()
    {
        assert    (root != NULL);
        return  helper_min(root);
    }
    int get_height()
    {
        assert(root != NULL);
        return helper_height(root);
    }
    void print_levels()
    {
        assert(root != NULL);
        queue <node*> q;
        q.push(root);
        while(!q.empty())
        {
            node* temp = q.front();
            if(temp->  left != NULL)
            {
                q.push(temp->  left);
            }
            if(temp-> right != NULL)
            {
                q.push(temp-> right);
            }
            cout << temp-> item << ' ';
            q.pop();
        }
        cout << '\n';
    }
    void print_preorder()
    {
        assert (root !=  NULL);
        helper_preorder (root);
        cout << '\n';
    }
    void print_inorder()
    {
        assert (root !=  NULL);
        helper_inorder  (root);
        cout << '\n';
    }
    void print_postorder()
    {
        assert (root  !=  NULL);
        helper_postorder (root);
        cout << '\n';
    }
    void pop(type val)
    {
        assert(root != NULL);
        root = helper_pop(root, val);
    }
};
int main()
{
    binary_search_tree <int> a;
    a.push(10);
    a.push (5);
    a.push (3);
    a.push (2);
    a.push (6);
    a.push (4);
    a.push(20);
    a.pop (10);
    cout << a.get_height() << '\n';
    a.print_levels   ();
    a.print_preorder ();
    a.print_inorder  ();
    a.print_postorder();
    return 0;
}
