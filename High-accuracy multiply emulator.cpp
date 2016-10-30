/**
	High-accuracy multiply emulator
		Deal with float/double multiply problems by simulating hand calculations.
		
	Input: Two lines of numbers which would be multiplied.
	Output: The result.
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 100

long power_of_10(const int n){
	long result = 1;
	if(n==0) return 1;
	for(int i=1; i<=n; i++)
	result *= 10;
	return result;
}

int main()
{
	int num1[MAXN];
	int num2[MAXN];
	int ans[MAXN];
	
	while(true){
		
			memset(num1,0,sizeof(num1));
			memset(num2,0,sizeof(num2));
			memset(ans,0,sizeof(ans));
			
			char buff_num1[MAXN];
			char buff_num2[MAXN];
			printf("Input the first number:"); 
				scanf("%s", buff_num1);
			printf("Input the second number:");
				scanf("%s", buff_num2);
			
			int len1 = strlen(buff_num1);
			int len2 = strlen(buff_num2);
			
			for(int i=0; i < len1; i++)
				num1[len1 - i - 1] = buff_num1[i] - '0';
			for(int i=0; i < len2; i++)
				num2[len2 - i - 1] = buff_num2[i] - '0';	
			
			/* 问题可分解：被乘数与乘数的每一位n逐一相乘，每次相乘的结果乘以10^n，累加即可。 */ 
			for(int j = 0; j <= len2; j++)
			{
				int current_stage[MAXN];
				memset(current_stage, 0, sizeof(current_stage));
				
				int c = 0;
				for(int i=0; i<=len1; i++){
					int s = num1[i] * num2[j] + c;
					current_stage[i + (j)] = s % 10;
					c = s / 10;
				}
				
				
				c = 0;
				for(int i=0; i<MAXN; i++){
					int s = ans[i] + current_stage[i] + c;
					ans[i] = s % 10;
					c = s / 10;
				}
			}
			
			/* Print out result */
			int j;
			for(j = MAXN-1; j>=0; j--)
				if(ans[j]) break;
			
			for(int i=j; i>=0; i--)
				printf("%d", ans[i]);
			
			printf("\n");
	
	}
	return 0;
}
