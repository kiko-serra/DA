#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int editDistance(string x, string y){
    int dp[x.size()+1][y.size()+1];
    int value=0;
    for (size_t i = 0; i < x.size()+1; i++)
        dp[i][0]=i;
    for (size_t j = 0; j < y.size()+1; j++)
        dp[0][j]=j;
    for (size_t i = 1; i < x.size()+1; i++) {
        for (size_t j = 1; j < y.size()+1; j++) {
            if (x[i]==y[j])
                value=0;
            else
                value=1;
            dp[i][j]= min(min(dp[i-1][j-1]+value, dp[i-1][j]+1), dp[i][j-1]+1);
        }
    }
    for (size_t i = 0; i < x.size(); i++) {
        for (size_t j = 0; j < y.size(); j++) {
            cout << dp[i][j] << endl;
        }

    }
    return dp[x.size()][y.size()];
}

void nearest(string filename, string x, int k, vector<pair<int, string> > &result){
    ifstream in(filename);

    if (!in.is_open()) return;
    vector<pair<int, string> > total;
    for (string line; getline(in, line);) {
        total.push_back(make_pair(editDistance(x, line), line));
    }
    sort(total.begin(), total.end());
    for (int i = 0; i < k; i++) {
        result.push_back(make_pair(total[i].first, total[i].second));
        cout << total[i].first << " ze "<<total[i].second<< endl;
        in.close();
    }
}
int main(){
    string s1 = "sunday";
    vector<pair<int, string> > result;
    cout << editDistance("sunday", "monday") << endl;
    nearest("../TP9/filename.txt", s1, 7, result);
    return 0;
}