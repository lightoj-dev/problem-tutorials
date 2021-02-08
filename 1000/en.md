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

### C#
-----
```csharp
using System;

public class HelloWorld {
  static public void Main () {
    int cases = int.Parse(Console.ReadLine());
    for (int caseno = 1; caseno <= cases; ++caseno) {
      string[] tokens = Console.ReadLine().Split();
      int a = int.Parse(tokens[0]);
      int b = int.Parse(tokens[1]);
      Console.WriteLine("Case " + caseno + ": " + (a + b));
    }
  }
}
```

### Clojure
-----
```clojure
(defn parse-int [string]
  (Integer. (re-find  #"\d+" string)))

(defn str-to-ints [string]
  (map parse-int (.split #" " string)))

(let
  [reader (java.io.BufferedReader. *in*)
   casesStr (.readLine reader)]
    
  (def cases (parse-int casesStr))
  (dotimes [i cases]
    (def line (.readLine reader))
    (def input (str-to-ints line))
    (def res (reduce + input))
    (def caseno (+ i 1))

    (println (format "Case %d: %d" caseno res))
  )
)
```

### Coffeescript
-----
```coffeescript
readline = require 'readline'
caseno = 1
rl = readline.createInterface process.stdin, process.stdout
rl.on 'line', (line) ->
  input = line.split " "
  if input.length is 2
    res = parseInt(input[0]) + parseInt(input[1])
    console.log ["Case ", caseno, ": ", res].join("")
    caseno = caseno + 1
```

### Dart
-----
```dart
import 'dart:io';
void main() {
  var cases = int.parse(stdin.readLineSync());
  for (var caseno = 1; caseno <= cases; ++caseno) {
    var inputStr = stdin.readLineSync();
    var inputs = inputStr.split(' ');
    var a = int.parse(inputs[0]);
    var b = int.parse(inputs[1]);
    var result = a + b;
    print("Case $caseno: $result");
  }
}
```

### Elixir
-----
```elixir
{cases, _} = IO.gets("") |> Integer.parse
Enum.each(1..cases, fn(caseno) ->
  [a, b] = IO.gets("") |> String.split |> Enum.map(&String.to_integer/1)
  IO.puts("Case #{caseno}: #{inspect(a + b)}")
end)
```

### Erlang
-----
```erlang
-module(main).
-export([start/0]).

loop(0, _) ->
  ok;

loop(N, CASENO) ->
  {ok, [A]} = io:fread("", "~d"),
  {ok, [B]} = io:fread("", "~d"),
  C = A+B,
  io:fwrite("Case ~w: ~w~n",[CASENO, C]),
  loop(N-1, CASENO+1).

start() ->
  {ok, [CASES]} = io:fread("", "~d"),
  loop(CASES, 1).
```

### Go
-----
```go
package main
import "fmt"

func main() {
  var cases int
  fmt.Scan(&cases)
  for caseno := 1;  caseno <= cases; caseno++ {
    var a int
    var b int
    fmt.Scan(&a)
    fmt.Scan(&b)

    fmt.Printf("Case %d: %d\n", caseno, a + b)
  }
}
```

### Groovy
-----
```groovy
System.in.withReader { Reader r ->
  int cases = r.readLine().toInteger()
  for (int caseno = 1; caseno <= cases; ++caseno) {
    def (a, b) = r.readLine().tokenize(' ')
    println("Case " + caseno + ": " + (a.toInteger() + b.toInteger()))
  }
}
```

### Haskell
-----
```haskell
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

### Kotlin
-----
```kotlin
import java.util.Scanner

fun main() {
  val input = Scanner(System.`in`)
  val cases = input.nextInt()

  for (caseno in 1..cases) {
    val a = input.nextInt()
    val b = input.nextInt()
    val c = a + b
    println("Case " + caseno + ": " + c)
  }
}
```

### Lisp
-----
```lisp
(defun main()
  (setq cases (read))
  (loop for caseno from 1 to cases
  do
      (setq a (read))
      (setq b (read))
      (setq c (+ a b))
      (format t "Case ~d: ~d" caseno c)
      (terpri)))
(main)
```

### Lua
-----
```lua
cases = io.read("*n")
for caseno = 1,cases,1
do
  a = io.read("*n")
  b = io.read("*n")
  c = a + b
  print(string.format("Case %d: %d", caseno, c))
end
```

### Objective C
-----
```objectivec
#include <stdio.h>
#import <Foundation/Foundation.h>

int main() {
  NSAutoreleasePool * pool = [[NSAutoreleasePool alloc] init];
  NSInteger cases, a, b;
  scanf("%lu", &cases);

  for (NSInteger caseno = 1; caseno <= cases; ++caseno) {
    scanf("%lu %lu", &a, &b);
    printf("Case %lu: %lu\n", caseno, a + b);
  }

  [pool drain];
  return 0;
}
```

### Pascal
-----
```pascal
var
    i, x, y, z, cases : Integer;

begin
    read(x);

    i := 0;

    repeat
        i := i + 1;
        read(y);
        read(z);
        y := y + z;
        writeln( 'Case ', i, ': ', y );
    until i = x;

end.
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
$cases = intval(fgets(STDIN));
for ($caseno = 1; $caseno <= $cases; ++$caseno) {
  $line = explode(" ", fgets(STDIN));
  $a = intval($line[0]);
  $b = intval($line[1]);

  fwrite(STDOUT, 'Case ' . $caseno . ': ' . ($a + $b) . "\n");
}
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

### Ruby
-----
```ruby
cases = gets.to_i
1.upto(cases) do |caseno|
  sum = 0
  gets.split(' ').map(&:to_i).each { |a| sum += a }
  puts "Case #{caseno}: #{sum}"
end
```

### Scala
-----
```scala
object Main {
  def main(args: Array[String]) {
    val cases = readInt()
    for (caseno <- 1 to cases) {
      val Array(a, b) = readLine() split " " map (_.toInt)
      println("Case " + caseno + ": " + (a + b))
    }
  }
}
```


### Swift
-----
```swift
import Foundation

let cases = Int(readLine()!)
if let cases = cases {
  for caseno in 1...cases {
  	let input = readLine()
		if let input = input {
	  	let sep = input.split(separator: " ")
	    let sum = sep.map { Int(String($0))! }.reduce(0, +)
	    print(String(format: "Case %d: %d", caseno, sum))
		}
	}
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
