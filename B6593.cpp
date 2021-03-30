#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

char build[31][31][31];
int visited[31][31][31];
int dx[6] = {1, 0, -1, 0, 0, 0};
int dy[6] = {0, 1, 0, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
void solve(int z, int x, int y, char bd[31][31][31], int l, int r, int c)
{

    queue<pair<int, pair<int, int> > > q;
    q.push(make_pair(x, (make_pair(y, z))));
    visited[x][y][z] = 0;
    while (!q.empty())
    {

        int cr = q.front().first;
        int cc = q.front().second.first;
        int cl = q.front().second.second;
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            int nr = cr + dx[i];
            int nc = cc + dy[i];
            int nl = cl + dz[i];
            if (0 <= nr && nr < r && 0 <= nc && nc < c && 0 <= nl && nl < l)
            {
                if (visited[nr][nc][nl] != -1)
                    continue;
                if (bd[nr][nc][nl] == '#')
                    continue;
                visited[nr][nc][nl] = visited[cr][cc][cl] + 1;
                q.push(make_pair(nr, (make_pair(nc, nl))));
            }
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1)
    {
        int l, r, c;
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            return 0;
        int s_r = -1, e_r = -1;
        int s_c = -1, e_c = -1;
        int s_l = -1, e_l = -1;
        for (int k = 0; k < l; k++)
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    char s;
                    cin >> s;
                    if (s == 'S')
                    {
                        s_r = i;
                        s_c = j;
                        s_l = k;
                    }
                    if (s == 'E')
                    {
                        e_r = i;
                        e_c = j;
                        e_l = k;
                    }
                    build[i][j][k] = s;
                    visited[i][j][k] = -1;
                }
            }
        }
        solve(s_l, s_r, s_c, build, l, r, c);
        if (visited[e_r][e_c][e_l] == -1)
            cout << "Trapped!\n";
        else
            cout << "Escaped in " << visited[e_r][e_c][e_l] << " minute(s).\n";
    }
}