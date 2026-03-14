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
#include <filesystem>  // C++17及以上支持路径处理

using namespace std;
using ll = long long;
namespace fs = std::filesystem;  // 简化文件系统操作

// ===================== 正解逻辑封装（核心：题目标准答案） =====================
ll solve_main(int n, int k, const vector<ll>& d, int& best_pos) {
	vector<ll> r(n + 1);  // r[i]: i右侧第一个满足1+(rr-i)*k >= d[rr]的位置
	vector<ll> l(n + 1);  // l[i]: i左侧第一个满足1+(i-ll)*k >= d[ll]的位置
	int rr = 1;
	for (int i = 1; i <= n; ++i) {
		while (rr <= n && 1 + (rr - i) * k < d[rr]) rr++;
		r[i] = rr;
	}
	int ll_pos = n;
	for (int i = n; i >= 1; --i) {
		while (ll_pos >= 1 && 1 + (i - ll_pos) * k < d[ll_pos]) ll_pos--;
		l[i] = ll_pos;
	}
	
	ll max_harm = 0;
	best_pos = 1;
	for (int i = 1; i <= n; ++i) {
		// 计算左侧伤害：1 + (1+k) + (1+2k) + ... + (1+(i-l[i]-1)k)
		ll left = (1 + (1 + (i - l[i] - 1) * k)) * (i - l[i]) / 2;
		// 计算右侧伤害：1 + (1+k) + (1+2k) + ... + (1+(r[i]-i-1)k)
		ll right = (1 + (1 + (r[i] - i - 1) * k)) * (r[i] - i) / 2;
		ll total = left + right - 1;  // 减去重复计算的初始1点伤害
		
		// 加上左右破裂节点的防御值（如果存在）
		if (l[i] >= 1) total += d[l[i]];
		if (r[i] <= n) total += d[r[i]];
		
		// 更新最大值（优先编号小的）
		if (total > max_harm || (total == max_harm && i < best_pos)) {
			max_harm = total;
			best_pos = i;
		}
	}
	return max_harm;
}

// ===================== 测试点生成逻辑 =====================
// 测试点配置结构体
struct TestCaseConfig {
	int case_num;       // 测试点编号
	int n;              // 敌人数量（n∈[1,1e5]）
	ll k_min;           // k的最小值（k∈[1,1e9]）
	ll k_max;           // k的最大值
	ll d_min;           // 防御值d_i的最小值（d_i∈[1,1e9]）
	ll d_max;           // 防御值d_i的最大值
	string file_path;   // 测试点保存路径（空则用全局路径）
};

// 生成随机数（范围 [min, max]）
template <typename T>
T random_num(T min, T max) {
	static mt19937_64 rng(time(nullptr));  // 64位随机数生成器，适配大数
	uniform_int_distribution<T> dist(min, max);
	return dist(rng);
}

// 写入.in文件
void write_input_file(const TestCaseConfig& config, int n, ll k, const vector<ll>& d, const string& global_path) {
	string base_path = config.file_path.empty() ? global_path : config.file_path;
	if (!base_path.empty()) fs::create_directories(base_path);
	
	fs::path in_file = fs::path(base_path) / (to_string(config.case_num) + ".in");
	ofstream fout(in_file.string());
	if (!fout) {
		cerr << "错误：无法创建输入文件 " << in_file << endl;
		exit(1);
	}
	
	fout << n << " " << k << endl;
	for (int i = 1; i <= n; ++i) {
		fout << d[i] << (i == n ? "\n" : " ");
	}
	fout.close();
	cout << "已生成输入文件：" << in_file << endl;
}

// 写入.out文件
void write_output_file(const TestCaseConfig& config, int best_pos, ll max_harm, const string& global_path) {
	string base_path = config.file_path.empty() ? global_path : config.file_path;
	if (!base_path.empty()) fs::create_directories(base_path);
	
	fs::path out_file = fs::path(base_path) / (to_string(config.case_num) + ".out");
	ofstream fout(out_file.string());
	if (!fout) {
		cerr << "错误：无法创建输出文件 " << out_file << endl;
		exit(1);
	}
	
	fout << best_pos << " " << max_harm << endl;
	fout.close();
	cout << "已生成输出文件：" << out_file << endl;
}

// ===================== 主函数 =====================
int main() {
	// ===================== 核心配置区 =====================
	// 全局文件保存路径（空则保存在当前目录）
	// Windows示例："C:\\Users\\xxx\\Desktop\\attack_test"
	// Linux/macOS示例："/home/xxx/attack_test"
	string GLOBAL_FILE_PATH = "C:\\Users\\23592\\Desktop\\DaoDun";
	
	// 测试点配置（可自定义每个测试点的参数）
	vector<TestCaseConfig> test_cases = {
		{1, 8, 2, 2, 1, 10, ""},          // 样例输入参数
		{2, 1, 1, 1, 1, 1, ""},            // 边界：n=1
		{3, 10, 1, 10, 1, 100, ""},        // 小数据测试
		{4, 100, 5, 50, 10, 1000, ""},     // 中等数据
		{5, 100000, 1, 1000000000, 1, 1000000000, ""},   // 大数据：n=1e5
		{6, 100000, 1000000000, 1000000000, 1, 1000000000, ""}, // 极端k值
		{7, 50000, 100, 1000, 100000000, 1000000000, ""},// 高防御值
		{8, 99999, 500, 5000, 5000, 1000000000, ""},// 混合参数
		{9, 1001, 1, 1, 1, 1, ""},         // k=1，d全1
		{10, 10000, 25, 900, 100, 10000, ""},  // 随机参数
		{11, 10000, 123, 93213122, 100, 10000, ""},  // 随机参数
		{12, 130, 233332, 111111100, 100, 10000, ""},  // 随机参数
		{13, 130, 2, 6, 100000000, 1000000000, ""},  // 随机参数
		{14, 130, 541324, 1023130, 99999999, 1000000000, ""},  // 随机参数
		{15, 99898, 50000000, 1000000000, 100, 10000, ""},  // 随机参数
		{16, 1332, 222, 1002, 1, 10000, ""},  // 随机参数
		{17, 54326, 1000000000, 1000000000, 100, 10000, ""},  // 随机参数
		{18, 99222, 2, 1000000000, 100, 10000, ""},  // 随机参数
		{19, 33, 1, 102330, 1000000000, 1000000000, ""},  // 随机参数
		{20, 2, 1000000000, 1000000000, 999999999, 1000000000, ""},  // 随机参数
	};
	// ======================================================
	
	// 逐个生成测试点
	for (const auto& config : test_cases) {
		cout << "\n===== 生成测试点 " << config.case_num << " =====" << endl;
		
		// 1. 生成随机参数k和d数组
		int n = config.n;
		ll k = random_num<ll>(config.k_min, config.k_max);
		vector<ll> d(n + 1);  // d[1..n]存储防御值
		for (int i = 1; i <= n; ++i) {
			d[i] = random_num<ll>(config.d_min, config.d_max);
		}
		
		// 2. 调用正解函数计算答案
		int best_pos;
		ll max_harm = solve_main(n, k, d, best_pos);
		
		// 3. 写入.in文件
		write_input_file(config, n, k, d, GLOBAL_FILE_PATH);
		
		// 4. 写入.out文件
		write_output_file(config, best_pos, max_harm, GLOBAL_FILE_PATH);
	}
	
	cout << "\n所有测试点生成完成！" << endl;
	return 0;
}
