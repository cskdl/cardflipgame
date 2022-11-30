#pragma once
#include "matchingcard.h"

void GotoXY(int x, int y) {
    COORD pos;  //��ǥ�� ���� ����ü
    pos.X = 2 * x;  //x��ǥ�� 2�� ���Ѵ�
    pos.Y = y;  //y��ǥ�� �Է¹��� �����
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);     //Ŀ�� �̵�
}

void SetConsoleView() {
    system("mode con:cols=80 lines=15");    //�ܼ�â ������ ����(���η� ��)
    system("title Eng word Matchig Game!");    //���ܾ� ¦���߱� �����̶�� �ܼ� ���� ����
}

void SetDictionary(vector<string>& strArr) {
    static const int INIT_NUM = 16;
    static const string str[INIT_NUM] = { "outcome", "���", "outgoing", "��������", "outlet", "���ⱸ", "outline", "����(�� �����ϴ�)", "outlook", "����", "outstanding", "�پ", "outward", "ǥ�����", "outdo", "�ɰ��ϴ�" };    //���� �ܾ��
    ifstream readFromFile("word_list.txt");     //word_list.txt ������ �б� �������� ����
    if (!readFromFile.is_open())      //is_open�� ���� �ʴ´ٴ°��� ������ ���ٴ� ��
    {
        ofstream writeToFile("word_list.txt");    //���� �������� word_list.txt ������ ���� (���� �� ���� == ������ ���� �̹Ƿ� �ڵ����� ������ش�)
        for (int i = 0; i < INIT_NUM; ++i) {    //���� �ܾ���� �� �� �� �� word_list.txt ���Ͽ� �Է�
            string tmp = str[i];
            if (i != INIT_NUM - 1) {
                tmp += "\n";
            }
            writeToFile.write(tmp.c_str(), tmp.size());    //���Ͽ� ���� �Լ�
            strArr.push_back(str[i]); //�ܾ���(strArr)�� �ܾ ����ֽ��ϴ�.
        }
        writeToFile.close();    //������������ �ݱ�
        return;                    //�Լ���
    }

    //����� �Դٴ°��� �б��������� ���Ͽ��� �Ǿ��ٴ¶�.  //���� ����� �ߴµ� �߸� ���� ��? ���ƿ�???
    for (int i = 0; i < 16; i++) {  //16�� �Ѿ�� ���� ���ϹǷ� 16���� �ݺ�
        string tmp;
        getline(readFromFile, tmp);    //���پ� �о
        strArr.push_back(tmp);        //�ܾ���(strArr)�� �ܾ� �ֱ�
    }
    readFromFile.close();        //�б��������� �ݱ�
    return;
}

int GetKeyDown() {
    if (_kbhit() != 0) {
        return _getch();    //Ű���� �Է�...
    }
    return 0;
}

void randarr(vector<string>& strarr, vector<string>& wordlist) {

    ifstream readFromFile("word_list.txt");     //word_list.txt�б�����
    if (!readFromFile.is_open()) return;       //�ȿ����� ����

    srand(time(0));//�ʱ�ȭ

    int arr[16];//�ε��� ���� ��� ���� ������ ����(�ε��� �� ���� �迭)
    for (int i = 0; i < 16; i++) {
        arr[i] = i;//0~16������ ���� ��� ����...�� �ƴϱ��� ��� ������ ��� ����...
    }

    int x, y;//������ �� �� ��
    int temp;//�ӽ÷� �����ϰ� ���� �� ��ȯ�� ����

    //�ִ� 50�� ���´�
    for (int i = 0; i < MAX_CHANGE_TIME; i++) {
        x = rand() % 16;
        y = rand() % 16;

        if (x != y) {//������ ���� �ٲ� �ʿ� �����ϱ�......
            temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
    }

    for (int i = 0; i < 16; i++) {
        strarr.push_back(wordlist[arr[i]]);     //���� �ε��� �� ������� �ܾ� ����
    }

    return;
}

void SetTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}