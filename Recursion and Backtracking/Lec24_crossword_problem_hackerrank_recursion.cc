#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define vc vector<char>
#define vcc vector<vector<char>>
#define endl "\n"

bool flag = false;

void fastio(bool read = false) {
	if(read) {
		#ifndef ONLINE_JUGDE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
		#endif	
	}
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	return;
}

class cell {
public:
	int row,col;
	cell(const int row,const int col) {
		this->row = row;
		this->col = col;
	}
};

cell* getNextCell(vcc puzzle,int row,int col) {
	for(int r = row; r >=0; r--) {
   		for(int c = 0; c< 10; c++) {
        	if(r == row && c >= col && puzzle[r][c] == '-')
            	return new cell(r,c);
         	else if (r < row && puzzle[r][c] == '-')
            	return new cell(r,c);
    	}
 	}
    return NULL;
}

void printPuzzle(vcc puzzle) {
	if(flag) {
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < 10; ++j) {
				if(puzzle[i][j] == '+') cout << "X";
				else cout << puzzle[i][j];
			}
			cout << endl;
		}
	} else {
		for(int i = 0; i < 10; ++i) {
			for(int j = 0; j < 10; ++j) {
				cout << puzzle[i][j];
			}
			cout << endl;
		}
	}
}

bool canDownFit(vcc puzzle,int row,int col,string s) {
	for(int r = row; r < 10 and r < (row + s.length()); r++) 
        if(puzzle[r][col] != '-' and puzzle[r][col] != s[r-row])
            return false;
    return true;	
}


void downFit(vcc &puzzle,int row,int col,string s) {
	for(int r = row; r < 10 and r < (row + s.length()); r++){
    	puzzle[r][col] = s[r-row];
    } 
}


bool canRightFit(vcc puzzle, int row, int col, string s) {
    for(int c = col; c < 10 and c < col + s.length(); c++) 
        if(puzzle[row][c] != '-' and puzzle[row][c] != s[c-col])
            return false;
    return true;
}


void rightFit(vcc&puzzle,int row,int col,string s) {
    for(int c = col; c < 10 and c < col + s.length(); c++) 
        puzzle[row][c] = s[c-col];
}

int getLeftStartCol(vcc puzzle, int row, int col) {
    while(col >=0 and puzzle[row][col] != '+') 
        col--;
    return col+1;
}

int getUpStartRow(vcc puzzle, int row, int col) {
    while(row >= 0 and puzzle[row][col] != '+')
        row--;
    return row+1;
}

int getDownEmptyCellsCount(vcc puzzle, int row, int col) {
    int count = 0;
    while(row < 10 and puzzle[row][col] != '+') {
        count++;
        row++;
    }
    return count;
}

int getRHSEmptyCellsCount(vcc puzzle, int row, int col) {
    int count = 0;
    while(col < 10 and puzzle[row][col] != '+') {
        count++;
        col++;
    }
    return count;
}

vcc copyPuzzle(vcc puzzle)
{
    vcc puzzleCopy(10,vc(10,' '));
    for(int r = 9; r >=0; r--) {
        for(int c = 0; c < 10; c++) {
            puzzleCopy[r][c] = puzzle[r][c];
        }
    }
    return puzzleCopy;
}

set<string> copySet(set<string> s1,string s) {
	set<string> res;
	for(auto str : s1) 
		if(s != str) 
			res.insert(str);
	return res;
}


void completeThePuzzleHelper(vcc puzzle,set<string> s,int row,int col) {
	if(puzzle[row][col] == '-') {
		int rCount = getRHSEmptyCellsCount(puzzle, row, col);
        int lStart = getLeftStartCol(puzzle, row, col);
		int size = (col == lStart) ? rCount : rCount+ (col - lStart);
		if(size > 1) {
			for(string str : s) {
				if(size == str.length() and canRightFit(puzzle,row,lStart,str)) {
					// create the copy of puzzle.
					vcc pCopy = copyPuzzle(puzzle);
					set<string> lcopy = copySet(s,str);
					rightFit(pCopy,row,lStart,str);
					cell *nxtCell = getNextCell(pCopy,row,col);
					if(nxtCell == NULL) {
						printPuzzle(pCopy);
						return;
					} else {
						completeThePuzzleHelper(pCopy,lcopy,nxtCell->row,nxtCell->col);
					}
				}
			}
		} else {
			int dCount = getDownEmptyCellsCount(puzzle, row+1, col);
          	int uStart = getUpStartRow(puzzle, row, col);	
			int size = (row == uStart) ? dCount : dCount+(row-uStart+1);
			for(auto str : s) {
				if(size == str.length() and canDownFit(puzzle,uStart,col,str)) {
					// create the copy of puzzle.
					vcc pCopy = copyPuzzle(puzzle);
					set<string> lcopy = copySet(s,str);
					downFit(pCopy,uStart,col,str);
					cell *nxtCell = getNextCell(pCopy,row,col);
					if(nxtCell == NULL) {
						printPuzzle(pCopy);
						return;
					} else {
						completeThePuzzleHelper(pCopy,lcopy,nxtCell->row,nxtCell->col);
					}
				}
			}
		}
	}
}

void completeThePuzzle(vcc puzzle, set<string> s){
    for(int r = 9; r >= 0; r--) 
    for(int c = 0; c < 10; c++) 
    if(puzzle[r][c] != '+') {
    	completeThePuzzleHelper(puzzle, s, r, c);
       	return;
    }               
}

set<string> genrateMapping() {
	char city[100];
	cin >> city;
	char*str = strtok(city,";");
	vector<string> cities;
	while(str != NULL) {
		string s(str);
		cities.push_back(s);
		str = strtok(NULL,";");
	}
	set<string> list;
	for(string s : cities) {
		list.insert(s);
	}
	return list;
}

int main() {
	fastio(true);
	vcc puzzle(10,vc(10,' '));
	for(int i = 0; i < 10; ++i) {
		for(int j = 0; j < 10; ++j) {
			char ch;
			cin >> ch;
			if(!flag and ch == 'X') flag = true;
			if(ch == 'X' or ch == '+')
				puzzle[i][j] = '+';
			else puzzle[i][j] = '-';
		}
	}
	set<string> s = genrateMapping();
	completeThePuzzle(puzzle,s);
	return 0;
}

// Sample Input :

// XXXXXX-XXX
// XX------XX
// XXXXXX-XXX
// XXXXXX-XXX
// XXX------X
// XXXXXX-X-X
// XXXXXX-X-X
// XXXXXXXX-X
// XXXXXXXX-X
// XXXXXXXX-X
// ICELAND;MEXICO;PANAMA;ALMATY

// ++++++++++ 		
// +------+++ 		
// +++-++++++ 		
// +++-++++++ 		
// +++-----++ 		
// +++-++-+++ 		
// ++++++-+++ 		
// ++++++-+++ 		
// ++++++-+++ 		
// ++++++++++
// POLAND;LHASA;SPAIN;INDIA

// Sample Output :

// XXXXXXIXXX
// XXMEXICOXX
// XXXXXXEXXX
// XXXXXXLXXX
// XXXPANAMAX
// XXXXXXNXLX
// XXXXXXDXMX
// XXXXXXXXAX
// XXXXXXXXTX
// XXXXXXXXYX

// ++++++++++
// +POLAND+++
// +++H++++++
// +++A++++++
// +++SPAIN++
// +++A++N+++
// ++++++D+++
// ++++++I+++
// ++++++A+++
// ++++++++++