解题思路
1.设置最大值的max
2.设置当前值cur
3.设置一个开始游标start
4.遍历string的数组，每取一位i跟之前start到i-1的值比价
  如果没一个相等cur++,如果有相等start移动到相等位置j+1
5.比较max和cur，谁大记录谁
6.重新设置cur值i - start +1;
7.继续遍历  