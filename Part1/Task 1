#include <iostream>
#include <string>
#include <stack>
#define ull unsigned long long
#define ll long long
#define N 100000005
#define FOR(P,Q) for(P=0;P<Q;P++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
string s;
char heap[N];

void tree(stack <char> st) {
	int mk = 0;
	stack <int> sym;
	while(!st.empty()) {
		char c = st.top();
		st.pop();
		heap[mk] = c;
		cout << c;

		//if symbol encountered, go to right node
		if(c == '>' or c == '^' or c == 'v') {
			sym.push(mk);
			mk = (2*mk) + 1;
		}

		// if negation symbol, put 0 in left node and go to right node
		else if (c == '~') {
			heap[2*(mk + 1)] = -1;
			mk = 2*mk + 1;
		}

		else {
			//right node (odd number) finished, go to left
			if(mk%2) {
				mk++;
				//check if the left node is -1
				if(heap[mk] == -1) {
					mk = 2*(sym.top()) + 2;
				}
				sym.pop();
			}

			//left node is done, go to left node of previously unfilled
			else {
					if(!sym.empty()) {
					mk = 2*(sym.top()) + 2;
					sym.pop();
					}

					else
						return;
			}
		}
	}

	cout<<'\n';
}

void printTree () {
	int mk = 0;
	stack <int> sym;
	FOR(i,n) {
		char c = heap[mk];
		cout<<mk<<c<<endl;

		//if symbol encountered, go to right node
		if(c == '>' or c == '^' or c == 'v') {
			sym.push(mk);
			mk = (2*mk) + 1;
		}

		// if negation symbol, put 0 in left node and go to right node
		else if (c == '~') {
			heap[2*(mk + 1)] = -1;
			mk = 2*mk + 1;
		}

		else {
			//right node finished, go to left
			if(mk%2) {
				mk++;
				if(heap[mk] == -1) {
					mk = 2*(sym.top()) + 2;
				}
				sym.pop();
			}

			//left node is done, go to left node of previously unfilled
			else {
					if(!sym.empty()) {
					mk = 2*(sym.top()) + 2;
					sym.pop();
					}

					else
						return;
			}
		}
	}
}

int main()
{
	IOS;
	ll flag = 0,a;
	stack <char> op,ans;
	cin>>s;
	a = s.size();
	for (int i = 0; i < s.size(); ++i)
	{
		if(!(s[i] > 96 and s[i] < 123) or s[i] == 'V')
		{
			op.push(s[i]);
			if(s[i] == '~')
				flag = 1;
			else flag = 0;
			if(op.top() == ')')
			{
				op.pop();
				do
				{
					if(op.top() != ')' and op.top() != '~')
						ans.push(op.top());
					op.pop();
				}
				while(op.top() != '(');
				op.pop();
				if(!op.empty() and (op.top() == '~'))
					ans.push(op.top());
				continue;
			}
		}
		else
		{
			if(flag == 1)
			{
				ans.push(s[i]);
				ans.push(op.top());
				op.pop();
				continue;
			}
			ans.push(s[i]);
		}
	}
	while(!op.empty())
	{
		ans.push(op.top());
		op.pop();
	}
	while(!ans.empty())
	{
		in.push(ans.top());
		ans.pop();
	}

	tree(ans);
	//printTree();
    return 0;
}
