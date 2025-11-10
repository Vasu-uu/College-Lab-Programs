#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char ch) {
   if (top >= (100 - 1)) {
      printf("Stack overflow\n");
      exit(1);
   }
   stack[++top] = ch;
}

char pop() {
   if (top == -1) {
      printf("Stack underflow\n");
      exit(1);
   }
   return stack[top--];
}

int precedence(char ch) {
   if (ch == '(')
      return 0;
   if (ch == '+' || ch == '-')
      return 1;
   if (ch == '*' || ch == '/')
      return 2;
   return 0;
}

float evaluate(char ch, float a, float b) {
   switch (ch) {
      case '+': return b + a;
      case '-': return b - a;
      case '*': return b * a;
      case '/': return b / a;
      default: return 0;
   }
}

int main() {
   char infix[100], t;
   printf("Enter the expression: ");
   scanf("%s", infix);

   char *exp = infix;
   char postfix[100];
   int index = 0;
   printf("Postfix: ");

   while (*exp != '\0') {
      if (isalnum(*exp)) {
         postfix[index++] = *exp;
      } else if (*exp == '(') {
         push(*exp);
      } else if (*exp == ')') {
         while ((t = pop()) != '(') {
            postfix[index++] = t;
         }
      } else {
         while (top != -1 && precedence(stack[top]) >= precedence(*exp)) {
            postfix[index++] = pop();
         }
         push(*exp);
      }
      exp++;
   }

   while (top != -1) {
      postfix[index++] = pop();
   }
   postfix[index] = '\0';

   printf("%s\n", postfix);

   float values[52];
   for (int i = 0; i < strlen(postfix); i++) {
      if (isalpha(postfix[i])) {
         printf("Enter value of %c: ", postfix[i]);
         scanf("%f", &values[postfix[i] - (islower(postfix[i]) ? 'a' : 'A' - 26)]);
      }
   }

   float result_stack[100];
   int result_top = -1;
   for (int i = 0; i < strlen(postfix); i++) {
      if (isalpha(postfix[i])) {
         result_stack[++result_top] = values[postfix[i] - (islower(postfix[i]) ? 'a' : 'A' - 26)];
      } else {
         float op1 = result_stack[result_top--];
         float op2 = result_stack[result_top--];
         result_stack[++result_top] = evaluate(postfix[i], op1, op2);
      }
   }

   printf("Result: %f\n", result_stack[result_top]);

   return 0;
}