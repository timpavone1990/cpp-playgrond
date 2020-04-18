#include "MyClass.h"
#include <iostream>

using namespace std;

void MyClass::printMembers() {
    cout << "Value member: " << myValueMember << endl;
    cout << "Pointer member: " << *myPointerMember << endl;
    cout << "Reference member: " << myReferenceMember << endl;
}

int MyClass::getValueMember() {
    return myValueMember;
}

int* MyClass::getPointerMember() {
    return myPointerMember;
}

int& MyClass::getReferenceMember() {
    return myReferenceMember;
}

int& MyClass::getNewlyCreated() {
    int* i = new int;
    *i = 55;
    return *i;
}