# Write your MySQL query statement below
WITH P AS (
    SELECT DISTINCT departmentId, salary
    FROM Employee
    ORDER BY departmentId, salary DESC
), P2 AS (
    SELECT
        departmentId,
        salary,
        ROW_NUMBER() OVER (PARTITION BY departmentId ORDER BY salary DESC) AS n
    FROM P
), S AS (
    SELECT E.name AS Employee, E.salary AS Salary, E.departmentId AS id
    FROM Employee AS E
    JOIN P2
    ON E.salary = P2.salary AND E.departmentId = P2.departmentId
    WHERE n <= 3
)
SELECT D.name AS Department, S.Employee, S.Salary
FROM S
JOIN Department AS D
ON S.id = D.id
ORDER BY S.id, S.Salary DESC;
