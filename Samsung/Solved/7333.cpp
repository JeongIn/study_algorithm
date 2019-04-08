#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<deque>

using namespace std;

int N;
deque<int> w;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	�Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	//�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	//freopen("sample_input.txt", "r", stdin);
	cin >> T;
	/*
	���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N;

		vector<int> v;
		int tmp;
		for (int n = 0; n < N; n++) {
			cin >> tmp;
			v.push_back(tmp);
		}

		sort(v.begin(), v.end());

		for (int n = 0; n < N; n++) {
			w.push_back(v[n]);
			//printf("[%d]: %d\n", n, w[n]);
		}

		int move_cnt = 0;
		int box_cnt;
		int now_w;
		int box_sum;
		while (!w.empty()) {
			move_cnt++;
			now_w = w.back(); w.pop_back();
			box_sum = now_w;
			box_cnt = 1;

			while (box_sum < 50) {
				if (w.empty()) break;
				box_sum += now_w;
				w.pop_front();
			}
		}

		if (box_sum < 50)
			move_cnt--;

		printf("#%d %d\n", test_case, move_cnt);
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}