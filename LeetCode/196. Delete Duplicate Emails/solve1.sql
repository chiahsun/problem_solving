# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below

# https://stackoverflow.com/questions/45494/mysql-error-1093-cant-specify-target-table-for-update-in-from-clause
DELETE FROM Person
WHERE id NOT IN 
  ( SELECT id FROM (SELECT MIN(id) AS id
  FROM Person
  GROUP BY email) AS id );

