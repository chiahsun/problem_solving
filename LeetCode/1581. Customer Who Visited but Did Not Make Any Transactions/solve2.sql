# Write your MySQL query statement below
SELECT customer_id, COUNT(customer_id) AS  count_no_trans
FROM Visits AS V NATURAL LEFT JOIN Transactions AS T
WHERE T.visit_id IS NULL
GROUP BY customer_id;
