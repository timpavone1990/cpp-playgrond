#include <iostream>

using namespace std;

int* returnPointer() {
    int* i = new int;
    *i = 5;
    return i;
}

int returnValue() {
    int i = 5;
    return i;
}

int& returnReference() {
    int i = 6;
    return i; // Will throw a compilation warning. Lifetime of i ends at the end of this function. Therefore the returned reference will reference to sometihng undefined.
}

class MyClass {
    private:
        int* myInt;
    
    public:
        MyClass(int value) {
            myInt = new int;
            *myInt = value;
        }
        
        ~MyClass() {
            cout << "Goodbye from MyClass! My value was " << *myInt << endl;
            delete myInt; // RAII idiom. Always release resources in destructor so that other functions don't have to care about deleteing this resource.
        }
        
        void printValue() {
            cout << *myInt << endl;
        }
};

class MyClassWithReferenceMember {
    private:
        int& myInt;
        
    public:
        MyClassWithReferenceMember(int& value) : myInt(value) { }
        ~MyClassWithReferenceMember() {
            cout << "Goodbye from MyClassWithReferenceMember! My value was " << myInt << endl;
        }
        void printValue() {
            cout << myInt << endl;
        }
};

int main()
{
   int* iPointer = returnPointer();
   cout << *iPointer << endl;
   delete iPointer;
   
   int iValue = returnValue();
   cout << iValue << endl;
   // delete iValue; // delete is meant for pointers!
   
   int& iReference = returnReference();
   cout << iReference << endl;
   // delete iReference; // delete is meant for pointers!
   
   MyClass myClass(5); // Lifetime of this object ends at the end of this function. Destructor will be called automatically *at the end*.
   myClass.printValue();
   
   MyClass* myNextClass = new MyClass(8);
   myNextClass->printValue();
   delete myNextClass;  // Lifetime of this object won't end at the end of this function because it was allocated in the free memory. Destructor has to be called manually.
   
   int myValue = 55;
   MyClassWithReferenceMember myClassWithReferenceMember(myValue);
   myClassWithReferenceMember.printValue();
   
   int* myNextValue = new int;
   *myNextValue = 44;
   MyClassWithReferenceMember* myNextClassWithReferenceMember = new MyClassWithReferenceMember(*myNextValue);
   myNextClassWithReferenceMember->printValue();
   
   delete myNextValue;
   myNextClassWithReferenceMember->printValue(); // Deleted myNextValue. Reference to it in the object is broken.
   delete myNextClassWithReferenceMember;
   
   return 0;
}

