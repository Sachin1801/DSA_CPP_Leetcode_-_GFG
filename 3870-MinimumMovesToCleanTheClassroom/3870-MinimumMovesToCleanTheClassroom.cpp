// Last updated: 12/14/2025, 4:15:10 PM
#include <bits/stdc++.h>
using namespace std;

struct Node{
    uint8_t x, y;         // 0 … 19
    uint8_t e;            // 0 … 50
    uint16_t mask;        // up to 10 bits
};

class Solution {
public:
    int minMoves(vector<string>& classroom, int E) {
        const int m = classroom.size();
        const int n = classroom[0].size();
        vector<pair<int,int>> litter;                     // store L positions
        int sx=-1, sy=-1;

        /* -------- collect coordinates -------- */
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j){
                if (classroom[i][j]=='S'){ sx=i; sy=j; }
                else if (classroom[i][j]=='L') litter.push_back({i,j});
            }

        const int L = litter.size();
        const uint16_t FULL = (1u<<L)-1;

        /* map (i,j) -> index in litter list, or -1 */
        int id[20][20]; memset(id,-1,sizeof(id));
        for (int k=0;k<L;++k) id[litter[k].first][litter[k].second]=k;

        /* -------- visited bitmap --------
           dim: m * n *  (1<<L) * (E+1)
           we pack (mask * (E+1) + e) into one dimension */
        const int EN = E+1;
        const int MASKN = 1<<L;
        vector<vector<vector<uint64_t>>> vis(m, vector<vector<uint64_t>>(n,
            vector<uint64_t>((MASKN*EN + 63)>>6, 0)));

        auto seen = [&](int x,int y,int mask,int e){
            size_t idx = mask*EN + e;
            size_t word = idx>>6, bit = idx & 63;
            uint64_t &w = vis[x][y][word];
            if (w>>bit & 1ull) return true;
            w |= 1ull<<bit;
            return false;
        };

        queue<Node> q;
        seen(sx,sy,0,E);
        q.push({(uint8_t)sx,(uint8_t)sy,(uint8_t)E,0});
        int moves = 0;

        const int dx[4]={1,-1,0,0}, dy[4]={0,0,1,-1};

        while (!q.empty()){
            int qs = q.size();
            while (qs--){
                Node cur = q.front(); q.pop();
                if (cur.mask == FULL) return moves;

                for (int dir=0;dir<4;++dir){
                    int nx = cur.x + dx[dir];
                    int ny = cur.y + dy[dir];
                    if (nx<0||nx>=m||ny<0||ny>=n) continue;
                    char cell = classroom[nx][ny];
                    if (cell=='X') continue;

                    int ne = cur.e - 1;
                    if (cell=='R') ne = E;               // recharge
                    int nmask = cur.mask;
                    int idxL = id[nx][ny];
                    if (idxL!=-1) nmask |= 1u<<idxL;

                    /* allow finishing with e==0 but nowhere else */
                    if (ne==0 && cell!='R' && nmask!=FULL) continue;

                    if (!seen(nx,ny,nmask,ne))
                        q.push({(uint8_t)nx,(uint8_t)ny,(uint8_t)ne,(uint16_t)nmask});
                }
            }
            ++moves;
        }
        return -1;
    }
};
