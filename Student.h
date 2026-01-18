#include <iostream>
#include <cstring>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class Student{
public:
  Student();
  ~Student();
  void firstname(const char*);
  const char* firstname();
  char m_firstname[80];

  void lastname(const char*);
  const char* lastname();
  char m_lastname[80];

  void setID(int id);
  int getID(); // const; ???
  int id;
  
  void setGPA(float gpa);
  float getGPA();
  float gpa;
  
};

#endif
