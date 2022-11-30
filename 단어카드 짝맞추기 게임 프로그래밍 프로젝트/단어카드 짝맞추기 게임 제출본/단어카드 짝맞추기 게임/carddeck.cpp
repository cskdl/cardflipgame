#pragma once
#include "carddeck.h"
#include "consolemain.h"

void Deck::Init() {
    system("cls");  //ȭ�� �����
    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 4; ++x)
        {
            cardDeck[y][x] = "??";    //ī�带 �� ����ǥ�� ����
        }
    }
    //���� �� ���� ���� 0���� �ʱ�ȭ
    reversecardcount = 0;
    reversecount = 0;
    point = 0;
}

int Deck::arrverchange(int* x, int* y) {
    int index;
    index = (4 * *y) + *x;  //���� 0���� �����ϹǷ� �� * 4�� ���ϸ� ��ģ ��ŭ ������ �� ����
    return index;
}

void Deck::FlipCard(vector<string>& strarr, int* x, int* y) {
    if (cardDeck[*y][*x] != "??") return;   //??�� �ƴϸ� ������ �����̹Ƿ� ����
    if (reversecardcount >= 2) return;  //�� ���� �� ������ ���� �������� ��� ����(0���� �����ϹǷ� 2�̻�)
    reversePos[reversecardcount].x = *x;    //ó���̸� 0��° �ε���
    reversePos[reversecardcount].y = *y;    //�ι�°�� 1��° �ε����� �����Ѵ�
    cardDeck[*y][*x] = strarr[(arrverchange(x, y))];    //������ ī��� ���� ������ ä�� �����Ѵ�.
    ++reversecardcount; //������ ī��Ʈ ����
}

void Deck::keyremove(vector<string>& wordset) {
    system("cls");  //���� �����
    DrawMain(wordset);  //���� �Ǹ� �ٽ� ����Ʈ
}

int Deck::isit_matched(vector<string>& wordlist, vector<string>& frontcard, int* x, int* y) {
    int i;  //�ε��� ��ȯ��
    string selectedcard = frontcard[arrverchange(x, y)];    //�Է¹��� ��ġ�� �ܾ� �����ϴ� ���ڿ�
    for (i = 0; i < 16; i++) {
        if (selectedcard == wordlist[i]) break; //�ܾ���(�ȼ���)�� �ܾ�� ���ڿ��� �ܾ� ��ġ�� �ߴ�
    }
    return i;   //�ε��� ��ȯ
}

void Deck::DrawGameClear() {
    system("cls");  //���� �����
    SetTextColor(14);   //����� �۾���
    GotoXY(13, 3);  //Ŀ�� �̵�
    cout << "=========================";
    GotoXY(13, 4);
    cout << "======= C L E A R =======";
    GotoXY(13, 5);
    cout << "=========================";
    SetTextColor(15);   //��� �۾���
    GotoXY(13, 7);  //Ŀ�� �̵�
    cout << "your flip count is " << reversecount;  //�󸶸��� �� ���������� ���� ���
}

void Deck::CheckCard(vector<string>& wordlist, vector<string>& frontcard, int* x1, int* x2, int* y1, int* y2, Deck* gamemanager) {
    int firstcard, secondcard;  //�ε��� �� ���� ���̹Ƿ� ������ ����, ù��°ī��, �ι�°ī�� ����
    firstcard = isit_matched(wordlist, frontcard, x1, y1);  //ù��° ī�忡�� ù��° ��ǥ �� ����
    secondcard = isit_matched(wordlist, frontcard, x2, y2); //�ι�° ī�忡�� �ι�° ��ǥ �� ����
    if (reversecardcount == 2)  //�ι� ����������(0���� +1, 1���� +1 �����Ƿ� 2)
    {
        string c1 = "??", c2 = "??";    //ù��° ī��, �ι�° ī���� �뿪 �����
        if (firstcard - secondcard == 1 || secondcard - firstcard == 1)     //ī���� �ε������� 1�� ���̳��ٸ�
        {
            //������(���ÿ� �� ���� ���� �ε��� ¦��)
            if ((firstcard < secondcard && firstcard % 2 == 0) || (firstcard > secondcard && secondcard % 2 == 0)) {
                c1 = cardDeck[reversePos[0].y][reversePos[0].x];    //�޸� �뿪������ �ո����� ����
                c2 = cardDeck[reversePos[1].y][reversePos[1].x];    //����
                point++;    //���� ī�� ����
            }
        }
        else
        {
            //�ٸ���.
            Sleep(1000);    //1�� ��ٸ���
        }
        cardDeck[reversePos[0].y][reversePos[0].x] = c1;    //�¾����� ī�� �ո��� ���� ����
        cardDeck[reversePos[1].y][reversePos[1].x] = c2;    //Ʋ������ ??�� ���� ����
        reversecardcount = 0;   //�� �ʱ�ȭ
        ++reversecount;     //������ Ƚ�� ����
        if (point >= 8)     //8�� �̻� ������ ��� ���� ���� ��
        {
            DrawGameClear();    //���� Ŭ���� ȭ�� ����ֱ�
            Sleep(2000);    //2�� ��ٸ���
            system("cls");      //ȭ�� �����
            drawconsolemain(gamemanager);   //�ܼ� ��ü ����ȭ������ ���ư���
        }
    }
}

