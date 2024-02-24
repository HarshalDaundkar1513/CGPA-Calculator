#include <iostream>
#include <string>

using namespace std;

class SGPA_CAL
{
public:
    int num_of_sub;
    string sub_name[100];
    int marks[100];
    float totalCredit = 0.0, TotalGradePoint = 0.0, credit, grade, gp, SGPA;

public:
    void input();
    void display();
    float Credit(int);
    float Grade(int);
    void setCredit();
    void setGradePoint();
    float CalCulateSGPA();
};

void SGPA_CAL::input()
{
    cout << "How many subs : ";
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
    cout << num_of_sub << " Subjects Marks " << endl;
    for (int i = 0; i < num_of_sub; i++)
    {
        cout << sub_name[i] << ": " << marks[i] << "\t";
    }
    cout << endl;
}

float SGPA_CAL::Credit(int marks)
{
    if (marks < 100 && marks > 90)
    {
        return 4;
    }
    else if (marks < 90 && marks > 80)
    {
        return 3;
    }
    else if (marks < 80 && marks > 70)
    {
        return 3;
    }
    else if (marks < 70 && marks > 60)
    {
        return 2;
    }
    else if (marks < 60 && marks > 50)
    {
        return 2;
    }
    else if (marks < 50 && marks > 40)
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
    if (marks < 100 && marks > 90)
    {
        return 10;
    }
    else if (marks < 90 && marks > 80)
    {
        return 9;
    }
    else if (marks < 80 && marks > 70)
    {
        return 8;
    }
    else if (marks < 70 && marks > 60)
    {
        return 7;
    }
    else if (marks < 60 && marks > 50)
    {
        return 6;
    }
    else if (marks < 50 && marks > 40)
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

int main()
{
    SGPA_CAL s1;
    s1.input();
    s1.display();
    s1.setCredit();
    s1.setGradePoint();
    s1.CalCulateSGPA();
    return 0;
}