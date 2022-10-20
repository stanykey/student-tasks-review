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

void print_words_end_with_vowels(const char* text) {
    int counter = 0;
    for (int i = 0; i < std::strlen(text); i++) {
        if (text[i] == ' ') {
            for (int j = 0; j < 6; j++) {
                if (is_vowel(text[i - 1])) {
                    for (int c = i - counter; c < i; c++) {
                        std::cout << text[c];
                    }
                    std::cout << std::endl;
                    break;
                }
            }
            counter = 0;
        }
        counter++;
    }
}

void print_words_end_with_consonants(const char* text) {
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
}

void process_text(const char* text) {
    print_words_end_with_consonants(text);
    print_words_end_with_vowels(text);
}

int main() {
    static const std::size_t MAX_TEXT_LENGTH = 255;

    char text[MAX_TEXT_LENGTH + 1] = {'\0'};
    std::cin.getline(text, MAX_TEXT_LENGTH, '\n');
    process_text(text);

    return 0;
}
