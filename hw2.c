/*******************************************************                        
* 學號：F74046349                                      *
* 姓名：梁祐承                                         *
* 編譯方式：gcc -o hw2 hw2.c                           *
* 執行方式：./hw2 N P                                  *
* 程式功能：Master Mind 猜數字遊戲                     *
* 更新日期：2015/10/21　　　　　　　　　　　　　　　 　*
********************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

void start(int N,int P) //開場動畫子程式
{
	system("clear");
	int i,j,k;
	for (i = 1;i <= 17;i++)
	{
		for(j = 1;j <= 62;j++)
		{
			printf("%s","█");
			fflush(stdout);
			usleep(2700);
		}
		printf("\n");
	}
	char mastermind[63];
	char *mastermindp[17];
	mastermindp[0] = &mastermind[0];
	mastermindp[0] = "╔════════════════════════════════════════════════════════════╗";
	mastermindp[1] = "║ ■     ■     ■ ■      ■ ■ ■    ■ ■ ■ ■   ■ ■ ■ ■    ■ ■ ■   ║";
	mastermindp[2] = "║ ■■   ■■    ■   ■    ■     ■      ■      ■          ■     ■ ║";
	mastermindp[3] = "║ ■ ■ ■ ■   ■     ■   ■            ■      ■          ■     ■ ║";
	mastermindp[4] = "║ ■  ■  ■   ■ ■ ■ ■    ■ ■ ■       ■      ■ ■ ■ ■    ■ ■ ■   ║";
	mastermindp[5] = "║ ■     ■   ■     ■         ■      ■      ■          ■     ■ ║";
	mastermindp[6] = "║ ■     ■   ■     ■   ■     ■      ■      ■          ■     ■ ║";
	mastermindp[7] = "║ ■     ■   ■     ■    ■ ■ ■       ■      ■ ■ ■ ■    ■     ■ ║";
	mastermindp[8] = "║                                                            ║";
	mastermindp[9] = "║           ■     ■   ■ ■ ■ ■   ■     ■   ■ ■ ■              ║";
	mastermindp[10]= "║           ■■   ■■      ■      ■■    ■   ■     ■            ║";
	mastermindp[11]= "║           ■ ■ ■ ■      ■      ■ ■   ■   ■     ■            ║";
	mastermindp[12]= "║           ■  ■  ■      ■      ■  ■  ■   ■     ■            ║";
	mastermindp[13]= "║           ■     ■      ■      ■   ■ ■   ■     ■            ║";
	mastermindp[14]= "║           ■     ■      ■      ■    ■■   ■     ■            ║";
	mastermindp[15]= "║           ■     ■   ■ ■ ■ ■   ■     ■   ■ ■ ■              ║";
	mastermindp[16]= "╚════════════════════════════════════════════════════════════╝";
	char white[63];
	char *whitep[1];
	whitep[0] = &white[0];
	whitep[0] = "██████████████████████████████████████████████████████████████";
	for(k = 0;k <= 16;k++)
	{
		system("clear");
		for(i = 0;i <= k;i++)
		{
			printf("%s\n",mastermindp[i]);
		}
		for(j = 0;j <= 15 - k;j++)
		{
			printf("%s\n",whitep[0]);
		}
		usleep(100000);
	}
	char entergame[24];
	char *entergamep[1];
	entergamep[0] = &entergame[0];
	entergamep[0] = "PRESS ENTER TO START...";
	for(i = 0;i < 24;i++)
	{
		printf("%c",entergamep[0][i]);
		fflush(stdout);
		usleep(50000);
	}
	char enter = 0;
	while(enter != '\r' && enter != '\n')
		enter = getchar();
	system("clear");
	printf("%s\n%s\n%s\n%s%d%s%s\n%s%-5d%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s\n%s",
	"╔═════════════════════════════════════════╤══════════════════╗",
	"║ Master Mind                             │Your guess history║",
	"╟─────────────────────────────────────────┼─────────────┬────╢",
	"║ Please input a ",P," digit number,","          │1.           │    ║",
	"║ which contains 1 to ",N,"               │2.           │    ║",
	"║                                         │3.           │    ║",
	"║                                         │4.           │    ║",
	"║                                         │5.           │    ║",
	"║                                         │6.           │    ║",
	"║                                         │7.           │    ║",
	"║                                         │8.           │    ║",
	"║                                         │9.           │    ║",
	"║                                         │10.          │    ║",
	"║                                         │11.          │    ║",
	"║                                         │12.          │    ║",
	"║ Times you guess:0                       │13.          │    ║",
	"╚═════════════════════════════════════════╧═════════════╧════╝",
	"Enter your guess here:"
	);
}
// 表格介面子程式 使用者輸入紀錄和比對結果將輸入此函式並顯示在螢幕上
void print(char *guess[],char *HX[],int type,int c,bool right,int N,int P,char *ans[])
{
	char print[3][41];
	char *printp[3];
	int i;
	for(i = 0;i < 3;i++)
	{
		printp[i] = &print[i][0];
	}
	if(type == 0 && right == true) //猜對時的顯示訊息
	{
		printp[0] = "Congratulation!";
		printp[1] = "Your guess is right!";
		printp[2] = "Thanks for playing.";
	}
	if(type == 0 && right == false) //猜錯時的顯示訊息
	{
		printp[0] = "Your guess is not right";
		printp[1] = "Please try again";
		printp[2] = "or you can type \"help\" for answer.";
	}
	if(type == 1) //輸入重複數字時的錯誤訊息
	{
		printp[0] = "Wrong input:";
		printp[1] = "The answer won't have the same number";
		printp[2] = "don't guess ansewr have same number.";
	}
	if(type == 2) //輸入非數字或超出N時的錯誤訊息
	{
		printp[0] = "Wrong input:";
		printp[1] = "Your input contains non-number";
		printp[2] = "character or out of range.";
	}
	if(type == 3) //輸入位數錯誤時的訊息
	{
		printp[0] = "Wrong input:";
		printp[1] = "Please input your guess which";
		printp[2] = "have right digits.";
	}
	if (type == 4) //輸入help時顯示答案
	{
		printp[0] = "HELP:";
		printp[1] = "The answer is:";
		printp[2] = ans[0];
	}
	//以下為表格框架
	system ("clear");
	printf("%s\n%s\n%s\n%s%d%s%10s%s%4s%s\n%s%-5d%s%10s%s%4s%s\n%s%10s%s%4s%s\n%s%-40s%s%10s%s%4s%s\n%s%-40s%s%10s%s%4s%s\n%s%-40s%s%10s%s%4s%s\n%s%10s%s%4s%s\n%s%10s%s%4s%s\n%s%10s%s%4s%s\n%s%10s%s%4s%s\n%s%10s%s%4s%s\n%s%10s%s%4s%s\n%s%-5d%s%10s%s%4s%s\n%s\n%s",
	"╔═════════════════════════════════════════╤══════════════════╗",
	"║ Master Mind                             │Your guess history║",
	"╟─────────────────────────────────────────┼─────────────┬────╢",
	"║ Please input a ",P," digit number,          │1. ",guess[0],"│",HX[0],"║",
	"║ Which contains 1 to ",N,"               │2. ",guess[1],"│",HX[1],"║",
	"╟─────────────────────────────────────────┤3. ",guess[2],"│",HX[2],"║",
	"║ ",printp[0],                           "│4. ",guess[3],"│",HX[3],"║",
	"║ ",printp[1],                           "│5. ",guess[4],"│",HX[4],"║",
	"║ ",printp[2],                           "│6. ",guess[5],"│",HX[5],"║",
	"║                                         │7. ",guess[6],"│",HX[6],"║",
	"║                                         │8. ",guess[7],"│",HX[7],"║",
	"║                                         │9. ",guess[8],"│",HX[8],"║",
	"║                                         │10.",guess[9],"│",HX[9],"║",
	"║                                         │11.",guess[10],"│",HX[10],"║",
	"║                                         │12.",guess[11],"│",HX[11],"║",
	"║ Times you guess:",c + 1,"                   │13.",guess[12],"│",HX[12],"║",
	"╚═════════════════════════════════════════╧═════════════╧════╝",
	"Enter your guess here:");
}
//輸入內容判端子程式
int input(int N,int P,char *userguessp[])
{
	int i,j,inputlength,inputtype;
	bool allnumber = true,numbertwice = false;
	inputlength = strlen(userguessp[0]);
	if(strcmp(userguessp[0],"help") == 0) //若使用者輸入help即輸出答案
    {
		//printf("help\n");
		inputtype = 4;
	}
	else if(inputlength != P) //輸入位數錯誤且非help時輸出錯誤訊息
	{
		//printf("Wrong input digits\n");
		inputtype = 3;
	}
	else
	{
		for(i = 0;i < P;i++) //檢查是否皆為合法數字或help
		{
			if((int)userguessp[0][i] < 49 || (int)userguessp[0][i] > N + 48)
			{
				allnumber = false;
				break;
			}
		}
		for(i = 0;i < P && numbertwice == false;i++) //檢查是否輸入重複數字
		{
			for(j = 0;j < P && j != i && numbertwice == false;j++)
			{
				if(userguessp[0][i] == userguessp[0][j])
				{
					numbertwice = true;
				}
			}
		}
		if (allnumber == false) //非全為數字則錯誤
		{
			inputtype = 2;
		}
		else if(numbertwice == true)
		{
			inputtype = 1;
		}
		else
		{
			inputtype = 0;
		}
	}

	return inputtype;
}


int main(int argc,char *argv[])
{
	int guesscount = 0;
	srand(time(NULL)); //用時間產生亂數
	if(argc != 3) //判定指令是否正確
	{
		printf("\n%s%s%s\n%s\n%s\n\n","Usage:",argv[0]," N P","N is the number of intergers to play with.","P is the number of positions.");
		exit(1);
	}
	int N = atoi(argv[1]); //把讀入的值轉為數字
	int P = atoi(argv[2]);
	if((N > 9 || N < 1) || (P > 9 || P < 1)) //檢查輸入之N與P為合法數字
	{
		printf("\n%s\n\n","N and P should be between one to nine.");
		exit(1);
	}
	if(N < P) //判斷是否會因位置太多導致答案無法亂數產生
	{
		printf("\n%s\n\n","The answer will not have the same interger twice,please input N >= P.");
		exit(1);
	}
	int i,j;
	int ans[P];
	char charans[P + 1];
	char *charansp[1];
	charansp[0] = &charans[0];
	memset(charans,'\0',sizeof(charans));
	for(i = 0;i < P;i++) //亂數產生要猜的答案
	{
		ans[i] = (rand() % N) + 1;
		charans[i] = (char)ans[i] + 48;
		for(j = i - 1;j >= 0;j--)
		{
			if(ans[i] == ans[j]) //亂數產生重複數字時i - 1重複產生
			{
				i--;
				break;
			}
		}
	}
	start(N,P);
	char userguess[11],*userguessp[1],history[50][P + 1],*historyp[50];
	int userguessnum[50][P];
	int inputtype;
	char H = '0',X = '0';
	char HX[50][5];
	char *HXp[50];
	bool guessright = false;
	memset(HX,'\0',sizeof(HX)); //填入空字元防止亂碼
	memset(history,'\0',sizeof(history));
	for(i = 0;i < 50;i++)
	{
		HXp[i] = &HX[i][0];
		historyp[i] = &history[i][0];
	}
	while(scanf("%s",userguess) != EOF)
	{
		userguessp[0] = &userguess[0];
		inputtype = input(N,P,userguessp);
		if(inputtype == 0) //輸入格式無誤時開始進行比對及紀錄
		{
			for(i = guesscount ;i > 0;i--) //將歷史紀錄往前移動一位
			{
				for(j = 0;j <= P;j++)
				{
					historyp[i][j] = historyp[i - 1][j];
				}
			}
			for(i = 0;i <= P;i++) //將最新的輸入紀錄填入history[0]
			{
				historyp[0][i] = userguessp[0][i];
			}
			H = '0'; //將猜測和答案比對
			X = '0';
			for(i = 0;i < P;i++)
			{
				userguessnum[guesscount][i] = (int)userguessp[0][i] - 48;
			}
			for(i = 0;i < P;i++)
			{
				for(j = 0;j < P;j++)
				{
					if(userguessnum[guesscount][i] == ans[j] && i == j)
						H++;
					if(userguessnum[guesscount][i] == ans[j] && i != j)
						X++;
				}
			}
			if ((int)H - 48 == P)
			guessright = true;
			for(i = guesscount;i > 0;i--)
			{
				for(j = 0;j < 5;j++)
				{
					HX[i][j] = HX[i - 1][j];
				}
			}
			HX[0][0] = H;   //比對結果存入文字陣列
			HX[0][1] = 'H';
			HX[0][2] = X;
			HX[0][3] = 'X';
			HX[0][4] = '\0';
			//存入後交由顯示子程式進行顯示
			print(historyp,HXp,inputtype,guesscount,guessright,N,P,charansp);
			guesscount++;
		}
		else //輸入不正確時將問題轉為數字並輸入副程式進行顯示
		{
			print(historyp,HXp,inputtype,guesscount,guessright,N,P,charansp);
		}
		if (guessright == true) //猜對後break跳出迴圈結束程式
		{
			printf("\n");
			break;
		}
	}
	return 0;
}
