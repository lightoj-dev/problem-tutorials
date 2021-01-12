# LOJ 1006 - Hex-a-bonacci
*In each test case, you are given first 6 elements of an integer series/sequence and an integer n. You have to find out the n-th element of the series.*
___
### Summary 
This is a little tweaked Fibonacci problem with a simple trick. Only difference from Fibonacci is, each element  starting from seventh position is summation of previous six elements. Also, you will need to keep integer overflow in mind as the given code in the statement prints answer with modulo 10000007.
### Solution
- Declare an array[] with ```long long int``` data type.
- Fill-up array[0] to array[5] with the first six numbers. Keep the number in 7-th position in a variable let's name N. 
- Start loop from array[6] which will be the summation of all the elements before it. Continue the loop to the array[N]. On each iteration MOD the sum of six elements by 10000007. 
-  Print array[N]%10000007.
___
### Code in C++
```
int main()
{
    long long a,b,c,d,e,f,t,n;
    scanf("%lld",&t);
    for (int cs = 1; cs <= t; cs++) {
        ll hexafib[10009];
        scanf("%lld %lld %lld %lld %lld %lld %lld",&hexafib[0],&hexafib[1],&hexafib[2],&hexafib[3],&hexafib[4],&hexafib[5],&n);
        for (int i =6; i <= n; ++i) {
            hexafib[i] =( hexafib[i-1]+hexafib[i-2]+hexafib[i-3]+hexafib[i-4]+hexafib[i-5]+hexafib[i-6] ) %10000007;
        }
        printf("Case %d: %lld\n",cs,hexafib[n] % 10000007);
    }

    return 0;
}
```




