#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// 顺时针方向：上、右、下、左
const int dx_clockwise[4] = {0, 1, 0, -1};
const int dy_clockwise[4] = {-1, 0, 1, 0};

// 逆时针方向：上、左、下、右 
const int dx_counter[4] = {0, -1, 0, 1};
const int dy_counter[4] = {-1, 0, 1, 0};
void File(string s){
	freopen((s+".in").c_str(),"r",stdin);
	freopen((s+".out").c_str(),"w",stdout);
}
int main() {
//	File("line");
    int N, M, K;
    cin >> N >> M >> K;
    
    vector<vector<int>> ans(N, vector<int>(M, INT_MAX));
    
    for (int k = 0; k < K; k++) {
        int x, y, t;
        cin >> x >> y >> t;
        x--; y--; // 转换为0-based索引
        
        int step = 1;
        int cur_x = x, cur_y = y;
        int dir = 0; // 当前方向
        int step_size = 1; // 当前步长
        int step_count = 0; // 当前步长已走步数
        int dir_change_count = 0; // 方向改变次数
        
        // 记录起点
        if (cur_x >= 0 && cur_x < N && cur_y >= 0 && cur_y < M) {
            ans[cur_x][cur_y] = min(ans[cur_x][cur_y], step);
        }
        
        // 模拟移动，最多N*M步
        while (step < N * M) {
            // 选择方向数组
            const int* dx = (t == 0) ? dy_clockwise : dy_counter;
            const int* dy = (t == 0) ? dx_clockwise : dx_counter;
            
            // 在当前方向上移动step_size步
            for (int i = 0; i < step_size; i++) {
                cur_x += dx[dir];
                cur_y += dy[dir];
                step++;
                
                // 记录网格内的位置
                if (cur_x >= 0 && cur_x < N && cur_y >= 0 && cur_y < M) {
                    ans[cur_x][cur_y] = min(ans[cur_x][cur_y], step);
                }
                
                if (step >= N * M) break;
            }
            
            if (step >= N * M) break;
            
            // 改变方向
            dir = (dir + 1) % 4;
            dir_change_count++;
            
            // 每两次方向改变后增加步长
            if (dir_change_count == 2) {
                step_size++;
                dir_change_count = 0;
            }
        }
    }
    
    // 输出结果
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (ans[i][j] == INT_MAX) {
                cout << 0;
            } else {
                cout << ans[i][j];
            }
            if (j < M - 1) cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}
