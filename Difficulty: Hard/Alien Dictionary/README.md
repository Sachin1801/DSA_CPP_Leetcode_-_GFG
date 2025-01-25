<h2><a href="https://www.geeksforgeeks.org/problems/alien-dictionary/1">Alien Dictionary</a></h2><h3>Difficulty Level : Difficulty: Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given a <strong>sorted</strong> dictionary of an alien language having some words <strong>dict</strong> and k starting alphabets of a standard dictionary. Find the order of characters in the alien language. If <strong>no valid</strong> ordering of letters is possible, then <strong>return </strong>an empty string.</span></p>
<p><span style="font-size: 14pt;"><strong>Note</strong>: Many orders may be possible for a particular test case, thus you may return any valid order and output will be "true" if the order of string returned by the function is correct else "false" denotes incorrect string returned.</span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>dict[] = ["baa","abcd","abca","cab","cad"], k = 4
<strong>Output: </strong>true
<strong>Explanation: </strong>Here order of characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
Similarly we can find other orders.</span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>dict[] = ["caa","aaa","aab"], k = 3
<strong>Output: </strong>true
<strong>Explanation: </strong>Here order of characters is 'c', 'a', 'b' Note that words are sorted and in the given language "caa" comes before "aaa", therefore 'c' is before 'a' in output.
Similarly we can find other orders.<br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>dict[] = ["dhhid","dahi","cedg","fg","gdah","i","gbdei","hbgf","e","ddde"], k = 9 
<strong>Output: </strong>false</span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ dict.size()≤ 10<sup>4</sup><br>1 ≤ k ≤ 26<br>1 ≤ Length of words&nbsp;≤ 50</span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>OYO Rooms</code>&nbsp;<code>Walmart</code>&nbsp;<code>Google</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Strings</code>&nbsp;<code>Sorting</code>&nbsp;<code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;