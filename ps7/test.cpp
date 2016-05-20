#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct coordinate_type{
    int x;
    int y;
};
coordinate_type pos[1001];
double Dis[1001][1001];

int main()
{
    int N, Case = 1;
    while (scanf("%d", &N) && N) {
        // Input
        for (int i = 1; i <= N; ++i)
            scanf("%d %d", &pos[i].x, &pos[i].y);

        // Initialize Distance
        for (int i = 1; i <= N; ++i)
            for (int j = i + 1; j <= N; ++j)
                Dis[i][j] = Dis[j][i] = sqrt(pow(pos[i].x - pos[j].x, 2) + pow(pos[i].y - pos[j].y, 2));

        // Floyd Algorithm
        for (int k = 1; k <= N; ++k)
            for (int i = 1; i <= N; ++i)
                for (int j = 1; j <= N; ++j)
                    Dis[i][j] = min(Dis[i][j], max(Dis[i][k], Dis[k][j]));

        // Output
        printf("Scenario #%d\n", Case++);
        printf("Frog Distance = %.3f\n\n", Dis[1][2]);
    }
}
