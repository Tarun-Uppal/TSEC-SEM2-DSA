#include <stdio.h>

void pushs1(int s[], int *c1, int *c2, int num){
    if ((*c1) <= (*c2)){
        s[*c1] = num;
        (*c1)++;
    } else {
        printf("ERROR\n");
    }
}
void pushs2(int s[], int *c1, int *c2, int num){
    if ((*c1) <= (*c2)){
        s[*c2] = num;
        (*c2)--;
    } else {
        printf("ERROR\n");
    }
}
int pops1(int s[], int *c){
    if ((*c)>0){
    int val = s[*c];
    (*c)--;
    return val;
    }
    else {
        printf("Error\n");
    }
}
int pops2(int s[], int *c, int size){
    if ((*c)<size-1){
    int val = s[*c];
    (*c)++;
    return val;
    } else {
        printf("Error\n");
    }
}

void display(int s[], int s1, int s2, int size){
    for (int i = 0;i<s1;i++){
        printf("%d ", s[i]);
    }
    for (int i = size-1;i>s2;i--){
        printf("%d ", s[i]);
    }
}

void main(){
    int size = 5;
    int s[size];
    int s1t = 0, s2t = size-1;
    pushs1(s, &s1t, &s2t, 10);
    pushs1(s, &s1t, &s2t, 11);
    pushs1(s, &s1t, &s2t, 12);
    pushs2(s, &s2t, &s2t, 13);
    pops1(s, &s1t);
    pops2(s, &s2t, size);
    display(s, s1t, s2t, size);
}
