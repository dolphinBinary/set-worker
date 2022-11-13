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

Node empty_set = {0, nullptr}; // Пустое множество

void add_to_set(char val, Node* head);
void print_set(Node* head);
void delete_from_set(Node* head, char elem);
void delete_set(Node* head);
Node* unite_sets(Node* set1, Node* set2);
Node* common_in_sets(Node* set1, Node* set2);

int main()
{
    Node* a = new Node;
    Node* b = new Node;
    Node* a_unite_b = new Node;
    Node* a_common_b = new Node;

    *a = empty_set;
    *b = empty_set;

    add_to_set('a', a);
    add_to_set('b', a);
    add_to_set('c', a);
    add_to_set('f', a);

    add_to_set('b', b);
    add_to_set('e', b);
    add_to_set('f', b);
    add_to_set('z', b);
    delete_from_set(b, 'z');

    a_unite_b = unite_sets(a, b);
    a_common_b = common_in_sets(a, b);

    print_set(a);
    print_set(b);
    print_set(a_unite_b);
    print_set(a_common_b);

    delete_set(a);
    delete_set(b);
    delete_set(a_common_b);
    delete_set(a_unite_b);
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

void delete_from_set(Node* head, char elem)
{
    while (head -> next_node != nullptr)
    {
        if (head->next_node->val == elem)
        {
            if (head->next_node->next_node == nullptr)
            {
                delete head->next_node;
                head->next_node = nullptr;
            }
            else
            {
                Node *tmp = head->next_node;
                head->next_node = head->next_node->next_node;
                delete tmp;
            }
            return;
        }
        head = head->next_node;
    }
}

Node* common_in_sets(Node* set1, Node* set2)
{
    Node* ans = new Node;
    *ans = empty_set;

    if (set1->val > set2->val)
    {
        Node* tmp = set1;
        set1 = set2;
        set2 = tmp;
    }

    while (set1 != nullptr && set2 != nullptr)
    {
        if (set1->val > set2->val)
        {
            set2 = set2->next_node;
        }
        else

        if (set1->val < set2->val)
        {
            set1 = set1->next_node;
        }
        else
        {
            add_to_set(set1->val, ans);
            set1 = set1->next_node;
            set2 = set2->next_node;
        }
    }
    return ans;
}

Node* unite_sets(Node* set1, Node* set2)
{
    Node* ans = new Node;
    *ans = empty_set;

    // set1 <= set2!

    if (set1->val > set2->val)
    {
        Node* tmp = set1;
        set1 = set2;
        set2 = tmp;
    }

    while ((set1 != nullptr) && (set2 != nullptr))
    {
        if (set1->val < set2->val)
        {
            add_to_set(set1->val, ans);
            set1 = set1->next_node;
        }
        else

        if (set1->val == set2->val)
        {
            add_to_set(set1->val, ans);
            set1 = set1->next_node;
            set2 = set2->next_node;
        }

        else
        {
            add_to_set(set2->val, ans);
            set2 = set2->next_node;
        }
    }

    // считаем, что элементы остались в set1.
    if (set2 != nullptr)
    {
        Node* tmp = set1;
        set1 = set2;
        set2 = tmp;
    }

    while (set1 != nullptr)
    {
        add_to_set(set1->val, ans);
        set1 = set1->next_node;
    }

    return ans;
}

void delete_set(Node* head)
{
    Node* tmp;
    while (head->next_node != nullptr)
    {
        tmp = head->next_node;
        delete head;
        head = tmp;
    }
}
