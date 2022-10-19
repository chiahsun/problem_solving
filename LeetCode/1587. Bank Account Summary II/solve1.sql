# Write your MySQL query statement below
SELECT name, SUM(amount) AS balance
FROM Transactions AS t
INNER JOIN Users AS u
USING (account)
GROUP BY account 
HAVING balance > 10000;

