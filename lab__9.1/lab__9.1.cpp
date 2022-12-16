// lab__9.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> // забезпечення відображення кирилиці
using namespace std;
enum Course { first, second, third };
string courseStr[] = { "перший", "другий", "третій" };
struct Student
{
	union aditioanal
	{
		int years;
		int work;
	};
	string prizv;
	string speciality;
	unsigned rik_nar;
	Course course;
	double physics;
	string math;
	int programming;
	int pedagogy;
	int numerical_methods;
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
double LineSearch(Student* p, const int N);
void Sort(Student* p, const int N);
int FiveSearch(Student* p, const int N, const string prizv, const Course course);
int* IndexSort(Student* p, const int N);
void PrintIndexSorted(Student* p, int* I, const int N);
void SaveToFile(Student* p, const int N, const char* filename);
void LoadFromFile(Student*& p, int& N, const char* filename);
int main()
{ // забезпечення відображення кирилиці:
	SetConsoleCP(1251); // встановлення сторінки win-cp1251 в потік вводу
	SetConsoleOutputCP(1251); // встановлення сторінки win-cp1251 в потік виводу
	int N;
	cout << "Введіть кількість студентів N: "; cin >> N;
	Student* p = new Student[N];
	string prizv;
	string speciality;
	unsigned rik_nar;
	Course course;
	double physics;
	int math;
	int programming;
	int pedagogy;
	int numerical_methods;
	int found;
	char filename[100];
	int menuItem;
	double number;
	int icourse;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію:" << endl << endl;
		cout << " [1] - введення даних з клавіатури" << endl;
		cout << " [2] - вивід даних на екран" << endl;
		cout << " [3] - вивід прізвищ та оцінок," << endl;
		cout << " які вчаться без 3 " << endl;
		cout << " [4] - фізичне впорядкування даних" << endl;
		cout << " [5] - к-ть студентів за 5 з фізики" << endl;
		cout << " [6] - індексне впорядкування та вивід даних" << endl;
		cout << " [7] - запис даних у файл" << endl;
		cout << " [8] - зчитування даних із файлу" << endl << endl;
		cout << " [0] - вихід та завершення роботи програми" << endl << endl;
		cout << "Введіть значення: "; cin >> menuItem;
		cout << endl << endl << endl;
		switch (menuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			number = LineSearch(p, N);
			cout << "вивід прізвищ та оцінок які вчаться без 3: " << endl;
			cout << number << ":" << endl;
			break;
		case 4:
			Sort(p, N);
			break;
		case 5:
			cout << "Введіть ключі пошуку:" << endl;
			cout << " курс (0 - перший 1 - другий, 2 - третій): ";
			cin >> icourse;
			course = (Course)icourse;
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			cout << " прізвище: "; getline(cin, prizv);
			cout << endl;
			if ((found = FiveSearch(p, N, prizv, course)) != -1)
				cout << "Знайдено працівника в позиції " << found + 1 << endl;
			else
				cout << "Шуканого працівника не знайдено" << endl;
			break;
		case 6:
			PrintIndexSorted(p, IndexSort(p, N), N);
			break;
		case 7:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 8:
			cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
			cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
			cout << "Введіть ім'я файлу: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели помилкове значення! "
				"Слід ввести число - номер вибраного пункту меню" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int course;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get(); // очищуємо буфер клавіатури – бо залишаються символи
		cin.sync(); // "кінець рядка", які не дають ввести наступний літерний рядок
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " спеціальність: "; getline(cin, p[i].speciality);
		cout << " рік нар.: "; cin >> p[i].rik_nar;
		cout << " курс (0 - перший, 1 - другий, 2 - третій): ";
		cin >> course;
		p[i].course = (Course)course;
		switch (p[i].course)
		{
		case first:
			cout << " математика : "; cin >> p[i].math;
			cout << " фізика  : "; cin >> p[i].physics;
			cout << " педагогіка : "; cin >> p[i].pedagogy;
			cout << " чисельні методи: "; cin >> p[i].numerical_methods;
			cout << " програмування : "; cin >> p[i].programming;
			break;
		case second:
			cout << " математика : "; cin >> p[i].math;
			cout << " фізика  : "; cin >> p[i].physics;
			cout << " педагогіка : "; cin >> p[i].pedagogy;
			cout << " чисельні методи: "; cin >> p[i].numerical_methods;
			cout << " програмування : "; cin >> p[i].programming;
			break;
		case third:
			cout << " математика : "; cin >> p[i].math;
			cout << " фізика  : "; cin >> p[i].physics;
			cout << " педагогіка : "; cin >> p[i].pedagogy;
			cout << " чисельні методи: "; cin >> p[i].numerical_methods;
			cout << " програмування : "; cin >> p[i].programming;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| № | Прізвище | Спеціальність | Рік.нар.| Курс | Фізика |Математика| Програмування |Педагогіка| Чисельні методи |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[i].prizv
			<< "| " << setw(4) << right << p[i].speciality << " "
			<< "| " << setw(13) << left << p[i].rik_nar
			<< "| " << setw(4) << right << p[i].course << " "
			<< "| " << setw(13) << left << p[i].physics
			<< "| " << setw(4) << right << p[i].math << " "
			<< "| " << setw(13) << left << p[i].programming
			<< "| " << setw(4) << right << p[i].pedagogy << " "
			<< "| " << setw(13) << left << p[i].numerical_methods;
		switch (p[i].course)
		{
		case first:
			cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
				<< p[i].math << " |" << endl;
			switch (p[i].course)
				break;
		case second:
		case third:
			cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
				<< p[i].physics << " |" << endl;
			break;
		}
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}
double LineSearch(Student* p, const int N)
{
	cout << "Прізвища студентів, які вчаться без 3:" << endl;
	int k = 0, n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].course == first)

		{
			n++;
			if (p[i].physics > 3)
			{
				k++;
				cout << setw(3) << right << k
					<< " " << p[i].physics << endl;
			}
		}
	}
	return 100.0 * k / n;
}
void Sort(Student* p, const int N)
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) // метод "бульбашки"
		for (int i1 = 0; i1 < N - i0 - 1; i1++)
			if ((p[i1].course > p[i1 + 1].course)
				||
				(p[i1].course == p[i1 + 1].course &&
					p[i1].prizv > p[i1 + 1].prizv))
			{
				tmp = p[i1];
				p[i1] = p[i1 + 1];
				p[i1 + 1] = tmp;
			}
}
int FiveSearch(Student* p, const int N, const string prizv, const Course course)
{ // повертає к-ть 5 з фізики
	int  m = 1;
		if (p[m].physics == 5)
			return m++;
	
}
int* IndexSort(Student* p, const int N)
{ // використовуємо метод вставки для формування індексного масиву
//
// int i, j, value;
// for (i = 1; i < length; i++) {
// value = a[i];
// for (j = i - 1; j >= 0 && a[j] > value; j--) {
// a[j + 1] = a[j];
// }
// a[j + 1] = value;
// }

	int* I = new int[N]; // створили індексний масив
	for (int i = 0; i < N; i++)
		I[i] = i; // заповнили його початковими даними
	int i, j, value; // починаємо сортувати масив індексів
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1;
			j >= 0 && ((p[I[j]].course > p[value].course) ||
				(p[I[j]].course == p[value].course &&
					p[I[j]].prizv > p[value].prizv));
			j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}
