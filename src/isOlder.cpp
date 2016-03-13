/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
#include<malloc.h>
int* strtodate(char *a)
{
	int sum = 0, i = 0, j = 0, k = 0;
	int* c = (int*)malloc(sizeof(int) * 3);

	for (i = 0; a[i] != '\0'; i++)
	{

		if (a[i] != 45)
		{

			sum = sum * 10 + (a[i] - 48);

		}
		else

		{

			c[j] = sum;

			j++;
			sum = 0;

		}


	}

	c[j] = sum;

	return c;
}
int checkleapyr(int year)
{
	if (year % 400 == 0)
		return 0;
	else if (year % 100 == 0)
		return -1;
	else if (year % 4 == 0)
		return 0;
	else
		return -1;

}
int checkvalid(int* dob)
{
	int date, month, year, y;
	date = dob[0];
	month = dob[1];
	year = dob[2];


	if (!(month >= 1 && month <= 12))
	{


		return -1;
	}
	else if (month == 2)
	{

		if (date>29)
			return -1;
		else if (date <= 28)
			return 0;
		else
		{

			y = checkleapyr(year);
			if (y == -1)
				return -1;

		}
	}

	else if (month == 4 || 6 || 9 || 11)
	{

		if (!(date <= 30))

			return -1;
	}
	else
	{

		if (!(date <= 31))

			return -1;

	}

	return 0;
}
int isOlder(char *dob1, char *dob2)
{
	int  len1 = 0, len2 = 0, i, valid1, valid2;
	int* dateofb1 = (int*)malloc(sizeof(int) * 3);
	int* dateofb2 = (int*)malloc(sizeof(int) * 3);
	for (i = 0; dob1[i] != '\0'; i++)
	{
		len1++;

	}

	for (i = 0; dob2[i] != '\0'; i++)
	{
		len2++;

	}

	if (len1 != 10 || len2 != 10)
	{

		return -1;
	}
	else
	{
		dateofb1 = strtodate(dob1);
		dateofb2 = strtodate(dob2);

		valid1 = checkvalid(dateofb1);
		valid2 = checkvalid(dateofb2);
		if (valid1 == -1 || valid2 == -1)
		{
			return -1;
		}
		else
		{
			if (dateofb1[2]<dateofb2[2])

				return 1;
			else if (dateofb1[2]>dateofb2[2])
				return 2;
			else
			{
				if (dateofb1[1]<dateofb2[1])
					return 1;
				else if (dateofb1[1]>dateofb2[1])
					return 2;
				else
				{
					if (dateofb1[0]<dateofb2[0])
						return 1;
					else if (dateofb1[0]>dateofb2[0])
						return 2;
					else
						return 0;
				}
			}

		}
	}
}
