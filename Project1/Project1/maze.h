//at first..you can...
#include <iostream>
#include <algorithm>
#include <fstream>
#include<stack>
#include <vector>
#include<string>
#include<queue>
using namespace std;


class Maze
{
public:
	pair<int, int> start;
	pair<int, int> finish;
	vector<vector<int> > Board;


	bool Readingfile();
	void print();
	vector<pair<int, int> > DFS(pair<int, int>, pair<int, int>);
	vector<pair<int, int> > BFS(pair<int, int>, pair<int, int>);
	vector<pair<int, int> > Dijkstra(pair<int, int>, pair<int, int>);
	bool checkfor_finish_or_not(int, int);
	bool check(int, int, vector<vector<int> >);
	pair<int, int>find(int, vector<vector<int> >, pair<int, int>);
	void setdes(pair<int, int>, pair<int, int>);
	bool DFS_check(int, int, vector<vector<int> >, vector<vector<int> >);
	pair<int, int>find_optimized(int x, vector<vector<int> >, pair<int, int>);
	//void input(int, int, int, int);

};

/*void Maze::input(int x1, int y1, int x2, int y2){

	pair<int, int>start;
	start.first = y1;
	start.second = x1;
	pair<int, int>finish;
	finish.first = y2;
	finish.second = x2;
	this->setdes(start, finish);

}*/
bool Maze::DFS_check(int x, int y, vector<vector<int> > nums, vector<vector<int> >board)
{
	bool b = true;
	if (x<0 || x>19 || y<0 || y>19 || nums[y][x] == -1 || board[y][x] == 1)
	{
		return false;

	}

	return true;
}
void Maze::setdes(pair<int, int>start1, pair<int, int>finish1)
{
	this->start.first = start1.first;
	this->start.second = start1.second;
	this->finish.first = finish1.first;
	this->finish.second = finish1.second;



}
pair<int, int> Maze::find_optimized(int x, vector<vector<int> >nums, pair<int, int>prev){
	pair<int, int> backing;
	if (x != 1)
	{
		//right
		if (prev.first + 1 >= 0 && prev.first + 1 < 20 && prev.second >= 0 && prev.second < 20)
		{
			if (nums[prev.first + 1][prev.second] == x - 1)
			{
				backing.first = prev.first + 1;
				backing.second = prev.second;
				return backing;
			}

		}
		//down
		if (prev.first >= 0 && prev.first < 20 && prev.second + 1 >= 0 && prev.second + 1 < 20)
		{
			if (nums[prev.first][prev.second + 1] == x - 1)
			{
				backing.first = prev.first;
				backing.second = prev.second + 1;
				return backing;
			}
		}
		//left
		if (prev.first - 1 >= 0 && prev.first - 1 < 20 && prev.second >= 0 && prev.second < 20)
		{
			if (nums[prev.first - 1][prev.second] == x - 1)
			{
				backing.first = prev.first - 1;
				backing.second = prev.second;
				return backing;
			}
		}

		//up
		if (prev.first >= 0 && prev.first < 20 && prev.second - 1 >= 0 && prev.second - 1 < 20)
		{
			if (nums[prev.first][prev.second - 1] == x - 1)
			{
				backing.first = prev.first;
				backing.second = prev.second - 1;
				return backing;

			}
		}

	}
}
pair<int, int> Maze::find(int x, vector<vector<int> >nums, pair<int, int>prev)
{
	pair<int, int> backing;
	//up
	if (x != 1)
	{
		if (prev.first >= 0 && prev.first < 20 && prev.second - 1 >= 0 && prev.second - 1 < 20)
		{
			if (nums[prev.first][prev.second - 1] == x - 1)
			{
				backing.first = prev.first;
				backing.second = prev.second - 1;
				return backing;

			}
		}
		//down
		if (prev.first >= 0 && prev.first < 20 && prev.second + 1 >= 0 && prev.second + 1 < 20)
		{
			if (nums[prev.first][prev.second + 1] == x - 1)
			{
				backing.first = prev.first;
				backing.second = prev.second + 1;
				return backing;
			}
		}
		//left
		if (prev.first - 1 >= 0 && prev.first - 1 < 20 && prev.second >= 0 && prev.second < 20)
		{
			if (nums[prev.first - 1][prev.second] == x - 1)
			{
				backing.first = prev.first - 1;
				backing.second = prev.second;
				return backing;
			}
		}
		//right
		if (prev.first + 1 >= 0 && prev.first + 1 < 20 && prev.second >= 0 && prev.second < 20)
		{
			if (nums[prev.first + 1][prev.second] == x - 1)
			{
				backing.first = prev.first + 1;
				backing.second = prev.second;
				return backing;
			}

		}
	}
}
bool Maze::Readingfile()
{

/*

	fstream fin;
	fin.open("input.txt", ios::in);
	if (!fin.is_open())
	{
		cout << "There aren't input file" << endl;
		return false;
	}
	else
	{
		/////////////////////////////////////
		cout << "ok!" << endl;
		/////////////////////////////////////	
		string s;
		int k = 0;
		while (!fin.eof())
		{
			vector<int> vec;
			getline(fin, s);
			for (int i = 0; i < s.size(); i++)
			{
				vec.push_back(s[i] - 48);
			}
			Board.push_back(vec);
			k++;
		}

	}
	return true;*/

	vector<vector<int> > Board(20, vector<int>(20, 0));


	Board[2][0] = 1;
	Board[0][ 3] = 1;
	Board[0][ 15] =1 ;
	Board[0][ 16] = 1;
	Board[1][ 0]=1 ;
	Board[1][ 1]= 1;
	Board[1][ 2]=1 ;
	Board[1][ 3]= 1;
	Board[1][ 4]=1;
	Board[1][ 5]=1;
	Board[1][ 6]=1;
	Board[1][ 7]=1;
	Board[0][ 2]=1;
	Board[2][ 2]=1;
	Board[2][ 1]=1;
	Board[2][ 6]=1;
	Board[3][ 6]=1;
	Board[4][ 6]=1;
	Board[5][ 6]=1;
	Board[6][ 6]=1;
	Board[7][ 6]=1;


	Board[3][1] = 1;
	Board[3][2] = 1;
	Board[3][3] = 1;
	Board[4][1] = 1;
	Board[4][2] = 1;
	Board[4][3] = 1;
	Board[4][7] = 1;
	Board[4][8] = 1;
	Board[5][7] = 1;
	Board[5][8] = 1;
				  
	Board[6][7] = 1;
	Board[6][8] = 1;
	Board[7][0] = 1;
	Board[7][1] = 1;
	Board[7][2] = 1;
	Board[7][3] = 1;
	Board[7][4] = 1;
	Board[6][12] =1;
	Board[6][13] =1;
	Board[6][14] =1;
	Board[6][15] =1;
	Board[6][16] =1;
	Board[6][17] =1;
	Board[6][18] =1;
	Board[8][8] = 1;
		Board[9][8] = 1;
	Board[10][ 8]=1;
	Board[11][ 8]=1;
	Board[12][ 8]=1;
	Board[10][ 6]=1;
	Board[10][ 7]=1;
	Board[10][ 8]=1;
	Board[10][ 9]=1;
	Board[10][ 10]=1;
	Board[10][ 13]=1;
	Board[10][ 14]=1;
			
	Board[13][ 2] =1;
	Board[4][6] = 1;////////////////////////////////////////////
	Board[4][6] =1;//
	Board[4][6]= 1;//
	Board[4][6]=1;///////////////////////////
			
	Board[16][ 0]= 1;
	Board[16][ 1]= 1;
	Board[16][ 2]= 1;
	Board[17][ 0]= 1;
	Board[17][ 1]= 1;
	Board[17][ 2]= 1;
	Board[18][ 0]= 1;
	Board[19][ 0]= 1;
	Board[18][ 17]= 1;
	Board[18][ 18]= 1;
	Board[18][ 19]= 1;
	Board[19][ 17]= 1;
	Board[19][ 18]= 1;
	Board[19][ 19]= 1;



	for (int l = 13; l < 15; l++)
	{
		for (int p = 10; p < 15; p++)
		{
			Board[p][l] = 1;


		}

	}
	for (int p = 10; p < 17; p++)
	{
		Board[p][ 19] = 1;


	}
	for (int p = 12; p < 20; p++)
	{
		Board[p][ 16] =1;


	}
	for (int l = 12; l < 19; l++)
	{
		for (int p = 2; p < 5; p++)
		{
			Board[p][ l] = 1;


		}

	}
	for (int l = 8; l < 11; l++)
	{
		for (int p = 17; p < 20; p++)
		{
			Board[p][l] = 1;


		}

	}

	for (int l = 4; l < 6; l++)
	{
		for (int p = 17; p < 20; p++)
		{
			Board[p][l] = 1;


		}

	}


	this->Board = Board;
	return true;



}                     //    done//done
bool Maze::checkfor_finish_or_not(int y, int x)
{
	if (y == finish.first&& x == finish.second)
	{
		return true;
	}
	return false;
}
bool Maze::check(int y, int x, vector<vector<int> > mark)
{
	bool b = false;

	if (y >= 0 && y < 20 && x >= 0 && x < 20)
	{
		if (mark[y][x] == 0)
		{
			b = true;

			if (Board[y][x] == 0 && b == true){
				return true;
			}
		}
	}

	return false;

}
void Maze::print()
{
	for (int i = 0; i < Board.size(); i++)
	{
		for (int j = 0; j < Board[i].size(); j++)
		{
			cout << Board[i][j] << " ";
		}
		cout << endl;
	}

}

