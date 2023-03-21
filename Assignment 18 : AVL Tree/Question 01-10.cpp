#include<bits/stdc++.h>
using namespace std ;
struct node
{
    int data ;
    node *left ;
    node *right ;
    int height ;
};
class AVL
{
    private:
        node *root ;
        node * insertion(node *,int);
        node * deletion(node *,int);
    public:
        AVL();
        int balanceFactor(node *);
        node * getRoot();
        node * leftRotate(node *);
        node * rightRotate(node *);
        void insert(int);
        void Delete(int);
        void preOrder(node *);
        void inOrder(node *);
        void postOrder(node *);
        int height(node *);
        node * searchElement(int);
        ~AVL();
};
AVL::~AVL()
{
    while(root!=nullptr)
        Delete(root->data);
}
node * AVL::searchElement(int value)
{
    node *t = root ;
    while(t!=nullptr)
    {
        if(value==t->data)
            return t ;
        if(value > t->data)
            t = t->right ;
        else if(value < t->data)
            t = t->left ;
    }
    return t ;
}
void AVL::postOrder(node *ptr)
{
    if(ptr!=nullptr)
    {
        postOrder(ptr->left);
        postOrder(ptr->right);
        cout << ptr->data << " " ;
    }
}
void AVL::inOrder(node *ptr)
{
    if(ptr!=nullptr)
    {
        inOrder(ptr->left);
        cout << ptr->data << " " ;
        inOrder(ptr->right);
    }
}
void AVL::preOrder(node *ptr)
{
    if(ptr!=nullptr)
    {
        cout << ptr->data << " " ;
        preOrder(ptr->left);
        preOrder(ptr->right);
    }
}
node * AVL::insertion(node *ptr,int value)
{
    node *n ;
    if(ptr==nullptr)
    {
        n = new node ;
        n->data = value ;
        n->right = nullptr ;
        n->left = nullptr ;
        n->height = 1 ;
        return n ;
    }
    if(value > ptr->data)
        ptr->right = insertion(ptr->right,value);
    else if(value < ptr->data)
        ptr->left = insertion(ptr->left,value);
    else
        return ptr ;
    
    ptr->height = max(height(ptr->left) , height(ptr->right)) + 1 ;                         
    
    int b_factor = balanceFactor(ptr);                       // Balance factor determining

    if(b_factor > 1 && value < ptr->left->data)              // Left Left Rotation Case
        return rightRotate(ptr);
    
    if(b_factor < -1 && value > ptr->right->data)            // Right Right Rotation Case
        return leftRotate(ptr);
    
    if(b_factor > 1 && value > ptr->left->data)             // Left Right Rotation Case
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }
    
    if(b_factor < -1 && value < ptr->right->data)           // Right Left Rotation Case 
    {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr ;
}
void AVL::insert(int value)
{
    root = insertion(root,value);
}
void AVL::Delete(int value)
{
    root = deletion(root,value);
}
node * AVL::deletion(node *ptr , int value)
{
    if(ptr==nullptr)
        return nullptr;
    if(value > ptr->data)
        ptr->right = deletion(ptr->right,value);
    else if(value < ptr->data)
        ptr->left = deletion(ptr->left,value);
    else
    {
        if(ptr->left==nullptr && ptr->right==nullptr)
        {
            delete ptr ;
            return nullptr ;
        }
        else if(ptr->left==nullptr || ptr->right==nullptr)
        {
            node *temp ;
            if(ptr->left)
                temp = ptr->left ;
            else if(ptr->right)
                temp = ptr->right ;
            delete ptr ;
            return temp ;
        }
        else
        {
            node *pred = ptr->left ;
            node *parent_pred = ptr ;
            while(pred->right!=nullptr)
            {
                parent_pred = pred ;
                pred = pred->right ;
            }
            ptr->data = pred->data ;
            if(parent_pred->right==pred)
                parent_pred->right = deletion(pred,value);
            else if(parent_pred->left==pred)
                parent_pred->left = deletion(pred,value);
        }
    }
    ptr->height = max(height(ptr->left) , height(ptr->right)) + 1 ;                         
    
    int b_factor = balanceFactor(ptr);                       // Balance factor determining

    if(b_factor > 1 && balanceFactor(ptr->left) >= 0)              // Left Left Rotation Case
        return rightRotate(ptr);
    
    if(b_factor > 1 && balanceFactor(ptr->left) < 0)              // Left Right Rotation Case
    {
        ptr->left = leftRotate(ptr->left);
        return rightRotate(ptr);
    }
    
    if(b_factor < -1 && balanceFactor(ptr->right) <= 0)            // Right Right Rotation Case
        return leftRotate(ptr);
    
    if(b_factor < -1 && balanceFactor(ptr->right) > 0)           // Right Left Rotation Case 
    {
        ptr->right = rightRotate(ptr->right);
        return leftRotate(ptr);
    }
    return ptr ; 
}
node * AVL::rightRotate(node *A)
{
    node *B = A->left ;
    node *temp = B->right ;
    B->right = A ;
    A->left = temp ;
    A->height = max(height(A->left) , height(A->right)) + 1 ;
    B->height = max(height(B->left) , height(B->right)) + 1 ;
    return B ;
}
node * AVL::leftRotate(node *A)
{
    node *B = A->right ;
    node *temp = B->left ;
    B->left = A ;  
    A->right = temp ;
    A->height = max(height(A->left) , height(A->right)) + 1 ;
    B->height = max(height(B->left) , height(B->right)) + 1 ;
    return B ;
}
node * AVL::getRoot()
{
    return root ;
}
int AVL::balanceFactor(node *ptr)
{
    if(ptr==nullptr)
        return 0 ;
    int b_factor = height(ptr->left) - height(ptr->right) ;
    return b_factor ;
}
int AVL::height(node *ptr)
{
    if(ptr==nullptr)
        return 0 ;
    return ptr->height ;
}
AVL::AVL()
{
    root = nullptr ;
}
