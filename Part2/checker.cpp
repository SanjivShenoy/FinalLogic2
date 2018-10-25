#include<bits/stdc++.h>

using namespace std;

char D2[100][100]; int Max=10;

bool MatchTree(char *tree1, char *tree2, int index1, int index2)
{
    int flag = 1, j, k; //must initialise j , k acc to input index1 and index2

    if(index1 == 0) j=-1;
    if(index1 == 1) j=0;
    if(index1 == 2) j=1;

    if(index2 == 0) k=-1;
    if(index2 == 1) k=0;
    if(index2 == 2) k=1;

    for(int i=0; i<=Max; i++)   ////max is length of tree not yet decided
    {
        if(i%2 == 1)
            j=2*j+1, k=2*k+1;
        else j++, k++;

        if(tree1[j] == tree2[k])
            continue;
        else
        {
            break;
            flag = 0;
        }
    }

    if(flag == 1) return true;
    else return false;
}

bool AndI(char tree[], int l1, int l2)
{
    if(tree[0] != '^') return false;
    if(MatchTree(tree, D2[l1-1], 1, 0) && MatchTree(tree, D2[l2-1], 2, 0))  /// 0->start from root// 1->left // 2->right
        return true;
    else
        return false;
}

bool AndE(char tree[], int type, int l1)
{
    if(D2[l1-1][0] != '^') return false;
    if(type == 1)
        if(MatchTree(tree, D2[l1-1], 0, 1))
            return true;
    if(type == 2)
        if(MatchTree(tree, D2[l1-1], 0, 2))
            return true;

    return false;
}

bool OrI(char tree[], int type, int l1)
{
    if(tree[0] != 'V') return false;
    if(type == 1)
        if(MatchTree(tree, D2[l1-1], 1, 0))
            return true;
    if(type == 2)
        if(MatchTree(tree, D2[l1-1], 2, 0))
            return true;

    return false;
}

bool ImpE(char tree[], int l1, int l2)
{
    if(D2[l1-1][0] != '>') return false;
    if(MatchTree(D2[l1-1], D2[l2-1], 1, 0) && MatchTree(D2[l1-1], tree, 2, 0))
        return true;

    return false;
}

bool MT(char tree[], int l1, int l2)
{
    if(D2[l1-1][0] != '>') return false;

    if(tree[0] != '~' || D2[l2-1][0] != '~') return false;

    if(MatchTree(tree, D2[l1-1], 2, 1) && MatchTree(D2[l2-1], D2[l1-1], 2, 2))
        return true;
    else
        return false;
}

int main()
{
    //IOS;
    int n;
    scanf("%d", &n);
    while(n--)
    {
        //cin>>s;
        //postfix(s);
        //tree(ans);
    }
    // Above Max is not initialised properly and MatchTree Function is a bit wrong
 return 0;
}
