#include <iostream>
#include <cstdlib>			//��׼��
#include <unistd.h>			//��ʱ����
#include <stdio.h>			//getchar	
#include <ctime>			
#include <termios.h>		//�ն�����

#define MAX_X 20
#define MAX_Y 30
bool flag = false;
bool slow = false;
bool autogame = true;

using namespace std;

int maze[MAX_X][MAX_Y];		//�Թ�

//·��ջ
class stack_of_maze {
private:
	//��¼�Թ�����
	struct node
	{
		int x;
		int y;
		char direction;  	//��һ��·����������ģ�
		node* next;
	};
	node* head;
public:
	stack_of_maze() {
		head = NULL;
	}

	~stack_of_maze() {
		node* p = head;
		while (head != NULL) {
			head = head->next;
			delete p;
			p = head;
		}
	}

	//ѹջ
	void push(int xx, int yy, char ddirection) {
		node* new_node = new node;
		if (new_node != NULL) {
			new_node->x = xx;
			new_node->y = yy;
			new_node->direction = ddirection;
			new_node->next = NULL;

			if (head == NULL)
				head = new_node;
			else {
				new_node->next = head;
				head = new_node;
			}
		}
		else
			cout << "�ڴ����ʧ��" << endl;

	}

	//��ջ
	node* pop(int& xx, int& yy) {
		if (head != NULL) {
			node* p = head;
			head = head->next;
			xx = p->x;
			yy = p->y;
			delete p;
		}
		return head;
	}

	void print() {
		if (head != NULL) {
			node* p = head;
			while (p != NULL) {
				cout << " " << p->x << " " << p->y << " " << p->direction << endl;
				p = p->next;
			}
		}
		else
			cout << "ջΪ�գ���ӡʧ��" << endl;
	}
};

//�����Թ�
void createMaze() {
	int maxway = MAX_X * MAX_Y;		//���ͨ·
	int x, y;

	for (x = 0; x < MAX_X; x++)
		for (y = 0; y < MAX_Y; y++)
			maze[x][y] = 1;			//������Թ�

	srand((unsigned)time(NULL));	//����������ӣ���ʱ��Ϊ����
	for (int i = 0; i < maxway; i++)		//��������Թ�ͨ·
	{
		x = rand() % (MAX_X - 2) + 1;
		y = rand() % (MAX_Y - 2) + 1;
		maze[x][y] = 0;
	}

	maze[1][1] = 0; 				//���
	maze[MAX_X - 2][MAX_Y - 2] = 0;		//����

	maze[0][1] = 3;
	maze[MAX_X - 1][MAX_Y - 2] = 0;
}

//����Թ�
void printMaze() {
	int x, y;
	system("clear");				//windows��ʹ��system("cls")
	//cout<<endl;
	for (x = 0; x < MAX_X; x++)
	{
		for (y = 0; y < MAX_Y; y++)
		{
			if (maze[x][y] == 0) { cout << "  "; continue; }		//ͨ·
			if (maze[x][y] == 1) { cout << "��"; continue; }		//ǽ
			if (maze[x][y] == 2) { cout << "��"; continue; }		//����ͬ
			if (maze[x][y] == 3) { cout << "��"; continue; }		//������
			if (maze[x][y] == 4) { cout << "��"; continue; }
			if (maze[x][y] == 5) { cout << "��"; continue; }
			if (maze[x][y] == 6) { cout << "��"; continue; }
			if (maze[x][y] == 7) { cout << "��"; continue; }		//��ǰվ��λ��
		}
		cout << endl;
	}
	if (slow) {
		sleep(1);											//��ʱ����
	}
}

