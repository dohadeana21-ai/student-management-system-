#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
class Student {
private:
    string name;
    vector<string> courses;

public:
    Student(string n) {
        name=n;
    }
    string getName() {
        return name;
    }
    void addCourse(string courseNew) {
        courses.push_back(courseNew);
    }
    bool deleteCourse(string courseName) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i] == courseName) {
                courses.erase(courses.begin() + i);
                return true;
            }
        }

        return false;
    }
    void displayStudent() {
        setColor(10);
        cout << "Student: " << name << endl;
        setColor(13);
        cout << "Courses: "<<"\n";
        setColor(7);

        if (courses.empty()) {
            setColor(10);
            cout << "No courses";
            setColor(7);
        }
        else {
            for (int i = 0; i < courses.size(); i++) {
                setColor(13);
                cout << courses[i] << endl;
                setColor(7);
            }cout<<"---------------------" << endl;
        }

        cout << endl;
    }
};

/*
 & بنقول للدالة: اشتغلي على نفس قائمة الطلاب اللي موجودة في main
*/
void addStudent(vector<Student>& students) {
    string name;

    cout << "Enter student name: ";
    cin >> name;

    students.push_back(Student(name));
    setColor(10);
    cout << "Student \"" << name << "\" added." << endl;
    setColor(7);
}
/*
 داله لحذف اسم طالب
*/
void deleteStudent(vector<Student>& students) {
    string name;
    bool found = false;

    cout << "Enter student name: ";
    cin >> name;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].getName() == name) {

            students.erase(students.begin() + i);
            setColor(10);
            cout << "Student \"" << name << "\" removed." << endl;
            setColor(7);

            found = true;
            break;
        }
    }

    if (found == false) {
        setColor(12);
        cout << "Student \"" << name << "\" does not exist." << endl;
        setColor(7);
    }
}
void addCourseToStudent(vector<Student>& students) {
    string name;
    string courseName;
    cout << "Enter student name: ";
    cin >> name;
    bool found = false;

    for (int i = 0; i < students.size(); i++) {

        if (students[i].getName() == name) {
            cout << "Enter course name: ";
            cin >> courseName;
            students[i].addCourse(courseName);
            setColor(10);
            cout << "Course \"" << courseName
            << "\" added to " << name << "." << endl;
            setColor(7);

            found = true;
            break;
        }
    }

    if (found == false) {
        setColor(12);
        cout << "Student \"" << name << "\" does not exist." << endl;
        setColor(7);
    }
}
void deleteCourseFromStudent(vector<Student>& students) {
    string name;
    string courseName;
    bool found = false;

    cout << "Enter student name: ";
    cin >> name;

    for (int i = 0; i < students.size(); i++) {

        if (students[i].getName() == name) {

            cout << "Enter course name: ";
            cin >> courseName;

            found = true;

            if (students[i].deleteCourse(courseName)) {
                setColor(10);
                cout << "Course \"" << courseName
                     << "\" deleted from " << name << "." << endl;
                setColor(7);
            }
            else {
                setColor(12);
                cout << "Course \"" << courseName
                     << "\" does not exist." << endl;
                setColor(7);
            }

            break;
        }
    }

    if (found == false) {
        setColor(12);
        cout << "Student \"" << name << "\" does not exist." << endl;
        setColor(7);
    }
}
void displayAllStudents(vector<Student>& students) {
    if (students.empty()) {
        setColor(12);
        cout << "No students found." << endl;
        setColor(7);
        return;
    }

    for (int i = 0; i < students.size(); i++) {
        students[i].displayStudent();
    }
}
int print() {
    cout<<"\n"<<"Choose an option: ";
    int choice;
    cin>>choice;
    return choice;
}

int main() {
    vector<Student> students;

    cout<<"\n"<<"=== Student Management System ==="<<endl;
    int choice;
    do {
        cout<<"\n"<<"1. Add Student"<<endl;
        cout<<"2. Delete Student"<<endl;
        cout<<"3. Add Course to Student"<<endl;
        cout<<"4. Delete Course from Student"<<endl;
        cout<<"5. Display All Students"<<endl;
        cout<<"6. Exit"<<endl;

        choice = print();

        if (choice==1)
        {
            addStudent(students);

        }
        else if (choice==2)
        {
            deleteStudent(students);
        }
        else if (choice==3)
        {
            addCourseToStudent(students);
        }
        else if (choice==4)
        {
            deleteCourseFromStudent(students);
        }
        else if (choice==5) {
            displayAllStudents(students);
        }
        else
        {
            setColor(12);
            cout << "Error! Please choose an option from 1 to 6." << endl;
            setColor(7);
        }
    } while (choice != 6);

    setColor(10);
    cout<<"Goodbye!"<<endl;

    return 0;
}
