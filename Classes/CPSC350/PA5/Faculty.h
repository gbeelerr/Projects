#ifndef FACULTY_H
#define FACULTY_H

#include <string>
#include <iostream>
#include "DblList.h"
using namespace std;
class Faculty
{
public:
    Faculty();
    Faculty(int facultyID, string name, string standing, string department);
    Faculty(int facultyID, string name, string standing, string department, DblList<int>* advisees);
    Faculty(int facultyID);
    virtual ~Faculty();
    int getID();
    string getName();
    string getDepartment();
    string getStanding();
    DblList<int>* getAdviseeList();
    void printAdviseeList();
    void setID(int studentID);
    void setName(string name);
    void setDepartment(string department);
    void setStanding(string academicStanding);
    void addAdvisee(int adviseeID);
    void removeAdvisee(int adviseeID);
    int getNumAdvisees();
    bool operator==(const Faculty &other) const;
    bool operator<(const Faculty &other) const;
    bool operator>(const Faculty &other) const;
    bool operator!=(const Faculty &other) const;
    friend ostream &operator<<(ostream &stream, const Faculty &faculty);

private:
    int facultyID;
    string name;
    string standing;
    string department;
    DblList<int>* adviseeIDs;
    
};

#endif