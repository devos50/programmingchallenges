#include <iostream>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstdlib>
#include <sys/time.h>

#define LINT 10000000

using namespace std;

// representatie van een kant
typedef struct Edge {
	int n1, n2;
	int weight;
} Edge;

// representatie van een knoop
typedef struct Node {
	int id;
	bool in_graph;
	vector<Edge *> adj;
	bool operator<(const Node &that) const { return that.id < id; }
} Node;

// distances voor dijkstra
map<Node *, int> d;

// struct om de distances te vergelijken
struct compareDist
 {  
   bool operator()( Node *l, Node *r)  
   {  
       return d[l] > d[r];
   }  
 };

// de graaf zelf
vector<Node*> graph;

// s1, s2, t1, t2
Node *s1, *s2, *t1, *t2;

// sla de kanten op
vector<Edge *> edges;

// retourneer true als edges een kant bevat die a met b verbindt
bool contains_edge(Node *a, Node *b)
{
	for(vector<Edge *>::iterator it = edges.begin(); it != edges.end(); it++)
	{
		if(((*it)->n1 == a->id && (*it)->n2 == b->id) || ((*it)->n1 == b->id && (*it)->n2 == a->id)) return true;
	}
	return false;
}

// retourneer het symmetrisch verschil tussen twee verzamelingen A en B
set<Node *> symmetric_difference(set<Node *> a, set<Node *> b)
{
	set<Node *> symdef;
	for(set<Node *>::iterator it = a.begin(); it != a.end(); it++)
		if(b.find(*it) == b.end()) symdef.insert(*it);
	for(set<Node *>::iterator it = b.begin(); it != b.end(); it++)
		if(a.find(*it) == a.end()) symdef.insert(*it);
	
	return symdef;
}

// retourneert de Node die hoort bij een gegeven id
Node *get_node_with_id(int id)
{
	for(vector<Node*>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		if((*it)->id == id) return *it;
	}
	return 0;
}

// retourneert true als t tussen de nodes a en b ligt
bool is_between(Node *t, Node *a, Node *b)
{
	if(a->id == b->id) return false;
	else if(a->id < b->id) return (t->id > a->id && t->id < b->id);
	else return (t->id > a->id || t->id < b->id);
}

// retourneer een set met nodes tussen twee gegeven nodes
set<Node *> nodes_between(Node *a, Node *b)
{
	set<Node *> res;
	for(vector<Node *>::iterator it = graph.begin(); it != graph.end(); it++)
	{
		Node *cur = *it;
		if(cur->id == a->id || cur->id == b->id) continue;
		if(is_between(cur, a, b)) res.insert(cur);
	}
	return res;
}

// retourneert de lengte van het kortste pad tussen twee nodes
int shortest_path(Node *s, Node *t)
{
	Node *v = get_node_with_id(3);
	for(vector<Node *>::iterator it = graph.begin(); it != graph.end(); it++)
		d[*it] = LINT;
	
	set<Node *> settled;
	priority_queue<Node *, vector<Node *>, compareDist> unsettled;
	unsettled.push(s);
	d[s] = 0;
	
	while(!unsettled.empty())
	{
		Node *u = unsettled.top(); unsettled.pop();
		settled.insert(u);
		
		// relaxatie van de buren
		for(vector<Edge *>::iterator it = u->adj.begin(); it != u->adj.end(); it++)
		{
			Edge *e = *it;
			Node *v = (e->n1 == u->id) ? get_node_with_id(e->n2) : get_node_with_id(e->n1);
			
			if(!v->in_graph) continue;
			
			if(settled.find(v) != settled.end()) continue;
			if(d[v] > d[u] + e->weight)
			{
				d[v] = d[u] + e->weight;
				unsettled.push(v);
			}
		}
	}
	return d[t];
}

