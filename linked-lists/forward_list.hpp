#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <iostream>
#include <string>

struct Element {
    int      data;
    Element* next;
};

void print_list(std::string msg, Element* head) {
    std::cout << msg;

    Element* ptr = head;
    while (ptr) {
        std::cout << ptr->data << " -> ";
        ptr = ptr->next;
    }

    std::cout << "null" << std::endl;
}
void push(Element** head, int data) {
    Element* newElement = new Element();
    newElement->data    = data;
    newElement->next    = *head;
    *head               = newElement;
}

void zamena(Element*& head) {
    Element* ptr  = head;
    int      data = head->data;
    while (ptr->next) {
        ptr = ptr->next;
    }
    head->data = ptr->data;
    ptr->data  = data;
}

void user() {
    Element* head = NULL;
    int      ammount, x;
    std::cout << "Please enter ammount of elements in your list: ";
    std::cin >> ammount;

    for (int i = 0; i < ammount; i++) {
        std::cin >> x;
        push(&head, x);
    }
    print_list("Original linked list: ", head);
    zamena(head);
    print_list("Reversed linked list: ", head);
}

int main() {
    user();
}

#endif  // FORWARD_LIST_HPP
