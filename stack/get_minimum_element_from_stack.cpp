stack<int>stk; //supporting stack to store the minimum element till now

int _stack :: getMin()
{
    if(stk.empty()) return -1;
    return stk.top();
}

/*returns poped element from stack*/
int _stack ::pop()
{
    if(stk.empty()) return -1;
    stk.pop();
    int temp = s.top();
    s.pop();
    return temp;
}

/*push element x into the stack*/
void _stack::push(int x)
{
    s.push(x);
    if(stk.empty()) stk.push(x);
    else stk.push(min(getMin(), x));
}

//more optimized solution
/*
Push(x) : Inserts x at the top of stack. 
 


If stack is empty, insert x into the stack and make minEle equal to x.
If stack is not empty, compare x with minEle. Two cases arise:
If x is greater than or equal to minEle, simply insert x.
If x is less than minEle, insert (2*x – minEle) into the stack and make minEle equal to x. 
For example, let previous minEle was 3. Now we want to insert 2. We update minEle as 2 and insert 2*2 - 3 = 1 into the stack.


Pop() : Removes an element from top of stack. 
 


Remove element from top. Let the removed element be y. Two cases arise:
If y is greater than or equal to minEle, the minimum element in the stack is still minEle.
If y is less than minEle, the minimum element now becomes (2*minEle – y), so update (minEle = 2*minEle - y). 
This is where we retrieve previous minimum from current minimum and its value in stack. 
For example, let the element to be removed be 1 and minEle be 2. We remove 1 and update minEle as 2*2 - 1 = 3. 
*/