void check(stack_of_maze& s) {
	int temp[MAX_X][MAX_Y];

	for (int x = 0; x < MAX_X; x++)
		for (int y = 0; y < MAX_Y; y++)
			temp[x][y] = maze[x][y];

	int x = 1, y = 1;					//������	
	while (1) {
		temp[x][y] = 2;

		//����
		if (temp[x + 1][y] == 0) {
			s.push(x, y, 'D');
			temp[x][y] = 3;			//�ڵ�ǰλ����һ�����µı�־
			x = x + 1;
			temp[x][y] = 7;			//��ǰλ��
			if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
				flag = true;
				return;
			}
			else
				continue;
		}

		//����
		if (temp[x][y + 1] == 0) {
			s.push(x, y, 'R');
			temp[x][y] = 4;			//�ڵ�ǰλ����һ�����ҵı�־
			y = y + 1;
			temp[x][y] = 7;
			if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
				flag = true;
				return;
			}
			else
				continue;
		}

		//����
		if (temp[x - 1][y] == 0) {
			s.push(x, y, 'U');
			temp[x][y] = 6;			//�ڵ�ǰλ����һ�����ϵı�־
			x = x - 1;
			temp[x][y] = 7;
			if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
				flag = true;
				return;
			}
			else
				continue;
		}

		//����
		if (temp[x][y - 1] == 0) {
			s.push(x, y, 'L');
			temp[x][y] = 5;			//�ڵ�ǰλ����һ�����ҵı�־
			y = y - 1;
			temp[x][y] = 7;
			if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
				flag = true;
				return;
			}
			else
				continue;
		}

		//�������Ҳ�ͨ�������
		if (s.pop(x, y) == NULL && temp[x - 1][y] != 0 && temp[x][y - 1] != 0 && temp[x][y + 1] != 0 && temp[x + 1][y] != 0) {
			temp[0][1] = 7;
			if (temp[1][1] != 1)
				temp[1][1] = 2;
			return;
		}
	}
}

//����,windows�¿���ʹ��#incldue<conio.h>����˺���
char getch() {
	char ch;
	static struct termios oldt, newt;				//����ԭ���ն����Ժ������õ��ն�����
	tcgetattr(STDIN_FILENO, &oldt);				//����ն�ԭ�����Բ������ڽṹ��oldflag

	//�����µ��ն�����
	newt = oldt;
	newt.c_lflag &= ~(ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);

	//ȡ������
	system("stty -echo");
	ch = getchar();
	system("stty echo");

	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);		//���ն˻ָ�Ϊԭ�е�����
	return ch;
}

void move() {
	int x = 1, y = 1;					//������	
	while (1) {
		switch (getch()) {
		case 's':
			if (maze[x + 1][y] == 0) {
				maze[x][y] = 0;
				x = x + 1;
				maze[x][y] = 7;			//��ǰλ��
				printMaze();
				if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
					cout << "\n\n              �ɹ��߳�" << endl;
					return;
				}
			}
			break;
		case 'd':
			if (maze[x][y + 1] == 0) {
				if (maze[x][y + 1] == 0) {
					maze[x][y] = 0;
					y = y + 1;
					maze[x][y] = 7;
					printMaze();
					if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
						cout << "\n\n              �ɹ��߳�" << endl;
						return;
					}
				}
			}

			break;
		case 'w':
			if (maze[x - 1][y] == 0) {
				maze[x][y] = 0;
				x = x - 1;
				maze[x][y] = 7;
				printMaze();
				if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
					cout << "\n\n              �ɹ��߳�" << endl;
					return;
				}
			}
			break;
		case 'a':
			if (maze[x][y - 1] == 0) {
				maze[x][y] = 0;
				y = y - 1;
				maze[x][y] = 7;
				printMaze();
				if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
					cout << "\n\n              �ɹ��߳�" << endl;
					return;
				}
			}
			break;
		}
	}
}

