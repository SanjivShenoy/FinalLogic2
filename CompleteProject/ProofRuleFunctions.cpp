/*
Contains functions one for each proof rule.
Returns true if rule applys correctly,
otherwise returns false.
*/


//#include "GlobalVariables+headers.cpp"    //Dependency if ran independently
//#include "Matching2Trees.cpp"             //Dependency if ran independently

/*
 NOTE - All the functions which follow use the MatchTree Function to
 compare subtrees.
 // 0->start from root// 1->start from left subtree// 2->start from right subtree
*/

/** Checks if the user has indeed introduced '^'. If yes, checks if the
left and right subtrees match with those mentions in line numbers l1 and l2.
* \param tree user input in the form of a tree.(Containing ^)
* \param l1 line number of proof containing the left side of ^i
* \param l2 line number of proof containing the right side of ^i
*/

bool AndI(char tree[], int l1, int l2)
{
    if(tree[0] != '^') return false; //checks if user indeed introduced '^'

    //Returns true if both left and right subtrees match.
    if(MatchTree(tree, D2[l1-1], 1, 0) && MatchTree(tree, D2[l2-1], 2, 0))
        return true;
    else
		return false;
}

/** Checks whether conclusion is true based on whether '^' in the proof line l1
can be eliminated(type specifies elimination 1 or 2)
* \param tree Binary tree on proof line l1
* \param type 1 - left, 2 - right
* \param l1 line number of proof containing the '^' to be eliminated.
*/
bool AndE(char tree[], int type, int l1)
{
    if(D2[l1-1][0] != '^') return false; //checks if for line l1 root node is '^'

    //based on type, matches either the left or right subtree and if matches returns true.
    if(type == 1)
        if(MatchTree(tree, D2[l1-1], 0, 1))
            return true;
    if(type == 2)
        if(MatchTree(tree, D2[l1-1], 0, 2))
            return true;

    return false;
}

/** Checks whether mentioned type of Or introduction
can be applied.
* \param tree user input as a Binary Tree (containing 'V')
* \type 1 - left, 2 - right
* \param l1 line number of the proof containing left or right side of 'V' based on the type.
*/
bool OrI(char tree[], int type, int l1)
{
    if(tree[0] != 'V') return false; //checks if user indeed introduced 'V'

    //based on the type, matches left or right subtree and returns true if matches.
    if(type == 1)
        if(MatchTree(tree, D2[l1-1], 1, 0))
            return true;
    if(type == 2)
        if(MatchTree(tree, D2[l1-1], 2, 0))
            return true;

    return false;
}

/** Checks whether implication can be eliminated based on whether the left
side of the implication is true, so as to conclude the right side.
* \param tree user input as a Binary Tree (conclusion i.e. right side of implication)
* \param l1 line number of proof containing the implication
* \param l2 line number of proof containing the left side of implication
*/
bool ImpE(char tree[], int l1, int l2)
{
    if(D2[l1-1][0] != '>') return false; //checks whether for l1 root node is '>'

    // returns true if left and right side of the implication match with l2 and
    // tree respectively.
    if(MatchTree(D2[l1-1], D2[l2-1], 1, 0) && MatchTree(D2[l1-1], tree, 2, 0))
        return true;

    return false;
}

/** Checks whether Modus Tollens is applied correctly based on whether
implication(on line l1) and negation of its right side(on line l2) are true
so as to conclude the negation of the left side(tree)
* \param tree user input as a tree.
* \param l1 line number of the proof containing implication.
* \param l2 line number of the proof containing negation of the right side of the implication.
*/
bool MT(char tree[], int l1, int l2)
{
    if(D2[l1-1][0] != '>') return false; // checks if for line l1 root node is '>'

    if(tree[0] != '~' || D2[l2-1][0] != '~') return false; // checks whether for tree and l2 root node is '~'

    //Returns true if the right subtrees of the negations match with the left
    // and right sides of implication on line l1
    if(MatchTree(tree, D2[l1-1], 2, 1) && MatchTree(D2[l2-1], D2[l1-1], 2, 2))
        return true;
    else
        return false;
}
