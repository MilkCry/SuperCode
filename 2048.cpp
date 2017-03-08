#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>



int map[4][4]={
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0},
				{0,0,0,0}
};//2048界面初值
int WIDTH=700; //界面宽
int HEIGHT=900;  //界面高
int score;//计算分数
int flag=0;//填充背景用
int pass;//用来判断是否要放置新数字

void start_1();//首界面
void start_2();//游戏介绍
void start_3();//操作说明
void start_4();//继续游戏界面
void show_bk2();//分数刷新
void show_bk1();//游戏界面背景
void show();//放置元素

void show_1();//初始化界面
void game_rand();//随机2||4数字
void interact();//调用控制移动
void interact_up();//向上移动判断
void interact_down();//向下移动判断
void interact_left();//向左移动判断
void interact_right();//向右移动判断

void game();//游戏初始化和运行
void game_restart();//继续游戏
int  game_win();//胜利界面
void game_failed();//失败界面
int  game_check();//游戏检查 胜负等
void game_clear();//游戏清屏函数
void loop();//游戏基本循环函数 调取显示函数

void show_bk1()//游戏界面背景
{
	setbkcolor(RGB(251,248,241));//左上角2048
	setfont(145,0,"Microsoft Yahei UI Bold");
	settextcolor(RGB(120,116,101));
	outtextxy(35,0,"2048");
	
	setfillcolor(RGB(184,175,160));//右上角 SCORE框和 BEST框
	solidroundrect(390,30,530,100,15,15);
	setfont(28,0,"Microsoft Yahei UI Bold");
	setbkcolor(RGB(184,175,160));
	settextcolor(RGB(248,247,241));
	outtextxy(425,35,"SCORE");
	solidroundrect(550,30,690,100,15,15);
	outtextxy(595,35,"BEST");
	
	setfillcolor(RGB(187,173,160));//下方游戏区域
	solidroundrect(10,210,690,890,20,20);
	
}

void show_bk2(int score)//分数刷新
{	
	
	char str[10],best_str[10];
	setbkcolor(RGB(184,175,160));
	itoa(score,str,10); 
	outtextxy(440,65,str);//分数
	if(str>=best_str)itoa(score,best_str,10);
	outtextxy(610,65,best_str);//最好分数
	if(flag==0)//背景只用读取一次
		show_bk1();
	flag++;
	
}

void show(int x,int y,int num,int score)
{
	setbkcolor(RGB(251,248,241));//背景色
	IMAGE img0,img2,img4,img8,img16,img32,img64,img128,img256,img512,img1024,img2048;
	show_bk2(score);

	switch(num)//调取图片
	{
		case 0:loadimage(&img0,"pic\\0.jpg");putimage(x*165+30,y*165+230,&img0);break;
		case 2:loadimage(&img2,"pic\\2.jpg");putimage(x*165+30,y*165+230,&img2);break;
		case 4:loadimage(&img4,"pic\\4.jpg");putimage(x*165+30,y*165+230,&img4);break;
		case 8:loadimage(&img8,"pic\\8.jpg");putimage(x*165+30,y*165+230,&img8);break;
		case 16:loadimage(&img16,"pic\\16.jpg");putimage(x*165+30,y*165+230,&img16);break;
		case 32:loadimage(&img32,"pic\\32.jpg");putimage(x*165+30,y*165+230,&img32);break;
		case 64:loadimage(&img64,"pic\\64.jpg");putimage(x*165+30,y*165+230,&img64);break;
		case 128:loadimage(&img128,"pic\\128.jpg");putimage(x*165+30,y*165+230,&img128);break;
		case 256:loadimage(&img256,"pic\\256.jpg");putimage(x*165+30,y*165+230,&img256);break;
		case 512:loadimage(&img512,"pic\\512.jpg");putimage(x*165+30,y*165+230,&img512);break;
		case 1024:loadimage(&img1024,"pic\\1024.jpg");putimage(x*165+30,y*165+230,&img1024);break;
		case 2048:loadimage(&img2048,"pic\\2048.jpg");putimage(x*165+30,y*165+230,&img2048);break;
	}
	
}

void show_1()//初始化界面
{
	initgraph(WIDTH,HEIGHT);//长宽
	setbkcolor(RGB(251,248,241));//背景
	settextcolor(RGB(150,126,104));
	start_1();
}               

