
# Write your MySQL query statement below
SELECT product_id, IF(SUM(units = 0), 0, ROUND(SUM(units * price) / SUM(units), 2)) AS average_price
FROM (
    SELECT P.product_id, IFNULL(units, 0) as units, price
    FROM Prices AS P
    LEFT JOIN UnitsSold AS U
    ON U.product_id = P.product_id
    WHERE (purchase_date >= start_date AND purchase_date <= end_date) OR purchase_date IS NULL ) AS T
GROUP BY product_id;
