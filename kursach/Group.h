#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "student.h"
#include "all_func.h"
using namespace std;
class Group
{
public:
	string name;
	vector<Student>students;
	int number_of_students;
	int semesters;
	Group()
	{
		number_of_students = students.size();
	}
	void set_students(Student student)
	{
		students.push_back(student);
	}
	void set_name(string group_name)
	{
		name = group_name;
	}
	string get_name()
	{
		return name;
	}
	vector<Student> get_students()
	{
		return students;
	}
	int get_semesters()
	{
		return semesters;
	}
	void set_semester(int group_semester)
	{
		semesters = group_semester;
	}
	void save_in_file()
	{
		fstream fl;
		string path = name + ".txt";
		fl.open(path, fstream::in | fstream::app | fstream::out);
		fl << name << " ";
		fl << number_of_students << " ";
		fl << semesters << " ";
		for (int i = 0; i < students.size(); i++)
		{
			fl << students[i] << endl;
		}
		fl.close();
	}
	void print_group()
	{
		cout << "Name: " << name << " ";
		cout << "Semester: " << semesters << " ";
		//cout << "Number of students: " << number_of_students << endl;
		for (int i = 0; i < students.size(); i++)
			cout << students[i] << endl;
	}
};