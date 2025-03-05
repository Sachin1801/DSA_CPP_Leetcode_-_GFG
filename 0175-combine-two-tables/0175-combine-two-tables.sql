# Write your MySQL query statement below

select p.firstName, p.lastName, city, state
from Person as p
left join Address as a
on p.personId = a.personId