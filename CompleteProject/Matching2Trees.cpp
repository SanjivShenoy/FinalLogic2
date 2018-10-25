/**
The function compares 2 trees given as input.
We can also compare with the subtree of a given tree
by specifying the starting node of the tree to start with.

* \param tree1 first tree
* \param tree2 second tree
* \param index1 starting node of the first tree
* \param index2 starting node of the second tree
*/


//#include "GlobalVariables+headers.cpp"  ////Dependency if ran independently

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
