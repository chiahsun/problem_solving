# Write your MySQL query statement below
SELECT class
FROM 
  (SELECT class, COUNT(student) AS student_count
   FROM Courses
   GROUP BY class) as subquery
WHERE student_count >= 5;

