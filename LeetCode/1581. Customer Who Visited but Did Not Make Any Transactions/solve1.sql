# Write your MySQL query statement below
WITH cte AS 
  (SELECT visit_id
   FROM Visits
   WHERE visit_id NOT IN 
     (SELECT visit_id 
      FROM Transactions))
SELECT customer_id, COUNT(visit_id) AS count_no_trans
FROM cte
INNER JOIN Visits
USING (visit_id)
GROUP BY customer_id;
