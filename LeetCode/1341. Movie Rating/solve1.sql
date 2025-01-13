# Write your MySQL query statement below
WITH R1 AS (
    SELECT user_id, COUNT(*) AS count
    FROM MovieRating AS M
    GROUP BY user_id
), R2 AS (
    SELECT name FROM R1
    JOIN Users AS U
    ON R1.user_id = U.user_id
    ORDER BY count DESC, name
    LIMIT 1
), M1 AS (
    SELECT movie_id, AVG(rating) AS rating
    FROM MovieRating
    WHERE DATE_FORMAT(created_at, "%Y-%m") = '2020-02'
    GROUP BY movie_id
), M2 AS (
    SELECT title
    FROM M1
    JOIN Movies AS M
    ON M1.movie_id = M.movie_id
    ORDER BY rating DESC, title
    LIMIT 1
)
SELECT name AS results FROM R2
UNION ALL
SELECT title AS results FROM M2;
