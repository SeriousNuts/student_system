#pragma once
#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Group.h"
#include "student.h"
using namespace std;
//istream& operator >> (istream& is, Student& student)
//{
//	cout << "First name: ";
//	is >> student.first_name;
//	cout << "Second name: ";
//	is >> student.second_name;
//	cout << "Age ";
//	is >> student.age;
//	return is;
//}
//ostream& operator<<(ostream& os, const Student& student)
//{
//	os << student.first_name << student.second_name << student.age << endl;
//	return os;
//}
//void show_data_file(fstream &ifs) {
//	string data((istreambuf_iterator<char>(ifs)), istreambuf_iterator<char>());
//	cout << data;
//}
//vector<Student>sorter(fstream &file)
//{
//	vector<Student>sorter;
//	Student student;
//	int count = 0;
//	while (!file.eof())
//	{
//		file >> student.first_name >> student.second_name;
//		sorter.push_back(student);
//	}
//	return sorter;
//}
