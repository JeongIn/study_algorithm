/////////////////////////////////////////////////////////////////////////////////////////////
// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
// ǥ�� �Է� ����
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            // int ���� 1�� �Է¹޴� ����
// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
// cin >> g;                            // char ���� 1�� �Է¹޴� ����
// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
/////////////////////////////////////////////////////////////////////////////////////////////
// ǥ�� ��� ����
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           // int ���� 1�� ����ϴ� ����
// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
// cout << g;                           // char ���� 1�� ����ϴ� ����
// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
// cout << AB;                          // long long ���� 1�� ����ϴ� ����
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int char_to_int(char c)
{
	int ans;
	if (c >= 'A' && c <= 'F')
	{
		ans = c - 'A' + 10;
	}
	else if (c >= '0' && c <= '9')
	{
		ans = c - '0';
	}

	return ans;
}

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
	//freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, K;
		string hex_val;
		char num[28];

		cin >> N >> K;
		cin >> hex_val;

		for (int i = 0; i < N; i++)
		{
			num[i] = char_to_int(hex_val[i]);
		}

		vector<int> find;
		int tmp = 0;
		for (int i = 0; i < N / 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				for (int k = 0; k < N / 4; k++)
				{
					tmp += num[(4 * i + j + k) % N] * pow(16, N / 4 - k - 1);
				}

				int flag = false;
				for (int v = 0; v < find.size(); v++)
				{
					if (find[v] == tmp)
						flag = true;
				}

				if (flag == false)
					find.push_back(tmp);

				tmp = 0;
			}
		}

		sort(find.begin(), find.end());

		cout << "#" << test_case << " " << find[find.size() - K] << "\n";
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}