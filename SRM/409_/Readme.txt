DIV  2 

250 Easy
500 Easy


NICE PROBLEM
1000 给定一棵树，求 加入k条边(k<5)，使得树任意节点到某一固定节点的最大值最小？

很简单的就是枚举k，这个时候可以简单写成for循环来进行枚举，更好的一种方法是使用递归的方法来进行枚举啊！！

void allCombinations( int index, int minValue, int[] teleports){
        if(index==teleports.length){
            //do something with the teleports here
        }else{
            for(int i=minValue;i<n;i++){
                teleports[index] = i;
                allCombinations(index + 1, i+1, teleports);
            }
        }
    }
	
	这个技巧非常值得借鉴！




DIV

250 EASY



600 GOOD problem！！
NICE PROBLEM

判定一个整数X是否能够被 C(n,m) 整除？

枚举X的素数表示，看 C(n,m) 的素数表示是否比 X的相关表示的大！


int LP(int x, int y)
{
    if(x < y) return 0;
    return x/y + LP(x/y,y);
}

int test(int x, int y,int p )
{
    return LP(x,p) - LP(y,p)- LP(x-y, p);
}

class MagicalSpheres
{
        public:
        int divideWork(int a, int b, int c)
        {
            for(i=c; i>=1; i--)
            {
                k = i;
                int fail = 0;
                for(j=2; j*j<=k;j++)
                {
                    int t = 0;
                    if(k%j == 0)
                    {
                        while(k%j==0)
                        {
                            k/=j; t++;
                        }
                        if(test(a+b,a,j) <  t) { fail = 1; break;}
                    }
                }
                if(k>1) if(test(a+b, a, k) < 1) fail = 1; 
                if(!fail) return i; 
            }
            return -1;
        }
}


409 真是神题啊！！！


计算获得每一个点被覆盖的概率！！



