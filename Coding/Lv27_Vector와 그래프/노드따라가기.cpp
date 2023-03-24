#include <iostream>
using namespace std;

struct Node
{
    char ch;
    Node *next;
};

Node *head;
Node *last;

void addNode(char ch)
{
    if (head == NULL)
    {
        head = new Node();
        head->ch = ch;
        last = head;
    }
    else
    {
        last->next = new Node();
        last = last->next;
        last->ch = ch;
    }
}

int main()
{
    int n;
    cin >> n;

    char ch = n - 11 + 'A';
    for (int i = 0; i < 4; i++)
    {
        addNode(ch);
        ch++;
    }

    Node *p;
    for (p = head; p != NULL; p = p->next)
    {
        cout << p->ch;
    }

    return 0;
}