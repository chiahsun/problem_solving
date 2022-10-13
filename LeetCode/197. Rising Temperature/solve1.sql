# Write your MySQL query statement below
WITH cte AS 
   (SELECT id, recordDate AS date, temperature as temp, LAG(temperature) OVER(ORDER BY recordDate) AS prev_temp, LAG(recordDate) OVER(ORDER BY recordDate) AS prev_date
    FROM Weather
    ORDER BY recordDate)
SELECT id 
FROM cte
WHERE prev_temp IS NOT NULL AND temp > prev_temp AND date = DATE_ADD(prev_date, INTERVAL 1 DAY);

