#include <iostream>
#include <thread>
#include <vector> 
#include <fstream> 
#include <iostream> 
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <string>
#include <list>
#include <iostream>
using namespace std;
int d[100][100];
#define MAX(x,y) ((x) > (y) ? (x) : (y));

// m =3   
int  globalEdit(string sm, string sn, int r = -1, int d = -1, int i_ = -1, int m_ = 1) {
	int n = sm.length() + 1;
	int m = sn.length() + 1;


	static int matrix[40][40];
	//for (int i = 0; i < m; i++)
	//{
	//	matrix[i] = new int[n];
	//}
	matrix[0][0] = 0;
	for (int i = 1; i < m; i++)
	{
		matrix[i][0] = matrix[i - 1][0] + d;
	}
	for (int j = 1; j < n; j++)
	{
		matrix[0][j] = matrix[0][j - 1] + i_;

	}
	int cost = r;

	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			if (sm[j - 1] == sn[i - 1]) {
				cost = m_;
			}
			else {
				cost = r;
			}
			int cal_cost = matrix[i - 1][j - 1] + cost;
			int temp = MAX(matrix[i - 1][j] + d, matrix[i][j - 1] + i_);
			matrix[i][j] = MAX(temp, cal_cost);
			//printf("%d,", matrix[i][j]);
		}//printf("\n");
	}
	int reture_score = matrix[m - 1][n - 1];
	return reture_score;

}










void calProcess(string intpu_file_name, string output_file_name, int num)
{
	std::cout << "A new111 thread!" << std::endl;
	ifstream dicfile("dict.txt");
	ifstream missfile(intpu_file_name);
	ofstream outfile(output_file_name, ios::app);
	string misspell1[8000];
	static string dirct[370099];
	if (!dicfile.is_open() || !missfile.is_open())
	{
		cout << "unsuccessful open the file" << endl;
	}

	string mistemp;
	string dictemp;

	int i = 0;
	while (getline(missfile, mistemp))
	{
		misspell1[i] = mistemp;
		i++;
	}

	i = 0;
	while (getline(dicfile, dictemp))
	{
		dirct[i] = dictemp;
		i++;
	}

	list<string>::iterator iter;

	for (int i = 0; i < num; i++)
	{
		int score = -999;
		string str = "";
		for (int j = 0; j < 370099; j++) {
			int cal_score = globalEdit(misspell1[i], dirct[j]);
			if (score < cal_score) {

				score = cal_score;
				str = dirct[j];
			}
			else if (score == cal_score) {

				str = str + "," + dirct[j];

			}
		}

		outfile << str;
		outfile << endl;
	}


	dicfile.close();
	outfile.close();

}







void calProcess1(string intpu_file_name, string output_file_name, int num)
{
	std::cout << "A new111 thread!" << std::endl;
	ifstream dicfile("dict.txt");
	ifstream missfile(intpu_file_name);
	ofstream outfile(output_file_name, ios::app);
	string misspell1[8000];
	static string dirct[370099];
	if (!dicfile.is_open() || !missfile.is_open())
	{
		cout << "unsuccessful open the file" << endl;
	}

	string mistemp;
	string dictemp;

	int i = 0;
	while (getline(missfile, mistemp))
	{
		misspell1[i] = mistemp;
		i++;
	}

	i = 0;
	while (getline(dicfile, dictemp))
	{
		dirct[i] = dictemp;
		i++;
	}

	list<string>::iterator iter;

	for (int i = 0; i < num; i++)
	{
		int score = -999;
		string str = "";
		for (int j = 0; j < 370099; j++) {
			int cal_score = globalEdit(misspell1[i], dirct[j]);
			if (score < cal_score) {

				score = cal_score;
				str = dirct[j];
			}
			else if (score == cal_score) {

				str = str + "," + dirct[j];

			}
		}

		outfile << str;
		outfile << endl;
	}


	dicfile.close();
	outfile.close();

}



void calProcess2(string intpu_file_name, string output_file_name, int num)
{
	std::cout << "A new111 thread!" << std::endl;
	ifstream dicfile("dict.txt");
	ifstream missfile(intpu_file_name);
	ofstream outfile(output_file_name, ios::app);
	string misspell1[8000];
	static string dirct[370099];
	if (!dicfile.is_open() || !missfile.is_open())
	{
		cout << "unsuccessful open the file" << endl;
	}

	string mistemp;
	string dictemp;

	int i = 0;
	while (getline(missfile, mistemp))
	{
		misspell1[i] = mistemp;
		i++;
	}

	i = 0;
	while (getline(dicfile, dictemp))
	{
		dirct[i] = dictemp;
		i++;
	}

	list<string>::iterator iter;

	for (int i = 0; i < num; i++)
	{
		int score = -999;
		string str = "";
		for (int j = 0; j < 370099; j++) {
			int cal_score = globalEdit(misspell1[i], dirct[j]);
			if (score < cal_score) {

				score = cal_score;
				str = dirct[j];
			}
			else if (score == cal_score) {

				str = str + "," + dirct[j];

			}
		}

		outfile << str;
		outfile << endl;
	}


	dicfile.close();
	outfile.close();

}



