#include <iostream>
#include <string>
#include <cstdlib>
#include <climits> 
using namespace std;

enum Department
{
    ComputerScience = 1,
    CSW,
    EE,
    ME,
    MGS,
    CIVIL,
    AI
};
enum courses
{
    MT = 1,
    PH,
    HM,
    CH,
    CS
};
enum EducationLevel
{
    Bachlors = 1,
    Masters,
    PHD
};

class Person
{
private:
    string Sname;
    int Regno;
    int age;
    int phoneno;
    string email;
    string Tname;
    string Gender;
    double salary;
    int marks;
    string depart;
    string Edu;
    string Rcourses[4];
    string Acourses[3];
    Person *student;
    Person *teacher;
    // Person *EnrollCourse;
public:
    Person()
    {
        Rcourses[0] = "NO COURSE ENROLLED";
        Rcourses[1] = "NO COURSE ENROLLED";
        Rcourses[2] = "NO COURSE ENROLLED";
        Rcourses[3] = "NO COURSE ENROLLED";
    }
    int users;
    bool checkingg=false;
    bool checkG=false;
    void student_Details(void)
    {

        for (int k = 0; k < 3; k++)
        {
        cout << "Enter the no. of Students you want to add : ";
        cin >> users;
            if ((users > 0) && (users < 100))
            {
                checkingg = true;
                break;
            }
            else
            {
                cout << endl
                     << "Invalid Input \t   (You have " << 2 - k << " tries left)" << endl;
                cout << "  " << endl;
            }
        }
        student = new Person[users];
        for (int i = 0; i < users; i++)
        {
            cout << endl
                 << "Enter the Name of Student " << i + 1 << " : ";
            cin >> student[i].Sname;
            cout << "Enter the Age of Student " << i + 1 << " : ";
            cin >> student[i].age;
            cout << "Enter the Email of Student " << i + 1 << " : ";
            cin >> student[i].email;
            do
            {
                char gender;
                cout << "Enter the Gender of Student (M/F) " << i + 1 << " : ";
                cin >> gender;
                if ((gender == 'M') || (gender == 'm') || (gender == 'f') || (gender == 'F'))
                {
                    if ((gender == 'M') || (gender == 'm'))
                    {
                        student[i].Gender = "MALE";
                    }
                    if ((gender == 'f') || (gender == 'F'))
                    {
                        student[i].Gender = "FEMALE";
                    }

                    break;
                }
                else
                    cout << "Invalid Input!!. Try Again " << endl;
            } while (true);
               do
            {
                int e;
                cout << "Enter the Education Level of Student " << i + 1 <<endl;
                cout<<endl<<"---$$-OFFERED DEGREES-$$---"<<endl;
                cout<<"1.) Bachlors"<<endl;
                cout<<"2.) Masters"<<endl;
                cout<<"3.) PHD"<<endl;
                cout<<"Enter your Choice : ";
                cin >> e;
                if ((e == Bachlors) || (e == PHD) || (e == Masters))
                {
                    if (e == Bachlors)
                    {
                        student[i].Edu = "Bachlors";
                    }
                    else if (e == Masters)
                    {
                        student[i].Edu = "Masters";
                    }
                    else if (e == PHD)
                    {
                        student[i].Edu = "PHD";
                    }
                    break;
                }
                else
                    cout << "Invalid Input!!. Try Again " << endl;
            } while (true);

             do{
                int dep;
                cout << "Enter the Department of Student " << i + 1 <<endl;
                cout<<endl<<"---$$-OFFERED PROGRAMS-$$---"<<endl;
                cout<<"1.) Computer Science"<<endl;
                cout<<"2.) Software Engineering"<<endl;
                cout<<"3.) Artificial Inteligence (AI)"<<endl;
                cout<<"4.) Electrical Engineering"<<endl;
                cout<<"5.) Mechanical Engineering"<<endl;
                cout<<"6.) CIVIL Engineering"<<endl;
                cout<<"7.) Management sciences"<<endl;
                cout<<"Enter your choice : ";
                cin >> dep;
                if ((dep ==ComputerScience)|| (dep == CSW) || (dep == EE) || (dep == ME) || (dep ==  MGS)|| (dep == CIVIL)|| (dep == AI))
                {
                    if (dep == ComputerScience)
                    {
                        student[i].depart = "ComputerScience";
                    }
                    else if (dep == CSW)
                    {
                        student[i].depart = "SoftwareEngineering";
                    }
                    else if (dep == AI)
                    {
                        student[i].depart = "ArtificialIntelligence";
                    }
                    else if (dep == ME)
                    {
                        student[i].depart = "MechanicalEngineering";
                    }
                    else if (dep == EE)
                    {
                        student[i].depart = "ElectricalEngineering";
                    }
                    else if (dep == MGS)
                    {
                        student[i].depart = "ManagementSciences";
                    }
                    else if (dep == CIVIL)
                    {
                        student[i].depart = "CivilEngineering";
                    }
                    break;
                }
                else
                    cout << "Invalid Input!!. Try Again " << endl;
            } while (true);
           
            cout << "Enter the Reg no. of Student " << i + 1 << " : ";
            cin >> student[i].Regno;
        }
    }
    void Check_Record(void)
    {   if (checkingg)
    {
        for (int i = 0; i < users; i++)
        {
            cout << endl
                 << "Name of Student " << i + 1 << " : " << student[i].Sname << endl;
            cout << "Age of Student " << i + 1 << " : " << student[i].age << endl;
            cout << "Gender of Student " << i + 1 << " : " << student[i].Gender << endl;
            cout << "Education Level of Student " << i + 1 << " : " << student[i].Edu << endl;
            cout << "Department of Student " << i + 1 << " : " << student[i].depart << endl;
            cout << "Email of Student " << i + 1 << " : " << student[i].email << endl;
            cout << "Reg no. of Student " << i + 1 << " : " << student[i].Regno << endl;
            for (int j = 0; j < 3; j++)
                cout << "Courses Enrolled by Student " << i + 1 << " : " << student[i].Rcourses[j] << endl;
            cout << endl;
        }
    }
    else
    cout<<endl<<"NO STUDENT RECORD FOUND!!"<<endl;
    }
    bool checking = false;

