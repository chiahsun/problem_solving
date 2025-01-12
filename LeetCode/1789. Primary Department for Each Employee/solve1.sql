# Write your MySQL query statement below
WITH T AS (
    SELECT employee_id, COUNT(*) AS count
    FROM Employee
    GROUP BY employee_id
    HAVING count > 1
)
    SELECT employee_id, department_id
    FROM Employee
    WHERE employee_id NOT IN (SELECT employee_id FROM T)
UNION
    SELECT employee_id, department_id
    FROM Employee
    WHERE employee_id IN (SELECT employee_id FROM T) AND primary_flag = 'Y';
