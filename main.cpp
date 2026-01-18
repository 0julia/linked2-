# include <iostream>
# include "node.h"
# include "Student.h"
using namespace std;

void add(const char newfirst[100],const char newlast[100], int my_id, float my_gpa, Node* &head);
void print(Node* next, Node* head);


int main(){
  Node* head = NULL;

  //ADD STUDENT THINGS TO NODE
  add("Student1" ,"last", 455929, 4.00, head);
  add("Student2", "last2", 355979, 1.00, head);
  add("Student3", "lasst3", 255429, 2.00, head);
  add("a_student", "last4", 155929, 3.00, head);
  
  //PRINT NODE OF STUDENTS
  print(head, head);

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
