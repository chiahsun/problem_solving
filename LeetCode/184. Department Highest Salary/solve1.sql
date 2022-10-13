# Write your MySQL query statement below

SELECT d.name AS Department, e.name AS Employee, salary AS Salary
FROM Employee AS e
INNER JOIN Department AS d
ON d.id = e.departmentId
WHERE (departmentId, salary) IN
  ( SELECT DISTINCT departmentId, MAX(salary) OVER(PARTITION BY departmentId) AS max_salary
    FROM Employee );

