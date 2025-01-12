# Write your MySQL query statement below
SELECT DISTINCT C1.customer_id
FROM Customer AS C1
JOIN (
    SELECT customer_id, COUNT(DISTINCT product_key) AS count
    FROM Customer
    GROUP BY customer_id
    HAVING count = (SELECT COUNT(*) FROM Product)) AS C2
ON C1.customer_id = C2.customer_id;

