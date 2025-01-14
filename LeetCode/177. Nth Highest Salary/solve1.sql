# https://www.techonthenet.com/mysql/functions.php
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  DECLARE L INT;
  SET L = N-1;
  RETURN (
    SELECT DISTINCT salary
    FROM Employee
    ORDER BY salary DESC
    LIMIT L, 1
  );
END
