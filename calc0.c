/*
TODO
同じ処理を関数にまとめる
符号反転を実装する
オーバーフローなどの処理を実装する
*/

#include<stdio.h>
#include<math.h>

#define DIGIT 10

int calc(int num, int acc, char last_op);

int main(int argc, char *argv[]) {
  char *strp = argv[1]; // 入力される文字列を格納
  int num;
  int acc = 0;
  char last_op = '+';
  int flag = 1;
  int memory;
  
  // printf("str = %s\n", strp);
  while(*strp != '\0') {
    printf("operand = %c\n", *strp);
    switch (*strp) {
      case '+':
        acc = calc(num, acc, last_op);
        last_op = '+';
        flag = 1;
        strp++;
        break;
      case '-':
        acc = calc(num, acc, last_op);
        last_op = '-';
        flag = 1;
        strp++;
        break;
      case '*':
        acc = calc(num, acc, last_op);
        last_op = '*';
        flag = 1;    
        strp++;
        break;
      case '/':
        acc = calc(num, acc, last_op);
        last_op = '/';
        flag = 1;
        strp++;
        break;
      case '=':
        acc = calc(num, acc, last_op);
        strp++;
        break;
      case 'S':
        num *= -1;
        strp++;
        break;
      case 'C':
        acc = calc(num, acc, last_op); 
        memory = 0;
        flag = 1;
        strp++;
        break;
      case 'R':
        acc = calc(num, acc, last_op); 
        acc = memory;
        flag = 1;
        strp++;
        break;
      case 'P':
        acc = calc(num, acc, last_op);
        memory += acc;
        printf("memory = %d\n", memory);
        acc = 0;
        num = 0;
        last_op = '+';
        flag = 1;
        strp++;
        break;
      case 'M':
        acc = calc(num, acc, last_op);
        memory -= acc;
        printf("memory = %d\n", memory);
        acc = 0;
        num = 0;
        last_op = '+';
        flag = 1;
        strp++;
        break;
      default:
        if(flag == 1) {
          num = *strp - '0';
          printf("num = %d\n", num);
          flag = 0;
          strp++;
        } else {
          if(num >= 0) {
            num = num * DIGIT + (*strp - '0');
          } else {
            num = num * DIGIT - (*strp - '0');
          }
          printf("num = %d\n", num);
          strp++;
        }
        break;
    }
  }
  printf("result = %d\n", acc);
  return 0;
}

int calc(int num, int acc, char last_op) {
  switch (last_op) {
    case '+':
      acc += num;
      break;
    case '-':
      acc -= num;
      break;
    case '*':
      acc *= num;
      break;
    case '/':
      acc /= num;
      break;
  }
  printf("acc = %d\n", acc);
  return acc;
}