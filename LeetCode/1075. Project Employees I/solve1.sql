# Write your MySQL query statement below
SELECT project_id, ROUND(SUM(experience_years) / COUNT(*), 2) AS average_years
FROM Project AS P
JOIN Employee AS E
ON P.employee_id = E.employee_id
GROUP BY project_id;
