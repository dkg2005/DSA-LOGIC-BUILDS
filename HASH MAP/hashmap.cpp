#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){

    // creation 
    // when we use ordered map it use bst so the order of key must be reserved .
    // but in the case of unordered_map the order of values must not be resreved .

     unordered_map<string,int>m;

     // insertion

     // 1
     pair<string,int> p = make_pair("dhruv", 1);
     m.insert(p);

     // 2
     pair<string,int> pair2("nakshatra", 2);
     m.insert(pair2);

     //3
     m["prachi"] = 3;

     //updation 
     m["prachi"] = 4;

     
     // Traverse the whole map
    for(auto i:m){
        cout   <<  i.first  << "    " <<  i.second <<endl;
    }

    // search 
    cout << m["prachi"] <<endl;
    cout<< m.at("prachi") <<endl;

    cout << m["UNKNOWN"] << endl;
     cout<< m.at("UNKNOWN") <<endl;

     // size
     cout<< m.size() <<endl;
   
//    for(auto i:m){
//         cout   <<  i.first  << "    " <<  i.second <<endl;
//     }


  // to check presence of key
    cout<<"count of dhruv means it was present or not"<<m.count("dhruv")<<endl ;

    // erase
    m.erase("UNKNOWN");
    cout<<m.size()<<endl;
   
   // for traversing it we can also use iterator
   unordered_map<string, int> :: iterator it = m.begin();

   while(it != m.end()){
         cout   <<  it->first  << "    " <<  it->second <<endl;
     it++ ;
   }
       
    return 0;
}



