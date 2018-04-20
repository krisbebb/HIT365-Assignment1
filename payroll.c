#include <stdio.h>

char prompt(void);


int main(void){
  int total_emps = 0;
  int manager_emps = 0;
  int hourly_emps = 0;
  int commission_emps = 0;
  int piece_emps= 0;

  float total_wages = 0;
  float manager_wages = 0;
  float hourly_wages = 0;
  float commission_wages = 0;
  float piece_wages = 0;

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
    } // end switch
  } // end while
  printf("Manager: Employees: %d  Total wages:  $%.2f\nHourly: Employees: %d  Total wages:  $%.2f\nCommission: Employees: %d  Total wages:  $%.2f\nPieceworker: Employees: %d  Total wages:  $%.2f\nNet Total: Employees: %d  Total wages:  $%.2f\n", manager_emps, manager_wages, hourly_emps, hourly_wages, commission_emps, commission_wages, piece_emps, piece_wages, total_emps, total_wages);
} // end main

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
