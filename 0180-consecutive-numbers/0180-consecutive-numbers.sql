# Write your MySQL query statement below

SELECT DISTINCT num as ConsecutiveNums
FROM (
    SELECT num,
        LAG(num,1) over (order by id) as prev1,
        LAG(num,2) OVER (ORDER BY id) as prev2
    FROM Logs
) t
WHERE num = prev1 AND num = prev2;