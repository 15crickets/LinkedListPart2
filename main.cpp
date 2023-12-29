#include <iostream>
#include <cstring>
#include "Node.h"
#include "student.h"
#include <iomanip>

using namespace std;
void add(Node* &head, Node* current, Node* prev, int Id, float GPA, char first[30], char last[30]);
void display(Node* current);
void remove(Node* &head, Node* current, Node* prev, int deleteID);
void average(Node* current, int counter, float sum);
int main(){
  Node* head = NULL;
  bool stillRunning = true;
  while (stillRunning == true){
    //prompt user to begin one of the functions
    cout << "Enter 'ADD', 'PRINT', 'DELETE', 'AVERAGE', or 'QUIT'" << endl;
    char input[15];
    for(int i = 0; i < 7; i++){
      input[i] = '\0';
    }
    cin.get(input, 15);
    cin.ignore(15, '\n');

    if(strcmp(input, "ADD") == 0){
      int id;
      float GPA;
      char first[30];
      char last[30];
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
      display(head);
    }
    if(strcmp(input, "QUIT") == 0){
      stillRunning = false;
    }
    if(strcmp(input, "AVERAGE") == 0){
      average(head, 0, 0);
    }
    if(strcmp(input, "DELETE") == 0){
      cout << "What ID would you like to delete?" << endl;
      int deleteID;
      cin >> deleteID;
      cin.get();
      remove(head, head, head, deleteID);
    }
  }
  return 0;
}

void add(Node* &head, Node* current, Node* prev, int Id, float GPA, char first[30], char last[30]){
  student* newstudent = new student();
 
  newstudent->setId(Id);
   
  strcpy(newstudent->first, first);
  
  strcpy(newstudent->last, last);
  newstudent->setGPA(GPA);

  if(head == NULL){
    head = new Node();
    head->setStudent(newstudent);
  }
  else{
    Node* tempNode = new Node();
    tempNode->setStudent(newstudent);
    if(Id < head->getStudent()->getId()){
      Node* newTemp = head;
      head = tempNode;
      head->setNext(newTemp);
    }
    else if(current == NULL){
      current = tempNode;
      prev->setNext(current);
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
void remove(Node* &head, Node* current, Node* prev, int deleteID){
  if(head == NULL){
    return;
  }
  else{
    if(current->getStudent()->getId() == deleteID){
      if(current == head){
        Node* tempNode = current->getNext();
        delete head;
        head = tempNode;
      }
      else{
        prev->setNext(current->getNext());
        delete current;
      }
    }
    else{
      if(current->getNext()!= NULL){
        remove(head, current->getNext(), current, deleteID);
      }
      else{
        return;
      }
      return;
    }
  }
}

void display(Node* current){
  if(current == NULL){
    return;
  }
  cout << current->getStudent()->first << " " << current->getStudent()->last;
  cout << ", " << current->getStudent()->getId() << ", " << fixed << setprecision(2) << current->getStudent()->getGPA() << endl;
  if(current->getNext() != NULL){
    display(current->getNext());
  }
  return;

}
void average(Node* current, int counter, float sum){
  if(current == NULL){
    if(counter == 0){
      cout << "There are no students in the list" << endl;
    }
    else{
      cout << "The average of all the students' GPAs is " << fixed << setprecision(2) << (sum/counter) << endl;
    }
    return;
  }
  else{
    counter++;
    sum = sum + current->getStudent()->getGPA();
    average(current->getNext(), counter, sum);
  }
}