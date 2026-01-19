# include <iostream>
# include "node.h"
# include "Student.h"
# include <cstring>
using namespace std;

void add(const char newfirst[100],const char newlast[100], int my_id, float my_gpa, Node* &head);
void print(Node* next, Node* head);

void round(float num, int dec){ //prints up to the 100ths place
  if (dec==3){//if not a decimal...
    cout<<int(num) << ".";//print then add the dot
    round(num-int(num), 2);
  }else if(dec > 0){//recursive part
    num = num*10;//move the tenths place into the ones place
    cout << int(num); //print the ones place
    round((num-int(num)),dec-1); // delete the ones place and go onto the next decimal
  }
}


void numerical(Node* head, Node* next){
  if(head->getNext()==NULL){
    return;
  }
  if (next->getNext() == NULL){
    numerical(head->getNext(),head->getNext()->getNext());
  }
  if(head->getStudent()->getID() > next->getStudent()->getID()){
    Student* temp_head = head->getStudent();
    Student* temp_next = next->getStudent();
    head->setStudent(temp_next);
    next->setStudent(temp_head);
    numerical(head, next->getNext());
  }
  if(next != NULL){
    cout << head->getStudent()->getID() << ": " << head->getStudent()->getID();//next->getStudent();
    cout << ", ";
    numerical(head, next->getNext());
  }
  
}


int main(){
  Node* head = NULL;
  cout << "Commands are:" << endl << "     ADD" << endl << "     PRINT" << endl << "     DELETE" << endl << "     QUIT" << endl << "     AVERAGE" << endl<<endl;
  char command[100];
  do{
  cout << "What would you like to do? ";
  cin >> command;
  if (strcmp(command, "ADD")==0){
    char f_name[100];
    char l_name[100];
    int identify;
    float grade;
    /*
    cout << "What's the student's first name? ";
    cin >> f_name;
    cout << "What's " << f_name << "'s last name? ";
    cin >> l_name;
    cout << "What's " << f_name << "'s student ID? ";
    cin >> identify;
    cout << "What's " << f_name << "'s GPA? ";
    cin >> grade;
    add(f_name, l_name,identify, grade, head);
    */
    add("Andrew", "Jeddeloh", 468921, 650.12, head);
    add("Josh", "Bowles", 903826, 3.2565, head);
    add("Jason", "Galbraith", 487329, .1005, head);
    numerical(head, head->getNext());
  }else if(strcmp(command, "PRINT")==0){
    print(head,head);
  }else if(strcmp(command, "AVERAGE")==0){
    cout<<"I will use recursion" <<endl;
  }else if(strcmp(command, "DELETE")==0){
    int del_id;
    cout<<"What is the ID of the student you would like to delete? " << endl;
    cin >> del_id;
  }
  cout << endl;
  }while (strcmp(command, "QUIT") !=0);


  //delete s and n from add()
  Node* next = head;
  while (next != NULL) {
    Node* nextNode = next->getNext();
    delete next;
    next = nextNode;
  }
  head = NULL;  // list is now empty
  return 0;
}

void add(const char newfirst[100], const char newlast[100], int my_id, float my_gpa, Node* &head){
  Node* next = head;
  if (next == NULL){//if empty list
    Student* s = new Student();
    s->firstname(newfirst);
    s->lastname(newlast);
    s->setID(my_id);
    s->setGPA(my_gpa);
    
    Node* n = new Node(s);
    head = n;
  } else{ //if theres stuff in the list
    while (next->getNext() != NULL){
      next = next->getNext();
    }
    
    Student* s = new Student();
    s->firstname(newfirst);
    s->lastname(newlast);
    s->setID(my_id);
    s->setGPA(my_gpa);
    Node* n = new Node(s);
    next->setNext(n);
  }
}



void print(Node* next, Node* head){
  if(next == head){
    cout << "list: " << endl;
  }
  if(next != NULL){
    cout << "     " << next->getStudent()->firstname() << " " << next->getStudent()->lastname() << ", "<< next->getStudent()->getID() << ", ";
    round(next->getStudent()->getGPA(),3);
    cout << endl;
    print(next->getNext(), head);
  }
}
