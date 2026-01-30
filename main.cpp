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


//orders things by the ids
void numerical(Node* head, Node* next){
  if(head->getNext()==NULL || next == NULL){ //if at the end of the list, leave
    return;
  }
  if (next->getNext() == NULL){ //if the compared value is at the end, move the 1st thing over
    numerical(head->getNext(),head->getNext()->getNext());
  }
  if(head->getStudent()->getID() > next->getStudent()->getID()){ //swap 2 nodes
    Student* temp_head = head->getStudent();
    Student* temp_next = next->getStudent();
    head->setStudent(temp_next);
    next->setStudent(temp_head);
    numerical(head, next->getNext());
  } // move the next value over
  if(next != NULL){
    numerical(head, next->getNext());
  }
  
}

//goes through all th gpas and adds them then divides them by pass (# of students)
void average(Node* head, float sum, int pass){
  if(head->getNext() == NULL){
    sum = sum + head->getStudent()->gpa;
    float avg = sum/(pass+1);
    cout<< "Average: ";
    round(avg, 3); //rounds it to 2 decimals
    cout << endl;
    return;
  }
  sum = sum + head->getStudent()->gpa;//adds the next gpa to the sum
  average(head->getNext(), sum, pass+1); //recursivness
  
}


void remove(int del_id, Node*& head){
  
  if (head == NULL){
    return;
  }
  
  //IF YOU NEED TO DELETE 1ST THING
  if(head->getStudent()->getID() == del_id){
    Node* temp = head;
    head = head->getNext();//Node* next_head = temp->getNext();
    delete temp;
    return; //head = next_head;
  }
   Node* next = head->getNext();   // store copy safely
    remove(del_id, next);           // recurse
    head->setNext(next);            // reconnect list

  }

///START MAIN FUNTION (sry theres some functions above and below main, I was inconsistant...)
int main(){
  cout<<"HI";
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
    cout << "What's the student's first name? ";
    cin >> f_name;
    cout << "What's " << f_name << "'s last name? ";
    cin >> l_name;
    cout << "What's " << f_name << "'s student ID? ";
    cin >> identify;
    cout << "What's " << f_name << "'s GPA? ";
    cin >> grade;
    add(f_name, l_name,identify, grade, head);
    numerical(head, head);
  }else if(strcmp(command, "PRINT")==0){
    print(head,head);
  }else if(strcmp(command, "AVERAGE")==0){
    average(head,0,0);
  }else if(strcmp(command, "DELETE")==0){
    int del_id;
    cout<<"What is the ID of the student you would like to delete? ";
    cin >> del_id;
    remove(del_id, head);
  }
  cout << endl;
  }while (strcmp(command, "QUIT") !=0);


  //delete s and n from add()
  while (head != NULL) {
    Node* temp = head;
    head = head->getNext();
    delete temp;
  }
  head = NULL;
  cout << "Aborted";
}

//adding student info to node
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
