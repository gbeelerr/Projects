#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>
using namespace std;
class Student{
    public:
        Student();
        Student(int studentID, string name, string academicStanding, string major, double GPA, int advisorID);
        Student(int studentID);
        virtual ~Student();
        int getID();
        string getName();
        string getMajor();
        double getGPA();
        int getAdvisorID();
        string getAcademicStanding();
        void setID(int studentID);
        void setName(string name);
        void setMajor(string major);
        void setGPA(double GPA);
        void setAdvisor(int advisorID);
        void setStanding(string academicStanding);
        bool operator==(const Student &other) const;
        bool operator<(const Student &other) const;
        bool operator>(const Student &other) const;
        bool operator!=(const Student &other) const;
        friend ostream& operator<<(ostream& stream, const Student& student);

    private : 
        int studentID;
        string name;
        string academicStanding;
        string major;
        double GPA;
        int advisorID;



};








#endif