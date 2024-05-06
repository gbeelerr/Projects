// - Richard Graedon Beeler
// - 2423448
// - beeler @chapman.edu
// -Faculty.cpp
#include "Faculty.h"
#include <string>
#include <iostream>



using namespace std;

Faculty::Faculty(){
    facultyID = 0;
    name = " ";
    standing = " ";
    department = " ";
    adviseeIDs = new DblList<int>();


}
Faculty::Faculty(int facultyID){
    this->facultyID = facultyID;
    name = " ";
    standing = " ";
    department = " ";
    adviseeIDs = new DblList<int>();
}
Faculty::Faculty(int facultyID, string name, string standing, string department)
{
    this->facultyID = facultyID;
    this->name = name;
    this->standing = standing;
    this->department = department;
    adviseeIDs = new DblList<int>();

}
Faculty::~Faculty(){
   // delete adviseeIDs;
}

int Faculty::getID()
{
    return facultyID;
}
string Faculty::getName()
{
    return name;
}
string Faculty::getDepartment()
{
    return department;
}
string Faculty::getStanding()
{
    return standing;
}
DblList<int> *Faculty::getAdviseeList()
{
    return adviseeIDs;
}
void Faculty::setID(int facultyID)
{
    this->facultyID = facultyID;
}
void Faculty::setName(string name)
{
    this->name = name;
}
void Faculty::setDepartment(string department)
{
    this->department = department;
}

void Faculty::setStanding(string standing)
{
    this->standing = standing;
}
void Faculty::removeAdvisee(int adviseeID)
{
    for (int i = 0; i < adviseeIDs->getSize(); i++){
        if (adviseeID == adviseeIDs->get(i)){
            adviseeIDs->remove(i);
        }
    }
}
void Faculty::addAdvisee(int adviseeID){
    adviseeIDs->addBack(adviseeID);
}
int Faculty::getNumAdvisees() {
    return adviseeIDs->getSize();
}
bool Faculty::operator==(const Faculty &other) const
{
    return facultyID == other.facultyID;
}
bool Faculty::operator<(const Faculty &other) const
{
    return facultyID < other.facultyID;
}
bool Faculty::operator>(const Faculty &other) const
{
    return facultyID > other.facultyID;
}

bool Faculty::operator!=(const Faculty &other) const
{
    return facultyID != other.facultyID;
}

void Faculty::printAdviseeList(){
    for (int i = 0; i < adviseeIDs->getSize(); i++){
        cout << adviseeIDs->get(i) << " ";
    }
    cout << endl;
}


ostream &operator<<(ostream &stream, const Faculty &faculty)
{
    
    stream << "Faculty ID: " << to_string(faculty.facultyID)
    << "\nName: " << faculty.name << "\nStanding: " << faculty.standing
    << "\nDepartment: " << faculty.department << "Advisees: ";

    return stream;
}