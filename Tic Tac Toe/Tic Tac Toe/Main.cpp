#include<iostream>
using namespace std;
void Player1(void); //���1����(����)����
void Player2(void); //���2����(����)����
void game_judge(void); //��Ӯ�ж�
void game_start(void); //��Ϸ��ʼ
int rows = 3, cols = 3; //���̴�С
bool win1_flag = false; //���1��ʤ��־λ
bool win2_flag = false; //���2��ʤ��־λ
char pieces[3][3] = { {' ',' ',' '},
{' ',' ',' '},
{' ',' ',' '} };; //��ʼ��
void draw(void) //��ӡ������
{
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << pieces[i][j];
			if (j < cols - 1)
				cout << " | ";
		}
		cout << "\n";
		if (i < rows - 1)
			cout << "����������" << endl;
	}
	cout << "\n";
}
void game_start(void) //��Ϸ��ʼ
{
	int n = 0; //��3*3=9������λ,�����ж��Ƿ�����
	bool flag = false; //����л���־λ
	cout << "��Ϸ��ʼ" << endl;
	while (n < 9 & win1_flag == false & win2_flag == false) //δ����,δ�ֳ�ʤ���������Ϸ
	{
		if (flag == false) { //�л������1
			cout << "���1����:" << endl;
			Player1(); //���1��������λ��
			flag = true; //��һ�������2
		}
		else { //�л������2
			cout << "���2����:" << endl;
			Player2(); //���2��������λ��
			flag = false; //��һ�������1
		}
		game_judge(); //�ж�ʤ��
		draw(); //��ӡ������
		n++; //����������һö����
	}
}
void game_judge(void) //�ж�ʤ��
{
	for (int i = 0; i < rows; i++) {
		if (pieces[i][0] == pieces[i][1] & pieces[i][0] == pieces[i][2] & pieces[i][0] != ' ') //�жϺ᷽����3����ͬ������
		{
			if (pieces[i][0] == 'O') //�ж������1�����ӻ������2
				win1_flag = true; //���1��ʤ
			else
				win2_flag = true; //���2��ʤ
		}
		if (pieces[0][i] == pieces[1][i] & pieces[1][i] == pieces[2][i] & pieces[0][i] != ' ') //�ж��ݷ�����3����ͬ������
		{
			if (pieces[0][i] == 'O') //�ж������1�����ӻ������2
				win1_flag = true;
			else
				win2_flag = true;
		}
		if ((pieces[0][0] == pieces[1][1] & pieces[1][1] == pieces[2][2] & pieces[0][0] != ' ') //�ж�б������3����ͬ������
			| (pieces[0][2] == pieces[1][1] & pieces[1][1] == pieces[2][0] & pieces[2][0] != ' '))
		{
			if (pieces[1][1] == 'O') //�ж������1�����ӻ������2
				win1_flag = true;
			else
				win2_flag = true;
		}
	}
}
void Player1(void)
{
	int row0, col0;
	cin >> row0 >> col0; //���1����λ��
	while (pieces[row0 - 1][col0 - 1] != ' ') //�жϸ�λ���Ƿ���������,�򲻴���
	{
		cout << "��λ���������,����������" << endl;
		cout << "������������(1-3),�Կո����:";
		cin >> row0 >> col0; //��������λ��
	}
	pieces[row0 - 1][col0 - 1] = 'O'; //�����з������1����
}
void Player2(void)
{
	int row1, col1;
	cin >> row1 >> col1; //���1����λ��
	while (pieces[row1 - 1][col1 - 1] != ' ') //�жϸ�λ���Ƿ���������,�򲻴���
	{
		cout << "��λ���������,����������" << endl;
		cout << "������������(1-3),�Կո����:";
		cin >> row1 >> col1; //��������λ��
	}
	pieces[row1 - 1][col1 - 1] = 'X'; //�����з������2����
}
int main(int argc, char** argv)
{
	cout << "��Ϸ������" << endl;
	draw(); //��ӡ��ʼ����
	game_start(); //��ʼ��Ϸ
	if (win1_flag == true) //���1��ʤ
		cout << "���1��ʤ!" << endl;
	if (win2_flag == true) //���2��ʤ
		cout << "���2��ʤ!" << endl;
	if (win1_flag == win2_flag) //��δ��ʤ,ƽ��
		cout << "ƽ��!" << endl;
	return 0;
}