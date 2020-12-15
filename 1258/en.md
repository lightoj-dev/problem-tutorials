<p class="has-line-data" data-line-start="0" data-line-end="1">Problem Title: 1258 - Making Huge Palindromes</p>
<p class="has-line-data" data-line-start="2" data-line-end="4">Problem Description: You will be given a non-empty string containing only lowercase English letters. Your task is to make it a palindrome adding<br>
minimum numbers of characters at the right side of the string.</p>
<p class="has-line-data" data-line-start="5" data-line-end="7">Observation: Suppose the input string length is N. We are allowed to add characters only right side of the given string to make the string palindrome. We can<br>
do it by adding the reversed string at the right side of the input string. But we have to minimize it as much as possible. Let’s, observe the following strings:</p>
<p class="has-line-data" data-line-start="8" data-line-end="13">Input string: kamal<br>
Reversed string: lamak<br>
Input string + reversed string: “kamal lamak” it is palindrome but not optimal.<br>
Optimal palindrome: kamalamak<br>
If we add “amak” to the right side then it be a palindrome (4 characters added).</p>
<p class="has-line-data" data-line-start="14" data-line-end="19">Input string: ahdaa<br>
Reversed string: aadha<br>
Input string + reversed string: ahdaa aadha<br>
Optimal palindrome: ahdaadha<br>
If we add “dha” to the right side then it be a palindrome (3 characters added).</p>
<p class="has-line-data" data-line-start="20" data-line-end="25">Input string: nooroo<br>
Reversed string: ooroon<br>
Input string + reversed string: nooroo ooroon<br>
Optimal palindrome: nooroon<br>
If we add “n” to the right side then it be a palindrome (1 character added).</p>
<p class="has-line-data" data-line-start="26" data-line-end="32">Input string: madam<br>
Reversed string: madam<br>
Input string + reversed string: madam madam<br>
Optimal palindrome: madam<br>
It is already palindrome. We needn’t to add any characters (0 character added).<br>
N.B. In input string + reversed string, space is added to separate both strings.</p>
<p class="has-line-data" data-line-start="33" data-line-end="36">We have observed that if we need to add K characters to the right side of a string to make the string palindrome then (N-K) characters are already<br>
palindrome which are at the right side of the string. These (N-K) characters are suffix of the input string and prefix of reversed string. We need<br>
to erase one (suffix or prefix) to get the optimal answer.</p>
<p class="has-line-data" data-line-start="37" data-line-end="38">So, how can we detect it?</p>
<ol>
<li class="has-line-data" data-line-start="39" data-line-end="42">Solution by KMP: Here, already palindrome characters are a suffix of the belonged string. If we can match it with the prefix of another string<br>
(reverse of input string) then we are done (the idea of KMP).</li>
</ol>
<p class="has-line-data" data-line-start="42" data-line-end="44">We can easily do it by adding both strings. Then the last value of the LPS array will be “already palindrome” part length. We will add both strings<br>
in this way: reversed_string#input_string → lamak#kamal  (Here, input string is “kamal”)</p>
<p class="has-line-data" data-line-start="45" data-line-end="46">N.B. We need to add ‘#’ to denote that each string is different (‘#’ will never be given in the input string).</p>
<p class="has-line-data" data-line-start="47" data-line-end="49">Time Complexity: O(T*N) Where, T denotes total number of test cases.<br>
Memory Complexity: O(N)</p>
<ol start="2">
<li class="has-line-data" data-line-start="50" data-line-end="53">Solution by Hashing: Reverse the input string and calculate the hash values from first to last. Take a variable to store max palindrome length starting<br>
from the first position initializing 1. Each time match the forward &amp; reversed hash value. If matched then update the max palindrome length value.</li>
</ol>
<p class="has-line-data" data-line-start="53" data-line-end="55">Time Complexity: O(T*N) Cause, we are calculating both hash values just running a single loop (Where T denotes total number of test cases).<br>
Memory Complexity: O(N)</p>
<hr>
<ol>
<li class="has-line-data" data-line-start="58" data-line-end="60">My Code using KMP:</li>
</ol>
<p class="has-line-data" data-line-start="60" data-line-end="63">#include &lt;bits/stdc++.h&gt;<br>
using namespace std;<br>
#define pb  push_back</p>
<p class="has-line-data" data-line-start="64" data-line-end="65">vector&lt;int&gt; lps;</p>
<p class="has-line-data" data-line-start="66" data-line-end="84">void createLPS(string pat)<br>
{<br>
lps.pb(0);<br>
int i = 0, j = 1;<br>
for ( ; pat[j]; ){<br>
if (pat[i] == pat[j]){<br>
lps.pb(i+1);<br>
++i, ++j;<br>
}<br>
else{<br>
if (i != 0) i = lps[i-1];<br>
else {<br>
++j;<br>
lps.pb(0);<br>
}<br>
}<br>
}<br>
}</p>
<p class="has-line-data" data-line-start="85" data-line-end="97">int main(){<br>
int sz, T; cin&gt;&gt;T;<br>
string text, pat;<br>
for (int t = 1; t &lt;= T; t++){<br>
cin&gt;&gt;text;<br>
pat = text;<br>
reverse(pat.begin(), pat.end());<br>
pat += ‘#’ + text;<br>
createLPS(pat);<br>
int sz = text.size();<br>
int total = 2*sz - lps[lps.size()-1];<br>
printf(“Case %d: %d\n”, t, total);</p>
<pre><code>    lps.clear();
}
</code></pre>
<p class="has-line-data" data-line-start="100" data-line-end="101">}</p>
<ol start="2">
<li class="has-line-data" data-line-start="102" data-line-end="104">My Code using Hashing:</li>
</ol>
<p class="has-line-data" data-line-start="104" data-line-end="112">#include &lt;bits/stdc++.h&gt;<br>
using namespace std;<br>
#define  LL    long long int<br>
#define  LIM   1000005<br>
#define  base1 129<br>
#define  base2 137<br>
#define  MOD1  1479386893<br>
#define  MOD2  1928476349</p>
<p class="has-line-data" data-line-start="114" data-line-end="116">string text;<br>
LL pow1[LIM], pow2[LIM];</p>
<p class="has-line-data" data-line-start="117" data-line-end="124">void calPower(){<br>
pow1[0] = pow2[0] = 1;<br>
for(int i = 1; i &lt; LIM; i++){<br>
pow1[i] = (pow1[i-1]*base1)%MOD1;<br>
pow2[i] = (pow2[i-1]*base2)%MOD2;<br>
}<br>
}</p>
<p class="has-line-data" data-line-start="125" data-line-end="137">int getHash(){<br>
LL hash1 = 0, hash2 = 0, revHash1 = 0, revHash2 = 0;<br>
int res = 1;<br>
for(int i = 0; text[i]; i++){<br>
hash1 = ((hash1<em>base1)%MOD1 + (text[i]-‘a’ + 1))%MOD1;<br>
hash2 = ((hash2</em>base2)%MOD2 + (text[i] - ‘a’ + 1))%MOD2;<br>
revHash1 = (revHash1 + ((text[i]-‘a’ + 1)*pow1[i])%MOD1)% MOD1;<br>
revHash2 = (revHash2 + ((text[i]-‘a’ + 1)*pow2[i])%MOD2)% MOD2;<br>
if(hash1 == revHash1 &amp;&amp; hash2 == revHash2) res = max(res, i+1);<br>
}<br>
return res;<br>
}</p>
<p class="has-line-data" data-line-start="138" data-line-end="151">int main(){<br>
calPower();<br>
int T; cin&gt;&gt;T;<br>
for(int t = 1; t &lt;= T; t++){<br>
cin&gt;&gt;text;<br>
string tmp = text;<br>
reverse(text.begin(), text.end());<br>
int res = getHash();<br>
int matched = res;<br>
res = (text.size()-res)*2 + res;<br>
printf(“Case %d: %d\n”, t, res);<br>
}<br>
}</p>
<p class="has-line-data" data-line-start="154" data-line-end="157">…<br>
Contributed by: AH Kamal, HSTU<br>
<a href="http://www.facebook.com/kamalcse36">www.facebook.com/kamalcse36</a></p>
