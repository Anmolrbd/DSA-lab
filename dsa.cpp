
#include<iostream>
#include<conio.h>
using namespace std;

int stack_top = -1;
int arr_top = 0, arr_bottom = -1;

int precedence(char op)
{
    switch(op){
        case '^':
        return 3;

        case '*': 
        case '/':
        return 2;

        case '+':
        case '-':
        return 1;

        default:
        return 0;
    }
}
void postfix(char arr, int n, char* stack, char* newarr){
    if(n == 0){
        cout << "Empty!" << endl;
        return;
    }
    if(arr >= 'A' && arr <= 'Z' || arr >= 'a' && arr <= 'z' || arr >= '0' && arr <= '9'){
        arr_top = 0;
        arr_bottom++;
        newarr[arr_bottom] = arr;
    }
    else{
        if(arr == '(')
        {
            stack_top ++;
            stack[stack_top] = arr;
        }


        else if(arr == ')'){

        while(stack_top != -1 && stack[stack_top] != '(')
        {
            arr_bottom++;
            newarr[arr_bottom] = stack[stack_top];
            stack_top--;
        }

        if(stack_top != -1)
        {
            stack_top--;
        }
    }

        else
{
    while(stack_top != -1 &&
          stack[stack_top] != '(' &&
          precedence(stack[stack_top]) >= precedence(arr))
    {
        arr_bottom++;
        newarr[arr_bottom] = stack[stack_top];
        stack_top--;
    }

    stack_top++;
    stack[stack_top] = arr;
}   
            }
}

int main(){
    int n, length;
    cout << "Enter the size of the array: ";
    cin >> n;
    char* arr = new char[n + 1];
    cout << "Enter expression: ";
    cin >> arr; 
    char* newarr = new char[n + 1];
    char* stack = new char[n];
    for(int i = 0; i < n ; i ++){
        postfix(arr[i],n,stack,newarr);
    }
    while(stack_top != -1)
{
    arr_bottom++;
    newarr[arr_bottom] = stack[stack_top];
    stack_top--;
}
    newarr[arr_bottom + 1] = '\0';
    cout << newarr;
    delete[] newarr;
    delete[] stack;
    return 0;
}