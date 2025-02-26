# Write your MySQL query statement below

SELECT max(num) as num
from MyNumbers
WHERE num IN (
    SELECT num
    FROM MyNumbers
    GROUP BY num
    HAVING COUNT(num)=1
)


