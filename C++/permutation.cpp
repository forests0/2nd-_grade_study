#include <iostream>
#include <vector>
using namespace std;
void printperm(vector<int> li)
{
    for (int i = 0; i < li.size(); i++)
    {
        cout << li[i] << " ";
    }
    cout << endl;
}
void perm(int r,vector<int> per, vector<int> rem)
{
    if(per.size() == r) {
        printperm(per);
        return ;

    }
    for(int i = 0; i < rem.size(); i++) {
        vector<int> remcopy = rem;
        per.push_back(rem[i]);
        remcopy.erase(remcopy.begin()+i);
        perm(r, per,remcopy);
        per.pop_back();
    }
}

int main()
{
    int num, r;
    cin >> num>> r;
    vector<int> list;
    for (int i = 1; i <= num; i++)
    {
        list.push_back(i);
    }
    perm(r, vector<int> (), list);
    return 0;
}