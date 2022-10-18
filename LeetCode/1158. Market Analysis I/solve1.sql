# Write your MySQL query statement below
SELECT user_id AS buyer_id, join_date, COALESCE(orders_in_2019, 0) AS orders_in_2019
FROM Users AS u
LEFT JOIN
  (SELECT buyer_id, COUNT(*) AS orders_in_2019
   FROM Orders
   WHERE EXTRACT(YEAR FROM order_date) = 2019
   GROUP BY buyer_id) AS s
ON u.user_id = s.buyer_id;
