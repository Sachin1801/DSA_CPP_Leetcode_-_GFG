//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();
};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())
        return;
   int temp = s.top();
   s.pop();
   sort();
   stack<int> s2;
   if(s.empty()){
       s.push(temp);
       return;
   }else{
       while(!s.empty() && s.top() > temp){
           s2.push(s.top());
           s.pop();
       }
       s.push(temp);
       while(!s2.empty()){
           s.push(s2.top());
           s2.pop();
       }
       return;
   }
   return;
   
}