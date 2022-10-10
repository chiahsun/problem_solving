# Write your MySQL query statement below
SELECT e.name AS Employee
FROM Employee as e
WHERE e.salary > 
  (SELECT salary from Employee WHERE id = e.managerId);
