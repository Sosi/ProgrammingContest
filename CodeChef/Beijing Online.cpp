/**

给出m种不同重量的石子, 每一种石子的个数无穷多。

然后要求选出N个石子，排成一个环，使得环上的石子重量的最大公约数为1. 同时如果2个方案 旋转同构的



旋转同构就是裸体polya, 就是burnside 的一个例子
然后问题就转化为 给定一个限定的 个数 N' (N' 是n的因子,这个搞过polya的应该都会把……不解释了)
问选N'个石子，有多少方案满足 他们的最大公约是是1
cnt[ i ]表示 m种石头中，有多少种石头的重量是i的倍数
可以知道预处理是 O(m sqrt(m)) 的
然后对于N', 假设g[i] = cnt[i] ^N'
那么g[i]就是长度为N'的，最大公约数为i倍数的 方案数



例如:

题目给了2种石头，重量分别是 2， 6

我们可以知道

cnt[1] = 2

cnt[2] = 2

cnt[3] = 1

cnt[4] = 0

cnt[5] = 0

cnt[6] = 1

假设一个长度为2的序列，那么其中最大公约是是 3的倍数的序列有1种

{6,6}

是2倍数的有2^2 = 4 种

{2,2}

{2,6}

{6,2}

{6,6}

...

求完以后， 来一个简单的容斥， 计算出 gcd == 1的方案数即可 (用square-free number 来搞...)



然后由于本题要除一个10007

于是变成mod (10007 * n) ,把最终的结果/ n 即可。。。。
*/
