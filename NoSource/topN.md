实现一个类似于"微博热搜"topN的功能.(待修改的topN)
solution:
首先点击量只增加不减少,先排序求出前N大的值，然后将第N大的作为阈值x。
记count[key],点击一下,count[key]++,
	如果 count[key]<x:不管
	否则 count[key]大于阈值x，更新阈值。并且重新计算topN.
