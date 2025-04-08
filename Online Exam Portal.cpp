#include<iostream>
#include<fstream>
using namespace std;

class ExamPortal
{
private:
	char questions[10][100];
	char options[10][4][30];
	int answers[10];
	bool usedQ[10];
public:
	ExamPortal()
	{
		for (int i = 0; i < 10; i++)
		{
			usedQ[i] = false;
		}
	}
	void loadQuestions(const char* filename)
	{
		ifstream fin(filename);
			if (!fin)
			{
				cout << "File Can't be Opened...! " << endl;
			}
			else
			{
				for (int i = 0; i < 10; i++)
				{
					fin.getline(questions[i], 100);
					for (int j = 0; j < 4; j++)
					{
						fin.getline(options[i][j], 30);
					}
					fin >> answers[i];
					fin.ignore();
				}
			}
			fin.close();
	}

	void startExam()
	{
		int score = 0, count = 0;
		while (count < 5)
		{
			int index = rand() % 10;
			if (!usedQ[index])
			{
				usedQ[index] = true;
				cout << "Q " << count + 1 << ": " << questions[index] << endl;
				for (int j = 0; j < 4; j++)
				{
					cout << j + 1 << "." << options[index][j] << endl;
				}
				int userAnswer;
				cout << "Your Answers: (1 to 4) " << endl;
				cin >> userAnswer;

				if (userAnswer == answers[index])
				{
					score++;
				}
				count++;
			}

		}
	
		cout << "You Got " << score << "/5" << endl;
		float percentage = (score / 5.0f) * 100;
		cout << "Percentage: " << percentage << " % " << endl;
	}
};

int main()
{
	ExamPortal exam;
	exam.loadQuestions("Questions.txt");
	exam.startExam();



	system("pause");
	return 0;
}