void autoMove(stack_of_maze& s) {
	int x = 1, y = 1;					//������	
	while (1) {
		maze[x][y] = 2;

		//����
		if (maze[x + 1][y] == 0) {
			s.push(x, y, 'D');
			maze[x][y] = 3;			//�ڵ�ǰλ����һ�����µı�־
			x = x + 1;
			maze[x][y] = 7;			//��ǰλ��
			if (slow)
				printMaze();
			if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
				s.push(x, y, '*');
				cout << "\n\n              �ɹ��߳�" << endl;
				return;
			}
			else
				continue;
		}

		//����
		if (maze[x][y + 1] == 0) {
			s.push(x, y, 'R');
			maze[x][y] = 4;			//�ڵ�ǰλ����һ�����ҵı�־
			y = y + 1;
			maze[x][y] = 7;
			if (slow)
				printMaze();
			if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
				s.push(x, y, '*');
				cout << "\n\n              �ɹ��߳�" << endl;
				return;
			}
			else
				continue;
		}

		//����
		if (maze[x - 1][y] == 0) {
			s.push(x, y, 'U');
			maze[x][y] = 6;			//�ڵ�ǰλ����һ�����ϵı�־
			x = x - 1;
			maze[x][y] = 7;
			if (slow)
				printMaze();
			if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
				s.push(x, y, '*');
				cout << "\n\n              �ɹ��߳�" << endl;
				return;
			}
			else
				continue;
		}

		//����
		if (maze[x][y - 1] == 0) {
			s.push(x, y, 'L');
			maze[x][y] = 5;			//�ڵ�ǰλ����һ�����ҵı�־
			y = y - 1;
			maze[x][y] = 7;
			if (slow)
				printMaze();
			if ((x == MAX_X - 1) && (y == MAX_Y - 2)) {
				s.push(x, y, '*');
				cout << "\n\n              �ɹ��߳�" << endl;
				return;
			}
			else
				continue;
		}

		//�������Ҳ�ͨ�������
		if (s.pop(x, y) == NULL && maze[x - 1][y] != 0 && maze[x][y - 1] != 0 && maze[x][y + 1] != 0 && maze[x + 1][y] != 0) {
			cout << "\n\n              û���ҵ����ʵ�·��" << endl;
			maze[0][1] = 7;
			if (maze[1][1] != 1)
				maze[1][1] = 2;
			return;
		}
	}
}

void menu();

void gamestart() {
	flag = false;
	while (!flag) {
		stack_of_maze stack;			//����һ��ջ�Ķ���������¼����·��	
		createMaze();
		check(stack);
		system("clear");
		cout << "\t*                loading.              *" << endl;
		system("clear");
		cout << "\t*                loading..             *" << endl;
		system("clear");
		cout << "\t*                loading...            *" << endl;
	}
	printMaze();						//�����ǰ�Թ��ĳ�ʼ״̬
	cout << "\n\n              ����enter������" << endl;
	getchar();
	if (!autogame) {
		move();
		cout << "\n\n              ����enter������" << endl;
		getchar();
		menu();
	}
	else {
		stack_of_maze stack1;
		autoMove(stack1);					//�����С���
	}
	printMaze();							//����Թ�������״̬
	cout << "\n\n              ����enter������" << endl;
	getchar();
	menu();
}

void menu() {
	system("clear");
	int num;
	cout << "\t****************************************" << endl;
	cout << "\t*                                      *" << endl;
	cout << "\t*               1.�鿴·��             *" << endl;
	cout << "\t*                                      *" << endl;
	cout << "\t*               2.�Զ�����             *" << endl;
	cout << "\t*                                      *" << endl;
	cout << "\t*               3.������Ϸ             *" << endl;
	cout << "\t*                                      *" << endl;
	cout << "\t*               4.�˳���Ϸ             *" << endl;
	cout << "\t*                                      *" << endl;
	cout << "\t****************************************" << endl;
	slow = false;
	switch (getch()) {
	case '1':
		autogame = true;
		gamestart(); break;
	case '2':
		autogame = true;
		slow = true;
		gamestart();
		break;
	case '3':
		autogame = false;
		gamestart();
		break;
	case '4':
		exit(1); break;
	default:
		cout << "\n\n              �������������enter���أ�" << endl;
		getchar();
		menu();
	}
	getchar();
}

int main(int argc, char** argv) {
	menu();
	return 0;
}
