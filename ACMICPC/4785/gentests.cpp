#include <iostream>
#include <sstream>
#include <vector>

#define kMaxLev 5
#define kMaxVectorSize 6

using namespace std;

string operators[7] = { "+", "-", "*", "drop", "rho", "iota", "/" };

string randomVector(int size)
{
	string res = "";
	for(int i = 0; i < size; i++)
	{
		stringstream ss; ss << rand() % 50;
		res += ss.str();
		if(i != size - 1) res += " ";
	}
		
	return res;
}

string randomNumber(int max)
{
	stringstream ss; ss << rand() % max;
	return ss.str();
}

string genExpression(int lev, int dimen)
{
	if(lev == kMaxLev) return "3";
	
	// choose random operator
	int randNum = rand() % 8 - 1;
	if(randNum == -1) randNum = 0;
	string op = operators[randNum];
	
	string leftOp, rightOp;
	if(op == "+" || op == "-" || op == "*")
	{
		// one element vector in it or not?
		randNum = rand() % 2;
		if(randNum) // one element operation
		{
			// left or right?
			randNum = rand() % 2;
			if(randNum) // one element vector left
			{
				leftOp = randomNumber(50);
				rightOp = randomVector(rand() % kMaxVectorSize + 1);
			}
			else // one element vector right
			{
				leftOp = randomVector(rand() % kMaxVectorSize + 1);
				rightOp = randomNumber(50);
			}
		}
		else
		{
			int size = rand() % kMaxVectorSize + 1;
			leftOp = randomVector(size);
			rightOp = randomVector(size);
		}
	}
	else if(op == "drop")
	{
		int rsize = rand() % kMaxVectorSize + 1;
		rightOp = randomVector(rsize);
		int leftNum = (rsize == 1) ? 0 : rand() % (rsize - 1);
		stringstream ss; ss << leftNum; leftOp = ss.str();
	}
	else if(op == "rho")
	{
		// one- two- or three dimensional?
		int dimension = rand() % 3 + 1;
		rightOp = randomVector(rand() % kMaxVectorSize + 1);
		leftOp = "";
		for(int i = 0; i < dimension; i++)
		{
			int randSize = rand() % 10 + 1;
			stringstream ss; ss << randSize;
			leftOp += ss.str();
			if(i != dimension - 1) leftOp += " ";
		}
	}
	else if(op == "iota")
	{
		stringstream ss; ss << randomNumber(50);
		rightOp = ss.str();
		leftOp = "";
	}
	else if(op == "/")
	{
		// choose a left operator
		int randNum = rand() % 3;
		if(randNum == 0) leftOp = "-";
		else if(randNum == 1) leftOp = "+";
		else if(randNum == 2) leftOp = "*";
		rightOp = randomVector(rand() % kMaxVectorSize + 1);
	}
	
	if(leftOp == "") return "( " + op + " " + rightOp + " )";
	return "( " + leftOp + " " + op + " " + rightOp + " )";
}

int main(int argc, char *argv[]) 
{
	for(int i = 0; i < 300; i++)
	{
		srand(clock());
		
		// choose random dimension for the answer
		int dimension = rand() % 3 + 1;
		
		cout << genExpression(0, dimension) << endl;
	}
}