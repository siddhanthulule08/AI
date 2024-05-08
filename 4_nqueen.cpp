#include <iostream>
using namespace std;
class Queen
{
    public:
        int NQueen(int r ,int n);
        int x[20],count=0;
        int place(int  r,int c);
        int display(int n);
};
int Queen::place(int r, int c)
{
    int i;
    for(i = 1; i <= r - 1; i++)
    {
        if(x[i] == c) // Checks for the same column
        {
            return 0;
        }
        else
        {
            if(abs(x[i] - c) == abs(i - r)) // Checks for the same diagonal
            {
                return 0;
            }
        }
    }
    return 1; // Returns 1 if no conflicts found
}
int Queen::NQueen(int r, int n)
{
    int c, i;
    for(c = 1; c <= n; c++)
    {
        if(place(r, c)) // Checks if it's safe to place a queen at (r, c)
        {
            x[r] = c; // Places the queen at (r, c)
            if(r == n) // If all queens are placed
            {
                display(n); // Display the solution
            }
            else // Recursively call NQueen for the next row
            {
                NQueen(r + 1, n);
            }
        }
    }
    return 0;
}
int Queen::display(int n)
{
    int i,j;
    cout<<"\n\nSolution\n\n"<<++count;
    for(i=1;i<=n;i++)
    {
        cout<<"\t"<<i;
    }
    for(i=1;i<=n;i++)
    {
        cout<<"\n"<<i;
                for(j=1;j<=n;j++)
                {
                    if(x[i]==j)
                        cout<<"\t Q";
                    else
                        cout<<"\t -";
                }

    }
    return 0;
}
int main() 
{
    Queen q1;
	int i,j,n,r;
    cout<<"------------------\n";
    cout<<" N-Queen Solution \n";
    cout<<"------------------\n";
    cout<<" Enter the Queen: ";
    cin>>n;
    q1.NQueen(1,n);

	return(0);
}

