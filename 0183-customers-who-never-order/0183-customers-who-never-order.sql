# Write your MySQL query statement below

select name as Customers
from Customers 
where id NOT IN(
    SELECT customerId
    from Orders
);