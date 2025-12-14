-- Last updated: 12/14/2025, 4:17:02 PM
# Write your MySQL query statement below
select s.user_id, IFNULL(round(sum(action='confirmed')/count(*),2),0.00) as confirmation_rate
from Signups s
left join Confirmations c
ON s.user_id = c.user_id
group by s.user_id;