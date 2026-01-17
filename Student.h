#include <iostream>
#include <cstring>
#ifndef STUDENT_H
#define STUDENT_H
using namespace std;

class Student{
public:
  Student();
  ~Student();
  void name(const char*);
  const char* name();
  char m_name[80];
};

#endif
