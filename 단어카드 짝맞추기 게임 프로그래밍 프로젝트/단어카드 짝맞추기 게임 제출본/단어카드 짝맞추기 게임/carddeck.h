#pragma once
#include "matchingcard.h"

class Deck {
private:
    string cardDeck[4][4];  //4*4 ī��
    Pos reversePos[2];  //�� ���� �� �� �����´�(������ ī�� 2���� x, y��ǥ ��� �迭)
    int reversecount; //������ Ƚ��
    int reversecardcount; //������ ī���� ����
    int point;  //���� �� ����

    //�ʱ�ȭ
    void Init();

    //������ �迭���� ������ �迭 �ε��� ������ �ٲٴ� �Լ�
    int arrverchange(int* x, int* y);

    //ī�� ������
    void FlipCard(vector<string>& strarr, int* x, int* y);

    //Ű�� �Է����ּ��� �κ� �����
    void keyremove(vector<string>& wordset);

    //�ܾ� Ȯ���� �ܾ����� �ε��� ���� ��ȯ
    int isit_matched(vector<string>& wordlist, vector<string>& frontcard, int* x, int* y);

    //��� �� ���߸� Ŭ����, �׶��� ȭ��
    void DrawGameClear();

    //�ε��� ���� ���� 1�̰� �� ���� �� ¦���� �� ī��� ¦�̴�
    void CheckCard(vector<string>& wordlist, vector<string>& frontcard, int* x1, int* x2, int* y1, int* y2, Deck* gamemanager);

    //��ǥ �Է����ּ���
    void KeyMove(int* x, int* y, int reversecardcount, vector<string>& wordset);

    //����ȭ�� ���
    void DrawMain(vector<string>& wordset);

public:
    //���� ����
    void startgame(Deck* gamemanager);
};