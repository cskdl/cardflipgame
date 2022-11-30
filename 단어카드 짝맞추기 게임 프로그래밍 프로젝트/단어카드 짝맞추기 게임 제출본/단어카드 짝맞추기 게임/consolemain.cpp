#include "consolemain.h"


void howtowordlist(Deck* gamemanager) {
	system("cls");	//���� �ۼ� ���� �ܼ� ȭ�� �����
	GotoXY(1, 1);	//Ŀ�� �̵�
	int input = 0;	//�Է� �ޱ� �뵵
	cout << "������ �ܾ����� ���� ���� 'word_list.txt'�� �۵��մϴ�." << endl
		<< "�ܾ����� 8���� �ܾ�ֱ����� �۵���, �Ѿ�� ���� �ܾ�� ���õ˴ϴ٤�..." << endl
		<< "���� �н��ϱ� ���ϴ� �ܾ �ۼ��� �ܾ����� ������ �� �ֽ��ϴ�." << endl
		<< "�ܾ����� '���ܾ� /(�ٹٲ�) �ܾ��� ��' �� �ݺ����� �̷�����ϴ�." << endl << endl
		<< "@�׷��� Ȥ�� �ܾ �ܾ��� ���� ���� �Ἥ ��ġ�� ��ϳ���?" << endl
		<< "	�������Դϴ�!" << endl << endl
		<< "������ �߸��Ǿ���! �ʹٸ� �ܾ����� ���� �� �ֽ��ϴ�. �� ��쿡�� �ʱ�ȭ(������) �ܾ����� �����˴ϴ�." << endl << endl
		<< "�ڷ� ���� ���� 'x'�� �����ּ���";

	//��� ���� ������� �Է��� �޴´�
	while (1) {
		input = _getch();	//input�� ����� �Է� ����
		if (input == BACKSPACE) DrawQmain(gamemanager);	//'x'Ű ������ ť������ �������� �̵�
		if (input == ESC) {	//escŰ ������ ���α׷� ����
			system("cls");	//ȭ�� �����
			GotoXY(14, 7);	//��� ������ Ŀ�� �̵�
			cout << "������ �����մϴ�...";
			Sleep(1000);	//�ٷ� �����ϸ� ���� �Ⱥ��̴ϱ� 1�� ��ٸ���
			delete(gamemanager);	//�Ҵ� ����
			exit(1);	//���α׷� ����
		}
	}
}

void howtoplay(Deck* gamemanager) {
	system("cls");	//ȭ�� �����
	GotoXY(1, 1);	//Ŀ�� �̵�
	int input = 0;	//����� �Է�
	cout << "�ܾ�ī�� ¦���߱� ������ �÷��̾��� ��ǥ�� �Է¹޾� ī���� ���� ���ߴ� �����Դϴ�." << endl
		<< "[ ?? ]�� ������ ī�尡 16�� �����µ� �÷��̾�� x ��ǥ�� y ��ǥ�� ������ ���̿� �ΰ� �Է��� ī�带 ������ �� �ֽ��ϴ�." << endl
		<< "�ܾ�ī���� ��ǥ�� ������ �����ϴ�. (x y)" << endl
		<< "0 0 // 1 0 // 2 0 // 3 0" << endl
		<< "0 1 // 1 1 // 2 1 // 3 1" << endl
		<< "0 2 // 1 2 // 2 2 // 3 2" << endl
		<< "0 3 // 1 3 // 2 3 // 3 3" << endl
		<< "������ ī��� �ϴû����� ǥ�õ˴ϴ�." << endl << endl
		<< "�ڷ� ���� ���� 'x'�� �����ּ���";

	//��� ���� ������� �Է��� �޴´�
	while (1) {
		input = _getch();	//input�� ����� �Է� ����
		if (input == BACKSPACE) DrawQmain(gamemanager);	//'x'Ű �Է½� ť������ �������� �̵�
		if (input == ESC) {	//escŰ �Է½� ���α׷� ����
			system("cls");
			GotoXY(14, 7);
			cout << "������ �����մϴ�...";
			Sleep(1000);
			delete(gamemanager);
			exit(1);
		}
	}
}

void howtomove(Deck* gamemanager) {
	system("cls");
	GotoXY(1, 1);
	int input = 0;
	cout << "������ ����: ��, �Ʒ� ȭ��ǥ" << endl
		<< "������ ����: �����̽���" << endl
		<< "�ڷ� ����: 'x'" << endl
		<< "���� ����: ���� ȭ�鿡�� ���� ���� ���� or Esc";
	while (1) {
		input = _getch();
		if (input == BACKSPACE) DrawQmain(gamemanager);
		if (input == ESC) {
			system("cls");
			GotoXY(14, 7);
			cout << "������ �����մϴ�...";
			Sleep(1000);
			delete(gamemanager);
			exit(1);
		}
	}
}