void PrintIndexSorted(Student* p, int* I, const int N)
{ // аналогічно функції Print(), але замість звертання p[i]...
// використовуємо доступ за допомогою індексного масиву І: p[I[i]]...
	cout << "========================================================================="
		<< endl;
	cout << "| № | Прізвище | Спеціальність | Рік.нар.| Курс | Фізика |Математика| Програмування |Педагогіка| Чисельні методи |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(13) << left << p[I[i]].prizv
			<< "| " << setw(4) << right << p[I[i]].rik_nar << " "
			<< "| " << setw(11) << left << courseStr[p[I[i]].course];
		switch (p[I[i]].course)
		{
		case first:
			cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
				<< p[i].math << " |" << endl;
			switch (p[i].course)
				break;
		case second:
		case third:
			cout << "| " << setw(11) << right << "|" << " " << setw(8) << right
				<< p[i].physics << " |" << endl;
			break;
		}
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}
void SaveToFile(Student* p, const int N, const char* filename)
{
	ofstream fout(filename, ios::binary); // відкрили бінарний файл запису
	fout.write((char*)&N, sizeof(N)); // записали кількість елементів
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Student)); // записали елементи масиву
	fout.close(); // закрили файл
}
void LoadFromFile(Student*& p, int& N, const char* filename)
{
	delete[] p; // знищили попередні дані
	ifstream fin(filename, ios::binary); // відкрили бінарний файл зчитування
	fin.read((char*)&N, sizeof(N)); // прочитали кількість елементів
	p = new Student[N]; // створили динамічний масив
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Student)); // прочитали елементи масиву
	fin.close(); // закрили файл
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