    void Enroll_Course(void)
    {
     if (checkingg)
     {    
        for (int i = 0; i < users; i++)
        {
            bool courses[5] = {false};
            cout << endl
                 << "Enrolling courses for student " << i + 1 <<"\t\t (MAX 3 COURSES) "<< endl;
            for (int j = 0; j < 3; j++)
            {
                cout << endl
                     << "-----ALL COURSES----- " << endl;
                cout << "1.)MT-101" << endl;
                cout << "2.)PH-101" << endl;
                cout << "3.)HM-101" << endl;
                cout << "4.)CH-101" << endl;
                cout << "5.)CS-101" << endl;
                cout << "6.)Exit" << endl;
                cout << "Enter the course number " << j + 1 << " : ";
                int courseChoice;
                cin >> courseChoice;
                if (courseChoice == 6)
                {
                    cout << endl
                         << "You have exited the Course Enrollment for Student " << i + 1 << endl;
                    break;
                }

                switch (courseChoice)
                {
                case MT:
                {
                    bool exit = false;
                    if (courses[0])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered!!" << endl;
                                student[i].Rcourses[j] = "MT-101";
                                courses[0] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                case PH:
                {
                    bool exit = false;
                    if (courses[1])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered" << endl;
                                student[i].Rcourses[j] = "PH-101";
                                courses[1] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again.";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                case HM:
                {
                    bool exit = false;
                    if (courses[2])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered!!" << endl;
                                student[i].Rcourses[j] = "HM-101";
                                courses[2] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                case CH:
                {
                    bool exit = false;
                    if (courses[3])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered!!" << endl;
                                student[i].Rcourses[j] = "CH-101";
                                courses[3] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                case CS:
                {
                    bool exit = false;
                    if (courses[4])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered!!" << endl;
                                student[i].Rcourses[j] = "CS-101";
                                courses[4] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                default:
                    cout << "Invalid course choice" << endl;
                    break;
                }
            }
        }
             
     }
     else
     cout<<endl<<"NO STUDENT RECORD FOUND!!"<<endl;
    }
    int teach;
    void Add_Teacher_Details()
    {
        for (int k = 0; k < 3; k++)
        {
            cout << "Enter the number of teachers you want to add (0-100) : ";
            cin >> teach;

            if ((teach > 0) && (teach < 100))
            {
                checking = true;
                break;
            }
            else
            {
                cout << endl
                     << "Invalid Input \t   (You have " << 2 - k << " tries left)" << endl;
                cout << "  " << endl;
            }
        }
        teacher = new Person[teach];
        if (checking)
        {
            for (int i = 0; i < teach; i++)
            {
                cout << endl
                     << "Enter the Name of Teacher " << i + 1 << " : ";
                cin >> teacher[i].Sname;

                cout << "Enter the Age of Teacher " << i + 1 << " : ";
                cin >> teacher[i].age;

                char gender;
                do
                {
                    cout << "Enter the Gender of Teacher (M/F) " << i + 1 << " : ";
                    cin >> gender;
                    if (gender == 'M' || gender == 'm')
                    {
                        teacher[i].Gender = "MALE";
                        break;
                    }
                    else if (gender == 'F' || gender == 'f')
                    {
                        teacher[i].Gender = "FEMALE";
                        break;
                    }
                    else
                    {
                        cout << "Invalid Input!!. Try Again." << endl;
                    }
                } while (true);

                cout << "Enter the Email of Teacher " << i + 1 << " : ";
                cin >> teacher[i].email;
                cout << "Enter Courses for Teacher " << i + 1 << " (MAX 3 Courses or Enter 'E' to exit):" << endl;
                for (int j = 0; j < 3; j++)
                {
                    cout << "Enter Course " << j + 1 << " : ";
                    cin >> teacher[i].Acourses[j];
                    if ((teacher[i].Acourses[j] == "E") || (teacher[i].Acourses[j] == "e"))
                    {
                        teacher[i].Acourses[j] = "NO Course";
                        break;
                    }
                }
                cout << endl
                     << "Courses Successfully Allotted for Teacher " << i + 1 << "!!" << endl;
                cout << endl
                     << "Enter the Salary of Teacher " << i + 1 << " : ";
                cin >> teacher[i].salary;
            }
        }
        else
            cout << endl
                 << "INVALID INPUT!!" << endl;
    }

    void Check_Alloted_Courses(void)
    {
        if (checking)
        {
            cout << endl
                 << "---*All Enrolled Teachers*---" << endl;
            int i = 0, checkcourse;
            while (i < teach)
            {
                cout << endl
                     << "Teacher " << i + 1 << " : " << teacher[i].Sname;
                i++;
            }
            string tname;
            cout << endl
                 << "Enter your Name : ";
            cin >> tname;
            for (int j = 0; j < teach; j++)
            {
                if (tname == teacher[j].Sname)
                {
                    checkcourse = j;
                }
            }
            cout << endl;
            for (int k = 0; k < 3; k++)
            {
                cout << "Allocated Course " << k + 1 << " : " << teacher[checkcourse].Acourses[k] << endl;
            }
        }
        else
            cout << endl
                 << "NO COURSES ALLOCATED BY ADMIN!!" << endl;
    }
   
    void Check_Teacher_Details(void)
    {   if (checking)
    {
        cout << "---*All Enrolled Teachers*---";
        int i = 0;
        while (i < teach)
        {
            cout << endl
                 << "Teacher " << i + 1 << " : " << teacher[i].Sname;
            i++;
        }
        string tname;
        cout << endl
             << "Enter your Name : ";
        cin >> tname;
        for (int j = 0; j < teach; j++)
        {
            if (tname == teacher[j].Sname)
            {
                cout << endl
                     << "\t\t ---&&-YOUR DETAILS-&&---" << endl;
                cout << "Name of Teacher : " << teacher[j].Sname << endl;
                cout << "Age of Teacher : " << teacher[j].age << endl;
                cout << "Gender of Teacher : " << teacher[j].Gender << endl;
                cout << "Email of Teacher : " << teacher[j].email << endl;
                cout << "Salary of Teacher : " << teacher[j].salary << "Rs." << endl;
            }
        }
    }
    else
    cout<<endl<<"NO RECORD FOUND!!"<<endl;
    }
    void Check_Alloted_Students(void)
    {
        int choice;
        bool exit1 = true;
        if (checkingg)
        {
        do
        {
            cout << endl
                 << "-----ALL COURSES----- " << endl;
            cout << "1.)MT-101" << endl;
            cout << "2.)PH-101" << endl;
            cout << "3.)HM-101" << endl;
            cout << "4.)CH-101" << endl;
            cout << "5.)CS-101" << endl;
            cout << "6.)Exit" << endl;
            cin >> choice;
            switch (choice)
            {
            case 1:
                cout << "Students inrolled in MT-101 Course are : " << endl;
                for (int i = 0; i < users; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (student[i].Rcourses[j] == "MT-101")
                        {
                            cout << "Student " << i + 1 << " : " << student[i].Sname << endl;
                        break;
                        }
                    }
                }

                break;
            case 2:
                cout << "Students inrolled in PH-101 Course are : " << endl;
                for (int i = 0; i < users; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (student[i].Rcourses[j] == "PH-101")
                        {
                            cout << "Student " << i + 1 << " : " << student[i].Sname << endl;
                        break;
                        }
                    }
                }

                break;
            case 3:
                cout << "Students inrolled in HM-101 Course are : " << endl;
                for (int i = 0; i < users; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (student[i].Rcourses[j] == "HM-101")
                        {
                            cout << "Student " << i + 1 << " : " << student[i].Sname << endl;
                        break;
                        }
                    }
                }

                break;
            case 4:
                cout << "Students inrolled in CH-101 Course are : " << endl;
                for (int i = 0; i < users; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (student[i].Rcourses[j] == "CH-101")
                        {
                            cout << "Student " << i + 1 << " : " << student[i].Sname << endl;
                        break;
                        }
                    }
                }

                break;
            case 5:
                cout << "Students inrolled in CS-101 Course are : " << endl;
                for (int i = 0; i < users; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        if (student[i].Rcourses[j] == "CS-101")
                        {
                            cout << "Student " << i + 1 << " : " << student[i].Sname << endl;
                        break;
                        }
                    }
                }

                break;
            case 6:
                cout << "Exiting...";
                exit1 = false;
                break;
            default:
                cout << "INVALID CHOICE!!";
                break;
            }
        } while (exit1);
        }
        else{
            cout<<endl<<"NO STUDENT RECORD FOUND!!"<<endl;
        }
    }
    void Assign_Marks(void)
    {   if (checkingg)
    {   
        for (int i = 0; i < users; i++)
        {
            cout << "Enter Marks for Student   " << i + 1 <<" ( "<<student[i].Sname<<" ) "<< " : ";
            cin >> student[i].marks;
        }
        checkG=true;
        cout <<endl<< "Marks Successfully Assigned!!"<<endl;
         
        }
        else{
            cout<<endl<<"NO STUDENT RECORD FOUND!!"<<endl;
        }
    }

void Check_TopStudent() {
    if (checkingg)
    {
    if (users >= 3) {
        int maxMarks1 = INT_MIN;
        int maxIndex1 = -1;
        
        for (int i = 0; i < users; i++) {
            if (student[i].marks > maxMarks1) {
                maxMarks1 = student[i].marks;
                maxIndex1 = i;
            }
        }

        int maxMarks2 = INT_MIN;
        int maxIndex2 = -1;
        for (int i = 0; i < users; i++) {
            if (i == maxIndex1) {
                continue; 
            }
            if (student[i].marks > maxMarks2) {
                maxMarks2 = student[i].marks;
                maxIndex2 = i;
            }
        }

        int maxMarks3 = INT_MIN;
        int maxIndex3 = -1;
        
        for (int i = 0; i < users; i++) {
            if (i == maxIndex1 || i == maxIndex2) {
                continue; 
            }
            if (student[i].marks > maxMarks3) {
                maxMarks3 = student[i].marks;
                maxIndex3 = i;
            }
        }

        cout << "1st Student: " << student[maxIndex1].Sname << ", Marks: " << maxMarks1 << endl;
        cout << "2nd Student: " << student[maxIndex2].Sname << ", Marks: " << maxMarks2 << endl;
        cout << "3rd Student: " << student[maxIndex3].Sname << ", Marks: " << maxMarks3 << endl;
    } else {
        cout <<endl<< "INSUFFICIENT RECORDS TO SHOW TOP 3 STUDENTS!!" << endl;
    }
    }
    else
    {
        cout<<endl<<"NO STUDENT RECORD FOUND!!"<<endl;
    }
}

void Check_Student_details(void){
if (checkingg)
{
cout<<endl<<"---*All Students*---"<<endl;
for (int i = 0; i < users; i++)
{
cout<<student[i].Sname<<endl;
}
string S;
cout<<"Enter your Name : ";
cin>>S;
for (int i = 0; i < users; i++)
{
    if (S==student[i].Sname)
    {
      cout << endl
                 << "Name of Student " << i + 1 << " : " << student[i].Sname << endl;
            cout << "Age of Student " << i + 1 << " : " << student[i].age << endl;
            cout << "Gender of Student " << i + 1 << " : " << student[i].Gender << endl;
            cout << "Education Level of Student " << i + 1 << " : " << student[i].Edu << endl;
            cout << "Department of Student " << i + 1 << " : " << student[i].depart << endl;
            cout << "Email of Student " << i + 1 << " : " << student[i].email << endl;
            cout << "Reg no. of Student " << i + 1 << " : " << student[i].Regno << endl;
            for (int j = 0; j < 3; j++)
                cout << "Courses Enrolled by Student " << i + 1 << " : " << student[i].Rcourses[j] << endl;
            cout << endl;
    }
    
}

}
else{
cout<<endl<<"NO RECORD FOUND!!"<<endl;
}
}
void Allocate_Student_Course(void){
if (checkingg)
{
cout<<endl<<"---*All Students*---"<<endl;
for (int i = 0; i < users; i++)
{
cout<<student[i].Sname<<endl;
}

bool courses[5] = {false};
string S;
cout<<"Enter your Name : ";
cin>>S;
for (int i = 0; i < users; i++)
{
    if (S==student[i].Sname)
    {
            cout << endl
                 << "Enrolling courses for student " << i + 1 << endl;
            for (int j = 0; j < 3; j++)
            {
                cout << endl
                     << "-----ALL COURSES----- " << endl;
                cout << "1.)MT-101" << endl;
                cout << "2.)PH-101" << endl;
                cout << "3.)HM-101" << endl;
                cout << "4.)CH-101" << endl;
                cout << "5.)CS-101" << endl;
                cout << "6.)Exit" << endl;
                cout << "Enter the course number " << j + 1 << " : ";
                int courseChoice;
                cin >> courseChoice;
                if (courseChoice == 6)
                {
                    cout << endl
                         << "You have exited the Course Enrollment for Student " << i + 1 << endl;
                    break;
                }

                switch (courseChoice)
                {
                case MT:
                {
                    bool exit = false;
                    if (courses[0])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered!!" << endl;
                                student[i].Rcourses[j] = "MT-101";
                                courses[0] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                case PH:
                {
                    bool exit = false;
                    if (courses[1])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered" << endl;
                                student[i].Rcourses[j] = "PH-101";
                                courses[1] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again.";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                case HM:
                {
                    bool exit = false;
                    if (courses[2])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered!!" << endl;
                                student[i].Rcourses[j] = "HM-101";
                                courses[2] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                case CH:
                {
                    bool exit = false;
                    if (courses[3])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered!!" << endl;
                                student[i].Rcourses[j] = "CH-101";
                                courses[3] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                case CS:
                {
                    bool exit = false;
                    if (courses[4])
                    {
                        cout << endl
                             << "Course Already Registered!!" << endl;
                        j--;
                    }
                    else
                    {
                        char reg;
                        cout << "Enter 'R' or 'r' to register Course : ";
                        cin >> reg;
                        do
                        {
                            if ((reg == 'R') || (reg == 'r'))
                            {
                                cout << endl
                                     << "Course Successfully  Registered!!" << endl;
                                student[i].Rcourses[j] = "CS-101";
                                courses[4] = true;
                                exit = false;
                            }
                            else
                            {
                                cout << "Invalid Entry Please Try Again";
                                exit = true;
                            }
                        } while (exit);
                    }
                    break;
                }
                default:
                    cout << "Invalid course choice" << endl;
                    break;
                }
            }
            }
            }
        }
        else{
        cout<<endl<<"NO STUDENT RECORD FOUND!!"<<endl;
        }
    }         
void View_Grade(void){
if (checkG)
{
cout<<endl<<"---*All Students*---"<<endl;
for (int i = 0; i < users; i++)
{
cout<<student[i].Sname<<endl;
}
string S;
cout<<"Enter your Name : ";
cin>>S;
for (int i = 0; i < users; i++)
{
    if (S==student[i].Sname)
    {
if (student[i].marks >= 95 && student[i].marks <= 100) {
        cout<<"Grade : A+"<<endl;
    } else if (student[i].marks >= 90 && student[i].marks < 95) {
        cout<<endl<<"Grade : A"<<endl;
    } else if (student[i].marks >= 85 && student[i].marks < 90) {
        cout<<endl<<"Grade : A-"<<endl;
    } else if (student[i].marks >= 80 && student[i].marks < 85) {
        cout<<endl<<"Grade : B+"<<endl;
    } else if (student[i].marks >= 75 && student[i].marks < 80) {
        cout<<endl<<"Grade : B"<<endl;
    } else if (student[i].marks >= 70 && student[i].marks < 75) {
        cout<<endl<<"Grade : B-"<<endl;
    } else if (student[i].marks >= 65 && student[i].marks < 70) {
        cout<<endl<<"Grade : C+"<<endl;
    } else if (student[i].marks >= 60 && student[i].marks < 65) {
        cout<<endl<<"Grade : C"<<endl;
    } else if (student[i].marks >= 55 && student[i].marks < 60) {
        cout<<endl<<"Grade : C-"<<endl;
    } else if (student[i].marks >= 50 && student[i].marks < 55) {
        cout<<endl<<"Grade : D+"<<endl;
    } else if (student[i].marks >= 45 && student[i].marks < 50) {
        cout<<endl<<"Grade : D"<<endl;
    } else if (student[i].marks >= 40 && student[i].marks < 45) {
        cout<<endl<<"Grade : D-"<<endl;
    } else {
        cout<<endl<<"Grade : F"<<endl;
    }
    }
    }
    }
    else
    cout<<endl<<"Grade not assigned by Teacher!!"<<endl;
}

};
    int num;
    class Course
    {
    private:
        // string CS101, HM101, MT101, PH101, CH161;
        int credithours;
        int duration;
        int passingmarks;
        string venue;
        string coursecode;
        string instructor;

    public:
        Course *arr;
        int check=-1;
        bool checking12=false;

void View_Teachers(void){
   if (checking12)
  {
   string S;
   bool flag=true;
 do
{
cout<<endl<<"---*All Courses*---"<<endl;
for (int i = 0; i < num ; i++)
{
cout<<arr[i].coursecode<<endl;
}
do
{
cout<<"Enter your Course Code or 'E' to Exit : ";
cin>>S;
for (int i = 0; i < num; i++)
{
    if (S==arr[i].coursecode)
    {
    cout<<endl<<"Your Instructor for "<<arr[i].coursecode<<" is  : "<<arr[i].instructor<<endl;
    flag=false;
    }
    else{
        if ((S!="E")&&(S!="e"))
        { 
    cout<<endl<<"INVALID INPUT!! PLEASE TRY AGAIN."<<endl;
        }
        }
}
} while (flag);
} while ((S!="E")&&(S!="e"));
}
else{
cout<<endl<<"NO COURSE OR INSTRUCTOR ASSIGNED BY ADMIN!!"<<endl;
}
}
        void Course_Details(void)
        {
            int choice;
            cout << endl
                 << "\t\t-----MENU-----" << endl;
            cout << "1.)ADD course details" << endl;
            cout << "2.)Edit course details" << endl;
            cout << "3.)Delete course " << endl;

            cout << "Enter your Choice : ";
            cin >> choice;
            if (choice == 1)
            {   
            for (int k = 0; k < 3; k++)
            {
            cout << "Enter the no. of Courses you want to add (1-20) : ";
            cin >> num;
            if ((num > 0) && (num < 20))
            {
                checking12 = true;
                break;
            }
            else
            {
                cout << endl
                     << "Invalid Input \t   (You have " << 2 - k << " tries left)" << endl;
                cout << "  " << endl;
            }
            }
                arr = new Course[num];
                for (int i = 0; i < num; i++)
                {
                    cout << endl
                         << "Enter details for Course " << i + 1 << " : " << endl;
                    cout << "Enter course Code : ";
                    cin >> arr[i].coursecode;
                    cout << "Enter Credit Hours : ";
                    cin >> arr[i].credithours;
                    cout << "Enter course Duration (Months): ";
                    cin >> arr[i].duration;
                    cout << "Enter course Passing Marks (Percentage): ";
                    cin >> arr[i].passingmarks;
                    cout << "Enter course  Instructor: ";
                    cin >> arr[i].instructor;
                    cout << "Enter course Venue : ";
                    cin >> arr[i].venue;
                    cout << endl
                         << "Courses Data successfully stored!! " << endl;
                }
            }
            else if (choice == 2)
            {
                if (checking12)
                {
                cout << "---** ALL Courses **---" << endl;
                cout << "    " << endl;
                for (int i = 0; i < num; i++)
                {   if (i==check)
                {   i--;
                    continue;
                }
                    cout << i + 1 << ".)" << arr[i].coursecode << endl;
                }
                string editCode;
                cout << "Enter the course code you want to edit: ";
                cin >> editCode;
                for (int i = 0; i < num; i++)
                {
                    if (arr[i].coursecode == editCode)
                    {
                        cout << "Enter new details for Course " << editCode << " : " << endl;
                        cout << "Enter course Credit Hours : ";
                        cin >> arr[i].credithours;
                        cout << "Enter course Duration (Months): ";
                        cin >> arr[i].duration;
                        cout << "Enter course Passing Marks (Percentage) : ";
                        cin >> arr[i].passingmarks;
                        cout << "Enter course  Instructor: ";
                        cin >> arr[i].instructor;
                        cout << "Enter course Venue : ";
                        cin >> arr[i].venue;
                        cout << "Course details updated successfully." << endl;
                        return;
                    }
                }
            }
            else
            cout<<endl<<"NO COURSE HAS BEEN REGISTERED YET!!";
            }
            else if (choice == 3)
            {
            if (checking12)
            {
                cout << "---** ALL Courses **---" << endl;
                cout << "    " << endl;

                for (int i = 0; i < num; i++)
                {   
                    int k=1;
                    if (i==check)
                {
                    continue;
                }
                
                    cout << k << ".)" << arr[i].coursecode << endl;
                    k++;
                }
                string Delete_Code;
                cout << "Enter the course code you want to Delete: ";
                cin >> Delete_Code;
                for (int i = 0; i < num; i++)
                {
                    if (arr[i].coursecode == Delete_Code)
                    {
                        check = i;
                        delete &arr[i];
                        cout << endl
                             << "Course deleted successfully." << endl;
                        return;
                    }
                }
            }
            else
            cout<<endl<<"NO COURSE HAS BEEN REGISTERED YET!!";
            }
        }
        void Check_CourseRecord(void)
        {   
            if (checking12)
        { 
                 cout << endl
                 << "\t\t---&&-All Courses Details-&&---" << endl;
            for (int i = 0; i < num; i++)
            {
                if (i == check)
                {
                    continue;
                }
                else
                    cout << "Course Code for Course " << i + 1 << " : " << arr[i].coursecode << endl;
                cout << "Course Credit Hours for Course " << i + 1 << " : " << arr[i].credithours<<" Hours" << endl;
                cout << "Course Passing Marks (Percentage)  for Course " << i + 1 << " : " << arr[i].passingmarks << "%" << endl;
                cout << "Course Duration for Course " << i + 1 << " : " << arr[i].duration << " Months" << endl;
                cout << "Instructor Name for Course " << i + 1 << " : " << arr[i].instructor << endl;
                cout << "Course Venue for Course " << i + 1 << " : " << arr[i].venue << endl;
                cout << "  " << endl;
            }
        }
        else
        cout<<endl<<"NO COURSE HAS BEEN ADDED YET!!"<<endl;
        }
    };
    int main()
    {
        int choose;
        Person Admin;
        Person S1;
        Course C1;
        bool EXIT = true;
        bool exit123=true;
       
           cout<<" "<<endl; 
           cout<<"\t\t  ## ##     ####   ##  ###    ####            ####     ##   ##   ## ##"<<endl;
           cout<<"\t\t ##   ##     ##    ##  ##      ##              ##       ## ##   ##   ##"<<endl;
           cout<<"\t\t ##          ##    ## ##       ##              ##      # ### #  ####"<<endl;
           cout<<"\t\t ##  ###     ##    ## ##       ##              ##      ## # ##   #####   "<<endl;
           cout<<"\t\t ##   ##     ##    ## ###      ##              ##      ##   ##      ###"<<endl;
           cout<<"\t\t ##   ##     ##    ##  ##      ##              ##  ##  ##   ##  ##   ## "<<endl;
           cout<<"\t\t  ## ##     ####   ##  ###    ####            ### ###  ##   ##   ## ##"<<endl;
           cout<<""<<endl;
            do
        {   cout<<endl<<"\t\t\t\t       -----$$-GIKI LMS-$$-----"<<endl;
            cout <<endl<<"\t\t\t 1.) Admin's Panel\t\t 2.) Teacher's Panel\n";
            cout <<endl<< "\t\t\t 3.) Student's Panel\t\t 4.) Exit Program\n\n";
            cin >> choose;

            switch (choose)
            {
            case 1:
            {
                bool Exit_Program = true;
                int choice;
                do
                {
                    cout << endl
                         << "\t\t\t\t       -----&&-Admin's Panel-&&-----" << endl;
                    cout << endl
                         <<"\t\t\t\t            -----##-MENU-##-----" << endl;
                    cout << endl
                         << "1.) Add No. of Students" << endl;
                    cout << "2.) Enroll/Unenroll Students" << endl;
                    cout << "3.) Check Record of All Students" << endl;
                    cout << "4.) Add,Delete and Update Course Details" << endl;
                    cout << "5.) Check Record of All Courses" << endl;
                    cout << "6.) Add Teacher details" << endl;
                    cout << "7.) Exit Panel" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        S1.student_Details();
                        break;
                    case 2:
                        S1.Enroll_Course();
                        break;
                    case 3:
                        S1.Check_Record();
                        break;
                    case 4:
                        C1.Course_Details();
                        break;
                    case 5:
                        C1.Check_CourseRecord();
                        break;
                    case 6:
                        S1.Add_Teacher_Details();
                        break;
                    case 7:
                        cout << "You have Exited Admin Panel!!";
                        Exit_Program = false;
                        break;
                    default:
                        cout << "INVALID CHOICE" << endl;
                        break;
                    }
                } while (Exit_Program);
                cout << "Program Exited!!" << endl;
                break;
            }
            case 2:
            {
                bool exit_program = true;
                int choice;
                do
                {
                    cout << endl
                         << "\t\t\t\t       -----&&-Teachers Panel-&&-----" << endl;
                    cout << endl
                         << "\t\t\t\t            -----##-MENU-##-----" << endl;
                    cout << endl
                         << "1.) Check Personal Details" << endl;
                    cout << "2.) View Allocated Courses" << endl;
                    cout << "3.) View Enrolled Students in each Course" << endl;
                    cout << "4.) Assign Marks " << endl;
                    cout << "5.) View top Students" << endl;
                    cout << "6.) Exit Panel" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;
                    switch (choice)
                    {
                    case 1:
                        S1.Check_Teacher_Details();
                        break;
                    case 2:
                        S1.Check_Alloted_Courses();
                        break;
                    case 3:
                        S1.Check_Alloted_Students();
                        break;
                    case 4:
                        S1.Assign_Marks();
                        break;
                    case 5:
                        S1.Check_TopStudent();
                        break;
                    case 6:
                        cout << "You have Exited Teachers Panel!!";
                        exit_program = false;
                        break;
                    default:
                        cout << "INVALID CHOICE" << endl;
                        break;
                    }
                } while (exit_program);
                cout << "Program Exited!!" << endl;
                break;
            }
            case 3:
                // Students Pannel
                int choice1;
                do
                {
                    cout << endl
                         << "\t\t\t\t       -----&&-Student Panel-&&-----" << endl;
                    cout << endl
                         << "\t\t\t\t            -----##-MENU-##-----" << endl;
                    cout << endl
                         << "1.) Check Personal Details" << endl;
                    cout << "2.) Enroll in Courses" << endl;
                    cout << "3.) View Final Grade" << endl;
                    cout << "4.) View List of Teachers " << endl;
                    cout << "5.) Exit Panel" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice1;
                    switch (choice1)
                    {
                    case 1 :
                    S1.Check_Student_details();
                        break;
                    case 2 :
                    S1.Allocate_Student_Course();
                        break;
                    case 3 :
                    S1.View_Grade();
                        break;
                    case 4 :
                    C1.View_Teachers();
                        break;
                    case 5 :
                    cout<<"Exiting Students Screen...";
                    exit123=false;
                        break;
                    default:
                        break;
                    }
                } while (exit123);
                break;
            case 4:
                cout << "You have Exited the Program!!";
                EXIT = false;
                break;
            default:
                cout << "INVALID CHOICE" << endl;
                break;
            }
        } while (EXIT);

        return 0;
    }
    