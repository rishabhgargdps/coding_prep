//if the order of nodes is messed up i.e. parent[i] < i does not hold true always
//int up[N][LOG]
//up[v][j] = 2^j-th ancestor of v
//for v = 0 .. N-1:
//  up[v][0] = parent[v]
//for(int j = 1 .. LOG-1) :
// for(int v = 0 .. N-1) :
//  up[v][j] = up[up[v][j-1]][j-1]

//if the order remains:
//for v = 0 .. N-1:
// up[v][0] = parent[v];
// for j = 1 .. LOG-1:
//  up[v][j] = up[up[v][j-1]][j-1]

#define vi vector<int>
#define vvi vector<vi>
class TreeAncestor {
public:
    vvi bl;
    TreeAncestor(int n, vector<int>& p) {
        bl = vvi (n, vi(20, -1));
        
        for(int i = 0; i < n; ++i)
            bl[i][0] = p[i];
        
        for(int i = 1; i < 20; ++i){
            for(int j = 0; j < n; ++j){
                int x = bl[j][i-1];
                if(x != -1) bl[j][i] = bl[x][i-1];
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        int anc = node;
        while(k){
            for(int i = 19; i >= 0; --i){
                int r = 1 << i;
                if(k >= r) k -= r, anc = bl[anc][i];
                if(anc == -1) return anc;
            }
        }
        return anc;
    }
};
/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */