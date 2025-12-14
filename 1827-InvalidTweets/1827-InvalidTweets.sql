-- Last updated: 12/14/2025, 4:17:15 PM
# Write your MySQL query statement below
select tweet_id
from Tweets
where length(content) > 15;