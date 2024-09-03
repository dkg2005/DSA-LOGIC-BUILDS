#include<iostream>
using namespace std;

int main(){
    
    int n;
    cin>>n;
    while(n--){
        int l,b;
       cin>>b>>l;  
       if (b == l) {
            cout << "Square" << endl;
        } else {
            cout << "Rectangle" << endl;
        }
    }    
    
    return 0;
}