#include<stdio.h>
#include<ctype.h>
#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value){
    if (top== SIZE-1){
        printf("stack overflow! Can't push anymore until you pop!");
    }else{
        top++;
        stack[top]=value;
        printf("the element %d is pushed into the stack \n", value);
    }
}
void pop(){
    if(top==-1){
        printf("stack underflow condition!");
    }else{
        printf("%d popped from stack \n",stack[top]);
        top--;
    }
}
void peek(){
    if(top==-1){
        printf("stack underflow condition!");
    }else{
        printf("the peek element is: %d",stack[top]);
    }
}
void display(){
    if(top==-1){
        printf("there is no element to display as the stack is empty");
    }else{
        printf("elements present in stack are :");
        for(int i=top; i>=0;i--){
            printf("%d ",stack[i]);

        }
}


}

int main(){
    while(1){
    printf("\n welcome to stack implementing arrays!\n");
    printf("------ MAIN-MENU ------\n");
    printf("1) PUSH\n");
    printf("2) POP\n");
    printf("3) PEEK\n");
    printf("4) DISPLAY\n");
    printf("5) to exit\n");
    int choice,value;
    printf("enter the operation u want to choose:");
    scanf("%d",&choice);
       switch(choice){
        case 1:
           printf("enter the value you want to push:");
           scanf("%d",&value);
           push(value);
           break;
        case 2:
           pop();
           break;
        case 3:
           peek();
           break;
        case 4:
           display();
           break;
        case 5:
         printf("---exit---");
         break;
       default:
         printf("invalid input !");
         break;
       }
       if(choice==5){
        break;
       }

    }
}
