#include <stdio.h>


int year_scan()
{
    int year;
    printf("Write a year: ");
  scanf("%d", &year);
  return year;
}

int month_scan()
{
    int month;
    printf("Write a number of a month: ");
    scanf("%d", &month);
    return month;
}
void first_day_calc(int year, int month, int *fday, int *leap) {
    int key[] = {1,4,4,0,2,5,0,3,6,1,4,6};
    int code[] = {4,2,0,6};

    int century = year / 100;
    int cent_code;

    if (century == 17){
        cent_code = code[0];
    } else if (century == 18){
        cent_code = code[1];
    } else if (century == 19){
        cent_code = code[2];
    } else if (century == 20){
        cent_code = code[3];
    } else {
        int year_cp = year;
        while (year_cp < 1700){
            year_cp += 400;
        }
        while (year_cp > 2100){
            year_cp -= 400;
        }
        return first_day_calc(year_cp, month, fday, leap);
    }

    int leap_year = 0;
    if (year % 400 == 0){
        leap_year = 1;
    } else if (year % 100 == 0){
        leap_year = 0;
    } else if (year % 4 == 0) {
        leap_year = 1;
    } else {
        leap_year = 0;
    }

    int last_digits = year % 100;

    int div4 = (last_digits / 4) + 1;

    int key_val = div4 + key[month - 1];

    int add_ccode = key_val + cent_code;

    int add_two = add_ccode + last_digits;

    if (leap_year == 1 && (month == 1 || month == 2)) {
        add_two -= 1;
    }

    *fday = add_two % 7;
    *leap = leap_year;

}
int pattern_interpeter(int fday, int month, int year, int leap)
{
    char* monthname[] = {"January", "February", "March", "April",
    "May", "June", "July", "August", "September", "October",
    "November", "December"};

    char* weekday[] = {"Saturday", "Sunday", "Monday", "Tuesday",
    "Wednesday", "Thursday", "Friday"};
    int daylist[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int counter = 0;
    int empty_counter = 0;
    if (leap == 1){
        daylist[1] = 29;
    }

    if (fday == 0) {
        fday = 5;
    } else if (fday == 1) {
        fday = 6;
    } else if (fday == 2) {
        fday = 0;
    } else if (fday == 3) {
        fday = 1;
    } else if (fday == 4) {
        fday = 2;
    } else if (fday == 5) {
        fday = 3;
    } else if (fday == 6) {
        fday = 4;
    }

    printf("\n        %d", year);
    printf("\n -------%s------", monthname[month-1]);
    printf("\n  M  T  W  T  F  S  S\n");

    for (empty_counter = 0; empty_counter < fday; empty_counter++) {
        printf("   ");
    }

    for (int day = 1; day <= daylist[month - 1]; day++) {
        if (empty_counter == 7) {
            printf("\n");
            empty_counter = 0;
        }

        printf("%3d", day);
        empty_counter++;
    }


    if (empty_counter != 0) {
        printf("\n");
    }

    return 0;
}




int main()
{
    int year = year_scan();
    int month = month_scan();
    if (month > 12| month < 1){
        printf("Wrong input.\nWrite number of a month from 1 to 12.");
        return 0;
    } else{
    int fday, leap;
    first_day_calc(year, month, &fday, &leap);
    pattern_interpeter(fday, month, year, leap);
    }
    return 0;
}