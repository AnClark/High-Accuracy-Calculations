/**
	High-accuracy multiply emulator --- SIMPLIFIED WORK
		A part of my HAME. (Sincerely speaking, I found that it's difficult to deal with those problems...)
		
	Input: Two lines of numbers which would be multiplied. 
		NOTICE that the SECOND one is an interger no larger than 10 and no less than 1.
	Output: The result.
*/

#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAXN 100

int main()
{
	int num1[MAXN];
	int num2;
	int ans[MAXN];
	
	memset(num1,0,sizeof(num1));
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
			printf("Input the second number between 0 and 10 (not including the bounds):");
			for(;;){
				scanf("%d", &num2); 
				if(num2>0 && num2<10) 
					break;
				else 
					printf("Illegal value. Give another one.\n");
			}
			
			/* Now, let's calculate! */
			int i;
			int c = 0;		//��ŵ�ǰ��λֵ
			for(i = 0; i <= len1; i++){
				int r = num1[i] * num2 + c;		//���Ŀǰ����֮��λ֮������ϴν�λֵ�������ۼӡ� 
				ans[i] = r % 10;	//ȡ���λ�������洢�ڴ��� 
				c = r / 10;		//ȡ��ʮλ�� 
			}
			
			int len_ans = i;
			// Output the result by printing the result array
			for(int j = len_ans - 1; j>=0; j--)
				printf("%d", ans[j]);
			printf("\n");
	}

		
	return 0;
}
