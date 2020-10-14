#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Group.h"
#include "all_func.h"
using namespace std;
class Student {
public:

	string first_name;
	string second_name;
	string middle_name;
	float average_ball;
	int course;
	string faculty;
	int age;
	vector<int>ball;
	Student()
	{}
	~Student() {}
	void army()
	{
		if (age > 17 && age < 28)
		{
			cout << first_name << " " << second_name << endl;
		}
	}
	void set_first_name(string name)
	{
		first_name = name + " ";
	}
	void set_second_name(string name)
	{
		second_name = name + " ";
	}
	void set_age(int student_age)
	{
		age = student_age;
	}
	void set_ball(int student_ball)
	{
		ball.push_back(student_ball);
	}
	void save_student_in_file(fstream& file)
	{
		//string group_name = group.get_name();
		string student_info;
		student_info = first_name + " " + second_name;
		//file << group_name << " ";
		cout << " ";
		file << student_info << " ";
		file << age << " ";
	}
};
istream& operator >> (istream& is, Student& student)
{
	cout << "First name: ";
	is >> student.first_name;
	cout << "Second name: ";
	is >> student.second_name;
	cout << "Age ";
	is >> student.age;
	return is;
}
ostream& operator<<(ostream& os, const Student& student)
{
	os << student.first_name << student.second_name << student.age << endl;
	return os;
}
void show_data_file(fstream &ifs) {
	string data((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
	cout << data;
}
vector<Student>sorter(fstream &file)
{
	vector<Student>sorter;
	Student student;
	string group;
	while (!file.eof())
	{
		file >> group >> student.first_name >> student.second_name >> student.age;
		sorter.push_back(student);
	}
	return sorter;
}
