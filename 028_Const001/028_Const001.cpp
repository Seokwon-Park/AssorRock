// 028_Const001.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

// const는 가 붙었다면 
// const가 사용되는곳으 오늘은 다 못보여드리지만
// const가 들어갔다면
// 특정 메모리 영역을 비트적 상수화 시켰다.
// 컴파일러부터 인식한다.
// C++ 이 상수화를 무시하는 문법이나

// 전역 const는 굉장히 많이 사용되는데.
// 전체 판수
// 기획자가 무조건 20번의 싸움은 있을것이다.
// 한번 상수면 영원히 상수지


// 플레이어가 치루는 총 전투 횟수
// 일반적인 값형 변수는 이렇게 사용한다.
const int FightCount = 20;

int main()
{
    // int Value = 20;
    // int Value0 = 0;
    // Value /= Value0;

    // 1. 변수의 자료형 앞에 const를 붙였을때
    //    Value의 메모리영역의 비트를 앞으로 바꿀수 없다.
    // const int FightCount = 20;
   
    // for (size_t i = 0; i < 20; i++)
    // 상수 코딩은 좋지 않습니다.

    // 프로그래밍의 기본은 변수기반 코딩을 해야한다.
    
    //if (20)
    //{
    //}

    //while (20)
    //{
    //}

    const int FightCount = 20;

    for (size_t i = 0; i < FightCount; i++)
    {

    }

    // 4바이트 정수
    int const Value = 0;
    // 100번지 104까지는 고칠수 없다.

    // 다 차이가 없다.
    // const int const Value = 0;
    // int const Value = 0;
    // const int Value = 0;
    // 다 똑같은 의미다.

    // 4바이트가 만들어 지겠구나
    // const를 보면 그 4바이트를 바꿀수 없겠구나.
    const int Value = 0;
    // Value = 20;

    // const를 *와 섞게되면
    // < * >
    // const int const* Value = 0;
    // int const* Value = 0;
    // const int* Value = 0;
    // 바꿀수 없는 int를 가리키는 *
    // 위쪽의 예제는 *

    // const * const

    // int* const ValuePtr = 0;
    // ValuePtr = nullptr;

    // 포인터는 2가지의 값을 가지고 있는 것과 같다.
    // 바꿀수 없는 int의 주소값
    // const int*
    //const int Value = 20;
    //const int* ValuePtr = &Value;
    //ValuePtr = nullptr;

    const int * const  ValuePtr = &Value;

    //const int* const * const * const * const * const ValuePtr = nullptr;
    
    // const int*;
    // const int* const * const;
    // const int* const * const * const;

    // 함수를 읽음에 있어서 굉장히 const가 
    // 함수의 대략적인 내용을 보고 알수가 있야 한다.


}


