# Write your MySQL query statement below
SELECT user_id AS buyer_id, join_date, COUNT(buyer_id) AS orders_in_2019
FROM Users AS u
LEFT JOIN Orders AS o
ON u.user_id = o.buyer_id AND EXTRACT(YEAR FROM order_date) = 2019
GROUP BY user_id;
