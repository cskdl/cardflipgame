#include "consolemain.h"


void howtowordlist(Deck* gamemanager) {
	system("cls");	//도움말 작성 위해 콘솔 화면 지우기
	GotoXY(1, 1);	//커서 이동
	int input = 0;	//입력 받기 용도
	cout << "게임의 단어장은 파일 속의 'word_list.txt'로 작동합니다." << endl
		<< "단어장은 8개의 단어쌍까지만 작동해, 넘어가는 양의 단어는 무시됩니다ㅠ..." << endl
		<< "따로 학습하기 원하는 단어를 작성해 단어장을 수정할 수 있습니다." << endl
		<< "단어장은 '영단어 /(줄바꿈) 단어의 뜻' 의 반복으로 이루어집니다." << endl << endl
		<< "@그런데 혹시 단어나 단어의 뜻을 같게 써서 겹치면 어떡하나요?" << endl
		<< "	ㄴ유감입니다!" << endl << endl
		<< "완전히 잘못되었다! 싶다면 단어장을 지울 수 있습니다. 그 경우에는 초기화(임의의) 단어장이 생성됩니다." << endl << endl
		<< "뒤로 가기 위해 'x'를 눌러주세요";

	//출력 이후 사용자의 입력을 받는다
	while (1) {
		input = _getch();	//input에 사용자 입력 저장
		if (input == BACKSPACE) DrawQmain(gamemanager);	//'x'키 받으면 큐엔에이 메인으로 이동
		if (input == ESC) {	//esc키 받으면 프로그램 종료
			system("cls");	//화면 지우기
			GotoXY(14, 7);	//가운데 쯤으로 커서 이동
			cout << "게임을 종료합니다...";
			Sleep(1000);	//바로 종료하면 문구 안보이니까 1초 기다리기
			delete(gamemanager);	//할당 해제
			exit(1);	//프로그램 종료
		}
	}
}

void howtoplay(Deck* gamemanager) {
	system("cls");	//화면 지우기
	GotoXY(1, 1);	//커서 이동
	int input = 0;	//사용자 입력
	cout << "단어카드 짝맞추기 게임은 플레이어의 좌표를 입력받아 카드의 쌍을 맞추는 게임입니다." << endl
		<< "[ ?? ]의 뒤집힌 카드가 16개 나오는데 플레이어는 x 좌표와 y 좌표를 공백을 사이에 두고 입력해 카드를 뒤집을 수 있습니다." << endl
		<< "단어카드의 좌표는 다음과 같습니다. (x y)" << endl
		<< "0 0 // 1 0 // 2 0 // 3 0" << endl
		<< "0 1 // 1 1 // 2 1 // 3 1" << endl
		<< "0 2 // 1 2 // 2 2 // 3 2" << endl
		<< "0 3 // 1 3 // 2 3 // 3 3" << endl
		<< "뒤집은 카드는 하늘색으로 표시됩니다." << endl << endl
		<< "뒤로 가기 위해 'x'를 눌러주세요";

	//출력 이후 사용자의 입력을 받는다
	while (1) {
		input = _getch();	//input에 사용자 입력 저장
		if (input == BACKSPACE) DrawQmain(gamemanager);	//'x'키 입력시 큐엔에이 메인으로 이동
		if (input == ESC) {	//esc키 입력시 프로그램 종료
			system("cls");
			GotoXY(14, 7);
			cout << "게임을 종료합니다...";
			Sleep(1000);
			delete(gamemanager);
			exit(1);
		}
	}
}

void howtomove(Deck* gamemanager) {
	system("cls");
	GotoXY(1, 1);
	int input = 0;
	cout << "선택지 변경: 위, 아래 화살표" << endl
		<< "선택지 선택: 스페이스바" << endl
		<< "뒤로 가기: 'x'" << endl
		<< "게임 종료: 메인 화면에서 게임 종료 선택 or Esc";
	while (1) {
		input = _getch();
		if (input == BACKSPACE) DrawQmain(gamemanager);
		if (input == ESC) {
			system("cls");
			GotoXY(14, 7);
			cout << "게임을 종료합니다...";
			Sleep(1000);
			delete(gamemanager);
			exit(1);
		}
	}
}

