# Write your MySQL query statement below
SELECT DISTINCT product_id, product_name
FROM Product AS p
INNER JOIN Sales AS s
USING (product_id) 
WHERE sale_date BETWEEN '2019-01-01' AND '2019-03-31' AND product_id NOT IN
  (SELECT product_id
   FROM Sales
   WHERE sale_date NOT BETWEEN '2019-01-01' AND '2019-03-31'
  );
