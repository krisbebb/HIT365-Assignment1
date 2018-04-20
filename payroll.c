#include <stdio.h>

char prompt(void);
float calc_manager(void);
float calc_hourly(void);
float calc_commission(void);
float calc_pieceworker(void);


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
  float temp_wage = 0;

  char emp_type;
  int finish = 0;

  while (!finish) {
    emp_type = prompt();
    switch(emp_type) {
      case '1':
        temp_wage = calc_manager();
        manager_wages += temp_wage;
        total_wages += temp_wage;
        manager_emps++;
        total_emps++;
        break;
      case '2':
        temp_wage = calc_hourly();
        hourly_wages += temp_wage;
        total_wages += temp_wage;
        hourly_emps++;
        total_emps++;
        break;
      case '3':
        temp_wage = calc_commission();
        commission_wages += temp_wage;
        total_wages += temp_wage;
        commission_emps++;
        total_emps++;
        break;
      case '4':
        temp_wage = calc_pieceworker();
        piece_wages += temp_wage;
        total_wages += temp_wage;
        piece_emps++;
        total_emps++;
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

float calc_manager(void){
  float wage;
  printf("Enter weekly salary for manager: ");
  scanf("%f", &wage);
  printf("Manager salary of $%.2f\n", wage);
  return wage;
}
float calc_hourly(void){

  int hours = 0;
  int overtime_hours = 0;
  float fixed_rate = 0;
  float overtime_rate = 0;
  float fixed_total = 0;
  float overtime_total = 0;
  float total = 0;

  printf("Enter the hourly wage for the employee: ");
  scanf("%f", &fixed_rate);
  printf("Enter hours worked for hourly employee: ");
  scanf("%d", &hours);
  if (hours<=40) {
    fixed_total = hours * fixed_rate;
    total = fixed_total;
  } else {
    fixed_total = (40 * fixed_rate);
    overtime_rate = 1.5 * fixed_rate;
    overtime_hours = hours - 40;
    overtime_total = overtime_rate * overtime_hours;

    total = fixed_total + overtime_total;
  }
  printf("Wages are $%.2f ($%.2f regular and $%.2f overtime)\n", total, fixed_total, overtime_total);
  return total;

}
float calc_commission(void){
  float base = 250;
  float val_A = 0;
  float val_B = 0;
  float val_C = 0;
  float rate_A = .057;
  float rate_B = .064;
  float rate_C = .072;
  float wage_A = 0;
  float wage_B = 0;
  float wage_C = 0;
  float comm_total = 0;
  float total = 0;


  printf("Enter the sales value of Item A: ");
  scanf("%f", &val_A);
  printf("Enter the sales value of Item B: ");
  scanf("%f", &val_B);
  printf("Enter the sales value of Item C: ");
  scanf("%f", &val_C);
  wage_A = val_A * rate_A;
  wage_B = val_B * rate_B;
  wage_C = val_C * rate_C;

  comm_total = wage_A + wage_B + wage_C;
  total = base + comm_total;
  printf("Commission wage is $%.2f ($%.2f base + $%.2f commissions ($%.2f item A, $%.2f item B, $%.2f item C))\n", total, base, comm_total, wage_A, wage_B, wage_C );

  return total;
}
float calc_pieceworker(void){
  return 0;
}
