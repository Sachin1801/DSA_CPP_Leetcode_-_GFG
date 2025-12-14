-- Last updated: 12/14/2025, 4:16:38 PM
# Write your MySQL query statement below

SELECT teacher_id, count(DISTINCT subject_id) as cnt
FROM Teacher
GROUP BY teacher_id;