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

//콘솔 내부로 커서 이동!
void GotoXY(int x, int y);

//콘솔 창 크기랑 창 제목
void SetConsoleView();

//단어장 확인, 없을시 생성
void SetDictionary(vector<string>& strArr);

//키보드 입력 감지
int GetKeyDown();

//이차원 배열 위한 좌표 구조체...(별찍기 for문의 i, j느낌)
struct Pos {
    int x, y;
};

//위아래 화살표
enum KEYBOARD {
    UP = 72,
    DOWN = 80
};

//앞면카드 섞기
void randarr(vector<string>& strarr, vector<string>& wordlist);

//글자색 바꾸기
void SetTextColor(int color);