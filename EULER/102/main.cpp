#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

string delimiter = ",";

typedef struct fPoint {
	int x, y;
} fPoint;

float sign(fPoint p1, fPoint p2, fPoint p3)
{
  return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
}

bool pointInTriangle(fPoint pt, fPoint v1, fPoint v2, fPoint v3)
{
  bool b1, b2, b3;

  b1 = sign(pt, v1, v2) < 0.0f;
  b2 = sign(pt, v2, v3) < 0.0f;
  b3 = sign(pt, v3, v1) < 0.0f;

  return ((b1 == b2) && (b2 == b3));
}

bool contains_origin(vector<int> triangle)
{
	fPoint p1; p1.x = triangle[0], p1.y = triangle[1];
	fPoint p2; p2.x = triangle[2], p2.y = triangle[3];
	fPoint p3; p3.x = triangle[4], p3.y = triangle[5];
	fPoint origin; origin.x = 0, origin.y = 0;
	
	return pointInTriangle(origin, p1, p2, p3);
}

int main(int argc, char *argv[]) 
{
	fstream fin("triangles.txt");
	
	string s;
	int ans = 0;
	while(getline(fin, s))
	{
		vector<int> triangle;
		size_t pos = 0;
		string token;
		while((pos = s.find(delimiter)) != std::string::npos) 
		{
		    token = s.substr(0, pos);
			triangle.push_back(atoi(token.c_str()));
		    // std::cout << atoi(token.c_str()) << " ";
		    s.erase(0, pos + delimiter.length());
		}
		// std::cout << atoi(s.c_str()) << std::endl;
		triangle.push_back(atoi(s.c_str()));
		if(contains_origin(triangle)) ans++;
	}
	cout << ans << endl;
}