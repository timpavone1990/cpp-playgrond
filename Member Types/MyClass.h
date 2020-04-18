#ifndef MYCLASS_H
#define MYCLASS_H

#include <iostream>

using namespace std;

class MyClass {
    private:
        int myValueMember;
        int* myPointerMember;
        int& myReferenceMember;
 
    public:
        MyClass(int& ref) : myReferenceMember(ref) { // Reference member must be initialized
            myValueMember = 1;
            myPointerMember = new int;
            *myPointerMember = 11;
            myReferenceMember = 111;
        }
        
        ~MyClass() {
            cout << "Bye, bye!" << endl;
            delete myPointerMember;
        }
        
        MyClass(int value, int* pointer, int& reference)
            : myValueMember(value),
              myPointerMember(pointer),
              myReferenceMember(reference) { }
    
        int getValueMember();
        int* getPointerMember();
        int& getReferenceMember();
        
        void printMembers();
        
        int& getNewlyCreated();
};
#endif