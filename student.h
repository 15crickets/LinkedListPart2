#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <cstring>

using namespace std;

class student{
//initializing variables
 int id;
 float GPA;

 public:
 //declaring functions
  char first[30];
  char last[30];
  float getGPA();
  void setGPA(float tempGPA);
  void setFirstName(char* first);
  void setLastName(char* last);
  char* getFirstName();
  char* getLastName();
  int getId();
  void setId(int tempId);

};

#endif
