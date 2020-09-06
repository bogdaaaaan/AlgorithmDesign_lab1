// Bogdan Glechkovskiy IP-92
#include <iostream>
#include <fstream>
#include <ctime>

const int N = 20; //count numbers in file

using namespace std;

void CreateFile();
void DivideOnFiles();
//void CombineFromThreeFiles();

int main() {
    // CreateFile();
    DivideOnFiles();
    return 0;
}

void DivideOnFiles() {
    ifstream fin("File.txt");
    if (!fin.is_open()){ return; }

    ofstream fout_b1("b1.txt");
    ofstream fout_b2("b2.txt");
    ofstream fout_b3("b3.txt");

    int temp, next_temp, flag = 1;
    fin >> temp;
    fout_b1 << temp << " ";
    while (!fin.eof())
    {
        fin >> next_temp;
        if (!(next_temp >= temp))
        {
            flag++;
            if (flag > 3)
            {
                flag -= 3;
            }
        }
        temp = next_temp;
        if (flag == 1)
        {
            fout_b1 << next_temp << " ";
        }
        if (flag == 2)
        {
            fout_b2 << next_temp << " ";
        }
        if (flag == 3)
        {
            fout_b3 << next_temp << " ";
        }
    }
   
    fin.close();
    fout_b1.close();
    fout_b2.close();
    fout_b3.close();
}

void CreateFile() {
    //srand(time(NULL));
    ofstream fout("File.txt");
    for (int i = 0; i < N; i++)
    {
        if (i != N-1)
        {
            fout << rand() % (N - 1) + 1 << " ";
        }
        else
        {
            fout << rand() % (N - 1) + 1;
        }
       
    }
    fout.close();
}


/*
void CombineFromThreeFiles()
{
    ifstream fin_b1("b1.txt");
    ifstream fin_b2("b2.txt");
    ifstream fin_b3("b3.txt");
    ofstream fout_c1("c1.txt");
    ofstream fout_c2("c2.txt");
    ofstream fout_c3("c3.txt");

    bool end = false;
    int temp1, temp2, temp3, next_temp1,next_temp2, next_temp3;
    int flag = 1;
    fin_b1 >> temp1;
    fin_b2 >> temp2;
    fin_b3 >> temp3;

    while (!end)
    {
        int temp_min = min(temp1, temp2, temp3);
        if (flag == 1)
        {
            fout_c3 << temp_min;
            fin_b1 >> temp1;
        }
        if (flag == 2)
        {
            fout_c2 << temp_min;
            fin_b2 >> temp2;
        }
        if (flag == 3)
        {
            fout_c3 << temp_min;
            fin_b3 >> temp3;
        }
    }


    fin_b1.close();
    fin_b2.close();
    fin_b3.close();
    fout_c1.close();
    fout_c2.close();
    fout_c3.close();
}
*/