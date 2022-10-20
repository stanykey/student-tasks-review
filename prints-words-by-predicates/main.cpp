#include <iostream>
#include <string>


bool is_vowel(char letter) {
    static const char*       VOWELS       = "aeiouy";
    static const std::size_t VOWELS_COUNT = std::strlen(VOWELS);

    for (int i = 0; i < VOWELS_COUNT; i++) {
        if (tolower(letter) == VOWELS[i]) {
            return true;
        }
    }

    return false;
}

void process_text(const char* text) {
    int counter = 0;
    for (int i = 0; i < std::strlen(text); i++) {
        if (text[i] == ' ') {
            for (int j = 0; j < 6; j++) {
                if (is_vowel(text[i - 1])) {
                    break;
                }

                for (int c = i - counter; c < i; c++) {
                    std::cout << text[c];
                }
                std::cout << std::endl;
                break;
            }
            counter = 0;
        }
        counter++;
    }

    int counters = 0;
    for (int i = 0; i < std::strlen(text); i++) {
        if (text[i] == ' ') {
            for (int j = 0; j < 6; j++) {
                if (is_vowel(text[i - 1])) {
                    for (int c = i - counters; c < i; c++) {
                        std::cout << text[c];
                    }
                    std::cout << std::endl;
                    break;
                }
            }
            counters = 0;
        }
        counters++;
    }
}

int main() {
    static const std::size_t MAX_TEXT_LENGTH = 255;

    char text[MAX_TEXT_LENGTH + 1] = {'\0'};
    std::cin.getline(text, MAX_TEXT_LENGTH, '\n');
    process_text(text);
}
