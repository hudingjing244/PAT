#include<cstdio>//int型会有一个测试点过不去，因为换算后数值过大，int存储不了

int main()
{
    long long int ans;
    long long int A[3];
    long long int B[3];

    scanf("%lld.%lld.%lld %lld.%lld.%lld", A, A + 1, A + 2, B, B + 1, B + 2);

    ans = A[2] + 29 * A[1] + 29 * 17 * A[0] + B[0] * 17 * 29 + B[1] * 29 + B[2];
    printf("%lld.%lld.%lld", ans / (29 * 17), (ans%(29*17))/29, ans % 29);
    return 0;
}