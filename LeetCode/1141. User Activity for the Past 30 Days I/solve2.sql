# Write your MySQL query statement below
SELECT activity_date AS day, COUNT(*) AS active_users
FROM (
    SELECT DISTINCT user_id, activity_date
    FROM Activity
    WHERE activity_date >= '2019-06-28' AND activity_date <= '2019-07-27'
) AS T
GROUP BY activity_date;
