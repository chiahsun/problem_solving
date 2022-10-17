# Write your MySQL query statement below
SELECT customer_number FROM
  (SELECT customer_number, COUNT(*) AS count, MAX(COUNT(*)) OVER() AS max_count
   FROM Orders
   GROUP BY customer_number) AS subquery
WHERE count = max_count;
