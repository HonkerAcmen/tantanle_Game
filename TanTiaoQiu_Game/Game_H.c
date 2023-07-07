#include "Game_H.h"

// 数据区
int high, width; // 画布的宽高
int ball_x, ball_y; // 球的位置
int ball_vx, ball_vy; // 球的移动位置
int pos_x, pos_y; // 挡板的中心坐标
int ridus; // 挡板的半径
int left, right; // 挡板的左右位置
int ball_number; //反弹小球的次数
int block_x, block_y; // 砖块的位置
int score; // 分数

// 将光标移动到特定的地点
void gotoxy(int x, int y){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

// 数据初始化
void startup(){
	
	high = 14;
	width = 18;
	ball_x = 0;
	ball_y = 15;
	ball_vx = 1;
	ball_vy = 1;
	ridus = 6;
	pos_x = high;
	pos_y = width / 2;
	left = pos_y - ridus;
	right = pos_y + ridus;
	ball_number = 0;
	srand((unsigned int)time(NULL));
	block_x = 0;
	block_y = rand() % width;
	score = 0;
}

// 显示
void show(){
	gotoxy(0, 0);
	int index_high, index_width;
	for (index_high = 0; index_high <= high + 1; index_high++) {
		for (index_width = 0; index_width <= width; index_width++) {
			if (index_high == ball_x && index_width == ball_y) {
				printf("0");
			}
			else if (index_width == width) {
				printf("|");
			}
			else if (index_high == high + 1) {
				printf("-");
			}
			else if (index_high == high && index_width > left && index_width < right) {
				printf("*");
			}
			else if (index_high == block_x && index_width == block_y) {
				printf("B");
			}
			else {
				printf(" ");
			}
		}
		printf("\n");
	}
	printf("反弹小球数：%d\n", ball_number);
	printf("消掉的砖块数：%d\n", score);
}

// 用户输入无关的更新
void upDateWithoutInput(){
	if (ball_x == high - 1) {
		if (ball_y >= left && ball_y <= right) {
			ball_number++;
			printf("\a");
		}
		else {
			// system("cls");
			printf("游戏结束\n");
			system("pause");
			exit(0);
		}
	}
	
	if (ball_x == block_x && ball_y == block_y) {
		score++;
		srand((unsigned int)time(NULL));
		block_y = rand() % width;
	}

	ball_x = ball_x + ball_vx;
	ball_y = ball_y + ball_vy;

	if (ball_x == 0 || ball_x == high - 1) {
		ball_vx = -ball_vx;
	}
	if (ball_y == 0 || ball_y == width - 1) {
		ball_vy = -ball_vy;
	}
	Sleep(80);
}

// 用户输入有关的更新
void upDateWithInput(){
	char input;
	if (kbhit()) {
		input = getch();
		if (input == 'a') {
			pos_y--;
			left = pos_y - ridus;
			right = pos_y + ridus;
		}
		if (input == 'd') {
			pos_y++;
			left = pos_y - ridus;
			right = pos_y + ridus;
		}
	}
}
