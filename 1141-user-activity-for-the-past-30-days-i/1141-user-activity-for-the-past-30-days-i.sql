# Write your MySQL query statement below

SELECT activity_date AS day, count(distinct user_id) AS active_users
from Activity
WHERE activity_date >= '2019-06-28' AND activity_date <='2019-07-27'
group by activity_date;

