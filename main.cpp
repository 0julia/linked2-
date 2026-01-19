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

/*
void remove(int del_id, Node*& head){
  cout << "checkpoint 1";
  if (head == NULL || head->getNext() == NULL){
    return;
  }
  //IF YOU NEED TO DELETE 1ST THING
  if(head->getStudent()->getID() == del_id){
    Node* temp = head;
    Node* next_head = temp->getNext();
    delete head->getStudent();
    delete head;
    head = next_head;
    cout <<"checkpoint 4";
    }
  Node* temp = head->getNext();
  //IF U NEED TO DELETE 2ND THING
  if(head->getNext()->getStudent()->id == del_id){
    head->setNext(head->getNext()->getNext());
    delete temp->getStudent();//head->getNext()->getStudent();
    delete temp;//head->getNext();
    
    cout <<"checkpoint 3";
  }
  cout <<"checkpoint 2";
  temp = head->getNext();
  remove(del_id, temp);
}


void remove(int del_id, Node*& head) {
  if(head == NULL){// || head->getNext()==NULL){
    return;
  }
  if(head->getStudent()->getID() == del_id) {
    Node* temp = head;
    head = head->getNext();
    delete temp->getStudent();
    delete temp;
    remove(del_id, head);
  }

  Node* current = head;
  if (current->getNext()->getStudent()->getID() == del_id) {
    Node* temp = current->getNext();
    current->setNext(temp->getNext());
    delete temp->getStudent();
    delete temp;
    remove(del_id, current->getNext());
  } else {
    current = current->getNext();
    remove(del_id, current);
  }
  
}



void remove(int del_id, Node** head) {
  if (*head == NULL) {
    return;
  }
  
  // If this node should be delete
  d
  if ((*head)->getStudent()->getID() == del_id) {
    Node* temp = *head;
    *head = (*head)->getNext();
    delete temp->getStudent();
    delete temp;
    remove(del_id, head);  // continue with new head
    //return;
  }else{
    // Recurse on the rest of the list
    remove(del_id, &((*head)->getNext()));
  }
}
*/
void remove(int del_id, Node*& head) {
    if (head == nullptr) return;

    // If current node should be deleted
    if (head->getStudent()->getID() == del_id) {
        Node* temp = head;
        head = head->getNext();        // move head forward
        delete temp->getStudent();     // delete student object
        delete temp;                   // delete node
        //remove(del_id, head);      // recurse on new head
        return;                        // important: stop using deleted node
    }else{
      head = head->getNext();
      remove(del_id, head);
    }
}

///START MAIN FUNTION (sry theres some functions above and below main, I was inconsistant...)
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
    add("Andrew", "Jeddeloh", 21, 1, head);
    add("Josh", "Bowles", 26, 1, head);
    add("Jason", "Galbraith", 487329, 2, head);
    add("drew", "Jeddeloh", 368921, 2, head);
    add("shE", "Bowles", 9066, 3, head);
    add("son", "Galbraith", 287329, 7, head);
    numerical(head, head);
  }else if(strcmp(command, "PRINT")==0){
    print(head,head);
  }else if(strcmp(command, "AVERAGE")==0){
    average(head,0,0);
  }else if(strcmp(command, "DELETE")==0){
    int del_id;
    cout<<"What is the ID of the student you would like to delete? ";
    cin >> del_id;
    cout << endl << "here";
    remove(del_id, head);
    cout << "done";
  }
  cout << endl;
  }while (strcmp(command, "QUIT") !=0);


  //delete s and n from add()
  while (head != NULL) {
    Node* temp = head;
    head = head->getNext();
    delete temp->getStudent();
    delete temp;
  }
  head = NULL;
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
