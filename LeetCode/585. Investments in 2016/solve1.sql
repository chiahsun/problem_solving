# Write your MySQL query statement below
WITH T AS (
    SELECT tiv_2015, COUNT(*) AS count
    FROM Insurance
    GROUP BY tiv_2015
    HAVING count > 1
), L AS (
    SELECT lat, lon, COUNT(*) AS count
    FROM Insurance
    GROUP BY lat, lon
    HAVING count = 1
)
SELECT ROUND(SUM(tiv_2016), 2) AS tiv_2016
FROM Insurance
WHERE tiv_2015 IN (SELECT tiv_2015 FROM T) AND (lat, lon) IN (SELECT lat, lon FROM L);
