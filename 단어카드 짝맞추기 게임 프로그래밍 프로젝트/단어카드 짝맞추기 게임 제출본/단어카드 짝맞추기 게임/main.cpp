#include "matchingcard.h"
#include "carddeck.h"
#include "consolemain.h"

int main()
{
    SetConsoleView();   //콘솔 설정
    Deck* pGameMgr = new Deck();    //게임 플레이용 클래스 동적 할당
    drawconsolemain(pGameMgr);  //메인 화면으로 프로그램 시작
    delete(pGameMgr);   //종료 전 동적 할당 해제
    return 0;
}