#pragma once
#include "carddeck.h"
#include "consolemain.h"

void Deck::Init() {
    system("cls");  //화면 지우기
    for (int y = 0; y < 4; ++y)
    {
        for (int x = 0; x < 4; ++x)
        {
            cardDeck[y][x] = "??";    //카드를 다 물음표로 세팅
        }
    }
    //수를 셀 변수 전부 0으로 초기화
    reversecardcount = 0;
    reversecount = 0;
    point = 0;
}

int Deck::arrverchange(int* x, int* y) {
    int index;
    index = (4 * *y) + *x;  //열이 0부터 시작하므로 열 * 4를 더하면 놓친 만큼 더해줄 수 있음
    return index;
}

void Deck::FlipCard(vector<string>& strarr, int* x, int* y) {
    if (cardDeck[*y][*x] != "??") return;   //??가 아니면 뒤집은 상태이므로 무시
    if (reversecardcount >= 2) return;  //한 번에 두 번보다 많아 뒤집었을 경우 오류(0부터 시작하므로 2이상)
    reversePos[reversecardcount].x = *x;    //처음이면 0번째 인덱스
    reversePos[reversecardcount].y = *y;    //두번째면 1번째 인덱스에 저장한다
    cardDeck[*y][*x] = strarr[(arrverchange(x, y))];    //뒤집은 카드는 덱에 뒤집은 채로 저장한다.
    ++reversecardcount; //뒤집음 카운트 증가
}

void Deck::keyremove(vector<string>& wordset) {
    system("cls");  //전부 지우고
    DrawMain(wordset);  //게임 판만 다시 프린트
}

int Deck::isit_matched(vector<string>& wordlist, vector<string>& frontcard, int* x, int* y) {
    int i;  //인덱스 반환용
    string selectedcard = frontcard[arrverchange(x, y)];    //입력받은 위치의 단어 저장하는 문자열
    for (i = 0; i < 16; i++) {
        if (selectedcard == wordlist[i]) break; //단어장(안섞임)의 단어와 문자열의 단어 일치시 중단
    }
    return i;   //인덱스 반환
}

void Deck::DrawGameClear() {
    system("cls");  //전부 지우기
    SetTextColor(14);   //노란색 글씨로
    GotoXY(13, 3);  //커서 이동
    cout << "=========================";
    GotoXY(13, 4);
    cout << "======= C L E A R =======";
    GotoXY(13, 5);
    cout << "=========================";
    SetTextColor(15);   //흰색 글씨로
    GotoXY(13, 7);  //커서 이동
    cout << "your flip count is " << reversecount;  //얼마만에 다 뒤집었는지 최종 출력
}

void Deck::CheckCard(vector<string>& wordlist, vector<string>& frontcard, int* x1, int* x2, int* y1, int* y2, Deck* gamemanager) {
    int firstcard, secondcard;  //인덱스 값 담을 것이므로 정수형 변수, 첫번째카드, 두번째카드 생성
    firstcard = isit_matched(wordlist, frontcard, x1, y1);  //첫번째 카드에는 첫번째 좌표 값 대입
    secondcard = isit_matched(wordlist, frontcard, x2, y2); //두번째 카드에는 두번째 좌표 값 대입
    if (reversecardcount == 2)  //두번 뒤집었으면(0에서 +1, 1에서 +1 했으므로 2)
    {
        string c1 = "??", c2 = "??";    //첫번째 카드, 두번째 카드의 대역 세우기
        if (firstcard - secondcard == 1 || secondcard - firstcard == 1)     //카드의 인덱스값이 1이 차이난다면
        {
            //같을때(동시에 더 작은 쪽의 인덱스 짝수)
            if ((firstcard < secondcard && firstcard % 2 == 0) || (firstcard > secondcard && secondcard % 2 == 0)) {
                c1 = cardDeck[reversePos[0].y][reversePos[0].x];    //뒷면 대역변수를 앞면으로 변경
                c2 = cardDeck[reversePos[1].y][reversePos[1].x];    //변경
                point++;    //맞춘 카드 증가
            }
        }
        else
        {
            //다를때.
            Sleep(1000);    //1초 기다리기
        }
        cardDeck[reversePos[0].y][reversePos[0].x] = c1;    //맞았으면 카드 앞면을 덱에 저장
        cardDeck[reversePos[1].y][reversePos[1].x] = c2;    //틀렸으면 ??를 덱에 저장
        reversecardcount = 0;   //턴 초기화
        ++reversecount;     //뒤집은 횟수 증가
        if (point >= 8)     //8개 이상 맞췄을 경우 전부 맞춘 것
        {
            DrawGameClear();    //게임 클리어 화면 띄워주기
            Sleep(2000);    //2초 기다리기
            system("cls");      //화면 지우기
            drawconsolemain(gamemanager);   //콘솔 자체 메인화면으로 돌아가기
        }
    }
}

