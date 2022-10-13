# Write your MySQL query statement below
SELECT salary AS SecondHighestSalary
FROM 
  ( SELECT salary, DENSE_RANK() OVER(ORDER BY salary DESC) AS row_n
    FROM Employee ) AS subquery
WHERE row_n = 2 
UNION 
SELECT NULL AS SecondHighestSalary FROM (SELECT COUNT(DISTINCT salary) AS cnt FROM Employee) AS subquery WHERE cnt <= 1;

