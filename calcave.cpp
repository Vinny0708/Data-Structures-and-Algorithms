#include <iostream>
using namespace std;

int main()
{
    float exam1, exam2, exam3;
    float average;
    const float Passing_Grade  = 70.0;
    cout  <<"Enter the score for Exam 1: ";
    cin >>exam1;
    cout  <<"Enter the score for Exam 2: ";
    cin >>exam2;
    cout  <<"Enter the score for Exam 3: ";
    cin >>exam3;
    average = (exam1 + exam2 +  exam3) / 3;
    cout <<"Average Score: " << average <<  endl;
    if (average >= Passing_Grade) {
        cout <<"Result: Passed" << endl;
    } else {
        cout <<"Result: Failed" << endl;
    }
    return 0;
}
