#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int data ;
    node *left ;
    node *right ;    
};
class BST
{
    private:
        node *root ;
        node * searchValue(int,node *);
        node * deletionTraversal(int,node *);
    public:
        BST(){ root = NULL ;}
        void insert(int);
        void preOrder(node *);
        void inOrder(node *);
        void postOrder(node *);
        void Delete(int);
        node * searchItem(int);
        bool isEmpty();
        node *getRoot() { return root ;}
        ~BST();
};
BST::~BST()
{
    while(root!=NULL)
        Delete(root->data);
}
node * BST::searchValue(int value ,node *root)
{
    node *x = root;
    if(x==NULL)
        return NULL ;
    if(value==root->data)
        x = root ;
    else
    {
        if(value < root->data)
            x = searchValue(value,root->left);
        else
            x = searchValue(value,root->right);
    }
    return x ;
}
node * BST::searchItem(int value)
{
    node *x ;
    x = searchValue(value,root);
    return x ;
}
node * BST::deletionTraversal(int value , node *ptr)
{
    if(ptr==NULL)
        return NULL ;
    if(value < ptr->data)
        ptr->left = deletionTraversal(value,ptr->left);
    else if(value > ptr->data)
        ptr->right = deletionTraversal(value,ptr->right);
    else
    {
        if(ptr->left==NULL && ptr->right==NULL)
        {
            delete ptr ;
            return NULL;
        }
        if(ptr->left==NULL || ptr->right==NULL)
        {
            node *child ;
            if(ptr->left!=NULL)
                child = ptr->left ;
            else if(ptr->right!=NULL)
                child = ptr->right ;
            delete ptr ;
            return child ;
        }
        node *prev_max , *parent ;
        parent = ptr ;
        prev_max = ptr->left ; // previous maximum value is present in left sub-tree
        while(prev_max->right!=NULL) // going extreme right in left sub-tree to get previous max value
        {
            parent = prev_max ;     // parent node of previous max value to given value for deletion
            prev_max = prev_max->right ;
        }
        ptr->data = prev_max->data ;  // assigning value of previous max value in node of given value for deletion to replace it with previous max value
        if(parent->right == prev_max)
            parent->right = deletionTraversal(prev_max->data , prev_max); // deletion of the node
        else if(parent->left == prev_max)
            parent->left = deletionTraversal(prev_max->data , prev_max); // deletion of the node
    }
    return ptr ;
}
void BST::Delete(int value)
{
    root = deletionTraversal(value , root);
}
void BST::preOrder(node *root)
{
    if(root!=NULL)
    {
        cout << root->data << " " ;
        preOrder(root->left);
        preOrder(root->right);
    }
}
void BST::inOrder(node *root)
{
    if(root!=NULL)
    {
        inOrder(root->left);
        cout << root->data << " " ;
        inOrder(root->right);
    }
}
void BST::postOrder(node *root)
{
    if(root!=NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " " ;
    }
}
void BST::insert(int value)
{
    node *n = new node ;
    n->data = value ;
    n->left = n->right = NULL ;
    if(isEmpty())
        root = n ;
    else
    {
        node * x = root ;
        while(x->data!=n->data)
        {
            if(value < x->data)
            {
                if(x->left!=NULL)
                    x = x->left ;
                else
                {
                    x->left = n ;
                    break;  
                }
            }
            else
            {
                if(x->right!=NULL)
                    x = x->right ;
                else
                {
                    x->right = n ;
                    break;  
                }
            }
        }
        if(x->data==value)
            delete n ;
    }
}
bool BST::isEmpty()
{
    if(root==NULL)
        return true ;
    return false ;
}