void drawconsolemain(Deck* gamemanager) {
	system("cls");	//ȭ�� �����
	GotoXY(1, 7);	//�������� Ŀ�� �̵�
	cout << "�ܾ�ī�� ¦ ���߱� ����";
	GotoXY(13, 5);	//���������� �̵�
	cout << ">���� �÷����ϱ�";
	GotoXY(13, 7);	//y ��ǥ�� �ٲ� �̵�
	cout << ">���� ����";
	GotoXY(13, 9);
	cout << ">���� ����";
	GotoXY(7, 13);
	cout << "���Ʒ� ȭ��ǥ�� �̵�, �����̽��ٷ� ����, Esc�� ����";
	GotoXY(13, 5);	//ù��° �������� Ŀ�� �̵�
	int y = 0;
	int input = 0;
	while (1) {
		input = _getch();
		if (input == MAGIC_KEY) {	//����Ű�� ��쿡 ����Ǵ� Ű�� ���ȴٸ�
			switch (_getch()) {
			case UP:	//���� ȭ��ǥ ���� �޾Ҵٸ�
				if (y <= 0) break;	//0������ ��� �̹� ù��° �������� �ٸ������Ƿ� ����
				y -= 2;	//�ƴ϶�� ���� �������� �̵���Ų��.
				break;
			case DOWN:	//�Ʒ��� ȭ��ǥ ���� �޾Ҵٸ�
				if (y >= 4) break;	//4�̻��� ��� �̹� ������ �������̹Ƿ� ����
				y += 2;	//���� �������� �̵�
				break;
			default:	//�ٸ� ��쿡�� ����
				break;
			}
		}
		if (input == SPACE) {	//�����̽��ٰ� ���ȴٸ�
			switch (y) {
			case 0:	//ù��° ������
				gamemanager->startgame(gamemanager);	//���� ����
				break;
			case 2:	//�ι�° ������
				DrawQmain(gamemanager);	//ť������
				break;
			case 4:	//����° ������
				//���� ����
				system("cls");
				GotoXY(14, 7);
				cout << "������ �����մϴ�...";
				Sleep(1000);
				delete(gamemanager);
				exit(1);
				break;
			default:	//�� ��쿡�� ��������...
				GotoXY(13, 5);	//ù��° �������� Ŀ���� �ű��
				break;
			}
		}
		if (input == ESC) {	//escŰ �Է�
			//���� ����
			system("cls");
			GotoXY(14, 7);
			cout << "������ �����մϴ�...";
			Sleep(1000);
			delete(gamemanager);
			exit(1);
		}
		GotoXY(13, (y + 5));	//�������� x��ǥ�� 13���� ���� ������ ù��° �������� y��ǥ�� 5�̹Ƿ� y�� 5�� ���� �̵�
	}
}

void DrawQmain(Deck* gamemanager) {
	system("cls");	//ȭ�� ����
	int y = 0;
	int input = 0;
	GotoXY(2, 7);
	cout << "*~Q&A~*";
	GotoXY(13, 5);
	cout << ">�ܾ��� ���� ���";
	GotoXY(13, 7);
	cout << ">���� �÷��� ���";
	GotoXY(13, 9);
	cout << ">����Ű ����";
	GotoXY(13, 5);
	while (1) {
		input = _getch();
		if (input == MAGIC_KEY) {
			switch (_getch()) {
			case UP:
				if (y <= 0) break;
				y -= 2;
				break;
			case DOWN:
				if (y >= 4) break;
				y += 2;
				break;
			default:
				break;
			}
		}
		if (input == SPACE) {
			switch (y) {
			case 0:
				howtowordlist(gamemanager);	//�ܾ��� ť������
				break;
			case 2:
				howtoplay(gamemanager);	//�÷��� ���
				break;
			case 4:
				howtomove(gamemanager);	//���۹�
				break;
			default: break;
			}
		}
		if (input == BACKSPACE) {
			drawconsolemain(gamemanager);
		}
		if (input == ESC) {
			system("cls");
			GotoXY(14, 7);
			cout << "������ �����մϴ�...";
			Sleep(1000);
			delete(gamemanager);
			exit(1);
		}
		GotoXY(13, (y + 5));
	}
}