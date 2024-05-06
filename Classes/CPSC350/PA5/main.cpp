// - Richard Graedon Beeler
// - 2423448
// - beeler @chapman.edu
// -main.cpp
#include "LazyBST.h"
#include "Student.h"
#include "Faculty.h"
#include "DatabaseSystem.h"
#include <iostream>
#include <stdexcept>
#include <limits>

using namespace std;

void printOptions();

int main()
{
    int selection = 0;
    DatabaseSystem d;
    while (selection != 11)
    {
        try
        {

            printOptions();

            cin.clear();
            cin >> selection;
            if (cin.fail())
            {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw invalid_argument("Error: please enter a number that corresponds to a menu option");
            }
            d.selectOption(selection);
        }
        catch (const out_of_range &e)
        {
            cerr << e.what() << endl;
        }
        catch (const invalid_argument &ia)
        {
            cerr << ia.what();
        }
        catch (...)
        {
            cerr << "Try again..." << endl;
        }
    }
    return 0;
}

void printOptions()
{
    cout << "\n1. Print all students and their information(sorted by ascending id #)" << endl
         << "2. Print all faculty and their information(sorted by ascending id #) " << endl
         << "3. Find and display student information given the student id " << endl
         << "4. Find and display faculty information given the faculty id" << endl
         << "5. Add a new student " << endl
         << "6. Delete a student given the id" << endl
         << "7. Add a new faculty member" << endl
         << "8. Delete a faculty member given the id." << endl
         << "9. Change a student’s advisor given the student id and the new faculty id." << endl
         << "10. Remove an advisee from a faculty member given the ids" << endl
         << "11. Exit\n"
         << endl;
}
