#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

double Average(vector <pair<string, double>>);
void FirstThreeStudenst(vector <pair<string, double>>);
void UnderTenGrade(vector <pair<string, double>>);
void Categorize(vector <pair<string, double>>);

int main()
{
    vector <pair<string, double>> studentsData;
    int number;
    cout<<"Enter number of students: ";
    cin>>number;
    for(int i = 1 ; i <= number ; i++)
    {
        cin.ignore(100,'\n');
        string name;
        double grade;
        cout<<"Enter the name of student "<<i<<" : ";
        getline(cin, name);
        cout<<"Enter his/her grade: ";
        cin>>grade;
        pair<string, double> nameAndGrade;
        nameAndGrade.first = name;
        nameAndGrade.second = grade;
        studentsData.push_back(nameAndGrade);
    }
    cout<<endl<<"-------------------"<<endl;
    cout<<"Average: "<<Average(studentsData)<<endl;
    FirstThreeStudenst(studentsData);
    UnderTenGrade(studentsData);
    Categorize(studentsData);

    return 0;
}

double Average(vector<pair<string, double>> students)
{
    double average = 0;
    for(int i = 0 ; i < students.size() ; i++)
    {
        average += students.at(i).second;
    }
    return average / students.size();
}

void FirstThreeStudenst(vector<pair<string, double>> students)
{
    cout<<"Three first students: "<<endl;
    for(int i = 0 ; i < students.size() - 1 ; i++)
    {
        for(int j = i + 1 ; j < students.size() ; j++)
        {
            if(students.at(i).second < students.at(j).second)
            {
                swap(students.at(i), students.at(j));
            }
        }
    }
    for(int i = 0 ; i < students.size() ; i++)
    {
        if(i >= 3)
            break;
        cout<<"Name: "<<students.at(i).first<<"   Grade: "<<students.at(i).second<<endl;
    }
}

void UnderTenGrade(vector<pair<string, double>> students)
{
    cout<<"Student(s) with grade less than 10: "<<endl;
    for(int i = 0 ; i < students.size() ; i++)
    {
        if(students.at(i).second < 10)
        {
            cout<<"Name: "<<students.at(i).first<<"   Grade: "<<students.at(i).second<<endl;
        }
    }
}

void Categorize(vector<pair<string, double>> students)
{
    for(int i = 0 ; i < students.size() - 1 ; i++)
    {
        for(int j = i + 1 ; j < students.size() ; j++)
        {
            if(students.at(i).second < students.at(j).second)
            {
                swap(students.at(i), students.at(j));
            }
        }
    }
    int groupMembersCount = round(double(students.size()) / double(3));
    if(groupMembersCount < 1)
        groupMembersCount = 1;

    cout<<endl<<"Goup A: "<<endl;
    for(int i = 0 ; i < groupMembersCount ; i++)
    {
        cout<<"Name: "<<students.at(i).first<<"   Grade: "<<students.at(i).second<<endl;
    }
    cout<<endl<<"Group B: "<<endl;
    for(int i = groupMembersCount ; i < 2 * groupMembersCount ; i++)
    {
        cout<<"Name: "<<students.at(i).first<<"   Grade: "<<students.at(i).second<<endl;
    }
    cout<<endl<<"Group C: "<<endl;
    for(int i = 2 * groupMembersCount ; i < students.size() ; i++)
    {
        cout<<"Name: "<<students.at(i).first<<"   Grade: "<<students.at(i).second<<endl;
    }
}
