#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class student{
//initializing variables
 int id;
 char* firstName;
 char* lastName;
 public:
 //declaring functions
  int getId();
  void setId(int tempId);

};

#endif
