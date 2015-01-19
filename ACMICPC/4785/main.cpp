#include <iostream>
#include <vector>
#include <sstream>
#include <stack>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;

enum StatementType { OPERATOR, VECTOR, PARENTESIS, VARIABLE };

class Type 
{
	public:
	StatementType type;
};

class OperatorType : public Type
{
	public:
	string op;
};

class VectorType : public Type
{
	public:
	int dimension, rows, columns, z;
	vector<int> vec;
	
	void print() 
	{
		if(dimension == 1)
		{
			for(int i = 0; i < vec.size(); i++)
			{
				cout << vec[i];
				if(i != vec.size() - 1) cout << " ";
			}
			cout << endl;
		}
		else if(dimension == 2)
		{
			for(int i = 0; i < rows; i++)
			{
				for(int j = 0; j < columns; j++)
				{
					cout << vec[i * columns + j];
					if(j != columns - 1) cout << " ";
				}
				cout << endl;
			}
		}
		else if(dimension == 3)
		{
			for(int i = 0; i < z; i++)
			{
				for(int j = 0; j < rows; j++)
				{
					for(int k = 0; k < columns; k++)
					{
						cout << vec[i * rows * columns + j * columns + k];
						if(k != columns - 1) cout << " ";
					}
					cout << endl;
				}
				if(i != z - 1) cout << endl;
			}
		}
	}
	
};

class ParenthesesType : public Type
{
	public:
	string par;
};

class VariableType : public Type
{
	public:
	string name;
};

bool isConstant(string s)
{
	for(int i = 0; i < s.size(); i++)
		if(s.at(i) < '0' || s.at(i) > '9') return false;
	return true;
}

bool isOperator(string s)
{
	return (s == "drop" || s == "iota" || s == "rho" || s == "*" || s == "-" || s == "+" || s == "=" || s == "/");
}

bool isParentheses(string s)
{
	return (s == "(" || s == ")");
}

int evalDivVec(vector<int> vec, string op)
{
	int ans = vec[0];
	if(op == "-") // alternating serie
	{
		bool isMinus = true;
		for(int i = 1; i < vec.size(); i++)
		{
			if(isMinus) ans -= vec[i];
			else ans += vec[i];
			isMinus = !isMinus;
		}
	}
	else if(op == "+") // sum
	{
		for(int i = 1; i < vec.size(); i++)
			ans += vec[i];
	}
	else if(op == "*") // times
	{
		for(int i = 1; i < vec.size(); i++)
			ans *= vec[i];
	}
	return ans;
}

map<string, VectorType *> varMap; // map that stores the values of variables

