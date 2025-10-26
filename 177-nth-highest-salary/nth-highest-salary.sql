CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    SET N = N-1;
  RETURN (
      # Write your MySQL query statement below.
    Select Distinct Salary from Employee order by salary desc Limit 1 Offset N
  );
END

