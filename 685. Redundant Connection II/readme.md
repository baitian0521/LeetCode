解题思路：
在图中寻找一个入度为2的点
    若 不存在
        则 图中有环
        找到最后一条使图成环的边 并返回
    若 存在
        获取与该结点相关的两条边A，B
        将B移除 得到新的图
        若 新的图符合条件
            返回B
        若 不符合条件
            返回A
采用Kruskal算法，判断是否形成环路            