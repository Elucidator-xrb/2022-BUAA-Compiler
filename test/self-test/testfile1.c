#include "selfio.h"
/*=========== testfile1 : Level A ===========*/
/*
 * try to cover all
 */
const int const1 = 0;                                          // 普通变量 + 初值
const int const1_arr[10/5] = {1,2}, const2_arr[3] = {3, 4, 5}; // 一维数组 + 一维初值
const int const1_arr2[2][5-7%4] = {{6,7},{8,7+2*(3-2)}};       // 二维数组 + 二维初值
const int _my_const = 3*1-1, const2 = -2, const3 = 4;          // 一行多次

int var1 = 3;   //  普通变量 + 初值
int var2 = 4-2%4, var_arr[4]={1,2,3,4}, var_arr2[2][1]={{3%2+0},{10}};    // 多维变量 + 多维初值 一行多次
int var3;       //  普通变量 + 无初值 
int var4, var5[2], var6[3][5];   // 多维变量 + 无初值

int test_return() {
    return 1 * (2 + 7) % 4 - (2 - 12) / 5;  // + - * / % () ： 3
}
int test_zero(int a) {
    int s = 0;
    if (!a) s = 1; // 单目运算符 ！（仅在条件表达式中）
    return s;
}
int test_add(int a, int b) {
    return a + b;
}
int test_sum(int a[], int num) {
    int sum = 0, i;
    i = 0;
    while(i < num) {
        sum = sum + a[i];
        i = i + 1;
    }
    return sum;
}
int test_ifcomb(int a[][2], int b[], int num) {
    int i = num-1, tar = 0;
    while (i >= 0) {
        if (a[i][0] == 0) ; //无Exp语句
        else if (a[i][0] > 0) {
            tar = tar + a[i][1] * b[i];
        } else {
            tar = tar - a[i][1] * b[i];
        }
        i = i - 1;
    }
    return tar;
}

void run_test_return() {
    printf("test_return:%d <==> correct:3\n", test_return());
    return;
}
void run_test_zero(int a, int verify) {
    printf("test_not:%d <==> correct:%d\n",test_zero(a), verify);
}
void run_test_sum(int a[], int num, int verify) {
    if (num <= 0) printf("num invalid: smaller than zero\n");
    else {
        printf("test_sum:%d <==> correct:%d\n", test_sum(a, num), verify);
    }
}
void run_test_ifcomb(int a[][2], int b[], int num, int verify) {
    printf("test_ifcomb:%d <==> correct:%d\n", test_ifcomb(a, b, num), verify);
}
void test_logic() {
    int a = 3, b = 5, c = 5;
    if (a == 3 && b != 4 || c < 5) printf("short-circuit logic or ok!\n");
    if (a > 4 || b >= 6 && c <= 5) ; else printf("short-circuit logic and ok!\n");
}
void test_exp() {
    int a = 1, b[2] = {2, 3};
    int c;
    c = -a + test_add(b[0], b[1]) * (b[0] % const1_arr2[0][1]);
    printf("c=%d <==> correct:%d\n", c, 9);
}

int main() {
    printf("20373585\n");

    {}
    int var = const1, arr[2];
    printf("const1_arr2[1][1]:%d <==> correct:9\n", const1_arr2[1][1]);
    
    run_test_return();
    
    arr[0] = var; // 0
    arr[1] = 1  ; // !0
    run_test_zero(arr[0], arr[1]);
    
    var6[2][0] = +-+-1; // 单目运算符：+ -
    var6[2][1] = +2;
    var6[2][2] = var1;
    var6[2][3] = getint();   // input: 4
    var6[2][4] = test_add(3, -3) + const2_arr[var6[2][3+const2]];
    run_test_sum(var6[2], 5, 15);  // 1 + 2 + 3 + 4 + 5

    int a[4][2];
    int i = 0, j;
    while (i < 4) {     // 嵌套 + continue/break
        j = 0;
        while (j < 2) {
            int get_var;
            get_var = getint();
            while (1) {  // 对于a[0][]来说，若值非大于0则不接受输入
                if (i != 0) break;
                if (get_var <= 0) {
                    get_var = getint();
                    continue;
                }
                break;
            }
            a[i][j] = get_var;
            j = j + 1;
        }
        i = i + 1;
    }
    run_test_ifcomb(a, var_arr, 4, -11); // 1*1 + 2*2 + 0 - 4*4
    
    test_logic();

    test_exp();

    return 0;
}