#include <iostream>
#include <string>

using namespace std;

class SGPA_CAL
{
public:
    int num_of_sub;
    string sub_name[100];
    int marks[100];
    float totalCredit = 0.0, TotalGradePoint = 0.0, credit, grade, gp, SGPA, CGPA;

public:
    void input();
    void display();
    float Credit(int);
    float Grade(int);
    void setCredit();
    void setGradePoint();
    float CalCulateSGPA();
    void CalCulateCGPA();
};

void SGPA_CAL::input()
{
    cout << "How many subjects: ";
    cin >> num_of_sub;
    for (int i = 0; i < num_of_sub; i++)
    {
        cout << "Enter subject name: ";
        cin >> sub_name[i];
        cout << "Enter marks for subject " << sub_name[i] << ": ";
        cin >> marks[i];
    }
}

void SGPA_CAL::display()
{
    cout << " Subjects Names and Marks Of : " << num_of_sub << " Subjects " << endl;
    for (int i = 0; i < num_of_sub; i++)
    {
        cout << sub_name[i] << ": " << marks[i] << "\t";
    }
    cout << endl;
}

float SGPA_CAL::Credit(int marks)
{
    if (marks <= 100 && marks >= 90)
    {
        return 4;
    }
    else if (marks <= 90 && marks >= 80)
    {
        return 3;
    }
    else if (marks <= 80 && marks >= 70)
    {
        return 3;
    }
    else if (marks <= 70 && marks >= 60)
    {
        return 2;
    }
    else if (marks <= 60 && marks >= 50)
    {
        return 2;
    }
    else if (marks <= 50 && marks >= 40)
    {
        return 1;
    }
    else
    {
        return 0.0;
    }
}

float SGPA_CAL::Grade(int marks)
{
    if (marks <= 100 && marks >= 90)
    {
        return 10;
    }
    else if (marks <= 90 && marks >= 80)
    {
        return 9;
    }
    else if (marks <= 80 && marks >= 70)
    {
        return 8;
    }
    else if (marks <= 70 && marks >= 60)
    {
        return 7;
    }
    else if (marks <= 60 && marks >= 50)
    {
        return 6;
    }
    else if (marks <= 50 && marks >= 40)
    {
        return 5;
    }
    else
    {
        return 0.0;
    }
}

void SGPA_CAL::setCredit()
{
    for (int i = 0; i < num_of_sub; i++)
    {
        totalCredit += Credit(marks[i]);
    }
    cout << "Total Credit " << totalCredit << endl;
}

void SGPA_CAL::setGradePoint()
{
    for (int i = 0; i < num_of_sub; i++)
    {
        float credit = Credit(marks[i]);
        float grade = Grade(marks[i]);
        if (credit == 0 || grade == 0)
        {
            TotalGradePoint = 0.0;
            cout << "Total Grade point " << TotalGradePoint << endl;
            return;
        }
        TotalGradePoint += credit * grade;
    }
    cout << "Total Grade point " << TotalGradePoint << endl;
}

float SGPA_CAL::CalCulateSGPA()
{
    if (totalCredit == 0.0)
    {
        return 0.0;
    }

    SGPA = TotalGradePoint / totalCredit;
    cout << "SGPA " << SGPA << endl;
    return SGPA;
}

void SGPA_CAL::CalCulateCGPA()
{
    int num_of_semesters;
    cout << "Enter the number of semesters: ";
    cin >> num_of_semesters;

    SGPA_CAL semesterCalculators[num_of_semesters];

    for (int i = 0; i < num_of_semesters; i++)
    {
        cout << "Enter details for Semester " << i + 1 << ":" << endl;
        semesterCalculators[i].input();
    }

    for (int i = 0; i < num_of_semesters; i++)
    {
        cout << "Details for Semester " << i + 1 << ":" << endl;
        semesterCalculators[i].display();
    }

    for (int i = 0; i < num_of_semesters; i++)
    {
        cout << "Total Credit And Grades of Semester " << i + 1 << ":" << endl;
        semesterCalculators[i].setCredit();
        semesterCalculators[i].setGradePoint();
    }

    float totalCreditCGPA = 0.0;
    float totalGradePointCGPA = 0.0;

    for (int i = 0; i < num_of_semesters; i++)
    {
        totalCreditCGPA += semesterCalculators[i].totalCredit;
        totalGradePointCGPA += semesterCalculators[i].TotalGradePoint;
    }

    if (totalCreditCGPA == 0.0)
    {
        CGPA = 0.0;
    }

    CGPA = totalGradePointCGPA / totalCreditCGPA;
    cout << "CGPA " << CGPA << endl;
}

int main()
{
    int ch;
    SGPA_CAL sgpaCalculator;
    SGPA_CAL CGPACalculator;
    cout << "Enter the choice: \n1. SGPA CALCULATOR \n2. CGPA CALCULATOR \n";
    cin >> ch;

    switch (ch)
    {
    case 1:
        sgpaCalculator.input();
        sgpaCalculator.display();
        sgpaCalculator.setCredit();
        sgpaCalculator.setGradePoint();
        sgpaCalculator.CalCulateSGPA();
        break;

    case 2:
        CGPACalculator.CalCulateCGPA();
        break;

    default:
        cout << "Invalid Choice";
        break;
    }

    return 0;
}
