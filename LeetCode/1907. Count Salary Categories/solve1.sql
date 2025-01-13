# Write your MySQL query statement below
WITH T AS (
SELECT account_id,
CASE
    WHEN income < 20000 THEN "Low Salary"
    WHEN income <= 50000 THEN "Average Salary"
    ELSE "High Salary"
END AS category
FROM Accounts ),
T2 AS (SELECT category FROM (VALUES ROW('Low Salary'), ROW('Average Salary'), ROW("High Salary")) mylist(category)),
T3 AS (
    SELECT category, COUNT(*) AS accounts_count
    FROM T
    GROUP BY category
)
SELECT T2.category, COALESCE(accounts_count, 0) AS accounts_count
FROM T3
RIGHT JOIN T2
ON T3.category = T2.category;
