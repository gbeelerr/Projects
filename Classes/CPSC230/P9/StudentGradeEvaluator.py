import csv

#Richard Graedon Beeler
#2423448
#beeler@chapman.edu
#Assignment 9

def open_file():
    input_file = input("Enter your csv file name: ")
    invalid = True
    while invalid:
        try:
            f = open(input_file, "r")
            type(f)
            #print(f.read())
            invalid = False
        except:
            print("File does not exist.")
            input_file = input("Enter your file name: ")
    f.close()
    return input_file
#f = open("Roster.csv", "r")
#type(f)
#print(f.read())
#f.close()

def input_grades(roster_input):
    f = open(roster_input, "r")
    file_reader = csv.reader(f, delimiter =',')
    #num_students = (len(f.readlines()))- 1
    assignment_list = ["Assignment 1", "Assignment 2", "Assignment 3"]
    grades = []
    grade = 0
    total_grade = 0
    header = True
    #for i in range(num_students):
    for row in file_reader:
        if header == True:
            header = False
            continue
        for j in range(len(assignment_list)):
            print("Enter", assignment_list[j], "grade for", row[0],  ".")
            each_grade = int(input(": "))
            grade += each_grade
        total_grade = round(grade/len(assignment_list))
        grades.append(total_grade)
        grade = 0
        total_grade = 0
    #print (grades)
    f.close()
    return grades
def write_grades(grades, filename):
    f = open(filename, "r")
    file_reader = csv.reader(f, delimiter =',')
    output_file = open("Grades.csv", "w")
    file_writer = csv.writer(output_file)
    header = True
    heading_row = ["Student Name", "Grade"]
    line = 0
    file_writer.writerow(heading_row)
    for row in file_reader:
        if header == True:
            header = False
            continue
        file_writer.writerow([row[0],grades[line]])
        line +=1
    print("Grades.csv updated!")
    f.close()
    output_file.close
pass

roster_name = open_file()
grade_list = input_grades(roster_name)
p = write_grades(grade_list,roster_name)