#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

float gradeToPoint(string grade)
{
    if (grade == "A+")
        return 10.0;
    else if (grade == "A")
        return 9.0;
    else if (grade == "B+")
        return 8.0;
    else if (grade == "B")
        return 7.0;
    else if (grade == "C+")
        return 6.0;
    else if (grade == "C")
        return 5.0;
    else if (grade == "D")
        return 4.0;
    else
        return 0.0;
}

int main()
{
    int n;
    cout << "Enter number of courses: ";
    cin >> n;

    vector<string> courseNames(n);
    vector<int> credits(n);
    vector<string> grades(n);
    float totalGradePoints = 0, totalCredits = 0;

    for (int i = 0; i < n; ++i)
    {
        cout << "\nEnter name of course " << i + 1 << ": ";
        cin >> ws;
        getline(cin, courseNames[i]);

        cout << "Enter credits for " << courseNames[i] << ": ";
        cin >> credits[i];

        cout << "Enter grade (A+, A, B+, B, C+, C, D, F) for " << courseNames[i] << ": ";
        cin >> grades[i];

        float gp = gradeToPoint(grades[i]);
        totalGradePoints += gp * credits[i];
        totalCredits += credits[i];
    }

    cout << "\n--- Course-wise Details ---\n";
    cout << left << setw(20) << "Course" << setw(10) << "Credits" << setw(10) << "Grade" << endl;
    for (int i = 0; i < n; ++i)
    {
        cout << left << setw(20) << courseNames[i] << setw(10) << credits[i] << setw(10) << grades[i] << endl;
    }

    float cgpa = totalGradePoints / totalCredits;
    cout << fixed << setprecision(2);
    cout << "\nTotal Credits: " << totalCredits;
    cout << "\nTotal Grade Points: " << totalGradePoints;
    cout << "\nYour CGPA is: " << cgpa << endl;

    return 0;
}
