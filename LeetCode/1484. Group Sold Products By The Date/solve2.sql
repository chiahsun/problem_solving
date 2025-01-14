# Write your MySQL query statement below
WITH T AS (
    SELECT DISTINCT sell_date, product
    FROM Activities
    ORDER BY sell_date, product
)
SELECT sell_date, COUNT(*) AS num_sold, GROUP_CONCAT(product ORDER BY sell_date, product SEPARATOR ',') AS products
FROM T
GROUP BY sell_date;
