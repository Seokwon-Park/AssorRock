﻿// 018_Char.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

int main()
{
	// 다들 웃었는데.
	// 알고 봤더니 프로그래밍씬에서도 차라고 발음하는 사람도 있다.
	// 1바이트 문자형입니다.
	// 1바이트 문자형은 결국 => 개념적으로 본다면 1바이트 정수인 겁니다.
	char Ch = 'A';

	// 문자에 대해서 이해하고 있느냐?
	// 이론
	// 문자형에 대한 이론은 딱 1개이다.
	// 프로그래밍에서 문자는 무조건 매칭방식으로 표현된다.
	// 'A' 글자 A가 뭔지 모른다.
	// 기본 하드웨어 적으로 구성되어 있고.
	// 문자고 65면 화면 A모양을 그린다

	// 문자열 인코딩이라는 것을 이해해야 한다.
	// 인코딩은 매칭 방식이 너무 많다.
	// 이게 무슨말이냐?
	// A => 65
	// 어딘가에서는 A가 65가 아닐수 있다.
	// => 알파뱃은 모든 국가에서 동일하게 사용합니다.
	
	// 선생님이 한글 쓰지 말라고 했던 이유가 여기서 나오는데.
	// 1바이트로 한글 전체를 표현할수 있나요?

	// <= 이녀석은 
	// 문자의 집합
	
	// 멀티바이트
	'A'; // <= 문자
	"안녕하세요"; // <= 문자열

	// 와이드 바이트
	L'A'; // <= 문자
	L"안녕하세요"; // <= 문자열

	// 

	// 보통 
	// 'A' 1바이트고
	// 'AA' 2바이트
	// '가' 2
	// '＠' 2바이트로

	u8"안녕하세요"; // <= UTF-8 1~4


	// 문자 자체는 그냥 기본 문법이라
	// 그냥 알아야 하는 영역인데.
	
	// 문법은 숨쉬는 것과 같아. => 문법에 관련해서는 모든걸 그냥 당연히 다 알고 
	// 있어야 한다.
	
	// 기본기라고 부를만한것들이 있다.
	
	// 디버깅을 잘하느냐 <= 끈기와 인내
	// 디버깅은 무식해야할때도 있다.
	// 어떤 10만 개가 있다. 그 값이 일일이 하나씩 다 확인해야할때도 있다.
	// 90% <= 
	
	// 파일입출력 편집과 이론
	// <= 2%
	// 문자열 편집과 이론
	// <= 8%

}