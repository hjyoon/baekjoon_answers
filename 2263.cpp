#include <iostream>

using namespace std;

int inorder[100000];
int postorder[100000];
int position[100001];

void solve(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) {
        return;
    }
    cout << "post_end = " << post_end << ' ' << '\n';
    int root = postorder[post_end];
    cout << root << ' ' << '\n';
    int p = position[root];
    cout << "p = " << p << ' ' << '\n';
    
    // inorder:   in_start p in_end
    // postorder: post_start post_end
    // left: p-in_start
    // right: in_end-p
    int left = p-in_start;
    solve(in_start, p-1, post_start, post_start + left - 1);
    solve(p+1, in_end, post_start+left, post_end-1);
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    for (int i=0; i<n; i++) {
        cin >> inorder[i];
    }

    for (int i=0; i<n; i++) {
        cin >> postorder[i];
    }

    for (int i=0; i<n; i++) {
        position[inorder[i]] = i;
    }

    solve(0, n-1, 0, n-1);

    return 0;
}