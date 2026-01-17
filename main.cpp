# include <iostream>
# include "node.h"
# include "Student.h"
using namespace std;

void add(const char newvalue[100],Node* &head);
void print(Node* next, Node* head);


int main(){
  Node* head = NULL;

  //ADD STUDENT THINGS TO NODE
  add("Student1", head);
  add("Student2", head);
  add("Student3", head);
  add("a_student", head);
  
  //PRINT NODE OF STUDENTS
  print(head, head);

  //delete s and n from add()
  Node* next = head;
  while (next != NULL) {
    Node* nextNode = next->getNext();
    //delete next->getStudent(); dont neeeddd 
    delete next;
    next = nextNode;
  }
  head = NULL;  // list is now empty
  return 0;
}

void add(const char newvalue[100], Node* &head){
  Node* next = head;
  if (next == NULL){//if empty list
    Student* s = new Student();
    s->name(newvalue);
    Node* n = new Node(s);
    head = n;
  } else{ //if theres stuff in the list
    while (next->getNext() != NULL){
      next = next->getNext();
    }
    
    Student* s = new Student();
    s->name(newvalue);
    Node* n = new Node(s);
    next->setNext(n);
  }
}



void print(Node* next, Node* head){
  if(next == head){
    cout << "list: ";
  }
  if(next != NULL){
    cout << next->getStudent()->name() << " ";
    print(next->getNext(), head);
  }
}
