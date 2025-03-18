//Total marks of 5 students in a batch in quiz-1

#include<iostream>
using namespace std;

int main(){
    //define variables
    int student1,student2,student3,student4,student5;
    int totalmarks=0;

    //assign value of students via user input
    cout<<"Enter marks of student1: ";
    cin>>student1;

    cout<<"Enter marks of student2: ";
    cin>>student2;

    cout<<"Enter marks of student3: ";
    cin>>student3;

    cout<<"Enter marks of student4: ";
    cin>>student4;

    cout<<"Enter marks of student5: ";
    cin>>student5;

    //calculate total marks of students 
    totalmarks=student1+student2+student3+student4+student5;

    //display data
    cout<<"Total marks of 5 students in quiz-1: "<<totalmarks <<endl;

    return 0;
}