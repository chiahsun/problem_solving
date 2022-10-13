# Write your MySQL query statement below
SELECT DISTINCT class
FROM (SELECT class, COUNT(student) OVER(PARTITION BY class) AS student_count
FROM Courses) AS subquery
WHERE student_count >= 5;
