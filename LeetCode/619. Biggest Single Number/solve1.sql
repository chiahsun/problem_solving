# Write your MySQL query statement below
SELECT max(M1.num) AS num
FROM MyNumbers AS M1
JOIN(
    SELECT num, COUNT(*) AS count
    FROM MyNumbers
    GROUP BY num
    HAVING count = 1
    ) AS M2
ON M1.num = M2.num;
