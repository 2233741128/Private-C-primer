#include <stdio.h>
#include <stdbool.h>

bool is_even(int num) {
    if (num % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int num = 5;
    if (is_even(num)) 
	{
        printf("%d is even.", num);
    } else {
        printf("%d is odd.", num);
    }
    return 0;
}
/*这个例子中，我们定义了一个名为is_even的函数，它接受一个整数参数并返回一个bool类型的值。
如果参数是偶数，则返回true；否则返回false。
在主函数中，我们调用is_even函数来判断一个数是否是偶数，并输出相应的结果。*/