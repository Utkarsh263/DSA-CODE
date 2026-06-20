CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  RETURN (
      SELECT Salary
      FROM (
          SELECT Salary,
                 DENSE_RANK() OVER (ORDER BY Salary DESC) AS rnk
          FROM Employee
      ) t
      WHERE rnk = N
      LIMIT 1
  );
END