#include <iostream>


//
// Stack implementation
//
struct stack {
    int    data{0};
    stack* next{nullptr};
};

stack* stack_new(int data = 0) {
    return new stack{data, nullptr};
}

void stack_push(stack*& top, int data) {
    stack* new_top = new stack;
    new_top->data  = data;
    new_top->next  = top;
    top            = new_top;
}

int stack_pop(stack*& top) {
    stack* old_top = top;
    top            = top->next;
    int result     = old_top->data;

    delete old_top;

    return result;
}

void stack_clear(stack*& top) {
    while (top->next) {
        stack_pop(top);
    }
}

void stack_delete(stack*& top) {
    stack_clear(top);
    delete top;
    top = nullptr;
}


//
// I/O helpers
//
stack* make_stack_with_randoms(std::size_t size) {
    stack* top = nullptr;
    for (std::size_t i = 0; i < size; i++) {
        const int data = rand() % 101 + (-50);
        stack_push(top, data);
    }
    return top;
}

void stack_print(const stack* top) {
    while (top) {
        std::cout << top->data << " ";
        top = top->next;
    }
}


//
// Task
//
int get_stack_median(const stack* top) {
    int count = 1;
    int sum   = top->data;
    while (top->next) {
        top = top->next;
        count++;
        sum += top->data;
    }

    return sum / count;
}

void move_greater(const stack* source, int value, stack*& destination) {
    while (source) {
        if (source->data > value) {
            stack_push(destination, source->data);
        }
        source = source->next;
    }
}

void print_stack(const char* prefix, const stack* top) {
    std::cout << prefix;
    if (top) {
        stack_print(top);
    }
    std::cout << std::endl;
}

void task() {
    int stack_size;
    std::cout << "Print number of elements in stacks: ";
    std::cin >> stack_size;

    stack* first = make_stack_with_randoms(stack_size);
    print_stack("First stack: ", first);
    std::cout << std::endl;

    const int median = get_stack_median(first);
    std::cout << "median is " << median << std::endl;

    stack* second = nullptr;
    move_greater(first, median, second);
    print_stack("Second stack: ", second);

    stack_delete(first);
    stack_delete(second);
}


//
// Application entry point
//
int main() {
    task();
    return 0;
}
