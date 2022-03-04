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

void showcase();

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
	showcase();
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

	showcase();
	return 0;
}

int correct()
{
	ifstream fin("d:\\labs\\lab1_source\\file.txt");
	int i = 0, j, N;
	int option;
	do
	{
		fin >> stud[i].full_name.first >> stud[i].full_name.second >> stud[i].birth_date >> stud[i].group >> stud[i].chemistry_grade >>
			stud[i].physics_grade >> stud[i].math_grade >> stud[i].informatics_grade >> stud[i].gpa;

		i++;
		j = i;
	} while (fin.get() != EOF);

	cout << "\nCписок:" << endl;
	for (int i = 0; i < j - 1; i++)
	{
		cout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
			<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;
	}
	cout << "Введите номер студента, которого нужно корректировать: " << endl;
	cin >> N;
	cout << "Выберите что нужно откорректировать:\n1.Имя\n2.Дата рождения\n3.Группа.\n4.Оценки." << endl;
	cin >> option;

	do
	{

		do
		{
			fin >> stud[i].full_name.first >> stud[i].full_name.second >> stud[i].birth_date >> stud[i].group >> stud[i].chemistry_grade >>
				stud[i].physics_grade >> stud[i].math_grade >> stud[i].informatics_grade >> stud[i].gpa;

			i++;
			j = i;
		} while (fin.get() != EOF);

		ofstream fout("d:\\labs\\lab1_source\\file.txt");

		for (int i = 0; i < j - 2; i++)
		{
			if ((i + 1) != N)
			{

				fout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
					<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;

			}
			else
			{


				switch (option)
				{
				case 1:
				{
					cout << "\nВведите корректоне значение:";
					cin >> stud[i].full_name.second>>stud[i].full_name.second;
					fout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
						<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;
					break;
				}
				case 2:
				{
					cout << "\nВведите корректоне значение:";
					cin >> stud[i].birth_date;
					fout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
						<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;
					break;

				}
				case 3:
				{
					cout << "\nВведите корректоне значение:";
					cin >> stud[i].group;
					fout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
						<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;
					break;
				}
				case 4:
				{
					
					cout << "\nВведите корректоне значение (Химия, физика, математика, информатика.):";
					cin >> stud[i].chemistry_grade >> stud[i].physics_grade >> stud[i].math_grade >> stud[i].informatics_grade;
					stud[i].gpa = (stud[i].physics_grade + stud[i].math_grade + stud[i].informatics_grade + stud[i].chemistry_grade) / 4;
					fout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
						<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;
					break;
				}

				default: {cout << "Некорректный вариант. Повторите попытку."; break; }
				}

			}
		}
	} while (fin.get() != EOF);

	cout << "\nОткорректированный список:" << endl;
	i = 0;
	for (int i = 0; i < j - 2; i++)
	{
		cout << stud[i].full_name.first << " " << stud[i].full_name.second << " " << stud[i].birth_date << " " << stud[i].group << " " << stud[i].chemistry_grade << " " << stud[i].physics_grade
		<< " " << stud[i].math_grade << " " << stud[i].informatics_grade << " " << stud[i].gpa << endl;
	}
	showcase();
	return 0;
}

int exit()
{
	cout << "\n\t\t\t\t\t\tДо встречи!" << endl;
	return 0;
}

void showcase()
{
	int n;
	cout << "\nВоспользуйтесь меню:" << endl;
	cout << "\n1.Создание.\n2.Просмотр.\n3.Коррекция.\n4.Решение индивидуального задания.\n5.Выход." << endl;
	cin >> n;
	switch (n)
	{
	case 1: {create(); break; }

	case 2: {show_file(); break; }

	case 3: {correct(); break; }

	case 4: {; break; }

	case 5: {exit(); break; }

	default: {cout << "\nНеверно выбран кейс. Повторите попытку." << endl; break; }
	}
	cout << endl;
}


int main()
{
	setlocale(LC_ALL, "Rus");
	showcase();
}
