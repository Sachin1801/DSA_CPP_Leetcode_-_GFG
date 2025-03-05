# Write your MySQL query statement below

select d.name as Department, e.name as Employee, e.salary 
from Employee as e
join Department as d
on e.departmentId = d.id
where(e.salary, e.departmentId) IN(
    SELECT MAX(salary), departmentId
    FROM Employee
    GROUP BY departmentId
);