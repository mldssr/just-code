#include <iostream>
#include <string>

void test_iterator() {
    std::string str("Test string");
    for (std::string::iterator it = str.begin(); it != str.end(); ++it) {
        std::cout << *it;
    }
    std::cout << '\n';
}

void test_capacity() {
    std::string str("Test string");

    // Both string::size and string::length are synonyms and return the exact
    // same value.
    std::cout << "The size of str is " << str.size() << " bytes.\n";
    std::cout << "The size of str is " << str.length() << " bytes.\n";

    std::string content;
    std::string line;
    std::cout << "Please introduce a text. Enter an empty line to finish:\n";
    do {
        getline(std::cin, line);
        content += line + '\n';
    } while (!line.empty());
    std::cout << "The text you introduced was:\n" << content;
}

void test_modifiers() {
    std::string str = "to be question";
    std::string str2 = "the ";
    std::string str3 = "or not to be";
    std::string::iterator it;

    // used in the same order as described above:
    str.insert(6, str2);                                // to be (the )question
    str.insert(6, str3, 3, 4);                          // to be (not )the question
    str.insert(10, "that is cool", 8);                  // to be not (that is )the question
    str.insert(10, "to be ");                           // to be not (to be )that is the question
    str.insert(15, 1, ':');                             // to be not to be(:) that is the question
    it = str.insert(str.begin() + 5, ',');              // to be(,) not to be: that is the question
    str.insert(str.end(), 3, '.');                      // to be, not to be: that is the question(...)
    str.insert(it + 2, str3.begin(), str3.begin() + 3); // (or )

    std::cout << str << '\n';
}

int main() {
    test_iterator();
    return 0;
}