void start_1()//首界面
{
	cleardevice();
	setbkcolor(RGB(251,248,241));
	settextcolor(RGB(150,126,104));
	setfont(70,0,"方正行黑简体");	//几个字框
	RECT r1 = {0, 0, WIDTH, HEIGHT/3};
	drawtext("欢迎来到2048的世界", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfont(30,0,"微软雅黑");
	RECT r2={WIDTH/2-45,HEIGHT/3,WIDTH/2+45,HEIGHT/3+30};
	drawtext("开始游戏", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3={WIDTH/2-45,HEIGHT/3+30,WIDTH/2+45,HEIGHT/3+60};
    drawtext("游戏介绍", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4={WIDTH/2-45,HEIGHT/3+60,WIDTH/2+45,HEIGHT/3+90};
	drawtext("操作说明", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5={WIDTH/2-45,HEIGHT/3+90,WIDTH/2+45,HEIGHT/3+120};
	drawtext("退出游戏", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	setfillcolor(RGB(244,186,1));//下方2048 logo的绘制
	solidroundrect(216,478,484,746,50,50);
	setfont(145,0,"Microsoft Yahei UI Bold");
	setbkcolor(RGB(244,186,1));
	settextcolor(RGB(254,253,249));
	outtextxy(216,535,"2048");
	
	setbkcolor(RGB(251,248,241));//初始化背景色
	settextcolor(RGB(150,126,104));
	setfont(30,0,"Microsoft Yahei UI");
	
	
	MOUSEMSG m;//鼠标点击位置的判断
	while(1)
	{
		BeginBatchDraw();
		m=GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			EndBatchDraw();
			if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3&&m.y<HEIGHT/3+30)//开始游戏
			{
				game_clear();
				cleardevice();
				flag=0;
				game();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+30&&m.y<HEIGHT/3+60)//游戏介绍
			{	
				start_2();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.y>HEIGHT/3+60&&m.x<WIDTH/2+45&&m.y<HEIGHT/3+90)//操作说明
			{	
				start_3();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.y>HEIGHT/3+90&&m.x<WIDTH/2+45&&m.y<HEIGHT/3+120)//退出游戏
			{
				exit(0);
			}
			break;
		}
	}
	getch();
}

void start_2()//游戏介绍
{
	cleardevice();
	RECT C2={60,60,640,790};
	drawtext("\n\n\n\n　　游戏介绍：每次可以选择上下左右其中一个方向去滑动，每滑动一次，所有的数字方块都会往滑动的方向靠拢外，系统也会在空白的地方乱数出现一个数字方块，相同数字的方块在靠拢、相撞时会相加。不断的叠加最终拼凑出2048这个数字就算成功。\n\n　　努力创造新的记录吧！！骚年！！\n\n\n　　开发者：\n\n　　 Milk \n\n\n\n\n\nPS：因技术原因，暂时不能达到4096或更高\n现在还有各种稀奇古怪的bug", &C2, DT_WORDBREAK);
	
	
	RECT R1={WIDTH-WIDTH+2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("返回", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	MOUSEMSG m;
	while(1)//返回键的设置
	{
		m=GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if(m.x>WIDTH-WIDTH+2&&m.x<WIDTH-2&&m.y>HEIGHT-200&&m.y<HEIGHT-2)
				start_1();	
		}
	}
}

void start_3()//操作说明
{
	cleardevice();
	RECT C3={60,60,640,790};
	drawtext("\n\n\n操作说明：\n\n左移：A键/方向键←\n\n右移：D键/方向键→\n\n上移：W键/方向键 ↑\n\n下移：S键/方向键  ↓\n\n主菜单：esc\n\n(返回：作者OS:你想得美 (￣^￣)ゞ)", &C3, DT_WORDBREAK);
	
	RECT R1={WIDTH-WIDTH+2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("返回", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	MOUSEMSG m;
	while(1)//返回键的设置
	{
		m=GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			if(m.x>WIDTH-WIDTH+2&&m.x<WIDTH-2&&m.y>HEIGHT-200&&m.y<HEIGHT-2)
				start_1();	
		}
	}
}

void start_4()//游戏暂停等
{
	cleardevice();
	setbkcolor(RGB(251,248,241));
	settextcolor(RGB(150,126,104));
	setfont(70,0,"方正行黑简体");	
	RECT r1 = {0, 0, WIDTH, HEIGHT/3};
	drawtext("休息 休息一下", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfont(30,0,"微软雅黑");
	
	RECT r2={WIDTH/2-45,HEIGHT/3,WIDTH/2+45,HEIGHT/3+30};
	drawtext("继续游戏", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3={WIDTH/2-45,HEIGHT/3+30,WIDTH/2+45,HEIGHT/3+60};
    drawtext("游戏介绍", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4={WIDTH/2-45,HEIGHT/3+60,WIDTH/2+45,HEIGHT/3+90};
	drawtext("操作说明", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5={WIDTH/2-45,HEIGHT/3+90,WIDTH/2+45,HEIGHT/3+120};
	drawtext("退出游戏", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r6={WIDTH/2-45,HEIGHT/3-30,WIDTH/2+45,HEIGHT/3};
	drawtext("新游戏", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	setfillcolor(RGB(244,186,1));
	solidroundrect(216,478,484,746,50,50);
	setfont(145,0,"Microsoft Yahei UI Bold");
	setbkcolor(RGB(244,186,1));
	settextcolor(RGB(254,253,249));
	outtextxy(216,535,"2048");
	
	setbkcolor(RGB(251,248,241));
	settextcolor(RGB(150,126,104));
	setfont(30,0,"Microsoft Yahei UI");
	
	
	MOUSEMSG m;
	while(1)
	{
		BeginBatchDraw();
		m=GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			EndBatchDraw();
			if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3-30&&m.y<HEIGHT/3)
			{
				cleardevice();
				flag=0;
				game_clear();
				game();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3&&m.y<HEIGHT/3+30)
			{
				cleardevice();
				flag=0;
				game_restart();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+30&&m.y<HEIGHT/3+60)
			{	
				start_2();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.y>HEIGHT/3+60&&m.x<WIDTH/2+45&&m.y<HEIGHT/3+90)
			{	
				start_3();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.y>HEIGHT/3+90&&m.x<WIDTH/2+45&&m.y<HEIGHT/3+120)
			{
				exit(0);
			}
			break;
		}
	}
	getch();
}

int game_win()//胜利的屏幕
{
	
	COLORREF ref;
	int r,g,b;
	int x,y;
	char *yes,*no,*win;
	srand((int)time(0));
	BeginBatchDraw();
	for(x=0;x<700;x++)
	{
		for(y=0;y<900;y++)
		{
			ref=getpixel(x,y);
			r=GetRValue(ref);
			g=GetGValue(ref);
			b=GetBValue(ref);
			putpixel(x,y,RGB(r*0.5,g*0.5,b*0.5));
		}
	}
	
	FlushBatchDraw();
	EndBatchDraw();
	yes="YES";
	no="NO";
	win="YOU WIN !";
	for(x=0;x<10;x++)//显示win的多彩色
	{
		settextcolor(RGB(rand()%255,rand()%255,rand()%255));
		settextstyle(100,50,NULL);
		outtextxy(50,50,win);
		Sleep(100);
	}
	
	settextstyle(50,25,"微软雅黑");
	settextcolor(GREEN);
	outtextxy(200,150,"继续？");
	settextcolor(BLUE);
	outtextxy(120,250,yes);
	outtextxy(320,250,no);
	setfillcolor(RED);
	
	MOUSEMSG m;//鼠标点击继续游戏或者退出
	while(1){//继续玩清屏返回1，重新开始清屏返回2
		FlushMouseMsgBuffer();
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			x=m.x;y=m.y;
			if(x>120&&x<220&&y>250&&y<300)
			{
				cleardevice();
				return 1;
			}//game函数调取
			if(x>320&&x<420&&y>250&&y<300)
			{
				cleardevice();
				return 2;
			}//game函数调取
		}
	}
}     

void game_failed()//输了的屏幕//内容同胜利
{
	
	COLORREF ref;
	int r,g,b;
	int x,y;
	srand((int)time(0));
	BeginBatchDraw();
	for(x=0;x<700;x++)
	{
		for(y=0;y<900;y++)
		{
			ref=getpixel(x,y);
			r=GetRValue(ref);
			g=GetGValue(ref);
			b=GetBValue(ref);
			putpixel(x,y,RGB(r*0.5,g*0.5,b*0.5));
		}
	}
	
	FlushBatchDraw();
	EndBatchDraw();
	
	for(x=0;x<5;x++)
	{
		settextcolor(RGB(rand()%255,rand()%255,rand()%255));
		settextstyle(80,20,NULL);
		outtextxy(WIDTH/3,HEIGHT/2-50,"YOU FAILED");
		Sleep(1000);
	}
	
	settextstyle(50,0,"微软雅黑");
	settextcolor(GREEN);
	outtextxy(WIDTH/3+50,HEIGHT/2+50,"OK");	//显示YOU FAILED,点击确定后清屏
	
	MOUSEMSG m;
	while(1)
	{
		FlushMouseMsgBuffer();
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			x=m.x;
			y=m.y;
			
			if(x>WIDTH/3+50&&x<WIDTH/3+100&&y>HEIGHT/2+50&&y<HEIGHT/2+100)
			{
				cleardevice();
				break;
			}
		}
	}
}

void game()//游戏的初始化和运行
{
	
	while(1)
	{
		
		score=0;//分数初始化
		game_rand();//随机出来两个数
		game_rand();
		loop();//放数字
		while(1)
		{
			if(_kbhit)//按键
			{
				pass=0;
				interact();//方向走
				fflush(stdin);//清空输入缓存
				if(pass)game_rand();//移动之后是否能移动后继续随机数字
				if(game_check())//检查 详见check函数
				{
					if(game_check()==1)//检查 详见check函数
					{
						if(game_win()==2)break;//胜利界面——再来一次
						
					}
					else if(game_check()==-1)//检查 详见check函数
					{
						loop();
						game_failed();
						break;
					}
				}
				loop();//放数字
			}
			else Sleep(1);
		}
		game_clear();//清屏
		continue;
	}
}

void game_restart()
{
	
	show_bk1();
	loop();
	while(1)
	{
		if(kbhit)//按键
		{
			pass=0;
			interact();//方向走
			fflush(stdin);//清空输入缓存
			if(pass)game_rand();//移动之后是否能移动后继续随机数字
			if(game_check())//检查 详见check函数
			{
				if(game_check()==1)//检查 详见check函数
				{
					if(game_win()==2)break;//胜利界面——再来一次
					
				}
				else if(game_check()==-1)//检查 详见check函数
				{
					loop();
					game_failed();
					break;
				}
			}
			loop();//放数字
		}
		else Sleep(1);
	}
	game_clear();//清屏
}

void game_rand()//随机2 4
{
	int x,y,temp,num;
	srand((int)time(0));
	while(1)
	{
		x=rand()%4;
		y=rand()%4;
		temp=rand()%5;
		if(temp==1)num=4;//随机4
		else num=2;//随机2
		if(map[y][x]==0)
		{
			map[y][x]=num;//放数字
			break;
		}
	}
}

void interact()
{
	char keyboard;
	keyboard=_getch();
	if(keyboard=='w'||keyboard=='W'||keyboard==72)interact_up();//上
	if(keyboard=='s'||keyboard=='S'||keyboard==80)interact_down();//下
	if(keyboard=='a'||keyboard=='A'||keyboard==75)interact_left();//左
	if(keyboard=='d'||keyboard=='D'||keyboard==77)interact_right();//右
	if(keyboard==27)//esc主菜单
	{
		flag=0;
		setbkcolor(RGB(251,248,241));
		start_4();
	}
}

void interact_up()//向上挪
{
	int n,i,j,k;
	for(n=0;n<4;n++)
	{
		k=0;
		for(i=0;i<4;i++)
		{
			if(map[i][n]!=0)
			{
				for(j=i;j>k;j--)
				{
					if(map[j-1][n]==0)//上面没数
					{
						map[j-1][n]=map[j][n];
						map[j][n]=0;
						pass=1;
						loop();
						Sleep(1);
					}
					else if(map[j-1][n]==map[j][n])//上面有数字
					{
						map[j-1][n]=2*map[j-1][n];
						score+=map[j-1][n];
						map[j][n]=0;
						k=j;
						pass=1;
						loop();
						Sleep(1);
						break;
					}
					else break;
				}
			}
		}
	}
}

void interact_down()
{
	int n,i,j,k;
	for(n=0;n<4;n++)
	{
		k=3;
		for(i=4;i>=0;i--)
		{
			if(map[i][n]!=0)
			{
				for(j=i;j<k;j++)
				{
					if(map[j+1][n]==0)
					{
						map[j+1][n]=map[j][n];
						map[j][n]=0;
						pass=1;
						loop();
						Sleep(1);
					}
					else if(map[j+1][n]==map[j][n])
					{
						map[j+1][n]=2*map[j+1][n];
						score+=map[j+1][n];
						map[j][n]=0;
						k=j;
						loop();
						Sleep(1);
						pass=1;
						break;
					}
					else break;
				}
			}
		}
	}
}

void interact_left()
{
	int n,i,j,k;
	for(i=0;i<4;i++)
	{
		k=0;
		for(n=0;n<4;n++)
		{
			if(map[i][n]!=0)
			{
				for(j=n;j>k;j--)
				{
					if(map[i][j-1]==0)
					{
						map[i][j-1]=map[i][j];
						map[i][j]=0;
						pass=1;
						loop();
						Sleep(1);
					}
					else if(map[i][j-1]==map[i][j])
					{
						map[i][j-1]=2*map[i][j-1];
						score+=map[i][j-1];
						map[i][j]=0;
						k=j;
						loop();
						Sleep(1);
						pass=1;
						break;
					}
					else break;
				}
			}
		}
	}
}

void interact_right()
{
	int n,i,j,k;
	for(i=0;i<4;i++)
	{
		k=3;
		for(n=3;n>=0;n--)
		{
			if(map[i][n]!=0)
			{
				for(j=n;j<k;j++)
				{
					if(map[i][j+1]==0)
					{
						map[i][j+1]=map[i][j];
						map[i][j]=0;
						pass=1;
						loop();
						Sleep(1);
					}
					else if(map[i][j+1]==map[i][j])
					{
						map[i][j+1]=2*map[i][j+1];
						score+=map[i][j+1];
						map[i][j]=0;
						k=j;
						loop();
						Sleep(1);
						pass=1;
						break;
					}
					else break;
				}
			}
		}
	}
}

int game_check()
{
	int success=0;
	int i,n;
	int a=0;//用来对旁边没有相同数字的格子进行计数
	if((map[0][0]!=0)&&(map[0][1]!=0)&&(map[0][0]!=0)&&(map[0][0]!=map[0][1])&&(map[0][0]!=map[1][0]))a++;
	if((map[3][3]!=0)&&(map[3][2]!=0)&&(map[2][3]!=0)&&(map[3][3]!=map[3][2])&&(map[3][3]!=map[2][3]))a++;
	if((map[0][3]!=0)&&(map[0][2]!=0)&&(map[1][3]!=0)&&(map[0][3]!=map[0][2])&&(map[0][3]!=map[1][3]))a++;
	if((map[3][0]!=0)&&(map[3][1]!=0)&&(map[2][0]!=0)&&(map[3][0]!=map[3][1])&&(map[3][0]!=map[2][0]))a++;
	if((map[0][1]!=0)&&(map[0][0]!=0)&&(map[0][2]!=0)&&(map[0][1]!=map[0][0])&&(map[0][1]!=map[0][2]))a++;
	if((map[0][2]!=0)&&(map[0][1]!=0)&&(map[0][3]!=0)&&(map[0][2]!=map[0][1])&&(map[0][2]!=map[0][3]))a++;
	if((map[3][1]!=0)&&(map[3][0]!=0)&&(map[3][2]!=0)&&(map[3][1]!=map[3][0])&&(map[3][1]!=map[3][2]))a++;
	if((map[3][2]!=0)&&(map[3][1]!=0)&&(map[3][3]!=0)&&(map[3][2]!=map[3][1])&&(map[3][2]!=map[3][3]))a++;
	if((map[1][0]!=0)&&(map[0][0]!=0)&&(map[2][0]!=0)&&(map[1][0]!=map[0][0])&&(map[1][0]!=map[2][0]))a++;
	if((map[2][0]!=0)&&(map[3][0]!=0)&&(map[1][0]!=0)&&(map[2][0]!=map[1][0])&&(map[2][0]!=map[3][0]))a++;
	if((map[1][3]!=0)&&(map[0][3]!=0)&&(map[2][3]!=0)&&(map[1][3]!=map[0][3])&&(map[1][3]!=map[2][3]))a++;
	if((map[2][3]!=0)&&(map[3][3]!=0)&&(map[1][3]!=0)&&(map[2][3]!=map[1][3])&&(map[2][3]!=map[3][3]))a++;
	for(i=1;i<3;i++)
		for(n=1;n<3;n++)
			if((map[n][i]!=0)&&(map[n-1][i]!=0)&&(map[n+1][i]!=0)&&(map[n][i-1]!=0)&&(map[n][i+1]!=0)&&(map[n][i]!=map[n+1][i])&&(map[n][i]!=map[n-1][i])&&(map[n][i]!=map[n][i+1])&&(map[n][i]!=map[n][i-1]))a++;
			if(a==16)success=-1;//输了
			for(i=0;i<4;i++)
				for(n=0;n<4;n++)if(map[n][i]==2048)//很多2048
				success=1;//胜利条件
				return success;
}

void loop()//循环显示
{
	int i,n;
	for(i=0;i<4;i++)
	{
		for(n=0;n<4;n++)
		{
			show(i,n,map[n][i],score);//最后一个参数传入分数
		}
	}
}

void game_clear()//清屏
{
	int i,n;
	for(i=0;i<4;i++)
	{
		for(n=0;n<4;n++)
		{
			map[n][i]=0;
		}
	}
}

int main()
{
	show_1();
	return 0;
}
