#include <stdio.h>

#include <string.h>

int count_decoding_digits(char *digits, int n)

{

    int count[n + 1]; 
    count[0] = 1;

    count[1] = 1;

    for (int i = 2; i <= n; i++)

    {

        count[i] = 0;


        if (digits[i - 1] > '0')

            count[i] = count[i - 1];


        if (digits[i - 2] == '1' || (digits[i - 2] == '2' && digits[i - 1] < '7'))

            count[i] += count[i - 2];
    }

    return count[n];
}

int main()

{

    char digits[15];

    printf("Enter the digit sequence:");

    gets(digits);

    int n = strlen(digits);

    printf("Possible count of decoding of the sequence: %d\n", count_decoding_digits(digits, n));

    return 0;
}