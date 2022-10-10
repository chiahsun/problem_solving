# Write your MySQL query statement below
SELECT email AS Email
FROM (
    SELECT email, COUNT(*) AS email_cnt 
    FROM Person 
    GROUP BY email ) AS sub_query 
WHERE email_cnt > 1;