void calProcess3(string intpu_file_name, string output_file_name, int num)
{
	std::cout << "A new111 thread!" << std::endl;
	ifstream dicfile("dict.txt");
	ifstream missfile(intpu_file_name);
	ofstream outfile(output_file_name, ios::app);
	string misspell1[8000];
	static string dirct[370099];
	if (!dicfile.is_open() || !missfile.is_open())
	{
		cout << "unsuccessful open the file" << endl;
	}

	string mistemp;
	string dictemp;

	int i = 0;
	while (getline(missfile, mistemp))
	{
		misspell1[i] = mistemp;
		i++;
	}

	i = 0;
	while (getline(dicfile, dictemp))
	{
		dirct[i] = dictemp;
		i++;
	}

	list<string>::iterator iter;

	for (int i = 0; i < num; i++)
	{
		int score = -999;
		string str = "";
		for (int j = 0; j < 370099; j++) {
			int cal_score = globalEdit(misspell1[i], dirct[j]);
			if (score < cal_score) {

				score = cal_score;
				str = dirct[j];
			}
			else if (score == cal_score) {

				str = str + "," + dirct[j];

			}
		}

		outfile << str;
		outfile << endl;
	}


	dicfile.close();
	outfile.close();

}

void calProcess4(string intpu_file_name, string output_file_name, int num)
{
	std::cout << "A new111 thread!" << std::endl;
	ifstream dicfile("dict.txt");
	ifstream missfile(intpu_file_name);
	ofstream outfile(output_file_name, ios::app);
	string misspell1[8000];
	static string dirct[370099];
	if (!dicfile.is_open() || !missfile.is_open())
	{
		cout << "unsuccessful open the file" << endl;
	}

	string mistemp;
	string dictemp;

	int i = 0;
	while (getline(missfile, mistemp))
	{
		misspell1[i] = mistemp;
		i++;
	}

	i = 0;
	while (getline(dicfile, dictemp))
	{
		dirct[i] = dictemp;
		i++;
	}

	list<string>::iterator iter;

	for (int i = 0; i < num; i++)
	{
		int score = -999;
		string str = "";
		for (int j = 0; j < 370099; j++) {
			int cal_score = globalEdit(misspell1[i], dirct[j]);
			if (score < cal_score) {

				score = cal_score;
				str = dirct[j];
			}
			else if (score == cal_score) {

				str = str + "," + dirct[j];

			}
		}

		outfile << str;
		outfile << endl;
	}


	dicfile.close();
	outfile.close();

}



void calProcess5(string intpu_file_name, string output_file_name, int num)
{
	std::cout << "A new111 thread!" << std::endl;
	ifstream dicfile("dict.txt");
	ifstream missfile(intpu_file_name);
	ofstream outfile(output_file_name, ios::app);
	string misspell1[8000];
	static string dirct[370099];
	if (!dicfile.is_open() || !missfile.is_open())
	{
		cout << "unsuccessful open the file" << endl;
	}

	string mistemp;
	string dictemp;

	int i = 0;
	while (getline(missfile, mistemp))
	{
		misspell1[i] = mistemp;
		i++;
	}

	i = 0;
	while (getline(dicfile, dictemp))
	{
		dirct[i] = dictemp;
		i++;
	}

	list<string>::iterator iter;

	for (int i = 0; i < num; i++)
	{
		int score = -999;
		string str = "";
		for (int j = 0; j < 370099; j++) {
			int cal_score = globalEdit(misspell1[i], dirct[j]);
			if (score < cal_score) {

				score = cal_score;
				str = dirct[j];
			}
			else if (score == cal_score) {

				str = str + "," + dirct[j];

			}
		}

		outfile << str;
		outfile << endl;
	}


	dicfile.close();
	outfile.close();

}



void fun1() {

	calProcess("ceshi1.txt","out1.txt",1000);
}
void fun2() {

	calProcess("ceshi2.txt", "out2.txt", 1000);
}
void fun3() {

	calProcess("ceshi3.txt", "out3.txt", 1000);
}
void fun4() {

	calProcess("ceshi4.txt", "out4.txt", 1000);
}
void fun5() {

	calProcess("ceshi5.txt", "out5.txt", 1000);
}
void fun6() {

	calProcess5("ceshi6.txt", "out6.txt", 1000);
}





void fun7() {

	calProcess4("ceshi7.txt", "out7.txt", 1000);
}
void fun8() {

	calProcess3("ceshi8.txt", "out8.txt", 1000);
}


void fun9() {

	calProcess2("ceshi9.txt", "out9.txt", 1000);
}
void fun10() {

	calProcess1("ceshi10.txt", "out10.txt", 1000);
}


void fun11() {

	calProcess("ceshi11.txt", "out11.txt", 322);
}



int main()
{

	std::thread t1(fun1);
	std::thread t2(fun2);
	std::thread t3(fun3);
	std::thread t4(fun4);
	std::thread t5(fun5);
	std::thread t6(fun6);
	std::thread t7(fun7);
	std::thread t8(fun8);
	std::thread t9(fun9);
	std::thread t10(fun10);
	std::thread t11(fun11);
	t1.join();
	t2.join();
	t3.join();
	t4.join();	
	t5.join();
	t6.join();
	t7.join();
	t8.join();
	t9.join();
	t10.join();
	t11.join();



	std::cout << "Main thread!" << std::endl;





}