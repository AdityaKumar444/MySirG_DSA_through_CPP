#include"arrayADT.cpp"
class Stack : private Array
{
    public:
        Stack(int cap) : Array(cap){}
        Stack(const Stack &s):Array(s){}
        void operator=(Stack &s)
        {
            Array::operator=(s);   
        }
        void push(int);
        void pop();
        int peek();
        bool checkOverflow();
        bool checkUnderflow();
        int capacity();
        ~Stack(){}
};
void Stack::push(int data)
{
    if(!fullOrNot())
        append(data);
}
void Stack::pop()
{
    if(!emptyOrNot())
        Delete(count()-1);
}
int Stack::peek()
{
    if(!emptyOrNot())
        return getElement(count()-1);
    return getElement(count()-1);
}
bool Stack::checkOverflow()
{
    return fullOrNot() ;
}
bool Stack::checkUnderflow()
{
    return emptyOrNot();
}
int Stack::capacity()
{
    return getCapacity();
}
void reverse(Stack &s1)
{
    Stack s2(s1.capacity()) ;
    while(!s1.checkUnderflow())
    {
        s2.push(s1.peek());
        s1.pop();
    }
    s1 = s2 ;
}
void pushStack(Stack &s , Stack &min , int data)
{
    s.push(data);
    if(min.checkUnderflow())
        min.push(data);
    else
    {
        if(data > min.peek())
            min.push(min.peek());
        else
            min.push(data);
    }
}
void popStack(Stack &s , Stack &min)
{
    s.pop();
    min.pop();
}
