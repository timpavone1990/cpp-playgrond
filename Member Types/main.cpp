#include <iostream>
#include "MyClass.h"

using namespace std;

int main() {
    int blupp = 5;
    
    MyClass myClass(blupp);
    myClass.printMembers();
   
    int value = myClass.getValueMember();
    int* pointer = myClass.getPointerMember();
    int& reference = myClass.getReferenceMember();
   
    cout << "Value: " << value << endl;
    cout << "Pointer: " << *pointer << endl;
    cout << "Reference: " << reference << endl;
    cout << "Blupp: " << blupp << endl;
   
    cout << endl;
   
    int testValue = 9;
    int* testPointer = new int;
    *testPointer = 8;
    
    MyClass anotherClass(7, testPointer, testValue);
    anotherClass.printMembers();
    
    int& newValue = anotherClass.getNewlyCreated();
    cout << "Newly created: " << newValue << endl;
    
    cout << endl;
    
    delete &newValue;
    
    return 0;
}

