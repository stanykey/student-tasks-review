#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
struct Element {
    int      data;
    Element* next;
    Element* prev;
};

void pop(Element*& start) {
    if (start == nullptr) std::cout << "The list is empty" << std::endl;
    else {
        Element* p      = start->next;
        int      result = p->data;
        start->next     = p->next;
        delete p;
    }
}

void delete_list(Element*& list) {
    if (list == nullptr) std::cout << "The list is empty" << std::endl;
    else {
        while (list != list->next) pop(list);
        delete list;
        list = nullptr;
    }
}

void push(Element** start, int data) {
    if (*start == nullptr) {
        Element* new_node = new Element;
        new_node->data    = data;
        new_node->next = new_node->prev = new_node;
        *start                          = new_node;
        return;
    }

    Element* last     = (*start)->prev;
    Element* new_node = new Element;
    new_node->data    = data;
    new_node->next    = *start;
    (*start)->prev    = new_node;
    new_node->prev    = last;
    last->next        = new_node;
}

void output(struct Element* start) {
    Element* temp = start;
    Element* last = start->prev;
    temp          = last;
    std::cout << "List: ";
    while (temp->prev != last) {
        std::cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    std::cout << temp->data << std::endl;
}

void swap(struct Element* start, int current, int amount) {
    Element* tmp = start;
    for (int i = 0; i < amount; i++) {
        tmp = tmp->prev;

        if (tmp->data == current) {
            int left, right;
            tmp       = tmp->prev;
            left      = tmp->data;
            tmp       = tmp->next;
            tmp       = tmp->next;
            right     = tmp->data;
            tmp->data = left;
            tmp       = tmp->prev;
            tmp       = tmp->prev;
            tmp->data = right;
        }
    }
}

void input(struct Element** start, int amount) {
    for (int i = 0; i < amount; i++) {
        int element;
        std::cout << "Enter new element: ";
        std::cin >> element;
        push(start, element);
    }
}

void user() {
    int      amount, current;
    Element* start = nullptr;

    std::cout << "Enter amount elements: ";
    std::cin >> amount;

    input(&start, amount);
    output(start);

    std::cout << "Enter current: ";
    std::cin >> current;

    swap(start, current, amount);
    output(start);
    delete_list(start);
}

int main() {
    user();
}

#endif  // LIST_HPP
