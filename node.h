//Header guards and imports
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "Student.h"

using namespace std;

//Node class
class Node{
	//Public constructor, destructor, and useful functions
	public:
		Node(Student*);
		~Node();
		void setStudent(Student*&);
		Student* getStudent();
		void setNext(Node*);
		Node* getNext();
	//Private variables
	private:
		Student* student;
		Node* next;
};
//End of header guard
#endif
