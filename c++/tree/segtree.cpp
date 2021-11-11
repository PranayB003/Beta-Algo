#include <bits/stdc++.h>

#define nl << "\n"
#define mod 1000000007
#define int long long
#define debug(n) cout << #n << " : " << n << '\n'
#define debug2(n1,n2) cout << #n1 << " : " << n1 << "  " << #n2 << " : " << n2 << '\n'

using namespace std;

void parr(int *a, int n);
void pvect(vector<int> &a);
int mgcd(int a, int b);
// Segment Tree. See the function descriptions for respective documentations.
void segTree(vector<int> &a, vector<int> &tree, int vertex, int leftStoredIndex, int rightStoredIndex);
int get(vector<int> &tree, int vertex, int leftStoredIndex, int rightStoredIndex, int queryLeftLimit, int queryRightLimit);
void patch(vector<int> &tree, int vertex, int leftStoredIndex, int rightStoredIndex, int updateIndex, int updateValue);

void solve(signed testnum){
    int n; cout << "Enter array size : "; cin >> n;
    cout << "Enter array elements\n";
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cout << ">> "; cin >> a[i];
    }
    cout << "\nThe array is : ";
    pvect(a);
    vector<int> st(2*a.size());
    segTree(a, st, 1, 0, a.size()-1);
    cout << "Current segment tree : "; pvect(st); cout << "\n";
    int q; cout << "Enter the number of queries : "; cin >> q;
    cout << "Enter the queries :\ntype (a) : 1 i j (replace the element at index i by the value j)\n";
    cout << "type (b) : 2 i j (get a range query from index i to j (both inclusive))\n";
    for(int k = 0; k < q; k++){
        cout << ">> "; int qtype, i, j; cin >> qtype >> i >> j;
        if(qtype == 1){
            a[i] = j;
            patch(st, 1, 0, a.size()-1, i, j);
            cout << "updated array : "; pvect(a); cout << "\n";
        }
        else if(qtype == 2){
            cout << "result : " << get(st, 1, 0, a.size()-1, i, j) << "\n\n";
        }
    }
}

signed main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
    signed t;
    cin >> t;
    for(signed testnum = 1; testnum <= t; testnum++){
        solve(testnum);
    }

    return 0;
}

void parr(int *a, int n){
    for(int i = 0; i < n; i++){
        cout << a[i] << " ";
    }
    cout nl;
}
void pvect(vector<int> &a){
    for(int i = 0; i < a.size(); i++){
        cout << a[i] << " ";
    }
    cout nl;
}

int mgcd(int a, int b){
    return (a == 0)?(b):(mgcd(b%a, a));
}

void segTree(vector<int> &a, vector<int> &tree, int vertex, int leftStoredIndex, int rightStoredIndex){
    // usage : segTree(a, tree, 1, 0, a.size()-1);

    /* Pass the vectors 'a' (for which segment tree is to be built) and 'tree'
    (where the tree will be stored). Elements in tree = 2*(Elements in 'a')-1,
    but indexing in the tree starts from 1 (index '0' is empty), so 'tree'
    should have size = 2*(a.size()) */

    // note : modify the relation that the tree represents (sum, max, min, etc.)

    if(leftStoredIndex == rightStoredIndex)
        tree[vertex] = a[rightStoredIndex]; // base case
    else{
        int middleIndex = (leftStoredIndex + rightStoredIndex)/2;
        // this implementation uses a preorder numbering of the tree vertices
        segTree(a, tree, vertex+1, leftStoredIndex, middleIndex);
        // a segTree on 'n' elements will always have 2*n-1 vertices
        segTree(a, tree, vertex+2*(middleIndex-leftStoredIndex+1), middleIndex+1, rightStoredIndex);
        tree[vertex] = max(tree[vertex+1], tree[vertex+2*(middleIndex-leftStoredIndex+1)]);
    }
}

int get(vector<int> &tree, int vertex, int leftStoredIndex, int rightStoredIndex, int queryLeftLimit, int queryRightLimit){
    // usage : get(tree, 1, 0, a.size()-1, L, R) , (0 <= L,R <= a.size()-1)
    // note : modify the relation that the tree represents (sum, max, min, etc.)
    int middleIndex = (leftStoredIndex + rightStoredIndex)/2;
    if(leftStoredIndex==queryLeftLimit && rightStoredIndex==queryRightLimit)
        return tree[vertex];
    else if(queryRightLimit <= middleIndex)
        return get(tree, vertex+1, leftStoredIndex, middleIndex, queryLeftLimit, queryRightLimit);
    else if(queryLeftLimit >= middleIndex+1)
        return get(tree, vertex+2*(middleIndex-leftStoredIndex+1), middleIndex+1, rightStoredIndex, queryLeftLimit, queryRightLimit);
    else
        return max(get(tree, vertex+1, leftStoredIndex, middleIndex, queryLeftLimit, middleIndex), get(tree, vertex+2*(middleIndex-leftStoredIndex+1), middleIndex+1, rightStoredIndex, middleIndex+1, queryRightLimit));
}

void patch(vector<int> &tree, int vertex, int leftStoredIndex, int rightStoredIndex, int updateIndex, int updateValue){
    // usage : get(tree, 1, 0, a.size()-1, ind, val) , (0 <= ind <= a.size()-1)
    // note : modify the relation that the tree represents (sum, max, min, etc.)
    if(leftStoredIndex == rightStoredIndex)
        tree[vertex] = updateValue;
    else{
        int middleIndex = (leftStoredIndex + rightStoredIndex)/2;
        if(updateIndex <= middleIndex)
            patch(tree, vertex+1, leftStoredIndex, middleIndex, updateIndex, updateValue);
        else if(updateIndex >= middleIndex)
            patch(tree, vertex+2*(middleIndex-leftStoredIndex+1), middleIndex+1, rightStoredIndex, updateIndex, updateValue);
        tree[vertex] = max(tree[vertex+1], tree[vertex+2*(middleIndex-leftStoredIndex+1)]);
    }
}
