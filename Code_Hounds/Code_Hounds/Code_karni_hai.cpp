#include<iostream>
#include<ctime>
#include<Windows.h>
#include<mmsystem.h>
#include<chrono>
#include<math.h>
#include<string>
using namespace std;

/*
Debjyoti Mondal 8116671020 nick.kittu.deb@gmail.com
Dedipya Paul 9475382390 dedipyapaul1999@gmail.com
Gowreesh Mago 8847284255 gkrm2727@gnail.com
Shlok Kumar Kyal 6296538879 shlokkyal.com1@gmail.com
*/

class vector
{
public:
	float x;
	float y;
	vector(float f1, float f2)
	{
		x = f1; y = f2;
	}
	vector()
	{
		x = 0; y = 0;
	}
	int display(vector)
	{
		cout << "( " << x << " , " << y << ")";
		return 0;
	}
};

int position(vector pos[5])
{
	for (int i = 0; i < 5; i++)
	{
		cout << "Enter position co-ordinate for position " << (i + 1) << "\n";
		cout << "X : ";
		cin >> pos[i].x;
		cout << "Y : ";
		cin >> pos[i].y;
	}
	return 0;
}

int vx()
{
	srand(time(NULL));
	return(rand() % (10 -2 + 1) +2);
}

//float alarm()
//{	
//	int prep_dist;
//	cout << "How long before your arrival, would you like to be informed?\n"
//					"Enter time in minutes : ";
//	cin >> prep_dist;
//	if (PlaySound(TEXT("alarm.wav"), NULL, SND_SYNC);)
//	{
//	}
//}

float distance(vector a, vector b)
{
	return sqrt(((a.x - b.x)*(a.x - b.x)) + ((a.y - b.y)*(a.y - b.y)));
}

int main()
{
	int i, vel_x;
	vector pos[5];
	position(pos);
	float f1, f2, prep_dist;
	float m[6];
	cout << "Where do you want to go? Specify co-ordinates, \n"
		"X : ";
	cin >> f1;
	cout << "Y : ";	
	cin >> f2;
	cout << "\nWhen do you wish to be notified? Enter distance : ";
	cin >> prep_dist;
	vector dest(f1, f2), start;
	m[0] = { (pos[0].y - start.y) / (pos[0].x - start.x) };
	for (i = 0; i < 4; i++)
	{
		m[i + 1] = { (pos[i + 1].y - pos[i].y) / (pos[i + 1].x - pos[i].x)};
	}
	m[i + 1] = { (dest.y - pos[i].y) / (dest.x - pos[i].x) };
	auto begin_time = chrono::steady_clock::now();
	i = 0;
	while (1)
	{	
		cout << "\nX : " << start.x << " Y : " << start.y << "\r" << std::flush;
		vel_x = vx();

		start.x += vel_x;
		start.y += m[i] * vel_x;
		if (start.x >= pos[i].x)
		{
			start.x = pos[i].x;
			start.y = pos[i].y;
			i++;
		}
		/*if (dist(start, pos[i]) == 0)
		{
			i++;
		}*/
		if (distance(start, dest) <= prep_dist)
		{
			auto end_time = chrono::steady_clock::now();
			cout << chrono::duration_cast<chrono::seconds>(end_time - begin_time).count();
			PlaySound(TEXT("alarm.wav"), NULL, SND_SYNC);
			break;
		}
	}
	
	string z;
	getline(cin, z);
}