VectorType *evaluate(Type *leftOp, Type *op, Type *rightOp)
{
	if(op->type == OPERATOR) // addition of the two operands
	{
		OperatorType *ot = (OperatorType *)op;
		vector<int> res;
		VectorType *ret = new VectorType();
		if(ot->op == "=") // assignment
		{
			string varName = ((VariableType *)leftOp)->name;
			vector<int> varValue;
			if(rightOp->type == VARIABLE)
			{
				VectorType *vt = varMap[((VariableType *)rightOp)->name];
				varValue = vt->vec;
				ret->z = vt->z, ret->rows = vt->rows, ret->columns = vt->columns;
				ret->dimension = varMap[((VariableType *)rightOp)->name]->dimension;
			}
			else 
			{
				VectorType *vt = (VectorType *)rightOp;
				varValue = vt->vec;
				ret->dimension = vt->dimension;
				ret->z = vt->z, ret->rows = vt->rows, ret->columns = vt->columns;
			}
			
			varMap[varName] = ret;
			res = varValue;
		}
		else if(ot->op == "iota") // iota
		{
			VectorType *rightVector;
			if(rightOp->type == VARIABLE) rightVector = varMap[((VariableType *)rightOp)->name];
			else rightVector = (VectorType *)rightOp;
			
			int length = rightVector->vec[0];
			for(int i = 1; i <= length; i++) res.push_back(i);
			ret->dimension = 1;
		}
		else if(ot->op == "drop") // drop
		{
			VectorType *leftVector, *rightVector;
			if(leftOp->type == VARIABLE) leftVector = varMap[((VariableType *)leftOp)->name];
			else leftVector = (VectorType *)leftOp;
			if(rightOp->type == VARIABLE) rightVector = varMap[((VariableType *)rightOp)->name];
			else rightVector = (VectorType *)rightOp;
			
			int todrop = leftVector->vec[0];
			
			if(todrop < 0) todrop = 0; // TOEGEVOEGD NA FOUT
			res = rightVector->vec;
			res.erase(res.begin(), res.begin() + todrop);
			ret->dimension = 1;
		}
		else if(ot->op == "/") // / operator
		{
			string leftOperator = ((OperatorType *)leftOp)->op;
			VectorType *vecType;
			if(rightOp->type == VARIABLE) vecType = varMap[((VariableType *)rightOp)->name];
			else vecType = ((VectorType *)rightOp);
			vector<int> varValue = vecType->vec;
			
			if(vecType->dimension == 1)
			{
				res.push_back(evalDivVec(varValue, leftOperator));
				ret->dimension = 1;
			}
			else
			{
				int rows = vecType->rows; int columns = vecType->columns; int z = vecType->z;
				vector<int>::iterator it = varValue.begin();
				int endind = (vecType->dimension == 2) ? rows : rows * z;
				for(int i = 0; i < endind; i++)
				{
					int ans = evalDivVec(vector<int>(it, it + columns), leftOperator);
					res.push_back(ans);
					it += columns;
				}
				ret->dimension = vecType->dimension - 1; ret->columns = vecType->rows; ret->rows = vecType->z; ret->z = 0;
			}
		}
		else if(ot->op == "rho") // rho operator
		{
			VectorType *leftVector;
			VectorType *rightVector;
			if(leftOp->type == VARIABLE) leftVector = varMap[((VariableType *)leftOp)->name];
			else leftVector = (VectorType *)leftOp;
			if(rightOp->type == VARIABLE) rightVector = varMap[((VariableType *)rightOp)->name];
			else rightVector = (VectorType *)rightOp;
			if(leftVector->vec.size() == 1) // create a vector out of the right operand
			{
				ret->dimension = 1;
				ret->columns = 1;
				for(int i = 0; i < leftVector->vec[0]; i++)
					res.push_back(rightVector->vec[i % rightVector->vec.size()]);
			}
			else if(leftVector->vec.size() == 2) // creating a 2d array out of the right operand
			{
				ret->dimension = 2;
				ret->rows = leftVector->vec[0];
				ret->columns = leftVector->vec[1];
				for(int i = 0; i < leftVector->vec[0] * leftVector->vec[1]; i++)
					res.push_back(rightVector->vec[i % rightVector->vec.size()]);
			}
			else if(leftVector->vec.size() == 3) // create a 3d array out of the right operand
			{
				ret->dimension = 3;
				ret->z = leftVector->vec[0];
				ret->rows = leftVector->vec[1];
				ret->columns = leftVector->vec[2];
				res = rightVector->vec;
				for(int i = 0; i < leftVector->vec[0] * leftVector->vec[1] * leftVector->vec[2]; i++)
					res.push_back(rightVector->vec[i % rightVector->vec.size()]);
			}
		}
		else
		{
			VectorType *l, *r;
			vector<int> lvec, rvec;
			if(leftOp->type == VARIABLE) l = varMap[((VariableType *) leftOp)->name];
			else l = (VectorType *)leftOp;
			if(rightOp->type == VARIABLE) r = varMap[((VariableType *) rightOp)->name];
			else r = (VectorType *)rightOp;
			
			lvec = l->vec, rvec = r->vec;
			// one right operand => i.e. var + 4 or 4 + var
			if(rvec.size() == 1)
			{
				for(int i = 0; i < lvec.size(); i++)
				{
					if(ot->op == "+") res.push_back(lvec[i] + rvec[0]);
					if(ot->op == "-") res.push_back(lvec[i] - rvec[0]);
					if(ot->op == "*") res.push_back(lvec[i] * rvec[0]);
				}
				ret->dimension = l->dimension;
				ret->rows = l->rows;
				ret->columns = l->columns;
				ret->z = l->z;
			}
			else if(lvec.size() == 1)
			{
				for(int i = 0; i < rvec.size(); i++)
				{
					if(ot->op == "+") res.push_back(rvec[i] + lvec[0]);
					if(ot->op == "-") res.push_back(lvec[0] - rvec[i]);
					if(ot->op == "*") res.push_back(rvec[i] * lvec[0]);
				}
				ret->dimension = r->dimension;
				ret->rows = r->rows;
				ret->columns = r->columns;
				ret->z = r->z;
			}
			else
			{
				for(int i = 0; i < lvec.size(); i++)
				{
					if(ot->op == "+") res.push_back(lvec[i] + rvec[i]);
					if(ot->op == "-") res.push_back(lvec[i] - rvec[i]);
					if(ot->op == "*") res.push_back(lvec[i] * rvec[i]);
				}
				ret->dimension = l->dimension;
				ret->rows = l->rows;
				ret->columns = l->columns;
				ret->z = l->z;
			}
		}
	 	ret->vec = res;
		return ret;
	}
	
	return new VectorType();
}

