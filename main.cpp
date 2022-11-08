#include <iostream>

using namespace std;

/*
задача: вставить с

(ук. 1): элемент a
	|
	V																						tmp
(ук. 2): элемент b		-		-		-		-	> 	(ук. 4): элемент c
																									|

(ук. 3): элемент d		<_		_		_			_			_		_	|
	|
  V
  NULL

*/

struct Node
{
    char val; // Значение элемента множества
    Node *next_node; // Указатель на след. элемент множества
};

Node clear_set = {0, nullptr}; // Пустое множество

void add_to_set(char val, Node *head);
void print_set(Node *head);

int main()
{

    Node *a = new Node;
    *a = clear_set;

    add_to_set('a', a);
    add_to_set('b', a);
    add_to_set('d', a);

    add_to_set('c', a);
    add_to_set('f', a);

    print_set(a);

    return 0;
}

void print_set(Node *head)
{
    while (head != nullptr)
    {
        if (head -> val != 0)
            cout << head -> val << " -> ";
        head = head -> next_node;
    }
}

void add_to_set(char val, Node *head)
{
    while (!(head -> next_node == nullptr || head -> next_node -> val > val))
        head = head -> next_node;

    Node *tmp = new Node;
    tmp -> val = val;
    tmp -> next_node = head -> next_node;
    head -> next_node = tmp;
}
