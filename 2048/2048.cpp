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
};//2048�����ֵ
int WIDTH=700; //�����
int HEIGHT=900;  //�����
int score;//�������
int flag=0;//��䱳����
int pass;//�����ж��Ƿ�Ҫ����������

void start_1();//�׽���
void start_2();//��Ϸ����
void start_3();//����˵��
void start_4();//������Ϸ����
void show_bk2();//����ˢ��
void show_bk1();//��Ϸ���汳��
void show();//����Ԫ��

void show_1();//��ʼ������
void game_rand();//���2||4����
void interact();//���ÿ����ƶ�
void interact_up();//�����ƶ��ж�
void interact_down();//�����ƶ��ж�
void interact_left();//�����ƶ��ж�
void interact_right();//�����ƶ��ж�

void game();//��Ϸ��ʼ��������
void game_restart();//������Ϸ
int  game_win();//ʤ������
void game_failed();//ʧ�ܽ���
int  game_check();//��Ϸ��� ʤ����
void game_clear();//��Ϸ��������
void loop();//��Ϸ����ѭ������ ��ȡ��ʾ����

void show_bk1()//��Ϸ���汳��
{
	setbkcolor(RGB(251,248,241));//���Ͻ�2048
	setfont(145,0,"Microsoft Yahei UI Bold");
	settextcolor(RGB(120,116,101));
	outtextxy(35,0,"2048");
	
	setfillcolor(RGB(184,175,160));//���Ͻ� SCORE��� BEST��
	solidroundrect(390,30,530,100,15,15);
	setfont(28,0,"Microsoft Yahei UI Bold");
	setbkcolor(RGB(184,175,160));
	settextcolor(RGB(248,247,241));
	outtextxy(425,35,"SCORE");
	solidroundrect(550,30,690,100,15,15);
	outtextxy(595,35,"BEST");
	
	setfillcolor(RGB(187,173,160));//�·���Ϸ����
	solidroundrect(10,210,690,890,20,20);
	
}

void show_bk2(int score)//����ˢ��
{	
	
	char str[10],best_str[10];
	setbkcolor(RGB(184,175,160));
	itoa(score,str,10); 
	outtextxy(440,65,str);//����
	if(str>=best_str)itoa(score,best_str,10);
	outtextxy(610,65,best_str);//��÷���
	if(flag==0)//����ֻ�ö�ȡһ��
		show_bk1();
	flag++;
	
}

