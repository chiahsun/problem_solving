# Write your MySQL query statement below
WITH cte AS 
  (SELECT class, COUNT(student) AS student_count
   FROM Courses
   GROUP BY class)
SELECT class
FROM cte
WHERE student_count >= 5;

