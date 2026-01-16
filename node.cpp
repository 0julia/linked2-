//Imports
#include "Node.h"

//Constructor
Node::Node(Student* inputStudent) {
	student = inputStudent;
	next = NULL;
}
//Destructor
Node::~Node() {
	delete student;
	next = NULL;
}

//set Student
void Node::setStudent(Student* &newStudent){
	student = newStudent;
}
//get Student
Student* Node::getStudent(){
	return student;
}
//set next node
void Node::setNext(Node* newNext) {
	next = newNext;
}
//get next node
Node* Node::getNext() {
	return next;
}
