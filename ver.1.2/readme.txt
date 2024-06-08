###utf-8
20240604
关于"unit.h" 的说明
========
中文注释就是乱码，根本改不了，所以不写了。

关于 单元unit:
数据
	add                             指的是此牌的占用状态。0-可用；1-被甲占用；2-被乙占用；-1-被禁用。
	s                               指的是因子个数（含1）
	ss                              指的是因子的集合（空位用-13填充）
函数
	void first(int)                 初始化
	void check_unit()               输出单元状态

关于 集合units
数据
	set                             23张牌
	set_add                         记录每张牌的占用情况，作为一个副本，方便查阅
    ERROR                           控制报错
    TEST                            调试模式
函数
    void error(bool)                报错开关
    void test(bool);                调试专用
    void first_all()                全局初始化
    void check_units(int)           输出某个单元的状态(调试专用)
    void sign(int,int)              将某张牌的占用更新
	void sign(int,int,char);        调试专用
    void del_all()                  "delete_all"的简写 全局禁用（调试专用）
    void del(int)                   "delete"的简写 禁用某张牌
    void srch_sg(int,int)           "search_sign"的简写 将某张牌的所有因子更新占用
	void srch_sg(int,int,char);     调试专用
    void out_ss_add()               输出未占用的牌
    bool find(int)                  判断该张牌是否有因子未被占用
    void choose(int)                对某张牌标记占用并标记因子占用
    bool check_all()                判断是否有牌未被占用
    bool check_one(int)             判断该张牌是否未被占用
    bool check_result()             判断甲是否胜利
    int get_ss_add(int, int)        获取某张牌某个因子的状态
	int get_ss_add(int,int,char);   调试专用
    int result()                    输出结果及输赢

tips
    1.如果要查看内部报错，请将 ERROR 设置为 1；
    2.如果要调用调试函数，请将 TEST 设置为 1；