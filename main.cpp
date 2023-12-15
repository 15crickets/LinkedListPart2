#include <iostream>
#include <cstring>
#include "Node.h"
#include "student.h"

using namespace std;

int main(){
  Node* head;




  return 0;
}

void add(Node* &head, Node* current, Node* prev){
  cout << "Input the user's ID" << endl;
  int tempID;
  cin >> tempID;
  student* newstudent = new Student();
  newstudent->setID(tempID);
  if(head == NULL){
    head = new Node();
    head->setStudent(newstudent);
  }
  else{
    Node* tempNode = new Node();
    tempNode.setStudent(newstudent);
    if(prev->getStudent()->getID() < tempID && current->getStudent()->getID() > tempID){
      prev->setNext(tempNode);
      tempNode->setNext(current);
      
    }




  }
  




}
