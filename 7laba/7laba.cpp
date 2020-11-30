#include <iostream>

using namespace std;

template <class QType>
class Queue 
{
    template <class QType>
    class Node
    {
    public:
        Node* next;
        QType k;

        Node(QType k = QType(), Node* next = NULL)
        {
            this->k = k;
            this->next = next;
        }
    };
    int size;
    Node<QType> *b;
public:
    void Push(QType);
    int GetSize() { return size; };
    Node<QType>* Search(QType searc);
    Queue();
    void Delete(QType);
    QType& operator[](const int index);
    friend ostream& operator<< (ostream & out, const QType& qtype)
    {

    }
    friend ostream& operator<< (ostream& out, const Queue<QType>& qtype)
    {
        Node<QType>* c = qtype.b;
        while (c)
        {
            out << c->k;
            c = c->next;
        }
        return out;
    }
    friend bool operator == (const Queue<QType>& qtype1, const Queue<QType>& qtype2)
    {
        return (qtype1.size == qtype2.size);
    }
};

template <class QType>
Queue<QType>::Node<QType>* Queue <QType> :: Search(QType searc)
{
    if (this->b->k == searc)
        return b;
    Node<QType>* c = this->b;
    while (c->next)
        if (c->next->k == searc)
            return c->next;
    return NULL;
}

template <class QType>
Queue <QType> ::Queue()
{
    size = 0;
    b = NULL;
}

template <class QType>
void Queue<QType>:: Push(QType n)
{
    if (!b)
        b = new Node<QType>(n);
    else
    {
        Node<QType>* c = new Node<QType>(n);
        c->next = b;
        b = c;
    }
    size++;
}

template <class QType>
void Queue<QType>::Delete(QType n)
{
    if (b->k == n)
    {
        Node<QType>* d = this->b;
        b = d->next;
        delete[] d;
        size--;
    }
    else
    {
        Node<QType>* c = this->b;
        while (c->next)
        {
            if (c->next->k == n)
            {
                Node<QType>* d = c->next;
                c->next = d->next;
                delete[] d;
                size--;
            }
        }
    }
}

template <class QType>
QType& Queue<QType>::operator[](const int index)
{
    Node<QType> *c = this->b;
    int in = 0;
    while (c)
    {
        if (in == index)
            return c->k;
        c = c->next;
        in++;
    }
}

int main()
{
    setlocale(LC_ALL, "rus");
    Queue<int> b;
    b.Push(6);
    b.Push(5);
    b.Search(6);
    b.Delete(6);
    cout << b;
    cout << b[0];
    Queue<int> b2;
    b2.Push(5);
    if (b == b2)
        cout << "yes";
    else
        cout << "no";
    system("pause");
    return 0;
}

