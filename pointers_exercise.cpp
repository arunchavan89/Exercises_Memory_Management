#include <iostream>
#include <assert.h>

template <class T>
class List{
public:
    List();
    ~List();
    void push_back(T value);
    void push_front(T value);
    T pop_front();
    T pop_back();
    int Size()const;

private:
    struct Node
    {
        T s_value;
        Node *s_previous;
        Node *s_next;
        Node(T val, Node *previous, Node *next) :s_value(val), s_previous(previous), s_next(next){}
    };

    Node *m_head;
    Node *m_tail;
};

//constructor initialization
template <class T>
List<T>::List() : m_head(nullptr), m_tail(nullptr){}

//destructor: deleting all assigned memory
template <class T>
List<T>::~List()
{
    while (m_head)
    {
        Node *temp = m_head;
        m_head = m_head->s_next; //update m_head
        delete temp;  //delete memory

    }
}

//push a new value to tail
template <class T>
void List<T>::push_back(T value)
{
    m_tail = new Node(value, m_tail, nullptr);
    if (m_head == nullptr)
    {
        m_head = m_tail;
    }
    else
    {
        m_tail->s_previous->s_next = m_tail;
    }
}

//push a new value to head
template <class T>
void List<T>::push_front(T value)
{
    m_head = new Node(value, nullptr, m_head);
    if (m_tail == nullptr)
    {
        m_tail = m_head;
    }
    else
    {
        m_head->s_next->s_previous = m_head;
    }
}

//pop the element in front
template <class T>
T List<T>::pop_front()
{
    assert(m_head != nullptr);
    T value;
    Node *temp(m_head);
    value = m_head->s_value;
    m_head = m_head->s_next; //update head
    if (m_head)
    {
        m_head->s_previous = nullptr;
    }
    else
    {
        m_tail = nullptr;
    }
    delete temp;
    return value;
}

//pop the element in back
template <class T>
T List<T>::pop_back()
{
    assert(m_tail != nullptr);
    T value;
    Node *temp(m_tail);
    value = m_tail->s_value;
    m_tail = m_tail->s_previous; //update head
    if (m_tail)
    {
        m_tail->s_next = nullptr;
    }
    else
    {
        m_head = nullptr;
    }
    delete temp;
    return value;
}

// Declare List::Size()
template <class T> 
int List<T>::Size() const 
{
    int size = 0;
    Node *ptr(m_head);
    while (ptr != nullptr) {
        ptr = ptr->s_next;
        size++;
    }
    return size;
}

int main()
{
    List<int>list1;
    list1.push_back(9);
    list1.push_back(10);
    list1.push_front(8);
    assert(list1.Size() == 3);
    list1.pop_front();
    list1.pop_back();
    assert(list1.pop_front() == 9);
    assert(list1.Size() == 0);
    return 0;
}