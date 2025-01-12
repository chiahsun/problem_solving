# Write your MySQL query statement below
SELECT DISTINCT L.num AS ConsecutiveNums
FROM Logs AS L
JOIN (
    SELECT id+1 as id, num
    FROM Logs ) AS L1
ON L.id = L1.id AND L.num = L1.num
JOIN (
    SELECT id+2 as id, num
    FROM Logs ) AS L2
ON L.id = L2.id AND L.num = L2.num
