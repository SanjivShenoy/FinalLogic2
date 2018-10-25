/**
Given a binary tree(as an array - heap implementaion),
it prints out the inoder traversal of the tree with brackets
put at appropriate places.
* \param i iterator
* \param Arr[] Input Binary Tree in heap implemenation 
*/

//#include "GlobalVariables+headers.cpp"    //Dependency if ran independently

void infix(int i, char Arr[]) //i is the node to start with as root node.
{
    if(Arr[0] == '^' || Arr[0] == 'V' || Arr[0] == '>' || Arr[0] == '~')  // Add bracket at start unless of form 'p'
        if(i == 0)
            printf("(");

    if(Arr[i] == 0)    // if A[i] is not a node return i.e. in case
        return;        //when the node that called it is a leaf node

    if(Arr[(2*i)+1] == 0 && Arr[(2*i)+2] == 0)  // if leaf node print it out
    {
        printf("%c", Arr[i]);
        return;
    }
    else
    {
        if(Arr[(2*i)+1] != 0)  //if left node is itself a subtree
            {
                //bracket needs to there when 2 binary operators like ^ or V or > come in sequence
                if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
                    if(Arr[(2*i)+1] == 'V' || Arr[(2*i)+1] == '^' || Arr[(2*i)+1] == '>')
                        printf("(");
                infix((2*i)+1, Arr); // Recursively call infix again on left subtree
            }

            //closing the bracket if opened for binary operators
        if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
            if(Arr[(2*i)+1] == 'V' || Arr[(2*i)+1] == '^' || Arr[(2*i)+1] == '>')
                printf(")");

        // ~ followed by any operator means a bracket is required
        printf("%c", Arr[i]);
        if(Arr[i] == '~')
            if(Arr[2*i+2] == 'V' || Arr[2*i+2] == '^' || Arr[2*i+2] == '>' || Arr[2*i+2] == '~')
                printf("%c", '(');

        if(Arr[(i*2)+2] != 0)  // it right node is itself a subtree
        {
            // same as for left
            if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
                if(Arr[(2*i)+2] == 'V' || Arr[(2*i)+2] == '^' || Arr[(2*i)+2] == '>')
                    printf("(");
            infix((2*i)+2, Arr); // Recursively call infix on right subtree
        }
        //same as for left
        if(Arr[i] == 'V' || Arr[i] == '^' || Arr[i] == '>')
            if(Arr[(2*i)+2] == 'V' || Arr[(2*i)+2] == '^' || Arr[(2*i)+2] == '>')
                printf(")");

        //closing brackets for negation
        if(Arr[i] == '~')
            if(Arr[2*i+2] == 'V' || Arr[2*i+2] == '^' || Arr[2*i+2] == '>' || Arr[2*i+2] == '~')
                printf("%c", ')');
    }
    if(Arr[0] == '^' || Arr[0] == 'V' || Arr[0] == '>' || Arr[0] == '~')  // Add bracket at end unless of form 'p'
        if(i == 0)
            printf(")");
}




/*
test input to run in main of ProofChecker where D2 is a 2D array
of characters already defined
Depending on length of proof can call D[i] ; 0 <= i <= (lines of proof -1)
cout << '\n';
infix(0, D2[0]);
cout << '\n';
infix(0, D2[1]);
cout<<'\n';
infix(0, D2[2]);
*/