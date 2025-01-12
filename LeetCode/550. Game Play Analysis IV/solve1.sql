# Write your MySQL query statement below
SELECT ROUND(COUNT(A1.player_id) / COUNT(*), 2) AS fraction
FROM Activity AS A1
RIGHT JOIN ( SELECT player_id, DATE_ADD(MIN(event_date), INTERVAL 1 DAY) AS event_date
       FROM Activity
       GROUP BY player_id ) AS A2
ON A1.player_id = A2.player_id AND A1.event_date = A2.event_date;
