#include "fileMaking.h"

string CreateFile(int N) {
	string str = "fout.txt";
	ofstream fout(str);
	for (int i = 0; i < N; i++)
	{
		if (i != N - 1)
		{
			fout << rand() % (N - 1) + 1 << " ";
		}
		else
		{
			fout << rand() % (N - 1) + 1;
		}
	}
	fout.close();
	return str;
}

void compileFile(string str) {
	ifstream fin(str);
	ofstream fout("TestFile.txt");
	if (!fin.is_open()) { return; }
	int temp, next_temp, counter = 0;
	fin >> temp;
	fout << " " << temp;
	while (!fin.eof())
	{

		fin >> next_temp;
		counter++;
		if (!(next_temp >= temp))
		{
			fout << " " << counter << endl;
			counter = 0;
		}
		temp = next_temp;
		fout << " " << next_temp;
		if (fin.eof())
		{
			counter++;
			fout << " " << counter;
		}
	}

	fin.close();
	fout.close();
}

string makeFile() {
	string fileName = "File.txt";

	ifstream fin("TestFile.txt");
	ofstream fout("File.txt");
	string line = "";
	while (!fin.eof())
	{
		getline(fin, line);
		size_t f = line.find_last_of(' ');
		if (fin.eof())
		{
			fout << line.substr(f + 1, string::npos) << line.substr(0, f);
		}
		else {
			fout << line.substr(f + 1, string::npos) << line.substr(0, f) << " ";
		}
	}
	fin.close();
	fout.close();
	remove("TestFile.txt");
	return fileName;
}
