#include <iostream>
#include <fstream>
#include <vector>
#include <random>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
#include <climits>
#include <functional>
#include <filesystem>  // 用于路径处理（C++17及以上）

using namespace std;
using ll = long long;
namespace fs = std::filesystem;  // 简化文件系统操作

// ===================== 正解逻辑封装（核心） =====================
struct Edge {
	int to, w1, w2;
	Edge(int t, int a, int b) : to(t), w1(a), w2(b) {}
};

ll solve(int n, int s, const vector<vector<Edge>>& tree) {
	vector<vector<Edge>> g = tree;
	ll ans = 0;
	vector<ll> dn(n + 1, 0);  // dn[u]: 从u向下的最大收益
	vector<ll> up(n + 1, 0);  // up[u]: 从u向上的最大收益
	ll sum = 0;
	function<void(int, int)> dfs = [&](int u, int fa) {
		ll upmx = 0;
		ll dnmx = 0;
		for (const Edge& e : g[u]) {
			int v = e.to;
			if (v == fa) continue;
			dfs(v, u);
			dn[u] = max(dn[u], dn[v] + e.w1);
			up[u] = max(up[u], up[v] + e.w2);
			ans = max(ans, dn[v]+e.w1 + upmx);
			ans = max(ans, up[v]+e.w2 + dnmx);
			upmx = max(upmx, up[v] + e.w2);
			dnmx = max(dnmx, dn[v] + e.w1);
		}
	};
	
	// 计算所有边权的总和（避免重复计算）
	for (int u = 1; u <= n; ++u) {
		for (const Edge& e : g[u]) {
			if (u < e.to) {  // 只计算一次每条边
				sum += e.w1 + e.w2;
			}
		}
	}
	
	dfs(s, 0);
	return sum - ans;
}

// ===================== 测试点生成逻辑 =====================
// 测试点配置结构体：新增路径配置（可选）
struct TestCaseConfig {
	int case_num;       // 测试点编号（如1,2,3）
	int n;              // 该测试点的节点数n
	int s;              // 起点（若为-1则随机生成）
	int w_min;          // 边权最小值
	int w_max;          // 边权最大值
	string file_path;   // 该测试点的文件保存路径（空则使用全局路径）
};

// 生成随机数（范围 [min, max]）
int random_int(int min, int max) {
	static mt19937 rng(time(nullptr));
	uniform_int_distribution<int> dist(min, max);
	return dist(rng);
}

// 生成树的边列表和邻接表
pair<vector<tuple<int, int, int, int>>, vector<vector<Edge>>> generate_tree(int n, int w_min, int w_max) {
	vector<tuple<int, int, int, int>> edge_list;  // 用于写入.in文件的边列表
	vector<vector<Edge>> adj(n + 1);              // 用于正解计算的邻接表
	
	// 生成树（保证连通：每个节点2~n随机连接到1~i-1）
	for (int v = 2; v <= n; ++v) {
		int u = random_int(1, v - 1);  // 父节点
		int w_uv = random_int(w_min, w_max);  // u->v的权值
		int w_vu = random_int(w_min, w_max);  // v->u的权值
		
		edge_list.emplace_back(u, v, w_uv, w_vu);
		adj[u].emplace_back(v, w_uv, w_vu);
		adj[v].emplace_back(u, w_vu, w_uv);
	}
	
	// 打乱边的顺序（模拟随机输入）
	shuffle(edge_list.begin(), edge_list.end(), mt19937(time(nullptr)));
	return {edge_list, adj};
}

