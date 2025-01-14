# Write your MySQL query statement below
WITH ODD AS (
    SELECT transaction_date, SUM(amount) AS odd_sum
    FROM transactions
    WHERE amount % 2 = 1
    GROUP BY transaction_date
), EVEN AS (
    SELECT transaction_date, SUM(amount) AS even_sum
    FROM transactions
    WHERE amount % 2 = 0
    GROUP BY transaction_date
), DATES AS (
    SELECT DISTINCT transaction_date FROM transactions
)
SELECT D.transaction_date, COALESCE(O.odd_sum, 0) AS odd_sum, COALESCE(E.even_sum, 0) AS even_sum FROM DATES AS D
LEFT JOIN ODD AS O
ON D.transaction_date = O.transaction_date
LEFT JOIN EVEN AS E
ON D.transaction_date = E.transaction_date
ORDER BY transaction_date;
