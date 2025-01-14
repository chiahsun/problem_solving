# Write your MySQL query statement below
WITH M1 AS (
    SELECT student_id, subject, MIN(exam_date) AS exam_date
    FROM Scores
    GROUP BY student_id, subject
), M2 AS (
    SELECT student_id, subject, MAX(exam_date) AS exam_date
    FROM Scores
    GROUP BY student_id, subject
)
SELECT S1.student_id, S1.subject, S1.score AS first_score, S2.score AS latest_score
FROM (SELECT student_id, subject, score, exam_date FROM Scores WHERE (student_id, subject, exam_date) IN (SELECT student_id, subject, exam_date FROM M1)) AS S1
JOIN (SELECT student_id, subject, score, exam_date FROM Scores WHERE (student_id, subject, exam_date) IN (SELECT student_id, subject, exam_date FROM M2)) AS S2
ON S1.student_id = S2.student_id AND S1.subject = S2.subject AND S1.exam_date < S2.exam_date AND S1.score < S2.score
ORDER BY student_id, subject;
