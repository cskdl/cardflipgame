#pragma once
#include "matchingcard.h"

class Deck {
private:
    string cardDeck[4][4];  //4*4 카드
    Pos reversePos[2];  //한 번에 두 번 뒤집는다(뒤집을 카드 2장의 x, y좌표 담는 배열)
    int reversecount; //뒤집은 횟수
    int reversecardcount; //뒤집은 카드의 개수
    int point;  //맞춘 쌍 개수

    //초기화
    void Init();

    //이차원 배열에서 일차원 배열 인덱스 값으로 바꾸는 함수
    int arrverchange(int* x, int* y);

    //카드 뒤집기
    void FlipCard(vector<string>& strarr, int* x, int* y);

    //키를 입력해주세요 부분 지우기
    void keyremove(vector<string>& wordset);

    //단어 확인해 단어장의 인덱스 값을 반환
    int isit_matched(vector<string>& wordlist, vector<string>& frontcard, int* x, int* y);

    //모든 쌍 맞추면 클리어, 그때의 화면
    void DrawGameClear();

    //인덱스 값의 차가 1이고 더 작은 게 짝수면 두 카드는 짝이다
    void CheckCard(vector<string>& wordlist, vector<string>& frontcard, int* x1, int* x2, int* y1, int* y2, Deck* gamemanager);

    //좌표 입력해주세요
    void KeyMove(int* x, int* y, int reversecardcount, vector<string>& wordset);

    //게임화면 출력
    void DrawMain(vector<string>& wordset);

public:
    //게임 시작
    void startgame(Deck* gamemanager);
};