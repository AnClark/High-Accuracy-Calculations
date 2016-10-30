/*
	High-accuracy Plus(+) Emulator
		Simulate the traditional method of calculating plus questions on the paper.
*/

#include<cstdio>
#include<cstdlib>
#include<cstring>
#define MAXN 1000

int main()

{
	int num1[MAXN];
	int num2[MAXN];
	int ans[MAXN];
	
	memset(num1,0,sizeof(num1));
	memset(num2,0,sizeof(num2));
	memset(ans,0,sizeof(ans));
	
	while(true){
			/* Input the first number */
			printf("Input the first number:");
			char buff_num1[MAXN];
			scanf("%s", buff_num1);
			
			int len1 = strlen(buff_num1);
			
			for(int i=0; i < len1; i++)
				num1[len1 - i - 1] = buff_num1[i] - '0';	
			
			/* Input the second number */
			printf("Input the second number:");
			char buff_num2[MAXN];
			scanf("%s", buff_num2);
			
			int len2 = strlen(buff_num2);
			
			for(int i=0; i < len2; i++)
				num2[len2 - i - 1] = buff_num2[i] - '0';
				
			/* Calculate now */
			int maxlen = (len1 > len2) ? len1 : len2;
			int anslen=0;
			
			int c = 0;
			for(int i=0; i <= maxlen; i++){
				int r = num1[i] + num2[i] + c;
				ans[i] = r % 10;
				c = r / 10;
				
				anslen++;
			}
			
			/* Print result */
			for(int i=anslen - 1; i>=0; i--){
				printf("%d", ans[i]);
			}
			printf("\n");
	}
}
