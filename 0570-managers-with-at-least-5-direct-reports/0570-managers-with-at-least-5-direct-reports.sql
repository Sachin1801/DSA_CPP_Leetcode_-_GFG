# Write your MySQL query statement below

SELECT e.name
FROM Employee e
INNER JOIN Employee d
ON e.id = d.managerId
GROUP BY d.managerId
HAVING COUNT(d.managerId) >=5;


