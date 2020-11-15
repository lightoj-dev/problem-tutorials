# LOJ 1015 - Brush (I)

এই সমস্যাটিতে আপনাকে `T` - টি টেস্ট কেস দেয়া হবে। যার প্রতিটা টেস্ট কেস একটি ফাঁকা লাইন দিয়ে শুরু হবে এবং এই ফাঁকা লাইনের পরে একটি ইন্টিজার `N` দেয়া থাকবে। পরবর্তী লাইনে স্পেস দিয়ে পৃথক পৃথক `N` - টি ইন্টিজার দেয়া হবে। অপনার কাজ হলো - ঋণাত্মক ইন্টিজারগুলো বাদ দিয়ে, এই `N` সংখ্যক ইন্টিজারের যোগফল বের করা।  

সমস্যাটি খুবই  সোজা সাপটা, যদিও সমস্যাটিকে গ্রহণযোগ্য করা কারো জন্য কষ্টকর হতে পারে। নিম্নোক্ত কারণগুলির একটিকে এর জন্য দায়ী করা যেতে পারে:

1. যোগ করার সময় ঋণাত্মক ইন্টিজারকেও যোগ করে ফেলা
2. আউটপুট ফরম্যাট সঠিক না হওয়া
3. প্রতি লাইনে ফাঁকা স্থান যোগ না করা

আপনি যদি এখনও এই সমস্যায় আটকে থাকেন তবে নীচের কোডগুলি দেখুন:

### C
-----
```c
#include <stdio.h>
int main() {
  int T, N, num, sum;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d", &N);
    sum = 0;
    for (int j = 1; j <= N; j++) {
      scanf("%d", &num);
      // negative number should be ignored, zero does not affect the sum
      if (num > 0) {
        sum += num;
      }
    }
    printf("Case %d: %d\n", i, sum);
  }
  return 0;
}
```

### Java
-----
```java
package com.loj.volume;

import java.util.Scanner;

class Brush {
  public static void main(String[] args) throws Exception {
    Scanner input = new Scanner(System.in);
    int T = input.nextInt();
    for (int i = 1; i <= T; i++) {
      int N = input.nextInt();
      int num, sum = 0;
      for (int j = 1; j <= N; j++) {
        num = input.nextInt();
        // negative number should be ignored, zero does not affect the sum
        if (num > 0) {
          sum += num;
        }
      }
      System.out.printf("Case %d: %d\n", i, sum);
    }
  }
}
```
