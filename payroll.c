#include <stdio.h>

char prompt(void);


int main(void){
  int total_emps;
  int manager_emps;
  int hourly_emps;
  int commission_emps;
  int piece_emps;

  float total_wages;
  float manager_wages;
  float hourly_wages;
  float commission_wages;
  float piece_wages;

  char emp_type;
  int finish = 0;

  while (!finish) {
    emp_type = prompt();
    switch(emp_type) {
      case '1':
        printf("Manager");
        break;
      case '2':
        break;
      case '3':
        break;
      case '4':
        break;
        case 'Z':
          printf("You entered too many characters. Please only enter '1' for manager, '2' for hourly, '3' for commission, '4' for pieceworker, or 'Q' to quit and see totals.\n");
          break;
      case 'Q':
        finish = 1;
        break;
      default:
        printf("Unrecognised paycode '%c'. Please only enter '1' for manager, '2' for hourly, '3' for commission, '4' for pieceworker, or 'Q' to quit and see totals.\n", emp_type);
        break;
    }
  }

}

 char prompt(void) {
  char paycode[100];
  printf("Enter employee paycode (1,2,3,4,Q): ");
  scanf(" %s", &paycode[0]);
  if (paycode[1] != '\0'){
    return 'Z';
  }

  getchar();
  return paycode[0];
}