void Deck::KeyMove(int* x, int* y, int reversecardcount, vector<string>& wordset) {
    GotoXY(1, 11);  //커서 이동
    cout << "움직일 " << (reversecardcount + 1) << "카드의 좌표를 입력해주세요(입력 양식 - x y) : ";   //한 턴에서 몇 번째인지 알려주면서 입력방식 알려주기
    cin >> *x;  //x좌표
    cin >> *y;  //y좌표
    if (*x < 0 || *x > 3 || *y < 0 || *y > 3) {     //0-3, 0-3이 범위로 값이 그 범위를 넘어갔을 경우
        GotoXY(1, 12);
        cout << "좌표 범위를 벗어났습니다." ;
        GotoXY(1, 13);
        cout << "0~3 사이의 값을 입력해주세요.";   //사용자에게 범위 알림
        Sleep(1000);    //1초 기다리기
        keyremove(wordset);     //좌표 입력부분만 지우기
        KeyMove(x, y, reversecardcount, wordset);   //다시 좌표 이동
    }
}

void Deck::DrawMain(vector<string>& wordset) {
    SetTextColor(15);   //글자색 흰색으로 설정
    vector<string> c(16, "??");     //??으로 초기화한 문자열 배열 16개(만일, 초기 생성 대비)
    int index;  //arrverchange를 계속 하면 번거로우므로 담을 변수를 생성
    for (int y = 0; y < 4; ++y) {
        GotoXY(INIT_POS, INIT_POS + (2 * y));
        for (int x = 0; x < 4; ++x) {
            index = arrverchange(&x, &y);
            c[index] = cardDeck[y][x];  //덱이 담은 문자열을 c에 저장
            if (c[index] != "??") {     //카드 앞면일 경우
                SetTextColor(11);   //글자 색 하늘색으로 설정
            }
            cout << "[ " << c[index] << " ]   ";    //출력
            SetTextColor(15);   //흰색으로 설정
        }
    }
    GotoXY(1, 9);
    cout << "Count : " << reversecount;     //판 밑에 얼마나 뒤집었는지 표시
}

void Deck::startgame(Deck* gamemanager) {
    Init();     //게임 시작시 초기화

    vector<string> wordset;     //단어장
    vector<string> frontcard;       //뒤집은 카드의 앞면

    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;     //첫, 두번째 카드의 좌표

    SetDictionary(wordset);     //단어장 생성

    randarr(frontcard, wordset);    //카드 섞기

    DrawMain(wordset);      //게임 화면 출력

    while (point < 8) {     //8점보다 작은 동안(8점 얻을시 끝나므로)
        KeyMove(&x1, &y1, reversecardcount, wordset);   //첫번째 카드 좌표 입력
        FlipCard(frontcard, &x1, &y1);      //첫번째 카드 뒤집기
        Sleep(1000);    //1초 기다리기
        keyremove(wordset);     //키 입력 부분 지우고

        KeyMove(&x2, &y2, reversecardcount, wordset);   //두번째 카드 좌표 입력
        FlipCard(frontcard, &x2, &y2);  //두번째 카드 뒤집기
        DrawMain(wordset);  //뒤집은 화면 출력

        Sleep(1000);    //1초 쉬었다가
        CheckCard(wordset, frontcard, &x1, &x2, &y1, &y2, gamemanager);     //카드 짝 확인
        if (point < 8) keyremove(wordset);
    }
}