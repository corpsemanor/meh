#include <string>
#include <vector>
#include <iostream>
#include <fstream> 

using namespace std;

struct Students
{
	pair<string, string>  full_name;
	string birth_date;
	double group, chemistry_grade, physics_grade, math_grade, informatics_grade;
	double gpa;
};

Students stud[10];

int create()
{
	int N;
	ofstream fout("d:\\labs\\lab1_source\\file.txt");
	cout << "Введите количество студентов N (N<10):";
	cin >> N;
	if (N < 10)
	{
		for (int i = 0; i < N; i++)
		{
			cout << "Введите Фамилию И.О. студента номер " << i + 1 << endl;
			cin >> stud[i].full_name.first >> stud[i].full_name.second;
			cout << "Введите номер группы: ";
			cin >> stud[i].group;
			cout << "Введите дату рождения:";
			cin >> stud[i].birth_date;
			cout << "Введите баллы по химии, физике, математие и информатике через пробел: ";
			cin >> stud[i].chemistry_grade >> stud[i].physics_grade >> stud[i].math_grade >> stud[i].informatics_grade;
			stud[i].gpa = (stud[i].physics_grade + stud[i].math_grade + stud[i].informatics_grade + stud[i].chemistry_grade) / 4;
			fout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
			<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;
		}
	}
	else cout << "\nВведите корректное число N и повторите попытку.";
	return 0;
}

int show_file()
{
	ifstream fin("d:\\labs\\lab1_source\\file.txt");
	int i = 0, j;
	do
	{
		fin >> stud[i].full_name.first >> stud[i].full_name.second >> stud[i].birth_date >> stud[i].group >> stud[i].chemistry_grade >>
			stud[i].physics_grade >> stud[i].math_grade >> stud[i].informatics_grade >> stud[i].gpa;

		i++;
		j = i;
	} while (fin.get() != EOF);
	for (int i = 0; i < j - 1; i++)
	{
		cout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
		<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;
	}
	return 0;
}

void showcase()
{
	int n;
	cout << "Добро пожаловать!\nВоспользуйтесь меню:" << endl;
	cout << "\n1.Создание.\n2.Просмотр.\n3.Коррекция.\n4.Решение индивидуального задания." << endl;
	cin >> n;
	switch (n)
	{
	case 1: {create(); break; }

	case 2: {show_file(); break; }

	case 3: {; break; }

	case 4: {; break; }


	default: {cout << "\n\t\t\t\nНеверно выбран кейс. Повторите попытку." << endl; break; }
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	showcase();
}
