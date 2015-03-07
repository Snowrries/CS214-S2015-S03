#include <list>
#include <set>
#include <iterator>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

// Pointer, reference, what's the difference? I'm not entirely sure...
void print_list(list<string> &l) {
    cout << "{ ";
    list<string>::iterator it = l.begin();
    for (int i = 0; i < l.size(); i++) {
        cout << *it++ << " ";
    }
    cout << "}\n";
}

int main(int argv, char **args) {
    list<string> list1;
    list1.push_back("some");
    list1.push_back("strings");
    list1.push_back("are");
    list1.push_back("go");
    list1.push_back("here");
    print_list(list1);
    
    //Create a beginning and end iterator
    list<string>::iterator iter1 = list1.begin(), iter2 = list1.end();
    //Note that in C++ the "end" refers to a "past-the-last element".
    //Eg. the end iterator points to a null trailer in the list

    //Move iter2 back 1 to point to the last element
    iter2--;
    
    
    //Add 5 gos to the front of the list
    for (int i = 0; i < 5; i++ ) {
        list1.push_front("go");
    }

    //Create another beginning iterator
    list<string>::iterator iter3 = list1.begin();

    // Note that when we dereference the iterator, we get the data it points to
    cout << "iter1: " << *iter1 << "\n";
    cout << "iter2: " << *iter2 << "\n";
    cout << "iter3: " << *iter3 << "\n";

    cout << "\n***advance iter3 by 3***\niter3: " << *iter3 << "\n";
    advance(iter3, 3);
    print_list(list1);

    cout << "\n***remove the 'go's***\n";
    list1.remove("go");
    
    print_list(list1);
    cout << "iter1: " << *iter1 << "\n";
    cout << "iter2: " << *iter2 << "\n";
    cout << "iter3: " << *iter3 << "\n";

    cout << "\n***attempt to advance iter3***\n";
    iter3++;
    cout << "iter1: " << *iter1 << "\n";
    cout << "iter2: " << *iter2 << "\n";
    cout << "iter3: " << *iter3 << "\n";

}
