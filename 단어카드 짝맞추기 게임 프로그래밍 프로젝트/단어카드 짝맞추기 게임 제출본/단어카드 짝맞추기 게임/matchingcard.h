#pragma once

#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<fstream>
#include<vector>
#include<string>
using namespace std;
#define INIT_POS 1
#define MAX_CHANGE_TIME 50

//�ܼ� ���η� Ŀ�� �̵�!
void GotoXY(int x, int y);

//�ܼ� â ũ��� â ����
void SetConsoleView();

//�ܾ��� Ȯ��, ������ ����
void SetDictionary(vector<string>& strArr);

//Ű���� �Է� ����
int GetKeyDown();

//������ �迭 ���� ��ǥ ����ü...(����� for���� i, j����)
struct Pos {
    int x, y;
};

//���Ʒ� ȭ��ǥ
enum KEYBOARD {
    UP = 72,
    DOWN = 80
};

//�ո�ī�� ����
void randarr(vector<string>& strarr, vector<string>& wordlist);

//���ڻ� �ٲٱ�
void SetTextColor(int color);