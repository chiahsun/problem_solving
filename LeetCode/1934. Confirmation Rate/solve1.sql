# Write your MySQL query statement below
SELECT T1.user_id, ROUND(confirmed_count / total_count, 2) AS confirmation_rate
FROM (
    SELECT S.user_id, COUNT(S.user_id) AS total_count
    FROM Confirmations AS C
    RIGHT JOIN Signups AS S
    ON C.user_id = S.user_id
    GROUP BY user_id ) AS T1
JOIN (
    SELECT S.user_id, COUNT(action) AS confirmed_count
    FROM (SELECT * FROM Confirmations WHERE action = 'confirmed') AS C
    RIGHT JOIN Signups AS S
    ON C.user_id = S.user_id
    GROUP BY S.user_id ) AS T2
ON T1.user_id = T2.user_id;
