#pragma once

//게임 메인 화면
#include "carddeck.h"

#define MAGIC_KEY 224    //상하좌우 화살표가 들어올때 선행되어 들어오는 숫자
#define SPACE 32
#define BACKSPACE 'x'
#define ESC 27

//큐엔에이 메인화면
void DrawQmain(Deck* gamemanager);

//큐엔에이-단어장 설정
void howtowordlist(Deck* gamemanager);

//큐엔에이-게임 플레이
void howtoplay(Deck* gamemanager);

//큐엔에이-조작법
void howtomove(Deck* gamemanager);

//전체 메인 화면
void drawconsolemain(Deck* gamemanager);