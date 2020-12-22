# LOJ 1000 - Greeting on LightOJ

It is the easiest problem on LightOJ volumes. All you have to do is print out the sum of input `a` and `b` on each case. There is nothing tricky about it.

But still some people can't get `Accepted` verdict because of not following the proper output format.

1. Make sure you have printed newline on each line
2. Make sure you have same output as the sample output on the problem descriptin, take a look at case number.
3. Make sure you have added right amount of spaces on the output.

If you are still stuck with this problem, check the codes below:

### Bash
-----
```bash
read cases
for caseno in $(seq 1 $cases)
do
  read line
  inputArray=($line)
  a=${inputArray[0]}
  b=${inputArray[1]}

  res=$((a+b))
  echo "Case $caseno: $res"
done
```

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

### Haskell
-----
```
import Control.Monad

main = do
  cases <- getLine
  forM_ [1..(read cases :: Int)] $ \caseno -> do
    input <- getLine
    let arr = words input
    let intArr = map (read::String->Int) arr

    putStr "Case "
    putStr (show caseno)
    putStr ": "
    print $ sum(intArr)
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

### Perl
-----
```perl
my $cases =  <STDIN>;

foreach my $caseno (1..$cases) {
  my ($a, $b) = split / /, <STDIN>;
  my $sum = $a + $b;
  print "Case $caseno: $sum\n";
}
```

### Php
-----
```php
<?php

$cases = intval(fgets(STDIN));
for ($caseno = 1; $caseno <= $cases; ++$caseno) {
  $line = explode(" ", fgets(STDIN));
  $a = intval($line[0]);
  $b = intval($line[1]);

  fwrite(STDOUT, 'Case ' . $caseno . ': ' . ($a + $b) . "\n");
}

?>
```

### Python 2
-----
```python
for i in xrange(int(raw_input())):
  print "Case %i: %i" % (i + 1, sum(map(int, raw_input().split())))
```

### Python 3
-----
```python
for i in range(int(input())):
  print("Case %i: %i" % (i + 1, sum(map(int, input().split()))))
```

### R
-----
```r
f <- file("stdin")
open(f)

cases <- readLines(f, n = 1)
for (caseno in 1:cases) {
  data <- strsplit(readLines(f, n = 1), " ", TRUE)[[1]]
  sum <- as.numeric(data[1]) + as.numeric(data[2])
  cat ("Case ", caseno, ": ", sum, "\n", sep="")
}
```

### Visual Basic
-----
```vb
Module GFL
    Sub Main()
        Dim cases, caseno, a, b, sum As Integer
        cases = CInt(Console.readLine())
        For caseno As Integer = 1 To cases
            Dim testInput() As String = Split(Console.readLine())
            a = CInt(testInput(0))
            b = CInt(testInput(1))
            sum = a + b
            Console.WriteLine("Case " & caseno & ": " & sum)
        Next
    End Sub

End Module
```
