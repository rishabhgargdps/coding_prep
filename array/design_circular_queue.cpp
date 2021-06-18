class MyCircularQueue
{
public:
    vector<int> v;
    int front = 0, rear = 0, size = 0;
    //we use a vector to implement the circular queue
    MyCircularQueue(int k)
    {
        v.clear();
        while (k--)
        {
            v.push_back(-1);
        }
    }

    bool enQueue(int value)
    {
        if (isFull())
        {
            return false;
        }
        if (isEmpty())
        {
            front = rear = 0;
            v[rear] = value;
            size++;
            return true;
        }
        rear++;
        rear %= v.size();
        v[rear] = value;
        size++;
        return true;
    }

    bool deQueue()
    {
        if (!isEmpty())
        {
            v[front] = -1;
            front++;
            front %= v.size();
            size--;
            return true;
        }
        return false;
    }

    int Front()
    {
        return v[front];
    }

    int Rear()
    {
        return v[rear];
    }

    bool isEmpty()
    {
        return (size == 0);
    }

    bool isFull()
    {
        return (size == v.size());
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */