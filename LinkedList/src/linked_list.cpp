#include <iostream>
#include "LinkedList/linked_list.h"
    
LinkedList::LinkedList()
{
    head_ = NULL;
}

void LinkedList::InsertFront(const int& value)
{
    Node* new_head = new Node();
    
    new_head->value = value;
    
    if(head_ == NULL)
    {
        head_ = new_head;    
    }
    else
    {
        new_head->next = head_;
        head_ = new_head;
    }
}

bool LinkedList::InsertMiddle(const int& value, const unsigned int& index)
{
    int i = 0;
    Node* current;
    Node* prev;
    Node* new_node = new Node();
    new_node->value = value;

    if(index < 1)
    {
        return false;
    }

    current = head_;
    
    while(current != NULL && i < index)
    {
        prev = current;
        current = current->next;
        i++;
    }

    if(current == NULL)
    {
        return false;
    }

    prev->next = new_node;
    new_node->next = current;

    return true;
}

void LinkedList::InsertEnd(const int& value)
{
    Node* new_node = new Node();
    new_node->value = value;

    Node* current = head_;
    
    if(head_ == NULL)
    {
        head_ = new_node;
    }
    else
    {
        while(current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
    }
}

void LinkedList::DeleteNodesByValue(const int& value)
{
    Node* prev;
    Node* current;

    while(head_ != NULL && head_->value == value)
    {
        Node* temp_head = head_->next;
        delete head_;
        head_ = temp_head;
    }

    current = head_;

    while(current != NULL)
    {
        if(current->value != value)
        {
            prev = current;
            current = current->next;
        }
        else
        {
            prev->next = current->next;
            delete current;
            current = current->next;
        }
    }
}

bool LinkedList::DeleteNodeByIndex(const unsigned int& index)
{
    int i = 0;
    Node* current;
    Node* prev;

    if(index == 0)
    {
        Node* temp_head = head_->next;
        delete head_;
        head_ = temp_head;
        return true;
    }

    current = head_;
    
    while(current != NULL && i < index)
    {
        prev = current;
        current = current->next;
        i++;
    }

    if(current == NULL)
    {
        return false;
    }

    prev->next = current->next;
    delete current;
    return true;
}

void LinkedList::Display() 
{
    Node* current = head_;

    while(current != NULL)
    {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "X" << std::endl;
}

int main()
{
    LinkedList list;
    list.InsertFront(4);
    list.Display();
    list.InsertFront(1);
    list.Display();
    list.InsertMiddle(2, 1);
    list.Display();
    list.InsertEnd(5);
    list.Display();
    list.InsertFront(0);
    list.Display();
    list.InsertMiddle(3, 3);
    list.Display();
    list.InsertFront(0);
    list.Display();
    list.DeleteNodesByValue(0);
    list.Display();
    list.DeleteNodeByIndex(3);
    list.Display();
    return 0;
}