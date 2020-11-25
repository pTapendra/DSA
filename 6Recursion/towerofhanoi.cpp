//solve tower of hanoi for N discs
#include<iostream>
using namespace std;
void move(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        cout<< "Move disk 1 from rod " <<from<< " to rod "<<to<<endl;
        return;
    }
    else
    {
        move(n - 1,from,aux,to);
        cout<< "Move disk " << n << " from rod "<<from<< " to rod "<<to<< endl;
        move(n - 1,aux,to,from);

    }

}
int main()
{
    int n;
    cout<<"Enter number of disks: "<<endl;
    cin>>n;
    move(n, 'A', 'C', 'B'); 
    return 0;
}
