# Write your MySQL query statement below
SELECT name
FROM Employee
WHERE id IN (SELECT id FROM (SELECT managerId AS id, COUNT(managerId) AS count
FROM Employee
WHERE managerId IS NOT NULL
GROUP BY managerId
HAVING count >= 5) AS M);
