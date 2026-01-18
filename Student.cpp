#include <iostream>
#include "student.h"
#include <cstring>
using namespace std;

Student::Student(){

}
Student::~Student(){
}


//saves firstname
void Student::firstname(const char* first_name){
  strcpy(m_firstname, first_name);
}
//returns firstname
const char* Student::firstname(){
  return m_firstname;
}



//saves lastname
void Student::lastname(const char* last_name){
  strcpy(m_lastname, last_name);
}
//returns lasname
const char* Student::lastname(){
  return m_lastname;
}

// saves then returns id
void Student::setID(int identify){
  id=identify;
}
int Student::getID(){
  return id;
}


// saves then returns gpa
void Student::setGPA(float my_gpa){
  gpa=my_gpa;
}
float Student::getGPA(){
  return gpa;
}
