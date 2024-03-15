#include<bits/stdc++.h>
using namespace std;

// reverse function of string
  void reverse(string &s, int x ,int y ){
    while(x<=y){
        swap(s[x++],s[y--]);
    }
  }
  //main function
  int main(){
    string s;
    getline(cin,s);
    
    int x = 0,y = 0;
       for(int i=0; i<s.length(); i++)
      {
            if(s[i] == ' ')
          {
            y = i-1;
            reverse(s,x,y);
            x = y + 2;  
          }            //My name is Dhruv gupta
      }

    //for last word means last character in the string is null then we apply directly out of the for loop
    reverse(s,x,s.length()-1);
    cout<<s;
    return 0;
  }