-- # Write your MySQL query statement below
-- select
-- (select distinct Salary 
-- from Employee order by salary desc 
-- limit 1 offset 1) 
-- as SecondHighestSalary;


# Write your MySQL query statement below
select Max(Salary) as SecondHighestSalary from Employee where Salary < (select  MAx(salary)from Employee)