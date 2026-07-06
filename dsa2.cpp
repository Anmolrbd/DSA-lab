#include<iostream>
#include<conio.h>
using namespace std;

int stack_top = -1;
int arr_bottom = -1;

int precedence(char op)
{
    switch(op)
    {
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

// Reverse the expression
void reverse(char arr[], int n)
{
    int i = 0;
    int j = n - 1;

    while(i < j)
    {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;

        i++;
        j--;
    }
}

// Swap ( with )
void swapBracket(char arr[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == '(')
        {
            arr[i] = ')';
        }

        else if(arr[i] == ')')
        {
            arr[i] = '(';
        }
    }
}

// Convert reversed infix to postfix
void postfix(char ch, char* stack, char* newarr)
{
    // Operand
    if((ch >= 'A' && ch <= 'Z') ||
       (ch >= 'a' && ch <= 'z') ||
       (ch >= '0' && ch <= '9'))
    {
        arr_bottom++;
        newarr[arr_bottom] = ch;
    }

    // Left bracket
    else if(ch == '(')
    {
        stack_top++;
        stack[stack_top] = ch;
    }

    // Right bracket
    else if(ch == ')')
    {
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

    // Operator
    else
    {
        while(stack_top != -1 &&
              stack[stack_top] != '(' &&
              precedence(stack[stack_top]) > precedence(ch))
        {
            arr_bottom++;
            newarr[arr_bottom] = stack[stack_top];
            stack_top--;
        }

        stack_top++;
        stack[stack_top] = ch;
    }
}
int main()
{
    int n;

    cout << "Enter the size of expression: ";
    cin >> n;

    char* arr = new char[n + 1];
    char* stack = new char[n];
    char* newarr = new char[n + 1];

    cout << "Enter expression: ";
    cin >> arr;

    // Step 1 : Reverse infix
    reverse(arr, n);

    // Step 2 : Swap brackets
    swapBracket(arr, n);

    // Step 3 : Convert to postfix
    for(int i = 0; i < n; i++)
    {
        postfix(arr[i], stack, newarr);
    }

    // Step 4 : Pop remaining operators
    while(stack_top != -1)
    {
        arr_bottom++;
        newarr[arr_bottom] = stack[stack_top];
        stack_top--;
    }

    newarr[arr_bottom + 1] = '\0';

    // Step 5 : Reverse postfix to get prefix
    reverse(newarr, arr_bottom + 1);

    cout << "Prefix Expression: " << newarr << endl;

    delete[] arr;
    delete[] stack;
    delete[] newarr;

    getch();
    return 0;
}