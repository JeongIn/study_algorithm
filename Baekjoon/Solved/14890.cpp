#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, L;
int board[100][100];
int ans;

int check_row(int idx, int row[100], int check[100])
{
	if (idx >= N - 1)
	{
		return 1;
	}

	if (idx < N - 1)
	{
		if (row[idx] == row[idx + 1]) // ���� ���� ��
		{
			return check_row(idx + 1, row, check);
		}
		else if (row[idx] == row[idx + 1] + 1) // �������� �� ĭ ���� ��
		{
			for (int i = 2; i <= L; i++)
			{
				if (i + idx >= N)
					return 0;

				if (row[idx + i] != row[idx + 1])
					return 0;
			}

			for (int i = 1; i <= L; i++)
			{
				check[idx + i] = 1;
			}

			return check_row(idx + L, row, check);
		}
		else if (row[idx] == row[idx + 1] - 1) // �������� �� ĭ ���� ��
		{
			for (int i = 0; i < L; i++)
			{
				if (idx - i < 0)
					return 0;

				if (check[idx - i] == 1)
					return 0;

				if (row[idx - i] != row[idx])
					return 0;
			}

			for (int i = 0; i < L; i++)
			{
				check[idx - i] = 1;
			}

			return check_row(idx + 1, row, check);
		}
		else
		{
			return 0;
		}
	}
}

int check_col(int row, int idx, int col[][100], int check[100])
{
	if (idx >= N - 1)
	{
		return 1;
	}

	if (idx < N - 1)
	{
		if (col[idx][row] == col[idx + 1][row]) // ���� ���� ��
		{
			return check_col(row, idx + 1, col, check);
		}
		else if (col[idx][row] == col[idx + 1][row] + 1) // �Ʒ����� �� ĭ ���� ��
		{
			for (int i = 2; i <= L; i++)
			{
				if (i + idx >= N)
					return 0;

				if (col[idx + i][row] != col[idx + 1][row])
					return 0;
			}

			for (int i = 1; i <= L; i++)
			{
				check[idx + i] = 1;
			}

			return check_col(row, idx + L, col, check);
		}
		else if (col[idx][row] == col[idx + 1][row] - 1) // �Ʒ����� �� ĭ ���� ��
		{
			for (int i = 0; i < L; i++)
			{
				if (idx - i < 0)
					return 0;

				if (check[idx - i] == 1)
					return 0;

				if (col[idx - i][row] != col[idx][row])
					return 0;
			}

			for (int i = 0; i < L; i++)
			{
				check[idx - i] = 1;
			}

			return check_col(row, idx + 1, col, check);
		}
		else
		{
			return 0;
		}
	}
}

int main()
{
	// baekjoon 14890

	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &board[i][j]);
		}
	}

	for (int i = 0; i < N; i++)
	{
		int check_r[100] = { 0, };
		int check_c[100] = { 0, };

		ans += check_row(0, board[i], check_r);
		ans += check_col(i, 0, board, check_c);
	}

	printf("%d\n", ans);

	getchar();
	getchar();

	return 0;
}