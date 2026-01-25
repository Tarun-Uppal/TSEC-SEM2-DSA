#include <stdio.h>
int a = 1;
int count = 3;
int arr[28];
int i = 0;
int pos, num, temp;

void insert();
void del();
void display();

void main()
{
    printf("Enter the numbers\n");
    for (int i = 0; i<count; i++){
        scanf("%d", &arr[i]);
    }
    while (a>0)
    {
        printf("1-Insert\n2-Delete\n3-Display\n4-Exit\n");
        scanf("%d", &i);
        switch(i)
        {
            case 1:
                insert();
                break;
            case 2:
                del();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exit\n");
                return;
            default:
                printf("Invalid Choice\n");
        }
    }
}
void insert(){
    printf("Insert\n");
    printf("Enter the number: ");
    scanf("%d", &num);
    printf("Enter the position: ");
    scanf("%d", &pos);
    count += 1;
    if (pos < 0 || pos > count)
    {
        printf("Error");
        return;
    }
    temp = arr[pos];
    arr[pos] = num;
    for(int i = pos; i < count; i++)
    {
        int xyz = arr[i+1];
        arr[i+1] = temp;
        temp = xyz;
    }
}
void del()
{
    printf("Delete\n");
    printf("Enter the position: ");
    scanf("%d", &pos);
    count -= 1;
    for (int i = pos; i<count;i++)
    {
        arr[i] = arr[i+1];
    }
}
void display()
{
    printf("Display\n");
    for(int i = 0;i < count; i++)
    {
        printf("%d, ", arr[i]);
    }
    printf("\n");
}