vector<pair<int, int> > Maze::DFS(pair<int, int> start, pair<int, int> finish)
{
	pair<int, int> temp;//previous dot
	vector<pair<int, int> > way;
	vector<vector<int> > nums(20, vector<int>(20, 0));//safhe copy
	pair<int, int> dot_for_push;
	int y = start.first;
	int x = start.second;
	stack<pair<int, int>> path;
	path.push(start);
	nums[y][x] = -1;
	//up
	bool right;
	bool left;
	bool up;
	bool down;
	temp.first = y;
	temp.second = x;
	//bool b;
	//tartib:
	//right up left down
	while (true)
	{
		if (DFS_check(x + 1, y, nums, Board))
		{
			temp.first = y;
			temp.second = x;
			x = x + 1;
			nums[y][x] = -1;

			dot_for_push.first = y;
			dot_for_push.second = x;
			path.push(dot_for_push);
			if (checkfor_finish_or_not(y, x))
			{
				break;
			}
			continue;
		}
		else{
			right = false;
		}
		if (DFS_check(x, y - 1, nums, Board))
		{
			temp.first = y;
			temp.second = x;
			y = y - 1;
			nums[y][x] = -1;
			dot_for_push.first = y;
			dot_for_push.second = x;
			path.push(dot_for_push);
			if (checkfor_finish_or_not(y, x))
			{
				break;
			}
			continue;
		}
		else{
			up = false;
		}
		if (DFS_check(x - 1, y, nums, Board))
		{
			temp.first = y;
			temp.second = x;
			x = x - 1;
			nums[y][x] = -1;
			dot_for_push.first = y;
			dot_for_push.second = x;
			path.push(dot_for_push);
			if (checkfor_finish_or_not(y, x))
			{
				break;
			}
			continue;
		}
		else{
			left = false;
		}
		if (DFS_check(x, y + 1, nums, Board))
		{
			temp.first = y;
			temp.second = x;
			y = y + 1;
			nums[y][x] = -1;
			dot_for_push.first = y;
			dot_for_push.second = x;
			path.push(dot_for_push);
			if (checkfor_finish_or_not(y, x))
			{
				break;
			}
			continue;
		}
		else{
			down = false;
		}
		if (right == false && left == false && up == false && down == false)
		{
			nums[dot_for_push.first][dot_for_push.second] == -1;
			path.pop();
			x = path.top().second;
			y = path.top().first;
		}

	}
	while (!path.empty())
	{
		cout << path.top().first << path.top().second << endl;
		way.push_back(path.top());
		path.pop();
	}
	cout << "End" << endl;

	return way;
}
vector<pair<int, int> > Maze::BFS(pair<int, int> start, pair<int, int> finish)
{
	bool ayafind = false;//befahmim ke finishe ya na
	vector<pair<int, int> > final;//baraye negah dashtane masiire asli
	pair<int, int>dot = start;//
	int i = 1;//shomare khoone ha
	int x = start.second;
	int y = start.first;
	vector<vector<int> > nums(20, vector<int>(20, 0));//safhe copy
	queue<pair<int, int> > des;//baraye harekatamoon

	nums[start.first][start.second] = i;
	des.push(start);
	while (true)
	{
		y = des.front().first;
		x = des.front().second;

		if (check(y, x - 1, nums))
		{
			//left
			if (checkfor_finish_or_not(y, x - 1))//find target!
			{
				ayafind = true;
				// x = x;
				//y = y - 1;
				nums[y][x - 1] = nums[y][x] + 1;
				//visited[x][y] = i + 1;

				break;

			}
			else
			{

				// x = x;
				//y = y - 1;
				nums[y][x - 1] = nums[y][x] + 1;
				dot.first = y;
				dot.second = x - 1;
				des.push(dot);

			}
		}
		//right
		if (check(y, x + 1, nums))
		{
			if (checkfor_finish_or_not(y, x + 1))//find target!
			{
				ayafind = true;
				// x = x;
				//y = y + 1;
				nums[y][x + 1] = nums[y][x] + 1;
				break;

			}
			else
			{

				// x = x;
				//y = y + 1;
				nums[y][x + 1] = nums[y][x] + 1;
				dot.first = y;
				dot.second = x + 1;
				des.push(dot);
			}
		}
		//up
		if (check(y - 1, x, nums))
		{
			if (checkfor_finish_or_not(y - 1, x))//find target!
			{
				ayafind = true;
				//x = x-1;
				//y = y ;
				nums[y - 1][x] = nums[y][x] + 1;
				break;

			}
			else
			{
				// x = x - 1;
				//y = y;
				nums[y - 1][x] = nums[y][x] + 1;
				dot.first = y - 1;
				dot.second = x;
				des.push(dot);

			}
		}
		//down
		if (check(y + 1, x, nums))
		{
			if (checkfor_finish_or_not(y + 1, x))//find target!
			{
				ayafind = true;

				nums[y + 1][x] = nums[y][x] + 1;
				break;

			}
			else
			{

				nums[y + 1][x] = nums[y][x] + 1;
				dot.first = y + 1;
				dot.second = x;
				des.push(dot);

			}
		}

		dot = des.front();
		des.pop();

	}
	if (ayafind == true)
	{

		pair<int, int>point;
		point = finish;
		final.push_back(point);
		for (int j = nums[finish.first][finish.second]; j > 1; j--)
		{
			point = find(j, nums, point);
			final.push_back(point);

		}
	}
	else{
		
	}
	return final;

}
vector<pair<int, int> > Maze::Dijkstra(pair<int, int> start, pair<int, int> finish)
{
	bool ayafind = false;//befahmim ke finishe ya na
	vector<pair<int, int> > final;//baraye negah dashtane masiire asli
	pair<int, int>dot = start;//
	int i = 1;//shomare khoone ha
	int x = start.second;
	int y = start.first;
	vector<vector<int> > nums(20, vector<int>(20, 0));//safhe copy
	queue<pair<int, int> > des;//baraye harekatamoon

	nums[start.first][start.second] = i;
	des.push(start);
	while (true)
	{
		y = des.front().first;
		x = des.front().second;
		//down
		if (check(y + 1, x, nums))
		{
			if (checkfor_finish_or_not(y + 1, x))//find target!
			{
				ayafind = true;

				nums[y + 1][x] = nums[y][x] + 1;
				break;

			}
			else
			{

				nums[y + 1][x] = nums[y][x] + 1;
				dot.first = y + 1;
				dot.second = x;
				des.push(dot);

			}
		}
		//left
		if (check(y, x - 1, nums))
		{
			if (checkfor_finish_or_not(y, x - 1))//find target!
			{
				ayafind = true;

				nums[y][x - 1] = nums[y][x] + 1;


				break;

			}
			else
			{

				nums[y][x - 1] = nums[y][x] + 1;
				dot.first = y;
				dot.second = x - 1;
				des.push(dot);

			}
		}

		//up
		if (check(y - 1, x, nums))
		{
			if (checkfor_finish_or_not(y - 1, x))//find target!
			{
				ayafind = true;
				nums[y - 1][x] = nums[y][x] + 1;
				break;

			}
			else
			{

				nums[y - 1][x] = nums[y][x] + 1;
				dot.first = y - 1;
				dot.second = x;
				des.push(dot);

			}
		}

		//right
		if (check(y, x + 1, nums))
		{
			if (checkfor_finish_or_not(y, x + 1))//find target!
			{
				ayafind = true;

				nums[y][x + 1] = nums[y][x] + 1;
				break;

			}
			else
			{

				// x = x;
				//y = y + 1;
				nums[y][x + 1] = nums[y][x] + 1;
				dot.first = y;
				dot.second = x + 1;
				des.push(dot);
			}
		}

		dot = des.front();
		des.pop();

	}
	if (ayafind == true)
	{

		pair<int, int>point;
		point = finish;

		for (int j = nums[finish.first][finish.second]; j > 1; j--)
		{
			point = find_optimized(j, nums, point);
			final.push_back(point);

		}
	}
	else{
		cout << "There aren't way to destination...." << endl;
	}
	cout << "yes";
	return final;

}