// 写入.in文件（支持自定义路径）
void write_input_file(const TestCaseConfig& config, const vector<tuple<int, int, int, int>>& edges, int actual_s, const string& global_path) {
	// 确定最终路径：优先使用测试点单独配置的路径，否则用全局路径
	string base_path = config.file_path.empty() ? global_path : config.file_path;
	// 确保路径存在（不存在则创建）
	if (!base_path.empty()) {
		fs::create_directories(base_path);
	}
	
	// 拼接完整的.in文件路径
	fs::path in_file_path = fs::path(base_path) / (to_string(config.case_num) + ".in");
	ofstream fout(in_file_path.string());
	if (!fout) {
		cerr << "错误：无法创建输入文件 " << in_file_path << endl;
		exit(1);
	}
	
	// 写入内容
	fout << config.n << " " << actual_s << endl;
	for (const auto& edge : edges) {
		int u = get<0>(edge);
		int v = get<1>(edge);
		int w1 = get<2>(edge);
		int w2 = get<3>(edge);
		fout << u << " " << v << " " << w1 << " " << w2 << endl;
	}
	
	fout.close();
	cout << "已生成输入文件：" << in_file_path << endl;
}

// 写入.out文件（支持自定义路径）
void write_output_file(const TestCaseConfig& config, ll answer, const string& global_path) {
	// 确定最终路径：优先使用测试点单独配置的路径，否则用全局路径
	string base_path = config.file_path.empty() ? global_path : config.file_path;
	// 确保路径存在
	if (!base_path.empty()) {
		fs::create_directories(base_path);
	}
	
	// 拼接完整的.out文件路径
	fs::path out_file_path = fs::path(base_path) / (to_string(config.case_num) + ".out");
	ofstream fout(out_file_path.string());
	if (!fout) {
		cerr << "错误：无法创建输出文件 " << out_file_path << endl;
		exit(1);
	}
	
	fout << answer << endl;
	fout.close();
	cout << "已生成输出文件：" << out_file_path << endl;
}

// ===================== 主函数 =====================
int main() {
	// ===================== 核心配置区 =====================
	// 1. 全局文件保存路径（所有测试点默认保存到这个路径，为空则保存在当前目录）
	// Windows示例："D:/test_cases" 或 "C:\\Users\\xxx\\Desktop\\定向测试点"
	// Linux/macOS示例："/home/xxx/test_cases" 或 "./test_cases"
	string GLOBAL_FILE_PATH = "C:\\Users\\23592\\Desktop\\schoolRun";  // 建议用相对路径，避免跨平台问题
	
	// 2. 测试点配置：可为每个测试点单独指定路径（file_path为空则用全局路径）
	vector<TestCaseConfig> test_cases = {
		{1, 5, -1, 1, 4, ""},      
		{2, 10, -1, 1, 10, ""},
		{3, 100, -1, 1, 100, ""}, 
		{4, 12, -1, 1, 1000, ""},
		{5, 100000, -1, 1, 1000000000, ""},
		{6, 100000, -1, 1, 1000000000, ""},
		{7, 6666, -1, 400, 23040, ""},
		{8, 1001, -1, 1, 1, ""},
		{9, 1001, -1, 2, 100, ""},
		{10, 130, -1, 1, 10230, ""},
		{11, 1000, -1, 1, 1000, ""},
		{12, 9999, -1, 1, 1000000, ""},
		{13, 99999, -1, 1, 1000000000, ""},
		{14, 100000, -1, 100000000, 1000000000, ""},
		{15, 10000, -1, 100000000, 1000000000, ""},
		{16, 1, -1, 1, 1, ""},
	};
	// ======================================================
	
	// 逐个生成测试点
	for (const auto& config : test_cases) {
		cout << "\n===== 生成测试点 " << config.case_num << " =====" << endl;
		
		// 1. 生成树的边列表和邻接表
		auto [edge_list, adj] = generate_tree(config.n, config.w_min, config.w_max);
		
		// 2. 确定实际使用的起点s
		int actual_s = (config.s == -1) ? random_int(1, config.n) : config.s;
		
		// 3. 写入.in文件（传入全局路径）
		write_input_file(config, edge_list, actual_s, GLOBAL_FILE_PATH);
		
		// 4. 调用正解函数计算答案
		ll answer = solve(config.n, actual_s, adj);
		
		// 5. 写入.out文件（传入全局路径）
		write_output_file(config, answer, GLOBAL_FILE_PATH);
	}
	
	cout << "\n所有测试点生成完成！" << endl;
	return 0;
}
