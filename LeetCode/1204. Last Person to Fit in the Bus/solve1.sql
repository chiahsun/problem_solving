# Write your MySQL query statement below
# https://stackoverflow.com/questions/2563918/create-a-cumulative-sum-column-in-mysql
# https://dev.mysql.com/doc/refman/8.0/en/window-functions-usage.html
WITH T AS (
    SELECT *, SUM(weight) OVER (ORDER BY turn) AS cumsum
    FROM Queue
)
SELECT person_name
FROM T
WHERE cumsum = (
    SELECT MAX(cumsum) AS cumsum
    FROM T
    WHERE cumsum <= 1000
);
