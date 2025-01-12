# Write your MySQL query statement below
SELECT E2.reports_to AS employee_id, name, reports_count, average_age
FROM Employees AS E1
JOIN (
    SELECT reports_to, COUNT(*) AS reports_count, ROUND(AVG(age)) AS average_age
    FROM Employees
    GROUP BY reports_to
    HAVING reports_to IS NOT NULL ) AS E2
ON E1.employee_id = E2.reports_to
ORDER BY employee_id;
