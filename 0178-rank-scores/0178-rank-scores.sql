# Write your MySQL query statement below

select score, DENSE_RANK() OVER (ORDER BY score DESC) AS 'rank'
from Scores
order by score desc;