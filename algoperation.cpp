//  Implement  algebric operation using  friend function and this pointer in cpp

#include <iostream>
using namespace std;

class MyNumber {
private:
    int num;

public:
    MyNumber(int value) : num(value) {}

    // Declare a friend function for algebraic addition
    friend MyNumber add(const MyNumber& a, const MyNumber& b);

    // Declare a friend function for algebraic subtraction
    friend MyNumber subtract(const MyNumber& a, const MyNumber& b);

    // declare a friend class for algebric multipication
    friend MyNumber multiply(const MyNumber& a, const MyNumber& b) ;

     void display() {
        cout << "Number: " << num << endl;
    }
};

// Friend function for addition
MyNumber add(const MyNumber& a, const MyNumber& b) {
    int result = a.num + b.num;
    return MyNumber(result);
}

// Friend function for subtraction
MyNumber subtract(const MyNumber& a, const MyNumber& b) {
    int result = a.num - b.num;
    return MyNumber(result);
}

// Friend function for multipication 
    friend MyNumber multiply(const MyNumber& a, const MyNumber& b)  {
    int result = (a.num )*( b.num);
     return MyNumber(result);
    }
    


int main() {
    MyNumber num1(10);
    MyNumber num2(5);

    cout << "Original Numbers:" << endl;
    num1.display();
    num2.display();

    MyNumber sum = add(num1, num2);
    MyNumber difference = subtract(num1, num2);
    MyNumber multiply =  multiply(num1, num2);

    cout << "After Algebraic Operations:" << endl;
    sum.display();
    difference.display();
    mutiply.display();
    

    return 0;
}
