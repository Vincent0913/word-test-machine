#include<bits/stdc++.h>
#include"abc.h"
using namespace std;

#include<fstream>
#include<windows.h>
#include<time.h>

#define int long long
#define pb push_back
#define f first
#define s second

vector<pair<string, string>>w;
vector<pair<string, int>>l;
vector<pair<string, string>>unfamiliar[26];

bool wrong = false;

int points = 0;

ifstream ifs;
string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	//get the var size
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//get the var size
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}

void test(string ans, string q)
{

    int input;

    cout << "......" << "\" " << q << " \"" << "\n\n";

    for(int i=0;i<l.size();i++)
    {
        cout << "(" << i+1 << ") " << l[i].f << "\n\n"; 
    }
    cout << "Your answer = ";

    cin >> input;

    if(l[input-1].s == 1){
        cout << "\n==== GOOD! ====";

        Sleep(1500);
        
        points++;

        system("cls");

        return;
    }

    else{
        cout << "==== WRONG! ====\n\n"; 

        cout << "The anser is => " << ans << "\n\n";    
            
    	Sleep(3000);
        
        int index = 0;
        
        if(q[0] <= 'Z' && q[0] >= 'A'){
        	index = q[0] - 'A';
		}
		
		else{
			index = q[0] - 'a';
		}
        
        unfamiliar[index].pb({q, ans});
        
        wrong = true;

        system("cls");

    }

  return;
}

// 出題演算法 
void game(int num)
{

    int now = 0, total = num;

    while(num--){
        
        now++;

        system("cls");
        l.clear();
        srand(time(NULL));

        cout << "     === " << now << '/' << total << " ===" << "\n\n";
        
        int question=0, MIN = 0, MAX = w.size()-1, r1,r2,r3;

        question = rand() % (MAX - MIN + 1) + MIN; // rand the index of w(vector)

        string q = w[question].f, a = w[question].s, b, c, d;
        
        swap(w[question], w[w.size()-1]);
        
        r1 = rand() % (MAX-1 - MIN + 1) + MIN;
        b = w[r1].s;
        swap(w[r1], w[w.size()-2]);

        r2 = rand() % (MAX-2 - MIN + 1) + MIN;
		c = w[r2].s;
		swap(w[r2], w[w.size()-3]);
		
        r3 = rand() % (MAX-3 - MIN + 1) + MIN;
        d = w[r3].s;

        l.pb({a, 1}); l.pb({b, 0}); l.pb({c, 0}); l.pb({d, 0}); // produce the questions.

        random_shuffle(l.begin(), l.end());

        test(a,q);

    }
    return;
}


void thank()
{
    
    cout << "---------------------------------------------------------\n\n";

    cout << "!!THANK you for playing the game. Hope you have a good day.\n\n";

    cout << "==========================================================\n\n";

    return;

}




signed main()
{
	points = 0;
	w.clear();
	for(int i=0;i<26;i++) unfamiliar[i].clear();
	
    string s, a, b;

    ifs.open("input.txt", std::ios::in);
   
    if(!ifs.is_open()) cout << "Fail to open the file\n";

    while(ifs >> a >> b)
    {    	
		string stra = UTF8ToGB(a.c_str()).c_str();
		string strb = UTF8ToGB(b.c_str()).c_str();
		
		w.pb({stra, strb});
	}
        
    ifs.close();

    game_instructions();

    int input;
    
    cout << "Please input the number: ";
    cin >> input;
    
    system("cls");

    if(input == 1){
        game_start(); 

        int num;

        cin >> num;

        game(num);
        
        cout << "==========================================================\n\n";
        
        cout << "Your points => " << points << "/" << num << "\n\n";
        
		if(wrong == true)
		{
			cout << "======   Unfamiliar Words   ======\n\n";
        
        	for(int i=0,t=1;i<26;i++){
        		for(int k=0;k<unfamiliar[i].size();++i){
        			cout << t << ". " << unfamiliar[i][k].f << ' ' << unfamiliar[i][k].s << "\n\n";
        			t++;
				}
			}
		}
		
		else{
			"GOOOOOOD!\n\n";
		}
    }
    
    
    else
    {
    	exit(0);
	}

    thank();
    
    system("pause");
    
    main();

    return 0;
}
