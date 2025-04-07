#include<iostream>
#include<bits/stdc++.h>
using namespace std;

//  OOPS CHEAT SHEET :   https://github.com/vineethm1627/OOP

class student {
    public:
    int rollNo;
    string name;
    static string schoolName ;  // we can aceess it without making object of this class
    static string printSchool(){
         return schoolName;
    }
    public:
        student(){
            cout<<"constructor intilallized"<<endl;
        }
        student(int rollNo){
            this->rollNo = rollNo;
        }
        student(int rollNo, string name){
            this->rollNo = rollNo;
            this->name = name;
        } 
        // writtean copy constructor manully
        // student(student& temp){   // here we are using & as if we do not use this it traps into the loop of copy (as a pass by value) so we do it bt pass by reference
        //     cout<<"After making default copy constructor is deleted"<<endl;
        //     this-> rollNo = temp.rollNo;
        //     this-> name = temp.name;
        // }
        void setInput(int rollNo, string name){
            this->rollNo = rollNo;
            this->name = name;
        }
        void printDetails(){
            cout<<"Name of the student : " << name << endl;
            cout<<"Roll No : " << rollNo <<endl;
        }
        ~student(){
            cout<<"Destructor called"<<endl;
        }
};
string student :: schoolName = "DSSA";
int main(){
    cout <<" ** OOPS CONCEPT **" << endl;
    cout << student :: schoolName << endl;
    cout << student :: printSchool() << endl;
    // Object Declared statically
    // student s1, s2;     
    // student s1(75);
    student s1(75,"Dhruv Gupta");

    // s1.setInput(75,"Dhruv");
    // s2.setInput(17,"Ankit");
    
    s1.printDetails();    
    // s2.printDetails();

    // COPY constructor
    // student s2(s1);
    // s2.printDetails(); 

    // CONCEPT OF SHALLOW COPY AND DEEP COPY 
    // In C++, a shallow copy does work fine as long as there are no dynamically allocated variables involved. 
    // A shallow copy essentially duplicates the values of the object's member variables, 
    // but if one of those members points to a dynamically allocated memory block (e.g., using ), it can lead to issues
    // s1.rollNo = 74;
    // s1.name = "Dhruv";
    // s1.printDetails();
    // s2.printDetails();
    // Objects Declared dynamically (2 ways to get acess this methods different from normal)
    // student *s3 = new student;
    // (*s3).setInput(1,"Gupta");  
    // s3->setInput(1,"Gupta");
    // (*s3).printDetails();
    // s3->printDetails();
    // delete s3;


   
    return 0;
}