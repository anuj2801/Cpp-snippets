#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

void VerticalOrderPrintOfBT(vector<int> v,int Size,int rootIndex,int rootKey,map<int,vector<int>> &BT)// rootkey is the distance of nodes from actual root node of the tree(which is at 0,left roots are negative and right ones are positive)
{ if(rootIndex>=Size)
   return;
   BT[rootKey].push_back(v[rootIndex]);
   VerticalOrderPrintOfBT(v,Size,rootIndex*2+1,rootKey-1,BT);//left child
   VerticalOrderPrintOfBT(v,Size,rootIndex*2+2,rootKey+1,BT);//right child

   //printing after iteration of n nodes
   if(rootIndex==0)
   for(auto i:BT)
    { for(int j:i.second)
        cout<<j<<" ";
      cout<<endl;
    }
}

//Number of Subarrays with sum 0
int sumSubarrayZero(vector<int> v)
{
  map<int,int> freq;
  int prefixSum=0;
  freq[0]++; //since before starting sum is zero
  for(auto i:v)
  {
    prefixSum+=i;
    freq[prefixSum]++;
  }
  int ans=0;
  for(auto i:freq)
  {   int c=i.second;
      ans+=(c*(c-1))/2;    // if 5 ones are there ,subarrays can built=4+3+2+1 // between any two Ones,one subarray
  }
  return ans;
  
}

//Top k most freq elements(means freq of first k distinct elements in descending order) 
void TopKMostFreqElements(vector<int> v,int k)
{ //if(v.size())
  map<int,int> freq;
  for(auto i:v)
  { 
    if(freq.size()==k&&freq[i]==0)
    break;
    freq[i]++;
  }
  vector<pair<int,int>> ans;
  for(auto i:freq)
  {  if(i.second!=0)
    ans.push_back(make_pair(i.second,i.first));
  }
  sort(ans.begin(),ans.end(),greater<pair<int,int>>());
  for(auto i:ans)
  cout<<i.second<<"= "<<i.first<<endl;

}

//sudokuSolver
bool fillEmptySpaces(vector<vector<char>> &sudoku,vector<vector<map<int,int>>> &grid, vector<map<int,int>> &row,vector<map<int,int>> &column,int R,int C)
{ 
  if(R==9)
  return true; 
  if(sudoku[R][C]!='.')
    {
      if(C==8)
      return fillEmptySpaces(sudoku,grid,row,column,R+1,0);
      else
      return fillEmptySpaces(sudoku,grid,row,column,R,C+1);
    }
    bool TRY=false;
    for(int i=1;i<=9;i++)
    { if(TRY==true)
       break;
      
      if(grid[R/3][C/3][i]==0&&row[R][i]==0&&column[C][i]==0)
      {
        sudoku[R][C]=i+'0';
        grid[R/3][C/3][i]=1;
        row[R][i]=1;
        column[C][i]=1;
       if(C==8)
        TRY=fillEmptySpaces(sudoku,grid,row,column,R+1,0);
       else
        TRY=fillEmptySpaces(sudoku,grid,row,column,R,C+1);
          if(TRY==false)
          { sudoku[R][C]='.';
            grid[R/3][C/3][i]=0;
            row[R][i]=0;
            column[C][i]=0;
          }
       }
     }
     return TRY;  

}
bool solveSudoku(vector<vector<char>> &sudoku)
{
  vector<vector<map<int,int>>> grid(3,vector<map<int,int>>(3));
  vector<map<int,int>> row(9);
  vector<map<int,int>> column(9);
  for(int i=0;i<9;i++)
   for(int j=0;j<9;j++)
    if(sudoku[i][j]!='.')
    { char c=sudoku[i][j];
      int gridRow=i/3;
      int gridCol=j/3;
      grid[gridRow][gridCol][c-'0']=1;
      row[i][c-'0']=1;
      column[j][c-'0']=1;
    }
    return fillEmptySpaces(sudoku,grid,row,column,0,0);
}
void printSudoku(vector<vector<char>> sudoku)
{
  for(int i=0;i<9;i++)
  { for(int j=0;j<9;j++)
     cout<<sudoku[i][j]<<" ";
     cout<<endl;
  }
   cout<<endl;
}
vector<vector<char>> createSudoku()
{vector<vector<char>> sudoku(9,vector<char>(9));
 for(int i=0;i<9;i++)
  { cout<<"enter"<<i+1<<"th row";
    for(int j=0;j<9;j++)
     cin>>sudoku[i][j];  
  }
 return sudoku;
}

int main()
{
//    map<int,int> mp;
//    vector<int> v={1,5,6,3,3,5,7,1,6,9,2,3};
//    for(auto i:v)
//     mp[i]++;

   /// map<int,int> ::iterator it;
    // for(it=mp.begin();it!=mp.end();it++)
    //     cout<<(*it).first<<"->"<<it->second<<endl;
 
    // for(auto i:mp)
    // cout<<i.first<<"->"<<i.second<<endl;

// map<int,vector<int>> BT;
//  vector<int> vi={10,7,4,3,11,14,6};
//  VerticalOrderPrintOfBT(vi,vi.size(),0,0,BT);

// vector<int>vii={1,-1,1,-1};
// cout<<sumSubarrayZero(vii)<<endl;

// vector<int>v={1,2,2,2,3,3,2,1,4,5,7};
// TopKMostFreqElements(v,3);

//vector<vector<char>> sudoku=createSudoku();
// vector<vector<char>> sudoku={{'5','4','.','.','2','.','8','.','6'},
//                              {'.','1','9','.','.','7','.','.','3'},
//                              {'.','.','.','3','.','.','2','1','.'},
//                              {'9','.','.','4','.','5','.','2','.'},
//                              {'.','.','1','.','.','.','6','.','4'},
//                              {'6','.','4','.','3','2','.','8','.'},
//                              {'.','6','.','.','.','.','1','9','.'},
//                              {'4','.','2','.','.','9','.','.','5'},
//                              {'.','9','.','.','7','.','4','.','2'}};                         
// printSudoku(sudoku);
// if(solveSudoku(sudoku))
//  printSudoku(sudoku);
//  else
//  cout<<" Cant solve"<<endl;


   return 0;
}