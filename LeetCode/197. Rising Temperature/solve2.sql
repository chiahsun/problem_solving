# Write your MySQL query statement below
SELECT cw.id -- pw.recordDate AS previous, pw.temperature AS previous_temp, cw.recordDate AS today, cw.temperature AS today_temp 
FROM Weather AS pw
INNER JOIN Weather AS cw
ON DATE_ADD(pw.recordDate, INTERVAL 1 DAY) = cw.recordDate AND pw.temperature < cw.temperature;

