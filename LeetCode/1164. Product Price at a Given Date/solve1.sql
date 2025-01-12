# Write your MySQL query statement below
WITH D AS (
    SELECT product_id, MAX(change_date) AS date
    FROM Products
    WHERE change_date <= '2019-08-16'
    GROUP BY product_id ),
T AS (
    SELECT P.product_id, P.change_date, P.new_price
    FROM Products AS P
    JOIN D
    ON P.product_id = D.product_id AND P.change_date = D.date)
SELECT P2.product_id, COALESCE(T.new_price, 10) AS price
FROM T
RIGHT JOIN (SELECT DISTINCT product_id FROM Products) AS P2
ON P2.product_id = T.product_id;