void show(int x,int y,int num,int score)
{
	setbkcolor(RGB(251,248,241));//����ɫ
	IMAGE img0,img2,img4,img8,img16,img32,img64,img128,img256,img512,img1024,img2048;
	show_bk2(score);

	switch(num)//��ȡͼƬ
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

void show_1()//��ʼ������
{
	initgraph(WIDTH,HEIGHT);//����
	setbkcolor(RGB(251,248,241));//����
	settextcolor(RGB(150,126,104));
	start_1();
}               

void start_1()//�׽���
{
	cleardevice();
	setbkcolor(RGB(251,248,241));
	settextcolor(RGB(150,126,104));
	setfont(70,0,"�����кڼ���");	//�����ֿ�
	RECT r1 = {0, 0, WIDTH, HEIGHT/3};
	drawtext("��ӭ����2048������", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfont(30,0,"΢���ź�");
	RECT r2={WIDTH/2-45,HEIGHT/3,WIDTH/2+45,HEIGHT/3+30};
	drawtext("��ʼ��Ϸ", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3={WIDTH/2-45,HEIGHT/3+30,WIDTH/2+45,HEIGHT/3+60};
    drawtext("��Ϸ����", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4={WIDTH/2-45,HEIGHT/3+60,WIDTH/2+45,HEIGHT/3+90};
	drawtext("����˵��", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5={WIDTH/2-45,HEIGHT/3+90,WIDTH/2+45,HEIGHT/3+120};
	drawtext("�˳���Ϸ", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
	setfillcolor(RGB(244,186,1));//�·�2048 logo�Ļ���
	solidroundrect(216,478,484,746,50,50);
	setfont(145,0,"Microsoft Yahei UI Bold");
	setbkcolor(RGB(244,186,1));
	settextcolor(RGB(254,253,249));
	outtextxy(216,535,"2048");
	
	setbkcolor(RGB(251,248,241));//��ʼ������ɫ
	settextcolor(RGB(150,126,104));
	setfont(30,0,"Microsoft Yahei UI");
	
	
	MOUSEMSG m;//�����λ�õ��ж�
	while(1)
	{
		BeginBatchDraw();
		m=GetMouseMsg();
		switch(m.uMsg)
		{
		case WM_LBUTTONDOWN:
			EndBatchDraw();
			if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3&&m.y<HEIGHT/3+30)//��ʼ��Ϸ
			{
				game_clear();
				cleardevice();
				flag=0;
				game();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.x<WIDTH/2+45&&m.y>HEIGHT/3+30&&m.y<HEIGHT/3+60)//��Ϸ����
			{	
				start_2();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.y>HEIGHT/3+60&&m.x<WIDTH/2+45&&m.y<HEIGHT/3+90)//����˵��
			{	
				start_3();
				break;
			}
			else if(m.x>WIDTH/2-45&&m.y>HEIGHT/3+90&&m.x<WIDTH/2+45&&m.y<HEIGHT/3+120)//�˳���Ϸ
			{
				exit(0);
			}
			break;
		}
	}
	getch();
}

void start_2()//��Ϸ����
{
	cleardevice();
	RECT C2={60,60,640,790};
	drawtext("\n\n\n\n������Ϸ���ܣ�ÿ�ο���ѡ��������������һ������ȥ������ÿ����һ�Σ����е����ַ��鶼���������ķ���£�⣬ϵͳҲ���ڿհ׵ĵط���������һ�����ַ��飬��ͬ���ֵķ����ڿ�£����ײʱ����ӡ����ϵĵ�������ƴ�ճ�2048������־���ɹ���\n\n����Ŭ�������µļ�¼�ɣ���ɧ�꣡��\n\n\n���������ߣ�\n\n���� ��諺��� / ������ / ���\n\n\n\n\n\nPS������ԭ����ʱ���ܴﵽ4096�����\n���ڻ��и���ϡ��Źֵ�bug�������˲�Ҫ����", &C2, DT_WORDBREAK);
	
	
	RECT R1={WIDTH-WIDTH+2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("����", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	MOUSEMSG m;
	while(1)//���ؼ�������
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

void start_3()//����˵��
{
	cleardevice();
	RECT C3={60,60,640,790};
	drawtext("\n\n\n����˵����\n\n���ƣ�A��/�������\n\n���ƣ�D��/�������\n\n���ƣ�W��/����� ��\n\n���ƣ�S��/�����  ��\n\n���˵���esc\n\n(���أ�����OS:������� (��^��)�g)", &C3, DT_WORDBREAK);
	
	RECT R1={WIDTH-WIDTH+2,HEIGHT-200,WIDTH-2,HEIGHT-2};
	drawtext("����", &R1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	MOUSEMSG m;
	while(1)//���ؼ�������
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

void start_4()//��Ϸ��ͣ��
{
	cleardevice();
	setbkcolor(RGB(251,248,241));
	settextcolor(RGB(150,126,104));
	setfont(70,0,"�����кڼ���");	
	RECT r1 = {0, 0, WIDTH, HEIGHT/3};
	drawtext("��Ϣ ��Ϣһ��", &r1, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	setfont(30,0,"΢���ź�");
	
	RECT r2={WIDTH/2-45,HEIGHT/3,WIDTH/2+45,HEIGHT/3+30};
	drawtext("������Ϸ", &r2, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r3={WIDTH/2-45,HEIGHT/3+30,WIDTH/2+45,HEIGHT/3+60};
    drawtext("��Ϸ����", &r3, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r4={WIDTH/2-45,HEIGHT/3+60,WIDTH/2+45,HEIGHT/3+90};
	drawtext("����˵��", &r4, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r5={WIDTH/2-45,HEIGHT/3+90,WIDTH/2+45,HEIGHT/3+120};
	drawtext("�˳���Ϸ", &r5, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	RECT r6={WIDTH/2-45,HEIGHT/3-30,WIDTH/2+45,HEIGHT/3};
	drawtext("����Ϸ", &r6, DT_CENTER | DT_VCENTER | DT_SINGLELINE);
	
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

int game_win()//ʤ������Ļ
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
	for(x=0;x<10;x++)//��ʾwin�Ķ��ɫ
	{
		settextcolor(RGB(rand()%255,rand()%255,rand()%255));
		settextstyle(100,50,NULL);
		outtextxy(50,50,win);
		Sleep(100);
	}
	
	settextstyle(50,25,"΢���ź�");
	settextcolor(GREEN);
	outtextxy(200,150,"������");
	settextcolor(BLUE);
	outtextxy(120,250,yes);
	outtextxy(320,250,no);
	setfillcolor(RED);
	
	MOUSEMSG m;//�����������Ϸ�����˳�
	while(1){//��������������1�����¿�ʼ��������2
		FlushMouseMsgBuffer();
		m=GetMouseMsg();
		if(m.uMsg==WM_LBUTTONDOWN)
		{
			x=m.x;y=m.y;
			if(x>120&&x<220&&y>250&&y<300)
			{
				cleardevice();
				return 1;
			}//game������ȡ
			if(x>320&&x<420&&y>250&&y<300)
			{
				cleardevice();
				return 2;
			}//game������ȡ
		}
	}
}     

void game_failed()//���˵���Ļ//����ͬʤ��
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
	
	settextstyle(50,0,"΢���ź�");
	settextcolor(GREEN);
	outtextxy(WIDTH/3+50,HEIGHT/2+50,"OK");	//��ʾYOU FAILED,���ȷ��������
	
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

void game()//��Ϸ�ĳ�ʼ��������
{
	
	while(1)
	{
		
		score=0;//������ʼ��
		game_rand();//�������������
		game_rand();
		loop();//������
		while(1)
		{
			if(_kbhit)//����
			{
				pass=0;
				interact();//������
				fflush(stdin);//������뻺��
				if(pass)game_rand();//�ƶ�֮���Ƿ����ƶ�������������
				if(game_check())//��� ���check����
				{
					if(game_check()==1)//��� ���check����
					{
						if(game_win()==2)break;//ʤ�����桪������һ��
						
					}
					else if(game_check()==-1)//��� ���check����
					{
						loop();
						game_failed();
						break;
					}
				}
				loop();//������
			}
			else Sleep(1);
		}
		game_clear();//����
		continue;
	}
}

void game_restart()
{
	
	show_bk1();
	loop();
	while(1)
	{
		if(kbhit)//����
		{
			pass=0;
			interact();//������
			fflush(stdin);//������뻺��
			if(pass)game_rand();//�ƶ�֮���Ƿ����ƶ�������������
			if(game_check())//��� ���check����
			{
				if(game_check()==1)//��� ���check����
				{
					if(game_win()==2)break;//ʤ�����桪������һ��
					
				}
				else if(game_check()==-1)//��� ���check����
				{
					loop();
					game_failed();
					break;
				}
			}
			loop();//������
		}
		else Sleep(1);
	}
	game_clear();//����
}

void game_rand()//���2 4
{
	int x,y,temp,num;
	srand((int)time(0));
	while(1)
	{
		x=rand()%4;
		y=rand()%4;
		temp=rand()%5;
		if(temp==1)num=4;//���4
		else num=2;//���2
		if(map[y][x]==0)
		{
			map[y][x]=num;//������
			break;
		}
	}
}

void interact()
{
	char keyboard;
	keyboard=_getch();
	if(keyboard=='w'||keyboard=='W'||keyboard==72)interact_up();//��
	if(keyboard=='s'||keyboard=='S'||keyboard==80)interact_down();//��
	if(keyboard=='a'||keyboard=='A'||keyboard==75)interact_left();//��
	if(keyboard=='d'||keyboard=='D'||keyboard==77)interact_right();//��
	if(keyboard==27)//esc���˵�
	{
		flag=0;
		setbkcolor(RGB(251,248,241));
		start_4();
	}
}

void interact_up()//����Ų
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
					if(map[j-1][n]==0)//����û��
					{
						map[j-1][n]=map[j][n];
						map[j][n]=0;
						pass=1;
						loop();
						Sleep(1);
					}
					else if(map[j-1][n]==map[j][n])//����������
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
	int a=0;//�������Ա�û����ͬ���ֵĸ��ӽ��м���
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
			if(a==16)success=-1;//����
			for(i=0;i<4;i++)
				for(n=0;n<4;n++)if(map[n][i]==2048)//�ܶ�2048
				success=1;//ʤ������
				return success;
}

void loop()//ѭ����ʾ
{
	int i,n;
	for(i=0;i<4;i++)
	{
		for(n=0;n<4;n++)
		{
			show(i,n,map[n][i],score);//���һ�������������
		}
	}
}

void game_clear()//����
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
