#include<iostream>
#include<string.h>
using namespace std;

class Hero{
  //properties

    private:
       int health;
  
    public:
      char level;
      char *name;
      static int timeToComplete;
      
    //constructor
    Hero(){
        cout<<"constructor called"<<endl;
        name  = new char[100];
    }
    
    //parametrized constructor
    Hero(int health){
        cout<<"this -> "<<this<<endl;
        this->health = health;
    }
    Hero(int health,char level){
        this->health = health;
        this->level = level;
    }
    //copy constructor
    Hero(Hero &temp){

         char *ch = new char[strlen(temp.name) + 1];
        strcpy(ch, temp.name);
        this->name = ch;

        cout<<"copy constructor is calling...."<<endl;
        this->health = temp.health;
        this->level = temp.level;
    }
      
     void print(){
        cout << endl;
        cout << "[ Name: " << this->name<< " ,";
        cout << "health: " << this->health << " ,";
        cout <<"level: " << this->level << " ]";
        cout << endl << endl;
    }

    //getters and setters
    int getHealth() {
        return health;
    }

    char getLevel() {
        return level;
    }

    void setHealth(int h) {
        health = h;
    }

    void setLevel(char ch) {
        level = ch;
    }
    void setName(char name[]) {
        strcpy(this->name, name);
    }
       // static functions
    static int random() {
        return timeToComplete ;
    }

     //Destructor
    ~Hero() {   
        cout << "Destructor bhai called" << endl;
    }
};

int Hero::timeToComplete = 5;

int main(){

      cout << Hero::timeToComplete << endl;
      cout << Hero::random() << endl;

    // Hero a;
    // cout << a.timeToComplete << endl;

    // Hero b;
    // b.timeToComplete = 10 ;
    // cout  << a.timeToComplete << endl;
    // cout << b.timeToComplete << endl;
  


    // //Static
    // Hero a;

    // //Dynamic
    // Hero *b = new Hero();
    // //manually destructor call
    // delete b;



// we can learn about concept of shallow copy fromm here
    //  Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('C');
    // char name[] = "Dhruv";
    // hero1.setName(name);

//     hero1.print();

//     //use default copy constructor

//    // Hero hero2(hero1);
//     //hero2.print();
  //  Hero hero2 = hero1;

    // hero1.name[0] = 'G';
    // hero1.print();

    // hero2.print();

    // hero1 = hero2;

    // hero1.print();

    // hero2.print();



    //    Hero D(90,'A');
    //    D.print();
    //    //copy constructor
    //    Hero N(D);
    //    N.print();



        // //statically constructor called
        // Hero dhruv(70);
        // cout<<"address of dhruv:"<<&dhruv<<endl;
        // dhruv.getHealth();
        // //dynamically constructor called
        // Hero *h = new Hero(80);


    //static allocation
    // Hero a;
    // a.setHealth(70);
    // a.setLevel('B');
    // cout<<"health is:"<<a.getHealth() <<endl;
    // cout<<"level is:"<<a.level<<endl;


    //dynamic allocation
    // Hero *b = new Hero ;
    // b->setLevel('A');
    // b->setHealth(80) ;
    // cout<<"level is:"<<(*b).level<<endl;
    //  cout<<"health is:"<<(*b).getHealth() <<endl;
    //     // or we can do this like 
    // cout<<"level is:"<<b->level<<endl;
    //  cout<<"health is:"<<b->getHealth() <<endl;



      //creation of Object
    // Hero ramesh;   
    // cout << "Size of Ramesh is " << sizeof(ramesh) << endl;

    // cout << "Ramesh health is " << ramesh.getHealth() << endl;
    // //use setter
    // ramesh.setHealth(70);
    // ramesh.level = 'A';


    // cout << "health is: " << ramesh.getHealth() << endl; 
    // cout << "Level is: " << ramesh.level << endl; 

    // //cout << "size : " << sizeof(h1) << endl;
    return 0;
}
