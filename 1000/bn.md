# LOJ 1000 - Greetings from LightOJ

এটি লাইটওজে ভলিউমের সবচেয়ে সহজ সমস্যা। আপনাকে যা করতে হবে তা হ'ল প্রতিটি ক্ষেত্রে ইনপুট `a` এবং `b` এর যোগফল প্রিন্ট আউট করা।

তবে এর পরেও কিছু প্রব্লেম সল্ভার সঠিক আউটপুট ফর্ম্যাট অনুসরণ না করার কারণে সফল হতে পারে না।

1. আপনি প্রতিটি লাইনে নিউলাইন প্রিন্ট করেছেন তা নিশ্চিত করুন।
2. সমস্যা বিবরণীতে দেয়া নমুনা আউটপুট এবং আপনার আউটপুট একই কি না তা নিশ্চিত করুন, কেস নম্বরটি একবার দেখুন।
3. আপনি আউটপুটে সঠিক পরিমাণে ফাঁকা স্থান যোগ করেছেন তা নিশ্চিত করুন।

আপনি যদি এখনও এই সমস্যায় আটকে থাকেন তবে নীচের কোডগুলি দেখুন:

### C
-----
```c
#include <stdio.h>

int main() {
  int cases, caseno;
  scanf("%d", &cases);
  for (caseno = 1; caseno <= cases; ++caseno) {
    int a, b;
    scanf("%d %d", &a, &b);
    printf("Case %d: %d\n", caseno, a + b);
  }
  return 0;
}
```

### Java
-----
```java
package com.loj.volume;

import java.util.Scanner;

class GreetingsFromLoj {
  public static void main(String[] args) throws Exception {
    Scanner scanner = new Scanner(System.in);
    int cases = scanner.nextInt();
    for (int caseno = 1; caseno <= cases; ++caseno) {
      int a = scanner.nextInt();
      int b = scanner.nextInt();
      System.out.println("Case " + caseno + ": " + (a + b));
    }
  }
}
```

### Python 2
-----
```python
for i in xrange(int(raw_input())):
  print "Case %i: %i" % (i + 1, sum(map(int, raw_input().split())))
```
