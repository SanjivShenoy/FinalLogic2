#include<bits/stdc++.h>
#include<stdio.h>
#include<string.h>
using namespace std;


int main()
{
    int n;
    cin>>n;
    string s[n];
    string rule[n];
    int d[n][2];
    int i = 0,z=0;
    for(i = 0; i < n; i++,z=0)
    {
        char c;
        scanf("%c", &c);
        while(c != '/')
        {
            string p(1,c);
            s[i].append(p);
            scanf("%c",&c);
        }
        scanf("%c",&c);
        while(c != '/')
        {
            string p(1,c);
            rule[i].append(p);
            if(c == 'P')
                break;
            scanf("%c",&c);
        }
        scanf("%c", &c );
        while(c != '\n')
        {
            if(c != '/')
                d[i][z++] = c-'0';
            scanf("%c",&c);
        }
    }

    cout<<s[0]<<' '<<rule[0]<<' '<<d[0][0]<<' '<<d[0][1]<<endl;
    return 0;
}
