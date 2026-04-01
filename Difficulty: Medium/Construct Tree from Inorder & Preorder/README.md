<h2><a href="https://www.geeksforgeeks.org/problems/construct-tree-1/1">Construct Tree from Inorder & Preorder</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 14pt;">Given two arrays representing the <strong>inorder</strong> and <strong>preorder</strong> traversals of a binary tree, your task is to construct the binary tree and return its&nbsp;<strong>root</strong>.</span></p>
<p><span style="font-size: 14pt;"><span style="font-size: 18.6667px;"><strong>Note:</strong> The inorder and preorder traversals contain unique values, and every value present in the preorder traversal is also found in the inorder traversal.</span></span></p>
<p><span style="font-size: 14pt;"><strong>Examples:</strong></span><span style="font-size: 14pt;"><br></span></p>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>inorder[] = [3, 1, 4, 0, 5, 2], preorder[] = [0, 1, 3, 4, 2, 5]
<strong>Output: </strong>[0, 1, 2, 3, 4, 5]<strong>
Explanation: </strong>The tree will look like<br><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/912538/Web/Other/blobid0_1758871794.webp" width="379" height="263"><br></span></pre>
<pre><span style="font-size: 14pt;"><strong>Input: </strong>inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
<strong>Output: </strong>[1, 4, 3, 5, N, N, N, 2]<br><strong>Explanation: </strong>The tree will look like<strong><br></strong></span><span style="font-size: 14pt;"><span style="font-family: -apple-system, BlinkMacSystemFont, 'Segoe UI', Roboto, Oxygen, Ubuntu, Cantarell, 'Open Sans', 'Helvetica Neue', sans-serif;"><img src="https://media.geeksforgeeks.org/img-practice/prod/addEditProblem/912538/Web/Other/blobid1_1758871841.webp" width="322" height="335"></span><br></span></pre>
<p><span style="font-size: 14pt;"><strong>Constraints:</strong><br>1 ≤ number of nodes ≤ 10<sup>3</sup><br>0 ≤ nodes -&gt; data ≤ 10<sup>3</sup><br>Both the inorder and preorder arrays contain unique values.</span></p>
<div id="highlighter--hover-tools" style="display: none;">
<div id="highlighter--hover-tools--container">
<div class="highlighter--icon highlighter--icon-copy" title="Copy">&nbsp;</div>
<div class="highlighter--icon highlighter--icon-change-color" title="Change Color">&nbsp;</div>
<div class="highlighter--icon highlighter--icon-delete" title="Delete">&nbsp;</div>
</div>
</div>
<div id="highlighter--hover-tools" style="display: none;">
<div id="highlighter--hover-tools--container">
<div class="highlighter--icon highlighter--icon-copy" title="Copy">&nbsp;</div>
<div class="highlighter--icon highlighter--icon-change-color" title="Change Color">&nbsp;</div>
<div class="highlighter--icon highlighter--icon-delete" title="Delete">&nbsp;</div>
</div>
</div></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Accolite</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;