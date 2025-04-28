#pragma warning(disable:4996)
#include <stdio.h>

int main4()
{
	/*레포트 1차 과제 개인별 급여 관리 시스템
	입력자료 사원번호 두 자리수 정수,나이,부서코드 문자 1개,근무시간,부양 가족수,신용카드 사용액,체크카드 사용액
	출력자료 사원번호 부서명 근무시간:시간,분으로 출력 초과근무시간:시간,분으로 출력 세전급여액,세후급여액 세금,환금액
	부서코드 A=인사,B=세무,C=경영,D=생산*/

	/*04.27 중간 점검
	입력값 완료, 초가 있을경우 분으로 올림 완료, 부서코드 받고 부서명으로 출력하기(switch문)으로 완료
	에러사항 초과근무시간을 출력해야함. 하지만 7시까지가 최대인 나이대에 7시1분으로 뜨고 초과근무시간 출력 안됨.
	에러해결 - sec>=1에만 전부 써서 else가 없었음 esle추가후 오류 해결
	04.28 중간점검 초과근무시간 완료 다음은 이제 부서코드를 입력받고 부서명 출력받기 완료
	기본급여 시간당 1.2만원,초과근무수당 분당 100원,세전급여액,세후급여액,세금,환금액(소수첫째자리 반올림)
	기본급여,초과급여,부양가족수당 환금액 2천원씩 추가,세후급여,세금까지 완료
	--------------------------------------------
	기본급여,초과급여,총급여까지 본문에 추가완료.*/

	int staffnum;//사번
	int age;//나이
	char department;//부서코드
	int Workhour;//근무시간(초)
	int hour;//시간
	int min;//분
	int sec;//초
	int sec2;//시간분출력을 위한 중간변수
	int overtime;//초과근무계산에 사용할 초
	int overhour;//초과근무 시
	int overmin;//초과근무 분
	int oversec;//초과근무 초
	int oversec2;//초과시분 출력을 위한 중간변수
	int family;//부양가족수
	int card;//신용카드사용액
	int checkcard;//체크카드 사용액
	int refund;//환금액
	int money;//기본급여
	int overmoney;//초과급여
	int allmoney;//총급여



	int maxWorkhour; //최대인정 근무시간 
	int tax; //세금의 대한 변수가 없어서 작성

	printf("사원번호를 입력하세요.(두자리 정수)");
	scanf("%d", &staffnum);
	printf("나이를 입력하세요.");
	scanf("%d", &age);
	printf("부서코드를 입력하세요.");
	scanf(" %c", &department);
	printf("근무시간을 입력하세요.(초단위)");
	scanf("%d", &Workhour);
	printf("부양 가족수를 입력하세요.");
	scanf("%d", &family);
	printf("신용카드 사용액을 입력하세요.");
	scanf("%d", &card);
	printf("체크카드 사용액을 입력하세요.");
	scanf("%d", &checkcard);



	/* 근무시간 계산 */
	hour = Workhour / 3600; /*초를 나눠서 시간으로 출력*/
	sec2 = Workhour % 3600;
	min = sec2 / 60;
	sec = sec2 % 60;
	/* 이 부분이 올림 처리 */
	if (sec >= 1) {
		min += 1;

	}

	/* 최대인정 근무시간 조건 */
	// maxWorkhour을 쓴 이유는 처리조건에서 몇세~ 몇세 사이에 인정되는 근무시간이 조건으로 나와있는데 이거를 저장할 변수가 없어서 
	{
		if (age < 18) {
			printf("고용불가\n");
			return 0;
		}
		else if (age >= 18 && age < 25) {
			maxWorkhour = 7;
		}
		else if (age >= 25 && age < 55) {
			maxWorkhour = 9;
		}
		else if (age >= 55 && age < 65) {
			maxWorkhour = 5;
		}
		else {
			maxWorkhour = 3;
		}

	}

	/* 초과 근무 시간 계산 */
	// 출력부분에서 ( 근무시간 ) 근무자 / ( 초과시간 ) 근무자 로 나오기 때문
	{
		overtime = Workhour - (maxWorkhour * 3600);

		if (overtime <= 0) {
			overtime = 0;
		}

		else if (overtime > 0) {

			overhour = overtime / 3600;
			oversec2 = overtime % 3600;
			overmin = oversec2 / 60;
			oversec = oversec2 % 60;

		}


	}


	/* 급여계산 */ //if문으로 maxWorkhour의 대한 문제 해결 확인해보기
	{
		money = maxWorkhour * 12000;
		overmoney = (overtime / 60) * 100;
		allmoney = money + overmoney;
	}


	/* 환급액 계산 */
	{
		refund = family * 2000;

		if (card > allmoney * 0.30) {
			refund += card * 0.10;
		}

		if (checkcard > allmoney * 0.30) {
			refund += checkcard * 0.20;
		}

	}

	/* 세율 계산 */
	{
		if (allmoney < 30000) {
			tax = allmoney * 0.05;
		}
		else if (allmoney < 70000) {
			tax = allmoney * 0.10;
		}
		else {
			tax = allmoney * 0.15;
		}

	}




	// 최종 급여 
	int realmoney = allmoney - tax + refund;










	printf("%d번 사원 급여정보입니다.\n", staffnum);  // 사원번호 출력
	printf("%d시간 %d분 %d초 근무자로 %d시간 %d분 %d초 초과근무한 %c 직원입니다.\n", hour, min, sec, overhour, overmin, oversec, department);
	printf("세전급여액은 %d원, 세금 %d원, 환급금 %d원 으로 세후급여액은 %d원입니다.\n", realmoney + tax - refund, tax, refund, realmoney);

	return 0;



}



// 분이랑 , if문으로 maxWorkhour , 급여계산 hour , 초과근무일 때 maxWorkhour

















//근무시간 , 급여계산 ,환급액 계산,  세울계산 , 최종급여 



