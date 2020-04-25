#include <iostream>
#define null NULL

using namespace std;

template<typename T>
class List
{
private:
    struct Node
    {
        T* element;
        Node* next;
        Node* previous;
    };
    Node* first;
    Node* last;
    int length;
public:
    List<T>()
    {
        first = null;
        last = null;
        length = 0;
    }

    int Length()const
    {
        return length;
    }

    void Add(T& element)
    {
        Node* node = new Node;
        node->element = &element;
        node->next = null;
        node->previous = null;
        if(first == null)
        {
            first = node;
            last = node;
            length = 1;
            return;
        }
        last->next = node;
        node->previous = last;
        last = node;
        length += 1;
    }

    void Remove(T& element)
    {
        Node* current = first;
        for(int i = 0; i < length; i++)
        {
            if(current->element == &element)
            {
                RemoveAt(i);
                break;
            }
            current = current->next;
        }
    }

    void RemoveAt(int index)
    {
        if(index < 0 || index >= length)
            return;
        Node* temp;
        if(index == 0)
        {
            temp = first;
            first = first->next;
            if(length == 1)
            {
                last = null;
            }
        }
        else if(index == length - 1)
        {
            temp = last;
            last = last->previous;
            last->next = null;
        }
        else
        {
            if(index < length / 2)
            {
                temp = first;
                for(int i = 0; i < index; i++)
                {
                    temp = temp->next;
                }
            }
            else
            {
                temp = last;
                for(int i = length - 1; i > index; i--)
                {
                    temp = temp->previous;
                }
            }
            temp->previous->next = temp->next;
            temp->next->previous = temp->previous;
        }
        length -= 1;
        delete temp;

    }

    T& operator[](int index)
    {
        if(index < 0 || index >= length)
        {
            cout << "\n**************************************\nERROR ACCESING ELEMENT WITH INDEX " << index << "\n**************************************";
        }
        Node* temp;
        if(index < length / 2)
        {
            temp = first;
            for(int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }

        else
        {
            temp = last;
            for(int i = length - 1; i > index; i--)
            {
                temp = temp->previous;
            }
        }
        return *(temp->element);
    }
};

int main()
{
    return 0;
}

    /*
    Int broj1(1);
    Int broj2(2);
    Int broj3(3);
    Int broj4(4);

    List<Int> brojevi;

    brojevi.Add(broj1);
    brojevi.Add(broj2);
    brojevi.Add(broj3);

    cout << brojevi[0].value << endl;
    cout << brojevi[1].value << endl;
    cout << brojevi[2].value << endl << endl;

    brojevi.RemoveAt(1);

    cout << brojevi[0].value << endl;
    cout << brojevi[1].value << endl << endl;

    brojevi.Remove(broj1);

    cout << brojevi[0].value << endl << endl;

    brojevi.RemoveAt(0);

    brojevi.Add(broj1);
    brojevi.Add(broj3);
    brojevi.Add(broj4);
    brojevi.Add(broj2);

    cout << brojevi[0].value << endl;
    cout << brojevi[1].value << endl;
    cout << brojevi[2].value << endl;
    cout << brojevi[3].value << endl << endl;

    brojevi.Remove(broj4);

    cout << brojevi[0].value << endl;
    cout << brojevi[1].value << endl;
    cout << brojevi[2].value << endl << endl;

    brojevi.RemoveAt(2);

    cout << brojevi[0].value << endl;
    cout << brojevi[1].value << endl << endl;
    */
