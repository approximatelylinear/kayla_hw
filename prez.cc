#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

ifstream prez;
ofstream output;


int main()
{
	prez.open("prez.dat");
	struct
	{
		int chronum;
		char pname[25];
		int next;
	} plist[50];
	int linecount = 0;

	while (!prez.eof())
	{
/*		if (plist[linecount].pname == "") {
			prez.getline(plist[linecount].pname, 25, '\n');
			continue;
		}*/
		plist[linecount].chronum = linecount;
		prez.getline(plist[linecount].pname, 25, '\n');
	/*	cout << "chronum is " << plist[linecount].chronum << endl;
		cout << "getline is " << plist[linecount].pname << endl;
		cout << "linecount is " << linecount << endl << endl; */
		linecount++;
	}

	// Bubblesort!
	int n = linecount;
	for (int x = 0; x<n; x++)
	{
		for (int y = 0; y<n - 1; y++)
			if (strcmp(plist[y].pname, plist[y + 1].pname) > 0)
			{
				swap(plist[y], plist[y + 1]);
				//cout << "swapped " << plist[y].pname << " with " << plist[y + 1].pname << endl;
			}
	}
	int i = 0;
	int search;

	while ( i < 45)
	{
		search = plist[i].chronum + 1;
		int searchtemp = 0;
		while ( searchtemp < sizeof(plist) / sizeof(plist[0]))
		{
			if (plist[search].chronum == plist[searchtemp].chronum)
			{
				cout << "searchtemp is currently " << plist[searchtemp].chronum << endl << "search is " << plist[search].chronum << endl << endl;
				plist[i].next = plist[searchtemp].chronum;
				cout << "!!!FOUND IT " << plist[i].next << endl;

				break;
			}
			else
			{
				//cout << "compared " << plist[search].chronum << " with " << plist[searchtemp].chronum << endl;
				cout << "searchtemp is currently " << plist[searchtemp].chronum << endl << "search is " << plist[search].chronum << endl << endl;
				searchtemp++;
				//cout << "searchtemp set to " << searchtemp << endl;;
				//cout << "searchtemp is currently " << searchtemp << endl << "search is " << search << endl << endl;

			}
		}
		i++;
		cout << "i set to " << i << endl;
	}
	i = 1;
	output.open("output.dat");
	output.width(20);
	output << setw(3) << right << "location " << setw(5) << right << "" <<  setw(1) << right << "chronum " << setw(10) << right << "" << setw(10) << right << "president's name " << setw(5) << right << "" << setw(5) << right << "next prez " << endl;
	for (i = 0; i <= n - 1; i++)
	{
	//	output << setw(10) << right << i << "" << setw(10) << right << plist[i].chronum << setw(10) << right << "" << setw(10) << right << plist[i].pname  << setw(10) << right << "" << setw(10) << right << plist[i].next << endl;
		output << setw(3) << right << i << setw(15) << right << plist[i].chronum << setw(30) << right << plist[i].pname << setw(10) << right << plist[i].next << endl;
	}





	//system("pause");
	return 0;
}
