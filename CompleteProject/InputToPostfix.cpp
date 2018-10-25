/**
Given an input as a string it converts the string
into postfix and updates the global stack "ans" with the postfix order.

* \warning Remember before using the postfix function the stack must be empty.

* \param s Input String which is fully paranthesized
*/


//#include "GlobalVariables+headers.cpp"   //Dependency if ran independently

void postfix(string s) // Parameter is in string format
{
	int flag = 0; // flag is used to keep track of negations
	for (int i = 0; i < s.size(); ++i) // Looping through the string
	{
		if(!(s[i] > 96 and s[i] < 123) or s[i] == 'V') // Ignoring literals and stacking operators int he "op" stack
		{
			op.push(s[i]);
			if(s[i] == '~')
				flag++;
			else flag = 0;
			if(op.top() == ')') // if '(' encountered then poping all the operators till ')' and storing them in a stack "ans"
			{
				op.pop();
				while(op.top() != '(') // pushing elements to "ans" stack till '(' is encountered
				{
					if(op.top() != ')' and op.top() != '~') // ignoring '~' while pushing operators to the "ans" stack
						ans.push(op.top());
					op.pop(); // poping operators from the operators stack after pushing the corresponding operators to the "ans" stack
				}
				op.pop(); // poping the '(' operator
				while(!op.empty() and (op.top() == '~')) // pushing '~' operator/s before the brackets to the "ans" stack
					ans.push(op.top()),op.pop();
				continue;
			}
		}
		else
		{
			ans.push(s[i]); // pushing th literals to the "ans" stack
			if(flag >= 1) // pushing '~' operators before the literals to the "ans" stack 
				while(flag--)
					ans.push(op.top()),op.pop();
		}
	}
	while(!op.empty()) // pusing remaining operators or literals beyond the scope of outtermost brackets to the "ans" stack
	{
		ans.push(op.top());
		op.pop();
	}
}