void Deck::KeyMove(int* x, int* y, int reversecardcount, vector<string>& wordset) {
    GotoXY(1, 11);  //Ŀ�� �̵�
    cout << "������ " << (reversecardcount + 1) << "ī���� ��ǥ�� �Է����ּ���(�Է� ��� - x y) : ";   //�� �Ͽ��� �� ��°���� �˷��ָ鼭 �Է¹�� �˷��ֱ�
    cin >> *x;  //x��ǥ
    cin >> *y;  //y��ǥ
    if (*x < 0 || *x > 3 || *y < 0 || *y > 3) {     //0-3, 0-3�� ������ ���� �� ������ �Ѿ�� ���
        GotoXY(1, 12);
        cout << "��ǥ ������ ������ϴ�." ;
        GotoXY(1, 13);
        cout << "0~3 ������ ���� �Է����ּ���.";   //����ڿ��� ���� �˸�
        Sleep(1000);    //1�� ��ٸ���
        keyremove(wordset);     //��ǥ �Էºκи� �����
        KeyMove(x, y, reversecardcount, wordset);   //�ٽ� ��ǥ �̵�
    }
}

void Deck::DrawMain(vector<string>& wordset) {
    SetTextColor(15);   //���ڻ� ������� ����
    vector<string> c(16, "??");     //??���� �ʱ�ȭ�� ���ڿ� �迭 16��(����, �ʱ� ���� ���)
    int index;  //arrverchange�� ��� �ϸ� ���ŷο�Ƿ� ���� ������ ����
    for (int y = 0; y < 4; ++y) {
        GotoXY(INIT_POS, INIT_POS + (2 * y));
        for (int x = 0; x < 4; ++x) {
            index = arrverchange(&x, &y);
            c[index] = cardDeck[y][x];  //���� ���� ���ڿ��� c�� ����
            if (c[index] != "??") {     //ī�� �ո��� ���
                SetTextColor(11);   //���� �� �ϴû����� ����
            }
            cout << "[ " << c[index] << " ]   ";    //���
            SetTextColor(15);   //������� ����
        }
    }
    GotoXY(1, 9);
    cout << "Count : " << reversecount;     //�� �ؿ� �󸶳� ���������� ǥ��
}

void Deck::startgame(Deck* gamemanager) {
    Init();     //���� ���۽� �ʱ�ȭ

    vector<string> wordset;     //�ܾ���
    vector<string> frontcard;       //������ ī���� �ո�

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;     //ù, �ι�° ī���� ��ǥ

    SetDictionary(wordset);     //�ܾ��� ����

    randarr(frontcard, wordset);    //ī�� ����

    DrawMain(wordset);      //���� ȭ�� ���

    while (point < 8) {     //8������ ���� ����(8�� ������ �����Ƿ�)
        KeyMove(&x1, &y1, reversecardcount, wordset);   //ù��° ī�� ��ǥ �Է�
        FlipCard(frontcard, &x1, &y1);      //ù��° ī�� ������
        Sleep(1000);    //1�� ��ٸ���
        keyremove(wordset);     //Ű �Է� �κ� �����

        KeyMove(&x2, &y2, reversecardcount, wordset);   //�ι�° ī�� ��ǥ �Է�
        FlipCard(frontcard, &x2, &y2);  //�ι�° ī�� ������
        DrawMain(wordset);  //������ ȭ�� ���

        Sleep(1000);    //1�� �����ٰ�
        CheckCard(wordset, frontcard, &x1, &x2, &y1, &y2, gamemanager);     //ī�� ¦ Ȯ��
        if (point < 8) keyremove(wordset);
    }
}