//#include <iostream>
//#include <vector>
//#include <random>
//#include <algorithm>
//#include <chrono>
//#include <fstream>
//#include <string>
//// 兼容处理：如果编译器不支持C++17，注释掉filesystem相关代码
//#if __cplusplus >= 201703L || (_MSVC_LANG >= 201703L)
//#include <filesystem>
//namespace fs = std::filesystem;  // 简化命名
//#endif
//
//// ===================== 可自定义参数 ======================
//#define DEFAULT_N 10          
//#define W1_MIN 1              
//#define int long long         // 注意：这里定义int为long long，需确保所有类型兼容
//#define W1_MAX 1000000000ll             
//#define W2_MIN 1             
//#define W2_MAX 1000000000ll             
//// 路径：确保data1文件夹已创建（桌面→新建文件夹，命名为data1）
//#define DEFAULT_FILENAME "C:\\Users\\llall\\Desktop\\data1\\test_"  
//// =========================================================
//
//using namespace std;
//
//struct Edge {
//	int u, v;
//	int w1, w2;
//};
//
//// dfs函数：无逻辑问题，保留
//int dfs(int u, int fa, vector<vector<int>>& g, vector<bool>& vis) {
//	int ans = 1;
//	vis[u] = 1;
//	for (auto v : g[u]) {
//		if (v != fa) {
//			ans += dfs(v, u, g, vis);
//		}
//	}
//	return ans;
//}
//
//// 修复：solve函数返回结果（不再直接cout），方便写入文件
//int solve(int n, vector<Edge>a) {
//	vector<vector<int>>g(n + 1);
//	vector<bool>vis(n + 1, false);
//	int mx = -1;
//	for (auto v : a) {
//		mx = max(v.w1 + v.w2, mx);
//	}
//	for (auto v : a) {
//		if (v.w1 + v.w2 != mx) {
//			g[v.u].push_back(v.v);
//			g[v.v].push_back(v.u);
//		}
//	}
//	int ans = n * n;
//	for (int i = 1; i <= n; i++) {
//		if (!vis[i]) {
//			int tmp = dfs(i, 0, g, vis);
//			ans -= tmp * tmp;
//		}
//	}
//	return ans;  // 返回计算结果，而非直接输出
//}
//
//signed main() {
//	int test = 0;
//	cout << "请输入测试用例组数：";
//	cin >> test;
//
//	// 初始化随机数引擎（仅初始化一次，保证随机性）
//	unsigned seed = chrono::system_clock::now().time_since_epoch().count();
//	mt19937 rng(seed);
//
//	// 定义边权分布（移到循环外，避免重复初始化）
//	uniform_int_distribution<int> w1_dist(W1_MIN, W1_MAX);
//	uniform_int_distribution<int> w2_dist(W2_MIN, W2_MAX);
//
//	for (int t = 1; t <= test; t++) {
//		int n;
//		// 手动输入节点数
//		cout << "请输入第" << t << "组用例的节点数n：";
//		cin >> n;
//
//		// 生成树的边
//		vector<Edge> edges;
//		for (int v = 2; v <= n; ++v) {
//			uniform_int_distribution<int> u_dist(1, v - 1);
//			int u = u_dist(rng);
//			int w1 = w1_dist(rng);
//			int w2 = w2_dist(rng);
//			edges.push_back({ u, v, w1, w2 });
//		}
//
//		// 打乱边的顺序
//		shuffle(edges.begin(), edges.end(), rng);
//
//		// 1. 拼接.txt文件名（存储树的边数据）
//		string txt_filename = string(DEFAULT_FILENAME) + to_string(t) + ".in";
//		// 2. 拼接.out文件名（存储solve的输出结果）
//		string out_filename = string(DEFAULT_FILENAME) + to_string(t) + ".out";
//
//		// 可选：打印完整路径（兼容C++17）
//#if __cplusplus >= 201703L || (_MSVC_LANG >= 201703L)
//		fs::path txt_full_path = fs::absolute(txt_filename);
//		fs::path out_full_path = fs::absolute(out_filename);
//		cout << "第" << t << "组用例数据文件路径：" << txt_full_path << endl;
//		cout << "第" << t << "组用例结果文件路径：" << out_full_path << endl;
//#else
//		cout << "第" << t << "组用例数据文件路径：" << txt_filename << endl;
//		cout << "第" << t << "组用例结果文件路径：" << out_filename << endl;
//#endif
//
//		// ========== 写入.txt文件（树的边数据） ==========
//		ofstream txt_outfile(txt_filename);
//		if (!txt_outfile.is_open()) {
//			cerr << "错误：无法打开数据文件 " << txt_filename << "！" << endl;
//			cerr << "请检查：1. 桌面是否有data1文件夹 2. 路径是否正确 3. 是否有写入权限" << endl;
//			continue;
//		}
//		txt_outfile << n << endl;
//		for (const auto& e : edges) {
//			txt_outfile << e.u << " " << e.v << " " << e.w1 << " " << e.w2 << endl;
//		}
//		txt_outfile.close();
//		cout << "第" << t << "组数据已写入.txt文件！" << endl;
//
//		// ========== 计算solve结果并写入.out文件 ==========
//		int solve_result = solve(n, edges);
//		// 打开.out文件
//		ofstream out_outfile(out_filename);
//		if (!out_outfile.is_open()) {
//			cerr << "错误：无法打开结果文件 " << out_filename << "！" << endl;
//			continue;
//		}
//		out_outfile << solve_result << endl;  // 写入solve结果
//		out_outfile.close();
//		// 控制台也输出结果，方便查看
//		cout << "当前测试用例的solve结果：" << solve_result << endl;
//		cout << "第" << t << "组结果已写入.out文件！" << endl;
//
//		cout << "-------------------------" << endl;
//	}
//
//	return 0;
//}