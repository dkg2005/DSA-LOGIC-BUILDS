#include<iostream>
using namespace std;
//function to calculate the length of sring
    
    bool checkpallindrome(char a[],int n){
        int i=0;
        int j = n-1;
        while(i<j){
            if(a[i]!=a[j]){
                return 0;  //false
            }
            else{
                i++;
                j--;
            }
        }
            return 1;
    }

int get_length(char name[]){
    int count =0 ;
    for(int i=0; name[i]!='\0';i++){
        count++;
    }
    return count;  //returning the value of variable "count
}

int main(){

    char name[20];
    cout<<"Enter the name:->"<<endl;
    cin>>name;
     
     int len = get_length(name);
    cout<<"Your name is:->>"<<name;
    cout<<"length is:->"<< len;

    cout<<"check the name is pallindrome or not:->"<<checkpallindrome(name,len);
    return 0;
}