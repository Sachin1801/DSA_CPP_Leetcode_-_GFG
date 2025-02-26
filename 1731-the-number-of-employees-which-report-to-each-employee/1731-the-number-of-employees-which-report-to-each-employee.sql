# Write your MySQL query statement below

SELECT e.employee_id, e.name, COUNT(*) as reports_count, ROUND(AVG(e2.age),0) as average_age
FROM Employees e
inner join Employees e2
ON e.employee_id = e2.reports_to
GROUP BY e.employee_id, e.name
ORDER BY employee_id