void drawconsolemain(Deck* gamemanager) {
	system("cls");	//화면 지우기
	GotoXY(1, 7);	//왼쪽으로 커서 이동
	cout << "단어카드 짝 맞추기 게임";
	GotoXY(13, 5);	//오른쪽으로 이동
	cout << ">게임 플레이하기";
	GotoXY(13, 7);	//y 좌표만 바꿔 이동
	cout << ">게임 설명";
	GotoXY(13, 9);
	cout << ">게임 종료";
	GotoXY(7, 13);
	cout << "위아래 화살표로 이동, 스페이스바로 선택, Esc로 종료";
	GotoXY(13, 5);	//첫번째 선택지로 커서 이동
	int y = 0;
	int input = 0;
	while (1) {
		input = _getch();
		if (input == MAGIC_KEY) {	//방향키의 경우에 선행되는 키가 눌렸다면
			switch (_getch()) {
			case UP:	//위쪽 화살표 값을 받았다면
				if (y <= 0) break;	//0이하의 경우 이미 첫번째 선택지와 다름없으므로 무시
				y -= 2;	//아니라면 이전 선택지로 이동시킨다.
				break;
			case DOWN:	//아래쪽 화살표 값을 받았다면
				if (y >= 4) break;	//4이상의 경우 이미 마지막 선택지이므로 무시
				y += 2;	//다음 선택지로 이동
				break;
			default:	//다른 경우에는 무시
				break;
			}
		}
		if (input == SPACE) {	//스페이스바가 눌렸다면
			switch (y) {
			case 0:	//첫번째 선택지
				gamemanager->startgame(gamemanager);	//게임 시작
				break;
			case 2:	//두번째 선택지
				DrawQmain(gamemanager);	//큐엔에이
				break;
			case 4:	//세번째 선택지
				//게임 종료
				system("cls");
				GotoXY(14, 7);
				cout << "게임을 종료합니다...";
				Sleep(1000);
				delete(gamemanager);
				exit(1);
				break;
			default:	//이 경우에는 오류지만...
				GotoXY(13, 5);	//첫번째 선택지로 커서를 옮긴다
				break;
			}
		}
		if (input == ESC) {	//esc키 입력
			//게임 종료
			system("cls");
			GotoXY(14, 7);
			cout << "게임을 종료합니다...";
			Sleep(1000);
			delete(gamemanager);
			exit(1);
		}
		GotoXY(13, (y + 5));	//선택지는 x좌표가 13으로 변함 없지만 첫번째 선택지의 y좌표는 5이므로 y에 5를 더해 이동
	}
}

void DrawQmain(Deck* gamemanager) {
	system("cls");	//화면 지움
	int y = 0;
	int input = 0;
	GotoXY(2, 7);
	cout << "*~Q&A~*";
	GotoXY(13, 5);
	cout << ">단어장 변경 방법";
	GotoXY(13, 7);
	cout << ">게임 플레이 방법";
	GotoXY(13, 9);
	cout << ">조작키 종류";
	GotoXY(13, 5);
	while (1) {
		input = _getch();
		if (input == MAGIC_KEY) {
			switch (_getch()) {
			case UP:
				if (y <= 0) break;
				y -= 2;
				break;
			case DOWN:
				if (y >= 4) break;
				y += 2;
				break;
			default:
				break;
			}
		}
		if (input == SPACE) {
			switch (y) {
			case 0:
				howtowordlist(gamemanager);	//단어장 큐엔에이
				break;
			case 2:
				howtoplay(gamemanager);	//플레이 방법
				break;
			case 4:
				howtomove(gamemanager);	//조작법
				break;
			default: break;
			}
		}
		if (input == BACKSPACE) {
			drawconsolemain(gamemanager);
		}
		if (input == ESC) {
			system("cls");
			GotoXY(14, 7);
			cout << "게임을 종료합니다...";
			Sleep(1000);
			delete(gamemanager);
			exit(1);
		}
		GotoXY(13, (y + 5));
	}
}