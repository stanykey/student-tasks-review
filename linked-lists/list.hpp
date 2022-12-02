#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>


namespace list {
    struct node {
        int   data{0};
        node* next{nullptr};
        node* prev{nullptr};
    };

    void delete_list(node*& head) {
        while (head) {
            node* temp = head;
            head       = head->next;
            delete temp;
        }
        head = nullptr;
    }

    void push(node** start, int data) {
        if (*start == nullptr) {
            node* new_node = new node;
            new_node->data = data;
            new_node->next = new_node->prev = new_node;
            *start                          = new_node;
            return;
        }

        node* last     = (*start)->prev;
        node* new_node = new node;
        new_node->data = data;
        new_node->next = *start;
        (*start)->prev = new_node;
        new_node->prev = last;
        last->next     = new_node;
    }

    void pop(node*& start) {
        if (start == nullptr) std::cout << "The list is empty" << std::endl;
        else {
            node* p      = start->next;
            int   result = p->data;
            start->next  = p->next;
            delete p;
        }
    }

    void output(struct node* start) {
        node* temp = start;
        node* last = start->prev;
        temp       = last;
        std::cout << "List: ";
        while (temp->prev != last) {
            std::cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        std::cout << temp->data << std::endl;
    }

    void swap(struct node* start, int current, int amount) {
        node* tmp = start;
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

    void input(struct node** start, int amount) {
        for (int i = 0; i < amount; i++) {
            int element;
            std::cout << "Enter new node: ";
            std::cin >> element;
            push(start, element);
        }
    }

    void demo() {
        int   amount, current;
        node* start = nullptr;

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
}  // namespace list

#endif  // LIST_HPP
