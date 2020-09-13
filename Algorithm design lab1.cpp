#include <iostream>
#include <queue>
#include <direct.h>
#include "fileMaking.h"

using namespace std;

// Базовый файл с данными
class BaseFile
{
public:
	BaseFile(string file);
	~BaseFile();
	void sort();
	queue<string> getfiles() {
		return _queue;
	};
protected:
	string NameOfFile;
	queue<string> _queue;
};

BaseFile::BaseFile(string file)
{
	NameOfFile = file;
}

BaseFile::~BaseFile()
{
}
void BaseFile::sort()
{
	ifstream fin(NameOfFile);
	int temp, iter = 1, num = 0;
	string fileNames = "tests\\b";
	// Пока не конец основного файла
	while (!fin.eof()) {
		fin >> num;
		// Создаем вспомогательные файлы и вносим их в очередь
		fileNames += to_string(iter);
		fileNames += ".txt";
		_queue.push(fileNames);

		ofstream fout(fileNames);
		for (int i = 0; i < num; i++) {
			fin >> temp;
			fout << temp;
			if (i < num - 1) {
				fout << " ";
			}
		}
		fout.close();
		fileNames = "tests\\b";
		iter++;
	}
}

// Доп. файлы
class AdditionalFiles
{
public:
	AdditionalFiles(queue<string> inf);
	~AdditionalFiles();
	void sorting();
	string getresult() {
		return _queue.front();
	}
protected:
	queue<string> _queue;
	int i = 0;
};

AdditionalFiles::AdditionalFiles(queue<string> inf)
{
	_queue = inf;
}

AdditionalFiles::~AdditionalFiles()
{
}

void AdditionalFiles::sorting()
{
	string fileNames = "tests\\c";
	int temp1 = 0, temp2 = 0, iter = 1;
	string file1, file2;
	bool first, second;
	while (_queue.size() > 1) {
		first = true;
		second = true;
		file1 = _queue.front();
		_queue.pop();
		file2 = _queue.front();
		_queue.pop();
		ifstream fin1(file1);
		ifstream fin2(file2);
		fileNames += to_string(iter);
		fileNames += ".txt";
		ofstream fout(fileNames);
		_queue.push(fileNames);
		while (!fin1.eof() && !fin2.eof()) {

			if (first) {
				fin1 >> temp1; 
			}
			if (second) {
				fin2 >> temp2;
			}
			if (temp2 > temp1) { 
				fout << " " << temp1;
				second = false; 
				first = true;
			}
			else if (temp2 == temp1) {
				fout << " " << temp1 << " " << temp2;
				first = true;
				second = true; 
			}
			else {
				fout << " " << temp2;
				second = true; 
				first = false;
			}

			if (fin1.eof()) {
				while (!fin2.eof()) {
					fin2 >> temp2;
					fout << " " << temp2; 
				}
			}
			if (fin2.eof()) {
				while (!fin1.eof()) {
					fin1 >> temp1;
					fout << " " << temp1;
				}
			}

		}
		fin1.close();
		fin2.close(); 
		fout.close();
		fileNames = "tests\\c";
		iter++;
	}
	
}

void makeResult(string fileName) {
	ifstream fin(fileName);
	ofstream fout("Result.txt");
	int x;
	while (!fin.eof())
	{
		fin >> x;
		fout << x << " ";
	}
}

int main()
{

	string filename = CreateFile(20);

	//string filename = "File.txt";
	compileFile(filename);
	string fileName = makeFile();
	

	BaseFile base_file(fileName);
	// Разбиение по доп. файлам
	base_file.sort();

	AdditionalFiles additional_files(base_file.getfiles());
	// Присоединение серий
	additional_files.sorting();
	makeResult(additional_files.getresult());
}

