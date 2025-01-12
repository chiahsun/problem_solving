# Write your MySQL query statement below
WITH
    T1 AS (SELECT DATE_FORMAT(trans_date, '%Y-%m') AS month, country, COUNT(*) AS trans_count, SUM(amount) AS trans_total_amount
           FROM Transactions
           GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country),
    T2 AS (SELECT DATE_FORMAT(trans_date, '%Y-%m') AS month, country, COUNT(*) AS approved_count, SUM(amount) AS approved_total_amount
           FROM Transactions
           WHERE state = 'approved'
           GROUP BY DATE_FORMAT(trans_date, '%Y-%m'), country)
SELECT T1.month, T1.country, trans_count, COALESCE(approved_count, 0) AS approved_count, trans_total_amount, COALESCE(approved_total_amount, 0) AS approved_total_amount
FROM T1 LEFT JOIN T2
ON T1.month = T2.month AND (T1.country = T2.country OR (T1.country IS NULL AND T2.country IS NULL));
