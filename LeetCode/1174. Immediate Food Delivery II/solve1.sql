# Write your MySQL query statement below
WITH T AS (
    SELECT D1.customer_id, D1.order_date, customer_pref_delivery_date
    FROM Delivery AS D1
    JOIN (SELECT customer_id, MIN(order_date) AS order_date
          FROM Delivery
          GROUP BY customer_id) AS D2
    ON D1.customer_id = D2.customer_id AND D1.order_date = D2.order_date
)
SELECT ROUND(100 * SUM(order_date = customer_pref_delivery_date) / COUNT(*), 2) AS immediate_percentage
FROM T;
