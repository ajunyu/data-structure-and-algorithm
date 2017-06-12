/*
 * 求解 n 阶 Hanoi 塔问题的递归算法
 */

// 将塔座x上从上到下编号为1至n，且按直径由小到大叠放的n个圆盘，按规则搬到塔座z上，y用作辅助塔座
void hanoi(int n, char x, char y, char z)
{
	if (n == 1)
	{
		// 将编号为1的圆盘从x移动到z
		move(x, 1, z);
	}
	else
	{
		// 将x上编号为1至n-1的圆盘移到y，z作辅助塔
		hanoi(n - 1, x, z, y);
		// 将编号为n的圆盘从x移到z
		move(x, n, z);
		// 将y上编号为1至n-1的圆盘移到z，x作辅助塔
		hanoi(n - 1, y, x, z);
	}
}
