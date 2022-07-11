#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <conio.h>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <sstream>
using namespace std;

int min(int x, int y, int z) { return min(min(x, y), z); }

int editDistDP(string str1, string str2, int m, int n)
{
	
	int dp[50][50];
	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0)
				dp[i][j] = j; 

			else if (j == 0)
				dp[i][j] = i; 

			else if (str1[i - 1] == str2[j - 1])
				dp[i][j] = dp[i - 1][j - 1];

			else
				dp[i][j]
				= 1
				+ min(dp[i][j - 1], // Insert
					dp[i - 1][j], // Remove
					dp[i - 1][j - 1]); // Replace
		}
	}

	return dp[m][n];
}



int main() {
	    vector<string> vs;
		int A[50] = { 0 };
		string input, line;
		cout << "enter the sentence: "<<endl;
		getline(cin, input);
		for (int i = 0; i < input.length(); i++)
			input[i] = tolower(input[i]);
		string word;
		stringstream iss(input);
		while (iss >> word)
			vs.push_back(word);
		ifstream words("words_alpha.txt");
		system("CLS");
		cout << "ENTERED SENTENCE:   "<<input<<endl;
		if (words)
		{
			for (int i = 0; i < vs.size(); i++)
			{
				while (getline(words, line))
				{
					if (vs[i].compare(line) == 0)
					{
						cout <<"the word \""<<vs[i]<<"\" is correct!" << endl;
						A[i] = 1;
						system("pause");
						break;
					}
				}
				words.close();
				if (!A[i])
				{
					system("CLS");
					cout << "the word \"" << vs[i] << "\" is false! " << endl<<"suggestions: "<<endl;
					ifstream words("words_alpha.txt");
					while (getline(words, line))
					{
						int dif=vs[i].length()-line.length();
						if (abs(dif) <= 1 )
						{
							if (editDistDP(vs[i], line, vs[i].length(), line.length()) <= 1)
								cout << line << " EDIT DISTANCE = " << editDistDP(vs[i], line, vs[i].length(), line.length())<<endl;
						}
					}
					system("pause");
				}
			}
		}
		else
			cout << "unable to open the dictionary file" << endl;
	





	_getch();
	return 0;
}