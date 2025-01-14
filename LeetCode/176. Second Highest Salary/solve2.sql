# Write your MySQL query statement below
# https://dev.mysql.com/doc/refman/8.4/en/select.html#id1046762
# https://stackoverflow.com/questions/17250243/how-to-return-null-when-result-is-empty
SELECT (SELECT DISTINCT salary
FROM Employee
ORDER BY salary DESC
LIMIT 1, 1) AS SecondHighestSalary;
