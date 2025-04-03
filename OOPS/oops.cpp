#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class student {
    int rollNo;
    string name;

    public:
        void setInput(int rollNo, string name){
            this->rollNo = rollNo;
            this->name = name;
        }
        void printDetails(){
            cout<<"Name of the student : " << name << endl;
            cout<<"Roll No : " << rollNo <<endl;
        }
};

int main(){
    cout <<" ** OOPS CONCEPT **" << endl;

    // Object Declared statically
    student s1, s2;     
    s1.setInput(75,"Dhruv");
    s2.setInput(17,"Ankit");
    s1.printDetails();
    s2.printDetails();

    // Objects Declared dynamically (2 ways to get acess this methods different from normal)
    student *s3 = new student;
    // (*s3).setInput(1,"Gupta");  
    s3->setInput(1,"Gupta");
    // (*s3).printDetails();
    s3->printDetails();
    delete s3;
    return 0;
}