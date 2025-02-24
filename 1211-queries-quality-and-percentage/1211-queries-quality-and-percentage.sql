# Write your MySQL query statement below

select query_name, round(sum(rating/position)/count(query_name),2)
as quality, round(avg(IF(rating < 3 , 1, 0))*100, 2)
as poor_query_percentage
from Queries
group by query_name