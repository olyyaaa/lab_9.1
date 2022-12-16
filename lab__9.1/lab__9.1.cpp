// lab__9.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <Windows.h> // ������������ ����������� ��������
using namespace std;
enum Course { first, second, third };
string courseStr[] = { "������", "������", "�����" };
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
{ // ������������ ����������� ��������:
	SetConsoleCP(1251); // ������������ ������� win-cp1251 � ���� �����
	SetConsoleOutputCP(1251); // ������������ ������� win-cp1251 � ���� ������
	int N;
	cout << "������ ������� �������� N: "; cin >> N;
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
		cout << "������� ��:" << endl << endl;
		cout << " [1] - �������� ����� � ���������" << endl;
		cout << " [2] - ���� ����� �� �����" << endl;
		cout << " [3] - ���� ������ �� ������," << endl;
		cout << " �� ������� ��� 3 " << endl;
		cout << " [4] - ������� ������������� �����" << endl;
		cout << " [5] - �-�� �������� �� 5 � ������" << endl;
		cout << " [6] - �������� ������������� �� ���� �����" << endl;
		cout << " [7] - ����� ����� � ����" << endl;
		cout << " [8] - ���������� ����� �� �����" << endl << endl;
		cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
		cout << "������ ��������: "; cin >> menuItem;
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
			cout << "���� ������ �� ������ �� ������� ��� 3: " << endl;
			cout << number << ":" << endl;
			break;
		case 4:
			Sort(p, N);
			break;
		case 5:
			cout << "������ ����� ������:" << endl;
			cout << " ���� (0 - ������ 1 - ������, 2 - �����): ";
			cin >> icourse;
			course = (Course)icourse;
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
			cout << " �������: "; getline(cin, prizv);
			cout << endl;
			if ((found = FiveSearch(p, N, prizv, course)) != -1)
				cout << "�������� ���������� � ������� " << found + 1 << endl;
			else
				cout << "�������� ���������� �� ��������" << endl;
			break;
		case 6:
			PrintIndexSorted(p, IndexSort(p, N), N);
			break;
		case 7:
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			SaveToFile(p, N, filename);
			break;
		case 8:
			cin.get(); // ������� ����� ��������� � �� ����������� �������
			cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
			cout << "������ ��'� �����: "; cin.getline(filename, 99);
			LoadFromFile(p, N, filename);
			break;
		case 0:
			break;
		default:
			cout << "�� ����� ��������� ��������! "
				"��� ������ ����� - ����� ��������� ������ ����" << endl;
		}
	} while (menuItem != 0);
	return 0;
}
void Create(Student* p, const int N)
{
	int course;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get(); // ������� ����� ��������� � �� ����������� �������
		cin.sync(); // "����� �����", �� �� ����� ������ ��������� ������� �����
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ������������: "; getline(cin, p[i].speciality);
		cout << " �� ���.: "; cin >> p[i].rik_nar;
		cout << " ���� (0 - ������, 1 - ������, 2 - �����): ";
		cin >> course;
		p[i].course = (Course)course;
		switch (p[i].course)
		{
		case first:
			cout << " ���������� : "; cin >> p[i].math;
			cout << " ������  : "; cin >> p[i].physics;
			cout << " ��������� : "; cin >> p[i].pedagogy;
			cout << " ������� ������: "; cin >> p[i].numerical_methods;
			cout << " ������������� : "; cin >> p[i].programming;
			break;
		case second:
			cout << " ���������� : "; cin >> p[i].math;
			cout << " ������  : "; cin >> p[i].physics;
			cout << " ��������� : "; cin >> p[i].pedagogy;
			cout << " ������� ������: "; cin >> p[i].numerical_methods;
			cout << " ������������� : "; cin >> p[i].programming;
			break;
		case third:
			cout << " ���������� : "; cin >> p[i].math;
			cout << " ������  : "; cin >> p[i].physics;
			cout << " ��������� : "; cin >> p[i].pedagogy;
			cout << " ������� ������: "; cin >> p[i].numerical_methods;
			cout << " ������������� : "; cin >> p[i].programming;
			break;
		}
		cout << endl;
	}
}
void Print(Student* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| � | ������� | ������������ | г�.���.| ���� | Գ���� |����������| ������������� |���������| ������� ������ |"
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
	cout << "������� ��������, �� ������� ��� 3:" << endl;
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
	for (int i0 = 0; i0 < N - 1; i0++) // ����� "���������"
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
{ // ������� �-�� 5 � ������
	int  m = 1;
		if (p[m].physics == 5)
			return m++;
	
}
int* IndexSort(Student* p, const int N)
{ // ������������� ����� ������� ��� ���������� ���������� ������
//
// int i, j, value;
// for (i = 1; i < length; i++) {
// value = a[i];
// for (j = i - 1; j >= 0 && a[j] > value; j--) {
// a[j + 1] = a[j];
// }
// a[j + 1] = value;
// }

	int* I = new int[N]; // �������� ��������� �����
	for (int i = 0; i < N; i++)
		I[i] = i; // ��������� ���� ����������� ������
	int i, j, value; // �������� ��������� ����� �������
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
{ // ��������� ������� Print(), ��� ������ ��������� p[i]...
// ������������� ������ �� ��������� ���������� ������ �: p[I[i]]...
	cout << "========================================================================="
		<< endl;
	cout << "| � | ������� | ������������ | г�.���.| ���� | Գ���� |����������| ������������� |���������| ������� ������ |"
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
	ofstream fout(filename, ios::binary); // ������� ������� ���� ������
	fout.write((char*)&N, sizeof(N)); // �������� ������� ��������
	for (int i = 0; i < N; i++)
		fout.write((char*)&p[i], sizeof(Student)); // �������� �������� ������
	fout.close(); // ������� ����
}
void LoadFromFile(Student*& p, int& N, const char* filename)
{
	delete[] p; // ������� �������� ���
	ifstream fin(filename, ios::binary); // ������� ������� ���� ����������
	fin.read((char*)&N, sizeof(N)); // ��������� ������� ��������
	p = new Student[N]; // �������� ��������� �����
	for (int i = 0; i < N; i++)
		fin.read((char*)&p[i], sizeof(Student)); // ��������� �������� ������
	fin.close(); // ������� ����
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
