# Write your MySQL query statement below
SELECT user_id, CONCAT(UCASE(SUBSTRING(name, 1, 1)), LCASE(SUBSTRING(name, 2, LENGTH(name)-1))) AS name
FROM Users
ORDER BY user_id;
