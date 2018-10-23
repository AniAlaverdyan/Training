#include <iostream>

struct node
{
    private:
        int number;  
        node *next;
    
    private:
	bool isEmpty(node *head);
        void insertFirstElement(node *&head, node *&last, int number);

    public:
        void insertElement(node *&head, node *&last, int number);
        void showList(node *current);
        void reverse(node *&head);
};

bool node::isEmpty(node *head)
{
    if(head == NULL)
        return true;
    else
        return false;
}

void node::insertFirstElement(node *&head, node *&last, int number)
{
    node *temp = new node;
    temp -> number = number;
    temp -> next = NULL;
    head = temp;
    last = temp;
}

void node::insertElement(node *&head, node *&last, int number)
{
    
    if(isEmpty(head))
        insertFirstElement(head, last, number);
    else
    {
        node *temp = new node;
        temp -> number = number;
        temp -> next = NULL;
        last -> next = temp;
        last = temp;
    }
}

void node::showList(node *current)
{
    if(isEmpty(current))
        std::cout << "The list is empty\n";
    else
    {
        
        while(current != NULL)
        {
            std::cout << current -> number << std::endl;
            current = current -> next;
        }
    }
}

void node::reverse(node *&head)
{
    struct node *next_ptr = NULL;
    struct node *temp_ptr = head;
    struct node *prev_ptr = NULL;
    
    while(temp_ptr != NULL)
    {
         next_ptr = temp_ptr -> next;
	 temp_ptr -> next = prev_ptr;
         prev_ptr = temp_ptr;
	 temp_ptr = next_ptr; 
    }
    head = prev_ptr;
        
}

int main()
{
    node *head = NULL;
    node *last = NULL;
        
    insertElement(head, last, 1);
    insertElement(head, last, 2);
    insertElement(head, last, 3);
    insertElement(head, last, 4);

    std::cout << "The initial list is: " << std::endl;
    showList(head);
    reverse(head);
    std::cout << "The reversed list is: " << std::endl;
    showList(head);
    return 0;
}
