#include <iostream>
#include "student.h"
#include <cstring>
using namespace std;

Student::Student(){
  //m_name[0]='\0';
}
Student::~Student(){
}

//saves name
void Student::name(const char* first_name){
  strcpy(m_name, first_name);
}


//returns name
const char* Student::name(){
  return m_name;
}
