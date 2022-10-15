# Write your MySQL query statement below
WITH CTE AS
  (SELECT s.sales_id
   FROM SalesPerson AS s
       INNER JOIN Orders AS o
           ON s.sales_id = o.sales_id
       INNER JOIN Company AS c
           ON c.com_id = o.com_id
   WHERE c.name = 'RED')
SELECT name
FROM SalesPerson
WHERE sales_id NOT IN (SELECT sales_id FROM CTE);
