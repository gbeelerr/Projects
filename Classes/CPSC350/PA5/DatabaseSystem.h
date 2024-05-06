#include "LazyBST.h"
#include "Student.h"
#include "Faculty.h"

#include <fstream>
#include <string>

class DatabaseSystem{

    public:
        DatabaseSystem();
        virtual ~DatabaseSystem();
        void printStudentData();
        void printFacultyData();
        void displayStudent(); // int studentID passed through terminal
        void displayFacultyMember(); // int facultyID pased through terminal
        void addStudent(); //request information for student through terminal
        void deleteStudent(); //ask for ID of student to delete through terminal
        void addFacultyMember(); //request member var info through terminal
        void deleteFacultyMember(); //ask for ID of faculty member to delete through terminal
        void changeAdvisorOfStudent(); //given student id and new faculty id
        void removeAdvisee(); //given id of advisee, delete from faculty member advisee list
        void selectOption(int option); 
        private :
        ofstream writer;
        LazyBST<Student>* studentDirectory;
        LazyBST<Faculty>* facultyDirectory;
        void runLogOnExit();
        void changeAdvisorOfStudent(Student s);
};