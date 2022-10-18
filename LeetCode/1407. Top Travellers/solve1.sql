# Write your MySQL query statement below
SELECT name, COALESCE(SUM(distance), 0) AS travelled_distance
  FROM 
    (SELECT u.id, name, distance 
     FROM Users AS u
     LEFT JOIN Rides AS r
     ON r.user_id = u.id) AS subquery
  GROUP BY id
  ORDER BY travelled_distance DESC, name ASC;

