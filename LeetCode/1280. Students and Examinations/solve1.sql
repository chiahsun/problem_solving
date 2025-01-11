# Write your MySQL query statement below
SELECT S.student_id, S.student_name, S.subject_name, COUNT(E.student_id) AS attended_exams
FROM Examinations AS E
RIGHT JOIN (SELECT * FROM Students CROSS JOIN Subjects) AS S
ON E.subject_name = S.subject_name AND E.student_id = S.student_id
GROUP BY S.student_id, S.subject_name
ORDER BY S.student_id, S.subject_name;
