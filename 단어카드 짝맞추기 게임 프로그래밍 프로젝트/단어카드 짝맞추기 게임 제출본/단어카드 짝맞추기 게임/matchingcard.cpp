#pragma once
#include "matchingcard.h"

void GotoXY(int x, int y) {
    COORD pos;  //좌표값 저장 구조체
    pos.X = 2 * x;  //x좌표는 2를 곱한다
    pos.Y = y;  //y좌표는 입력받은 값대로
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);     //커서 이동
}

void SetConsoleView() {
    system("mode con:cols=80 lines=15");    //콘솔창 사이즈 설정(가로로 김)
    system("title Eng word Matchig Game!");    //영단어 짝맞추기 게임이라는 콘솔 제목 설정
}

void SetDictionary(vector<string>& strArr) {
    static const int INIT_NUM = 16;
    static const string str[INIT_NUM] = { "outcome", "결과", "outgoing", "외향적인", "outlet", "배출구", "outline", "개요(를 서술하다)", "outlook", "전망", "outstanding", "뛰어난", "outward", "표면상의", "outdo", "능가하다" };    //샘플 단어들
    ifstream readFromFile("word_list.txt");     //word_list.txt 파일을 읽기 전용으로 오픈
    if (!readFromFile.is_open())      //is_open이 되지 않는다는것은 파일이 없다는 것
    {
        ofstream writeToFile("word_list.txt");    //쓰기 전용으로 word_list.txt 파일을 오픈 (읽을 수 없다 == 파일이 없다 이므로 자동으로 만들어준다)
        for (int i = 0; i < INIT_NUM; ++i) {    //샘플 단어들을 한 줄 한 줄 word_list.txt 파일에 입력
            string tmp = str[i];
            if (i != INIT_NUM - 1) {
                tmp += "\n";
            }
            writeToFile.write(tmp.c_str(), tmp.size());    //파일에 쓰는 함수
            strArr.push_back(str[i]); //단어장(strArr)에 단어를 집어넣습니다.
        }
        writeToFile.close();    //쓰기전용파일 닫기
        return;                    //함수끝
    }

    //여기로 왔다는것은 읽기전용으로 파일오픈 되었다는뜻.  //여기 뭐라고 뜨는데 잘못 누른 거? 같아요???
    for (int i = 0; i < 16; i++) {  //16번 넘어가면 저장 못하므로 16번만 반복
        string tmp;
        getline(readFromFile, tmp);    //한줄씩 읽어서
        strArr.push_back(tmp);        //단어장(strArr)에 단어 넣기
    }
    readFromFile.close();        //읽기전용파일 닫기
    return;
}

int GetKeyDown() {
    if (_kbhit() != 0) {
        return _getch();    //키보드 입력...
    }
    return 0;
}

void randarr(vector<string>& strarr, vector<string>& wordlist) {

    ifstream readFromFile("word_list.txt");     //word_list.txt읽기전용
    if (!readFromFile.is_open()) return;       //안열리면 오류

    srand(time(0));//초기화

    int arr[16];//인덱스 값을 섞어서 랜덤 저장할 예정(인덱스 값 담을 배열)
    for (int i = 0; i < 16; i++) {
        arr[i] = i;//0~16까지의 값을 담고 있음...이 아니구나 방금 수정함 담고 있음...
    }

    int x, y;//임의의 값 두 개
    int temp;//임시로 저장하고 있을 값 교환용 변수

    //최대 50번 섞는다
    for (int i = 0; i < MAX_CHANGE_TIME; i++) {
        x = rand() % 16;
        y = rand() % 16;

        if (x != y) {//같으면 굳이 바꿀 필요 없으니까......
            temp = arr[x];
            arr[x] = arr[y];
            arr[y] = temp;
        }
    }

    for (int i = 0; i < 16; i++) {
        strarr.push_back(wordlist[arr[i]]);     //섞인 인덱스 값 순서대로 단어 저장
    }

    return;
}

void SetTextColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}