VectorType *evalRightToLeft(vector<Type *> parts)
{
	// classified everything -> create a stack and evaluate everything
	stack<Type *> typeStack;
	for(vector<Type *>::iterator it = parts.begin(); it != parts.end(); it++)
		typeStack.push(*it);
		
	// end reached - evaluate everything on the stack
	while(typeStack.size() != 1)
	{
		Type *rightOp = typeStack.top(); typeStack.pop();
		if(rightOp->type == PARENTESIS)
		{
			vector<Type *> toEval;
			// pop until we find a (
			Type *cur = typeStack.top(); typeStack.pop();
			int niv = 0;
			while(true)
			{
				if(niv == 0 && cur->type == PARENTESIS && ((ParenthesesType *)cur)->par == "(") break;
				else if(cur->type == PARENTESIS && ((ParenthesesType *)cur)->par == "(") niv--;
				else if(cur->type == PARENTESIS && ((ParenthesesType *)cur)->par == ")") niv++;
				toEval.push_back(cur);
				cur = typeStack.top(); typeStack.pop();
			}
			
			// reverse vector
			reverse(toEval.begin(), toEval.end());
			rightOp = evalRightToLeft(toEval);
		}
		
		if(typeStack.size() == 0) return (VectorType *)rightOp;
		
		Type *op = typeStack.top(); typeStack.pop();
		Type *leftOp = typeStack.top(); typeStack.pop();
		if(leftOp->type == PARENTESIS)
		{
			vector<Type *> toEval;
			// pop until we find a (
			Type *cur = typeStack.top(); typeStack.pop();
			int niv = 0;
			while(true)
			{
				if(niv == 0 && cur->type == PARENTESIS && ((ParenthesesType *)cur)->par == "(") break;
				else if(cur->type == PARENTESIS && ((ParenthesesType *)cur)->par == "(") niv--;
				else if(cur->type == PARENTESIS && ((ParenthesesType *)cur)->par == ")") niv++;
				toEval.push_back(cur);
				cur = typeStack.top(); typeStack.pop();
			}
			// reverse vector
			reverse(toEval.begin(), toEval.end());
			leftOp = evalRightToLeft(toEval);
		}
		
		typeStack.push(evaluate(leftOp, op, rightOp));
	}
	
	Type *topType = typeStack.top(); typeStack.pop();
	if(topType->type == VARIABLE) return varMap[((VariableType *)topType)->name];
	
	return (VectorType *)topType;
}

void solve(string s, int c)
{
	cout << "Case " << c << ": " << s << endl;
	vector<Type *> parts;
	stringstream ss(s);
	string buf;
	while(ss >> buf)
	{
		// check if buf is a constant - if so, read till we don't have any more constants and create a vector
		if(isConstant(buf))
		{
			vector<int> constValues; constValues.push_back(atoi(buf.c_str()));
			while(ss >> buf && isConstant(buf)) constValues.push_back(atoi(buf.c_str()));
			
			VectorType *vt = new VectorType(); vt->vec = constValues;
			vt->dimension = 1;
			vt->type = VECTOR;
			parts.push_back(vt);
			
			if(isOperator(buf))
			{
				OperatorType *ot = new OperatorType(); ot->op = buf;
				ot->type = OPERATOR;
				if(buf == "iota") parts.push_back(new VectorType());
				parts.push_back(ot);
			}
			else if(isParentheses(buf))
			{
				ParenthesesType *pt = new ParenthesesType(); pt->par = buf;
				pt->type = PARENTESIS;
				parts.push_back(pt);
			}
		}
		else if(isOperator(buf))
		{
			OperatorType *ot = new OperatorType(); ot->op = buf;
			ot->type = OPERATOR;
			if(buf == "iota") parts.push_back(new VectorType());
			parts.push_back(ot);
		}
		else if(isParentheses(buf))
		{
			ParenthesesType *pt = new ParenthesesType(); pt->par = buf;
			pt->type = PARENTESIS;
			parts.push_back(pt);
		}
		else
		{
			VariableType *vt = new VariableType(); vt->name = buf;
			vt->type = VARIABLE;
			parts.push_back(vt);
		}
	}
	VectorType *res = evalRightToLeft(parts);
	res->print();
}

int main(int argc, char *argv[]) 
{
	string s;
	int c = 1;
	while(getline(cin, s))
	{
		if(s == "#") break;
		solve(s, c);
		c++;
	}
}