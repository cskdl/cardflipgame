#pragma once

//���� ���� ȭ��
#include "carddeck.h"

#define MAGIC_KEY 224    //�����¿� ȭ��ǥ�� ���ö� ����Ǿ� ������ ����
#define SPACE 32
#define BACKSPACE 'x'
#define ESC 27

//ť������ ����ȭ��
void DrawQmain(Deck* gamemanager);

//ť������-�ܾ��� ����
void howtowordlist(Deck* gamemanager);

//ť������-���� �÷���
void howtoplay(Deck* gamemanager);

//ť������-���۹�
void howtomove(Deck* gamemanager);

//��ü ���� ȭ��
void drawconsolemain(Deck* gamemanager);