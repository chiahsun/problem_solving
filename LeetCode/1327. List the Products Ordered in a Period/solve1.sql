# Write your MySQL query statement below
SELECT product_name, SUM(unit) AS unit
FROM Orders AS O
JOIN Products AS P
ON O.product_id = P.product_id
WHERE DATE_FORMAT(order_date, '%Y-%m') = '2020-02'
GROUP BY O.product_id
HAVING unit >= 100;