/*
int main()
{
	vector<pair<int, int> > ans;
	vector<pair<int, int> > ans2;

	Maze maze;
	bool b;
	if (b)
	{

		int x1;
		int y1;
		int x2;
		int y2;
		cout << "enter x & y for start;" << endl;
		cin >> x1 >> y1;
		cout << "enter x & y for end;" << endl;
		cin >> x2 >> y2;
		if (x1 < 0 && x1>20 && y1 < 0 && y1>20 && x2 <0 && x2>20 && y2 < 0 && y2>20)
		{
			cout << "it's not possible...try again " << endl;
		}

		maze.print();
		pair<int, int>start;
		start.first = y1;
		start.second = x1;
		pair<int, int>finish;
		finish.first = y2;
		finish.second = x2;
		//maze.input(x1, y1, x2, y2);
	/ *voroodi mikhoone* /	//maze.setdes(start, finish);
	/ ** /	ans = maze.BFS(start, finish);
		//cout << endl;
		for (int i = 0; i < ans.size(); i++)
		{
			cout << "(" << ans[i].first << " , " << ans[i].second << " ) " << endl;
		}

	/ ** /	maze.DFS(start, finish);
	/ ** /	ans2 = maze.Dijkstra(start, finish);
		for (int i = 0; i < ans.size(); i++)
		{
			cout << "(" << ans2[i].first << " , " << ans2[i].second << " ) " << endl;
		}

	}


	system("pause");
	return 0;
}*/

