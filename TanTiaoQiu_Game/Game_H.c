#include "Game_H.h"

// ������
int high, width; // �����Ŀ��
int ball_x, ball_y; // ���λ��
int ball_vx, ball_vy; // ����ƶ�λ��
int pos_x, pos_y; // �������������
int ridus; // ����İ뾶
int left, right; // ���������λ��
int ball_number; //����С��Ĵ���
int block_x, block_y; // ש���λ��
int score; // ����

// ������ƶ����ض��ĵص�
void gotoxy(int x, int y){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(handle, pos);
}

// ���ݳ�ʼ��
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

// ��ʾ
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
	printf("����С������%d\n", ball_number);
	printf("������ש������%d\n", score);
}

// �û������޹صĸ���
void upDateWithoutInput(){
	if (ball_x == high - 1) {
		if (ball_y >= left && ball_y <= right) {
			ball_number++;
			printf("\a");
		}
		else {
			// system("cls");
			printf("��Ϸ����\n");
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

// �û������йصĸ���
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
