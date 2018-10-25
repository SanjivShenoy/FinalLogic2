/**
The function takes a stack with the postfix order as input
and returns binary tree(in the form of a character array--using heap--
left node of a node is 2*index+1 and right node of a node is 2*index+2)

* \param st A char stack with postfix order in it
*/

//#include "GlobalVariables+headers.cpp"   //Dependency if ran independently

void tree(stack <char> st)
{
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
					return;

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
						return;
			}
		}
	}

	return;
}