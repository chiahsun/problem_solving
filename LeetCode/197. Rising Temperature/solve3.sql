# Write your MySQL query statement below
SELECT W2.id
FROM Weather AS W1 JOIN Weather AS W2
WHERE W1.recordDate = DATE_SUB(W2.recordDate, INTERVAL 1 DAY) AND W1.temperature < W2.temperature;
