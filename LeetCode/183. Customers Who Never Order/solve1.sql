# Write your MySQL query statement below
SELECT name AS Customers
FROM Customers
WHERE (SELECT count(*) FROM Orders WHERE Orders.customerId = Customers.id) = 0;
