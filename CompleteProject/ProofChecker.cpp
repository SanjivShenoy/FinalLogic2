/*!
* \mainpage Proof Checker
* \section Objective
* Propositional Logic Proof Checker for rules:

* And Introduction(^i)

* And Elimination1(^e1)

* And Elimination2(^e2)

* Or  Introduction1(Vi1)

* Or  Introduction2(Vi2)

* Implication Elimination(>e)

* Modus Tollens(MT)

\section Working
* Takes proof as input (input as strings of well-formed propositional formula,
proof rules and line numbers(if required))
and prints whether the proof is valid or invalid.
*/


#include "GlobalVariables+headers.cpp"
#include "InputToPostfix.cpp"
#include "PostfixToBinaryTree.cpp"
#include "BinaryTreeToInfix.cpp"
#include "Matching2Trees.cpp"
#include "ProofRuleFunctions.cpp"


int main()
{
	IOS;
	int n;
    cin>>n; // enter number of lines of proof

	string s[1000];     //string array containing user input.
    string rule[1000];  //string array containing rule for each line.
    int d[1000][2];     //2 Dimensional array containing line numbers if required.
    int i = 0,z=0;
    for(i = 0; i < n; i++,z=0)  // checking each line in a for loop.
    {
        char c = 0;
		//taking user input as a string
        scanf("\n%c", &c);
		while(c == 32)
			scanf("%c", &c);
        while(c != '/')
        {
            string p(1,c);
            s[i].append(p);
            scanf("%c",&c);
			while(c == 32)
				scanf("%c", &c);
        }

		postfix(s[i]); //converting user input to postfix and stores it in a stack 'ans'

		tree(ans); //converting postfix to a binary tree and storing in heap global array.

		for(int j=0; j<Z; j++)
			D2[i][j] = heap[j]; //transferring the tree in heap to the global 2D array
								//It stores each line entered as a binary tree.

		while(!ans.empty())  //emptying the answer stack.
			ans.pop();

		//taking rule used as a string
        scanf("%c",&c);
		while(c == 32)
			scanf("%c", &c);

        while(c != '/')
        {
            string p(1,c);
            rule[i].append(p);
            if(c == 'P')
                break;
            scanf("%c",&c);
			while(c == 32)
				scanf("%c", &c);
        }

		//taking line numbers as input and storing in a array.
		int x;
        while(c != '\n')
        {
			if(c == '/')
	        {
				scanf("%d", &x );
				d[i][z++] = x;
			}
            scanf("%c",&c);
			while(c == 32)
				scanf("%c", &c);

        }
    }



	for(int i=0; i<n; i++)
	{
		//if ith rule is a premise, skip it
		if(rule[i] == "P")
			continue;
		// if it is ^i then call and introduction function
		else if(rule[i] == "^i")
		{
			bool truth = AndI(D2[i], d[i][0], d[i][1]);

			//if and introduction returns false, then it is an invalid proof.
			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}

		//if ith rule is ^e1 then call And E with second parameter as 1
		else if(rule[i] == "^e1")
		{
			bool truth = AndE(D2[i], 1, d[i][0]);

			//if and elimination returns false, then it is an invalid proof.
			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}

		//if ith rule is ^e2 then call And E with second parameter as 2
		else if(rule[i] == "^e2")
		{
			bool truth = AndE(D2[i], 2, d[i][0]);

			//if and elimination returns false, then it is an invalid proof.
			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}

		//if ith rule is Vi1 then call OrI with second parameter as 1
		else if(rule[i] == "Vi1")
		{

			bool truth = OrI(D2[i], 1, d[i][0]);
			//if Or introduction returns false, then it is an invalid proof.
			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}

		//if ith rule is Vi2 then call OrI with second parameter as 2
		else if(rule[i] == "Vi2")
		{
			bool truth = OrI(D2[i], 2, d[i][0]);

			//if Or introduction returns false, then it is an invalid proof.
			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}

		//if ith rule is >e then call Imp Elimination
		else if(rule[i] == ">e")
		{
			bool truth = ImpE(D2[i], d[i][0], d[i][1]);

			//if Imp Elimination returns false, then it is an invalid proof.
			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}

		//if ith rule is MT then call Modus Tollens
		else if(rule[i] == "MT")
		{
			bool truth = MT(D2[i], d[i][0], d[i][1]);

			//if Modus Tollens returns false, then it is an invalid proof.
			if(truth == false)
			{
				printf("Invalid Proof");
				return 0;
			}
		}
	}


	//As none of the proof rules returned invalid for all the n lines of the
	//proof, it is a valid proof.
	printf("Valid Proof");

    return 0;
}
