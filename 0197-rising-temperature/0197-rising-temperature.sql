# Write your MySQL query statement below
Select a.id as id 
from Weather as a
inner join Weather as b
where DATEDIFF(a.recordDate, b.recordDate) = 1
AND a.temperature > b.temperature;
