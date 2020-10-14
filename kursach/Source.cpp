#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>
#include <vector>
#include <fstream>
#include <Windows.h>
#include "Group.h"
#include "student.h"
#include "all_func.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<Student>students;
	Student *student1 = new Student;
	Group group;
	int value;
	string base = "data_base.txt";
	fstream stud;
	string group_base = "groups.txt";
	fstream grp;
	string path_grp = "All_groups.txt";
	bool flag_menu = true;
	string line;
	string ball_file = "balls.txt";
	fstream balls;
	stud.open(base, fstream::in | fstream::out | fstream::app);
	students = sorter(stud);
	if (!stud.is_open())
	{
		cout << "File could not open";
		return 2;
		stud.close();
	}
	stud.close();
	while (flag_menu)
	{
		cout << "-----MAIN MENU-----" << endl;
		cout << "Add student 1." << endl;
		cout << "Find student 2." << endl;
		cout << "All students 3." << endl;
		cout << "Add mark to student 4." << endl;
		cout << "Add group 5." << endl;
		cout << "Set group semesters 6." << endl;
		cout << "Students older militate age 7." << endl;
		cout << "Exit " << endl;
		stud.open(base, fstream::in | fstream::out | fstream::app);
		cin >> value;
		switch (value)
		{
		case 1:
		{
			grp.open(path_grp, fstream::in | fstream::out | fstream::app);
			show_data_file(grp);
			cout << endl;
			cout << "Choose group and enter it" << endl;
			string group_name;
			cin >> group_name;
			group.set_name(group_name);
			string name;
			string last_name;
			int student_age;
			// Ввод имени с клавиатуры
			cout << "Name: ";
			cin >> name;
			student1->set_first_name(name);
			// Ввод фамилии
			cout << "Last name: ";
			cin >> last_name;
			student1->set_second_name(last_name);
			//Ввод возраста 
			cout << "Age: ";
			cin >> student_age;
		    student1->set_age(student_age);
			group.set_students(*student1);
			stud << endl << group.name << " ";
			student1->save_student_in_file(stud);
			group.save_in_file();
			grp.close();
			stud.close();
			system("cls");
			break;
		}
		case 2://поиск
		{
			string search;
			cout << "Finder: ";
			cin >> search;
			while (getline(stud, line)) { 
				if (line.find(search, 0) != string::npos)
				{
					cout << line << endl;
				}
			}
			_getch();
			stud.close();
			system("cls");
			break;
		}
		case 3:
		{
			show_data_file(stud);
			stud.close();
			_getch();
			system("cls");
			break;
		}
		case 4://добавление баллов
		{
			grp.open(path_grp, fstream::in | fstream::out | fstream::app);
			show_data_file(grp);
			cout << endl;
			cout << "Choose group and enter it" << endl;
			string group_name;
			cin >> group_name;
			group.set_name(group_name);
			cout << "Choose your student" << endl;
			string first_name;
			string second_name;
			cout << "Enter first name" << endl;
			cin >> first_name;
			cout << "Enter second name" << endl;
			cin >> second_name;
			student1->set_first_name(first_name);
			student1->set_second_name(second_name);
			cout << "Enter ball" << endl;
			int ball;
			cin >> ball;
			student1->set_ball(ball);
			balls.open(ball_file, fstream::in | fstream::out | fstream::app);

			grp.close();
			stud.close();
			system("cls");
			break;
		}
		case 5://Добавление группы
		{
			string name;
			cin >> name;
			group.set_name(name);
			grp.open(path_grp, fstream::in | fstream::out | fstream::app);
			grp << name << "  ";
			grp.close();
			stud.close();
			system("cls");
			break;
		}
		case 6:
		{
			grp.open(path_grp, fstream::in | fstream::out | fstream::app);
			show_data_file(grp);
			cout << endl;
			cout << "Choose group and enter it" << endl;
			string group_name;
			cin >> group_name;
			group.set_name(group_name);
			cout << "Enter number of semesters" << endl;
			int number_of_semesters;
			cin >> number_of_semesters;
			group.set_semester(number_of_semesters);
			stud.close();
			grp.close();
			system("cls");
			break;
		}
		case 7:
		{
			cout << "Military age students: " << endl;
			for (int i = 0; i < students.size(); i++)
			{
				students[i].army();
			}
			_getch();
			system("cls");
			stud.close();
			break;
		}
		case 8:
		{

		}
		default:
			flag_menu = false;
			break;
		}
	}
	stud.close();
	_getch();
	return 0;
}