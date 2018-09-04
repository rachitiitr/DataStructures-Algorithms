//Video explanation at : https://youtu.be/qsMahidcehY 
#include <iostream>
using namespace std;

class A{
public:
    static int x;
    A(){
     
    }
    ~A(){
       
    }
    void* operator new(size_t sz) {
        x++;
    }
};

int A::x = 0;

int main()
{
    A a, b; //local --> stack
    A c, d, e;
    
    //dynamic --> heap
    //A* ptr = (A*)malloc(sizeof(A)); //allocates memory, doesnt call ctor
    A* ptr = new A; //ctor as well
    A* ptr2 = new A;
    //free(ptr); //doesn't call the destructor
    delete ptr; // TO DO: overload delete and decrement counter..
    
    
    cout << A::x << endl;

}
