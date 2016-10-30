/**
	High-accuracy serial plus emulator
		Simulate the traditional method of calculating plus questions on the paper.
		This program is the update of HPE, as it supports adding up more than two numbers.
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 100		//Max capacity of numbers
#define MAXL 1000		//Max length of each number

int main()
{
	/* Define and initialize core variables */
	int nums[MAXN][MAXL];		//Numbers
	int ans[MAXL];				//Final answer
	//Use memset() to initialize them
	for(int i=0; i<MAXN; i++)
		memset(nums[i], 0, sizeof(nums[i]));
	memset(ans, 0, sizeof(ans));
		
	/* Input numbers by string format */
	printf("Input a series of numbers you want to add. Type EOF (Ctrl+Z) for an end.\n");
	char buff_nums [MAXN][MAXL];
	
	//Continuously receive values until you press Ctrl+Z and press Enter.
	int count_nums=0; 
	while((scanf("%s", buff_nums[count_nums]) != -1))		//Note: EOF is a macro definition. It's value is -1.
		count_nums++;
		
	/* Convert every char-stored digits into real digit format (aka. int). */
	//At the same time, I'll pick out the largest length for the next calculations.
	int max_length=0;
	for(int i=0; i<count_nums; i++){
		
		int length = strlen(buff_nums[i]);
		for(int j=0; j<length; j++)
			nums[i][length - j - 1] = buff_nums[i][j] - '0';
			
		//Pick out the largest number length
		if(length > max_length) max_length = length;
	}
	
	/* Now, let's calculate! */
	int c = 0;
	int ans_length=0;
	for(int i=0; i<=max_length; i++)	//Horizontal direction
	{
		int s = c;
		for(int j=0; j<count_nums; j++)		//Vertical direction
			s += nums[j][i];
		
		ans[i] = s % 10;
		c = s / 10;
		
		ans_length++;
	}
		
	/* Output result */
	for(int i=ans_length-1; i>=0; i--)
		printf("%d", ans[i]);
	printf("\n");
	
//	//For debug
//	printf("\n");
//	for(int i=0; i<count_nums; i++)
//		printf("%s\n", buff_nums[i]);
		
}
