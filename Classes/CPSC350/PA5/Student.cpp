// - Richard Graedon Beeler
// - 2423448
// - beeler @chapman.edu
// -Student.cpp

#include "Student.h"
#include <iostream>
#include <string>

using namespace std;

Student::Student(){
    studentID = 0;
    name = " ";
    academicStanding = " ";
    major = " ";
    GPA = 0.0;
    advisorID = 0;
    
}

Student::Student(int studentID, string name, string academicStanding, string major, double GPA, int advisorID){
    this->studentID = studentID;
    this->name = name;
    this->major = major;
    this->academicStanding = academicStanding;
    this->GPA = GPA;
    this->advisorID = advisorID;
}

Student::Student(int studentID){
    this->studentID = studentID;
    name = " ";
    academicStanding = " ";
    major = " ";
    GPA = 0.0;
    advisorID = 0;
}

Student::~Student(){

}

int Student::getID(){
    return studentID;
}

string Student::getName(){
    return name;
}

string Student::getMajor(){
    return major;
}

string Student::getAcademicStanding(){
    return academicStanding;
}

double Student::getGPA(){
    return GPA;
}

int Student::getAdvisorID(){
    return advisorID;
}

void Student::setID(int studentID){
    this->studentID = studentID;
}
void Student::setName(string name){
    this->name = name;
}
void Student::setMajor(string major){
    this->major = major;
}
void Student::setGPA(double GPA){
    this->GPA = GPA;
}
void Student::setAdvisor(int advisorID){
    this->advisorID = advisorID;
}
void Student::setStanding(string academicStanding){
    this->academicStanding = academicStanding;
}

bool Student::operator<(const Student &other) const
{
    return studentID < other.studentID;
}

bool Student::operator==(const Student &other) const
{
    return studentID == other.studentID;
}

bool Student::operator>(const Student &other) const
{
    return studentID > other.studentID;
}

bool Student::operator!=(const Student &other) const
{
    return studentID != other.studentID;
}

ostream& operator<<(ostream& stream, const Student& student){
    stream << "Student ID: " << student.studentID
           << "\nName: " << student.name << "\nAcademic Standing: "
           << student.academicStanding << "\nMajor: " << student.major
           << "\nGPA: " << to_string(student.GPA) << "\nAdvisor ID:" << student.advisorID;

    return stream;
}