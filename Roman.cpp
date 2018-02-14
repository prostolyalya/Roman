#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string nameFile;

int main()
{
	int sum,k,ks,z,d,l,v,s;
	cout << "Input text file name('roman.txt') -> ";
	cin >> nameFile;
	ifstream file(nameFile);
	std::string line;
	vector<string> mass;
	vector<int> massive;
	s = 0;
	for (int i = 0; getline(file, line); i++)
	{
		mass.push_back(line);
		sum = z = 0;
		k = ks = 1;
		d = l = v = 0;
		for (int u = 0; u < line.size(); u++)
		{
			if (k >= ks)
				ks = k;
			else
			{
				massive.push_back(0);
				break;
			}
			if (line[u] == 'M')
			{
				sum += 1000;
				k = 1;
			}
			else if (line[u] == 'D')
			{
				sum += 500;
				k = 2;
				d++;
				if (d > 1)
				{
					massive.push_back(0);
					break;
				}
			}
			else if (line[u] == 'C')
			{
				sum += 100;
				k = 3;
			}
			else if (line[u] == 'L')
			{
				sum += 50;
				k = 4;
				l++;
				if (l > 1)
				{
					massive.push_back(0);
					break;
				}
			}
			else if (line[u] == 'X')
			{
				sum += 10;
				k = 5;
			}
			else if (line[u] == 'V')
			{
				sum += 5;
				k = 6;
				v++;
				if (v > 1)
				{
					massive.push_back(0);
					break;
				}
			}
			else if (line[u] == 'I')
			{
				k = 7;
				if (line[u + 1] == 'X')
				{
					sum += 9;
					massive.push_back(sum);
					break;
				}
				else if (line[u + 1] == 'V')
				{
					sum += 4;
					massive.push_back(sum);
					break;
				}
				else
				{
					z++;
					sum += 1;
					if (z > 3)
					{
						massive.push_back(0);
						break;
					}
				}
			}
			if (u == line.size() - 1) massive.push_back(sum);
		}
		if (massive[i]!=0)
		s++;
	}
		cout << "The number of characters saved by writing each of these in their minimal form -> " << s << endl;
		system("pause");
    return 0;
}

