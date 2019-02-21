/* Author: Jorge Moreno, euid: jm1066
   Instructor: Professor Ryan Michaels
   Date: 1/23/18
   Description In this program i read in numbers from data1 file into a linked list and then read numbers in from
   data2 file. Then i take those numbers in data2 and compare to the numbers in the linked list. If two numbers are
   the same i delete that number in the linked list, Afterwords i output the updated list. */
  
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
using namespace std;

struct File  //struct that holds information for all my nodes
{
  int fData;  //holds data inside a given node
  File* fLink; //pointer to next node
};

void compare(File *Head, int fNumbers2); //function for comparing and deleting nodes

int main()
{
  int count = 0;  //counter
  int fNumbers;  //to hold numbers read in from first file
  int fNumbers2;  //to hold numbers read in from second file
  File* Head = NULL;  //initialize my head node
  
  ifstream fin;  //first ifstream variable for file 1
  ifstream fin2;  //second ifstream variable for file 2
  
  cout << "=========================================================" << endl;
  
  fin.open("data1.txt");  //open the first file
  if(fin.fail())
  {
    cout << "Unable to open this file." << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    cout << "Input file opened, retreiving numbers." << endl;
  }
  
  fin2.open("data2.txt");  //open the second file
  if(fin.fail())
  {
    cout << "Unable to open this file." << endl;
    exit(EXIT_FAILURE);
  }
  else
  {
    cout << "Input file 2 opened, retreiving numbers." << endl;
  }
  
  cout << "=========================================================" << endl;
  
  while(!fin.eof())  //loop through all the numbers in the file
  {
    fin >> fNumbers;  //read in each number
    
    File* temp = new File();  //create a new node for each number
    temp->fData = fNumbers;  //store the number in the data variable
    temp->fLink = NULL;  //make the next pointer NULL so that this number is at the end of the list 

    if(Head != NULL) //If the list is empty
    {
     File *temp2 = Head;  //create a Head
     while(temp2->fLink != NULL)
     {
      temp2 = temp2->fLink;
     }
     temp2->fLink = temp;
    }
    else
    {
       Head = temp;
    }
    count++;
    if(count == 50)  //output numbers every 50
    {
      cout << "Outputting the contents of my Linked List after each 50 numbers: " << endl;
      File *temp3 = Head;
      while(temp3 != NULL)  //output the linked list
      {
        cout << temp3->fData << " ";
        temp3 = temp3->fLink;
      }
      cout << endl;
      count =0;
    }
   }
  cout << endl;
  cout << "These Numbers are from the 2nd list and are not found in the 1st list." << endl;
   while(!fin2.eof())  //loop through the second file
   { 
    fin2 >> fNumbers2;  //read in each number
    compare(Head,fNumbers2); //compare and delete function
   }
  cout << endl;
  cout << "Now deleting numbers in the 1st list that are the same as the 2nd list" << endl;
  cout << "Updated List 1: " << endl;
  File *tempD = Head;
  while(tempD != NULL)  //show the updated list
 {
  cout << tempD->fData << " ";
  tempD = tempD->fLink;
 }

 cout << endl;

 cout << endl;
 fin.close();  //close the first file
 fin2.close();  //close the second file
 return 0;
}

void compare(File *Head,int fNumbers2) //function to compare and delete nodes
{
    int count2=0;  //another counter
    File *prev = NULL;  //set the previous node to null
    File *cur = Head;  //set the current node to the head of the Linked List
    
   while(cur->fLink != NULL)  //loop through list
    {  
     if(cur->fData == fNumbers2 &&  prev == NULL) //If the number is the same as the head
     {
      prev = cur;     //set the previous to the current
      cur = cur->fLink;  //move the current node to the next
      Head = cur;  //make the head the current node
      delete prev;  //delete the original head
      count2++; //increment the counter
     }
     else if(cur->fData == fNumbers2) //if the number is the same as a node in the list not the head 
     {
      prev->fLink = cur->fLink;  //make the previous next equal to the current next
      delete cur;  //delete the current node
      count2++;  //increment the counter
     }
     else  //none of the numbers match
     {
      prev = cur;  //set the previous node to the current node
      cur =  cur->fLink;  //move over to the next node
     }
    }
   if(count2 ==0)  //whenever a number does not match output it
   {
    cout << fNumbers2 << " ";  //cout the numbers
   }
}
