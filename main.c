#include <stdio.h>
#pragma warning(disable:4996)

int main() {
	int staffnum;//사번
	int age;//나이
	char department;//부서코드
	int Workhour;//근무시간(초)
	int maxWorkhour;
	int hour;//시간
	int min;//분
	int sec;//초
	int sec2;//시간분출력을 위한 중간변수
	int overtime;//초과근무계산에 사용할 초
	int overhour=0;//초과근무 시
	int overmin=0;//초과근무 분
	int oversec=0;//초과근무 초
	int oversec2;//초과시분 출력을 위한 중간변수
	int family;//부양가족수
	int card;//신용카드사용액
	int checkcard;//체크카드 사용액
	int refund;//환금액
	int duty;//세금
	int money = 0;//기본급여
	int overmoney = 0;//초과급여
	int allmoney = 0;//세전급여
	int finalmoney; //세후급여

	
	printf("사원번호를 입력하세요.(두자리 정수)");
	scanf("%d", &staffnum);

	if (staffnum >= 1 && staffnum <= 99);

	else {
		printf("사원번호를 다시 입력해주세요.");
		return 0;
	}
	/*----------------------------*/
	printf("나이를 입력하세요.");
	scanf("%d", &age);

	if (age >= 1 && age <= 99);

	else {
		printf("나이를 다시입력해주세요.");
		return 0;
	}
	/*----------------------------------*/

	printf("부서코드를 입력하세요.");
	scanf(" %c", &department);

	/*----------------------------------*/
	printf("근무시간을 입력하세요.(초단위)");
	scanf("%d", &Workhour);
	/*----------------------------------*/
	printf("부양 가족수를 입력하세요.");
	scanf("%d", &family);
	/*----------------------------------*/
	printf("신용카드 사용액을 입력하세요.");
	scanf("%d", &card);
	/*----------------------------------*/
	printf("체크카드 사용액을 입력하세요.");
	scanf("%d", &checkcard);
	/*----------------------------------*/

	hour = Workhour / 3600; /*초를 나눠서 시간으로 출력*/
	sec2 = Workhour % 3600;
	min = sec2 / 60;
	sec = sec2 % 60;

	/*초에서 분 올림*/
	if (sec >= 1) {
		min += 1;
	}

	/*나이별 최대 근무시간*/
	if (age < 18) {

		printf("근무가능한 나이가 아닙니다.");
		return 0;
	}

	else if (age >= 18 && age < 25) maxWorkhour = 7;

	else if (age >= 25 && age < 55) maxWorkhour = 9;

	else if (age >= 55 && age < 65) maxWorkhour = 5;

	else maxWorkhour = 3;

	/*---------------------부서코드------------------------*/
	if (department == 'A' || department == 'a') {
		printf("부서명:인사팀\n");
	}
	else if (department == 'B' || department == 'b') {
		printf("부서명:세무팀\n");
	}
	else if (department == 'C' || department == 'c') {
		printf("부서명:경영팀\n");
	}
	else if (department == 'D' || department == 'd') {
		printf("부서명:생산팀\n");
	}
	else {
		printf("부서코드을 다시 입력해주세요. 입력한 부서코드 :%c", staffnum);
		return 0;
	}
	/*---------------------------------------------------*/


	//초과근무 시간

	overtime = Workhour - (3600 * maxWorkhour);

	if (overtime > 3600 * maxWorkhour) {
		overhour = overtime / 3600;/*초과근무의시간*/
		oversec2 = overtime % 3600;/*초과근무 분초를 위한 중간변수*/
		overmin = oversec2 / 60;/*초과근무의분*/
		oversec = oversec2 % 60;/*초과근무의초*/
		if (oversec >= 1) {
			overmin += 1; //초과근무 초를 올림처리하는 식
		}
	
	}
	else if(overtime <= 0){
	overhour, overmin = 0;
	}
	

	//급여계산 
	money = hour * 12000;
	
	if (overtime >= 1) {
		money = maxWorkhour * 12000;//초과근무가 있으면 최대근무시간은 채운거랑 같음
		overmoney = (overtime / 60) * 100;//초과근무 급여계산
		allmoney = money + overmoney;//기본급여+초과근무급여 합
	}

	//1초를 분으로 환산하고 100원을 급여에 추가하는 식
	if (oversec >= 1) {
		overmoney += 100;
	}

	//환급액계산

	refund = family * 2000;
	if (allmoney * 0.3 < card) refund += (card * 0.1); //신용카드 환급

	if (allmoney * 0.3 < checkcard) refund += (checkcard * 0.2);//체크카드 환급

	//소득액에 따른 세율
	if (allmoney < 30000) duty = allmoney * 0.05;

	else if (allmoney >= 30000 && allmoney < 70000) duty = allmoney * 0.1;

	else duty = allmoney * 0.15;
	//세후계산
	finalmoney = allmoney - duty + refund;

	printf("사원번호:%d\n나이:%d\n근무시간:%d시%d분\n초과근무시간:%d시%d분\n기본급여:%d\n초과근무수당:%d\n세전급여:%d\n",staffnum,age,hour,min,overhour,overmin,money,overmoney,allmoney);
	printf("환금액:%d\n세금:%d\n세후급여:%d\n",refund,duty,finalmoney);

	return 0;
}