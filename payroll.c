#include <stdio.h>

int prompt(void);

int main(void){
  int emp_type = prompt();
  switch(emp_type) {
    case 1:
      printf("Manager");
      break;
      
  }

}

int prompt(void) {
  int paycode;
  printf("Enter employee paycode (1,2,3,4,Q): ");
  scanf("%d", &paycode);
  return paycode;
}
