#include<bits/stdc++.h>
using namespace std;

class human{
    public:
        int age;
        int height;
    private:
        int weight;
    public:
        void setWeight(int weight){
            this->weight = weight;
        }
        int getAge(){
            return this->age;
        }
};

class male : public human{
    public:
    string color;
    void sleep(){
        cout<<"Male sleeping"<<endl;
    }
};

int main(){
    male m1;
    m1.age = 15;
    // m1.weight = 34;    // NOT ACESSIBLE DUE TO PRIVATE IN HIS PARENT CLASS
    cout<<m1.age<<endl;
    cout<<m1.getAge()<<endl;
    m1.sleep();
    return 0;
}