#include <iostream>
#include <cstring>
#include "student.h"

using namespace std;

//function that sets the student's id
void student::setId(int tempId){
    id = tempId;
}
/*
char* student::getFirstName(){
    return firstName;
}
char* student::getLastName(){
    return lastName;
}
*/
//function that returns the id of the student.
int student::getId(){
    return id;
}
void student::setGPA(float tempGPA){
    GPA = tempGPA;
}
float student::getGPA(){
    return GPA;
}
/*
void student::setFirstName(char* first){
    firstName = first;
}
void student::setLastName(char* last){
    lastName = last;
}
*/