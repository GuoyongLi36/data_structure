#include<iostream>
#include<deque>
#include<cstring>
#include <iterator>
using namespace std;

deque<int> ready, block;
int var[26], id[1024], str[5], program, q, t;
string code[1024];
bool locked = false;;

void run(int i)
{
	int time = q;
	while(time > 0)
	{
		string now = code[id[i]];
		if(now[2] == '=')
		{
			var[now[0] - 'a'] = isdigit(now[5])? ((now[4] - '0')*10 + now[5] - '0'): (now[4] - '0');
			time -= str[0];
		}
		else if (now[2] == 'i')
		{
			cout << i+1 << ':' << ' '<< var[now[6] -'a'] << endl;
			time -= str[1];
		}
		else if(now[2] == 'c')
		{
			if(locked)
			{
				block.push_back(i);
				return;
			}
			else
			{
				locked = true;
				time -= str[2];
			}
		}
		else if(now[2] == 'l')
		{
			locked = false;
			ready.push_front(block[0]);
			block.pop_front();
			time -= str[3];
		}
		else if(now[2] == 'd')
		{
			return;
		}
		id[i]++;
	}
	ready.push_back(i);
}

int main(){
	cin >> t;
	while(t--)
	{
		memset(var,0,sizeof(var));
		ready.clear();
		block.clear();
		cin >> program >> str[0] >> str[1] >> str[2] >> str[3] >> str[4] >> q;
		int indexCode = 0;
		int indexProm = 0;
		id[indexProm++] = 0;
		while(getline(cin, code[indexCode++]))
		{
			if(code[indexCode-1][2] == 'd')
			{
				id[indexProm++] = indexCode;
				cout << "indexProm: " << indexProm << endl;
				if(indexProm == program + 1)
				{
					break;
				} 	
			}
		}
		for(int i = 0; i < program; i++)
		{
			ready.push_back(i);
		}	
		while(ready.size())
		{

			int next = ready[0];
			ready.pop_front();
			run(next);
		}
	}
	
}
