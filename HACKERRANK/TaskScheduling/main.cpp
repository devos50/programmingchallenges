#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <list>
#include <cassert>

#define H 18
#define TO2H 262144
#define INT_LOW -1000000000;

using namespace std;

int n;

typedef struct Node {
    int subtree_length;
    int max_overshoot;
    int id;
} Node;

typedef struct Task {
	int time;
	int deadline;
	int index;
} Task;

vector<Task> tasks;
vector<Task> sortedtasks;
Node tree[TO2H*2];

bool compare(const Task &t1, const Task &t2) { return (t1.deadline < t2.deadline); }

int main() 
{
	cin >> n;
	
	for(int i = 0; i < n; i++)
	{
		Task t; cin >> t.time >> t.deadline; t.index = i;
		tasks.push_back(t);
		sortedtasks.push_back(t);
	}
	
	sort(sortedtasks.begin(), sortedtasks.end(), compare);
	
	// voeg lege nodes toe
	for(int i = 0; i < TO2H*2; i++)
	{
		Node n; n.subtree_length = 0; n.max_overshoot = INT_LOW;
		tree[i] = n;
	}
	
	for(int i = 0; i < n; i++)
	{
		int taskindex = sortedtasks[i].index;
		int treeindex = taskindex | TO2H;
		
		cout << "current task time: " << tasks[taskindex].time << ", deadline: " << tasks[taskindex].deadline << ", index: " << tasks[taskindex].index << endl;
		
		// voeg tasks toe
		Task curt = tasks[taskindex];
		Node n; n.subtree_length = curt.time; n.max_overshoot = curt.time - curt.deadline;
		cout << "new overshoot: " << n.max_overshoot << endl;
		tree[treeindex] = n;
		
		while(treeindex != 1)
		{
			treeindex /= 2;
			tree[treeindex].subtree_length = tree[treeindex * 2].subtree_length + tree[treeindex * 2 + 1].subtree_length;
			tree[treeindex].max_overshoot = max(tree[treeindex * 2].max_overshoot - tasks[taskindex].deadline, 
												 tree[treeindex * 2 + 1].max_overshoot - tasks[taskindex].deadline);
			cout << "max overshoot: " << tree[treeindex].max_overshoot << endl;
		}
		cout << tree[1].max_overshoot << endl;
	}
	
    return 0;
}
