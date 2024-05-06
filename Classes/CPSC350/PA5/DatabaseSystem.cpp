// - Richard Graedon Beeler
// - 2423448 
// - beeler @chapman.edu
// -DatabaseSystem.cpp
#include "DatabaseSystem.h"
#include "LazyBST.h"
#include "Student.h"
#include "Faculty.h"
#include <string>
#include <iostream>
#include <fstream>
#include <stdexcept>

                                     DatabaseSystem::DatabaseSystem(){
    studentDirectory = new LazyBST<Student>();
    facultyDirectory = new LazyBST<Faculty>();
}

DatabaseSystem::~DatabaseSystem(){
    delete studentDirectory;
    delete facultyDirectory;
}

void DatabaseSystem::printStudentData(){
    studentDirectory->printTreeInOrder();
}
void DatabaseSystem::printFacultyData()
{
    facultyDirectory->printTreeInOrder();
}
void DatabaseSystem::displayStudent()
{
    int idToCheck;

    cout << "Enter Student ID: " ;
    cin >> idToCheck;
    Student tempStudent(idToCheck);
    cout << studentDirectory->getFromTemp(tempStudent);



}
void DatabaseSystem::displayFacultyMember()
{
    int idToCheck;

    cout << "Enter faculty member's ID: ";
    cin >> idToCheck;
    Faculty tempFaculty(idToCheck);
    cout << facultyDirectory->getFromTemp(tempFaculty);
}
void DatabaseSystem::addStudent()
{
    cout << "Enter ID of Student to add: ";
    int studentID;
    cin >> studentID;
    cout << "Enter Name: ";
    string name;
    getline(cin >> ws,name);
    cout << "Enter Academic Standing: ";
    string academicStanding;
    cin >> academicStanding;
    cout << "Enter major: ";
    string major;
    getline(cin >> ws,major);
    cout << "Enter GPA: ";
    double GPA;
    cin >> GPA;
    cout << "Enter Advisor ID: ";
    int advisorID;
    cin >> advisorID;
    //check to see if advisorID matches a current faculty member
    Faculty f(advisorID);
    if(!facultyDirectory->contains(f)){
       cout << "Invalid advisor ID" << endl;
       return;
    }

    Student tempStudent(studentID,name,academicStanding,major,GPA,advisorID);
    studentDirectory->insert(tempStudent);
    facultyDirectory->getFromTemp(f).addAdvisee(studentID); //add student to their advisor's advisee list

    
}
void DatabaseSystem::deleteStudent()
{
    cout << "Enter the ID of student to delete: ";
    int studentID;
    cin >> studentID;
    Student s(studentID);
    studentDirectory->remove(studentDirectory->getFromTemp(s));

}
void DatabaseSystem::addFacultyMember()
{
    cout << "Enter ID of faculty member to add: ";
    int facultyID;
    cin >> facultyID;
    cout << "Enter Name: ";
    string name;
    getline(cin >> ws, name);
    cout << "Enter Position: ";
    string standing;
    getline(cin >> ws, standing);
    cout << "Enter Department: ";
    string department;
    getline(cin >> ws, department);

    Faculty tempFaculty(facultyID, name, standing, department);
    facultyDirectory->insert(tempFaculty);
}
void DatabaseSystem::deleteFacultyMember()
{
    cout << "Enter the ID of faculty member to delete: ";
    int advisorID;
    cin >> advisorID;
    Faculty f(advisorID);
    int adviseesToRedirect = facultyDirectory->getFromTemp(f).getAdviseeList()->getSize();
    cout << "Advisees to reassign: " << adviseesToRedirect << endl;
    for (int i = 0; i <  adviseesToRedirect; i++){
        int id = facultyDirectory->getFromTemp(f).getAdviseeList()->get(i);
        changeAdvisorOfStudent(id);
    }
    facultyDirectory->remove(facultyDirectory->getFromTemp(f));

}
void DatabaseSystem::changeAdvisorOfStudent()
{
    cout << "Enter student ID: ";
    int studentID;
    cin >> studentID;
    Student s(studentID);
    if (studentDirectory->contains(s)){
        changeAdvisorOfStudent(s);
    }else{
        cout << "did not find student" << endl;
    }

}
void DatabaseSystem::changeAdvisorOfStudent(Student s)
{
    int advisorID;
    //Student s(studentId);
        try{
            cout << "Enter the new advisor ID for the student: ";
            cin >> advisorID;
            Faculty f(advisorID);
            if(!facultyDirectory->contains(f)){
                throw invalid_argument("Advisor does not exist");
                
            }
            int oldAdvisorID = studentDirectory->getFromTemp(s).getAdvisorID();
            Faculty oldAdvisor(oldAdvisorID);
            studentDirectory->getFromTemp(s).setAdvisor(advisorID); //does not change the value of advisor

            facultyDirectory->getFromTemp(f).addAdvisee(s.getID()); //adds student to new advisor
            facultyDirectory->getFromTemp(oldAdvisor).removeAdvisee(s.getID()); //removes advisee from student's old advisor

            
       

        }catch(const invalid_argument& ia){
            cerr << ia.what();
        }
}
void DatabaseSystem::removeAdvisee()
{
    cout << "Enter faculty ID: " << endl;
    int facultyID;
    cin >> facultyID;
    Faculty f(facultyID);
    if (!facultyDirectory->contains(f))
    {
        cerr << "Invalid faculty ID" << endl;
        return;
    }
    cout << "Select advisee ID to remove: " << endl;
    facultyDirectory->getFromTemp(f).printAdviseeList();
    cout << endl;
    int adviseeID;
    cin >> adviseeID;
    Student s(adviseeID);
    if (!studentDirectory->contains(s)){
        cerr << "No such student in database" << endl;
        return;
    }
    facultyDirectory->getFromTemp(f).removeAdvisee(adviseeID);
    changeAdvisorOfStudent(s);
}


void DatabaseSystem::runLogOnExit()
{
    writer.open("runLog.txt");
    streambuf *coutToFile;
    coutToFile = cout.rdbuf();
    cout.rdbuf(writer.rdbuf());
    studentDirectory->printTreeInOrder();
    facultyDirectory->printTreeInOrder();
    writer.close();
}

void DatabaseSystem::selectOption(int option){
    switch (option){
        case 1:
            printStudentData();
            break;
        case 2:
            printFacultyData();
            break;
        case 3:
            displayStudent();
            break;
        case 4:
            displayFacultyMember();
            break;
        case 5:
            addStudent();
            break;
        case 6:
            deleteStudent();
            break;
        case 7:
            addFacultyMember();
            break;
        case 8:
            deleteFacultyMember();
            break;
        case 9:
            changeAdvisorOfStudent();
            break;
        case 10:
            removeAdvisee();
            break;
        case 11:
            runLogOnExit();
            break;
        default:
            throw out_of_range("Invalid selection");
           break;
    }
}