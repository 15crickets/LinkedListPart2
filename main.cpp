#include <iostream>
#include <cstring>
#include "Node.h"
#include "student.h"
#include <iomanip>

using namespace std;
void add(Node* &head, Node* current, Node* prev, int Id, float GPA, char* first, char* last);
void display(Node* current);

int main(){
  Node* head = NULL;
  bool stillRunning = true;
  while (stillRunning == true){
    //prompt user to begin one of the functions
    cout << "Enter 'ADD', 'PRINT', 'REMOVE', or 'QUIT'" << endl;
    char input[15];
    for(int i = 0; i < 7; i++){
      input[i] = '\0';
    }
    cin.get(input, 15);
    cin.ignore(15, '\n');

    if(strcmp(input, "ADD") == 0){
      int id;
      float GPA;
      char* first;
      char* last;
      cout << "What is the student's first name? " << endl;
      cin.get(first, 30);
      cin.get();
      cout << "What is the student's last name? " << endl;
      cin.get(last, 30);
      cin.get();
      cout << "What is the student's ID? " << endl;
      cin >> id;
      cin.get();
      cout << "What is the student's GPA? " << endl;
      cin >> GPA;
      cin.get();
      add(head, head, head, id, GPA, first, last);

    }
    if(strcmp(input, "PRINT") == 0){
      cout << "Print called" << endl;
      display(head);
    }



  
  }
  return 0;
}

void add(Node* &head, Node* current, Node* prev, int Id, float GPA, char* first, char* last){
  cout << Id << endl;
  student* newstudent = new student();
 
  newstudent->setId(Id);
   
  newstudent->setFirstName(first);
  
  newstudent->setLastName(last);
  newstudent->setGPA(GPA);
  
  if(head == NULL){
    cout << "In" << endl;
    head = new Node();
    head->setStudent(newstudent);
  }
  else{
    cout << "Entered" << endl;
    Node* tempNode = new Node();
    tempNode->setStudent(newstudent);
    if(Id < head->getStudent()->getId()){
      cout << "Less than" << endl;
      Node* newTemp = head;
      head = tempNode;
      head->setNext(newTemp);
    }
    else if(current == NULL){
      current = tempNode;
    }
    else if(prev->getStudent()->getId() < Id && current->getStudent()->getId() > Id){
      prev->setNext(tempNode);
      tempNode->setNext(current);
    }
    else{
      add(head, current->getNext(), current, Id, GPA, first, last);
    }
    return;
  }
  return;
}
void display(Node* current){
  cout << "Entered display" << endl;
  if(current == NULL){
    return;
  }
  cout << current->getStudent()->getFirstName() << " " << current->getStudent()->getLastName();
  cout << ", " << current->getStudent()->getId() << ", " << current->getStudent()->getGPA() << endl;
  if(current->getNext() != NULL){
    display(current->getNext());
  }
  return;

}
