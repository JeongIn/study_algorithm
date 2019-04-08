#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dx[8] = { 0, 1, 0, -1, -1, -1, 1, 1 };
int dy[8] = { 1, 0, -1, 0, 1, -1, -1, 1 };

int N, M, K;
vector<int> tree[10][10]; // �� ��ǥ�� �������� ���� ����
int food[10][10]; // ��� �� ����
int add_food[10][10];

/*
//// food �ʱ� ��: 5
1. ��
����� �԰� ������ ���̰� 1 �����Ѵ�.
���̰� � �������� ����� �Դ´�.
�ڽ��� ���̸�ŭ ����� �� ������ ������ �״´�.
2. ����
���� ������ ������� ���Ѵ� (��� �� = ���� / 2)
3. ����
�����Ѵ� (���� ���̰� 5�� ���)
4. �ܿ�
��� �߰�
*/

int compare(int a, int b) {
	return (a < b);
}

void spring_summer() {
	int tree_size;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			tree_size = tree[x][y].size();

			int cur_year;
			int die = tree_size;
			for (int t = 0; t < tree_size; t++) {
				cur_year = tree[x][y][t];
				if (food[x][y] >= cur_year) {
					tree[x][y][t]++;
					food[x][y] -= cur_year;
				}
				else {
					for (int d = t; d < tree_size; d++) {
						food[x][y] += (tree[x][y].back() / 2);
						tree[x][y].pop_back();
					}
					break;
				}
			}
		}
	}
}

void fall() {
	int nx, ny;
	int tree_size;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			tree_size = tree[x][y].size();
			for (int t = 0; t < tree_size; t++) {
				if (tree[x][y][t] % 5 == 0) {
					for (int i = 0; i < 8; i++) {
						nx = x + dx[i]; ny = y + dy[i];

						if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

						tree[nx][ny].push_back(1);
					}
				}
			}
		}
	}
}

void winter() {
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			food[x][y] += add_food[x][y];
			sort(tree[x][y].begin(), tree[x][y].end(), compare);
		}
	}
}

int main() {
	// baekjoon 16235

	scanf("%d %d %d", &N, &M, &K);
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			scanf("%d", &add_food[x][y]);
			food[x][y] = 5;
		}
	}

	int x, y, z;
	for (int m = 0; m < M; m++) {
		scanf("%d %d %d", &x, &y, &z);
		tree[x - 1][y - 1].push_back(z);
	}

	for (int k = 0; k < K; k++) {
		spring_summer();
		fall();
		winter();
	}

	int cnt = 0;
	for (int x = 0; x < N; x++) {
		for (int y = 0; y < N; y++) {
			cnt += tree[x][y].size();
		}
	}

	printf("%d\n", cnt);

	getchar();
	getchar();

	return 0;
}