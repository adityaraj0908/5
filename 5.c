#include <stdio.h>
#include <string.h>

int horspool(char T[], char P[], int n, int m); 

int main()
{
    char T[100], P[100];
    int flag;

    printf("Enter the Text String: \n");
    // fgets(T, sizeof(T), stdin);
    // T[strcspn(T, "\n")] = '\0';
    gets(T); 

    printf("Enter the Pattern String: \n");
    // fgets(P, sizeof(P), stdin);
    // P[strcspn(P, "\n")] = '\0'; 
    gets(P);

    flag = horspool(T, P, strlen(T), strlen(P));

    if (flag == -1)
        printf("String not found \n");
    else
        printf("String found at position %d \n", flag);

    return 0;
}


int horspool(char T[], char P[], int n, int m)
{
    char table[256]; 
    int i, j;

    
    for(i = 0; i < 256; i++)
        table[i] = m; 


    for(i = 0; i < m - 1; i++)
        table[(unsigned char)P[i]] = m - 1 - i;

    i = m - 1;

    while(i < n)
    {
        j = 0;

        while(j < m && T[i - j] == P[m - 1 - j])
            j++;

        if(j == m)
            return i - m + 1;
        else
            i = i + table[(unsigned char)T[i]];
    }
    return -1; 
}
