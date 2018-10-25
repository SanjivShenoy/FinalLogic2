#include <iostream>
#include<stdio.h>
#include <string.h>
#include <stack>
#include<math.h>
#define ull unsigned long long
#define ll long long
#define Z 1000005
#define FOR(P,Q) for(P=0;P<Q;P++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
string s;
char D2[10000][Z];
int i,cnt;
stack <char> op,ans,in;
int height = 13;

void postfix(string s)
{
	int flag = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(!(s[i] > 96 and s[i] < 123) or s[i] == 'V')
		{
			op.push(s[i]);
			if(s[i] == '~')
				flag++;
			else flag = 0;
			if(op.top() == ')')
			{
				op.pop();
				while(op.top() != '(')
				{
					if(op.top() != ')' and op.top() != '~')
						ans.push(op.top());
					op.pop();
				}
				op.pop();
				while(!op.empty() and (op.top() == '~'))
					ans.push(op.top()),op.pop();
				continue;
			}
		}
		else
		{
			ans.push(s[i]);
			if(flag >= 1)
				while(flag--)
					ans.push(op.top()),op.pop();
		}
	}
	while(!op.empty())
	{
		ans.push(op.top());
		op.pop();
	}
}

char* tree(stack <char> st)
{
	char heap[Z];
	for(int i=0; i<Z; i++)
	{
		heap[i] = 0;
	}
	int mk = 0;
	stack <int> sym;
	while(!st.empty())
	{
		char c = st.top();
		st.pop();
		heap[mk] = c;

		//if symbol encountered, go to right node
		if(c == '>' or c == '^' or c == 'V')
		{
			sym.push(mk);
			mk = (2*mk) + 2;
		}

		// if negation symbol, put 0 in left node and go to right node
		else if (c == '~')
			mk = 2*mk + 2;

		else
		{
			//right node (even number) finished, go to left
			if(mk%2 == 0)
			{
				mk--;
				//check if the left node is 0
				if(heap[mk] == 0 && !sym.empty())
					mk = 2*(sym.top()) + 1;
				else
					return heap;

				sym.pop();
			}

			//left node is done, go to left node of previously unfilled
			else
			{
					if(!sym.empty())
					{
						mk = 2*(sym.top()) + 1;
						sym.pop();
					}

					else
						return heap;
			}
		}
	}

	cout<<'\n';
	return heap;
}

void infix(int i, char Arr[], int N)
{
    if(i == 0) printf("(");

    if(Arr[i] == 0)
        return;
    if(Arr[(2*i)+1] == 0 && Arr[(2*i)+2] == 0)
    {
        printf("%c", Arr[i]);
        return;
    }
    else
    {
        if(Arr[(2*i)+1] != 0)
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

        if(Arr[(i*2)+2] != 0)
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
    if(i == 0) printf(")");
}

////Part2 begins

// here arr is the biger tree and arr2 is the tree that we are comparing,
// ind is the index corresponding to the starting point of the subtree that we intensd to compare with arr2
// h is the height of the subtree, if not known we can give values like 10 or 15
bool MatchTree(char *tree1, char *tree2, int index1, int index2)
{
	int i = index1 ,j = index2, h = -1; // Initializing the iterators of the levels
	while(h++ <= height)
	{
		for (int k = 0; k < pow(2,h); ++k) // Checking the trees at level h
		{
			if(tree1[i+k] == tree2[j+k])
				continue;
			else
				return false;
		}
		i = 2*i+1; // Updating i to next level
		j = 2*j+1; // Updating j to next level
	}
    return true;
}



bool AndI(char tree[], int l1, int l2)
{
    if(tree[0] != '^') return false;
    if(MatchTree(tree, D2[l1-1], 1, 0) & MatchTree(tree, D2[l2-1], 2, 0))  /// 0->start from root// 1->left // 2->right
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
	IOS;
	int n;
    cin>>n;

	string s[n];
    string rule[n];
    int d[n][2];
    int i = 0,z=0;
    for(i = 0; i < n; i++,z=0)
    {
        char c;
		//string input
        scanf("\n%c", &c);
        while(c != '/')
        {
            string p(1,c);
            s[i].append(p);
            scanf("%c",&c);
        }

		postfix(s[i]);

		char *heap1 = tree(ans);

		for(int j=0; j<Z; j++)
			D2[i][j] = *(heap1+j);

		while(!ans.empty())
			ans.pop();

		//rule input
        scanf("%c",&c);
        while(c != '/')
        {
            string p(1,c);
            rule[i].append(p);
            if(c == 'P')
                break;
            scanf("%c",&c);
        }
		//numbers input
        scanf("%c", &c );
        while(c != '\n')
        {
            if(c != '/')
                d[i][z++] = c-'0';
            scanf("%c",&c);
        }
    }

	for(int i=0; i<n; i++)
	{
		if(rule[i] == "P")
			continue;
		else if(rule[i] == "^i")
		{
			bool truth = AndI(D2[i], d[i][0], d[i][1]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "^e1")
		{
			bool truth = AndE(D2[i], 1, d[i][0]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "^e2")
		{
			bool truth = AndE(D2[i], 2, d[i][0]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "Vi1")
		{
			bool truth = OrI(D2[i], 1, d[i][0]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "Vi2")
		{
			bool truth = OrI(D2[i], 2, d[i][0]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == ">e")
		{
			bool truth = ImpE(D2[i], d[i][0], d[i][1]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
		else if(rule[i] == "MT")
		{
			bool truth = MT(D2[i], d[i][0], d[i][1]);

			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
	}
	printf("Valid Proof");

    return 0;
}
