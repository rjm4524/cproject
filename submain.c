#pragma warning(disable:4996)
#include <stdio.h>

int main5()
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

	printf("사원번호를 입력하세요.(두자리 정수)");
	scanf("%d", &staffnum);
	if (staffnum  >=1 && staffnum <= 99) {
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
	}
	else {
		printf("사원번호를 다시 입력해주세요.");
		return 0;
	}
	

	hour = Workhour / 3600; /*초를 나눠서 시간으로 출력*/
	sec2 = Workhour % 3600;
	min = sec2 / 60;
	sec = sec2 % 60;

	if (department == 'A') {
		refund = (family * 2000);
		if (sec >= 1) {//초 분으로 올림 if
			min += 1;
			if (age < 18) {
				printf("채용이 불가능한 나이입니다. 나이를 다시입력해주세요.");
			}
			else if (age >= 18 && age < 25) {
				money = hour * 12000;//기본급여는 시간 * 12000원
				allmoney = money;

				if (Workhour > (3600 * 7)||money > (12000 * 7)) {
					overtime = Workhour - (3600 * 7);
					overhour = overtime / 3600;/*초과근무의시간*/
					oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
					overmin = oversec2 / 60;/*초과근무의분*/
					oversec = oversec2 % 60;/*초과근무의초*/
					money = 72000;//최대로 받는 기본급여
					if (oversec >= 1) {
						overmin += 1;
						overmoney = (overtime / 60)*100 + (overmin * 100); //초과급여 = 초과근무 시 + 초과근무 분 따로 계산후 합치기
						allmoney = overmoney + money;
						
					}

					else {
						overmoney = (overtime / 60) * 100 + (overmin * 100); //초과급여 = 초과근무 시 + 초과근무 분 따로 계산후 합치기
						
					}

				}
				else {
					printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시 %d분\n초과근무 시간이 없습니다.\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
						staffnum, age, hour, min, family, card, checkcard);
				}
			}
			else if (age >= 25 && age < 55) {
				if (Workhour > (3600 * 9)) {
					overtime = Workhour - (3600 * 9);
					overhour = overtime / 3600;/*초과근무의시간*/
					oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
					overmin = oversec2 / 60;/*초과근무의분*/
					oversec = oversec2 % 60;/*초과근무의초*/
					if (oversec >= 1) {
						overmin += 1;
						
					}
					else {
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
				}
				else {
					printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시 %d분\n초과근무 시간이 없습니다.\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
						staffnum, age, hour, min, family, card, checkcard);
				}
			}
			else if (age >= 55 && age < 65) {
				if (Workhour > (3600 * 5)) {
					overtime = Workhour - (3600 * 5);
					overhour = overtime / 3600;/*초과근무의시간*/
					oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
					overmin = oversec2 / 60;/*초과근무의분*/
					oversec = oversec2 % 60;/*초과근무의초*/
					if (oversec >= 1) {
						overmin += 1;
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
					else {
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
				}
				else {
					printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시 %d분\n초과근무 시간이 없습니다.\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
						staffnum, age, hour, min, family, card, checkcard);
				}
			}
			else {
				if (Workhour > (3600 * 3)) {
					overtime = Workhour - (3600 * 3);
					overhour = overtime / 3600;/*초과근무의시간*/
					oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
					overmin = oversec2 / 60;/*초과근무의분*/
					oversec = oversec2 % 60;/*초과근무의초*/
					if (oversec >= 1) {
						overmin += 1;
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
					else {
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
				}
				else {
					printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시 %d분\n초과근무 시간이 없습니다.\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
						staffnum, age, hour, min, family, card, checkcard);
				}

			}

		}//초 분으로 올림 if


		else {//초 분으로 올림의 else
			if (age < 18) {
				printf("채용이 불가능한 나이입니다. 나이를 다시입력해주세요.");
			}
			else if (age >= 18 && age < 25) {

				if (Workhour > (3600 * 7)) {
					overtime = Workhour - (3600 * 7);
					overhour = overtime / 3600;/*초과근무의시간*/
					oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
					overmin = oversec2 / 60;/*초과근무의분*/
					oversec = oversec2 % 60;/*초과근무의초*/
					if (oversec >= 1) {
						overmin += 1;
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
					else {
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}

				}
				else {
					printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시 %d분\n초과근무 시간이 없습니다.\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
						staffnum, age, hour, min, family, card, checkcard);
				}
			}
			else if (age >= 25 && age < 55) {
				if (Workhour > (3600 * 9)) {
					overtime = Workhour - (3600 * 9);
					overhour = overtime / 3600;/*초과근무의시간*/
					oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
					overmin = oversec2 / 60;/*초과근무의분*/
					oversec = oversec2 % 60;/*초과근무의초*/
					if (oversec >= 1) {
						overmin += 1;
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
					else {
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
				}
				else {
					printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시 %d분\n초과근무 시간이 없습니다.\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
						staffnum, age, hour, min, family, card, checkcard);
				}
			}
			else if (age >= 55 && age < 65) {
				if (Workhour > (3600 * 5)) {
					overtime = Workhour - (3600 * 5);
					overhour = overtime / 3600;/*초과근무의시간*/
					oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
					overmin = oversec2 / 60;/*초과근무의분*/
					oversec = oversec2 % 60;/*초과근무의초*/
					if (oversec >= 1) {
						overmin += 1;
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
					else {
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
				}
				else {
					printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시 %d분\n초과근무 시간이 없습니다.\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
						staffnum, age, hour, min, family, card, checkcard);
				}
			}
			else {
				if (Workhour > (3600 * 3)) {
					overtime = Workhour - (3600 * 3);
					overhour = overtime / 3600;/*초과근무의시간*/
					oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
					overmin = oversec2 / 60;/*초과근무의분*/
					oversec = oversec2 % 60;/*초과근무의초*/
					if (oversec >= 1) {
						overmin += 1;
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
					else {
						printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시%d분\n초과근무 시간:%d시 %d분\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
							staffnum, age, hour, min, overhour, overmin, family, card, checkcard);
					}
				}
				else {
					printf("사원번호:%d번\n나이:%d세\n부서명:인사팀%\n근무시간:%d시 %d분\n초과근무 시간이 없습니다.\n부양가족수:%d명\n신용카드 사용액:%d원\n체크카드 사용액:%d원\n",
						staffnum, age, hour, min, family, card, checkcard);
				}

			}

		}//초분으로 올림의 else 
	}//부서코드 A일때의 if문 
	

	else {
		printf("부서명을 찾을수없습니다. 부서명을 다시 입력해주세요.");
	}

	return 0;

	}//초분으로 올림의 else 

	
