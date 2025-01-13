# Write your MySQL query statement below
SELECT IF((id % 2 = 1) AND (id = (SELECT COUNT(*) as id FROM Seat)), id, (2*((id+1) / 2) - 2 * ((id+1) % 2))) AS id, student
FROM Seat
ORDER BY id;
