# Write your MySQL query statement below
# https://stackoverflow.com/questions/16121023/calculating-a-moving-average-mysql
WITH C1 AS (
    SELECT visited_on, SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on
), C2 AS (
    SELECT visited_on,
    SUM(amount) OVER (ORDER BY visited_on ASC RANGE INTERVAL 6 DAY PRECEDING) AS amount,
    ROUND(AVG(amount) OVER (ORDER BY visited_on ASC RANGE INTERVAL 6 DAY PRECEDING), 2) AS average_amount
    FROM C1
), C3 AS (
    SELECT visited_on, amount, average_amount, DATEDIFF(visited_on, min_date) >= 6 AS ok
    FROM C2
    JOIN (SELECT MIN(visited_on) AS min_date FROM Customer) AS D
)
SELECT visited_on, amount, average_amount
FROM C3
WHERE ok
ORDER BY visited_on;


