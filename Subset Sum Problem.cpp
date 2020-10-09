/*

Subset Sum Problem

Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
Example:

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 9
Output: True  
There is a subset (4, 5) with sum 9.

Input: set[] = {3, 34, 4, 12, 5, 2}, sum = 30
Output: False
There is no subset that add up to 30.

*/


// Recursive solution


vector<int> tmp;

bool findSet(vector<int> &v, int sum, int index) {
    if(sum == 0) {
        for(int i=0; i<tmp.size(); i++)
            cout<<tmp[i]<<" ";
        cout<<"\n";
        return true;
    }
    if(sum < 0 || index >= v.size()) return false;
    for(int i=index; i<v.size(); i++){
        tmp.push_back(v[i]);
        if(findSet(v, sum - v[i], i+1))
            return true;
        tmp.pop_back();
    }
    return false;
}
int main() {
    vector<int> v{3, 34, 4, 12, 5, 2};
    int sum = 14;
    if(findSet(v, sum, 0)){
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    return 0;
}

// output
// 3 4 5 2 
// Yes
