#ifndef FORWARD_LIST_HPP
#define FORWARD_LIST_HPP

#include <iostream>
#include <string>

#include "io.hpp"


namespace forward_list {
    struct node {
        int   data{0};
        node* next{nullptr};
    };

    void delete_list(node*& head) {
        while (head) {
            node* temp = head;
            head       = head->next;
            delete temp;
        }
        head = nullptr;
    }

    void print_list(const std::string& msg, node* head, std::ostream& out = std::cout) {
        std::cout << msg;

        node* item = head;
        while (item) {
            out << item->data << " -> ";
            item = item->next;
        }

        out << "null" << std::endl;
    }

    node* push(node* head, int data) {
        node* new_head = new node();
        new_head->data = data;
        new_head->next = head;
        return new_head;
    }

    node* reverse(node*& head) {
        node* current = head;
        node* prev    = nullptr;
        node* next    = nullptr;

        while (current) {
            next          = current->next;
            current->next = prev;
            prev          = current;
            current       = next;
        }
        head = prev;

        return head;
    }

    void demo() {
        std::cout << "Please enter list_size of elements in your list: ";
        const auto list_size = io::read<std::size_t>(std::cin);

        node* head = nullptr;
        for (int i = 0; i < list_size; i++) {
            const auto value = io::read<int>(std::cin);
            head             = push(head, value);
        }

        print_list("Original linked list: ", head);
        print_list("Reversed linked list: ", reverse(head));

        delete_list(head);
    }
}  // namespace forward_list

#endif  // FORWARD_LIST_HPP
