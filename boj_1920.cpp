	#include <iostream>
	#include <algorithm>

	int main()
	{
		int n, m;
		int v[100001];

		scanf("%d", &n);
		for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
		scanf("%d",&m);

		std::sort(v, v + n);

		for (int t = 0; t < m; ++t)
		{
			int ans = 0;
			int target;
			scanf("%d", &target);

			int left, mid, right;

			left = 0;
			right = n - 1;
			mid = (left + right) / 2;

			while(left <= right)
			{
				//std::cout << "target: " << target << '\n';
				//std::cout << "v[mid]: " << v[mid] << '\n';
				if (v[mid] == target)
				{
					ans = 1;
					break;
				}

				if (v[mid] > target)
					right = mid - 1;
				else
					left = mid + 1;

				mid = (right + left) / 2;
			}

			printf("%d\n", ans);
		}
	}