/*
Deze functie lost het min-max 2 disjoint path probleem op voor 2-connected outer-planar graphs.
De input is een graaf G met de terminale knopen s1, s2, t1 en t2.
*/
void solve_min_max()
{
	// maak de sets w, n, e en s
	set<Node *> w = nodes_between(s2, s1);
	set<Node *> n = nodes_between(s1, t1);
	set<Node *> e = nodes_between(t1, t2);
	set<Node *> s = nodes_between(t2, s2);
	
	// voor elke (w,e) uit {s2} u W x {t2} u E
	set<Node *> w_new = w; w_new.insert(s2);
	set<Node *> e_new = e; e_new.insert(t2);
	int p1_min_length = LINT; int p2_min_length = LINT;
	for(set<Node *>::iterator it1 = w_new.begin(); it1 != w_new.end(); it1++)
	{
		Node *w_node = *it1;
		for(set<Node *>::iterator it2 = e_new.begin(); it2 != e_new.end(); it2++)
		{
			Node *e_node = *it2;
			if(!contains_edge(w_node, e_node) && !(w_node->id == s2->id && e_node->id == t2->id)) continue;
			
			// partitioneer W in W1 die de nodes tussen w en s1 bevat en W2 = W \ W1
			set<Node *> w1 = nodes_between(s1, w_node);
			set<Node *> w2 = symmetric_difference(w, w1);
			// partitioneer E in E1 die de nodes tussen e en t1 bevat en E2 = E \ E2
			set<Node *> e1 = nodes_between(t1, e_node);
			set<Node *> e2 = symmetric_difference(e, e1);
			
			// haal alle knopen uit de graaf
			for(vector<Node *>::iterator it = graph.begin(); it != graph.end(); it++) (*it)->in_graph = false;
			// zet alles in de graaf uit N / W1 / E1
			for(set<Node *>::iterator it = n.begin(); it != n.end(); it++) { Node *n = *it; n->in_graph = true; }
			for(set<Node *>::iterator it = w1.begin(); it != w1.end(); it++) { Node *n = *it; n->in_graph = true; }
			for(set<Node *>::iterator it = e1.begin(); it != e1.end(); it++) { Node *n = *it; n->in_graph = true; }
			
			// include s1 / t1
			s1->in_graph = true; t1->in_graph = true;
			
			// find the shortest path between s1 and t1
			int p1_length = shortest_path(s1, t1);
			
			// reset de graaf en zet haal knopen uit de graaf
			for(vector<Node *>::iterator it = graph.begin(); it != graph.end(); it++) (*it)->in_graph = false;
			// zet alles in de graaf uit S / W2 / E2
			for(set<Node *>::iterator it = s.begin(); it != s.end(); it++) { Node *n = *it; n->in_graph = true; }
			for(set<Node *>::iterator it = w2.begin(); it != w2.end(); it++) { Node *n = *it; n->in_graph = true; }
			for(set<Node *>::iterator it = e2.begin(); it != e2.end(); it++) { Node *n = *it; n->in_graph = true; }
			// include s2 / t2
			s2->in_graph = true; t2->in_graph = true;
			
			int p2_length = shortest_path(s2, t2);
			// cout << "p1 length: " << p1_length << ", p2 length: " << p2_length << endl;
			if(max(p1_length, p2_length) < max(p1_min_length, p2_min_length))
			{
				p1_min_length = p1_length;
				p2_min_length = p2_length;
			}
		}
	}
	cout << "p1 length: " << p1_min_length << ", p2 length: " << p2_min_length << endl;
}

int main(int argc, char *argv[]) 
{
	// arg1: aantal knopen
	// arg2: aantal keer dat het programma herhaald moet worden
	int kNodes = atoi(argv[1]);
	int times = atoi(argv[2]);
	
	int elapsed = clock();
	for(int i = 0; i < times; i++)
	{
		edges.clear();
		graph.clear();
		// looptijd analyse -> maak een outer-planaire graaf met kNodes nodes
		struct timeval time;
		gettimeofday(&time, NULL);
		srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
			
		// maak een simpele graaf
		Node *prevNode = new Node(); prevNode->id = 1; prevNode->in_graph = true; 
		graph.push_back(prevNode); // eerste node
		for(int i = 2; i <= kNodes; i++)
		{
			Node *v = new Node(); v->id = i; v->in_graph = true; graph.push_back(v);
			Edge *e = new Edge(); e->n1 = prevNode->id; e->n2 = v->id; 
			e->weight = rand() % 100 + 1; // geef kant e een random gewicht tussen 1 en 100
			edges.push_back(e);
			v->adj.push_back(e); prevNode->adj.push_back(e);
			prevNode = v;
		}
			
		// maak edge van laaste node -> eerste node
		Edge *e = new Edge(); e->n1 = kNodes; e->n2 = 1; e->weight = rand() % 100 + 1;
		edges.push_back(e);
		
		// partitioneer de graaf in 4 delen en kies in elk deel respectievelijk s1, t1, t2, s2
		int partitionSize = kNodes / 4;
		s1 = get_node_with_id(1);
		t1 = get_node_with_id(rand() % partitionSize + 1 + partitionSize);
		t2 = get_node_with_id(rand() % partitionSize + 1 + 2 * partitionSize);
		s2 = get_node_with_id(rand() % partitionSize + 1 + 3 * partitionSize);
		
		int curw = s2->id + 1;
		int cure = t1->id + 1;
		while(curw < kNodes && cure < t2->id)
		{
			e = new Edge(); e->n1 = curw; e->n2 = cure; e->weight = rand() % 100 + 1;
			edges.push_back(e);
			curw++; cure++;
		}
		/*
		// maak een willekeurige partitie tussen w en e
		int n1 = rand() % (s2->id - s1->id) + s1->id;
		int n2 = rand() % (t2->id - t1->id) + t1->id;
		e = new Edge(); e->n1 = n1; e->n2 = n1; e->weight = rand() % 100 + 1;
		edges.push_back(e);
		*/
		solve_min_max();
	}
	cout << (clock() - elapsed) / times << endl;
}