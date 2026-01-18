# include <iostream>
# include "node.h"
# include "Student.h"
# include <cstring>
using namespace std;

void add(const char newfirst[100],const char newlast[100], int my_id, float my_gpa, Node* &head);
void print(Node* next, Node* head);


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
    cin >> f_name;
    cin >> l_name;
    cin >> identify;
    cin >> grade;
    add(f_name, l_name,identify, grade, head);
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
    cout << "     " << next->getStudent()->firstname() << ", " << next->getStudent()->lastname() << ", " << next->getStudent()->getID() << ", " << next->getStudent()->getGPA() << endl;
    print(next->getNext(), head);
  }
}
