// find example
#include <iostream>     // std::cout
#include <algorithm>    // std::find
#include <vector>       // std::vector

void test_find() {
    // using std::find with array and pointer:
    int myints[] = { 10, 20, 30, 40 };
    int *p;

    // Returns an iterator to the first element in the
    // range [first,last) that compares equal to val.
    p = std::find(myints, myints + 4, 30);
    if (p != myints + 4) {
        std::cout << "Element found in myints: " << *p << '\n';
    }
    else {
        std::cout << "Element not found in myints\n";
    }

    // using std::find with vector and iterator:
    std::vector<int>myvector(myints, myints + 4);
    std::vector<int>::iterator it;

    it = find(myvector.begin(), myvector.end(), 30);
    if (it != myvector.end()) {
        std::cout << "Element found in myvector: " << *it << '\n';
    }
    else {
        std::cout << "Element not found in myvector\n";
    }
}

/*
 * sort()
 */
bool myfunction(int i, int j) {
    return i < j;
}

struct myclass {
    bool operator()(int i, int j) {
        return i < j;
    }
} myobject;

void test_sort() {
    int myints[] = { 32, 71, 12, 45, 26, 80, 53, 33 };

    std::vector<int>myvector(myints, myints + 8);                // 32 71 12 45 26 80 53 33

    // using default comparison (operator <):
    std::sort(myvector.begin(), myvector.begin() + 4);           // (12 32 45 71)26 80 53 33

    // using function as comp
    std::sort(myvector.begin() + 4, myvector.end(), myfunction); // 12 32 45 71(26 33 53 80)

    // using object as comp
    std::sort(myvector.begin(), myvector.end(), myobject);       // (12 26 32 33 45 53 71 80)

    // print out content:
    std::cout << "myvector contains:";
    for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end();
         ++it) std::cout << ' ' << *it;
    std::cout << '\n';
}

void test_lower_upper_bound() {
    int myints[] = { 10, 20, 30, 30, 20, 10, 10, 20 };

    std::vector<int>v(myints, myints + 8);          // 10 20 30 30 20 10 10 20

    std::sort(v.begin(), v.end());                  // 10 10 10 20 20 20 30 30

    std::vector<int>::iterator low, up;
    low = std::lower_bound(v.begin(), v.end(), 20); //          ^
    up = std::upper_bound(v.begin(), v.end(), 20);  //                   ^

    std::cout << "lower_bound at position " << (low - v.begin()) << '\n';
    std::cout << "upper_bound at position " << (up - v.begin()) << '\n';
}

void test_heap() {
    int myints[] = { 10, 20, 30, 5, 15 };

    std::vector<int>v(myints, myints + 5);

    std::make_heap(v.begin(), v.end());
    std::cout << "initial max heap   : " << v.front() << '\n';

    std::pop_heap(v.begin(), v.end());

    // v.pop_back();
    std::cout << "max heap after pop : " << v.front() << '\n';

    v.push_back(99);
    std::push_heap(v.begin(), v.end());
    std::cout << "max heap after push: " << v.front() << '\n';

    std::sort_heap(v.begin(), v.end());
    std::cout << "final sorted range :";
    for (unsigned i = 0; i < v.size(); i++) std::cout << ' ' << v[i];
    std::cout << '\n';
}

int main() {
    // test_find();
    // test_sort();
    test_heap();
    return 0;
}
