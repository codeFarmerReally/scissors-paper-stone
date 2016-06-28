#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<iostream>

using namespace std;

int main()
{
	string maps[4];

	char scan[10];
	int person = 0;
	int alpha = 0;
	int data[100000];
	int i = 0;
	int max;
	int k = 0;
	int scoreP = 0;
	int scoreA = 0;
	printf("ʯͷ��shitou ������jiandao ����bu \n");
	memset(data,0,sizeof(data));
	int a = 0,b = 0, c = 0;
	srand((unsigned int)time(NULL));

	while(scanf("%s",scan) != EOF)
	{
		if(scan[0] == 's')
			person = 1;
		else if(scan[0] == 'j')
			person = 2;
		else if(scan[0] == 'b')
			person = 3;
		else
		{
			printf("your key is wrong ,please check your answer!");
			continue;
		}
		data[i] = person;
		++i;
		max = a;
		alpha = 3;
		if(b == max)
		{
			if(rand()%2)
			{
				max = b;
				alpha = 1;
			}
		}
		if(b > max)
		{
			max = b;
			alpha = 1;
		}
		if(c == max)
		{
			if(rand()%2)
			{
				max = c;
				alpha = 2;
			}
		}
		if(c > max)
		{
			max = c;
			alpha = 2;
		}
		if(i == 1)
		{
			alpha = rand()%3+1;
		}
		if(alpha != person)
		{
			if((alpha == 1 && person == 3) || (alpha == 2 && person ==1) || (alpha == 3 && person == 2))
			{
				k++;
			}
			if((alpha == 3 && person == 1) || (alpha == 1 && person ==2) || (alpha == 2 && person == 3))
			{
				k = 0;
				if(scoreA >= scoreP)
				{
					a = 0;
					b = 0;
					c = 0;
				}
			}
		}
		if(k >= 2)
		{
			alpha = rand()%3+1;
		}
		if(alpha != person)
		{
			if((alpha == 1 && person == 3) || (alpha == 2 && person ==1) || (alpha == 3 && person == 2))
			{
				scoreP++;
			}
			if((alpha == 3 && person == 1) || (alpha == 1 && person ==2) || (alpha == 2 && person == 3))
			{
				scoreA++;
			}
		}

		cout<<"your answer is "<<maps[person]<<endl;
		cout<<"alphaGo's answer is "<<maps[alpha]<<endl;

		printf("yours score is %d   alphaGo's score is %d\n",scoreP,scoreA);
		switch(person)
		{
			case 1:
				++a;
				break;
			case 2:
				++b;
				break;
			case 3:
				++c;
				break;
		}
	}
	return 0;
}
