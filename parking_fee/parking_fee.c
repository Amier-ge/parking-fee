#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

void enter_car(char *carNum);
void input_carNum(char *user_carNum);
void check_fee(char *carNum, char *user_carNum);

int main() {

	char carNum[1000] = {0}, user_carNum[9] = {0};
	int car_time;

	enter_car(carNum);
	input_carNum(user_carNum);
	check_fee(carNum, user_carNum);

	return 0;
}

void enter_car(char *carNum){

	char input_carNum[9];
	char yn;
	int index = 0;

	while(1){

		printf("Input car number(ex: 12³ª3456) : ");
		scanf("%s", input_carNum);
		strcat(carNum, input_carNum);

		printf("Do you want to enter more?\n");
		printf("Y/N : ");
		scanf(" %c", &yn);

		if((yn == 'n') || (yn == 'N')) break;
	}
}

void input_carNum(char *user_carNum){

	printf("Input your car number : ");
	scanf("%s", user_carNum);

}

void check_fee(char *carNum, char *user_carNum){

	char comp_car[9] = {0};
	int user_time, fee, index = 0;
	int i, j = 0;

	srand( (unsigned int)time(0) );

	user_time = (rand() % 180) + 1; // 1~180 Random
	
	if(user_time <= 30) fee = 0;
	else fee = ( (user_time-30) / 10 ) * 500; // 500won per 10min, until 30min is free.

	while(1){
		for(i = index ; i < index + 8 ; i++){

			*(comp_car + j) = *(carNum + i);
			j++;
		}
		*(comp_car + j) = '\0';

		if( strcmp(user_carNum, comp_car) == 0 ){

			if(fee != 0) printf("\nCar : %s || Time : %dmin || Fee : %dwon\n", user_carNum,user_time, fee);
			else printf("\nCar : %s || Time : %dmin || Fee : free\n", user_carNum, user_time, fee);
			break;
		}
		else if( (strcmp(user_carNum, comp_car) != 0) && *(carNum + i) != '\0'){
			j = 0;
			index += 8;
		}
		else if( *(carNum + i) != '\0') printf("Your car don't exist\n");
	}
}