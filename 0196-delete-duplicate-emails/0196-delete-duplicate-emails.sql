# Write your MySQL query statement below

-- select email, id
-- from Person 
-- Group by email
-- having count(*) > 1

DELETE p1 from Person as p1
inner join Person as p2
where p1.id > p2.id AND p1.email = p2.email;