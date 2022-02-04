class Solution {
public:
    bool judge_num(int i, int j, int k){
        
        //cout << "i: " << i << "j: " << j;
        int res = 0;
        while(i!=0){
            res += i%10;
            i /= 10;
        }
        while(j!=0){
            res += j % 10;
            j /= 10;
        }
        //cout << "res: " << res<<  endl;
        if (res <= k) return true;
        return false;
    }
    int movingCount(int m, int n, int k) {
        int res = 1; 
        vector<vector<int>> vis(m, vector<int>(n,0));
        //一下的遍历方式是不行的，需要用到bfs判断连通性
        // for(int i = 0; i < m; i++){
        //     for(int j = 0; j<n ;j++){
        //         if(judge_num(i,j,k)) res += 1;
        //     }
        // }

        //需要用到bfs判断连通性
        int dx[] = {0,1};
        int dy[] = {1,0};
        queue<pair<int,int>> q;
        vis[0][0] = true;
        q.push(make_pair(0,0));
        int xx = 0; 
        int yy = 0;
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            for(int i = 0; i< 2;i++){
                xx = x + dx[i];
                yy = y + dy[i];
                if(xx < 0|| xx >= m || yy < 0 || yy >= n) continue;
                if(!judge_num(xx,yy,k)) continue;
                if(vis[xx][yy] == 0) {
                    q.push(make_pair(xx,yy));
                    vis[xx][yy] = 1;
                    res += 1;
                }
            }
        }
        return res;
    }
};