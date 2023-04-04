#include <iostream>

using namespace std;

typedef int Info;

struct Elem
{

    Elem* prev,
        * next;
    Info info;
};

Elem* first = NULL;
    Elem* last = NULL;


void enqueue(Elem*& first, Elem*& last, int value);
int odd_numbers(Elem* first);
Info dequeue(Elem*& first, Elem*& last);


int main()
{
    int amount;
    cout << "\n Enter the number of the list elements: "; cin >> amount;

    int num;
    for (int i = 0; i < amount; i++)
    {
        cout << "Enter the number to include to list: ";
        cin >> num;
        enqueue(first, last, num);
      
    }
   int rezult = odd_numbers(first);
   cout << "The list contains " << rezult << " odd numbers.\n";
    dequeue(first, last);

}

void enqueue(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem; // 1
    tmp->info = value; // 2
    tmp->next = NULL; // 3
    if (last != NULL)
        last->next = tmp; // 4
    tmp->prev = last; // 5
    last = tmp; // 6
    if (first == NULL)
        first = tmp; // 7
}

int odd_numbers(Elem* first)
{
    int count = 0;
    Elem* current = first;
    while (current != NULL)
    {
        if (current->info % 2 != 0)
        {
            count++;
        }
        current = current->next;
    }
    return count;
}

Info dequeue(Elem*& first, Elem*& last)
{
    Elem* tmp = first->next; // 1
    Info value = first->info; // 2
    delete first; // 3
    first = tmp; // 4
    if (first == NULL)
        last = NULL; // 5
    else
        first->prev = NULL; // 6
    return value; // 7
}




