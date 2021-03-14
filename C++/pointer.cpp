/*A pointer in C is a way to share a memory address among different contexts (primarily functions). They are primarily used whenever a function needs to modify the content of a variable, of which it doesn't have ownership.

In order to access the memory address of a variable,val we need to prepend it with "&" sign. E.g., &val returns the memory address of "val"


Input Format

Input will contain two integers, "a" and "b", separated by a newline.

Output Format

You have to print the updated value of "a" and "b", on two different lines*/



#include <stdio.h>

void update(int *a,int *b) {
    // Complete this function
    int aa = *a;
    *a = *a+*b;
    *b = aa-*b;
    if(*b < 0)*b *= -1;
}
int main() {

    int a, b;
    int *pa = &a, *pb = &b;
    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);
    return 0;
}
