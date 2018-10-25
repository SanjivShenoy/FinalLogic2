#include<bits/stdc++.h>

using namespace std;

void infix(int i, char Arr[], int N)
{
    if(Arr[i] == '0')
        return;
    if(Arr[(2*i)+1] == '0' && Arr[(2*i)+2] == '0')
    {
        printf("%c", Arr[i]);
        return;
    }
    else
    {
        if(Arr[(2*i)+1] != '0')
            {
                if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
                    if(Arr[(2*i)+1] == 'V' || Arr[(2*i)+1] == '^' || Arr[(2*i)+1] == '>')
                        printf("(");
                infix((2*i)+1, Arr, N);
            }

        if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
            if(Arr[(2*i)+1] == 'V' || Arr[(2*i)+1] == '^' || Arr[(2*i)+1] == '>')
                printf(")");

        printf("%c", Arr[i]);
        if(Arr[i] == '~')
            if(Arr[2*i+2] == 'V' || Arr[2*i+2] == '^' || Arr[2*i+2] == '>' || Arr[2*i+2] == '~')
                printf("%c", '(');

        if(Arr[(i*2)+2] != '0')
        {
            if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
                if(Arr[(2*i)+2] == 'V' || Arr[(2*i)+2] == '^' || Arr[(2*i)+2] == '>')
                    printf("(");
            infix((2*i)+2, Arr, N);
        }

        if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
            if(Arr[(2*i)+2] == 'V' || Arr[(2*i)+2] == '^' || Arr[(2*i)+2] == '>')
                printf(")");

        if(Arr[i] == '~')
            if(Arr[2*i+2] == 'V' || Arr[2*i+2] == '^' || Arr[2*i+2] == '>' || Arr[2*i+2] == '~')
                printf("%c", ')');
    }
}

int main()
{
    //test
    int n = 1000;
    char Arr[n] ;
    for(int i = 0; i < 1000; i++)
    {
        Arr[i] = '0';
    }

    Arr[0] = '~';
    Arr[2] = '~';
    Arr[6] = 'V';
    Arr[13] = '^';
    Arr[14] = 'V';
    Arr[27] = '~';
    Arr[28] = 'q';
    Arr[29] = 'q';
    Arr[30] = '^';
    Arr[56] = 'p';
    Arr[61] = 'p';
    Arr[62] = 's';

    infix(0, Arr, n);

    return 0;
}
